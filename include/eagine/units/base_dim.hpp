/**
 *  @file eagine/unit/base_dim.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_BASE_DIM_1512222148_HPP
#define EAGINE_UNITS_BASE_DIM_1512222148_HPP

#include "../type_traits.hpp"
#include "scales.hpp"

namespace eagine {
namespace units {
namespace base {

// dimension
template <typename Derived>
struct dimension
{
	typedef Derived type;
};

struct angle       : dimension<angle> { };
struct solid_angle : dimension<solid_angle> { };

struct length : dimension<length> { };
struct mass   : dimension<mass> { };
struct time   : dimension<time> { };

struct temperature         : dimension<temperature> { };
struct electric_current    : dimension<electric_current> { };
struct number_of_cycles    : dimension<number_of_cycles> { };
struct number_of_decays    : dimension<number_of_decays> { };
struct luminous_intensity  : dimension<luminous_intensity> { };
struct amount_of_substance : dimension<amount_of_substance> { };

// dim_num
template <typename Dimension>
struct dim_num;

template <typename Dimension>
const int dim_num_v = dim_num<Dimension>::value;

template <> struct dim_num<angle>  : int_constant<0>{ };
template <> struct dim_num<mass>   : int_constant<1> { };
template <> struct dim_num<length> : int_constant<2> { };
template <> struct dim_num<time>   : int_constant<3> { };

template <> struct dim_num<temperature>         : int_constant<4>  { };
template <> struct dim_num<electric_current>    : int_constant<5>  { };
template <> struct dim_num<number_of_cycles>    : int_constant<6>  { };
template <> struct dim_num<number_of_decays>    : int_constant<7>  { };
template <> struct dim_num<luminous_intensity>  : int_constant<8>  { };
template <> struct dim_num<amount_of_substance> : int_constant<9>  { };
template <> struct dim_num<solid_angle>         : int_constant<10> { };

// get_number
template <typename Derived>
static constexpr inline
int get_number(dimension<Derived>)
noexcept
{
	return dim_num_v<Derived>;
}


template <typename Dimension>
struct dim_name;

template <>
struct dim_name<angle>
{
	static constexpr const char mp_str[] = "angle";
};

template <>
struct dim_name<solid_angle>
{
	static constexpr const char mp_str[] = "solid angle";
};

template <>
struct dim_name<mass>
{
	static constexpr const char mp_str[] = "mass";
};

template <>
struct dim_name<length>
{
	static constexpr const char mp_str[] = "length";
};

template <>
struct dim_name<time>
{
	static constexpr const char mp_str[] = "time";
};

template <>
struct dim_name<temperature>
{
	static constexpr const char mp_str[] = "temperature";
};

template <>
struct dim_name<electric_current>
{
	static constexpr const char mp_str[] = "electric current";
};

template <>
struct dim_name<number_of_cycles>
{
	static constexpr const char mp_str[] = "number of cycles";
};

template <>
struct dim_name<number_of_decays>
{
	static constexpr const char mp_str[] = "number of decays";
};

template <>
struct dim_name<luminous_intensity>
{
	static constexpr const char mp_str[] = "luminous intensity";
};

template <>
struct dim_name<amount_of_substance>
{
	static constexpr const char mp_str[] = "amount of substance";
};

} // namespace base
} // namespace units
} // namespace eagine

#endif //include guard

