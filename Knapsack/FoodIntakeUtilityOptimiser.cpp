#include <iostream>

#include "Knapsack.h"

int main()
{
	std::vector<std::shared_ptr<KnapsackItem>> items;

	items.push_back(std::make_shared<KnapsackItem>("1", 100, 3));
	items.push_back(std::make_shared<KnapsackItem>("2", 20, 2));
	items.push_back(std::make_shared<KnapsackItem>("3", 60, 4));
	items.push_back(std::make_shared<KnapsackItem>("4", 40, 1));

	auto maxWeight = 5;

	Knapsack algo;
	auto result = algo.calculateKnapsack(items, maxWeight);
	std::cout << "Hello, World!" << std::endl;
}