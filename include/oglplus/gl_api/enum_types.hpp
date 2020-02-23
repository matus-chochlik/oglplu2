/**
 *  @file oglplus/gl_api/enum_types.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_GL_API_ENUM_TYPES_HPP
#define OGLPLUS_GL_API_ENUM_TYPES_HPP

#include "enum_class.hpp"

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
struct error_code : gl_enum_class<error_code, EAGINE_ID_V(ErrorCode)> {
    using enum_class::enum_class;
};

struct capability : gl_enum_class<capability, EAGINE_ID_V(Capability)> {
    using enum_class::enum_class;
};

struct graphics_reset_status
  : gl_enum_class<graphics_reset_status, EAGINE_ID_V(GrphRstStt)> {
    using enum_class::enum_class;
};

struct memory_barrier_bit
  : gl_enum_class<memory_barrier_bit, EAGINE_ID_V(MemBrirBit)> {
    using enum_class::enum_class;
};

struct access_specifier
  : gl_enum_class<access_specifier, EAGINE_ID_V(AccessSpec)> {
    using enum_class::enum_class;
};

struct shader_type : gl_enum_class<shader_type, EAGINE_ID_V(ShaderType)> {
    using enum_class::enum_class;
};

struct buffer_target : gl_enum_class<buffer_target, EAGINE_ID_V(BufferTgt)> {
    using enum_class::enum_class;
};

struct buffer_parameter
  : gl_enum_class<buffer_parameter, EAGINE_ID_V(BufParmtr)> {
    using enum_class::enum_class;
};

struct buffer_usage : gl_enum_class<buffer_usage, EAGINE_ID_V(BufferUsge)> {
    using enum_class::enum_class;
};

struct buffer_map_access_bit
  : gl_enum_class<buffer_map_access_bit, EAGINE_ID_V(BufMapAccB)> {
    using enum_class::enum_class;
};

struct texture_target : gl_enum_class<texture_target, EAGINE_ID_V(TextureTgt)> {
    using enum_class::enum_class;
};

struct program_interface
  : gl_enum_class<program_interface, EAGINE_ID_V(ProgrmIntf)> {
    using enum_class::enum_class;
};

struct program_property
  : gl_enum_class<program_property, EAGINE_ID_V(ProgrmProp)> {
    using enum_class::enum_class;
};

struct buffer_clear_bit
  : gl_enum_class<buffer_clear_bit, EAGINE_ID_V(BuffClrBit)> {
    using enum_class::enum_class;
};

struct texture_compare_mode
  : gl_enum_class<texture_compare_mode, EAGINE_ID_V(TexCmpMode)> {
    using enum_class::enum_class;
};

struct texture_min_filter
  : gl_enum_class<texture_min_filter, EAGINE_ID_V(TexMinFltr)> {
    using enum_class::enum_class;
};

struct texture_mag_filter
  : gl_enum_class<texture_mag_filter, EAGINE_ID_V(TexMagFltr)> {
    using enum_class::enum_class;
};

struct texture_filter : gl_enum_class<texture_filter, EAGINE_ID_V(TexFilter)> {
    using enum_class::enum_class;
};

struct texture_parameter
  : gl_enum_class<texture_parameter, EAGINE_ID_V(TexParamtr)> {
    using enum_class::enum_class;
};

struct texture_swizzle_coord
  : gl_enum_class<texture_swizzle_coord, EAGINE_ID_V(TexSwzCord)> {
    using enum_class::enum_class;
};

struct texture_swizzle_mode
  : gl_enum_class<texture_swizzle_mode, EAGINE_ID_V(TexSwzMode)> {
    using enum_class::enum_class;
};

struct texture_wrap_coord
  : gl_enum_class<texture_wrap_coord, EAGINE_ID_V(TexWrpCord)> {
    using enum_class::enum_class;
};

struct texture_wrap_mode
  : gl_enum_class<texture_wrap_mode, EAGINE_ID_V(TexWrpMode)> {
    using enum_class::enum_class;
};

struct color_buffer : gl_enum_class<color_buffer, EAGINE_ID_V(ColorBuffr)> {
    using enum_class::enum_class;
};

struct compare_function
  : gl_enum_class<compare_function, EAGINE_ID_V(ComparFunc)> {
    using enum_class::enum_class;
};

struct blit_filter : gl_enum_class<blit_filter, EAGINE_ID_V(BlitFilter)> {
    using enum_class::enum_class;
};

struct binding_query : gl_enum_class<binding_query, EAGINE_ID_V(BindQuery)> {
    using enum_class::enum_class;
};

struct integer_query : gl_enum_class<integer_query, EAGINE_ID_V(IntQuery)> {
    using enum_class::enum_class;
};

struct string_query : gl_enum_class<string_query, EAGINE_ID_V(StrQuery)> {
    using enum_class::enum_class;
};

struct sl_data_type : gl_enum_class<sl_data_type, EAGINE_ID_V(SLDataType)> {
    using enum_class::enum_class;
};
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine

#endif // OGLPLUS_GL_API_ENUM_TYPES_HPP

