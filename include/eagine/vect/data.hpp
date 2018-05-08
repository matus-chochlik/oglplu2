/**
 *  @file eagine/vect/data.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_VECT_DATA_1509260923_HPP
#define EAGINE_VECT_DATA_1509260923_HPP

#include "data_ary.hpp"
#if EAGINE_USE_SIMD
#include "data_vec.hpp"
#endif

namespace eagine {
namespace vect {

// data
template <typename T, int N, bool V>
struct data
  : std::conditional_t<_has_vec_data<T, N>::value && V,
      _vec_data<T, N>,
      _ary_data<T, N>> {
    typedef T value_type;
    static constexpr int size = N;
};

// has_vect_data
template <typename T, int N, bool V>
struct has_vect_data : bool_constant<V && _has_vec_data<T, N>::value> {};

// data_param
template <typename T, int N, bool V>
struct data_param
  : std::conditional_t<_has_vec_data<T, N>::value && V,
      _vec_data<T, N>,
      _ary_cref<T, N>> {};

// param
template <typename Data>
struct param;

template <typename T, int N, bool V>
struct param<data<T, N, V>> : data_param<T, N, V> {};

} // namespace vect
} // namespace eagine

#endif // include guard
