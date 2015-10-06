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

array_view<const long>
get_enum_value_range(const any_enum_class&)
noexcept;

template <typename EnumClass, typename T, unsigned EnumId>
static inline
array_view<const long>
enum_value_range(enum_class<EnumClass, T, EnumId> cls)
noexcept
{
	return ::oglplus::get_enum_value_range(cls);
}

} // namespace oglplus

#include <oglplus/enum_value_range.inl>

#endif // include guard
