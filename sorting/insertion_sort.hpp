//
//  insertion_sort.hpp
//  ATHENE
//
//  Created by Simon Racz on 08/02/14.
//
//

#ifndef insertion_sort_hpp
#define insertion_sort_hpp

#include <vector>
#include <algorithm>

namespace athene {
	
template <typename T>
void insertion_sort(std::vector<T>& vec)
{
	for (int i=1; i<vec.size(); ++i) {
		//T key = vec[i];
		//auto up = std::upper_bound(vec.begin(), vec.begin()+i, key);
		//std::rotate(up, vec.begin()+i, vec.begin()+i+1);
		
		std::rotate(std::upper_bound(vec.begin(), vec.begin()+i, vec[i]), vec.begin()+i, vec.begin()+i+1);
	}
}
	
} //namespace

#endif
