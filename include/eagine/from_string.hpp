/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_FROM_STRING_HPP
#define EAGINE_FROM_STRING_HPP

#include "is_within_limits.hpp"
#include "memory/span_algo.hpp"
#include "mp_string.hpp"
#include "selector.hpp"
#include "string_span.hpp"
#include "type_identity.hpp"
#include "valid_if/always.hpp"
#include "valid_if/decl.hpp"
#include <chrono>
#include <cstdlib>

namespace eagine {
//------------------------------------------------------------------------------
auto _parse_from_string(string_view src, long long int&) noexcept -> bool;
//------------------------------------------------------------------------------
template <typename T>
static inline auto parse_from_string(string_view src, type_identity<T>) noexcept
  -> std::enable_if_t<std::is_integral_v<T>, optionally_valid<T>> {
    long long int parsed{};
    if(_parse_from_string(src, parsed)) {
        return convert_if_fits<T>(parsed);
    }
    return {};
}
//------------------------------------------------------------------------------
auto _parse_from_string(string_view src, long double&) noexcept -> bool;
//------------------------------------------------------------------------------
template <typename T>
static inline auto parse_from_string(string_view src, type_identity<T>) noexcept
  -> std::enable_if_t<std::is_floating_point_v<T>, optionally_valid<T>> {
    long double parsed{};
    if(_parse_from_string(src, parsed)) {
        return convert_if_fits<T>(parsed);
    }
    return {};
}
//------------------------------------------------------------------------------
template <identifier_t V>
static inline auto
from_string(string_view src, type_identity<bool>, selector<V>) noexcept
  -> optionally_valid<bool> {

    const string_view true_strs[] = {{"true"}, {"True"}, {"1"}, {"t"}, {"T"}};
    if(find_element(view(true_strs), src)) {
        return {true, true};
    }

    const string_view false_strs[] = {
      {"false"}, {"False"}, {"0"}, {"f"}, {"F"}};
    if(find_element(view(false_strs), src)) {
        return {false, true};
    }

    return {};
}

template <identifier_t V>
static inline auto
from_string(string_view src, type_identity<char>, selector<V>) noexcept
  -> optionally_valid<char> {
    if(src.size() == 1) {
        return {extract(src), true};
    }
    return {};
}
//------------------------------------------------------------------------------
template <typename T, typename N>
auto multiply_and_convert_if_fits(N n, const char* c) noexcept
  -> optionally_valid<T> {
    if(!c[0]) {
        return convert_if_fits<T>(n);
    } else if((c[0] == 'k') && (!c[1])) {
        return convert_if_fits<T>(n * 1000);
    } else if((c[0] == 'M') && (!c[1])) {
        return convert_if_fits<T>(n * 1000000);
    } else if((c[0] == 'G') && (!c[1])) {
        return convert_if_fits<T>(n * 1000000000);
    }

    return {};
}
//------------------------------------------------------------------------------
template <typename T, typename N>
auto convert_from_string_with(
  N (*converter)(const char*, char**),
  string_view src,
  type_identity<T> tid) noexcept -> optionally_valid<T> {
    char* end = nullptr;
    auto cstr = c_str(src);
    errno = 0;
    const N result{converter(cstr, &end)};
    if((errno != ERANGE) && (end != cstr) && (end != nullptr)) {
        if(auto converted{multiply_and_convert_if_fits<T>(result, end)}) {
            return converted;
        }
    }

    return parse_from_string(src, tid);
}
//------------------------------------------------------------------------------
template <typename T, typename N>
auto convert_from_string_with(
  N (*converter)(const char*, char**, int),
  int base,
  string_view src,
  type_identity<T> tid) noexcept -> optionally_valid<T> {
    char* end = nullptr;
    auto cstr = c_str(src);
    errno = 0;
    const N result = converter(cstr, &end, base);
    if((errno != ERANGE) && (end != cstr) && (end != nullptr)) {
        if(auto converted{multiply_and_convert_if_fits<T>(result, end)}) {
            return converted;
        }
    }

    return parse_from_string(src, tid);
}
//------------------------------------------------------------------------------
template <identifier_t V>
static inline auto from_string(
  string_view src,
  type_identity<short> id,
  selector<V>,
  int base = 10) noexcept -> optionally_valid<short> {
    return convert_from_string_with(&std::strtol, base, src, id);
}

template <identifier_t V>
static inline auto from_string(
  string_view src,
  type_identity<int> id,
  selector<V>,
  int base = 10) noexcept -> optionally_valid<int> {
    return convert_from_string_with(&std::strtol, base, src, id);
}

template <identifier_t V>
static inline auto from_string(
  string_view src,
  type_identity<long> id,
  selector<V>,
  int base = 10) noexcept -> optionally_valid<long> {
    return convert_from_string_with(&std::strtol, base, src, id);
}

template <identifier_t V>
static inline auto from_string(
  string_view src,
  type_identity<long long> id,
  selector<V>,
  int base = 10) noexcept -> optionally_valid<long long> {
    return convert_from_string_with(&std::strtoll, base, src, id);
}

template <identifier_t V>
static inline auto from_string(
  string_view src,
  type_identity<unsigned short> id,
  selector<V>,
  int base = 10) noexcept -> optionally_valid<unsigned short> {
    return convert_from_string_with(&std::strtoul, base, src, id);
}

template <identifier_t V>
static inline auto from_string(
  string_view src,
  type_identity<unsigned int> id,
  selector<V>,
  int base = 10) noexcept -> optionally_valid<unsigned int> {
    return convert_from_string_with(&std::strtoul, base, src, id);
}

template <identifier_t V>
static inline auto from_string(
  string_view src,
  type_identity<unsigned long> id,
  selector<V>,
  int base = 10) noexcept -> optionally_valid<unsigned long> {
    return convert_from_string_with(&std::strtoul, base, src, id);
}

template <identifier_t V>
static inline auto from_string(
  string_view src,
  type_identity<unsigned long long> id,
  selector<V>,
  int base = 10) noexcept -> optionally_valid<unsigned long long> {
    return convert_from_string_with(&std::strtoull, base, src, id);
}
//------------------------------------------------------------------------------
template <identifier_t V>
static inline auto
from_string(string_view src, type_identity<byte>, selector<V> sel) noexcept
  -> optionally_valid<byte> {
    if(starts_with(src, string_view("0x"))) {
        if(const auto opt_val{
             from_string(skip(src, 2), type_identity<unsigned>(), sel, 16)}) {
            return {static_cast<byte>(extract(opt_val)), bool(opt_val <= 255U)};
        }
    }
    if(starts_with(src, string_view("0"))) {
        if(const auto opt_val{
             from_string(skip(src, 1), type_identity<unsigned>(), sel, 8)}) {
            return {static_cast<byte>(extract(opt_val)), bool(opt_val <= 255U)};
        }
    }
    if(const auto opt_val{
         from_string(src, type_identity<unsigned>(), sel, 10)}) {
        return {static_cast<byte>(extract(opt_val)), bool(opt_val <= 255U)};
    }
    return {};
}
//------------------------------------------------------------------------------
template <identifier_t V>
static inline auto
from_string(string_view src, type_identity<float> id, selector<V>) noexcept
  -> optionally_valid<float> {
    return convert_from_string_with(&std::strtof, src, id);
}

template <identifier_t V>
static inline auto
from_string(string_view src, type_identity<double> id, selector<V>) noexcept
  -> optionally_valid<double> {
    return convert_from_string_with(&std::strtod, src, id);
}

template <identifier_t V>
static inline auto from_string(
  string_view src,
  type_identity<long double> id,
  selector<V>) noexcept -> optionally_valid<long double> {
    return convert_from_string_with(&std::strtold, src, id);
}

template <identifier_t V>
static inline auto
from_string(string_view src, type_identity<std::string>, selector<V>) noexcept
  -> always_valid<std::string> {
    return to_string(src);
}
//------------------------------------------------------------------------------
template <typename Rep, typename Period, identifier_t V, typename Symbol>
static inline auto convert_from_string(
  string_view src,
  type_identity<std::chrono::duration<Rep, Period>>,
  selector<V> sel,
  Symbol sym_const) noexcept
  -> optionally_valid<std::chrono::duration<Rep, Period>> {
    const string_view symbol{sym_const};
    if(memory::ends_with(src, symbol)) {
        if(
          auto opt_val =
            from_string(snip(src, symbol.size()), type_identity<Rep>(), sel)) {
            return {std::chrono::duration<Rep, Period>(extract(opt_val)), true};
        }
    }
    return {};
}
//------------------------------------------------------------------------------
template <typename Rep, typename Period, identifier_t V>
static inline auto from_string(
  string_view str,
  type_identity<std::chrono::duration<Rep, Period>>,
  selector<V> sel) noexcept
  -> optionally_valid<std::chrono::duration<Rep, Period>> {
    using dur_t = std::chrono::duration<Rep, Period>;

    if(
      auto d = convert_from_string(
        str,
        type_identity<std::chrono::duration<Rep, std::ratio<1>>>(),
        sel,
        mp_string<'s'>())) {
        return {std::chrono::duration_cast<dur_t>(extract(d)), true};
    }
    if(
      auto d = convert_from_string(
        str,
        type_identity<std::chrono::duration<Rep, std::milli>>(),
        sel,
        mp_string<'m', 's'>())) {
        return {std::chrono::duration_cast<dur_t>(extract(d)), true};
    }
    if(
      auto d = convert_from_string(
        str,
        type_identity<std::chrono::duration<Rep, std::micro>>(),
        sel,
        mp_string<char(0xc2), char(0xb5), 's'>())) {
        return {std::chrono::duration_cast<dur_t>(extract(d)), true};
    }
    if(
      auto d = convert_from_string(
        str,
        type_identity<std::chrono::duration<Rep, std::nano>>(),
        sel,
        mp_string<'n', 's'>())) {
        return {std::chrono::duration_cast<dur_t>(extract(d)), true};
    }
    if(
      auto d = convert_from_string(
        str,
        type_identity<std::chrono::duration<Rep, std::ratio<60>>>(),
        sel,
        mp_string<'m', 'i', 'n'>())) {
        return {std::chrono::duration_cast<dur_t>(extract(d)), true};
    }
    if(
      auto d = convert_from_string(
        str,
        type_identity<std::chrono::duration<Rep, std::ratio<3600>>>(),
        sel,
        mp_string<'h', 'r'>())) {
        return {std::chrono::duration_cast<dur_t>(extract(d)), true};
    }
    if(
      auto d = convert_from_string(
        str,
        type_identity<std::chrono::duration<Rep, std::ratio<86400LL>>>(),
        sel,
        mp_string<'d', 'y'>())) {
        return {std::chrono::duration_cast<dur_t>(extract(d)), true};
    }
    if(
      auto d = convert_from_string(
        str,
        type_identity<std::chrono::duration<Rep, std::ratio<31556952LL>>>(),
        sel,
        mp_string<'y', 'r'>())) {
        return {std::chrono::duration_cast<dur_t>(extract(d)), true};
    }
    if(
      auto d = convert_from_string(
        str,
        type_identity<std::chrono::duration<Rep, std::ratio<31556952LL>>>(),
        sel,
        mp_string<'a'>())) {
        return {std::chrono::duration_cast<dur_t>(extract(d)), true};
    }
    return {};
}
//------------------------------------------------------------------------------
/// @brief Converts the string representation in @p src to a value of type @p T.
/// @ingroup type_utils
/// @see is_within_limits
template <typename T>
auto from_string(string_view src) noexcept {
    return from_string(src, type_identity<T>(), default_selector);
}
//------------------------------------------------------------------------------
/// @brief Converts the string representation in @p src to a value of type @p T.
/// @ingroup type_utils
/// @see is_within_limits
///
/// This overload allows to specify a selector that can change the value
/// conversion rules.
template <typename T, identifier_t V>
auto from_string(string_view src, selector<V> sel) noexcept {
    return from_string(src, type_identity<T>(), sel);
}
//------------------------------------------------------------------------------
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/from_string.inl>
#endif

#endif // EAGINE_FROM_STRING_HPP
