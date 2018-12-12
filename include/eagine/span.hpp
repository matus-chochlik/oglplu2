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
// has_span_size_member
//------------------------------------------------------------------------------
struct _has_span_size_member_base {
    template <typename X, typename S = decltype(std::declval<X>().size())>
    static bool_constant<std::is_integral_v<S>> _detect(X*);

    static std::false_type _detect(...);
};
//------------------------------------------------------------------------------
template <typename T>
struct has_span_size_member
  : public decltype(
      _has_span_size_member_base::_detect(static_cast<T*>(nullptr))) {};
//------------------------------------------------------------------------------
template <typename T>
constexpr bool has_span_size_member_v = has_span_size_member<T>::value;
//------------------------------------------------------------------------------
// has_span_data_member
//------------------------------------------------------------------------------
struct _has_span_data_member_base {
    template <
      typename X,
      typename P = decltype(std::declval<X>().data()),
      typename PT = typename std::pointer_traits<P>::element_type>
    static std::true_type _detect(X*);

    static std::false_type _detect(...);
};
//------------------------------------------------------------------------------
template <typename T>
struct has_span_data_member
  : public decltype(
      _has_span_data_member_base::_detect(static_cast<T*>(nullptr))) {};
//------------------------------------------------------------------------------
template <typename T>
constexpr bool has_span_data_member_v = has_span_data_member<T>::value;
//------------------------------------------------------------------------------
using memory::span;
//------------------------------------------------------------------------------
using memory::cover;
using memory::coverOne;
using memory::view;
using memory::viewOne;
//------------------------------------------------------------------------------
template <
  typename C,
  typename =
    std::enable_if_t<has_span_data_member_v<C> && has_span_size_member_v<C>>>
static constexpr inline auto view(C& container) noexcept {
    return view(container.data(), container.size());
}
//------------------------------------------------------------------------------
template <
  typename C,
  typename =
    std::enable_if_t<has_span_data_member_v<C> && has_span_size_member_v<C>>>
static constexpr inline auto cover(C& container) noexcept {
    return cover(container.data(), container.size());
}
//------------------------------------------------------------------------------
template <typename T, typename P, typename S, typename Output>
static inline Output&
list_to_stream(Output& out, memory::basic_span<T, P, S> s) {
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
