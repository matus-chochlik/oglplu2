/**
 *  @file eagine/unit/traits.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_TRAITS_1512222148_HPP
#define EAGINE_UNITS_TRAITS_1512222148_HPP

#include "fwd.hpp"

namespace eagine {
namespace units {

// is_dimension
template <typename X>
struct is_dimension
 : std::false_type
{ };

template <typename X>
constexpr bool is_dimension_v = is_dimension<X>::value;

template <typename H, typename T>
struct is_dimension<bits::dims<H, T>>
 : std::true_type
{ };

// is_unit
template <typename X>
struct is_unit
 : std::false_type
{ };

template <typename D, typename S>
struct is_unit<unit<D, S>>
 : std::true_type
{ };

template <typename D, typename US, typename S>
struct is_unit<scaled_unit<D, US, S>>
 : std::true_type
{ };

// same_dimension
template <typename X, typename Y>
struct same_dimension
 : std::false_type
{ };

template <typename X, typename Y>
constexpr bool same_dimension_v = same_dimension<X, Y>::value;

template <typename D, typename S>
struct same_dimension<unit<D, S>, unit<D, S>>
 : std::true_type
{ };

template <typename D, typename US, typename S>
struct same_dimension<unit<D, S>, scaled_unit<D, US, S>>
 : std::true_type
{ };

template <typename D, typename US, typename S>
struct same_dimension<scaled_unit<D, US, S>, unit<D, S>>
 : std::true_type
{ };

template <typename D, typename US1, typename US2, typename S>
struct same_dimension<scaled_unit<D, US1, S>, scaled_unit<D, US2, S>>
 : std::true_type
{ };

} // namespace units
} // namespace eagine

#endif //include guard

