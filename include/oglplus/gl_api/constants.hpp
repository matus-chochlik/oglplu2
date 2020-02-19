/**
 *  @file oglplus/gl_api/constants.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_GL_API_CONSTANTS_HPP
#define OGLPLUS_GL_API_CONSTANTS_HPP

#include "c_api.hpp"
#include "enum_types.hpp"

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
struct basic_gl_constants {
public:
    using enum_type = typename gl_types::enum_type;
    using enum_type_i = identity<enum_type>;
    template <enum_type value>
    using enum_type_c = std::integral_constant<enum_type, value>;

    using bitfield_type = typename gl_types::bitfield_type;
    using bitfield_type_i = identity<bitfield_type>;
    template <bitfield_type value>
    using bitfield_type_c = std::integral_constant<bitfield_type, value>;

    opt_c_api_constant<
      mp_list<error_code, graphics_reset_status>,
#ifdef GL_NO_ERROR
      enum_type_c<GL_NO_ERROR>>
#else
      enum_type_i>
#endif
      no_error;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef GL_INVALID_ENUM
      enum_type_c<GL_INVALID_ENUM>>
#else
      enum_type_i>
#endif
      invalid_enum;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef GL_INVALID_VALUE
      enum_type_c<GL_INVALID_VALUE>>
#else
      enum_type_i>
#endif
      invalid_value;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef GL_INVALID_OPERATION
      enum_type_c<GL_INVALID_OPERATION>>
#else
      enum_type_i>
#endif
      invalid_operation;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef GL_INVALID_FRAMEBUFFER_OPERATION
      enum_type_c<GL_INVALID_FRAMEBUFFER_OPERATION>>
#else
      enum_type_i>
#endif
      invalid_framebuffer_operation;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef GL_STACK_OVERFLOW
      enum_type_c<GL_STACK_OVERFLOW>>
#else
      enum_type_i>
#endif
      stack_overflow;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef GL_STACK_UNDERFLOW
      enum_type_c<GL_STACK_UNDERFLOW>>
#else
      enum_type_i>
#endif
      stack_underflow;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef GL_TABLE_TOO_LARGE
      enum_type_c<GL_TABLE_TOO_LARGE>>
#else
      enum_type_i>
#endif
      table_too_large;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef GL_CONTEXT_LOST
      enum_type_c<GL_CONTEXT_LOST>>
#else
      enum_type_i>
#endif
      context_lost;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef GL_OUT_OF_MEMORY
      enum_type_c<GL_OUT_OF_MEMORY>>
#else
      enum_type_i>
#endif
      out_of_memory;

    opt_c_api_constant<
      mp_list<graphics_reset_status>,
#ifdef GL_GUILTY_CONTEXT_RESET
      enum_type_c<GL_GUILTY_CONTEXT_RESET>>
#else
      enum_type_i>
#endif
      guilty_context_reset;

    opt_c_api_constant<
      mp_list<graphics_reset_status>,
#ifdef GL_INNOCENT_CONTEXT_RESET
      enum_type_c<GL_INNOCENT_CONTEXT_RESET>>
#else
      enum_type_i>
#endif
      innocent_context_reset;

    opt_c_api_constant<
      mp_list<graphics_reset_status>,
#ifdef GL_UNKNOWN_CONTEXT_RESET
      enum_type_c<GL_UNKNOWN_CONTEXT_RESET>>
#else
      enum_type_i>
#endif
      unknown_context_reset;

    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_ARRAY_BUFFER
      enum_type_c<GL_ARRAY_BUFFER>>
#else
      enum_type_i>
#endif
      array_buffer;

    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_ATOMIC_COUNTER_BUFFER
      enum_type_c<GL_ATOMIC_COUNTER_BUFFER>>
#else
      enum_type_i>
#endif
      atomic_counter_buffer;

    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_COPY_READ_BUFFER
      enum_type_c<GL_COPY_READ_BUFFER>>
#else
      enum_type_i>
#endif
      copy_read_buffer;

    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_COPY_WRITE_BUFFER
      enum_type_c<GL_COPY_WRITE_BUFFER>>
#else
      enum_type_i>
#endif
      copy_write_buffer;

    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_DISPATCH_INDIRECT_BUFFER
      enum_type_c<GL_DISPATCH_INDIRECT_BUFFER>>
#else
      enum_type_i>
#endif
      dispatch_indirect_buffer;

    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_DRAW_INDIRECT_BUFFER
      enum_type_c<GL_DRAW_INDIRECT_BUFFER>>
#else
      enum_type_i>
#endif
      draw_indirect_buffer;

    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_ELEMENT_ARRAY_BUFFER
      enum_type_c<GL_ELEMENT_ARRAY_BUFFER>>
#else
      enum_type_i>
#endif
      element_array_buffer;

    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_PARAMETER_BUFFER
      enum_type_c<GL_PARAMETER_BUFFER>>
#else
      enum_type_i>
#endif
      parameter_buffer;

    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_PIXEL_PACK_BUFFER
      enum_type_c<GL_PIXEL_PACK_BUFFER>>
#else
      enum_type_i>
#endif
      pixel_pack_buffer;

    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_PIXEL_UNPACK_BUFFER
      enum_type_c<GL_PIXEL_UNPACK_BUFFER>>
#else
      enum_type_i>
#endif
      pixel_unpack_buffer;

    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_QUERY_BUFFER
      enum_type_c<GL_QUERY_BUFFER>>
#else
      enum_type_i>
#endif
      query_buffer;

    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_SHADER_STORAGE_BUFFER
      enum_type_c<GL_SHADER_STORAGE_BUFFER>>
#else
      enum_type_i>
#endif
      shader_storage_buffer;

    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_TEXTURE_BUFFER
      enum_type_c<GL_TEXTURE_BUFFER>>
#else
      enum_type_i>
#endif
      texture_buffer;

    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER
      enum_type_c<GL_TRANSFORM_FEEDBACK_BUFFER>>
#else
      enum_type_i>
#endif
      transform_feedback_buffer;

    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_UNIFORM_BUFFER
      enum_type_c<GL_UNIFORM_BUFFER>>
#else
      enum_type_i>
#endif
      uniform_buffer;

    opt_c_api_constant<
      mp_list<buffer_usage>,
#ifdef GL_STREAM_DRAW
      enum_type_c<GL_STREAM_DRAW>>
#else
      enum_type_i>
#endif
      stream_draw;

    opt_c_api_constant<
      mp_list<buffer_usage>,
#ifdef GL_STREAM_READ
      enum_type_c<GL_STREAM_READ>>
#else
      enum_type_i>
#endif
      stream_read;

    opt_c_api_constant<
      mp_list<buffer_usage>,
#ifdef GL_STREAM_COPY
      enum_type_c<GL_STREAM_COPY>>
#else
      enum_type_i>
#endif
      stream_copy;

    opt_c_api_constant<
      mp_list<buffer_usage>,
#ifdef GL_STATIC_DRAW
      enum_type_c<GL_STATIC_DRAW>>
#else
      enum_type_i>
#endif
      static_draw;

    opt_c_api_constant<
      mp_list<buffer_usage>,
#ifdef GL_STATIC_READ
      enum_type_c<GL_STATIC_READ>>
#else
      enum_type_i>
#endif
      static_read;

    opt_c_api_constant<
      mp_list<buffer_usage>,
#ifdef GL_STATIC_COPY
      enum_type_c<GL_STATIC_COPY>>
#else
      enum_type_i>
#endif
      static_copy;

    opt_c_api_constant<
      mp_list<buffer_usage>,
#ifdef GL_DYNAMIC_DRAW
      enum_type_c<GL_DYNAMIC_DRAW>>
#else
      enum_type_i>
#endif
      dynamic_draw;

    opt_c_api_constant<
      mp_list<buffer_usage>,
#ifdef GL_DYNAMIC_READ
      enum_type_c<GL_DYNAMIC_READ>>
#else
      enum_type_i>
#endif
      dynamic_read;

    opt_c_api_constant<
      mp_list<buffer_usage>,
#ifdef GL_DYNAMIC_COPY
      enum_type_c<GL_DYNAMIC_COPY>>
#else
      enum_type_i>
#endif
      dynamic_copy;

    opt_c_api_constant<
      mp_list<buffer_map_access_bit>,
#ifdef GL_MAP_READ_BIT
      enum_type_c<GL_MAP_READ_BIT>>
#else
      enum_type_i>
#endif
      map_read_bit;

    opt_c_api_constant<
      mp_list<buffer_map_access_bit>,
#ifdef GL_MAP_WRITE_BIT
      enum_type_c<GL_MAP_WRITE_BIT>>
#else
      enum_type_i>
#endif
      map_write_bit;

    opt_c_api_constant<
      mp_list<buffer_map_access_bit>,
#ifdef GL_MAP_PERSISTENT_BIT
      enum_type_c<GL_MAP_PERSISTENT_BIT>>
#else
      enum_type_i>
#endif
      map_persistent_bit;

    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_BLEND
      enum_type_c<GL_BLEND>>
#else
      enum_type_i>
#endif
      blend;

    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_CULL_FACE
      enum_type_c<GL_CULL_FACE>>
#else
      enum_type_i>
#endif
      cull_face;

    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_DEPTH_CLAMP
      enum_type_c<GL_DEPTH_CLAMP>>
#else
      enum_type_i>
#endif
      depth_clamp;

    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_DEPTH_TEST
      enum_type_c<GL_DEPTH_TEST>>
#else
      enum_type_i>
#endif
      depth_test;

    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_SCISSOR_TEST
      enum_type_c<GL_SCISSOR_TEST>>
#else
      enum_type_i>
#endif
      scissor_test;

    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_STENCIL_TEST
      enum_type_c<GL_STENCIL_TEST>>
#else
      enum_type_i>
#endif
      stencil_test;

    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_MULTISAMPLE
      enum_type_c<GL_MULTISAMPLE>>
#else
      enum_type_i>
#endif
      multisample;

    opt_c_api_constant<
      mp_list<string_query>,
#ifdef GL_VENDOR
      enum_type_c<GL_VENDOR>>
#else
      enum_type_i>
#endif
      vendor;

    opt_c_api_constant<
      mp_list<string_query>,
#ifdef GL_RENDERER
      enum_type_c<GL_RENDERER>>
#else
      enum_type_i>
#endif
      renderer;

    opt_c_api_constant<
      mp_list<string_query>,
#ifdef GL_VERSION
      enum_type_c<GL_VERSION>>
#else
      enum_type_i>
#endif
      version;

    opt_c_api_constant<
      mp_list<string_query>,
#ifdef GL_SHADING_LANGUAGE_VERSION
      enum_type_c<GL_SHADING_LANGUAGE_VERSION>>
#else
      enum_type_i>
#endif
      shading_language_version;

    opt_c_api_constant<
      mp_list<string_query>,
#ifdef GL_EXTENSIONS
      enum_type_c<GL_EXTENSIONS>>
#else
      enum_type_i>
#endif
      extensions;

    opt_c_api_constant<
      mp_list<buffer_clear_bit>,
#ifdef GL_COLOR_BUFFER_BIT
      bitfield_type_c<GL_COLOR_BUFFER_BIT>>
#else
      bitfield_type_i>
#endif
      color_buffer_bit;

    opt_c_api_constant<
      mp_list<buffer_clear_bit>,
#ifdef GL_DEPTH_BUFFER_BIT
      bitfield_type_c<GL_DEPTH_BUFFER_BIT>>
#else
      bitfield_type_i>
#endif
      depth_buffer_bit;

    opt_c_api_constant<
      mp_list<buffer_clear_bit>,
#ifdef GL_STENCIL_BUFFER_BIT
      bitfield_type_c<GL_STENCIL_BUFFER_BIT>>
#else
      bitfield_type_i>
#endif
      stencil_buffer_bit;

    opt_c_api_constant<
      mp_list<texture_compare_mode>,
#ifdef GL_NONE
      bitfield_type_c<GL_NONE>>
#else
      bitfield_type_i>
#endif
      none;

    basic_gl_constants(ApiTraits& traits, basic_gl_c_api<ApiTraits>& api)
      : no_error("NO_ERROR", traits, api)
      , invalid_enum("INVALID_ENUM", traits, api)
      , invalid_value("INVALID_VALUE", traits, api)
      , invalid_operation("INVALID_OPERATION", traits, api)
      , invalid_framebuffer_operation(
          "INVALID_FRAMEBUFFER_OPERATION", traits, api)
      , stack_overflow("STACK_OVERFLOW", traits, api)
      , stack_underflow("STACK_UNDERFLOW", traits, api)
      , table_too_large("TABLE_TOO_LARGE", traits, api)
      , context_lost("CONTEXT_LOST", traits, api)
      , out_of_memory("OUT_OF_MEMORY", traits, api)
      , guilty_context_reset("GUILTY_CONTEXT_RESET", traits, api)
      , innocent_context_reset("INNOCENT_CONTEXT_RESET", traits, api)
      , unknown_context_reset("UNKNOWN_CONTEXT_RESET", traits, api)
      , array_buffer("ARRAY_BUFFER", traits, api)
      , atomic_counter_buffer("ATOMIC_COUNTER_BUFFER", traits, api)
      , copy_read_buffer("COPY_READ_BUFFER", traits, api)
      , copy_write_buffer("COPY_WRITE_BUFFER", traits, api)
      , dispatch_indirect_buffer("DISPATCH_INDIRECT_BUFFER", traits, api)
      , draw_indirect_buffer("DRAW_INDIRECT_BUFFER", traits, api)
      , element_array_buffer("ELEMENT_ARRAY_BUFFER", traits, api)
      , parameter_buffer("PARAMETER_BUFFER", traits, api)
      , pixel_pack_buffer("PIXEL_PACK_BUFFER", traits, api)
      , pixel_unpack_buffer("PIXEL_UNPACK_BUFFER", traits, api)
      , query_buffer("QUERY_BUFFER", traits, api)
      , shader_storage_buffer("SHADER_STORAGE_BUFFER", traits, api)
      , texture_buffer("TEXTURE_BUFFER", traits, api)
      , transform_feedback_buffer("TRANSFORM_FEEDBACK_BUFFER", traits, api)
      , uniform_buffer("UNIFORM_BUFFER", traits, api)
      , stream_draw("STREAM_DRAW", traits, api)
      , stream_read("STREAM_READ", traits, api)
      , stream_copy("STREAM_COPY", traits, api)
      , static_draw("STATIC_DRAW", traits, api)
      , static_read("STATIC_READ", traits, api)
      , static_copy("STATIC_COPY", traits, api)
      , dynamic_draw("DYNAMIC_DRAW", traits, api)
      , dynamic_read("DYNAMIC_READ", traits, api)
      , dynamic_copy("DYNAMIC_COPY", traits, api)
      , map_read_bit("MAP_READ_BIT", traits, api)
      , map_write_bit("MAP_WRITE_BIT", traits, api)
      , map_persistent_bit("MAP_PERSISTENT_BIT", traits, api)
      , blend("BLEND", traits, api)
      , cull_face("CULL_FACE", traits, api)
      , depth_clamp("DEPTH_CLAMP", traits, api)
      , depth_test("DEPTH_TEST", traits, api)
      , scissor_test("SCISSOR_TEST", traits, api)
      , stencil_test("STENCIL_TEST", traits, api)
      , multisample("MULTISAMPLE", traits, api)
      , vendor("VENDOR", traits, api)
      , renderer("RENDERER", traits, api)
      , version("VERSION", traits, api)
      , shading_language_version("SHADING_LANGUAGE_VERSION", traits, api)
      , extensions("EXTENSIONS", traits, api)
      , color_buffer_bit("COLOR_BUFFER_BIT", traits, api)
      , depth_buffer_bit("DEPTH_BUFFER_BIT", traits, api)
      , stencil_buffer_bit("STENCIL_BUFFER_BIT", traits, api)
      , none("NONE", traits, api) {
    }
};
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine

#endif // OGLPLUS_GL_API_CONSTANTS_HPP

