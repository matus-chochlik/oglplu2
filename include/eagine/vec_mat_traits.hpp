/**
 *  @file eagine/vec_mat_traits.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VEC_MAT_TRAITS_1509260923_HPP
#define EAGINE_VEC_MAT_TRAITS_1509260923_HPP

#include "array_view.hpp"
#include "identity.hpp"
#include "nothing.hpp"
#include <type_traits>

namespace eagine {

template <typename T>
struct is_known_vector_type
 : std::false_type
{ };

template <typename T, std::size_t N>
struct is_known_vector_type<T[N]>
 : std::is_scalar<T>
{ };

template <typename T>
struct is_known_matrix_type
 : std::false_type
{ };

template <typename T, std::size_t C, std::size_t R>
struct is_known_matrix_type<T[C][R]>
 : std::is_scalar<T>
{ };

template <typename T>
struct canonical_compound_type
 : nothing_t
{ };

template <typename C, typename CT>
struct has_canonical_compound_type
 : std::is_same<typename canonical_compound_type<C>::type, CT>
{ };

template <typename T, std::size_t N>
struct canonical_compound_type<T[N]>
 : identity<typename std::remove_cv<T[N]>::type>
{ };

template <typename T, std::size_t C, std::size_t R>
struct canonical_compound_type<T[C][R]>
 : identity<typename std::remove_cv<T[C][R]>::type>
{ };

template <typename T, std::size_t N>
static inline
array_view<T>
element_view(T (&v)[N])
noexcept
{
	return {v, N};
}

template <typename T, std::size_t C, std::size_t R>
static inline
array_view<T>
element_view(T (&v)[C][R])
noexcept
{
	return {v[0], C*R};
}

template <typename R>
static constexpr inline
bool is_row_major(R)
noexcept;

template <typename T, std::size_t C, std::size_t R>
static constexpr inline
bool is_row_major(T (&)[C][R])
noexcept
{
	return false;
}

} // namespace eagine

#endif // include guard
