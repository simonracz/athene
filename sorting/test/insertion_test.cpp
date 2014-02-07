#include <gtest/gtest.h>
#include <algorithm>
#include <random>
#include <chrono>
#include <numeric>
#include <iterator>
#include "insertion_sort.hpp"

TEST(InsertionTest, predefined)
{
	std::vector<int> vec{5,1,3,4,2};
	athene::insertion_sort(vec);
	EXPECT_TRUE(std::is_sorted(vec.begin(), vec.end()));
	
	std::fill_n(vec.begin(), 5, 10);
	vec[0] = 100;
	athene::insertion_sort(vec);
	EXPECT_TRUE(std::is_sorted(vec.begin(), vec.end()));
	
	std::fill_n(vec.begin(), 5, -1);
	vec[1] = 5;
	athene::insertion_sort(vec);
	EXPECT_TRUE(std::is_sorted(vec.begin(), vec.end()));
}

TEST(InsertionTest, random)
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 m(seed);
	
	std::vector<double> vec(100);
	std::iota(vec.begin(), vec.end(), 1);
	
	std::shuffle(vec.begin(), vec.end(), m);
	athene::insertion_sort(vec);
	EXPECT_TRUE(std::is_sorted(vec.begin(), vec.end()));
	
	std::shuffle(vec.begin(), vec.end(), m);
	athene::insertion_sort(vec);
	EXPECT_TRUE(std::is_sorted(vec.begin(), vec.end()));
	
	std::shuffle(vec.begin(), vec.end(), m);
	athene::insertion_sort(vec);
	EXPECT_TRUE(std::is_sorted(vec.begin(), vec.end()));
}




