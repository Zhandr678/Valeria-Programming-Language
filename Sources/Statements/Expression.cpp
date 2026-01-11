
// This code was automatically built by TreeGen
// Written by Hans de Nivelle, see www.compiler-tools.eu

#include "Expression.h"

val::Expression::Expression( const Expression& from )
   : _ssss( from. _ssss )
{
   // std::cout << "Expression( const Expression& " << from. _ssss << " )";
   
   switch( from. _ssss )
   {
   case BinaryExpr:
      tvm::init( repr. _fld00. loc, from. repr. _fld00. loc );
      repr. _fld00. heap = takeshare( from. repr. _fld00. heap );
      break;
   case BoolLiteralExpr:
      tvm::init( repr. _fld01. loc, from. repr. _fld01. loc );
      break;
   case CharLiteralExpr:
      tvm::init( repr. _fld02. loc, from. repr. _fld02. loc );
      break;
   case DoubleLiteralExpr:
      tvm::init( repr. _fld03. loc, from. repr. _fld03. loc );
      break;
   case EmptyExpr:
      break;
   case FnCallExpr:
      tvm::init( repr. _fld05. loc, from. repr. _fld05. loc );
      repr. _fld05. heap = takeshare( from. repr. _fld05. heap );
      break;
   case IntLiteralExpr:
      tvm::init( repr. _fld06. loc, from. repr. _fld06. loc );
      break;
   case StringLiteralExpr:
   case VarNameExpr:
      tvm::init( repr. _fld07. loc, from. repr. _fld07. loc );
      break;
   case UnaryExpr:
      tvm::init( repr. _fld08. loc, from. repr. _fld08. loc );
      repr. _fld08. heap = takeshare( from. repr. _fld08. heap );
      break;
   }
}

val::Expression::Expression( Expression&& from ) noexcept
   : _ssss( from. _ssss )
{
   // std::cout << "Expression( Expression&& " << from. _ssss << " )";
   
   switch( from. _ssss )
   {
   case BinaryExpr:
      tvm::init( repr. _fld00. loc, std::move( from. repr. _fld00. loc ) );
      tvm::destroy( from. repr. _fld00. loc );
      repr. _fld00. heap = from. repr. _fld00. heap;
      break;
   case BoolLiteralExpr:
      tvm::init( repr. _fld01. loc, std::move( from. repr. _fld01. loc ) );
      tvm::destroy( from. repr. _fld01. loc );
      break;
   case CharLiteralExpr:
      tvm::init( repr. _fld02. loc, std::move( from. repr. _fld02. loc ) );
      tvm::destroy( from. repr. _fld02. loc );
      break;
   case DoubleLiteralExpr:
      tvm::init( repr. _fld03. loc, std::move( from. repr. _fld03. loc ) );
      tvm::destroy( from. repr. _fld03. loc );
      break;
   case EmptyExpr:
      break;
   case FnCallExpr:
      tvm::init( repr. _fld05. loc, std::move( from. repr. _fld05. loc ) );
      tvm::destroy( from. repr. _fld05. loc );
      repr. _fld05. heap = from. repr. _fld05. heap;
      break;
   case IntLiteralExpr:
      tvm::init( repr. _fld06. loc, std::move( from. repr. _fld06. loc ) );
      tvm::destroy( from. repr. _fld06. loc );
      break;
   case StringLiteralExpr:
   case VarNameExpr:
      tvm::init( repr. _fld07. loc, std::move( from. repr. _fld07. loc ) );
      tvm::destroy( from. repr. _fld07. loc );
      break;
   case UnaryExpr:
      tvm::init( repr. _fld08. loc, std::move( from. repr. _fld08. loc ) );
      tvm::destroy( from. repr. _fld08. loc );
      repr. _fld08. heap = from. repr. _fld08. heap;
      break;
   }

   // Leave from in trivial state:
   
   from. _ssss = EmptyExpr;
   new (&from. repr) options( );
}

// Note that the implementation of assignment is minimalistic.
// One should create special cases for when *this and from are 
// in the same state.

const val::Expression & val::Expression::operator = ( const Expression& from )
{
   if( this == &from )
      return *this;
   
   switch( from. _ssss )
   {
   case BinaryExpr:
      takeshare( from. repr. _fld00. heap );
      break;
   case FnCallExpr:
      takeshare( from. repr. _fld05. heap );
      break;
   case UnaryExpr:
      takeshare( from. repr. _fld08. heap );
      break;
   }

   this -> ~Expression( );
   
   _ssss = from. _ssss;
   
   switch( _ssss )
   {
   case BinaryExpr:
      tvm::init( repr. _fld00. loc, from. repr. _fld00. loc );
      repr. _fld00. heap = from. repr. _fld00. heap;
      break;
   case BoolLiteralExpr:
      tvm::init( repr. _fld01. loc, from. repr. _fld01. loc );
      break;
   case CharLiteralExpr:
      tvm::init( repr. _fld02. loc, from. repr. _fld02. loc );
      break;
   case DoubleLiteralExpr:
      tvm::init( repr. _fld03. loc, from. repr. _fld03. loc );
      break;
   case EmptyExpr:
      break;
   case FnCallExpr:
      tvm::init( repr. _fld05. loc, from. repr. _fld05. loc );
      repr. _fld05. heap = from. repr. _fld05. heap;
      break;
   case IntLiteralExpr:
      tvm::init( repr. _fld06. loc, from. repr. _fld06. loc );
      break;
   case StringLiteralExpr:
   case VarNameExpr:
      tvm::init( repr. _fld07. loc, from. repr. _fld07. loc );
      break;
   case UnaryExpr:
      tvm::init( repr. _fld08. loc, from. repr. _fld08. loc );
      repr. _fld08. heap = from. repr. _fld08. heap;
      break;
   }

   return *this;
}

// We don't check self assignment in the moving case, because it is UB:

const val::Expression & val::Expression::operator = ( Expression&& from ) noexcept
{
   if( _ssss == from. _ssss )
   {
      switch( _ssss )
      {
      case BinaryExpr:
         tvm::assign( repr. _fld00. loc, std::move( from. repr. _fld00. loc ) );
         tvm::destroy( from. repr. _fld00. loc );
         dropshare( repr. _fld00. heap );
         repr. _fld00. heap = from. repr. _fld00. heap;
         break;
      case BoolLiteralExpr:
         tvm::assign( repr. _fld01. loc, std::move( from. repr. _fld01. loc ) );
         tvm::destroy( from. repr. _fld01. loc );
         break;
      case CharLiteralExpr:
         tvm::assign( repr. _fld02. loc, std::move( from. repr. _fld02. loc ) );
         tvm::destroy( from. repr. _fld02. loc );
         break;
      case DoubleLiteralExpr:
         tvm::assign( repr. _fld03. loc, std::move( from. repr. _fld03. loc ) );
         tvm::destroy( from. repr. _fld03. loc );
         break;
      case EmptyExpr:
         break;
      case FnCallExpr:
         tvm::assign( repr. _fld05. loc, std::move( from. repr. _fld05. loc ) );
         tvm::destroy( from. repr. _fld05. loc );
         dropshare( repr. _fld05. heap );
         repr. _fld05. heap = from. repr. _fld05. heap;
         break;
      case IntLiteralExpr:
         tvm::assign( repr. _fld06. loc, std::move( from. repr. _fld06. loc ) );
         tvm::destroy( from. repr. _fld06. loc );
         break;
      case StringLiteralExpr:
      case VarNameExpr:
         tvm::assign( repr. _fld07. loc, std::move( from. repr. _fld07. loc ) );
         tvm::destroy( from. repr. _fld07. loc );
         break;
      case UnaryExpr:
         tvm::assign( repr. _fld08. loc, std::move( from. repr. _fld08. loc ) );
         tvm::destroy( from. repr. _fld08. loc );
         dropshare( repr. _fld08. heap );
         repr. _fld08. heap = from. repr. _fld08. heap;
         break;
      }

      // Leave from in trivial state:

      from. _ssss = EmptyExpr;
      new (&from. repr) options( );
      return *this;
   }
   else
   {
      // I believe that this wll be safe, because we have
      // the only reference to other: 

      this -> ~Expression( );

      new (this) Expression( std::move( from ));
      return *this;
   }
}

val::Expression::~Expression( ) noexcept
{
   // If there are prefix fields, they will be destroyed automatically

   switch( _ssss )
   {
   case BinaryExpr:
      tvm::destroy( repr. _fld00. loc );
      dropshare( repr. _fld00. heap );
      break;
   case BoolLiteralExpr:
      tvm::destroy( repr. _fld01. loc );
      break;
   case CharLiteralExpr:
      tvm::destroy( repr. _fld02. loc );
      break;
   case DoubleLiteralExpr:
      tvm::destroy( repr. _fld03. loc );
      break;
   case EmptyExpr:
      break;
   case FnCallExpr:
      tvm::destroy( repr. _fld05. loc );
      dropshare( repr. _fld05. heap );
      break;
   case IntLiteralExpr:
      tvm::destroy( repr. _fld06. loc );
      break;
   case StringLiteralExpr:
   case VarNameExpr:
      tvm::destroy( repr. _fld07. loc );
      break;
   case UnaryExpr:
      tvm::destroy( repr. _fld08. loc );
      dropshare( repr. _fld08. heap );
      break;
   }
}

bool val::Expression::very_equal_to( const Expression & other ) const
{
   if( _ssss != other. _ssss )
      return false;

   switch( _ssss )
   {
   case BinaryExpr:
      if( tvm::distinct( repr. _fld00. loc, other. repr. _fld00. loc ))
         return false;
      if( repr. _fld00. heap != other. repr. _fld00. heap )
         return false;
      return true;
   case BoolLiteralExpr:
      if( tvm::distinct( repr. _fld01. loc, other. repr. _fld01. loc ))
         return false;
      return true;
   case CharLiteralExpr:
      if( tvm::distinct( repr. _fld02. loc, other. repr. _fld02. loc ))
         return false;
      return true;
   case DoubleLiteralExpr:
      if( tvm::distinct( repr. _fld03. loc, other. repr. _fld03. loc ))
         return false;
      return true;
   case EmptyExpr:
      return true;
   case FnCallExpr:
      if( tvm::distinct( repr. _fld05. loc, other. repr. _fld05. loc ))
         return false;
      if( repr. _fld05. heap != other. repr. _fld05. heap )
         return false;
      return true;
   case IntLiteralExpr:
      if( tvm::distinct( repr. _fld06. loc, other. repr. _fld06. loc ))
         return false;
      return true;
   case StringLiteralExpr:
   case VarNameExpr:
      if( tvm::distinct( repr. _fld07. loc, other. repr. _fld07. loc ))
         return false;
      return true;
   case UnaryExpr:
      if( tvm::distinct( repr. _fld08. loc, other. repr. _fld08. loc ))
         return false;
      if( repr. _fld08. heap != other. repr. _fld08. heap )
         return false;
      return true;
   }
}

void val::Expression::printstate( std::ostream& out ) const
{
   switch( _ssss )
   {
   case BinaryExpr:
      tvm::printstate( repr. _fld00. heap, out );
      break;
   case FnCallExpr:
      tvm::printstate( repr. _fld05. heap, out );
      break;
   case UnaryExpr:
      tvm::printstate( repr. _fld08. heap, out );
      break;
   }
}

