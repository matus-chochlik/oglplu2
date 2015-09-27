//  File include/oglplus/enum_types.hpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
#ifndef OGLPLUS_ENUM_TYPES_HPP
#define OGLPLUS_ENUM_TYPES_HPP

#include "utils/enum_class.hpp"

namespace oglplus {

struct shader_type
 : enum_class<shader_type, GLenum>
{ using enum_class<shader_type, GLenum>::enum_class; };

struct texture_filter
 : enum_class<texture_filter, GLenum>
{ using enum_class<texture_filter, GLenum>::enum_class; };

struct texture_mag_filter
 : enum_class<texture_mag_filter, GLenum>
{ using enum_class<texture_mag_filter, GLenum>::enum_class; };

struct texture_min_filter
 : enum_class<texture_min_filter, GLenum>
{ using enum_class<texture_min_filter, GLenum>::enum_class; };

} // namespace oglplus

#endif // include guard
