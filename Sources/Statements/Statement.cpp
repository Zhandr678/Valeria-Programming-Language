
// This code was automatically built by TreeGen
// Written by Hans de Nivelle, see www.compiler-tools.eu

#include "Statement.h"

val::Statement::Statement( const Statement& from )
   : _ssss( from. _ssss )
{
   // std::cout << "Statement( const Statement& " << from. _ssss << " )";
   
   switch( from. _ssss )
   {
   case BreakStmt:
   case ContinueStmt:
   case EmptyStmt:
      break;
   case CaseClauseStmt:
   case MakePropertyStmt:
   case MakeStructStmt:
   case MatchStmt:
      tvm::init( repr. _fld01. loc, from. repr. _fld01. loc );
      repr. _fld01. heap = takeshare( from. repr. _fld01. heap );
      break;
   case ConditionStmt:
      repr. _fld02. heap = takeshare( from. repr. _fld02. heap );
      break;
   case WhileLoopStmt:
   case ElifConditionStmt:
      repr. _fld03. heap = takeshare( from. repr. _fld03. heap );
      break;
   case ExprCallStmt:
   case ReturnStmt:
      repr. _fld04. heap = takeshare( from. repr. _fld04. heap );
      break;
   case FnArgStmt:
      tvm::init( get<0> ( repr. _fld05. loc ), get<0> ( from. repr. _fld05. loc ) );
      tvm::init( get<1> ( repr. _fld05. loc ), get<1> ( from. repr. _fld05. loc ) );
      tvm::init( get<2> ( repr. _fld05. loc ), get<2> ( from. repr. _fld05. loc ) );
      repr. _fld05. heap = takeshare( from. repr. _fld05. heap );
      break;
   case ForLoopStmt:
      repr. _fld06. heap = takeshare( from. repr. _fld06. heap );
      break;
   case MakeEnumStmt:
      tvm::init( repr. _fld07. loc, from. repr. _fld07. loc );
      repr. _fld07. heap = takeshare( from. repr. _fld07. heap );
      break;
   case MakeFunctionStmt:
      tvm::init( repr. _fld08. loc. first, from. repr. _fld08. loc. first );
      tvm::init( repr. _fld08. loc. second, from. repr. _fld08. loc. second );
      repr. _fld08. heap = takeshare( from. repr. _fld08. heap );
      break;
   case VarInitStmt:
      tvm::init( repr. _fld09. loc. first, from. repr. _fld09. loc. first );
      tvm::init( repr. _fld09. loc. second, from. repr. _fld09. loc. second );
      repr. _fld09. heap = takeshare( from. repr. _fld09. heap );
      break;
   }
}

val::Statement::Statement( Statement&& from ) noexcept
   : _ssss( from. _ssss )
{
   // std::cout << "Statement( Statement&& " << from. _ssss << " )";
   
   switch( from. _ssss )
   {
   case BreakStmt:
   case ContinueStmt:
   case EmptyStmt:
      break;
   case CaseClauseStmt:
   case MakePropertyStmt:
   case MakeStructStmt:
   case MatchStmt:
      tvm::init( repr. _fld01. loc, std::move( from. repr. _fld01. loc ) );
      tvm::destroy( from. repr. _fld01. loc );
      repr. _fld01. heap = from. repr. _fld01. heap;
      break;
   case ConditionStmt:
      repr. _fld02. heap = from. repr. _fld02. heap;
      break;
   case WhileLoopStmt:
   case ElifConditionStmt:
      repr. _fld03. heap = from. repr. _fld03. heap;
      break;
   case ExprCallStmt:
   case ReturnStmt:
      repr. _fld04. heap = from. repr. _fld04. heap;
      break;
   case FnArgStmt:
      tvm::init( get<0> ( repr. _fld05. loc ), std::move( get<0> ( from. repr. _fld05. loc ) ) );
      tvm::destroy( get<0> ( from. repr. _fld05. loc ) );
      tvm::init( get<1> ( repr. _fld05. loc ), std::move( get<1> ( from. repr. _fld05. loc ) ) );
      tvm::destroy( get<1> ( from. repr. _fld05. loc ) );
      tvm::init( get<2> ( repr. _fld05. loc ), std::move( get<2> ( from. repr. _fld05. loc ) ) );
      tvm::destroy( get<2> ( from. repr. _fld05. loc ) );
      repr. _fld05. heap = from. repr. _fld05. heap;
      break;
   case ForLoopStmt:
      repr. _fld06. heap = from. repr. _fld06. heap;
      break;
   case MakeEnumStmt:
      tvm::init( repr. _fld07. loc, std::move( from. repr. _fld07. loc ) );
      tvm::destroy( from. repr. _fld07. loc );
      repr. _fld07. heap = from. repr. _fld07. heap;
      break;
   case MakeFunctionStmt:
      tvm::init( repr. _fld08. loc. first, std::move( from. repr. _fld08. loc. first ) );
      tvm::destroy( from. repr. _fld08. loc. first );
      tvm::init( repr. _fld08. loc. second, std::move( from. repr. _fld08. loc. second ) );
      tvm::destroy( from. repr. _fld08. loc. second );
      repr. _fld08. heap = from. repr. _fld08. heap;
      break;
   case VarInitStmt:
      tvm::init( repr. _fld09. loc. first, std::move( from. repr. _fld09. loc. first ) );
      tvm::destroy( from. repr. _fld09. loc. first );
      tvm::init( repr. _fld09. loc. second, std::move( from. repr. _fld09. loc. second ) );
      tvm::destroy( from. repr. _fld09. loc. second );
      repr. _fld09. heap = from. repr. _fld09. heap;
      break;
   }

   // Leave from in trivial state:
   
   from. _ssss = EmptyStmt;
   new (&from. repr) options( );
}

// Note that the implementation of assignment is minimalistic.
// One should create special cases for when *this and from are 
// in the same state.

const val::Statement & val::Statement::operator = ( const Statement& from )
{
   if( this == &from )
      return *this;
   
   switch( from. _ssss )
   {
   case CaseClauseStmt:
   case MakePropertyStmt:
   case MakeStructStmt:
   case MatchStmt:
      takeshare( from. repr. _fld01. heap );
      break;
   case ConditionStmt:
      takeshare( from. repr. _fld02. heap );
      break;
   case WhileLoopStmt:
   case ElifConditionStmt:
      takeshare( from. repr. _fld03. heap );
      break;
   case ExprCallStmt:
   case ReturnStmt:
      takeshare( from. repr. _fld04. heap );
      break;
   case FnArgStmt:
      takeshare( from. repr. _fld05. heap );
      break;
   case ForLoopStmt:
      takeshare( from. repr. _fld06. heap );
      break;
   case MakeEnumStmt:
      takeshare( from. repr. _fld07. heap );
      break;
   case MakeFunctionStmt:
      takeshare( from. repr. _fld08. heap );
      break;
   case VarInitStmt:
      takeshare( from. repr. _fld09. heap );
      break;
   }

   this -> ~Statement( );
   
   _ssss = from. _ssss;
   
   switch( _ssss )
   {
   case BreakStmt:
   case ContinueStmt:
   case EmptyStmt:
      break;
   case CaseClauseStmt:
   case MakePropertyStmt:
   case MakeStructStmt:
   case MatchStmt:
      tvm::init( repr. _fld01. loc, from. repr. _fld01. loc );
      repr. _fld01. heap = from. repr. _fld01. heap;
      break;
   case ConditionStmt:
      repr. _fld02. heap = from. repr. _fld02. heap;
      break;
   case WhileLoopStmt:
   case ElifConditionStmt:
      repr. _fld03. heap = from. repr. _fld03. heap;
      break;
   case ExprCallStmt:
   case ReturnStmt:
      repr. _fld04. heap = from. repr. _fld04. heap;
      break;
   case FnArgStmt:
      tvm::init( get<0> ( repr. _fld05. loc ), get<0> ( from. repr. _fld05. loc ) );
      tvm::init( get<1> ( repr. _fld05. loc ), get<1> ( from. repr. _fld05. loc ) );
      tvm::init( get<2> ( repr. _fld05. loc ), get<2> ( from. repr. _fld05. loc ) );
      repr. _fld05. heap = from. repr. _fld05. heap;
      break;
   case ForLoopStmt:
      repr. _fld06. heap = from. repr. _fld06. heap;
      break;
   case MakeEnumStmt:
      tvm::init( repr. _fld07. loc, from. repr. _fld07. loc );
      repr. _fld07. heap = from. repr. _fld07. heap;
      break;
   case MakeFunctionStmt:
      tvm::init( repr. _fld08. loc. first, from. repr. _fld08. loc. first );
      tvm::init( repr. _fld08. loc. second, from. repr. _fld08. loc. second );
      repr. _fld08. heap = from. repr. _fld08. heap;
      break;
   case VarInitStmt:
      tvm::init( repr. _fld09. loc. first, from. repr. _fld09. loc. first );
      tvm::init( repr. _fld09. loc. second, from. repr. _fld09. loc. second );
      repr. _fld09. heap = from. repr. _fld09. heap;
      break;
   }

   return *this;
}

// We don't check self assignment in the moving case, because it is UB:

const val::Statement & val::Statement::operator = ( Statement&& from ) noexcept
{
   if( _ssss == from. _ssss )
   {
      switch( _ssss )
      {
      case BreakStmt:
      case ContinueStmt:
      case EmptyStmt:
         break;
      case CaseClauseStmt:
      case MakePropertyStmt:
      case MakeStructStmt:
      case MatchStmt:
         tvm::assign( repr. _fld01. loc, std::move( from. repr. _fld01. loc ) );
         tvm::destroy( from. repr. _fld01. loc );
         dropshare( repr. _fld01. heap );
         repr. _fld01. heap = from. repr. _fld01. heap;
         break;
      case ConditionStmt:
         dropshare( repr. _fld02. heap );
         repr. _fld02. heap = from. repr. _fld02. heap;
         break;
      case WhileLoopStmt:
      case ElifConditionStmt:
         dropshare( repr. _fld03. heap );
         repr. _fld03. heap = from. repr. _fld03. heap;
         break;
      case ExprCallStmt:
      case ReturnStmt:
         dropshare( repr. _fld04. heap );
         repr. _fld04. heap = from. repr. _fld04. heap;
         break;
      case FnArgStmt:
         tvm::assign( get<0> ( repr. _fld05. loc ), std::move( get<0> ( from. repr. _fld05. loc ) ) );
         tvm::destroy( get<0> ( from. repr. _fld05. loc ) );
         tvm::assign( get<1> ( repr. _fld05. loc ), std::move( get<1> ( from. repr. _fld05. loc ) ) );
         tvm::destroy( get<1> ( from. repr. _fld05. loc ) );
         tvm::assign( get<2> ( repr. _fld05. loc ), std::move( get<2> ( from. repr. _fld05. loc ) ) );
         tvm::destroy( get<2> ( from. repr. _fld05. loc ) );
         dropshare( repr. _fld05. heap );
         repr. _fld05. heap = from. repr. _fld05. heap;
         break;
      case ForLoopStmt:
         dropshare( repr. _fld06. heap );
         repr. _fld06. heap = from. repr. _fld06. heap;
         break;
      case MakeEnumStmt:
         tvm::assign( repr. _fld07. loc, std::move( from. repr. _fld07. loc ) );
         tvm::destroy( from. repr. _fld07. loc );
         dropshare( repr. _fld07. heap );
         repr. _fld07. heap = from. repr. _fld07. heap;
         break;
      case MakeFunctionStmt:
         tvm::assign( repr. _fld08. loc. first, std::move( from. repr. _fld08. loc. first ) );
         tvm::destroy( from. repr. _fld08. loc. first );
         tvm::assign( repr. _fld08. loc. second, std::move( from. repr. _fld08. loc. second ) );
         tvm::destroy( from. repr. _fld08. loc. second );
         dropshare( repr. _fld08. heap );
         repr. _fld08. heap = from. repr. _fld08. heap;
         break;
      case VarInitStmt:
         tvm::assign( repr. _fld09. loc. first, std::move( from. repr. _fld09. loc. first ) );
         tvm::destroy( from. repr. _fld09. loc. first );
         tvm::assign( repr. _fld09. loc. second, std::move( from. repr. _fld09. loc. second ) );
         tvm::destroy( from. repr. _fld09. loc. second );
         dropshare( repr. _fld09. heap );
         repr. _fld09. heap = from. repr. _fld09. heap;
         break;
      }

      // Leave from in trivial state:

      from. _ssss = EmptyStmt;
      new (&from. repr) options( );
      return *this;
   }
   else
   {
      // I believe that this wll be safe, because we have
      // the only reference to other: 

      this -> ~Statement( );

      new (this) Statement( std::move( from ));
      return *this;
   }
}

val::Statement::~Statement( ) noexcept
{
   // If there are prefix fields, they will be destroyed automatically

   switch( _ssss )
   {
   case BreakStmt:
   case ContinueStmt:
   case EmptyStmt:
      break;
   case CaseClauseStmt:
   case MakePropertyStmt:
   case MakeStructStmt:
   case MatchStmt:
      tvm::destroy( repr. _fld01. loc );
      dropshare( repr. _fld01. heap );
      break;
   case ConditionStmt:
      dropshare( repr. _fld02. heap );
      break;
   case WhileLoopStmt:
   case ElifConditionStmt:
      dropshare( repr. _fld03. heap );
      break;
   case ExprCallStmt:
   case ReturnStmt:
      dropshare( repr. _fld04. heap );
      break;
   case FnArgStmt:
      tvm::destroy( get<0> ( repr. _fld05. loc ) );
      tvm::destroy( get<1> ( repr. _fld05. loc ) );
      tvm::destroy( get<2> ( repr. _fld05. loc ) );
      dropshare( repr. _fld05. heap );
      break;
   case ForLoopStmt:
      dropshare( repr. _fld06. heap );
      break;
   case MakeEnumStmt:
      tvm::destroy( repr. _fld07. loc );
      dropshare( repr. _fld07. heap );
      break;
   case MakeFunctionStmt:
      tvm::destroy( repr. _fld08. loc. first );
      tvm::destroy( repr. _fld08. loc. second );
      dropshare( repr. _fld08. heap );
      break;
   case VarInitStmt:
      tvm::destroy( repr. _fld09. loc. first );
      tvm::destroy( repr. _fld09. loc. second );
      dropshare( repr. _fld09. heap );
      break;
   }
}

bool val::Statement::very_equal_to( const Statement & other ) const
{
   if( _ssss != other. _ssss )
      return false;

   switch( _ssss )
   {
   case BreakStmt:
   case ContinueStmt:
   case EmptyStmt:
      return true;
   case CaseClauseStmt:
   case MakePropertyStmt:
   case MakeStructStmt:
   case MatchStmt:
      if( tvm::distinct( repr. _fld01. loc, other. repr. _fld01. loc ))
         return false;
      if( repr. _fld01. heap != other. repr. _fld01. heap )
         return false;
      return true;
   case ConditionStmt:
      if( repr. _fld02. heap != other. repr. _fld02. heap )
         return false;
      return true;
   case WhileLoopStmt:
   case ElifConditionStmt:
      if( repr. _fld03. heap != other. repr. _fld03. heap )
         return false;
      return true;
   case ExprCallStmt:
   case ReturnStmt:
      if( repr. _fld04. heap != other. repr. _fld04. heap )
         return false;
      return true;
   case FnArgStmt:
      if( tvm::distinct( get<0> ( repr. _fld05. loc ), get<0> ( other. repr. _fld05. loc ) ))
         return false;
      if( tvm::distinct( get<1> ( repr. _fld05. loc ), get<1> ( other. repr. _fld05. loc ) ))
         return false;
      if( tvm::distinct( get<2> ( repr. _fld05. loc ), get<2> ( other. repr. _fld05. loc ) ))
         return false;
      if( repr. _fld05. heap != other. repr. _fld05. heap )
         return false;
      return true;
   case ForLoopStmt:
      if( repr. _fld06. heap != other. repr. _fld06. heap )
         return false;
      return true;
   case MakeEnumStmt:
      if( tvm::distinct( repr. _fld07. loc, other. repr. _fld07. loc ))
         return false;
      if( repr. _fld07. heap != other. repr. _fld07. heap )
         return false;
      return true;
   case MakeFunctionStmt:
      if( tvm::distinct( repr. _fld08. loc. first, other. repr. _fld08. loc. first ))
         return false;
      if( tvm::distinct( repr. _fld08. loc. second, other. repr. _fld08. loc. second ))
         return false;
      if( repr. _fld08. heap != other. repr. _fld08. heap )
         return false;
      return true;
   case VarInitStmt:
      if( tvm::distinct( repr. _fld09. loc. first, other. repr. _fld09. loc. first ))
         return false;
      if( tvm::distinct( repr. _fld09. loc. second, other. repr. _fld09. loc. second ))
         return false;
      if( repr. _fld09. heap != other. repr. _fld09. heap )
         return false;
      return true;
   }
}

void val::Statement::printstate( std::ostream& out ) const
{
   switch( _ssss )
   {
   case CaseClauseStmt:
   case MakePropertyStmt:
   case MakeStructStmt:
   case MatchStmt:
      tvm::printstate( repr. _fld01. heap, out );
      break;
   case ConditionStmt:
      tvm::printstate( repr. _fld02. heap, out );
      break;
   case WhileLoopStmt:
   case ElifConditionStmt:
      tvm::printstate( repr. _fld03. heap, out );
      break;
   case ExprCallStmt:
   case ReturnStmt:
      tvm::printstate( repr. _fld04. heap, out );
      break;
   case FnArgStmt:
      tvm::printstate( repr. _fld05. heap, out );
      break;
   case ForLoopStmt:
      tvm::printstate( repr. _fld06. heap, out );
      break;
   case MakeEnumStmt:
      tvm::printstate( repr. _fld07. heap, out );
      break;
   case MakeFunctionStmt:
      tvm::printstate( repr. _fld08. heap, out );
      break;
   case VarInitStmt:
      tvm::printstate( repr. _fld09. heap, out );
      break;
   }
}

