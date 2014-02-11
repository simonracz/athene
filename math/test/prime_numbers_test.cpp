#include <gtest/gtest.h>
#include <prime_numbers.hpp>

using namespace athene;

TEST(PrimeNumbers, isPrime1)
{
	EXPECT_TRUE(is_prime(2));
	EXPECT_TRUE(is_prime(3));
	EXPECT_TRUE(is_prime(4967));
	EXPECT_TRUE(is_prime(7919));
	
	EXPECT_FALSE(is_prime(4));
	EXPECT_FALSE(is_prime(3465));	
}

TEST(PrimeNumbers, isPrime2)
{
	EXPECT_TRUE(is_prime2(2));
	EXPECT_TRUE(is_prime2(3));
	EXPECT_TRUE(is_prime2(4967));
	EXPECT_TRUE(is_prime2(7919));
	
	EXPECT_FALSE(is_prime2(4));
	EXPECT_FALSE(is_prime2(3465));
}

TEST(PrimeNumbers, gcd)
{
	EXPECT_EQ(1,  gcd(3691, 2069));
	EXPECT_EQ(2069,  gcd(4138, 2069));
	EXPECT_EQ(12, gcd(240, 84));
}