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

#include "identity.hpp"
#include "nothing.hpp"
#include "span.hpp"
#include "std/type_traits.hpp"

namespace eagine {

template <typename T>
struct is_known_vector_type : std::false_type {};

template <typename T>
constexpr const bool is_known_vector_type_v = is_known_vector_type<T>::value;

template <typename T, span_size_t N>
struct is_known_vector_type<T[N]> : std::is_scalar<T> {};

template <typename T>
struct is_known_matrix_type : std::false_type {};

template <typename T>
constexpr const bool is_known_matrix_type_v = is_known_matrix_type<T>::value;

template <typename T, span_size_t C, span_size_t R>
struct is_known_matrix_type<T[C][R]> : std::is_scalar<T> {};

template <typename T>
struct canonical_compound_type : nothing_t {};

template <typename T>
using canonical_compound_type_t = typename canonical_compound_type<T>::type;

template <typename C, typename CT>
struct has_canonical_type : std::is_same<canonical_compound_type_t<C>, CT> {};

template <typename T, span_size_t N>
struct canonical_compound_type<T[N]> : identity<std::remove_cv_t<T[N]>> {};

template <typename T, span_size_t C, span_size_t R>
struct canonical_compound_type<T[C][R]>
  : identity<std::remove_cv_t<T[C][R]>> {};

template <typename T>
struct compound_element_type : identity<std::remove_cv_t<T>> {};

template <typename T, span_size_t N>
struct compound_element_type<T[N]> : identity<std::remove_cv_t<T>> {};

template <typename T, span_size_t C, span_size_t R>
struct compound_element_type<T[C][R]> : identity<std::remove_cv_t<T>> {};

template <typename T>
struct canonical_element_type
  : compound_element_type<canonical_compound_type_t<T>> {};

template <typename T>
using canonical_element_type_t = typename canonical_element_type<T>::type;

template <typename C>
struct compound_view_maker;

template <typename C>
static inline auto
element_view(const C& c) noexcept {
    return compound_view_maker<C>()(c);
}

template <typename T, span_size_t N>
struct compound_view_maker<T[N]> {
    inline span<T> operator()(T (&v)[N]) const noexcept {
	return {v, N};
    }
};

template <typename T, span_size_t N>
static inline auto
element_view(T (&v)[N]) noexcept {
    return compound_view_maker<T[N]>()(v);
}

template <typename T, span_size_t C, span_size_t R>
struct compound_view_maker<T[C][R]> {
    inline span<T> operator()(T (&v)[C][R]) const noexcept {
	return {v[0], C * R};
    }
};

template <typename T, span_size_t C, span_size_t R>
static inline auto
element_view(T (&m)[C][R]) noexcept {
    return compound_view_maker<T[C][R]>()(m);
}

template <typename C>
struct is_row_major : std::false_type {};

} // namespace eagine

#endif // include guard
