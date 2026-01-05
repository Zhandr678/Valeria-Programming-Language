#pragma once
#include "cxxopts.hpp"

namespace val
{
	struct CompilerOption
	{
		std::string option;
		std::string desc;
		std::shared_ptr <cxxopts::Value> value;
		bool required;
	};

	extern const std::string PROGRAM_NAME;
	extern const std::string PROGRAM_DESC;

	extern const std::vector <CompilerOption> OPTIONS;

	void AddOptions(cxxopts::Options& args, const std::vector <CompilerOption>& options);

	bool AssertCorrectOptions(cxxopts::ParseResult& result, int argc, char** argv, const cxxopts::Options& args);
};