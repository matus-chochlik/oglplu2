/**
 *  @file eagine/span.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SPAN_1509260923_HPP
#define EAGINE_SPAN_1509260923_HPP

#include "memory/span.hpp"
#include <iosfwd>

namespace eagine {
//------------------------------------------------------------------------------
using memory::span;
//------------------------------------------------------------------------------
using memory::cover;
using memory::coverOne;
using memory::view;
using memory::viewOne;
//------------------------------------------------------------------------------
template <typename T, typename P, typename S, typename Output>
static inline Output& list_to_stream(
  Output& out, memory::basic_span<T, P, S> s) {
    out << '[';
    bool first = true;
    for(const auto& e : s) {
        if(first) {
            first = false;
        } else {
            out << ',';
        }
        out << e;
    }
    return out << ']';
}
//------------------------------------------------------------------------------
template <typename T, typename Output>
static inline Output& write_to_stream(Output& out, span<T> s) {
    return out.write(s.data(), s.size());
}
//------------------------------------------------------------------------------
template <typename T, typename P, typename S>
static inline std::
  enable_if_t<!std::is_same_v<std::remove_const_t<T>, char>, std::ostream&>
  operator<<(std::ostream& out, memory::basic_span<T, P, S> s) {
    return list_to_stream(out, s);
}
//------------------------------------------------------------------------------
template <typename T, typename P, typename S>
static inline std::
  enable_if_t<std::is_same_v<std::remove_const_t<T>, char>, std::ostream&>
  operator<<(std::ostream& out, memory::basic_span<T, P, S> s) {
    return write_to_stream(out, absolute(s));
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // include guard
