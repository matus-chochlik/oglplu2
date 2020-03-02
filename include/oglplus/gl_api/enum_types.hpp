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

struct context_flag_bit
  : gl_bitfield_class<context_flag_bit, EAGINE_ID_V(CtxFlagBit)> {
    using enum_class::enum_class;
};

struct context_profile_bit
  : gl_bitfield_class<context_profile_bit, EAGINE_ID_V(CtxProfBit)> {
    using enum_class::enum_class;
};

struct context_release_behavior
  : gl_enum_class<context_release_behavior, EAGINE_ID_V(CtxRlsBhvr)> {
    using enum_class::enum_class;
};

struct capability : gl_enum_class<capability, EAGINE_ID_V(Capability)> {
    using enum_class::enum_class;
};

struct client_capability
  : gl_enum_class<client_capability, EAGINE_ID_V(ClientCap)> {
    using enum_class::enum_class;
};

struct graphics_reset_status
  : gl_enum_class<graphics_reset_status, EAGINE_ID_V(GrphRstStt)> {
    using enum_class::enum_class;
};

struct memory_barrier_bit
  : gl_bitfield_class<memory_barrier_bit, EAGINE_ID_V(MemBrirBit)> {
    using enum_class::enum_class;
};

struct access_specifier
  : gl_enum_class<access_specifier, EAGINE_ID_V(AccessSpec)> {
    using enum_class::enum_class;
};

struct object_type : gl_enum_class<object_type, EAGINE_ID_V(ObjectType)> {
    using enum_class::enum_class;
};

struct shader_type : gl_enum_class<shader_type, EAGINE_ID_V(ShaderType)> {
    using enum_class::enum_class;
};

struct shader_parameter
  : gl_enum_class<shader_parameter, EAGINE_ID_V(ShdrPrmter)> {
    using enum_class::enum_class;
};

struct program_parameter
  : gl_enum_class<program_parameter, EAGINE_ID_V(ProgPrmter)> {
    using enum_class::enum_class;
};

struct program_pipeline_parameter
  : gl_enum_class<program_pipeline_parameter, EAGINE_ID_V(PiplPrmter)> {
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
  : gl_bitfield_class<buffer_map_access_bit, EAGINE_ID_V(BufMapAccB)> {
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
  : gl_bitfield_class<buffer_clear_bit, EAGINE_ID_V(BuffClrBit)> {
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

struct sampler_parameter
  : gl_enum_class<sampler_parameter, EAGINE_ID_V(SamParamtr)> {
    using enum_class::enum_class;
};

struct primitive_type : gl_enum_class<primitive_type, EAGINE_ID_V(PrmtveType)> {
    using enum_class::enum_class;
};

struct tess_gen_primitive_type
  : gl_enum_class<tess_gen_primitive_type, EAGINE_ID_V(TsGnPrmTyp)> {
    using enum_class::enum_class;
};

struct tess_gen_primitive_spacing
  : gl_enum_class<tess_gen_primitive_spacing, EAGINE_ID_V(TsGnPrmSpc)> {
    using enum_class::enum_class;
};

struct provoke_mode : gl_enum_class<provoke_mode, EAGINE_ID_V(ProvkeMode)> {
    using enum_class::enum_class;
};

struct conditional_render_mode
  : gl_enum_class<conditional_render_mode, EAGINE_ID_V(CndRndrMod)> {
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

struct polygon_mode : gl_enum_class<polygon_mode, EAGINE_ID_V(PolygnMode)> {
    using enum_class::enum_class;
};

struct stencil_operation
  : gl_enum_class<stencil_operation, EAGINE_ID_V(StencilOp)> {
    using enum_class::enum_class;
};

struct logic_operation : gl_enum_class<logic_operation, EAGINE_ID_V(LogicOp)> {
    using enum_class::enum_class;
};

struct blend_equation : gl_enum_class<blend_equation, EAGINE_ID_V(BlendEqtn)> {
    using enum_class::enum_class;
};

struct blend_equation_advanced
  : gl_enum_class<blend_equation_advanced, EAGINE_ID_V(BlndEqAdvn)> {
    using enum_class::enum_class;
};

struct blend_function : gl_enum_class<blend_function, EAGINE_ID_V(BlendFunc)> {
    using enum_class::enum_class;
};

struct pixel_data_type
  : gl_enum_class<pixel_data_type, EAGINE_ID_V(PixDataTyp)> {
    using enum_class::enum_class;
};

struct pixel_format : gl_enum_class<pixel_format, EAGINE_ID_V(PixelFrmat)> {
    using enum_class::enum_class;
};

struct pixel_internal_format
  : gl_enum_class<pixel_internal_format, EAGINE_ID_V(PixIntlFmt)> {
    using enum_class::enum_class;
};

struct pixel_store_parameter
  : gl_enum_class<pixel_store_parameter, EAGINE_ID_V(PixStorPrm)> {
    using enum_class::enum_class;
};

struct internal_format_parameter
  : gl_enum_class<internal_format_parameter, EAGINE_ID_V(IntlFmtPrm)> {
    using enum_class::enum_class;
};

struct view_compatibility_class
  : gl_enum_class<view_compatibility_class, EAGINE_ID_V(VwCompClss)> {
    using enum_class::enum_class;
};

struct debug_output_severity
  : gl_enum_class<debug_output_severity, EAGINE_ID_V(DbgOutSvrt)> {
    using enum_class::enum_class;
};

struct debug_output_source
  : gl_enum_class<debug_output_source, EAGINE_ID_V(DbgOutSrce)> {
    using enum_class::enum_class;
};

struct debug_output_type
  : gl_enum_class<debug_output_type, EAGINE_ID_V(DbgOutType)> {
    using enum_class::enum_class;
};

struct support_level : gl_enum_class<support_level, EAGINE_ID_V(SupportLvl)> {
    using enum_class::enum_class;
};
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine

#endif // OGLPLUS_GL_API_ENUM_TYPES_HPP

