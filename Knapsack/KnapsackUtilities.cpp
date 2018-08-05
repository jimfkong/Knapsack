#include <algorithm>

#include "KnapsackUtilities.h"

std::vector<std::string> KnapsackUtilities::getKnapsackItemNames(
	const std::vector<std::shared_ptr<KnapsackItem>>& knapsack)
{
	std::vector<std::string> resultNames;

	std::for_each(begin(knapsack), end(knapsack), [&resultNames](auto item) {
		resultNames.push_back(item->getName());
	});

	return resultNames;
}

int KnapsackUtilities::getKnapsackValue(
	const std::vector<std::shared_ptr<KnapsackItem>>& knapsack)
{
	auto value = 0;

	std::for_each(begin(knapsack), end(knapsack), [&value](auto item) {
		value += item->getValue();
	});

	return value;
}
