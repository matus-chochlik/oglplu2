/**
 *  @file oalplus/al_api/enum_types.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_AL_API_ENUM_TYPES_HPP
#define OALPLUS_AL_API_ENUM_TYPES_HPP

#include "enum_class.hpp"

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
struct al_error_code : al_enum_class<al_error_code, EAGINE_ID_V(ErrorCode)> {
    using enum_class::enum_class;
};

struct al_capability : al_enum_class<al_capability, EAGINE_ID_V(Capability)> {
    using enum_class::enum_class;
};

struct al_boolean_query
  : al_enum_class<al_boolean_query, EAGINE_ID_V(BoolQuery)> {
    using enum_class::enum_class;
};

struct al_integer_query
  : al_enum_class<al_integer_query, EAGINE_ID_V(IntQuery)> {
    using enum_class::enum_class;
};

struct al_numeric_query
  : al_enum_class<al_numeric_query, EAGINE_ID_V(NumQuery)> {
    using enum_class::enum_class;
};

struct al_string_query : al_enum_class<al_string_query, EAGINE_ID_V(StrQuery)> {
    using enum_class::enum_class;
};

struct distance_model : al_enum_class<distance_model, EAGINE_ID_V(DistModel)> {
    using enum_class::enum_class;
};

struct listener_attribute
  : al_enum_class<listener_attribute, EAGINE_ID_V(ListenAttr)> {
    using enum_class::enum_class;
};

struct buffer_attribute
  : al_enum_class<buffer_attribute, EAGINE_ID_V(BufferAttr)> {
    using enum_class::enum_class;
};

struct buffer_format : al_enum_class<buffer_format, EAGINE_ID_V(BufferFrmt)> {
    using enum_class::enum_class;
};

struct source_attribute
  : al_enum_class<source_attribute, EAGINE_ID_V(SourceAttr)> {
    using enum_class::enum_class;
};

struct source_state : al_enum_class<source_state, EAGINE_ID_V(SourceStte)> {
    using enum_class::enum_class;
};

struct source_type : al_enum_class<source_type, EAGINE_ID_V(SourceType)> {
    using enum_class::enum_class;
};
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_AL_API_ENUM_TYPES_HPP

