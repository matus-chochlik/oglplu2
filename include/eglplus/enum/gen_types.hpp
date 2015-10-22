//  File include/eglplus/enum/gen_types.hpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/eglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt
//
#ifndef EGLPLUS_EGL_GEN_ENUM_TYPES_HPP
#define EGLPLUS_EGL_GEN_ENUM_TYPES_HPP

#include "../utils/enum_class.hpp"

namespace eglplus {

struct color_buffer_type
 : enum_class<color_buffer_type, EGLenum, 0>
{ using enum_class::enum_class; };

struct config_attrib
 : enum_class<config_attrib, EGLenum, 1>
{ using enum_class::enum_class; };

struct config_caveat
 : enum_class<config_caveat, EGLenum, 2>
{ using enum_class::enum_class; };

struct context_attrib
 : enum_class<context_attrib, EGLenum, 3>
{ using enum_class::enum_class; };

struct context_flag
 : enum_class<context_flag, EGLenum, 4>
{ using enum_class::enum_class; };

struct error_code
 : enum_class<error_code, EGLenum, 5>
{ using enum_class::enum_class; };

struct gl_colorspace
 : enum_class<gl_colorspace, EGLenum, 6>
{ using enum_class::enum_class; };

struct multisample_resolve
 : enum_class<multisample_resolve, EGLenum, 7>
{ using enum_class::enum_class; };

struct opengl_profile_bit
 : enum_class<opengl_profile_bit, EGLenum, 8>
{ using enum_class::enum_class; };

struct opengl_rns
 : enum_class<opengl_rns, EGLenum, 9>
{ using enum_class::enum_class; };

struct render_buffer
 : enum_class<render_buffer, EGLenum, 10>
{ using enum_class::enum_class; };

struct renderable_type_bit
 : enum_class<renderable_type_bit, EGLenum, 11>
{ using enum_class::enum_class; };

struct rendering_api
 : enum_class<rendering_api, EGLenum, 12>
{ using enum_class::enum_class; };

struct string_query
 : enum_class<string_query, EGLenum, 13>
{ using enum_class::enum_class; };

struct surface_attrib
 : enum_class<surface_attrib, EGLenum, 14>
{ using enum_class::enum_class; };

struct surface_type_bit
 : enum_class<surface_type_bit, EGLenum, 15>
{ using enum_class::enum_class; };

struct swap_behavior
 : enum_class<swap_behavior, EGLenum, 16>
{ using enum_class::enum_class; };

struct texture_format
 : enum_class<texture_format, EGLenum, 17>
{ using enum_class::enum_class; };

struct texture_target
 : enum_class<texture_target, EGLenum, 18>
{ using enum_class::enum_class; };

struct transparent_type
 : enum_class<transparent_type, EGLenum, 19>
{ using enum_class::enum_class; };

struct vg_alpha_format
 : enum_class<vg_alpha_format, EGLenum, 20>
{ using enum_class::enum_class; };

struct vg_colorspace
 : enum_class<vg_colorspace, EGLenum, 21>
{ using enum_class::enum_class; };

} // namespace eglplus

#endif // include guard
