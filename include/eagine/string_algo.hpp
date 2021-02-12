/// @file eagine/string_algo.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_STRING_ALGO_HPP
#define EAGINE_STRING_ALGO_HPP

#include "string_span.hpp"

namespace eagine {
//------------------------------------------------------------------------------
template <
  typename C,
  typename T,
  typename A,
  typename P1,
  typename P2,
  typename S1,
  typename S2>
auto string_replace(
  std::basic_string<C, T, A>& str,
  memory::basic_span<const C, P1, S1> from,
  memory::basic_span<const C, P2, S2> to) -> std::basic_string<C, T, A>& {
    std::string::size_type index = 0;
    while(true) {
        index = str.find(from.data(), index, from.size());
        if(index == std::string::npos) {
            break;
        }
        str.replace(index, from.size(), to.data(), to.size());
        index += to.size();
    }
    return str;
}
//------------------------------------------------------------------------------
template <
  typename C,
  typename T,
  typename A,
  typename P1,
  typename P2,
  typename S1,
  typename S2>
auto string_replace(
  std::basic_string<C, T, A>& str,
  span<const std::tuple<
    basic_string_span<const C, P1, S1>,
    basic_string_span<const C, P2, S2>>> dict) -> std::basic_string<C, T, A>& {
    for(auto& [from, to] : dict) {
        string_replace(str, from, to);
    }
    return str;
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_STRING_ALGO_HPP
