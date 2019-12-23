/**
 *  @file oalplus/alut_api/enum_class.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ALUT_API_ENUM_CLASS_HPP
#define OALPLUS_ALUT_API_ENUM_CLASS_HPP

#include <eagine/enum_bitfield.hpp>
#include <eagine/enum_class.hpp>

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
template <typename Self, typename T, unsigned Id>
using alut_enum_class = enum_class<Self, T, 202, Id>;

using alut_any_enum_class = any_enum_class<202>;
using alut_any_enum_value = any_enum_value<202>;

static constexpr inline bool same_enum_class(
  alut_any_enum_class a, alut_any_enum_class b) noexcept {
    return ::eagine::same_enum_class(a, b);
}
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_ALUT_API_ENUM_CLASS_HPP
