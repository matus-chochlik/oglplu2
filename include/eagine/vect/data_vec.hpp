/**
 *  @file eagine/vect/data_vec.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_VECT_DATA_VEC_1509260923_HPP
#define EAGINE_VECT_DATA_VEC_1509260923_HPP

#include "config.hpp"
#include "fwd.hpp"
#include <cstdint>
#include <utility>

namespace eagine {
namespace vect {

#if EAGINE_USE_SIMD
#if defined(__clang__)

// int8_t
template <>
struct _vec_data<int8_t, 8> {
    using type __attribute__((vector_size(8))) = int8_t;
};

// int16_t
template <>
struct _vec_data<int16_t, 4> {
    using type __attribute__((vector_size(8))) = int16_t;
};

// int32_t
template <>
struct _vec_data<int32_t, 2> {
    using type __attribute__((vector_size(8))) = int32_t;
};

template <>
struct _vec_data<int32_t, 4> {
    using type __attribute__((vector_size(16))) = int32_t;
};

// int64_t
template <>
struct _vec_data<int64_t, 2> {
    using type __attribute__((vector_size(16))) = int64_t;
};

template <>
struct _vec_data<int64_t, 4> {
    using type __attribute__((vector_size(32))) = int64_t;
};

// float
template <>
struct _vec_data<float, 2> {
    using type __attribute__((vector_size(8))) = float;
};

template <>
struct _vec_data<float, 3> {
    using type __attribute__((vector_size(16))) = float;
};

template <>
struct _vec_data<float, 4> {
    using type __attribute__((vector_size(16))) = float;
};

// double
template <>
struct _vec_data<double, 2> {
    using type __attribute__((vector_size(16))) = double;
};

template <>
struct _vec_data<double, 3> {
    using type __attribute__((vector_size(32))) = double;
};

template <>
struct _vec_data<double, 4> {
    using type __attribute__((vector_size(32))) = double;
};

#elif defined(__GNUC__)

template <typename T, int N>
struct _gnuc_vec_data {
    using type __attribute__((vector_size(sizeof(T) * N))) = T;
};

template <typename T>
struct _vec_data<T, 2> : _gnuc_vec_data<T, 2> {};

template <typename T>
struct _vec_data<T, 3> : _gnuc_vec_data<T, 4> {};

template <typename T>
struct _vec_data<T, 4> : _gnuc_vec_data<T, 4> {};

template <typename T>
struct _vec_data<T, 8> : _gnuc_vec_data<T, 8> {};

#endif // platform

// has_vec_data<int8_t>
template <int N>
struct _has_vec_data<int8_t, N>
  : bool_constant<
#if defined(__SSE2__) && __SSE2__
      ((N == 2) || (N == 4) || (N == 8) || (N == 16)) ||
#endif
#if defined(__MMX__) && __MMX__
      ((N == 2) || (N == 4) || (N == 8)) ||
#endif
      false> {
};

// has_vec_data<int16_t>
template <int N>
struct _has_vec_data<int16_t, N>
  : bool_constant<
#if defined(__SSE2__) && __SSE2__
      ((N == 2) || (N == 4) || (N == 8)) ||
#endif
#if defined(__MMX__) && __MMX__
      ((N == 2) || (N == 4)) ||
#endif
      false> {
};

// has_vec_data<int32_t>
template <int N>
struct _has_vec_data<int32_t, N>
  : bool_constant<
#if defined(__SSE2__) && __SSE2__
      ((N == 2) || (N == 4)) ||
#endif
#if defined(__MMX__) && __MMX__
      (N == 2) ||
#endif
      false> {
};

// has_vec_data<int64_t>
template <int N>
struct _has_vec_data<int64_t, N>
  : bool_constant<
#if defined(__SSE2__) && __SSE2__
      (N == 2) ||
#endif
      false> {
};

// has_vec_data<float>
template <int N>
struct _has_vec_data<float, N>
  : bool_constant<
#if defined(__AVX__) && __AVX__
      ((N == 2) || (N == 3) || (N == 4)) ||
#endif
#if defined(__SSE__) && __SSE__
      ((N == 2) || (N == 4)) ||
#endif
      false> {
};

// has_vec_data<double>
template <int N>
struct _has_vec_data<double, N>
  : bool_constant<
#if defined(__AVX__) && __AVX__
      ((N == 2) || (N == 4)) ||
#endif
#if defined(__SSE2__) && __SSE2__
      (N == 2) ||
#endif
      false> {
};
#endif // EAGINE_USE_SIMD

} // namespace vect
} // namespace eagine

#endif // include guard
