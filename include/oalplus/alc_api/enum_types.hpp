/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OALPLUS_ALC_API_ENUM_TYPES_HPP
#define OALPLUS_ALC_API_ENUM_TYPES_HPP

#include "enum_class.hpp"

namespace eagine::oalp {
//------------------------------------------------------------------------------
struct alc_error_code : alc_enum_class<alc_error_code, EAGINE_ID_V(ErrorCode)> {
    using enum_class::enum_class;
};

struct context_attribute
  : alc_enum_class<context_attribute, EAGINE_ID_V(CntxtAttr)> {
    using enum_class::enum_class;
};

struct alc_string_query
  : alc_enum_class<alc_string_query, EAGINE_ID_V(StrQuery)> {
    using enum_class::enum_class;
};

struct alc_integer_query
  : alc_enum_class<alc_integer_query, EAGINE_ID_V(IntQuery)> {
    using enum_class::enum_class;
};
//------------------------------------------------------------------------------
} // namespace eagine::oalp

#endif // OALPLUS_ALC_API_ENUM_TYPES_HPP
