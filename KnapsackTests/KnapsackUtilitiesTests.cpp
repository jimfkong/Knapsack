#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../Knapsack/KnapsackUtilities.h"

TEST(KnapsackUtilitiesTests, GetKnapsackItemNames_ShouldReturnItemNames)
{
	std::vector<std::shared_ptr<KnapsackItem>> items;
	items.push_back(std::make_shared<KnapsackItem>("1", 100, 3));
	items.push_back(std::make_shared<KnapsackItem>("2", 20, 2));
	items.push_back(std::make_shared<KnapsackItem>("3", 60, 4));
	items.push_back(std::make_shared<KnapsackItem>("4", 40, 1));

	auto names = KnapsackUtilities::getKnapsackItemNames(items);

	EXPECT_THAT(names, testing::WhenSorted(testing::ElementsAre("1", "2", "3", "4")));
}

TEST(KnapsackUtilitiesTests, GetKnapsackItemNames_ShouldReturnEmptyArray_IfNoItemsPassed)
{
	std::vector<std::shared_ptr<KnapsackItem>> items;

	auto names = KnapsackUtilities::getKnapsackItemNames(items);

	ASSERT_EQ(0, names.size());
}

TEST(KnapsackUtilitiesTests, GetKnapsackValue_ShouldReturnSumOfValues)
{
	std::vector<std::shared_ptr<KnapsackItem>> items;
	items.push_back(std::make_shared<KnapsackItem>("1", 100, 3));
	items.push_back(std::make_shared<KnapsackItem>("2", 20, 2));
	items.push_back(std::make_shared<KnapsackItem>("3", 60, 4));
	items.push_back(std::make_shared<KnapsackItem>("4", 40, 1));

	auto value = KnapsackUtilities::getKnapsackValue(items);

	ASSERT_EQ(220, value);
}

TEST(KnapsackUtilitiesTests, GetKnapsackValue_ShouldReturnZero_IfKnapsackIsEmpty)
{
	std::vector<std::shared_ptr<KnapsackItem>> items;

	auto value = KnapsackUtilities::getKnapsackValue(items);

	ASSERT_EQ(0, value);
}
