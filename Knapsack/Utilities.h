#pragma once

#ifndef UTILITIES_H
#define UTILITIES_H

#include <vector>

static class Utilities
{
public:
	static std::vector<std::string> ReadLineByLine(const std::string& inputPath);
	static std::vector<std::string> SplitLine(const std::string& input, const char delim);
private:
	static std::ifstream OpenFile(const std::string& path);
};

#endif