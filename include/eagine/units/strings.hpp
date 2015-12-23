/**
 *  @file eagine/unit/strings.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNIT_STRINGS_1308281038_HPP
#define EAGINE_UNIT_STRINGS_1308281038_HPP

#include "fwd.hpp"
#include "detail.hpp"
#include "../mp_string.hpp"
#include <string>

namespace eagine {
namespace units {
namespace base {

template <typename Derived>
static inline
const char* get_dim_name(dimension<Derived>)
noexcept
{
	return mp_make_string<dim_name<Derived>>::value;
}

} // namespace base

namespace scales {

template <typename Scale>
static inline
const char* get_scale_name(Scale)
noexcept
{
	return mp_make_string<scale_name<Scale>>::value;
}

template <typename Scale>
static inline
const char* get_scale_symbol(Scale)
noexcept
{
	return mp_make_string<scale_symbol<Scale>>::value;
}

} // namespace scales

template <typename H, typename T>
static inline
const char* get_dim_name(bits::dims<H, T>)
noexcept
{
	return mp_make_string<dim_name<bits::dims<H, T>>>::value;
}

static inline
std::string get_dim_pows(nothing_t)
{
	return std::string();
}

static inline
std::string get_dim_pows(bits::dimless)
{
	return std::string();
}

template <typename Dim, typename Pow, typename T>
static inline
std::string get_dim_pows(bits::dims<bits::dim_pow<Dim, Pow>, T>)
{
	return std::string(get_dim_name(Dim()))+"^"+std::to_string(Pow::value)+
		get_dim_pows(T());
}

} // namespace units
} // namespace eagine

#endif //include guard

