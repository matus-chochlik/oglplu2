/**
 *  @file eagine/unit/base_dim.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_BASE_DIM_HPP
#define EAGINE_UNITS_BASE_DIM_HPP

#include "fwd.hpp"
#include <utility>

namespace eagine::units {
namespace base {

// dimension
template <typename Derived>
struct dimension {
    using type = Derived;
};

struct angle : dimension<angle> {};
struct solid_angle : dimension<solid_angle> {};

struct length : dimension<length> {};
struct mass : dimension<mass> {};
struct time : dimension<time> {};

struct temperature : dimension<temperature> {};
struct electric_current : dimension<electric_current> {};
struct number_of_cycles : dimension<number_of_cycles> {};
struct number_of_decays : dimension<number_of_decays> {};
struct luminous_intensity : dimension<luminous_intensity> {};
struct amount_of_substance : dimension<amount_of_substance> {};
struct amount_of_information : dimension<amount_of_information> {};

template <typename Func>
auto for_each_dim(Func func) -> Func {
    func(angle());
    func(solid_angle());
    func(length());
    func(mass());
    func(time());
    func(temperature());
    func(electric_current());
    func(number_of_cycles());
    func(number_of_decays());
    func(luminous_intensity());
    func(amount_of_substance());
    func(amount_of_information());

    return std::move(func);
}

// dim_num
template <typename Dimension>
struct dim_num;

template <typename Dim>
struct dim_num<dimension<Dim>> : dim_num<Dim> {};

template <typename Dimension>
const int dim_num_v = dim_num<Dimension>::value;

template <>
struct dim_num<nothing_t> : int_constant<0> {};

template <>
struct dim_num<angle> : int_constant<1> {};
template <>
struct dim_num<solid_angle> : int_constant<2> {};
template <>
struct dim_num<mass> : int_constant<3> {};
template <>
struct dim_num<length> : int_constant<4> {};
template <>
struct dim_num<time> : int_constant<5> {};

template <>
struct dim_num<temperature> : int_constant<6> {};
template <>
struct dim_num<electric_current> : int_constant<7> {};
template <>
struct dim_num<number_of_cycles> : int_constant<8> {};
template <>
struct dim_num<number_of_decays> : int_constant<9> {};
template <>
struct dim_num<luminous_intensity> : int_constant<10> {};
template <>
struct dim_num<amount_of_substance> : int_constant<11> {};
template <>
struct dim_num<amount_of_information> : int_constant<12> {};

// get_number
template <typename Derived>
static constexpr inline auto get_number(dimension<Derived>) noexcept -> int {
    return dim_num_v<Derived>;
}

} // namespace base

template <>
struct name_of<base::angle> {
    static constexpr const char mp_str[] = "angle";
};

template <>
struct name_of<base::solid_angle> {
    static constexpr const char mp_str[] = "solid angle";
};

template <>
struct name_of<base::mass> {
    static constexpr const char mp_str[] = "mass";
};

template <>
struct name_of<base::length> {
    static constexpr const char mp_str[] = "length";
};

template <>
struct name_of<base::time> {
    static constexpr const char mp_str[] = "time";
};

template <>
struct name_of<base::temperature> {
    static constexpr const char mp_str[] = "temperature";
};

template <>
struct name_of<base::electric_current> {
    static constexpr const char mp_str[] = "electric current";
};

template <>
struct name_of<base::number_of_cycles> {
    static constexpr const char mp_str[] = "number of cycles";
};

template <>
struct name_of<base::number_of_decays> {
    static constexpr const char mp_str[] = "number of decays";
};

template <>
struct name_of<base::luminous_intensity> {
    static constexpr const char mp_str[] = "luminous intensity";
};

template <>
struct name_of<base::amount_of_substance> {
    static constexpr const char mp_str[] = "amount of substance";
};

template <>
struct name_of<base::amount_of_information> {
    static constexpr const char mp_str[] = "amount of information";
};

} // namespace eagine::units

#endif // EAGINE_UNITS_BASE_DIM_HPP
