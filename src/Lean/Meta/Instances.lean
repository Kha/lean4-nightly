/-
Copyright (c) 2019 Microsoft Corporation. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Leonardo de Moura
-/
import Lean.ScopedEnvExtension
import Lean.Meta.DiscrTree

namespace Lean.Meta

structure InstanceEntry where
  keys        : Array DiscrTree.Key
  val         : Expr
  globalName? : Option Name := none
  deriving Inhabited

structure Instances where
  discrTree       : DiscrTree Expr := DiscrTree.empty
  globalInstances : NameSet := {}
  deriving Inhabited

def addInstanceEntry (d : Instances) (e : InstanceEntry) : Instances := {
  d with
    discrTree := d.discrTree.insertCore e.keys e.val
    globalInstances := match e.globalName? with
      | some n => d.globalInstances.insert n
      | none   => d.globalInstances
}

builtin_initialize instanceExtension : SimpleScopedEnvExtension InstanceEntry Instances ←
  registerSimpleScopedEnvExtension {
    name     := `instanceExt
    initial  := {}
    addEntry := addInstanceEntry
  }

private def mkInstanceKey (e : Expr) : MetaM (Array DiscrTree.Key) := do
  let type ← inferType e
  withNewMCtxDepth do
    let (_, _, type) ← forallMetaTelescopeReducing type
    DiscrTree.mkPath type

def addInstance (declName : Name) (attrKind : AttributeKind) : MetaM Unit := do
  let cinfo ← getConstInfo declName
  let c := mkConst declName (cinfo.lparams.map mkLevelParam)
  let keys ← mkInstanceKey c
  instanceExtension.add { keys := keys, val := c, globalName? := declName } attrKind

builtin_initialize
  registerBuiltinAttribute {
    name  := `instance
    descr := "type class instance"
    add   := fun declName stx attrKind => do
      let prio ← match stx with
        | Syntax.missing => pure <| evalPrio! default -- small hack, in the elaborator we use `Syntax.missing` when creating attribute views for `instance
        | _              => getAttrParamOptPrio stx[1]
      -- TODO use prio
      discard <| addInstance declName attrKind |>.run {} {}
  }

@[export lean_is_instance]
def isGlobalInstance (env : Environment) (declName : Name) : Bool :=
  Meta.instanceExtension.getState env |>.globalInstances.contains declName

def getGlobalInstancesIndex : MetaM (DiscrTree Expr) :=
  return Meta.instanceExtension.getState (← getEnv) |>.discrTree

/- Default instance support -/

structure DefaultInstanceEntry where
  className    : Name
  instanceName : Name
  priority     : Nat

abbrev PrioritySet := Std.RBTree Nat (.>.)

structure DefaultInstances where
  defaultInstances : NameMap (List (Name × Nat)) := {}
  priorities       : PrioritySet := {}
  deriving Inhabited

def addDefaultInstanceEntry (d : DefaultInstances) (e : DefaultInstanceEntry) : DefaultInstances :=
  let d := { d with priorities := d.priorities.insert e.priority }
  match d.defaultInstances.find? e.className with
  | some insts => { d with defaultInstances := d.defaultInstances.insert e.className <| (e.instanceName, e.priority) :: insts }
  | none       => { d with defaultInstances := d.defaultInstances.insert e.className [(e.instanceName, e.priority)] }

builtin_initialize defaultInstanceExtension : SimplePersistentEnvExtension DefaultInstanceEntry DefaultInstances ←
  registerSimplePersistentEnvExtension {
    name          := `defaultInstanceExt
    addEntryFn    := addDefaultInstanceEntry
    addImportedFn := fun es => (mkStateFromImportedEntries addDefaultInstanceEntry {} es)
  }

def addDefaultInstance (declName : Name) (prio : Nat := 0) : MetaM Unit := do
  match (← getEnv).find? declName with
  | none => throwError! "unknown constant '{declName}'"
  | some info =>
    forallTelescopeReducing info.type fun _ type => do
      match type.getAppFn with
      | Expr.const className _ _ =>
        unless isClass (← getEnv) className do
          throwError! "invalid default instance '{declName}', it has type '({className} ...)', but {className}' is not a type class"
        setEnv <| defaultInstanceExtension.addEntry (← getEnv) { className := className, instanceName := declName, priority := prio }
      | _ => throwError! "invalid default instance '{declName}', type must be of the form '(C ...)' where 'C' is a type class"

builtin_initialize
  registerBuiltinAttribute {
    name  := `defaultInstance
    descr := "type class default instance"
    add   := fun declName stx kind => do
      let prio ← getAttrParamOptPrio stx[1]
      unless kind == AttributeKind.global do throwError "invalid attribute 'defaultInstance', must be global"
      discard <| addDefaultInstance declName prio |>.run {} {}
  }

def getDefaultInstancesPriorities [Monad m] [MonadEnv m] : m PrioritySet :=
  return defaultInstanceExtension.getState (← getEnv) |>.priorities

def getDefaultInstances [Monad m] [MonadEnv m] (className : Name) : m (List (Name × Nat)) :=
  return defaultInstanceExtension.getState (← getEnv) |>.defaultInstances.find? className |>.getD []

end Lean.Meta
