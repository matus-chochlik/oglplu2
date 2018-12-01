/**
 *  @file oglplus/enum/value_names.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_ENUM_VALUE_NAMES_1509260923_HPP
#define OGLPLUS_ENUM_VALUE_NAMES_1509260923_HPP

#include "../config/basic.hpp"
#include "../utils/cstr_ref.hpp"
#include "../utils/enum_class.hpp"

namespace oglplus {

cstr_ref get_enum_value_name(const any_enum_value&) noexcept;

template <typename EnumClass, typename T, unsigned EnumId>
static inline cstr_ref
enum_value_name(enum_class<EnumClass, T, EnumId> val) noexcept {
    return ::oglplus::get_enum_value_name(val);
}

} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/enum/value_names.inl>
#endif

#endif // include guard
