/-
Copyright (c) 2020 Wojciech Nawrocki. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.

Authors: Wojciech Nawrocki
-/
import Init.System.IO

import Lean.Elab.Import
import Lean.Elab.Command

/-! One can think of this module as being a partial reimplementation
of Lean.Elab.Frontend which also stores a snapshot of the world after
each command. Importantly, we allow (re)starting compilation from any
snapshot/position in the file for interactive editing purposes. -/

namespace Lean
namespace Server
namespace Snapshots

open Elab

/-- The data associated with a snapshot is different depending on whether
it was produced from the header or from a command. -/
inductive SnapshotData where
  | headerData : Environment → MessageLog → Options → SnapshotData
  | cmdData : Command.State → SnapshotData
  deriving Inhabited

/-- What Lean knows about the world after the header and each command. -/
structure Snapshot where
  /- Where the command which produced this snapshot begins. Note that
  neighbouring snapshots are *not* necessarily attached beginning-to-end,
  since inputs outside the grammar advance the parser but do not produce
  snapshots. -/
  beginPos : String.Pos
  stx : Syntax
  mpState : Parser.ModuleParserState
  data : SnapshotData
  deriving Inhabited

namespace Snapshot

def endPos (s : Snapshot) : String.Pos := s.mpState.pos

def env : Snapshot → Environment
  | ⟨_, _, _, SnapshotData.headerData env_ _ _⟩ => env_
  | ⟨_, _, _, SnapshotData.cmdData cmdState⟩ => cmdState.env

def msgLog : Snapshot → MessageLog
  | ⟨_, _, _, SnapshotData.headerData _ msgLog_ _⟩ => msgLog_
  | ⟨_, _, _, SnapshotData.cmdData cmdState⟩ => cmdState.messages

def toCmdState : Snapshot → Command.State
  | ⟨_, _, _, SnapshotData.headerData env msgLog opts⟩ => Command.mkState env msgLog opts
  | ⟨_, _, _, SnapshotData.cmdData cmdState⟩ => cmdState

end Snapshot

-- TODO(WN): fns here should probably take inputCtx and live
-- in some SnapshotsM := ReaderT Context (EIO Empty)

def reparseHeader (contents : String) (header : Snapshot) (opts : Options := {}) : IO Snapshot := do
  let inputCtx := Parser.mkInputContext contents "<input>"
  let (_, newHeaderParserState, _) ← Parser.parseHeader inputCtx
  pure { header with mpState := newHeaderParserState }

private def ioErrorFromEmpty (ex : Empty) : IO.Error :=
  nomatch ex

/-- Parses the next command occurring after the given snapshot
without elaborating it. -/
def parseNextCmd (contents : String) (snap : Snapshot) : IO Syntax := do
  let inputCtx := Parser.mkInputContext contents "<input>"
  let cmdState := snap.toCmdState
  let scope := cmdState.scopes.head!
  let pmctx := { env := cmdState.env, options := scope.opts, currNamespace := scope.currNamespace, openDecls := scope.openDecls }
  let (cmdStx, _, _) :=
    Parser.parseCommand inputCtx pmctx snap.mpState snap.msgLog
  cmdStx

/--
  Parse remaining file without elaboration. NOTE that doing so can lead to parse errors or even wrong syntax objects,
  so it should only be done for reporting preliminary results! -/
partial def parseAhead (contents : String) (snap : Snapshot) : IO (Array Syntax) := do
  let inputCtx := Parser.mkInputContext contents "<input>"
  let cmdState := snap.toCmdState
  let scope := cmdState.scopes.head!
  let pmctx := { env := cmdState.env, options := scope.opts, currNamespace := scope.currNamespace, openDecls := scope.openDecls }
  go inputCtx pmctx snap.mpState #[]
  where
    go inputCtx pmctx cmdParserState stxs := do
      let (cmdStx, cmdParserState, _) := Parser.parseCommand inputCtx pmctx cmdParserState snap.msgLog
      if Parser.isEOI cmdStx || Parser.isExitCommand cmdStx then
        stxs.push cmdStx
      else
        go inputCtx pmctx cmdParserState (stxs.push cmdStx)

/-- Compiles the next command occurring after the given snapshot.
If there is no next command (file ended), returns messages produced
through the file. -/
-- NOTE: This code is really very similar to Elab.Frontend. But generalizing it
-- over "store snapshots"/"don't store snapshots" would likely result in confusing
-- isServer? conditionals and not be worth it due to how short it is.
def compileNextCmd (contents : String) (snap : Snapshot) : IO (Sum Snapshot MessageLog) := do
  let inputCtx := Parser.mkInputContext contents "<input>"
  let cmdState := snap.toCmdState
  let scope := cmdState.scopes.head!
  let pmctx := { env := cmdState.env, options := scope.opts, currNamespace := scope.currNamespace, openDecls := scope.openDecls }
  let (cmdStx, cmdParserState, msgLog) :=
    Parser.parseCommand inputCtx pmctx snap.mpState snap.msgLog
  let cmdPos := cmdStx.getHeadInfo.get!.pos.get! -- TODO(WN): always `some`?
  if Parser.isEOI cmdStx || Parser.isExitCommand cmdStx then
    Sum.inr msgLog
  else
    let cmdStateRef ← IO.mkRef { snap.toCmdState with messages := msgLog }
    let cmdCtx : Elab.Command.Context := {
        cmdPos   := snap.endPos
        fileName := inputCtx.fileName
        fileMap  := inputCtx.fileMap
      }
    EIO.toIO ioErrorFromEmpty $
      Elab.Command.catchExceptions
        (Elab.Command.elabCommand cmdStx)
        cmdCtx cmdStateRef
    let postCmdState ← cmdStateRef.get
    let postCmdSnap : Snapshot := {
        beginPos := cmdPos
        stx := cmdStx
        mpState := cmdParserState
        data := SnapshotData.cmdData postCmdState
      }
    Sum.inl postCmdSnap

/-- Compiles all commands after the given snapshot. Returns them as a list, together with
the final message log. -/
partial def compileCmdsAfter (contents : String) (snap : Snapshot) : IO (List Snapshot × MessageLog) := do
  let cmdOut ← compileNextCmd contents snap
  match cmdOut with
  | Sum.inl snap =>
    let (snaps, msgLog) ← compileCmdsAfter contents snap
    (snap :: snaps, msgLog)
  | Sum.inr msgLog => ([], msgLog)

end Snapshots
end Server
end Lean
