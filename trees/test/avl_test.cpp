#include <gtest/gtest.h>
#include <algorithm>
#include <numeric>
#include <random>
#include <chrono>
#include <iterator>
#include "avl_tree.hpp"

TEST(BSTreeTest, predefined1)
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

TEST(BSTreeTest, predefined2)
{
	athene::naive_bs_tree<int> bs;
	//1
	bs.insert(10);
	bs.insert(5);
	bs.insert(6);
	bs.insert(15);
	bs.insert(14);
	bs.insert(16);
	EXPECT_TRUE(bs.size() == 6);
	EXPECT_TRUE(bs.min() == 5);
	EXPECT_TRUE(bs.max() == 16);
	
	bs.erase(10);
	EXPECT_TRUE(bs.size() == 5);
	EXPECT_TRUE(bs.min() == 5);
	EXPECT_TRUE(bs.max() == 16);
}

TEST(BSTreeTest, predefined3)
{
	athene::naive_bs_tree<int> bs;
	bs.insert(11);
	bs.insert(10);
	bs.insert(5);
	bs.insert(6);
	bs.insert(15);
	bs.insert(14);
	bs.insert(16);
	EXPECT_TRUE(bs.size() == 7);
	EXPECT_TRUE(bs.min() == 5);
	EXPECT_TRUE(bs.max() == 16);
	
	bs.erase(10);
	EXPECT_TRUE(bs.size() == 6);
	EXPECT_TRUE(bs.min() == 5);
	EXPECT_TRUE(bs.max() == 16);
}

TEST(BSTreeTest, predefined4)
{
	athene::naive_bs_tree<int> bs;
	bs.insert(10);
	bs.insert(5);
	bs.insert(15);
	bs.insert(14);
	bs.insert(16);
	EXPECT_TRUE(bs.size() == 5);
	EXPECT_TRUE(bs.min() == 5);
	EXPECT_TRUE(bs.max() == 16);
	
	bs.erase(10);
	EXPECT_TRUE(bs.size() == 4);
	EXPECT_TRUE(bs.min() == 5);
	EXPECT_TRUE(bs.max() == 16);
}

TEST(BSTreeTest, predefined5)
{
	athene::naive_bs_tree<int> bs;
	bs.insert(11);
	bs.insert(10);
	bs.insert(5);
	bs.insert(15);
	bs.insert(14);
	bs.insert(16);
	EXPECT_TRUE(bs.size() == 6);
	EXPECT_TRUE(bs.min() == 5);
	EXPECT_TRUE(bs.max() == 16);
	
	bs.erase(10);
	EXPECT_TRUE(bs.size() == 5);
	EXPECT_TRUE(bs.min() == 5);
	EXPECT_TRUE(bs.max() == 16);
}

TEST(BSTreeTest, predefined6)
{
	athene::naive_bs_tree<int> bs;
	bs.insert(10);
	bs.insert(5);
	bs.insert(15);
	EXPECT_TRUE(bs.size() == 3);
	EXPECT_TRUE(bs.min() == 5);
	EXPECT_TRUE(bs.max() == 15);
	
	bs.erase(5);
	EXPECT_TRUE(bs.size() == 2);
	EXPECT_TRUE(bs.min() == 10);
	EXPECT_TRUE(bs.max() == 15);
}

TEST(BSTreeTest, predefined7)
{
	athene::naive_bs_tree<int> bs;
	bs.insert(10);
	bs.insert(5);
	bs.insert(15);
	EXPECT_TRUE(bs.size() == 3);
	EXPECT_TRUE(bs.min() == 5);
	EXPECT_TRUE(bs.max() == 15);
	
	bs.erase(15);
	EXPECT_TRUE(bs.size() == 2);
	EXPECT_TRUE(bs.min() == 5);
	EXPECT_TRUE(bs.max() == 10);
}

TEST(BSTreeTest, random10)
{
	std::vector<int> vec;
	vec.reserve(10);
	for (int i=0; i<10; ++i) {
		vec.push_back(50+i*2);
	}
	
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 m(seed);
	std::shuffle(vec.begin(), vec.end(), m);
	
	athene::naive_bs_tree<int> bs;
	
	for (auto& it : vec) {
		//std::cout << bs.print() << std::endl;
		bs.insert(it);
	}
	
	//std::cout << bs.print() << std::endl;
	
	EXPECT_TRUE(bs.size() == 10);
	
	std::shuffle(vec.begin(), vec.end(), m);
	for (int i=0; i<3; ++i) {
		EXPECT_TRUE(bs.erase(vec[i]));
		//std::cout << bs.print() << std::endl;
	}
	
	EXPECT_TRUE(bs.size() == 7);
}


TEST(BSTreeTest, random100)
{
	std::vector<int> vec;
	vec.reserve(100);
	for (int i=0; i<100; ++i) {
		vec.push_back(50+i*2);
	}
	
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 m(seed);
	std::shuffle(vec.begin(), vec.end(), m);
	
	athene::naive_bs_tree<int> bs;
	
	for (auto& it : vec) {
		bs.insert(it);
	}
	
	EXPECT_TRUE(bs.size() == 100);
	EXPECT_TRUE(bs.min() == 50);
	EXPECT_TRUE(bs.max() == 248);
	
	std::shuffle(vec.begin(), vec.end(), m);
	for (int i=0; i<50; ++i) {
		EXPECT_TRUE(bs.erase(vec[i]));
	}
	
	//std::cout << bs.print();
	EXPECT_TRUE(bs.size() == 50);
}
