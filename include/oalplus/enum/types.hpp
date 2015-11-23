//  File include/oalplus/enum/types.hpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oalplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt
//
#ifndef OALPLUS_AL_ENUM_TYPES_HPP
#define OALPLUS_AL_ENUM_TYPES_HPP

#include "../utils/enum_class.hpp"

namespace oalplus {

struct al_error_code
 : enum_class<al_error_code, ALenum, 0>
{ using enum_class::enum_class; };

struct data_format
 : enum_class<data_format, ALenum, 1>
{ using enum_class::enum_class; };

struct distance_model
 : enum_class<distance_model, ALenum, 2>
{ using enum_class::enum_class; };

struct source_state
 : enum_class<source_state, ALenum, 3>
{ using enum_class::enum_class; };

struct source_type
 : enum_class<source_type, ALenum, 4>
{ using enum_class::enum_class; };

struct string_query
 : enum_class<string_query, ALenum, 5>
{ using enum_class::enum_class; };

} // namespace oalplus

#endif // include guard
