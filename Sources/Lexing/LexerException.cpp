#include "LexerException.h"

namespace val 
{

	LexerException::LexerException(const std::string& msg, const std::string& filename, size_t line, size_t at)
		: std::logic_error("LexerException: [" + msg + "] \
			\n\tin File: [" + filename + "]" +
			"\n\tline " + std::to_string(line) + 
			"\n\tat " + std::to_string(at))
	{
	}

	LexerException::LexerException(const std::string& msg, Location loc)
		: std::logic_error("LexerException: [" + msg + "] \
			\n\tin File [" + loc.filename + "]" +
			"\n\tline " + std::to_string(loc.line) +
			"\n\tat " + std::to_string(loc.at))
	{
	}

	LexerException::LexerException(const std::string& msg)
		: std::logic_error("LexerException: [" + msg + "]")
	{
	}

}