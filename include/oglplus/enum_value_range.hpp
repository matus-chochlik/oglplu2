/**
 *  @file oglplus/enum_value_range.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_ENUM_VALUE_RANGE_1509260923_HPP
#define OGLPLUS_ENUM_VALUE_RANGE_1509260923_HPP

#include "utils/enum_class.hpp"
#include "utils/array_view.hpp"

namespace oglplus {

std::pair<const void*, std::size_t>
get_enum_value_range(const any_enum_class&)
noexcept;

template <typename EnumClass, typename T, unsigned EnumId>
static inline
array_view<const T>
enum_value_range(enum_class<EnumClass, T, EnumId> cls)
noexcept
{
	auto p = ::oglplus::get_enum_value_range(cls);
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

} // namespace oglplus

#include <oglplus/enum_value_range.inl>

#endif // include guard
