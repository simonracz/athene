#ifndef quick_sort_hpp
#define quick_sort_hpp

#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

namespace athene {

template<typename T>
void quick_sort_impl(std::vector<T>&, int, int);
	
template<typename T>
void quick_sort(std::vector<T>& vec)
{
	quick_sort_impl(vec, 0, vec.size());
}

//this is not stable
//TODO : implement own partition method
template<typename T>
void quick_sort_impl(std::vector<T>& vec, int low, int high)
{
	if (low >= high -1) return;
	
	int pivot = (high + low)/2;

	T temp = vec[pivot];
//	auto it = std::stable_partition(vec.begin()+low, vec.begin()+high, std::bind(std::less_equal<T>(), std::placeholders::_1 , temp));
//	it = std::stable_partition(vec.begin()+low, it, std::bind(std::less<T>(), std::placeholders::_1 , temp));
	
	auto it = std::partition(vec.begin()+low, vec.begin()+high, std::bind(std::less_equal<T>(), std::placeholders::_1 , temp));
	it = std::partition(vec.begin()+low, it, std::bind(std::less<T>(), std::placeholders::_1 , temp));

	
	pivot = std::distance(vec.begin(), it);

	quick_sort_impl(vec, low, pivot);
	quick_sort_impl(vec, pivot+1, high);
}

}

#endif