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
		if (not pending.empty())
		{
			Statement next_st = std::move(pending.front());
			pending.pop();
			return next_st;
		}

		if (eof) { return Statement(EmptyStmt); }

		if (GetNextPeeked().label == TokenLabel::_EOF_)
		{
			eof = true;
			return Statement(EmptyStmt);
		}

		next = 0;

		if (auto st = AnalyzeExpressionStatement())    return *st;
		if (auto st = AnalyzeInitalizationStatement()) return *st;
		if (auto st = AnalyzeConditionStatement())     return *st;
		if (auto st = AnalyzeForLoopStatement())       return *st;
		if (auto st = AnalyzeWhileLoopStatement())     return *st;
		if (auto st = AnalyzeMakeEnumStatement())      return *st;
		if (auto st = AnalyzeMakeFunctionStatement())  return *st;
		if (auto st = AnalyzeMakeStructStatement())    return *st;
		if (auto st = AnalyzeMatchStatement())         return *st; 

		throw ParserException("Unknown Statement", GetFileName(), EmptyExpr, GetLine());
	}

	std::string Parser::GetFileName() const
	{
		return lexer.GetFileName();
	}

	size_t Parser::GetLine() const
	{
		return lexer.GetLine();
	}

	size_t Parser::GetColumn() const
	{
		return lexer.GetColumn();
	}

	Token Parser::GetNextImportantToken()
	{
		Token next = lexer.ReadAndClassifyNext();

		while (next.label == TokenLabel::COM_BLOCK || next.label == TokenLabel::COM_LINE || next.label == TokenLabel::SYM_SEMICOLON)
		{
			next = lexer.ReadAndClassifyNext();
		}

		return next;
	}

	Token Parser::GetNextPeeked()
	{
		if (next >= peeked.size())
		{
			peeked.push_back(GetNextImportantToken());
		}

		return peeked[next++];
	}

	std::optional<Statement> Parser::AnalyzeInitalizationStatement()
	{
		Token type_token = GetNextPeeked();

		if (type_token.label != TokenLabel::KW_INT || type_token.label != TokenLabel::KW_DOUBLE || type_token.label != TokenLabel::KW_CHAR ||
			type_token.label != TokenLabel::KW_STRING || type_token.label != TokenLabel::KW_BOOL || type_token.label != TokenLabel::IDENTIFIER)
		{
			next = 0;
			return std::nullopt;
		}

		Token next_token = GetNextPeeked();
		while (next_token.label != TokenLabel::SYM_SEMICOLON)
		{
			Token varname_token = std::move(next_token);

			if (varname_token.label != TokenLabel::IDENTIFIER)
			{
				throw; // initialization of variable with forbidden name;
			}

			next_token = GetNextPeeked();

			if (next_token.label == TokenLabel::SYM_COMMA)
			{
				next_token = GetNextPeeked();
				pending.emplace(Statement(VarInitStmt, Expression(EmptyExpr), varname_token.attr, type_token.attr));
				continue;
			}

			if (next_token.label == TokenLabel::SYM_EQUAL)
			{
				auto expr = AnalyzeExpressionStatement();
				if (not expr.has_value()) 
				{ 
					throw; // no expression after equal symbol
				}
				pending.emplace(Statement(VarInitStmt, expr->view_ExprCall().expr(), varname_token.attr, type_token.attr));
				next_token = GetNextPeeked();
				if (next_token.label == TokenLabel::SYM_COMMA)
				{ 
					next_token = GetNextPeeked();
					continue;
				}
			}
		}

		next = 0;
		peeked.clear();
		Statement next_st = std::move(pending.front());
		pending.pop();
		return next_st;
	}

	std::optional<Statement> Parser::AnalyzeAssignmentStatement()
	{
		return std::optional<Statement>();
	}

	std::optional<Statement> Parser::AnalyzeConditionStatement()
	{
		if (GetNextPeeked().label != TokenLabel::KW_IF)
		{
			next = 0;
			return std::nullopt;
		}

		if (GetNextPeeked().label != TokenLabel::SYM_LPAR)
		{
			throw; // no ( after if
		}

		auto expr = AnalyzeExpressionStatement();
		
		if (not expr.has_value())
		{
			throw; // no expression inside if
		}

		if (GetNextPeeked().label != TokenLabel::SYM_RPAR)
		{
			throw; // no ) after if (expr
		}

		if (GetNextPeeked().label != TokenLabel::SYM_LBRACE)
		{
			throw; // no { after if (expr)
		}

		Statement if_then = GetNextStatement();

		if (GetNextPeeked().label != TokenLabel::SYM_RBRACE)
		{
			throw; // no } after if (expr) { stmts 
		}
		return if_then;
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