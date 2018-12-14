/**
 *  @file eagine/string_span.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_STRING_SPAN_HPP
#define EAGINE_STRING_SPAN_HPP

#include "span.hpp"
#include "types.hpp"
#include <cstring>
#include <string>
#include <string_view>

namespace eagine {
//------------------------------------------------------------------------------
// basic_string_span
//------------------------------------------------------------------------------
template <typename C, typename P = C*, typename S = span_size_t>
class basic_string_span : public memory::basic_span<C, P, S> {
    using base = memory::basic_span<C, P, S>;

public:
    using string_type = std::basic_string<std::remove_const_t<C>>;
    using std_view_type = std::basic_string_view<std::remove_const_t<C>>;

    constexpr basic_string_span() noexcept = default;

    constexpr basic_string_span(P addr, S length) noexcept
      : base(addr, length) {
    }

    template <
      typename R,
      typename = std::enable_if_t<
        !std::is_array_v<R> && std::is_convertible_v<R, P> &&
        std::is_same_v<std::remove_const_t<std::remove_pointer_t<R>>, char>>>
    constexpr explicit basic_string_span(R addr) noexcept
      : base(addr, span_size(std::strlen(addr))) {
    }

    template <std::size_t N>
    constexpr basic_string_span(C (&array)[N]) noexcept
      : base(
          static_cast<P>(array),
          limit_cast<S>(array[N - 1] == C(0) ? N - 1 : N)) {
    }

    template <
      typename Str,
      typename = std::enable_if_t<
        memory::has_span_data_member_v<Str> &&
        memory::has_span_size_member_v<Str>>>
    constexpr basic_string_span(Str& str) noexcept
      : base(static_cast<P>(str.data()), limit_cast<S>(str.size())) {
    }

    template <
      typename Str,
      typename = std::enable_if_t<
        memory::has_span_data_member_v<Str> &&
        memory::has_span_size_member_v<Str>>>
    constexpr basic_string_span(const Str& str) noexcept
      : base(static_cast<P>(str.data()), limit_cast<S>(str.size())) {
    }

    using base::data;
    using base::empty;
    using base::size;

    constexpr bool is_zero_terminated() const noexcept {
        if(empty()) {
            return false;
        }
        return data()[size()] == C(0);
    }

    constexpr std_view_type std_view() const {
        return {data(), std_size_t(size())};
    }

    constexpr operator std_view_type() const {
        return std_view();
    }

    constexpr string_type to_string() const {
        return {data(), std_size_t(size())};
    }
};
//------------------------------------------------------------------------------
template <typename T, typename P, typename S>
struct cmp_decay_to<basic_string_span<T, P, S>>
  : identity<memory::basic_span<T, P, S>> {};
//------------------------------------------------------------------------------
using string_span = basic_string_span<char>;
using string_view = basic_string_span<const char>;
//------------------------------------------------------------------------------
template <typename C, typename P, typename S>
class basic_c_str {
public:
    using string_type = std::basic_string<std::remove_const_t<C>>;

    constexpr basic_c_str(basic_string_span<C, P, S> s)
      : _span{s}
      , _str{s.is_zero_terminated() ? string_type{} : s.to_string()} {
    }

    constexpr P c_str() const noexcept {
        return _span.empty() ? _str.c_str() : _span.data();
    }

    constexpr operator P() const noexcept {
        return c_str();
    }

private:
    basic_string_span<C, P, S> _span = {};
    string_type _str = {};
};
//------------------------------------------------------------------------------
template <typename C, typename P, typename S>
static constexpr inline std::enable_if_t<
  std::
    is_convertible_v<memory::basic_span<C, P, S>, basic_string_span<C, P, S>>,
  basic_c_str<C, P, S>>
c_str(memory::basic_span<C, P, S> s) {
    return {s};
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_STRING_SPAN_HPP
