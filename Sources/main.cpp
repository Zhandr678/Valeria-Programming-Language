#include <iostream>
#include <vector>
#include <string>
#include <variant>
#include <fstream>
#include <algorithm>
#include <format>

#include "Lexing/lexer.h"

#include "argsconfig.h"

int main(int argc, char* argv[])
{

#pragma region("Argument Parsing")

	cxxopts::Options args(val::PROGRAM_NAME, val::PROGRAM_DESC);
	val::AddOptions(args, val::OPTIONS);

	cxxopts::ParseResult result;
	if (not val::AssertCorrectOptions(result, argc, argv, args))
	{
		return 1;
	}

#pragma endregion



#pragma region("Lexical Analysis")

	std::filesystem::path val_source_path = result["file"].as<std::string>();
	std::ifstream in(val_source_path);
	
	val::Lexer lexer(lexing::filereader(&in, val_source_path.filename().string()));

	try {
		auto t = lexer.ReadAndClassifyNext();
		while (t.label != val::TokenLabel::_EOF_)
		{
			std::cout << std::format("[\n\tLabel: {},\n\tValue: {},\n\tLocation: {} {}\n]\n", t.label, t.attr, t.loc.line, t.loc.at);
			t = lexer.ReadAndClassifyNext();
		}
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << '\n';
	}

#pragma endregion



	std::cout << "Compilation Finished\n";
	return 0;
}

// std::ifstream in("C:/Users/sagin/Desktop/exprog.val");
// lexing::filereader f(&in, "C:/Users/sagin/Desktop/exprog.val");