/**
 *  @file oalplus/enum_value_range.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ENUM_VALUE_RANGE_1509260923_HPP
#define OALPLUS_ENUM_VALUE_RANGE_1509260923_HPP

#include "../config/basic.hpp"
#include "../utils/enum_class.hpp"
#include "../utils/span.hpp"
#include <eagine/enum_range.hpp>

namespace oalplus {

std::pair<const void*, span_size_t>
get_enum_value_range(const any_enum_class&) noexcept;

using eagine::enumerated_value_range;

template <typename EnumClass,
  typename = std::enable_if_t<is_enum_class<typename EnumClass::type>::value>>
static inline enumerated_value_range<typename EnumClass::type>
enum_value_range(void) noexcept {
    return enumerated_value_range<typename EnumClass::type>(
      get_enum_value_range(typename EnumClass::type()));
}

} // namespace oalplus

#if !OALPLUS_LINK_LIBRARY || defined(OALPLUS_IMPLEMENTING_LIBRARY)
#include <oalplus/enum/value_range.inl>
#endif

#endif // include guard
