import Lean
new_frontend

open Lean
open Lean.Elab
open Lean.Elab.Term

def getCtors (c : Name) : TermElabM (List Name) := do
let env ← getEnv;
match env.find? c with
| some (ConstantInfo.inductInfo val) =>
  pure val.ctors
| _ => pure []

def elabAnonCtor (args : Syntax) (τ : Expr) : TermElabM Expr := do
  match τ.getAppFn with
  | Expr.const C _ _ => do
    let ctors ← getCtors C;
    match ctors with
    | [c] => do
      let stx ← `($(Lean.mkIdent c) $(Array.getSepElems args.getArgs)*);
      elabTerm stx τ
-- error handling
    | _ => unreachable!
  | _ => unreachable!

elab "foo⟨" args:(sepBy term ", ") "⟩" : term <= τ => do
  elabAnonCtor args τ

example : Nat × Nat := foo⟨1, 2⟩
