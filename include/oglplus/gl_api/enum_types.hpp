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
/// @brief Wrapper for true, false GL enums.
/// @ingroup gl_api_wrap
struct true_false : gl_bool_class<true_false, EAGINE_ID_V(TrueFalse)> {
    using enum_class::enum_class;

    /// @brief Explicit conversion to native bool.
    constexpr explicit operator bool() const noexcept {
#ifdef GL_TRUE
        return this->_value == GL_TRUE;
#else
        return false;
#endif
    }
};

/// @brief Typed enumeration for GL error code constants.
/// @ingroup gl_api_wrap
struct error_code : gl_enum_class<error_code, EAGINE_ID_V(ErrorCode)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL context flag bit constants.
/// @ingroup gl_api_wrap
struct context_flag_bit
  : gl_bitfield_class<context_flag_bit, EAGINE_ID_V(CtxFlagBit)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL context profile bit constants.
/// @ingroup gl_api_wrap
struct context_profile_bit
  : gl_bitfield_class<context_profile_bit, EAGINE_ID_V(CtxProfBit)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL context release behavior constants.
/// @ingroup gl_api_wrap
struct context_release_behavior
  : gl_enum_class<context_release_behavior, EAGINE_ID_V(CtxRlsBhvr)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL context reset notification strategy constants.
/// @ingroup gl_api_wrap
struct reset_notification_strategy
  : gl_enum_class<reset_notification_strategy, EAGINE_ID_V(RstNtfStgy)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL capability constants.
/// @ingroup gl_api_wrap
struct capability : gl_enum_class<capability, EAGINE_ID_V(Capability)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL client capability constants.
/// @ingroup gl_api_wrap
struct client_capability
  : gl_enum_class<client_capability, EAGINE_ID_V(ClientCap)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL graphics reset status constants.
/// @ingroup gl_api_wrap
struct graphics_reset_status
  : gl_enum_class<graphics_reset_status, EAGINE_ID_V(GrphRstStt)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL memory barrier bit constants.
/// @ingroup gl_api_wrap
struct memory_barrier_bit
  : gl_bitfield_class<memory_barrier_bit, EAGINE_ID_V(MemBrirBit)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL access specifier constants.
/// @ingroup gl_api_wrap
struct access_specifier
  : gl_enum_class<access_specifier, EAGINE_ID_V(AccessSpec)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL precision type constants.
/// @ingroup gl_api_wrap
struct precision_type : gl_enum_class<precision_type, EAGINE_ID_V(PrecisType)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL object type constants.
/// @ingroup gl_api_wrap
struct object_type : gl_enum_class<object_type, EAGINE_ID_V(ObjectType)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL sync type constants.
/// @ingroup gl_api_wrap
struct sync_type : gl_enum_class<sync_type, EAGINE_ID_V(SyncType)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL sync status constants.
/// @ingroup gl_api_wrap
struct sync_status : gl_enum_class<sync_status, EAGINE_ID_V(SyncStatus)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL sync condition constants.
/// @ingroup gl_api_wrap
struct sync_condition : gl_enum_class<sync_condition, EAGINE_ID_V(SyncCondtn)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL sync flag bit constants.
/// @ingroup gl_api_wrap
struct sync_flag_bit
  : gl_bitfield_class<sync_flag_bit, EAGINE_ID_V(SyncFlgBit)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL sync parameter constants.
/// @ingroup gl_api_wrap
struct sync_parameter : gl_enum_class<sync_parameter, EAGINE_ID_V(SynParamtr)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL sync wait result constants.
/// @ingroup gl_api_wrap
struct sync_wait_result
  : gl_enum_class<sync_wait_result, EAGINE_ID_V(SynWaitRes)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL shader type constants.
/// @ingroup gl_api_wrap
struct shader_type : gl_enum_class<shader_type, EAGINE_ID_V(ShaderType)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL shader parameter constants.
/// @ingroup gl_api_wrap
struct shader_parameter
  : gl_enum_class<shader_parameter, EAGINE_ID_V(ShdrPrmter)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL program stage bit constants.
/// @ingroup gl_api_wrap
struct program_stage_bit
  : gl_bitfield_class<program_stage_bit, EAGINE_ID_V(PrgStgeBit)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL program stage parameter constants.
/// @ingroup gl_api_wrap
struct program_stage_parameter
  : gl_enum_class<program_stage_parameter, EAGINE_ID_V(PrgStgePrm)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL program parameter constants.
/// @ingroup gl_api_wrap
struct program_parameter
  : gl_enum_class<program_parameter, EAGINE_ID_V(ProgPrmter)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL program binary format constants.
/// @ingroup gl_api_wrap
struct program_binary_format
  : gl_enum_class<program_binary_format, EAGINE_ID_V(ProgBinFmt)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL program pipeline parameter constants.
/// @ingroup gl_api_wrap
struct program_pipeline_parameter
  : gl_enum_class<program_pipeline_parameter, EAGINE_ID_V(PiplPrmter)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL buffer bind target constants.
/// @ingroup gl_api_wrap
struct buffer_target : gl_enum_class<buffer_target, EAGINE_ID_V(BufferTgt)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL buffer parameter constants.
/// @ingroup gl_api_wrap
struct buffer_parameter
  : gl_enum_class<buffer_parameter, EAGINE_ID_V(BufParmtr)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL buffer usage constants.
/// @ingroup gl_api_wrap
struct buffer_usage : gl_enum_class<buffer_usage, EAGINE_ID_V(BufferUsge)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL buffer map access bit constants.
/// @ingroup gl_api_wrap
struct buffer_map_access_bit
  : gl_bitfield_class<buffer_map_access_bit, EAGINE_ID_V(BufMapAccB)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL buffer storage bit constants.
/// @ingroup gl_api_wrap
struct buffer_storage_bit
  : gl_bitfield_class<buffer_storage_bit, EAGINE_ID_V(BufStrgBit)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL program interface constants.
/// @ingroup gl_api_wrap
struct program_interface
  : gl_enum_class<program_interface, EAGINE_ID_V(ProgrmIntf)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL program property constants.
/// @ingroup gl_api_wrap
struct program_property
  : gl_enum_class<program_property, EAGINE_ID_V(ProgrmProp)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL buffer clear bit constants.
/// @ingroup gl_api_wrap
struct buffer_clear_bit
  : gl_bitfield_class<buffer_clear_bit, EAGINE_ID_V(BufClerBit)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL buffer blit bit constants.
/// @ingroup gl_api_wrap
struct buffer_blit_bit
  : gl_bitfield_class<buffer_blit_bit, EAGINE_ID_V(BufBlitBit)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL texture unit constants.
/// @ingroup gl_api_wrap
struct texture_unit : gl_enum_class<texture_unit, EAGINE_ID_V(TexUnit)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL texture bind target constants.
/// @ingroup gl_api_wrap
struct texture_target : gl_enum_class<texture_target, EAGINE_ID_V(TexTarget)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL texture compare mode constants.
/// @ingroup gl_api_wrap
struct texture_compare_mode
  : gl_enum_class<texture_compare_mode, EAGINE_ID_V(TexCmpMode)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL texture minification filter constants.
/// @ingroup gl_api_wrap
struct texture_min_filter
  : gl_enum_class<texture_min_filter, EAGINE_ID_V(TexMinFltr)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL texture magnification filter constants.
/// @ingroup gl_api_wrap
struct texture_mag_filter
  : gl_enum_class<texture_mag_filter, EAGINE_ID_V(TexMagFltr)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL texture filter constants.
/// @ingroup gl_api_wrap
struct texture_filter : gl_enum_class<texture_filter, EAGINE_ID_V(TexFilter)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL texture level parameter constants.
/// @ingroup gl_api_wrap
struct texture_level_parameter
  : gl_enum_class<texture_level_parameter, EAGINE_ID_V(TexLvlParm)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL texture parameter constants.
/// @ingroup gl_api_wrap
struct texture_parameter
  : gl_enum_class<texture_parameter, EAGINE_ID_V(TexParamtr)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL texture swizzle coordinate constants.
/// @ingroup gl_api_wrap
struct texture_swizzle_coord
  : gl_enum_class<texture_swizzle_coord, EAGINE_ID_V(TexSwzCord)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL texture swizzle mode constants.
/// @ingroup gl_api_wrap
struct texture_swizzle_mode
  : gl_enum_class<texture_swizzle_mode, EAGINE_ID_V(TexSwzMode)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL texture wrap coordinate constants.
/// @ingroup gl_api_wrap
struct texture_wrap_coord
  : gl_enum_class<texture_wrap_coord, EAGINE_ID_V(TexWrpCord)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL texture wrap mode constants.
/// @ingroup gl_api_wrap
struct texture_wrap_mode
  : gl_enum_class<texture_wrap_mode, EAGINE_ID_V(TexWrpMode)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL renderbuffer bind target constants.
/// @ingroup gl_api_wrap
struct renderbuffer_target
  : gl_enum_class<renderbuffer_target, EAGINE_ID_V(RboTarget)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL renderbuffer parameter constants.
/// @ingroup gl_api_wrap
struct renderbuffer_parameter
  : gl_enum_class<renderbuffer_parameter, EAGINE_ID_V(RboParamtr)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL framebuffer bind target constants.
/// @ingroup gl_api_wrap
struct framebuffer_target
  : gl_enum_class<framebuffer_target, EAGINE_ID_V(FboTarget)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL framebuffer status constants.
/// @ingroup gl_api_wrap
struct framebuffer_status
  : gl_enum_class<framebuffer_status, EAGINE_ID_V(FboStatus)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL framebuffer parameter constants.
/// @ingroup gl_api_wrap
struct framebuffer_parameter
  : gl_enum_class<framebuffer_parameter, EAGINE_ID_V(FboParamtr)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL framebuffer attachment parameter constants.
/// @ingroup gl_api_wrap
struct framebuffer_attachment_parameter
  : gl_enum_class<framebuffer_attachment_parameter, EAGINE_ID_V(FboAtchPar)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL framebuffer draw buffer constants.
/// @ingroup gl_api_wrap
struct framebuffer_buffer
  : gl_enum_class<framebuffer_buffer, EAGINE_ID_V(FboBuffer)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL framebuffer attachment constants.
/// @ingroup gl_api_wrap
struct framebuffer_attachment
  : gl_enum_class<framebuffer_attachment, EAGINE_ID_V(FboAttchmt)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL sampler parameter constants.
/// @ingroup gl_api_wrap
struct sampler_parameter
  : gl_enum_class<sampler_parameter, EAGINE_ID_V(SamParamtr)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL query target constants.
/// @ingroup gl_api_wrap
struct query_target : gl_enum_class<query_target, EAGINE_ID_V(QryTarget)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL counter query target constants.
/// @ingroup gl_api_wrap
struct counter_query_target
  : gl_enum_class<counter_query_target, EAGINE_ID_V(CntrQryTgt)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL query parameter constants.
/// @ingroup gl_api_wrap
struct query_parameter
  : gl_enum_class<query_parameter, EAGINE_ID_V(QryParamtr)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL transform feedback target constants.
/// @ingroup gl_api_wrap
struct transform_feedback_target
  : gl_enum_class<transform_feedback_target, EAGINE_ID_V(XfbTarget)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL transform feedback primitive type constants.
/// @ingroup gl_api_wrap
struct transform_feedback_primitive_type
  : gl_enum_class<transform_feedback_primitive_type, EAGINE_ID_V(XfbPrimTyp)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL transform feedback mode constants.
/// @ingroup gl_api_wrap
struct transform_feedback_mode
  : gl_enum_class<transform_feedback_mode, EAGINE_ID_V(XfbMode)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL transform feedback parameter constants.
/// @ingroup gl_api_wrap
struct transform_feedback_parameter
  : gl_enum_class<transform_feedback_parameter, EAGINE_ID_V(XfbParamtr)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL vertex attribute parameter constants.
/// @ingroup gl_api_wrap
struct vertex_attrib_parameter
  : gl_enum_class<vertex_attrib_parameter, EAGINE_ID_V(VAtrParmtr)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL primitive type constants.
/// @ingroup gl_api_wrap
struct primitive_type : gl_enum_class<primitive_type, EAGINE_ID_V(PrmtveType)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL legacy primitive type constants.
/// @ingroup gl_api_wrap
struct old_primitive_type
  : gl_enum_class<old_primitive_type, EAGINE_ID_V(OldPrmType)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL tessellation generator primitive type constants.
/// @ingroup gl_api_wrap
struct tess_gen_primitive_type
  : gl_enum_class<tess_gen_primitive_type, EAGINE_ID_V(TsGnPrmTyp)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL tessellation generator primitive spacing constants.
/// @ingroup gl_api_wrap
struct tess_gen_primitive_spacing
  : gl_enum_class<tess_gen_primitive_spacing, EAGINE_ID_V(TsGnPrmSpc)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL patch parameter constants.
/// @ingroup gl_api_wrap
struct patch_parameter
  : gl_enum_class<patch_parameter, EAGINE_ID_V(PtchParmtr)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL provoke mode constants.
/// @ingroup gl_api_wrap
struct provoke_mode : gl_enum_class<provoke_mode, EAGINE_ID_V(ProvkeMode)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL conditional render mode constants.
/// @ingroup gl_api_wrap
struct conditional_render_mode
  : gl_enum_class<conditional_render_mode, EAGINE_ID_V(CndRndrMod)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL face mode constants.
/// @ingroup gl_api_wrap
struct face_mode : gl_enum_class<face_mode, EAGINE_ID_V(FaceMode)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL face orientation constants.
/// @ingroup gl_api_wrap
struct face_orientation
  : gl_enum_class<face_orientation, EAGINE_ID_V(FaceOrient)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL draw surface buffer constants.
/// @ingroup gl_api_wrap
struct surface_buffer : gl_enum_class<surface_buffer, EAGINE_ID_V(SrfceBuffr)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL compare function constants.
/// @ingroup gl_api_wrap
struct compare_function
  : gl_enum_class<compare_function, EAGINE_ID_V(ComparFunc)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL blit filter constants.
/// @ingroup gl_api_wrap
struct blit_filter : gl_enum_class<blit_filter, EAGINE_ID_V(BlitFilter)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL binding query constants.
/// @ingroup gl_api_wrap
struct binding_query : gl_enum_class<binding_query, EAGINE_ID_V(BindQuery)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL integer query constants.
/// @ingroup gl_api_wrap
struct integer_query : gl_enum_class<integer_query, EAGINE_ID_V(IntQuery)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL floating-point query constants.
/// @ingroup gl_api_wrap
struct float_query : gl_enum_class<float_query, EAGINE_ID_V(FloatQuery)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL string query constants.
/// @ingroup gl_api_wrap
struct string_query : gl_enum_class<string_query, EAGINE_ID_V(StrQuery)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL named string query constants.
/// @ingroup gl_api_wrap
struct named_string_query
  : gl_enum_class<named_string_query, EAGINE_ID_V(NmdStrQury)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL data type constants.
/// @ingroup gl_api_wrap
struct data_type : gl_enum_class<data_type, EAGINE_ID_V(DataType)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL index data type constants.
/// @ingroup gl_api_wrap
struct index_data_type
  : gl_enum_class<index_data_type, EAGINE_ID_V(IdxDtaType)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL shading language data type constants.
/// @ingroup gl_api_wrap
struct sl_data_type : gl_enum_class<sl_data_type, EAGINE_ID_V(SLDataType)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL point parameter constants.
/// @ingroup gl_api_wrap
struct point_parameter
  : gl_enum_class<point_parameter, EAGINE_ID_V(PtParametr)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL point sprite coord origin constants.
/// @ingroup gl_api_wrap
struct point_sprite_coord_origin
  : gl_enum_class<point_sprite_coord_origin, EAGINE_ID_V(PtSprCrdOr)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL polygon mode constants.
/// @ingroup gl_api_wrap
struct polygon_mode : gl_enum_class<polygon_mode, EAGINE_ID_V(PolygnMode)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL stencil operation constants.
/// @ingroup gl_api_wrap
struct stencil_operation
  : gl_enum_class<stencil_operation, EAGINE_ID_V(StencilOp)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL logic operation constants.
/// @ingroup gl_api_wrap
struct logic_operation : gl_enum_class<logic_operation, EAGINE_ID_V(LogicOp)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL blend equation constants.
/// @ingroup gl_api_wrap
struct blend_equation : gl_enum_class<blend_equation, EAGINE_ID_V(BlendEqtn)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL advanced blend equation constants.
/// @ingroup gl_api_wrap
struct blend_equation_advanced
  : gl_enum_class<blend_equation_advanced, EAGINE_ID_V(BlndEqAdvn)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL blend function constants.
/// @ingroup gl_api_wrap
struct blend_function : gl_enum_class<blend_function, EAGINE_ID_V(BlendFunc)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL pixel data type constants.
/// @ingroup gl_api_wrap
struct pixel_data_type
  : gl_enum_class<pixel_data_type, EAGINE_ID_V(PixDataTyp)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL pixel format constants.
/// @ingroup gl_api_wrap
struct pixel_format : gl_enum_class<pixel_format, EAGINE_ID_V(PixelFrmat)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL image unit format constants.
/// @ingroup gl_api_wrap
struct image_unit_format
  : gl_enum_class<image_unit_format, EAGINE_ID_V(ImgUnitFmt)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL pixel internal format constants.
/// @ingroup gl_api_wrap
struct pixel_internal_format
  : gl_enum_class<pixel_internal_format, EAGINE_ID_V(PixIntlFmt)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL pixel store parameter constants.
/// @ingroup gl_api_wrap
struct pixel_store_parameter
  : gl_enum_class<pixel_store_parameter, EAGINE_ID_V(PixStorPrm)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL internal format parameter constants.
/// @ingroup gl_api_wrap
struct internal_format_parameter
  : gl_enum_class<internal_format_parameter, EAGINE_ID_V(IntlFmtPrm)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL image compatibility class constants.
/// @ingroup gl_api_wrap
struct image_compatibility_class
  : gl_enum_class<image_compatibility_class, EAGINE_ID_V(ImCompClss)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL view compatibility class constants.
/// @ingroup gl_api_wrap
struct view_compatibility_class
  : gl_enum_class<view_compatibility_class, EAGINE_ID_V(VwCompClss)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL sample parameter constants.
/// @ingroup gl_api_wrap
struct sample_parameter
  : gl_enum_class<sample_parameter, EAGINE_ID_V(SampleParm)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL hint option constants.
/// @ingroup gl_api_wrap
struct hint_option : gl_enum_class<hint_option, EAGINE_ID_V(HintOption)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL hint target constants.
/// @ingroup gl_api_wrap
struct hint_target : gl_enum_class<hint_target, EAGINE_ID_V(HintTarget)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL debug output severity constants.
/// @ingroup gl_api_wrap
struct debug_output_severity
  : gl_enum_class<debug_output_severity, EAGINE_ID_V(DbgOutSvrt)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL debug output source constants.
/// @ingroup gl_api_wrap
struct debug_output_source
  : gl_enum_class<debug_output_source, EAGINE_ID_V(DbgOutSrce)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL debug output type constants.
/// @ingroup gl_api_wrap
struct debug_output_type
  : gl_enum_class<debug_output_type, EAGINE_ID_V(DbgOutType)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL feature support level constants.
/// @ingroup gl_api_wrap
struct support_level : gl_enum_class<support_level, EAGINE_ID_V(SupportLvl)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL named string kind constants.
/// @ingroup gl_api_wrap
struct named_string_kind
  : gl_enum_class<named_string_kind, EAGINE_ID_V(NmdStrKind)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL legacy matrix mode constants.
/// @ingroup gl_api_wrap
struct matrix_mode : gl_enum_class<matrix_mode, EAGINE_ID_V(MatrixMode)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL path command constants.
/// @ingroup gl_api_wrap
struct path_command_nv
  : gl_ubyte_class<path_command_nv, EAGINE_ID_V(PathComand)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL path cap style constants.
/// @ingroup gl_api_wrap
struct path_cap_style_nv
  : gl_enum_class<path_cap_style_nv, EAGINE_ID_V(PathCapSty)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL path color format constants.
/// @ingroup gl_api_wrap
struct path_color_format_nv
  : gl_enum_class<path_color_format_nv, EAGINE_ID_V(PathClrFmt)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL path color constants.
/// @ingroup gl_api_wrap
struct path_color_nv : gl_enum_class<path_color_nv, EAGINE_ID_V(PathColor)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL path dash offset constants.
/// @ingroup gl_api_wrap
struct path_dash_offset_reset_nv
  : gl_enum_class<path_dash_offset_reset_nv, EAGINE_ID_V(PathDsORst)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL path stroke cover mode constants.
/// @ingroup gl_api_wrap
struct path_stroke_cover_mode_nv
  : gl_enum_class<path_stroke_cover_mode_nv, EAGINE_ID_V(PathStCvrM)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL path fill cover mode constants.
/// @ingroup gl_api_wrap
struct path_fill_cover_mode_nv
  : gl_enum_class<path_fill_cover_mode_nv, EAGINE_ID_V(PathFlCvrM)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL path fill mode constants.
/// @ingroup gl_api_wrap
struct path_fill_mode_nv
  : gl_enum_class<path_fill_mode_nv, EAGINE_ID_V(PathFillMd)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL path font style constants.
/// @ingroup gl_api_wrap
struct path_font_style_nv
  : gl_bitfield_class<path_font_style_nv, EAGINE_ID_V(PathFntSty)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL path join style constants.
/// @ingroup gl_api_wrap
struct path_join_style_nv
  : gl_bitfield_class<path_join_style_nv, EAGINE_ID_V(PathJinSty)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL path font target constants.
/// @ingroup gl_api_wrap
struct path_font_target_nv
  : gl_enum_class<path_font_target_nv, EAGINE_ID_V(PathFntTgt)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL path format constants.
/// @ingroup gl_api_wrap
struct path_format_nv : gl_enum_class<path_format_nv, EAGINE_ID_V(PathFormat)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL path gen mode constants.
/// @ingroup gl_api_wrap
struct path_gen_mode_nv
  : gl_enum_class<path_gen_mode_nv, EAGINE_ID_V(PathGenMod)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL path list mode constants.
/// @ingroup gl_api_wrap
struct path_list_mode_nv
  : gl_enum_class<path_list_mode_nv, EAGINE_ID_V(PathLstMod)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL path metric query constants.
/// @ingroup gl_api_wrap
struct path_metric_query_nv
  : gl_bitfield_class<path_metric_query_nv, EAGINE_ID_V(PathMrcQry)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL path missing glyph constants.
/// @ingroup gl_api_wrap
struct path_missing_glyph_nv
  : gl_bitfield_class<path_missing_glyph_nv, EAGINE_ID_V(PathMsnGph)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL path parameter constants.
/// @ingroup gl_api_wrap
struct path_parameter_nv
  : gl_bitfield_class<path_parameter_nv, EAGINE_ID_V(PathPrmter)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL path text encoding constants.
/// @ingroup gl_api_wrap
struct path_text_encoding_nv
  : gl_bitfield_class<path_text_encoding_nv, EAGINE_ID_V(PathTxtEnc)> {
    using enum_class::enum_class;
};

/// @brief Typed enumeration for GL path transform type constants.
/// @ingroup gl_api_wrap
struct path_transform_type_nv
  : gl_bitfield_class<path_transform_type_nv, EAGINE_ID_V(PathTrnsfT)> {
    using enum_class::enum_class;
};
//------------------------------------------------------------------------------
} // namespace eagine::oglp

#endif // OGLPLUS_GL_API_ENUM_TYPES_HPP
