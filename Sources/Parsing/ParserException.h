#pragma once

#include <string>
#include <exception>

#include "Statement/selector.h"

namespace val 
{

	class ParserException
	{
	public:
		explicit ParserException(const std::string& msg, const std::string& filename, val::selector sel, size_t line);
		explicit ParserException(const std::string& filename, val::selector sel, size_t line);

		ParserException() = default;
		ParserException(const ParserException& other) = default;
		ParserException& operator =(const ParserException& other) = default;
		ParserException(ParserException&& other) noexcept = default;
		ParserException& operator =(ParserException&& other) noexcept = default;

		~ParserException() = default;
	};

}