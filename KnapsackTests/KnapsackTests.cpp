#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../Knapsack/Knapsack.h"

TEST(KnapsackTests, CalculateKnapsack_ShouldReturnOptimalSolution)
{
	std::vector<std::shared_ptr<KnapsackItem>> items;

	items.push_back(std::make_shared<KnapsackItem>("1", 100, 3));
	items.push_back(std::make_shared<KnapsackItem>("2", 20, 2));
	items.push_back(std::make_shared<KnapsackItem>("3", 60, 4));
	items.push_back(std::make_shared<KnapsackItem>("4", 40, 1));

	auto maxWeight = 5;

	Knapsack algo;
	auto result = algo.calculateKnapsack(items, maxWeight);

	std::vector<std::string> resultNames;
	std::for_each(begin(result), end(result), [&resultNames](auto item) {
		resultNames.push_back(item->getName());
	});

	EXPECT_THAT(resultNames, testing::WhenSorted(testing::ElementsAre("1", "4")));
}

TEST(KnapsackTests, CalculateKnapsack_ShouldReturnEmpty_IfOnlyOneItemExceedsMaxWeight)
{
	std::vector<std::shared_ptr<KnapsackItem>> items;

	items.push_back(std::make_shared<KnapsackItem>("1", 1, 5));

	auto maxWeight = 1;

	Knapsack algo;
	auto result = algo.calculateKnapsack(items, maxWeight);

	ASSERT_EQ(0, result.size());
}

TEST(KnapsackTests, CalculateKnapsack_ShouldReturnEmpty_IfInputArrayIsEmpty)
{
	std::vector<std::shared_ptr<KnapsackItem>> items;

	auto maxWeight = 1;

	Knapsack algo;
	auto result = algo.calculateKnapsack(items, maxWeight);

	ASSERT_EQ(0, result.size());
}
