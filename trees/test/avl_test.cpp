#include <gtest/gtest.h>
#include <algorithm>
#include <numeric>
#include <random>
#include <chrono>
#include <iterator>
#include "avl_tree.hpp"

TEST(BSTreeTest, predefined)
{
	athene::naive_bs_tree<int> bs;
	ASSERT_TRUE(bs.size()==0);
	bs.insert(50);
	ASSERT_TRUE(bs.size()==1);
	
	bs.insert(17);
	bs.insert(74);
	bs.insert(7);
	bs.insert(68);
	bs.insert(44);
	bs.insert(28);
	bs.insert(89);
	bs.insert(49);
	
	EXPECT_TRUE(bs.size() == 9);
	EXPECT_TRUE(bs.min() == 7);
	EXPECT_TRUE(bs.max() == 89);
		
	bs.erase(44);
	EXPECT_TRUE(bs.size() == 8);
	EXPECT_TRUE(bs.min() == 7);
	EXPECT_TRUE(bs.max() == 89);
	
	//std::cout << bs.print();
	
	bs.read("{8,7,17,28,49,50,68,74,89}");
	EXPECT_TRUE(bs.size() == 8);
	EXPECT_TRUE(bs.min() == 7);
	EXPECT_TRUE(bs.max() == 89);
	
	EXPECT_TRUE(bs.find(50));
	EXPECT_FALSE(bs.find(51));
}
