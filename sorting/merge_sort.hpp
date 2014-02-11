#ifndef merge_sort_hpp
#define merge_sort_hpp

#include <vector>
#include <algorithm>

namespace athene {

template <typename T>
std::vector<T> merge_sort_impl(std::vector<T>& vec, size_t lower, size_t upper)
{
	if (lower>=upper) {
		return std::vector<T>(1,vec[lower]);
	}
	
	size_t split = (upper - lower) / 2;
	
	auto vLeft = merge_sort_impl(vec, lower, lower + split);
	auto vRight = merge_sort_impl(vec, lower + split + 1, upper);
	
	std::vector<T> ret;
	ret.reserve(upper - lower + 1);
	
	std::merge(vLeft.begin(), vLeft.end(), vRight.begin(), vRight.end(), back_inserter(ret));
	
	return ret;
}

template <typename T>
void merge_sort(std::vector<T>& vec)
{
	vec = merge_sort_impl(vec, 0, vec.size() - 1);
}
	
/*
template <typename T>
std::vector<T> my_merge(std::vector<T>& vLeft, std::vector<T>& vRight)
{
	std::vector<T> m;
	m.reserve(vLeft.size() + vRight.size());
	
	int i=0, j=0;
	
	while ((i<vLeft.size()) && (j<vRight.size())) {
		if (vLeft[i] < vRight[j]) {
			m.push_back(vLeft[i++]);
		} else {
			m.push_back(vRight[j++]);
		}
	}
	
	if (i<vLeft.size()) {
		std::copy_n(vLeft.begin() + i, vLeft.size() - i, back_inserter(m));
	} else {
		std::copy_n(vRight.begin() + j, vRight.size() - j, back_inserter(m));
	}
	
	return m;
}

template <typename T>
void merge_sort2(std::vector<T>& vec)
{
	if (vec.size() == 1) {
		return;
	}
	
	size_t split = vec.size() / 2;
	
	std::vector<T> vLeft;
	vLeft.reserve(split);
	
	std::vector<T> vRight;
	vRight.reserve(split + (vec.size() % 2));
	
	std::copy_n(vec.begin(), split, back_inserter(vLeft));
	std::copy_n(vec.begin() + split, split + (vec.size() % 2), back_inserter(vRight));
	
	merge_sort2(vLeft);
	merge_sort2(vRight);
	
	vec = my_merge(vLeft, vRight);
}
*/
	
} //namespace

#endif
