/// @file
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
/// @brief Specialization of memory::basic_span for character string containers.
/// @ingroup string_utils
template <typename C, typename P = C*, typename S = span_size_t>
class basic_string_span : public memory::basic_span<C, P, S> {
    using base = memory::basic_span<C, P, S>;

public:
    /// @brief Related standard string type.
    using string_type = std::basic_string<std::remove_const_t<C>>;

    /// @brief Related standard string view type.
    using std_view_type = std::basic_string_view<std::remove_const_t<C>>;

    /// @brief Default constructor.
    /// @post empty
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

    /// @brief Construction from C string literal
    template <std::size_t N>
    constexpr basic_string_span(C (&array)[N]) noexcept
      : base(
          static_cast<P>(array),
          array[N - 1] == C(0) ? 1 - limit_cast<S>(N) : limit_cast<S>(N)) {}

    /// @brief Construction from C-array and explicit length value.
    template <std::size_t N>
    constexpr basic_string_span(C (&array)[N], span_size_t n) noexcept
      : base(static_cast<P>(array), limit_cast<S>(n)) {}

    /// @brief Construction from related standard string type.
    constexpr basic_string_span(const string_type& str) noexcept
      : base(static_cast<P>(str.c_str()), -limit_cast<S>(str.size())) {}

    /// @brief Construction from compatible container reference.
    ///
    /// The container passed as argument should have @c data and @c size
    /// member functions with the same semantics as std::string does.
    template <
      typename Str,
      typename = std::enable_if_t<
        memory::has_span_data_member_v<Str, C> &&
        memory::has_span_size_member_v<Str>>>
    constexpr basic_string_span(Str& str) noexcept
      : base(static_cast<P>(str.data()), limit_cast<S>(str.size())) {}

    /// @brief Construction from compatible container const reference.
    ///
    /// The container passed as argument should have @c data and @c size
    /// member functions with the same semantics as std::string does.
    template <
      typename Str,
      typename = std::enable_if_t<
        memory::has_span_data_member_v<Str, C> &&
        memory::has_span_size_member_v<Str>>>
    constexpr basic_string_span(const Str& str) noexcept
      : base(static_cast<P>(str.data()), limit_cast<S>(str.size())) {}

    using base::data;
    using base::empty;
    using base::size;

    /// @brief Named conversion to the corresponding standard string view.
    constexpr auto std_view() const noexcept -> std_view_type {
        return {data(), std_size_t(size())};
    }

    /// @brief Implicit conversion to the corresponding standard string view.
    constexpr operator std_view_type() const noexcept {
        return std_view();
    }

    /// @brief Conversion to the corresponding standard string.
    constexpr auto to_string() const -> string_type {
        return {data(), std_size_t(size())};
    }
};
//------------------------------------------------------------------------------
/// @brief Alias for mutable string spans.
/// @ingroup string_utils
using string_span = basic_string_span<char>;

/// @brief Alias for const string views.
/// @ingroup string_utils
using string_view = basic_string_span<const char>;
//------------------------------------------------------------------------------
/// @brief Converts a basic_span of characters to string_span.
/// @ingroup string_utils
template <typename C, typename P, typename S>
static constexpr auto std_view(memory::basic_span<C, P, S> spn) noexcept
  -> std::basic_string_view<std::remove_const_t<C>> {
    return {spn.data(), std_size_t(spn.size())};
}
//------------------------------------------------------------------------------
/// @brief Converts a basic_span of characters to standard string.
/// @ingroup string_utils
template <typename C, typename P, typename S>
static constexpr auto to_string(memory::basic_span<C, P, S> spn)
  -> std::basic_string<std::remove_const_t<C>> {
    return {spn.data(), std_size_t(spn.size())};
}
//------------------------------------------------------------------------------
/// @brief Assigns the contents of a span of characters to a standard string.
/// @ingroup string_utils
template <typename C, typename T, typename A, typename P, typename S>
static constexpr auto assign_to(
  std::basic_string<C, T, A>& str,
  memory::basic_span<const C, P, S> spn) -> auto& {
    str.assign(spn.data(), std_size(spn.size()));
    return str;
}
//------------------------------------------------------------------------------
/// @brief Appends the contents of a span of characters to a standard string.
/// @ingroup string_utils
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
/// @brief Comparator template for string span - string span comparisons.
/// @ingroup string_utils
template <typename Spn>
struct basic_view_less {
    using is_transparent = std::true_type;

    constexpr auto
    _helper(int cmp, span_size_t lsz, span_size_t rsz) const noexcept -> bool {
        return cmp < 0 ? true : cmp > 0 ? false : (lsz < rsz);
    }

    constexpr auto operator()(Spn l, Spn r) const noexcept -> bool {
        return _helper(
          std::strncmp(
            l.data(), r.data(), std_size(std::min(l.size(), r.size()))),
          l.size(),
          r.size());
    }
};
//------------------------------------------------------------------------------
/// @brief Comparator template for standard string - string span comparisons.
/// @ingroup string_utils
template <typename Str, typename Spn>
struct basic_str_view_less : basic_view_less<Spn> {
    using base = basic_view_less<Spn>;

    using base::operator();

    constexpr auto operator()(const Str& l, const Str& r) const noexcept
      -> bool {
        return l < r;
    }

    constexpr auto operator()(const Str& l, Spn r) const noexcept -> bool {
        return (*this)(Spn(l), r);
    }

    constexpr auto operator()(Spn l, const Str& r) const noexcept -> bool {
        return (*this)(l, Spn(r));
    }
};
//------------------------------------------------------------------------------
/// @brief Comparator template for standard string - string_view comparisons.
/// @ingroup string_utils
using str_view_less = basic_str_view_less<std::string, string_view>;
//------------------------------------------------------------------------------
// c_str
//------------------------------------------------------------------------------
/// @brief Helper template for getting zero-terminated strings from string spans.
/// @ingroup string_utils
/// @see c_str
///
/// String spans can in many cases internally know if the element past the end
/// is zero or not. There are cases where string spans or generally spans are
/// not zero terminated. Because of this whenever a zero-terminated C-string
/// is used, for example as an argument to a C-API call, instantiations of this
/// template should be used the obtain a valid C-string.
template <typename C, typename P, typename S>
class basic_c_str {
public:
    using string_type = std::basic_string<std::remove_const_t<C>>;
    using pointer_type = P;

    constexpr basic_c_str(basic_string_span<C, P, S> s)
      : _span{s.is_zero_terminated() ? s : basic_string_span<C, P, S>{}}
      , _str{s.is_zero_terminated() ? string_type{} : s.to_string()} {}

    /// @brief Return a zero terminated C-string as pointer_type.
    constexpr auto c_str() const noexcept -> pointer_type {
        return _span.empty() ? _str.c_str() : _span.data();
    }

    /// @brief Implicit conversion to character pointer_type.
    /// @see c_str
    constexpr operator pointer_type() const noexcept {
        return c_str();
    }

private:
    basic_string_span<C, P, S> _span{};
    string_type _str{};
};
//------------------------------------------------------------------------------
/// @brief Functions that construct a basic_c_str from a basic_string_span.
/// @ingroup string_utils
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
