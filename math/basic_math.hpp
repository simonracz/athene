#ifndef basic_math_sort_hpp
#define basic_math_sort_hpp

#include <vector>
#include <algorithm>
#include <unordered_map>

namespace athene {

long long factorial(int n)
{
	static int lookup[] = {1, 2, 6, 24, 120, 720, 5040, 40320};
	
	if (n<=0) return 0;
	if (n<9) return lookup[n-1];

	return static_cast<long long>(n)*factorial(n-1);	
}

long long fibonacci(int n)
{
	static int lookup[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233};

	if (n<0) return 0;
	if (n<14) return lookup[n];

	return fibonacci(n-2) + fibonacci(n-1);
}

long long fibonacci2(int n)
{
	static std::unordered_map<int, long long> lookup = {{0,0}, {1,1}, {2,1}, {3,2}, {4,3}};

	if (n<0) return 0;
	if (lookup.count(n) == 1) return lookup[n];
	
	long long ret = fibonacci2(n-2) + fibonacci2(n-1);
	lookup[n] = ret;
	return ret;
}

long long fibonacci3(int n)
{
	
	if (n<=0) return 0;

	long long r1 = 0;
	long long r2 = 1;

	long long temp = 0;
	for (int i = 1; i<n; ++i) {
		temp = r1 + r2;
		r1 = r2;
		r2 = temp;
	}

	return r2;
}

} //namespace

#endif
