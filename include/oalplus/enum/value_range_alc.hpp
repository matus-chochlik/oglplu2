/**
 *  @file oalplus/enum_value_range_alc.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ENUM_VALUE_RANGE_ALC_HPP
#define OALPLUS_ENUM_VALUE_RANGE_ALC_HPP

#include "value_range.hpp"

namespace oalplus {

std::pair<const void*, span_size_t> get_enum_value_range(
  const any_enum_class_alc&) noexcept;

} // namespace oalplus

#if !OALPLUS_LINK_LIBRARY || defined(OALPLUS_IMPLEMENTING_LIBRARY)
#include <oalplus/enum/value_range_alc.inl>
#endif

#endif // OALPLUS_ENUM_VALUE_RANGE_ALC_HPP
