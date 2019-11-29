/**
 *  @file eagine/span.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SPAN_HPP
#define EAGINE_SPAN_HPP

#include "memory/span.hpp"
#include "valid_if/decl.hpp"
#include <iosfwd>

namespace eagine {
//------------------------------------------------------------------------------
using memory::span;
//------------------------------------------------------------------------------
using memory::cover;
using memory::cover_one;
using memory::view;
using memory::view_one;
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
    return out.write(
      reinterpret_cast<const char*>(s.data()),
      limit_cast<std::streamsize>(s.size()));
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
template <typename T, typename P, typename S>
static inline auto make_span_getter(
  span_size_t& i, memory::basic_span<T, P, S> spn) {
    return [&i, spn]() -> optionally_valid<std::remove_const_t<T>> {
        if(i < spn.size()) {
            return {spn[i++], true};
        }
        return {};
    };
}
//------------------------------------------------------------------------------
template <typename T, typename P, typename S, typename Transform>
static inline auto make_span_getter(
  span_size_t& i, memory::basic_span<T, P, S> spn, Transform transform) {
    return [&i, spn, transform]() -> optionally_valid<std::remove_const_t<T>> {
        if(i < spn.size()) {
            return transform(spn[i++]);
        }
        return {};
    };
}
//------------------------------------------------------------------------------
template <typename T, typename P, typename S>
static inline auto make_span_putter(
  span_size_t& i, memory::basic_span<T, P, S> spn) {
    return [&i, spn](auto value) mutable -> bool {
        if(i < spn.size()) {
            spn[i++] = std::move(value);
            return true;
        }
        return false;
    };
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SPAN_HPP
