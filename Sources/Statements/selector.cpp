
// This code was automatically built by TreeGen
// Written by Hans de Nivelle, see www.compiler-tools.eu

#include "selector.h"

const char* val::getcstring( selector sel )
{
   switch( sel )
   {
   case ArrayIndexExpr :
      return "ArrayIndexExpr";
   case BinaryExpr :
      return "BinaryExpr";
   case BoolLiteralExpr :
      return "BoolLiteralExpr";
   case CharLiteralExpr :
      return "CharLiteralExpr";
   case DoubleLiteralExpr :
      return "DoubleLiteralExpr";
   case FieldCallExpr :
      return "FieldCallExpr";
   case EmptyExpr :
      return "EmptyExpr";
   case VarInitStmt :
      return "VarInitStmt";
   case FnCallExpr :
      return "FnCallExpr";
   case InitListExpr :
      return "InitListExpr";
   case IntLiteralExpr :
      return "IntLiteralExpr";
   case StringLiteralExpr :
      return "StringLiteralExpr";
   case StructInitExpr :
      return "StructInitExpr";
   case UnaryExpr :
      return "UnaryExpr";
   case VarNameExpr :
      return "VarNameExpr";
   case ElifConditionStmt :
      return "ElifConditionStmt";
   case ContinueStmt :
      return "ContinueStmt";
   case CaseClauseStmt :
      return "CaseClauseStmt";
   case ArrayInitStmt :
      return "ArrayInitStmt";
   case BreakStmt :
      return "BreakStmt";
   case AssignmentStmt :
      return "AssignmentStmt";
   case BlockOfStmt :
      return "BlockOfStmt";
   case ConditionStmt :
      return "ConditionStmt";
   case MakePropertyStmt :
      return "MakePropertyStmt";
   case EmptyStmt :
      return "EmptyStmt";
   case ForLoopStmt :
      return "ForLoopStmt";
   case MakeStructStmt :
      return "MakeStructStmt";
   case ExprCallStmt :
      return "ExprCallStmt";
   case FnArgsStmt :
      return "FnArgsStmt";
   case MakeEnumStmt :
      return "MakeEnumStmt";
   case MakeFunctionStmt :
      return "MakeFunctionStmt";
   case MatchStmt :
      return "MatchStmt";
   case ReturnStmt :
      return "ReturnStmt";
   case WhileLoopStmt :
      return "WhileLoopStmt";
   }
   return "???";
}

