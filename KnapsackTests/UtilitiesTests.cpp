#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../Knapsack/Utilities.h"

TEST(UtilitiesTests, SplitLine_ShouldSplitStringBasedOnCommaDelim)
{
	auto input = "a,b,c,d,e";
	auto delim = ',';

	auto result = Utilities::SplitLine(input, delim);

	EXPECT_THAT(result, testing::WhenSorted(testing::ElementsAre("a", "b", "c", "d", "e")));
}

TEST(UtilitiesTests, SplitLine_ShouldSplitStringBasedOnSpaceDelim)
{
	auto input = "foo bar foobar";
	auto delim = ' ';

	auto result = Utilities::SplitLine(input, delim);

	EXPECT_THAT(result, testing::WhenSorted(testing::ElementsAre("bar", "foo", "foobar")));
}
