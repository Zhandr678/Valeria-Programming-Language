#include "ParserException.h"

namespace val
{

	ParserException::ParserException(const std::string& msg, const std::string& filename, val::selector sel, size_t line)
		: std::logic_error("ParserException: [" + msg + "], \
			\n\tin Statement: [" + sel.getcstring() + "]" +
			"\n\tin File: [" + filename + "]" +
			"\n\tline " + std::to_string(line))
	{
	}

	ParserException::ParserException(const std::string& filename, val::selector sel, size_t line)
		: std::logic_error("ParserException: \
			\n\tin Statement: [" + sel.getcstring() + "]" +
			"\n\tin File: [" + filename + "]" +
			"\n\tline " + std::to_string(line))
	{
	}

}