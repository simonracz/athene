#include <gtest/gtest.h>
#include <algorithm>
#include <random>
#include <chrono>
#include <numeric>
#include <iterator>
#include "basic_math.hpp"

using namespace athene;

TEST(BasicMathTest, factorial)
{
	long long ret = factorial(1);
	EXPECT_TRUE(ret == 1);

	ret = factorial(2);
	EXPECT_TRUE(ret == 2);

	ret = factorial(7);
	EXPECT_TRUE(ret == 5040);

	ret = factorial(11);
	EXPECT_TRUE(ret == 39916800L);
	
	ret = factorial(8);
	EXPECT_TRUE(ret == 40320);

	ret = factorial(9);
	EXPECT_TRUE(ret == 362880L);


	ret = factorial(10);
	EXPECT_TRUE(ret == 3628800L);
}

TEST(BasicMathTest, fibonacci1)
{
	long long ret = fibonacci(0);
	EXPECT_TRUE(ret == 0);

	ret = fibonacci(1);
	EXPECT_TRUE(ret == 1);

	ret = fibonacci(5);
	EXPECT_TRUE(ret == 5);

	ret = fibonacci(18);
	EXPECT_TRUE(ret == 2584);
	
	ret = fibonacci(12);
	EXPECT_TRUE(ret == 144);

	ret = fibonacci(19);
	EXPECT_TRUE(ret == 4181);

	ret = fibonacci(20);
	EXPECT_TRUE(ret == 6765);
}

TEST(BasicMathTest, fibonacci2)
{
	long long ret = fibonacci2(0);
	EXPECT_EQ(0, ret);

	ret = fibonacci2(1);
	EXPECT_EQ(1, ret);

	ret = fibonacci2(5);
	EXPECT_EQ(5, ret);

	ret = fibonacci2(19);
	EXPECT_EQ(4181, ret);
	
	ret = fibonacci2(12);
	EXPECT_EQ(144, ret);

	ret = fibonacci2(18);
	EXPECT_EQ(2584, ret);

	ret = fibonacci2(20);
	EXPECT_EQ(6765, ret);
}


TEST(BasicMathTest, fibonacci3)
{
	long long ret = fibonacci3(0);
	EXPECT_TRUE(ret == 0);

	ret = fibonacci3(1);
	EXPECT_TRUE(ret == 1);

	ret = fibonacci3(19);
	EXPECT_TRUE(ret == 4181);
	
	ret = fibonacci3(5);
	EXPECT_TRUE(ret == 5);

	ret = fibonacci3(12);
	EXPECT_TRUE(ret == 144);

	ret = fibonacci3(18);
	EXPECT_TRUE(ret == 2584);

	ret = fibonacci3(20);
	EXPECT_TRUE(ret == 6765);
}



