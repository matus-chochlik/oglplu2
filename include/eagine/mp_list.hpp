/**
 *  @file eagine/mp_list.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MP_LIST_1509260923_HPP
#define EAGINE_MP_LIST_1509260923_HPP

#include "std/type_traits.hpp"

namespace eagine {

template <typename... C>
struct mp_list {
    typedef mp_list type;
};

template <typename TL>
struct mp_empty;

template <>
struct mp_empty<mp_list<>> : std::true_type {};

template <typename... T>
struct mp_empty<mp_list<T...>> : std::false_type {};

template <typename TL, typename T>
struct mp_contains;

template <typename T>
struct mp_contains<mp_list<>, T> : std::false_type {};

template <typename H, typename... C, typename T>
struct mp_contains<mp_list<H, C...>, T> : mp_contains<mp_list<C...>, T> {};

template <typename... C, typename T>
struct mp_contains<mp_list<T, C...>, T> : std::true_type {};

template <typename TL, typename T>
using mp_contains_t = typename mp_contains<TL, T>::type;

template <typename TL1, typename TL2, typename TL3>
struct mp_union_add;

template <typename... T3>
struct mp_union_add<mp_list<>, mp_list<>, mp_list<T3...>> : mp_list<T3...> {};

template <typename... T1, typename... T3>
struct mp_union_add<mp_list<T1...>, mp_list<>, mp_list<T3...>>
  : mp_list<T3...> {};

template <typename... T2, typename... T3>
struct mp_union_add<mp_list<>, mp_list<T2...>, mp_list<T3...>>
  : mp_list<T3...> {};

template <typename H, typename... T1, typename... T2, typename... T3>
struct mp_union_add<mp_list<H, T1...>, mp_list<T2...>, mp_list<T3...>>
  : std::conditional_t<
      mp_contains<mp_list<T2...>, H>::value,
      mp_union_add<mp_list<T1...>, mp_list<T2...>, mp_list<T3..., H>>,
      mp_union_add<mp_list<T1...>, mp_list<T2...>, mp_list<T3...>>> {};

template <typename TL1, typename TL2>
using mp_union = mp_union_add<TL1, TL2, mp_list<>>;

template <typename TL1, typename TL2>
using mp_union_t = typename mp_union<TL1, TL2>::type;

} // namespace eagine

#endif // include guard
