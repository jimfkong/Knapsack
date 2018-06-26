#include "InputParser.h"

#include "CSVReader.h"

InputParser::InputParser()
{}

InputParser::~InputParser()
{}

std::vector<std::shared_ptr<KnapsackItem>> InputParser::Parse(const std::string& inputPath)
{
	auto reader = std::make_shared<CSVReader>();
	std::vector<std::shared_ptr<KnapsackItem>> items;

	auto csvFile = reader->ReadFile(inputPath);

	//for (auto line = csvFile.begin(); line != csvFile.end(); line++)
	//{
	//	// TODO Get rid of magic numbers
	//	// TODO Input validation
	//	auto item = std::make_shared<KnapsackItem>(line->at(0), line->at(1), line->at(2));
	//	items.push_back(item);
	//}

	return items;
}