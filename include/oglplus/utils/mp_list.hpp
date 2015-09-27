/**
 *  @file oglplus/utils/mp_list.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_UTILS_MP_LIST_1509260923_HPP
#define OGLPLUS_UTILS_MP_LIST_1509260923_HPP

#include <type_traits>

namespace oglplus {

template <typename ... C>
struct mp_list;

template <typename TL, typename T>
struct mp_contains;

template <typename T>
struct mp_contains<mp_list<>, T>
 : std::false_type
{ };

template <typename H, typename ... C, typename T>
struct mp_contains<mp_list<H, C...>, T>
 : mp_contains<mp_list<C...>, T>
{ };

template <typename ... C, typename T>
struct mp_contains<mp_list<T,C...>, T>
 : std::true_type
{ };

} // namespace oglplus

#endif // include guard
