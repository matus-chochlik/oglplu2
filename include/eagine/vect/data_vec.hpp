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
#include <utility>
#include <cstdint>

namespace eagine {
namespace vect {

#if EAGINE_USE_SIMD
#if defined(__clang__)

// int8_t
template <>
struct _vec_data<int8_t, 8>
{
	typedef int8_t type __attribute__ ((vector_size ( 8)));
};

// int16_t
template <>
struct _vec_data<int16_t, 4>
{
	typedef int16_t type __attribute__ ((vector_size ( 8)));
};

// int32_t
template <>
struct _vec_data<int32_t, 2>
{
	typedef int32_t type __attribute__ ((vector_size ( 8)));
};

template <>
struct _vec_data<int32_t, 4>
{
	typedef int32_t type __attribute__ ((vector_size (16)));
};

// int64_t
template <>
struct _vec_data<int64_t, 2>
{
	typedef int64_t type __attribute__ ((vector_size (16)));
};

template <>
struct _vec_data<int64_t, 4>
{
	typedef int64_t type __attribute__ ((vector_size (32)));
};

// float
template <>
struct _vec_data<float, 2>
{
	typedef float type __attribute__ ((vector_size ( 8)));
};

template <>
struct _vec_data<float, 3>
{
	typedef float type __attribute__ ((vector_size (16)));
};

template <>
struct _vec_data<float, 4>
{
	typedef float type __attribute__ ((vector_size (16)));
};

// double
template <>
struct _vec_data<double, 2>
{
	typedef double type __attribute__ ((vector_size (16)));
};

template <>
struct _vec_data<double, 3>
{
	typedef double type __attribute__ ((vector_size (32)));
};

template <>
struct _vec_data<double, 4>
{
	typedef double type __attribute__ ((vector_size (32)));
};

#elif defined(__GNUC__)

template <typename T, int N>
struct _gnuc_vec_data
{
	typedef T type __attribute__ ((vector_size (sizeof(T)*N)));
};

template <typename T>
struct _vec_data<T,2> : _gnuc_vec_data<T,2>
{ };

template <typename T>
struct _vec_data<T,3> : _gnuc_vec_data<T,4>
{ };

template <typename T>
struct _vec_data<T,4> : _gnuc_vec_data<T,4>
{ };

template <typename T>
struct _vec_data<T,8> : _gnuc_vec_data<T,8>
{ };

#endif // platform

// has_vec_data<int8_t>
template <int N>
struct _has_vec_data<int8_t, N>
 : bool_constant<
#if defined(__SSE2__) && __SSE2__
	((N==2)||(N==4)||(N==8)||(N==16)) ||
#endif
#if defined(__MMX__) && __MMX__
	((N==2)||(N==4)||(N==8)) ||
#endif
	false
>
{ };

// has_vec_data<int16_t>
template <int N>
struct _has_vec_data<int16_t, N>
 : bool_constant<
#if defined(__SSE2__) && __SSE2__
	((N==2)||(N==4)||(N==8)) ||
#endif
#if defined(__MMX__) && __MMX__
	((N==2)||(N==4)) ||
#endif
	false
>
{ };

// has_vec_data<int32_t>
template <int N>
struct _has_vec_data<int32_t, N>
 : bool_constant<
#if defined(__SSE2__) && __SSE2__
	((N==2)||(N==4)) ||
#endif
#if defined(__MMX__) && __MMX__
	(N==2) ||
#endif
	false
>
{ };

// has_vec_data<int64_t>
template <int N>
struct _has_vec_data<int64_t, N>
 : bool_constant<
#if defined(__SSE2__) && __SSE2__
	(N==2) ||
#endif
	false
>
{ };

// has_vec_data<float>
template <int N>
struct _has_vec_data<float, N>
 : bool_constant<
#if defined(__AVX__) && __AVX__
	((N==2)||(N==3)||(N==4)) ||
#endif
#if defined(__SSE__) && __SSE__
	((N==2)||(N==4)) ||
#endif
	false
>
{ };

// has_vec_data<double>
template <int N>
struct _has_vec_data<double, N>
 : bool_constant<
#if defined(__AVX__) && __AVX__
	((N==2)||(N==4)) ||
#endif
#if defined(__SSE2__) && __SSE2__
	(N==2) ||
#endif
	false
>
{ };
#endif // EAGINE_USE_SIMD

} // namespace vect
} // namespace eagine

#endif //include guard

