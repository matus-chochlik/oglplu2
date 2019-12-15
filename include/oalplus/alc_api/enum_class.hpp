/**
 *  @file oalplus/alc_api/enum_class.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ALC_API_ENUM_CLASS_HPP
#define OALPLUS_ALC_API_ENUM_CLASS_HPP

#include <eagine/enum_bitfield.hpp>
#include <eagine/enum_class.hpp>

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
template <typename Self, typename T, unsigned Id>
using alc_enum_class = enum_class<Self, T, 201, Id>;

using alc_any_enum_class = any_enum_class<201>;
using alc_any_enum_value = any_enum_value<201>;

static constexpr inline bool same_enum_class(
  alc_any_enum_class a, alc_any_enum_class b) noexcept {
    return ::eagine::same_enum_class(a, b);
}
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_ALC_API_ENUM_CLASS_HPP

