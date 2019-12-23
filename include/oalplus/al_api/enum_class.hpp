/**
 *  @file oalplus/al_api/enum_class.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_AL_API_ENUM_CLASS_HPP
#define OALPLUS_AL_API_ENUM_CLASS_HPP

#include <eagine/enum_bitfield.hpp>
#include <eagine/enum_class.hpp>

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
template <typename Self, typename T, unsigned Id>
using al_enum_class = enum_class<Self, T, 200, Id>;

using al_any_enum_class = any_enum_class<200>;
using al_any_enum_value = any_enum_value<200>;

static constexpr inline bool same_enum_class(
  al_any_enum_class a, al_any_enum_class b) noexcept {
    return ::eagine::same_enum_class(a, b);
}
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_AL_API_ENUM_CLASS_HPP
