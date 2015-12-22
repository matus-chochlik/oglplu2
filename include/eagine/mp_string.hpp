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

namespace eagine {

template <char ... C>
struct mp_string
{
	typedef mp_string type;

	typedef const char value_type [sizeof ... (C)];
	static constexpr const char value [sizeof ... (C)] = {C...};
};

template <char ... C>
constexpr const char mp_string<C...>::value[sizeof ... (C)];

template <typename S, typename A>
struct mp_do_make_string;

template <typename S, typename IS>
struct mp_create_string;

template <typename S, std::size_t ... I>
struct mp_create_string<S, std::index_sequence<I...>>
 : mp_string<S::mp_str[I]...>
{ };

template <typename S, std::size_t N>
struct mp_do_make_string<S, const char[N]>
 : mp_create_string<S, std::make_index_sequence<N>>
{ };

template <typename S>
struct mp_make_string
 : mp_do_make_string<S, decltype(S::mp_str)>
{ };

} // namespace eagine

#endif // include guard
