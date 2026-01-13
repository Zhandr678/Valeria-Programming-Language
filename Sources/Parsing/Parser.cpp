#include "Parser.h"

#include "ParserException.h"

namespace val 
{

	Parser::Parser(Lexer&& lexer) 
		: lexer(std::move(lexer)) 
	{
	}

	Parser::Parser(Parser&& parser) noexcept 
		: lexer(std::move(parser.lexer))
	{
	}

	Parser& Parser::operator=(Parser&& parser) noexcept
	{
		this->lexer = std::move(parser.lexer);
		return *this;
	}

	Statement Parser::GetNextStatement()
	{
		if (eof || lexer.ReadAndClassifyNext().label == TokenLabel::_EOF_) 
		{
			eof = true;
			return val::Statement(val::EmptyStmt);
		}

		if (auto st = AnalyzeAssignmentStatement())    return *st;
		if (auto st = AnalyzeInitalizationStatement()) return *st;
		if (auto st = AnalyzeExpressionStatement())    return *st;
		if (auto st = AnalyzeConditionStatement())     return *st;
		if (auto st = AnalyzeForLoopStatement())       return *st;
		if (auto st = AnalyzeWhileLoopStatement())     return *st;
		if (auto st = AnalyzeMakeEnumStatement())      return *st;
		if (auto st = AnalyzeMakeFunctionStatement())  return *st;
		if (auto st = AnalyzeMakeStructStatement())    return *st;
		if (auto st = AnalyzeMatchStatement())         return *st; 

		throw ParserException("Unknown Statement", lexer.GetFileName(), EmptyExpr, lexer.GetLine());
	}

	std::optional<Statement> Parser::AnalyzeInitalizationStatement()
	{
		return std::optional<Statement>();
	}

	std::optional<Statement> Parser::AnalyzeAssignmentStatement()
	{
		return std::optional<Statement>();
	}

	std::optional<Statement> Parser::AnalyzeConditionStatement()
	{
		return std::optional<Statement>();
	}

	std::optional<Statement> Parser::AnalyzeForLoopStatement()
	{
		return std::optional<Statement>();
	}

	std::optional<Statement> Parser::AnalyzeWhileLoopStatement()
	{
		return std::optional<Statement>();
	}

	std::optional<Statement> Parser::AnalyzeMakeFunctionStatement()
	{
		return std::optional<Statement>();
	}

	std::optional<Statement> Parser::AnalyzeMakeStructStatement()
	{
		return std::optional<Statement>();
	}

	std::optional<Statement> Parser::AnalyzeMakePropertyStatement()
	{
		return std::optional<Statement>();
	}

	std::optional<Statement> Parser::AnalyzeMakeEnumStatement()
	{
		return std::optional<Statement>();
	}

	std::optional<Statement> Parser::AnalyzeMatchStatement()
	{
		return std::optional<Statement>();
	}

	std::optional<Statement> Parser::AnalyzeExpressionStatement()
	{
		return std::optional<Statement>();
	}

}