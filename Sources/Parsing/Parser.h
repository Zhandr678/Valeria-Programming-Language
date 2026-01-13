#pragma once

#include "Lexing/Lexer.h"
#include "Statements/Statement.h"
#include <variant>

namespace val 
{
	class Parser
	{
	private:
		Lexer lexer;
		bool eof = false;

		std::optional <Statement> AnalyzeInitalizationStatement();
		std::optional <Statement> AnalyzeAssignmentStatement();
		std::optional <Statement> AnalyzeConditionStatement();
		std::optional <Statement> AnalyzeForLoopStatement();
		std::optional <Statement> AnalyzeWhileLoopStatement();
		std::optional <Statement> AnalyzeMakeFunctionStatement();
		std::optional <Statement> AnalyzeMakeStructStatement();
		std::optional <Statement> AnalyzeMakePropertyStatement();
		std::optional <Statement> AnalyzeMakeEnumStatement();
		std::optional <Statement> AnalyzeMatchStatement();
		std::optional <Statement> AnalyzeExpressionStatement();

	public:
		explicit Parser(Lexer&& lexer);
		
		Parser() = delete;
		Parser(const Parser&) = delete;
		Parser& operator=(const Parser&) = delete;

		Parser(Parser&& parser) noexcept;
		Parser& operator=(Parser&& parser) noexcept;

		Statement GetNextStatement();

		~Parser() = default;
	};

}