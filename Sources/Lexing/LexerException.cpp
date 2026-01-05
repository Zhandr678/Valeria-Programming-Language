#include "LexerException.h"

namespace val 
{

	LexerException::LexerException(const std::string& msg, const std::string& filename, int line, int at)
		: std::runtime_error("[" + msg + "] in " + filename + "\nline " + std::to_string(line) + "\nat " + std::to_string(at))
	{
	}

	LexerException::LexerException(const std::string& msg, Location loc)
		: std::runtime_error("[" + msg + "] in " + loc.filename +
			"\nline " + std::to_string(loc.line) +
			"\nat " + std::to_string(loc.at))
	{
	}

	LexerException::LexerException(const std::string& msg)
		: std::runtime_error("[" + msg + "]")
	{
	}

}