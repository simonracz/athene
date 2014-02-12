#include <gtest/gtest.h>
#include <algorithm>
#include <numeric>
#include <random>
#include <chrono>
#include <iterator>
#include "heap_sort.hpp"

TEST(HeapSortTest, random100)
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 m(seed);
	std::uniform_real_distribution<double> dist(0.0,1.0);
	auto dice = std::bind(dist, m);
	
	std::vector<double> vec;
	vec.reserve(100);
	std::generate_n(back_inserter(vec), 100, [&dice] {return dice();});
	
	athene::bin_heapsort(vec);
	EXPECT_TRUE(std::is_sorted(vec.begin(), vec.end()));
	ASSERT_TRUE(vec.size() == 100);
	
	std::shuffle(vec.begin(), vec.end(), m);
	athene::bin_heapsort(vec);
	EXPECT_TRUE(std::is_sorted(vec.begin(), vec.end()));
	
	std::shuffle(vec.begin(), vec.end(), m);
	athene::bin_heapsort(vec);
	EXPECT_TRUE(std::is_sorted(vec.begin(), vec.end()));
}
