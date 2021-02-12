/// @file eagine/unit/strings.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_UNITS_STRINGS_HPP
#define EAGINE_UNITS_STRINGS_HPP

#include "../fixed_size_str.hpp"
#include "../mp_strings.hpp"
#include "../string_span.hpp"
#include "detail.hpp"
#include "fwd.hpp"

namespace eagine::units {
//------------------------------------------------------------------------------
template <typename MpStr, int Pow>
struct dim_pow_superscript
  : mp_concat<MpStr, mp_translate_t<mp_int_to_string_t<Pow>, mp_superscript>> {
};
//------------------------------------------------------------------------------
template <typename MpStr>
struct dim_pow_superscript<MpStr, 0> : mp_string<> {};
//------------------------------------------------------------------------------
template <typename MpStr>
struct dim_pow_superscript<MpStr, 1> : MpStr {};
//------------------------------------------------------------------------------
template <typename MpStr, int Pow>
using dim_pow_superscript_t = typename dim_pow_superscript<MpStr, Pow>::type;
//------------------------------------------------------------------------------
template <typename MpStrL, typename MpStrR>
struct chain_term_strings
  : mp_concat_t<MpStrL, mp_string<char(0xC3), char(0x97)>, MpStrR> {};
//------------------------------------------------------------------------------
template <typename MpStrL>
struct chain_term_strings<MpStrL, mp_string<>> : MpStrL {};
//------------------------------------------------------------------------------
template <typename MpStrL, typename MpStrR>
using chain_term_strings_t = typename chain_term_strings<MpStrL, MpStrR>::type;
//------------------------------------------------------------------------------
// generic unit system name
//------------------------------------------------------------------------------
template <template <typename> class MpStrWrap, typename X, typename MpStr>
struct compose_str;
//------------------------------------------------------------------------------
template <template <typename> class MpStrWrap, typename X>
using compose_str_t =
  typename compose_str<MpStrWrap, X, decltype(MpStrWrap<X>::mp_str)>::type;
//------------------------------------------------------------------------------
template <template <typename> class MpStrWrap, typename X>
using compose_str_n = typename compose_str<MpStrWrap, X, nothing_t>::type;
//------------------------------------------------------------------------------
template <template <typename> class MpStrWrap, typename X>
struct compose_str<MpStrWrap, X, const nothing_t>
  : compose_str_n<MpStrWrap, X> {};
//------------------------------------------------------------------------------
template <template <typename> class MpStrWrap, typename X, std::size_t N>
struct compose_str<MpStrWrap, X, const char[N]>
  : mp_make_string_t<MpStrWrap<X>> {};
//------------------------------------------------------------------------------
template <template <typename> class MpStrWrap>
struct compose_str<MpStrWrap, nothing_t, nothing_t> : mp_string<> {};
//------------------------------------------------------------------------------
template <template <typename> class MpStrWrap, typename BaseDim, int Pow>
struct compose_str<MpStrWrap, bits::dim_pow<BaseDim, Pow>, nothing_t>
  : dim_pow_superscript_t<mp_make_string_t<MpStrWrap<BaseDim>>, Pow> {};
//------------------------------------------------------------------------------
template <template <typename> class MpStrWrap, typename H, typename T>
struct compose_str<MpStrWrap, bits::dims<H, T>, nothing_t>
  : chain_term_strings<compose_str_t<MpStrWrap, H>, compose_str_t<MpStrWrap, T>> {
};
//------------------------------------------------------------------------------
template <template <typename> class MpStrWrap, typename Sys>
struct compose_str<MpStrWrap, unit<nothing_t, Sys>, nothing_t> : mp_string<> {};
//------------------------------------------------------------------------------
template <template <typename> class MpStrWrap, typename Dim, int Pow, typename Sys>
struct compose_str<MpStrWrap, unit<bits::dim_pow<Dim, Pow>, Sys>, nothing_t>
  : dim_pow_superscript_t<
      compose_str_t<MpStrWrap, typename Sys::template base_unit<Dim>::type>,
      Pow> {};
//------------------------------------------------------------------------------
template <template <typename> class MpStrWrap, typename H, typename T, typename Sys>
struct compose_str<MpStrWrap, unit<bits::dims<H, T>, Sys>, nothing_t>
  : chain_term_strings<
      compose_str_t<MpStrWrap, unit<H, Sys>>,
      compose_str_t<MpStrWrap, unit<T, Sys>>> {};

//------------------------------------------------------------------------------
template <template <typename> class MpStrWrap, typename Scale, typename Unit>
struct compose_str<MpStrWrap, base::scaled_unit<Scale, Unit>, nothing_t>
  : mp_concat<compose_str_t<MpStrWrap, Scale>, compose_str_t<MpStrWrap, Unit>> {
};
//------------------------------------------------------------------------------
template <typename X>
static inline auto get_symbol(X) noexcept -> string_view {
    return compose_str_t<symbol_of, X>::value;
}
//------------------------------------------------------------------------------
template <typename X>
static inline auto get_symbol_form(X) noexcept -> string_view {
    return compose_str_n<symbol_of, X>::value;
}
//------------------------------------------------------------------------------
template <typename X>
static inline auto get_name(X) noexcept -> string_view {
    return compose_str_t<name_of, X>::value;
}
//------------------------------------------------------------------------------
template <typename X>
static inline auto get_name_form(X) noexcept -> string_view {
    return compose_str_n<name_of, X>::value;
}
//------------------------------------------------------------------------------
} // namespace eagine::units

#endif // EAGINE_UNITS_STRINGS_HPP
