#pragma once

#include <exception>
#include <string>

#include "Token.h"

namespace val
{
	class LexerException : public std::logic_error
	{
	public:
		explicit LexerException(const std::string& msg, const std::string& filename, size_t line, size_t at);
		explicit LexerException(const std::string& msg, Location loc);
		explicit LexerException(const std::string& msg);

		LexerException() = default;
		LexerException(const LexerException& other) = default;
		LexerException& operator =(const LexerException& other) = default;
		LexerException(LexerException&& other) noexcept = default;
		LexerException& operator =(LexerException&& other) noexcept = default;

		~LexerException() = default;
	};
}