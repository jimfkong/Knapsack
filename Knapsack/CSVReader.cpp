#include "CSVReader.h"

#include "Utilities.h"

std::vector<std::vector<std::string>> CSVReader::ReadFile(const std::string& inputPath)
{
	auto lines = Utilities::ReadLineByLine(inputPath);

	std::vector<std::vector<std::string>> csvFile;

	for (auto it = lines.begin(); it != lines.end(); it++)
	{
		csvFile.push_back(Utilities::SplitLine(*it, ','));
	}

	return csvFile;
}