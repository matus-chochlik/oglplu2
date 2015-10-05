/**
 *  @file oglplus/enum_value_names.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_ENUM_VALUE_NAMES_1509260923_HPP
#define OGLPLUS_ENUM_VALUE_NAMES_1509260923_HPP

#include "utils/enum_class.hpp"
#include "utils/string_view.hpp"

namespace oglplus {

cstring_view<>
get_enum_value_name(const any_enum_value&)
noexcept;

template <typename EnumClass, typename T, unsigned EnumId>
static inline
cstring_view<>
enum_value_name(enum_class<EnumClass, T, EnumId> val)
noexcept
{
	return ::oglplus::get_enum_value_name(val);
}

} // namespace oglplus

#include <oglplus/enum_value_names.inl>

#endif // include guard
