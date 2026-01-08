#include "Parsing/Parser.h"

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
		return Statement();
	}
}