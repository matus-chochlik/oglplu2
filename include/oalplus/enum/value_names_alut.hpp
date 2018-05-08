/**
 *  @file oalplus/enum_value_names_alut.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ENUM_VALUE_NAMES_ALUT_1509260923_HPP
#define OALPLUS_ENUM_VALUE_NAMES_ALUT_1509260923_HPP

#include "value_names.hpp"

namespace oalplus {

cstr_ref
get_enum_value_name(const any_enum_value_alut&) noexcept;

template <typename EnumClass, typename T, unsigned EnumId>
static inline cstr_ref
enum_value_name(enum_class_alut<EnumClass, T, EnumId> val) noexcept {
    return ::oalplus::get_enum_value_name(val);
}

} // namespace oalplus

#if !OALPLUS_LINK_LIBRARY || defined(OALPLUS_IMPLEMENTING_LIBRARY)
#include <oalplus/enum/value_names_alut.inl>
#endif

#endif // include guard
