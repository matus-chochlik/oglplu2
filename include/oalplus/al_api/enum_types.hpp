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

#include "config.hpp"
#include "enum_class.hpp"

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
struct al_error_code : al_enum_class<al_error_code, al_types::enum_type, 0> {
    using enum_class::enum_class;
};

struct al_boolean_query
  : al_enum_class<al_boolean_query, al_types::enum_type, 1> {
    using enum_class::enum_class;
};

struct al_integer_query
  : al_enum_class<al_integer_query, al_types::enum_type, 2> {
    using enum_class::enum_class;
};

struct al_numeric_query
  : al_enum_class<al_numeric_query, al_types::enum_type, 3> {
    using enum_class::enum_class;
};

struct al_string_query
  : al_enum_class<al_string_query, al_types::enum_type, 4> {
    using enum_class::enum_class;
};

struct distance_model : al_enum_class<distance_model, al_types::enum_type, 5> {
    using enum_class::enum_class;
};

struct listener_attribute
  : al_enum_class<listener_attribute, al_types::enum_type, 6> {
    using enum_class::enum_class;
};

struct buffer_attribute
  : al_enum_class<buffer_attribute, al_types::enum_type, 7> {
    using enum_class::enum_class;
};

struct buffer_format : al_enum_class<buffer_format, al_types::enum_type, 8> {
    using enum_class::enum_class;
};

struct source_attribute
  : al_enum_class<source_attribute, al_types::enum_type, 9> {
    using enum_class::enum_class;
};

struct source_state : al_enum_class<source_state, al_types::enum_type, 10> {
    using enum_class::enum_class;
};
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_AL_API_ENUM_TYPES_HPP

