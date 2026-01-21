
// This code was automatically built by TreeGen
// Written by Hans de Nivelle, see www.compiler-tools.eu

#ifndef VAL_SELECTOR_
#define VAL_SELECTOR_

#include <iostream>


namespace val { 

   enum selector
   {      
      ArrayIndexExpr, BinaryExpr, BoolLiteralExpr, CharLiteralExpr, 
      DoubleLiteralExpr, FieldCallExpr, EmptyExpr, VarInitStmt, 
      FnCallExpr, InitListExpr, IntLiteralExpr, StringLiteralExpr, 
      StructInitExpr, UnaryExpr, VarNameExpr, ElifConditionStmt, 
      ContinueStmt, CaseClauseStmt, ArrayInitStmt, BreakStmt, 
      AssignmentStmt, BlockOfStmt, ConditionStmt, MakePropertyStmt, 
      EmptyStmt, ForLoopStmt, MakeStructStmt, ExprCallStmt, 
      FnArgsStmt, MakeEnumStmt, MakeFunctionStmt, MatchStmt, 
      ReturnStmt, WhileLoopStmt
   };

   const char* getcstring( selector );

   inline std::ostream& operator << ( std::ostream& out, selector sel )
      { out << getcstring( sel ); return out; }

}


#endif


