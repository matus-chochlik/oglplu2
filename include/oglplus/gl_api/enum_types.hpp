/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OGLPLUS_GL_API_ENUM_TYPES_HPP
#define OGLPLUS_GL_API_ENUM_TYPES_HPP

#include "enum_class.hpp"

namespace eagine::oglp {
//------------------------------------------------------------------------------
struct true_false : gl_bool_class<true_false, EAGINE_ID_V(TrueFalse)> {
    using enum_class::enum_class;

    constexpr explicit operator bool() const noexcept {
#ifdef GL_TRUE
        return this->_value == GL_TRUE;
#else
        return false;
#endif
    }
};

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

struct reset_notification_strategy
  : gl_enum_class<reset_notification_strategy, EAGINE_ID_V(RstNtfStgy)> {
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

struct precision_type : gl_enum_class<precision_type, EAGINE_ID_V(PrecisType)> {
    using enum_class::enum_class;
};

struct object_type : gl_enum_class<object_type, EAGINE_ID_V(ObjectType)> {
    using enum_class::enum_class;
};

struct sync_type : gl_enum_class<sync_type, EAGINE_ID_V(SyncType)> {
    using enum_class::enum_class;
};

struct sync_status : gl_enum_class<sync_status, EAGINE_ID_V(SyncStatus)> {
    using enum_class::enum_class;
};

struct sync_condition : gl_enum_class<sync_condition, EAGINE_ID_V(SyncCondtn)> {
    using enum_class::enum_class;
};

struct sync_flag_bit
  : gl_bitfield_class<sync_flag_bit, EAGINE_ID_V(SyncFlgBit)> {
    using enum_class::enum_class;
};

struct sync_parameter : gl_enum_class<sync_parameter, EAGINE_ID_V(SynParamtr)> {
    using enum_class::enum_class;
};

struct sync_wait_result
  : gl_enum_class<sync_wait_result, EAGINE_ID_V(SynWaitRes)> {
    using enum_class::enum_class;
};

struct shader_type : gl_enum_class<shader_type, EAGINE_ID_V(ShaderType)> {
    using enum_class::enum_class;
};

struct shader_parameter
  : gl_enum_class<shader_parameter, EAGINE_ID_V(ShdrPrmter)> {
    using enum_class::enum_class;
};

struct program_stage_bit
  : gl_bitfield_class<program_stage_bit, EAGINE_ID_V(PrgStgeBit)> {
    using enum_class::enum_class;
};

struct program_stage_parameter
  : gl_enum_class<program_stage_parameter, EAGINE_ID_V(PrgStgePrm)> {
    using enum_class::enum_class;
};

struct program_parameter
  : gl_enum_class<program_parameter, EAGINE_ID_V(ProgPrmter)> {
    using enum_class::enum_class;
};

struct program_binary_format
  : gl_enum_class<program_binary_format, EAGINE_ID_V(ProgBinFmt)> {
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

struct buffer_storage_bit
  : gl_bitfield_class<buffer_storage_bit, EAGINE_ID_V(BufStrgBit)> {
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
  : gl_bitfield_class<buffer_clear_bit, EAGINE_ID_V(BufClerBit)> {
    using enum_class::enum_class;
};

struct buffer_blit_bit
  : gl_bitfield_class<buffer_blit_bit, EAGINE_ID_V(BufBlitBit)> {
    using enum_class::enum_class;
};

struct texture_unit : gl_enum_class<texture_unit, EAGINE_ID_V(TexUnit)> {
    using enum_class::enum_class;
};

struct texture_target : gl_enum_class<texture_target, EAGINE_ID_V(TexTarget)> {
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

struct texture_level_parameter
  : gl_enum_class<texture_level_parameter, EAGINE_ID_V(TexLvlParm)> {
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

struct renderbuffer_target
  : gl_enum_class<renderbuffer_target, EAGINE_ID_V(RboTarget)> {
    using enum_class::enum_class;
};

struct renderbuffer_parameter
  : gl_enum_class<renderbuffer_parameter, EAGINE_ID_V(RboParamtr)> {
    using enum_class::enum_class;
};

struct framebuffer_target
  : gl_enum_class<framebuffer_target, EAGINE_ID_V(FboTarget)> {
    using enum_class::enum_class;
};

struct framebuffer_status
  : gl_enum_class<framebuffer_status, EAGINE_ID_V(FboStatus)> {
    using enum_class::enum_class;
};

struct framebuffer_parameter
  : gl_enum_class<framebuffer_parameter, EAGINE_ID_V(FboParamtr)> {
    using enum_class::enum_class;
};

struct framebuffer_attachment_parameter
  : gl_enum_class<framebuffer_attachment_parameter, EAGINE_ID_V(FboAtchPar)> {
    using enum_class::enum_class;
};

struct framebuffer_buffer
  : gl_enum_class<framebuffer_buffer, EAGINE_ID_V(FboBuffer)> {
    using enum_class::enum_class;
};

struct framebuffer_attachment
  : gl_enum_class<framebuffer_attachment, EAGINE_ID_V(FboAttchmt)> {
    using enum_class::enum_class;
};

struct sampler_parameter
  : gl_enum_class<sampler_parameter, EAGINE_ID_V(SamParamtr)> {
    using enum_class::enum_class;
};

struct query_target : gl_enum_class<query_target, EAGINE_ID_V(QryTarget)> {
    using enum_class::enum_class;
};

struct counter_query_target
  : gl_enum_class<counter_query_target, EAGINE_ID_V(CntrQryTgt)> {
    using enum_class::enum_class;
};

struct query_parameter
  : gl_enum_class<query_parameter, EAGINE_ID_V(QryParamtr)> {
    using enum_class::enum_class;
};

struct transform_feedback_target
  : gl_enum_class<transform_feedback_target, EAGINE_ID_V(XfbTarget)> {
    using enum_class::enum_class;
};

struct transform_feedback_primitive_type
  : gl_enum_class<transform_feedback_primitive_type, EAGINE_ID_V(XfbPrimTyp)> {
    using enum_class::enum_class;
};

struct transform_feedback_mode
  : gl_enum_class<transform_feedback_mode, EAGINE_ID_V(XfbMode)> {
    using enum_class::enum_class;
};

struct transform_feedback_parameter
  : gl_enum_class<transform_feedback_parameter, EAGINE_ID_V(XfbParamtr)> {
    using enum_class::enum_class;
};

struct vertex_attrib_parameter
  : gl_enum_class<vertex_attrib_parameter, EAGINE_ID_V(VAtrParmtr)> {
    using enum_class::enum_class;
};

struct primitive_type : gl_enum_class<primitive_type, EAGINE_ID_V(PrmtveType)> {
    using enum_class::enum_class;
};

struct old_primitive_type
  : gl_enum_class<old_primitive_type, EAGINE_ID_V(OldPrmType)> {
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

struct patch_parameter
  : gl_enum_class<patch_parameter, EAGINE_ID_V(PtchParmtr)> {
    using enum_class::enum_class;
};

struct provoke_mode : gl_enum_class<provoke_mode, EAGINE_ID_V(ProvkeMode)> {
    using enum_class::enum_class;
};

struct conditional_render_mode
  : gl_enum_class<conditional_render_mode, EAGINE_ID_V(CndRndrMod)> {
    using enum_class::enum_class;
};

struct face_mode : gl_enum_class<face_mode, EAGINE_ID_V(FaceMode)> {
    using enum_class::enum_class;
};

struct face_orientation
  : gl_enum_class<face_orientation, EAGINE_ID_V(FaceOrient)> {
    using enum_class::enum_class;
};

struct surface_buffer : gl_enum_class<surface_buffer, EAGINE_ID_V(SrfceBuffr)> {
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

struct float_query : gl_enum_class<float_query, EAGINE_ID_V(FloatQuery)> {
    using enum_class::enum_class;
};

struct string_query : gl_enum_class<string_query, EAGINE_ID_V(StrQuery)> {
    using enum_class::enum_class;
};

struct named_string_query
  : gl_enum_class<named_string_query, EAGINE_ID_V(NmdStrQury)> {
    using enum_class::enum_class;
};

struct data_type : gl_enum_class<data_type, EAGINE_ID_V(DataType)> {
    using enum_class::enum_class;
};

struct index_data_type
  : gl_enum_class<index_data_type, EAGINE_ID_V(IdxDtaType)> {
    using enum_class::enum_class;
};

struct sl_data_type : gl_enum_class<sl_data_type, EAGINE_ID_V(SLDataType)> {
    using enum_class::enum_class;
};

struct point_parameter
  : gl_enum_class<point_parameter, EAGINE_ID_V(PtParametr)> {
    using enum_class::enum_class;
};

struct point_sprite_coord_origin
  : gl_enum_class<point_sprite_coord_origin, EAGINE_ID_V(PtSprCrdOr)> {
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

struct image_unit_format
  : gl_enum_class<image_unit_format, EAGINE_ID_V(ImgUnitFmt)> {
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

struct image_compatibility_class
  : gl_enum_class<image_compatibility_class, EAGINE_ID_V(ImCompClss)> {
    using enum_class::enum_class;
};

struct view_compatibility_class
  : gl_enum_class<view_compatibility_class, EAGINE_ID_V(VwCompClss)> {
    using enum_class::enum_class;
};

struct hint_option : gl_enum_class<hint_option, EAGINE_ID_V(HintOption)> {
    using enum_class::enum_class;
};

struct sample_parameter
  : gl_enum_class<sample_parameter, EAGINE_ID_V(SampleParm)> {
    using enum_class::enum_class;
};

struct hint_target : gl_enum_class<hint_target, EAGINE_ID_V(HintTarget)> {
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

struct named_string_kind
  : gl_enum_class<named_string_kind, EAGINE_ID_V(NmdStrKind)> {
    using enum_class::enum_class;
};

struct matrix_mode : gl_enum_class<matrix_mode, EAGINE_ID_V(MatrixMode)> {
    using enum_class::enum_class;
};

struct path_command_nv
  : gl_ubyte_class<path_command_nv, EAGINE_ID_V(PathComand)> {
    using enum_class::enum_class;
};

struct path_cap_style_nv
  : gl_enum_class<path_cap_style_nv, EAGINE_ID_V(PathCapSty)> {
    using enum_class::enum_class;
};

struct path_color_format_nv
  : gl_enum_class<path_color_format_nv, EAGINE_ID_V(PathClrFmt)> {
    using enum_class::enum_class;
};

struct path_color_nv : gl_enum_class<path_color_nv, EAGINE_ID_V(PathColor)> {
    using enum_class::enum_class;
};

struct path_dash_offset_reset_nv
  : gl_enum_class<path_dash_offset_reset_nv, EAGINE_ID_V(PathDsORst)> {
    using enum_class::enum_class;
};

struct path_stroke_cover_mode_nv
  : gl_enum_class<path_stroke_cover_mode_nv, EAGINE_ID_V(PathStCvrM)> {
    using enum_class::enum_class;
};

struct path_fill_cover_mode_nv
  : gl_enum_class<path_fill_cover_mode_nv, EAGINE_ID_V(PathFlCvrM)> {
    using enum_class::enum_class;
};

struct path_fill_mode_nv
  : gl_enum_class<path_fill_mode_nv, EAGINE_ID_V(PathFillMd)> {
    using enum_class::enum_class;
};

struct path_font_style_nv
  : gl_bitfield_class<path_font_style_nv, EAGINE_ID_V(PathFntSty)> {
    using enum_class::enum_class;
};

struct path_join_style_nv
  : gl_bitfield_class<path_join_style_nv, EAGINE_ID_V(PathJinSty)> {
    using enum_class::enum_class;
};

struct path_font_target_nv
  : gl_enum_class<path_font_target_nv, EAGINE_ID_V(PathFntTgt)> {
    using enum_class::enum_class;
};

struct path_format_nv : gl_enum_class<path_format_nv, EAGINE_ID_V(PathFormat)> {
    using enum_class::enum_class;
};

struct path_gen_mode_nv
  : gl_enum_class<path_gen_mode_nv, EAGINE_ID_V(PathGenMod)> {
    using enum_class::enum_class;
};

struct path_list_mode_nv
  : gl_enum_class<path_list_mode_nv, EAGINE_ID_V(PathLstMod)> {
    using enum_class::enum_class;
};

struct path_metric_query_nv
  : gl_bitfield_class<path_metric_query_nv, EAGINE_ID_V(PathMrcQry)> {
    using enum_class::enum_class;
};

struct path_missing_glyph_nv
  : gl_bitfield_class<path_missing_glyph_nv, EAGINE_ID_V(PathMsnGph)> {
    using enum_class::enum_class;
};

struct path_parameter_nv
  : gl_bitfield_class<path_parameter_nv, EAGINE_ID_V(PathPrmter)> {
    using enum_class::enum_class;
};

struct path_text_encoding_nv
  : gl_bitfield_class<path_text_encoding_nv, EAGINE_ID_V(PathTxtEnc)> {
    using enum_class::enum_class;
};

struct path_transform_type_nv
  : gl_bitfield_class<path_transform_type_nv, EAGINE_ID_V(PathTrnsfT)> {
    using enum_class::enum_class;
};
//------------------------------------------------------------------------------
} // namespace eagine::oglp

#endif // OGLPLUS_GL_API_ENUM_TYPES_HPP
