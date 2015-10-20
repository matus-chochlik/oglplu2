/**
 *  @file eglplus/enum_value_range.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EGLPLUS_ENUM_VALUE_RANGE_1509260923_HPP
#define EGLPLUS_ENUM_VALUE_RANGE_1509260923_HPP

#include "utils/enum_class.hpp"
#include "utils/array_view.hpp"
#include "config/basic.hpp"

namespace eglplus {

std::pair<const void*, std::size_t>
get_enum_value_range(const any_enum_class&)
noexcept;

template <typename EnumClass, typename T, unsigned EnumId>
static inline
array_view<const T>
enum_value_range(enum_class<EnumClass, T, EnumId> cls)
noexcept
{
	auto p = ::eglplus::get_enum_value_range(cls);
	return {static_cast<const T*>(p.first), p.second};
}

template <typename EnumClass>
static inline
array_view<const typename EnumClass::value_type>
enum_value_range(void)
noexcept
{
	return enum_value_range(EnumClass());
}

} // namespace eglplus

#if !EGLPLUS_LINK_LIBRARY || defined(EGLPLUS_IMPLEMENTING_LIBRARY)
#include <eglplus/enum_value_range.inl>
#endif

#endif // include guard
