#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../Knapsack/Knapsack.h"
#include "../Knapsack/KnapsackUtilities.h"

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

	auto resultNames = KnapsackUtilities::getKnapsackItemNames(result);

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

TEST(KnapsackTests, CalculateKnapsack_ShouldReturnOptimalSolution_IfInputHasOneItem)
{
	std::vector<std::shared_ptr<KnapsackItem>> items;
	items.push_back(std::make_shared<KnapsackItem>("1", 100, 3));

	auto maxWeight = 4;

	Knapsack algo;
	auto result = algo.calculateKnapsack(items, maxWeight);

	auto resultNames = KnapsackUtilities::getKnapsackItemNames(result);

	EXPECT_THAT(resultNames, testing::WhenSorted(testing::ElementsAre("1")));
}

TEST(KnapsackTests, CalculateKnapsack_ShouldReturnOptimalSolution_IfSumOfValuesBelowMax)
{
	std::vector<std::shared_ptr<KnapsackItem>> items;
	items.push_back(std::make_shared<KnapsackItem>("1", 100, 3));
	items.push_back(std::make_shared<KnapsackItem>("2", 100, 4));
	items.push_back(std::make_shared<KnapsackItem>("3", 100, 2));
	items.push_back(std::make_shared<KnapsackItem>("4", 100, 5));
	items.push_back(std::make_shared<KnapsackItem>("5", 100, 5));
	items.push_back(std::make_shared<KnapsackItem>("6", 100, 1));

	auto maxWeight = 50;

	Knapsack algo;
	auto result = algo.calculateKnapsack(items, maxWeight);

	auto resultNames = KnapsackUtilities::getKnapsackItemNames(result);

	EXPECT_THAT(resultNames, testing::WhenSorted(testing::ElementsAre("1", "2", "3", "4", "5", "6")));
}
