#include <gtest/gtest.h>
#include <algorithm>
#include <random>
#include <chrono>
#include <numeric>
#include <iterator>
#include "bubble_sort.hpp"

TEST(BubbleTest, predefined)
{
	std::vector<int> vec{5,1,3,4,2};
	athene::bubble_sort(vec);
	EXPECT_TRUE(std::is_sorted(vec.begin(), vec.end()));
	ASSERT_TRUE(vec.size() == 5);
	
	std::fill_n(vec.begin(), 5, 10);
	vec[0] = 100;
	athene::bubble_sort(vec);
	EXPECT_TRUE(std::is_sorted(vec.begin(), vec.end()));
	
	std::fill_n(vec.begin(), 5, -1);
	vec[1] = 5;
	athene::bubble_sort(vec);
	EXPECT_TRUE(std::is_sorted(vec.begin(), vec.end()));
}

TEST(BubbleTest, random)
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 m(seed);
	std::uniform_real_distribution<double> dist(0.0,1.0);
	auto dice = std::bind(dist, m);
	
	std::vector<double> vec;
	vec.reserve(100);
	std::generate_n(back_inserter(vec), 100, [&dice] {return dice();});
	
	std::shuffle(vec.begin(), vec.end(), m);
	athene::bubble_sort(vec);
	EXPECT_TRUE(std::is_sorted(vec.begin(), vec.end()));
	ASSERT_TRUE(vec.size() == 100);
	
	std::shuffle(vec.begin(), vec.end(), m);
	athene::bubble_sort(vec);
	EXPECT_TRUE(std::is_sorted(vec.begin(), vec.end()));
	
	std::shuffle(vec.begin(), vec.end(), m);
	athene::bubble_sort(vec);
	EXPECT_TRUE(std::is_sorted(vec.begin(), vec.end()));
}




