#pragma once

#include "Lexing/Lexer.h"
#include "Statements/Statement.h"
#include <variant>
#include <vector>
#include <queue>

namespace val 
{
	class Parser
	{
	private:
		Lexer lexer;
		bool eof = false;

		std::vector <Token> peeked;
		size_t next;

		std::queue <Statement> pending;

		Token GetNextImportantToken();
		Token GetNextPeeked();

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

		std::string GetFileName() const;
		size_t GetLine() const;
		size_t GetColumn() const;

		~Parser() = default;
	};

}