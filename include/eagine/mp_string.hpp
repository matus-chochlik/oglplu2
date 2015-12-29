/**
 *  @file eagine/mp_string.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MP_STRING_1509260923_HPP
#define EAGINE_MP_STRING_1509260923_HPP

#include "int_sequence.hpp"
#include "type_traits.hpp"

namespace eagine {

// mp_string
template <char ... C>
struct mp_string
{
	typedef mp_string type;

	typedef const char value_type [sizeof ... (C)+1];
	static constexpr const char value [sizeof ... (C)+1] = {C...,'\0'};
};

template <char ... C>
constexpr const char mp_string<C...>::value[sizeof ... (C)+1];

// mp_strlen
template <typename String>
struct mp_strlen;

template <char ... C>
struct mp_strlen<mp_string<C...>>
 : size_constant<sizeof...(C)>
{ };

// mp_concat
template <typename ... S>
struct mp_concat;

template <typename ... S>
using mp_concat_t = typename mp_concat<S...>::type;

template <char ... C>
struct mp_concat<mp_string<C...>>
 : mp_string<C...>
{ };

template <char ... C1, char ... C2, typename ... S>
struct mp_concat<mp_string<C1...>, mp_string<C2...>, S...>
 : mp_concat_t<mp_string<C1..., C2...>, S...>
{ };

// mp_translate
template <typename S, template <char> class Transf>
struct mp_translate;

template <typename S, template <char> class Transf>
using mp_translate_t = typename mp_translate<S, Transf>::type;

template <char ... C, template <char> class Transf>
struct mp_translate<mp_string<C...>, Transf>
 : mp_concat_t<typename Transf<C>::type...>
{ };

// mp_uint_to_string
template <unsigned I>
struct mp_uint_to_string;

template <unsigned I>
using mp_uint_to_string_t = typename mp_uint_to_string<I>::type;

template <> struct mp_uint_to_string<0u> : mp_string<'0'> { };
template <> struct mp_uint_to_string<1u> : mp_string<'1'> { };
template <> struct mp_uint_to_string<2u> : mp_string<'2'> { };
template <> struct mp_uint_to_string<3u> : mp_string<'3'> { };
template <> struct mp_uint_to_string<4u> : mp_string<'4'> { };
template <> struct mp_uint_to_string<5u> : mp_string<'5'> { };
template <> struct mp_uint_to_string<6u> : mp_string<'6'> { };
template <> struct mp_uint_to_string<7u> : mp_string<'7'> { };
template <> struct mp_uint_to_string<8u> : mp_string<'8'> { };
template <> struct mp_uint_to_string<9u> : mp_string<'9'> { };

template <unsigned I>
struct mp_uint_to_string
 : mp_concat_t<mp_uint_to_string_t<I/10>, mp_uint_to_string_t<I%10>>
{ };

// mp_int_to_string
template <int I>
struct mp_int_to_string
 : std::conditional_t<
	(I < 0),
	mp_concat<mp_string<'-'>, mp_uint_to_string_t<unsigned(-I)>>,
	mp_uint_to_string_t<unsigned(I)>
> { };

template <int I>
using mp_int_to_string_t = typename mp_int_to_string<I>::type;

// bits
namespace bits {

// mp_create_string
template <typename S, typename IS>
struct mp_create_string;

template <typename S, std::size_t ... I>
struct mp_create_string<S, std::index_sequence<I...>>
 : mp_string<S::mp_str[I]...>
{ };

// mp_do_make_string
template <typename S, typename A>
struct mp_do_make_string;

template <typename S, std::size_t N>
struct mp_do_make_string<S, const char[N]>
 : mp_create_string<S, std::make_index_sequence<N-1>>
{ };

template <typename X>
std::true_type does_have_mp_str_const(X*, decltype(X::mp_str) = X::mp_str);

std::false_type does_have_mp_str_const(...);

} // namespace bits

// has_mp_str_const
template <typename T>
struct has_mp_str_const
 : decltype(bits::does_have_mp_str_const(static_cast<T*>(nullptr)))
{ };

template <typename T>
using has_mp_str_const_t = typename has_mp_str_const<T>::type;

// mp_make_string
template <typename S>
struct mp_make_string
 : bits::mp_do_make_string<S, decltype(S::mp_str)>
{ };

template <typename S>
using mp_make_string_t = typename mp_make_string<S>::type;

} // namespace eagine

#endif // include guard
