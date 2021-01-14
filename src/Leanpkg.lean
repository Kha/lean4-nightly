/-
Copyright (c) 2017 Microsoft Corporation. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Gabriel Ebner, Sebastian Ullrich
-/
import Leanpkg.Resolve
import Leanpkg.Git

namespace Leanpkg

def readManifest : IO Manifest := do
  let m ← Manifest.fromFile leanpkgTomlFn
  if m.leanVersion ≠ leanVersionString then
    IO.eprintln $ "\nWARNING: Lean version mismatch: installed version is " ++ leanVersionString
       ++ ", but package requires " ++ m.leanVersion ++ "\n"
  return m

def writeManifest (manifest : Lean.Syntax) (fn : String) : IO Unit := do
  IO.FS.writeFile fn manifest.reprint.get!

def lockFileName := ".leanpkg-lock"

partial def withLockFile (x : IO α) : IO α :=
  acquire *> x <* IO.removeFile lockFileName
  where
    acquire (firstTime := true) :=
      try
        -- x: fail if already exists (not part of POSIX, but supported on all our platforms)
        discard <| IO.Prim.Handle.mk lockFileName "wx"
        -- TODO: should ideally contain PID
      catch
        | IO.Error.alreadyExists _ _ => do
          if firstTime then
            IO.eprintln s!"Waiting for prior leanpkg invocation to finish... (remove '{lockFileName}' if stuck)"
          IO.sleep (ms := 300)
          acquire (firstTime := false)
        | e => throw e

def configure : IO String := do
  let d ← readManifest
  IO.eprintln $ "configuring " ++ d.name ++ " " ++ d.version
  let assg ← solveDeps d
  let paths ← constructPath assg
  for path in paths do
    unless path == "./." do
      -- build recursively
      -- TODO: share build of common dependencies
      execCmd {
        cmd := (← IO.appPath)
        cwd := path
        args := #["build"]
      }
  System.FilePath.searchPathSeparator.toString.intercalate <| paths.map (· ++ "/build")

def execMake (makeArgs leanArgs : List String) (leanPath : String) : IO Unit := withLockFile do
  let manifest ← readManifest
  let leanArgs := (match manifest.timeout with | some t => ["-T", toString t] | none => []) ++ leanArgs
  let mut spawnArgs := {
    cmd := "sh"
    cwd := manifest.effectivePath
    args := #["-c", s!"\"{← IO.appDir}/leanmake\" LEAN_OPTS=\"{" ".intercalate leanArgs}\" LEAN_PATH=\"{leanPath}\" {" ".intercalate makeArgs} >&2"]
  }
  execCmd spawnArgs

def buildImports (imports : List String) (leanArgs : List String) : IO String := do
  let manifest ← readManifest
  let leanPath ← configure
  let imports := imports.map (·.toName)
  -- TODO: shoddy check
  let localImports := imports.filter fun i => i.getRoot.toString.toLower == manifest.name.toLower
  if localImports != [] then
    let oleans := localImports.map fun i => s!"\"build{Lean.modPathToFilePath i}.olean\""
    execMake oleans leanArgs leanPath
  return leanPath

def build (leanArgs : List String) : IO Unit := do
  execMake [] leanArgs (← configure)

def initGitignoreContents :=
  "/build
"

def initPkg (n : String) (fromNew : Bool) : IO Unit := do
  IO.FS.writeFile leanpkgTomlFn s!"[package]
name = \"{n}\"
version = \"0.1\"
"
  IO.FS.writeFile s!"{n.capitalize}.lean" "def main : IO Unit :=
  IO.println \"Hello, world!\"
"
  let h ← IO.FS.Handle.mk ".gitignore" IO.FS.Mode.append (bin := false)
  h.putStr initGitignoreContents
  let gitEx ← IO.isDir ".git"
  unless gitEx do
    (do
      execCmd {cmd := "git", args := #["init", "-q"]}
      unless upstreamGitBranch = "master" do
        execCmd {cmd := "git", args := #["checkout", "-B", upstreamGitBranch]}
    ) <|> IO.eprintln "WARNING: failed to initialize git repository"

def init (n : String) := initPkg n false

def usage :=
  "Lean package manager, version " ++ uiLeanVersionString ++ "

Usage: leanpkg <command>

configure              download and build dependencies and print resulting LEAN_PATH
build [-- <Lean-args>] configure and build *.olean files
init <name>            create a Lean package in the current directory

See `leanpkg help <command>` for more information on a specific command."

def main : (cmd : String) → (leanpkgArgs leanArgs : List String) → IO Unit
  | "configure", [],     []        => discard <| configure
  | "print-path", leanpkgArgs, leanArgs => buildImports leanpkgArgs leanArgs >>= IO.println
  | "build",     _,      leanArgs  => build leanArgs
  | "init",      [Name], []        => init Name
  | "help",      ["configure"], [] => IO.println "Download dependencies

Usage:
  leanpkg configure

This command sets up the `build/deps` directory.

For each (transitive) git dependency, the specified commit is checked out
into a sub-directory of `build/deps`. If there are dependencies on multiple
versions of the same package, the version materialized is undefined. No copy
is made of local dependencies."
  | "help",       ["build"], []    => IO.println "download dependencies and build *.olean files

Usage:
  leanpkg build [-- <lean-args>]

This command invokes `Leanpkg configure` followed by
`Leanmake <lean-args>`, building the package's Lean files as well as
(transitively) imported files of dependencies. If defined, the `package.timeout`
configuration value is passed to Lean via its `-T` parameter."
  | "help",       ["init"], []     => IO.println "Create a new Lean package in the current directory

Usage:
  leanpkg init <name>

This command creates a new Lean package with the given name in the current
directory."
  | "help",       _,     []        => IO.println usage
  | _,            _,     _         => throw <| IO.userError usage

private def splitCmdlineArgsCore : List String → List String × List String
  | []           => ([], [])
  | (arg::args)  => if arg == "--"
                    then ([], args)
                    else
                      let (outerArgs, innerArgs) := splitCmdlineArgsCore args
                      (arg::outerArgs, innerArgs)

def splitCmdlineArgs : List String → IO (String × List String × List String)
| [] => throw <| IO.userError usage
| [cmd] => return (cmd, [], [])
| (cmd::rest) =>
  let (outerArgs, innerArgs) := splitCmdlineArgsCore rest
  return (cmd, outerArgs, innerArgs)

end Leanpkg

def main (args : List String) : IO Unit := do
  Lean.initSearchPath none  -- HACK
  let (cmd, outerArgs, innerArgs) ← Leanpkg.splitCmdlineArgs args
  Leanpkg.main cmd outerArgs innerArgs
