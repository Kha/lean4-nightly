{ debug ? false, extraCMakeFlags ? [],
  stdenv, lib, cmake, gmp, gnumake, buildLeanPackage, writeShellScriptBin, runCommand, symlinkJoin, lndir,
  ... } @ args:
rec {
  inherit stdenv;
  buildCMake = args: stdenv.mkDerivation ({
    nativeBuildInputs = [ cmake ];
    buildInputs = [ gmp ];
    # https://github.com/NixOS/nixpkgs/issues/60919
    hardeningDisable = [ "all" ];
    cmakeFlags = [ "-DSTAGE=1" "-DPREV_STAGE=./faux-prev-stage" "-DUSE_GITHASH=OFF" ] ++ extraCMakeFlags ++ lib.optional (args.debug or debug) [ "-DCMAKE_BUILD_TYPE=Debug" ];
    dontStrip = (args.debug or debug);

    postConfigure = ''
      patchShebangs bin
    '';
  } // args // {
    src = args.realSrc or (lib.sourceByRegex args.src [ "[a-z].*" "CMakeLists\.txt" ]);
  });
  lean-bin-tools-unwrapped = buildCMake {
    name = "lean-bin-tools";
    realSrc = lib.sourceByRegex ../src [ "CMakeLists\.txt" "bin.*" "include.*" ".*\.in" ];
    preConfigure = ''
      touch empty.cpp
      sed -i 's/find_package.*//;s/add_subdirectory.*//;s/set(LEAN_OBJS.*/set(LEAN_OBJS empty.cpp)/' CMakeLists.txt
    '';
    dontBuild = true;
    installPhase = ''
      mkdir $out
      mv bin/ include/ share/ $out/
      substituteInPlace $out/bin/leanmake --replace "make" "${gnumake}/bin/make"
    '';
  };
  leancpp = buildCMake {
    name = "leancpp";
    src = ../src;
    # `lean.cpp` is usually linked directly into the executable, but we want to do that step outside of CMake
    preConfigure = ''
      echo 'add_library(leancppmain shell/lean.cpp)
        set_target_properties(leancppmain PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ''${CMAKE_BINARY_DIR}/lib/lean
        OUTPUT_NAME leancppmain)' >> CMakeLists.txt
    '';
    buildFlags = [ "leancpp" "leancppmain" ];
    installPhase = ''
      mkdir -p $out
      mv lib/ $out/
    '';
  };
  # rename derivation so `nix run` uses the right executable name but we still see the stage in the build log
  wrapStage = stage: runCommand "lean" {} ''
    ln -s ${stage} $out
  '';
  stage0 = wrapStage (args.stage0 or (buildCMake {
    name = "lean-stage0";
    src = ../stage0/src;
    debug = false;
    cmakeFlags = [ "-DSTAGE=0" ];
    preConfigure = ''
      ln -s ${../stage0/stdlib} ../stdlib
    '';
    installPhase = ''
      mkdir -p $out/bin
      mv bin/lean $out/bin/
    '';
  }));
  stage = { stage, prevStage, self }:
    let
      desc = "stage${toString stage}";
      build = args: buildLeanPackage.override {
        lean = prevStage;
        leanc = lean-bin-tools-unwrapped;
        # use same stage for retrieving dependencies
        lean-leanDeps = stage0;
        lean-final = self;
      } (args // {
        inherit debug;
        leanFlags = [ "-Dinterpreter.prefer_native=false" ];
      });
    in (all: all // all.lean) rec {
      Init = build { name = "Init"; src = ../src; deps = []; };
      Std  = build { name = "Std";  src = ../src; deps = [ Init ]; };
      Lean = build { name = "Lean"; src = ../src; deps = [ Init Std ]; };
      Leanpkg = build { name = "Leanpkg"; src = ../src; deps = [ Init Std Lean ]; };
      inherit (Lean) emacs-dev emacs-package vscode-dev vscode-package;
      mods = Init.mods // Std.mods // Lean.mods;
      leanc = writeShellScriptBin "leanc" ''
        ${lean-bin-tools-unwrapped}/bin/leanc -L${gmp}/lib -L${Init.staticLib} -L${Std.staticLib} -L${Lean.staticLib} -L${leancpp}/lib/lean "$@"
      '';
      lean = wrapStage(stdenv.mkDerivation {
        name = "lean-${desc}";
        buildCommand = ''
          mkdir -p $out/bin $out/lib/lean
          ln -sf ${leancpp}/lib/lean/libleancpp.* ${Leanpkg.modRoot}/* ${Lean.staticLib}/* ${Lean.modRoot}/* ${Std.staticLib}/* ${Std.modRoot}/* ${Init.staticLib}/* ${Init.modRoot}/* $out/lib/lean/
          ${leanc}/bin/leanc -x none -rdynamic ${leancpp}/lib/lean/libleancppmain.* -o $out/bin/lean
          ${leanc}/bin/leanc -x none -rdynamic ${Leanpkg.staticLib}/* -o $out/bin/leanpkg
          # put everything in a single final derivation so `IO.appDir` references work
          for i in ${lean-bin-tools-unwrapped} ${leanc}; do
            ${lndir}/bin/lndir -silent $i $out
          done
        '';
      });
      test = buildCMake {
        name = "lean-test-${desc}";
        realSrc = lib.sourceByRegex ../. [ "src.*" "tests.*" ];
        preConfigure = ''
          cd src
        '';
        postConfigure = ''
          patchShebangs ../../tests
          rm -r bin lib include share
          ln -sf ${lean}/* .
        '';
        buildPhase = ''
          ctest --output-on-failure -E 'leancomptest_(doc_example|foreign)' -j$NIX_BUILD_CORES
        '';
        installPhase = ''
          touch $out
        '';
      };
      update-stage0 =
        let cTree = symlinkJoin { name = "cs"; paths = [ Init.cTree Std.cTree Lean.cTree Leanpkg.cTree ]; }; in
        writeShellScriptBin "update-stage0" ''
        set -euo pipefail
        rm -r stage0 || true
        mkdir -p stage0/
        cp -r --dereference --no-preserve=all ${cTree} stage0/stdlib
        # ensure deterministic ordering
        c_files="$(cd ${cTree}; find . -type l | LC_ALL=C sort | tr '\n' ' ')"
        echo "add_library (stage0 OBJECT $c_files)" > stage0/stdlib/CMakeLists.txt
        # don't copy untracked crap
        git ls-files -z src | xargs -0 -I '{}' bash -c 'mkdir -p `dirname stage0/{}` && cp {} stage0/{}'
        git add stage0
      '';
      update-stage0-commit = writeShellScriptBin "update-stage0-commit" ''
        set -euo pipefail
        ${update-stage0}/bin/update-stage0
        git commit -m "chore: update stage0"
      '';
    };
  stage1 = stage { stage = 1; prevStage = stage0; self = stage1; };
  stage2 = stage { stage = 2; prevStage = stage1; self = stage2; };
  stage3 = stage { stage = 3; prevStage = stage2; self = stage3; };
}
