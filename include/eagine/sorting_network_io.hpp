/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_SORTING_NETWORK_IO_HPP
#define EAGINE_SORTING_NETWORK_IO_HPP

#include "integer_range.hpp"
#include "sorting_network.hpp"
#include <iostream>

namespace eagine {

template <typename SortingNetwork>
static inline std::ostream&
print_sorting_network(std::ostream& out, const SortingNetwork& sn) {
    for(const auto r : integer_range(sn.rounds())) {
        for(const auto i : integer_range(sn.size())) {
            span_size_t j = sn.index(r, i);

            if(i < j) {
                for(const auto m : integer_range(sn.size())) {
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
        for(const auto k : integer_range(1, sn.size())) {
            out << "==";
        }
        out << std::endl;
    }
    return out;
}

} // namespace eagine

#endif // EAGINE_SORTING_NETWORK_IO_HPP
