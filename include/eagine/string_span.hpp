/// @file eagine/string_span.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

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
      : base(addr, length) {}

    template <
      typename R,
      typename = std::enable_if_t<
        !std::is_array_v<R> && std::is_convertible_v<R, P> &&
        std::is_same_v<std::remove_const_t<std::remove_pointer_t<R>>, char>>>
    constexpr explicit basic_string_span(R addr) noexcept
      : base(addr, -limit_cast<S>(std::strlen(addr))) {}

    template <std::size_t N>
    constexpr basic_string_span(C (&array)[N]) noexcept
      : base(
          static_cast<P>(array),
          array[N - 1] == C(0) ? 1 - limit_cast<S>(N) : limit_cast<S>(N)) {}

    template <std::size_t N>
    constexpr basic_string_span(C (&array)[N], span_size_t n) noexcept
      : base(static_cast<P>(array), limit_cast<S>(n)) {}

    constexpr basic_string_span(const string_type& str) noexcept
      : base(static_cast<P>(str.c_str()), -limit_cast<S>(str.size())) {}

    template <
      typename Str,
      typename = std::enable_if_t<
        memory::has_span_data_member_v<Str> &&
        memory::has_span_size_member_v<Str>>>
    constexpr basic_string_span(Str& str) noexcept
      : base(static_cast<P>(str.data()), limit_cast<S>(str.size())) {}

    template <
      typename Str,
      typename = std::enable_if_t<
        memory::has_span_data_member_v<Str> &&
        memory::has_span_size_member_v<Str>>>
    constexpr basic_string_span(const Str& str) noexcept
      : base(static_cast<P>(str.data()), limit_cast<S>(str.size())) {}

    using base::data;
    using base::empty;
    using base::size;

    constexpr auto std_view() const noexcept -> std_view_type {
        return {data(), std_size_t(size())};
    }

    constexpr operator std_view_type() const noexcept {
        return std_view();
    }

    constexpr auto to_string() const -> string_type {
        return {data(), std_size_t(size())};
    }
};
//------------------------------------------------------------------------------
using string_span = basic_string_span<char>;
using string_view = basic_string_span<const char>;
//------------------------------------------------------------------------------
template <typename C, typename P, typename S>
static constexpr auto std_view(memory::basic_span<C, P, S> spn) noexcept
  -> std::basic_string_view<std::remove_const_t<C>> {
    return {spn.data(), std_size_t(spn.size())};
}
//------------------------------------------------------------------------------
template <typename C, typename P, typename S>
static constexpr auto to_string(memory::basic_span<C, P, S> spn)
  -> std::basic_string<std::remove_const_t<C>> {
    return {spn.data(), std_size_t(spn.size())};
}
//------------------------------------------------------------------------------
template <typename C, typename T, typename A, typename P, typename S>
static constexpr auto assign_to(
  std::basic_string<C, T, A>& str,
  memory::basic_span<const C, P, S> spn) -> auto& {
    str.assign(spn.data(), std_size(spn.size()));
    return str;
}
//------------------------------------------------------------------------------
template <typename C, typename T, typename A, typename P, typename S>
static constexpr auto append_to(
  std::basic_string<C, T, A>& str,
  memory::basic_span<const C, P, S> spn) -> auto& {
    str.append(spn.data(), std_size(spn.size()));
    return str;
}
//------------------------------------------------------------------------------
// are_equal helper
//------------------------------------------------------------------------------
template <typename T, typename P, typename S>
struct cmp_decay_to<basic_string_span<T, P, S>>
  : type_identity<memory::basic_span<T, P, S>> {};
//------------------------------------------------------------------------------
// less
//------------------------------------------------------------------------------
template <typename Str, typename Spn>
struct basic_str_view_less {
    using is_transparent = std::true_type;

    constexpr auto operator()(const Str& l, const Str& r) const noexcept
      -> bool {
        return l < r;
    }

    constexpr auto operator()(const Str& l, Spn r) const noexcept -> bool {
        return std::strncmp(l.data(), r.data(), std_size(r.size())) < 0;
    }

    constexpr auto operator()(Spn l, const Str& r) const noexcept -> bool {
        return std::strncmp(l.data(), r.data(), std_size(l.size())) < 0;
    }
};
//------------------------------------------------------------------------------
using str_view_less = basic_str_view_less<std::string, string_view>;
//------------------------------------------------------------------------------
// c_str
//------------------------------------------------------------------------------
template <typename C, typename P, typename S>
class basic_c_str {
public:
    using string_type = std::basic_string<std::remove_const_t<C>>;

    constexpr basic_c_str(basic_string_span<C, P, S> s)
      : _span{s.is_zero_terminated() ? s : basic_string_span<C, P, S>{}}
      , _str{s.is_zero_terminated() ? string_type{} : s.to_string()} {}

    constexpr auto c_str() const noexcept -> P {
        return _span.empty() ? _str.c_str() : _span.data();
    }

    constexpr operator P() const noexcept {
        return c_str();
    }

private:
    basic_string_span<C, P, S> _span{};
    string_type _str{};
};
//------------------------------------------------------------------------------
template <typename C, typename P, typename S>
static constexpr auto c_str(memory::basic_span<C, P, S> s) -> std::enable_if_t<
  std::is_convertible_v<memory::basic_span<C, P, S>, basic_string_span<C, P, S>>,
  basic_c_str<C, P, S>> {
    return {s};
}
//------------------------------------------------------------------------------
template <typename C, typename T, typename A, typename Transform>
static inline auto make_span_putter(
  span_size_t& i,
  std::basic_string<C, T, A>& str,
  Transform transform) {
    return [&i, &str, transform](auto value) mutable -> bool {
        if(i < span_size_t(str.size())) {
            if(auto transformed = transform(value)) {
                str[i++] = std::move(extract(transformed));
                return true;
            }
        }
        return false;
    };
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_STRING_SPAN_HPP
