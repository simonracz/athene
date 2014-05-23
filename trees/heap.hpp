#ifndef heaps_hpp
#define heaps_hpp

#include <algorithm>
#include <vector>

namespace athene {

template<typename T>
void max_heapify(std::vector<T>&,int, int);
	
template<typename T>
void make_bin_heap(std::vector<T>& vec)
{
	for (int i = (vec.size()/2 - 1) ; i>=0; --i) {
		max_heapify(vec, i, vec.size());
	}
}

template<typename T>
void max_heapify(std::vector<T>& vec, int index, int heapSize)
{
	if ((2*index + 1) > (heapSize - 1)) {
		return;
	}
		
	if ((2*index + 2) > (heapSize - 1)) {
		if (vec[2*index + 1] > vec[index]) {
			std::swap(vec[2*index + 1], vec[index]);
		}
		return;
	}
	
	int largest = index;
	
	if (vec[2*index + 1] > vec[largest]) largest = 2*index + 1;
	if (vec[2*index + 2] > vec[largest]) largest = 2*index + 2;

	if (largest!=index) {
		std::swap(vec[index], vec[largest]);
		max_heapify(vec, largest, heapSize);
	}
	
	return;
}

}

#endif