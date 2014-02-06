#ifndef bubble_sort_hpp
#define bubble_sort_hpp

#include <vector>
#include <algorithm>

template <typename T>
void bubble_sort(std::vector<T>& vec)
{
	std::sort(vec.begin(), vec.end());
}

#endif