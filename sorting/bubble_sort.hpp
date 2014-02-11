#ifndef bubble_sort_hpp
#define bubble_sort_hpp

#include <vector>
#include <algorithm>

namespace athene {

template <typename T>
void bubble_sort(std::vector<T>& vec)
{
	for (int j=vec.size()-1; j>0; --j) {
		for (int i=0; i<j; ++i) {
			if (vec[i]>vec[i+1]) {
				std::swap(vec[i], vec[i+1]);
			}			
		}
	}	
}

} //namespace

#endif
