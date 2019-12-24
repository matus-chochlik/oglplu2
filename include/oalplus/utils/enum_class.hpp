/**
 *  @file oalplus/utils/enum_class.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OALPLUS_UTILS_ENUM_CLASS_HPP
#define OALPLUS_UTILS_ENUM_CLASS_HPP

#include "../al.hpp"
#include <eagine/enum_bitfield.hpp>
#include <eagine/enum_class.hpp>

namespace oalplus {

using eagine::enum_bitfield;
using eagine::enum_value;
using eagine::is_enum_class;

// AL
template <typename Self, typename T, eagine::identifier_t Id>
using enum_class = eagine::enum_class<Self, T, 200, Id>;

using any_enum_class = eagine::any_enum_class<200>;
using any_enum_value = eagine::any_enum_value<200>;

static constexpr inline bool same_enum_class(
  any_enum_class a, any_enum_class b) noexcept {
    return ::eagine::same_enum_class(a, b);
}

// ALC
template <typename Self, typename T, eagine::identifier_t Id>
using enum_class_alc = eagine::enum_class<Self, T, 201, Id>;

using any_enum_class_alc = eagine::any_enum_class<201>;
using any_enum_value_alc = eagine::any_enum_value<201>;

static constexpr inline bool same_enum_class(
  any_enum_class_alc a, any_enum_class_alc b) noexcept {
    return ::eagine::same_enum_class(a, b);
}

// ALUT
template <typename Self, typename T, eagine::identifier_t Id>
using enum_class_alut = eagine::enum_class<Self, T, 202, Id>;

using any_enum_class_alut = eagine::any_enum_class<202>;
using any_enum_value_alut = eagine::any_enum_value<202>;

static constexpr inline bool same_enum_class(
  any_enum_class_alut a, any_enum_class_alut b) noexcept {
    return ::eagine::same_enum_class(a, b);
}

} // namespace oalplus

#endif // OALPLUS_UTILS_ENUM_CLASS_HPP
