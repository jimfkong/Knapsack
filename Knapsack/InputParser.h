#pragma once

#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include "KnapsackItem.h"

#include <vector>
#include <memory>

class InputParser
{
public:
	InputParser();
	~InputParser();

	std::vector<std::shared_ptr<KnapsackItem>> Parse(const std::string& inputPath);
};

#endif