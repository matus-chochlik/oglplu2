/// @file eagine/vect/fwd.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_VECT_FWD_HPP
#define EAGINE_VECT_FWD_HPP

#include "../int_constant.hpp"

namespace eagine::vect {

template <typename T, int N>
struct _ary_data;

template <typename T, int N>
struct _vec_data;

template <typename T, int N>
struct _has_vec_data : std::false_type {};

template <typename T, int N, bool V>
struct has_vect_data;

template <typename T, int N, bool V>
using has_vect_data_t = typename has_vect_data<T, N, V>::type;

template <typename T, int N, bool V>
struct data;

template <typename T, int N, bool V>
using data_t = typename data<T, N, V>::type;

template <typename T, int N, bool V>
struct data_param;

template <typename T, int N, bool V>
using data_param_t = typename data_param<T, N, V>::type;

} // namespace eagine::vect

#endif // EAGINE_VECT_FWD_HPP
