/**
 *  @file oalplus/alut_api/config.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ALUT_API_CONFIG_HPP
#define OALPLUS_ALUT_API_CONFIG_HPP

#include "../al_api/config.hpp"
#include "../config/basic.hpp"

#ifndef OALPLUS_HAS_ALUT
#if defined(ALUT_ERROR_NO_ERROR)
#define OALPLUS_HAS_ALUT 1
#else
#define OALPLUS_HAS_ALUT 0
#endif
#endif // OALPLUS_HAS_ALUT

#if !OALPLUS_HAS_ALUT
#include <cstdint>
#endif

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
struct alut_types {

    using int_type = al_types::int_type;
    using bool_type = al_types::bool_type;
    using char_type = al_types::char_type;
    using enum_type = al_types::enum_type;
    using uint_type = al_types::uint_type;
    using name_type = al_types::name_type;
    using size_type = al_types::size_type;
    using float_type = al_types::float_type;
    using void_ptr_type = al_types::void_ptr_type;
    using const_void_ptr_type = al_types::const_void_ptr_type;
#if OALPLUS_HAS_ALUT
    static constexpr bool has_api = true;
#else
    static constexpr bool has_api = false;
#endif
};
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_ALUT_API_CONFIG_HPP

