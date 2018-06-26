#pragma once

#ifndef KNAPSACKUTILITIES_H
#define KNAPSACKUTILITIES_H

#include <vector>
#include <memory>

#include "KnapsackItem.h"

class KnapsackUtilities
{
public:
	static std::vector<std::string> getKnapsackItemNames(
		const std::vector<std::shared_ptr<KnapsackItem>>& knapsack);
	static int getKnapsackValue(
		const std::vector<std::shared_ptr<KnapsackItem>>& knapsack);
};

#endif