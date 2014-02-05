#include <gtest/gtest.h>
#include <algorithm>
#include "bubble_sort.hpp"

TEST(BubbleTest, PredefinedRandom) 
{
	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(2);

	athene::bubble_sort(vec);
	ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
}


