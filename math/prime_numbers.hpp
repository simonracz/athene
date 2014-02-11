#ifndef prime_numbers_hpp
#define prime_numbers_hpp

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstdlib>

namespace athene {

bool is_prime(long num)
{
	num = std::abs(num);
	
	if ((num == 2) || (num == 3)) return true;
	if ((num == 0) || (num == 1)) return false;
	
	for (int i=2; i*i<=num; ++i) {
		if ((num % i) == 0) {
			return false;
		}	
	}
	
	return true;	
}

struct PrimeDatabase {
	long max_num{5};
	std::vector<bool> sieve{false, false, true, true, false, true};
	void calcPrimesUpTo(long num);
};

bool is_prime2(long num)
{
	num = std::abs(num);
	
	static PrimeDatabase pdb;
	
	if (pdb.max_num < num) pdb.calcPrimesUpTo(num);

	return pdb.sieve[num];
}

void PrimeDatabase::calcPrimesUpTo(long num) 
{
	sieve.resize(num+1, true);

	for (int i=2; i*i <= num; ++i) {
		for (int j=2; j*i<=num; ++j) {
			sieve[j*i]=false;
		}
	}
}

long gcd(long a, long b)
{
	long temp = 0;
	while (b!=0) {
		temp = b;
		b = a % b;
		a = temp;
	}

	return a;
}

} //namespace

#endif
