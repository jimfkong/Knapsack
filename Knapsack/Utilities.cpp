#include "Utilities.h"

#include <fstream>
#include <sstream>
#include <string>

std::ifstream Utilities::OpenFile(const std::string& path)
{
	std::ifstream ifs;

	try
	{
		ifs.open(path);
	}
	catch (std::ifstream::failure failure)
	{
		throw failure;
	}

	return ifs;
}

std::vector<std::string> Utilities::ReadLineByLine(const std::string& inputFile)
{
	std::string line;
	std::vector<std::string> output;

	auto ifs = OpenFile(inputFile);

	if (ifs.is_open())
	{
		while (getline(ifs, line))
		{
			output.push_back(line);
		}
	}

	return output;
}

std::vector<std::string> Utilities::SplitLine(const std::string& input, const char delim)
{
	std::vector<std::string> result;
	std::stringstream ssInput(input);
	std::string token;
	while (std::getline(ssInput, token, delim))
	{
		result.push_back(token);
	}

	return result;
}