/**
 *  @file oalplus/alc_api/enum_types.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ALC_API_ENUM_TYPES_HPP
#define OALPLUS_ALC_API_ENUM_TYPES_HPP

#include "api_types.hpp"
#include "enum_class.hpp"

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
struct alc_error_code
  : alc_enum_class<alc_error_code, api_types::enum_type, 0> {
    using enum_class::enum_class;
};

struct context_attrib
  : alc_enum_class<context_attrib, api_types::enum_type, 1> {
    using enum_class::enum_class;
};

struct alc_string_query
  : alc_enum_class<alc_string_query, api_types::enum_type, 2> {
    using enum_class::enum_class;
};
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_ALC_API_ENUM_TYPES_HPP

