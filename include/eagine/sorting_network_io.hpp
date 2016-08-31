/**
 *  @file eagine/sorting_network_io.hpp
 */

#ifndef EAGINE_SORTING_NETWORK_IO_1512222148_HPP
#define EAGINE_SORTING_NETWORK_IO_1512222148_HPP

#include "sorting_network.hpp"
#include <iostream>

namespace eagine {

template <typename SortingNetwork>
static inline
void print_sorting_network(const SortingNetwork& sn)
{
	for(std::size_t r=0; r<sn.rounds(); ++r)
	{
		for(std::size_t i=0; i<sn.size(); ++i)
		{
			std::size_t j = sn.index(r, i);

			if(i < j)
			{
				for(std::size_t m=0; m<sn.size(); ++m)
				{
					std::size_t k=sn.size()-m-1;
					if(i == k) {
						if(sn.min(r, i, j)) {
							std::cout << 'o';
						} else {
							std::cout << '>';
						}
					} else if(j == k) {
						if(sn.max(r, i, j)) {
							std::cout << 'o';
						} else {
							std::cout << '<';
						}
					} else {
						if((i <  k) && (k <= j)) {
							std::cout << '+';
						} else {
							std::cout << '|';
						}
					}

					if((i <  k) && (k <= j)) {
						std::cout << '-';
					} else {
						std::cout << ' ';
					}
				}
				std::cout << std::endl;
			}
		}
		std::cout << "=";
		for(std::size_t k=1; k<sn.size(); ++k)
		{
			std::cout << "==";
		}
		std::cout << std::endl;
	}
}

} // namespace eagine

#endif //include guard

