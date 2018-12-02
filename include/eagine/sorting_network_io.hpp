/**
 *  @file eagine/sorting_network_io.hpp
 */

#ifndef EAGINE_SORTING_NETWORK_IO_1512222148_HPP
#define EAGINE_SORTING_NETWORK_IO_1512222148_HPP

#include "sorting_network.hpp"
#include <iostream>

namespace eagine {

template <typename SortingNetwork>
static inline std::ostream&
print_sorting_network(std::ostream& out, const SortingNetwork& sn) {
    for(span_size_t r = 0; r < sn.rounds(); ++r) {
        for(span_size_t i = 0; i < sn.size(); ++i) {
            span_size_t j = sn.index(r, i);

            if(i < j) {
                for(span_size_t m = 0; m < sn.size(); ++m) {
                    span_size_t k = sn.size() - m - 1;
                    if(i == k) {
                        if(sn.min(r, i, j)) {
                            out << 'o';
                        } else {
                            out << '>';
                        }
                    } else if(j == k) {
                        if(sn.max(r, i, j)) {
                            out << 'o';
                        } else {
                            out << '<';
                        }
                    } else {
                        if((i < k) && (k <= j)) {
                            out << '+';
                        } else {
                            out << '|';
                        }
                    }

                    if((i < k) && (k <= j)) {
                        out << '-';
                    } else {
                        out << ' ';
                    }
                }
                out << std::endl;
            }
        }
        out << "=";
        for(span_size_t k = 1; k < sn.size(); ++k) {
            out << "==";
        }
        out << std::endl;
    }
    return out;
}

} // namespace eagine

#endif // include guard
