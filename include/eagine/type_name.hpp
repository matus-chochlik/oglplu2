/**
 *  @file eagine/type_name.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_TYPE_NAME_1509260923_HPP
#define EAGINE_TYPE_NAME_1509260923_HPP

#include "config/basic.hpp"

#include <string>
#include <typeinfo>

namespace eagine {

std::string demangle_type_name(const char*)
noexcept;

template <typename T>
static inline
std::string type_name(const T&)
noexcept
{
	return demangle_type_name(typeid(T).name());
}

template <typename T>
static inline
std::string type_name(void)
noexcept
{
	return demangle_type_name(typeid(T).name());
}

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/type_name.inl>
#endif

#endif // include guard
