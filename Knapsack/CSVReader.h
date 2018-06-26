#pragma once

#ifndef CSVREADER_H
#define CSVREADER_H

#include <vector>

static class CSVReader
{
public:
	std::vector<std::vector<std::string>> ReadFile(const std::string& inputPath);
};

#endif