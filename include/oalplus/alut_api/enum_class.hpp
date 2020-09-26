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

#include "config.hpp"
#include <eagine/enum_bitfield.hpp>
#include <eagine/enum_class.hpp>
#include <eagine/identifier.hpp>

namespace eagine::oalp {
//------------------------------------------------------------------------------
template <typename Self, identifier_t Id>
using alut_enum_class =
  enum_class<Self, alut_types::enum_type, EAGINE_ID_V(ALUT), Id>;

using alut_any_enum_class = any_enum_class<EAGINE_ID_V(ALUT)>;
using alut_any_enum_value = any_enum_value<EAGINE_ID_V(ALUT)>;

static constexpr inline auto
same_enum_class(alut_any_enum_class a, alut_any_enum_class b) noexcept -> bool {
    return ::eagine::same_enum_class(a, b);
}
//------------------------------------------------------------------------------
} // namespace eagine::oalp

#endif // OALPLUS_ALUT_API_ENUM_CLASS_HPP
