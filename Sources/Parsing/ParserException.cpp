#include "ParserException.h"

namespace val
{

	ParserException::ParserException(const std::string& msg, const std::string& filename, selector sel, size_t line)
		: std::logic_error("ParserException: [" + msg + "], \
			\n\tin Statement: [" + getcstring(sel) + "]" +
			"\n\tin File: [" + filename + "]" +
			"\n\tline " + std::to_string(line))
	{
	}

}