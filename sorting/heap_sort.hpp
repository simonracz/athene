#ifndef heap_sort_hpp
#define heap_sort_hpp

#include <vector>
#include <algorithm>
#include <heaps.hpp>

namespace athene {

template<typename T>
void bin_heapsort(std::vector<T>& vec)
{
	if (!std::is_heap(vec.begin(), vec.end())) make_bin_heap(vec);
	
	for (int i=(vec.size()-1); i>0; --i) {
		std::swap(vec[0], vec[i]);
		max_heapify(vec, 0, i);
	}
}

}

#endif