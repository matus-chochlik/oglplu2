/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OGLPLUS_GL_API_CONSTANTS_HPP
#define OGLPLUS_GL_API_CONSTANTS_HPP

#include "../math/matrix.hpp"
#include "../math/vector.hpp"
#include "c_api.hpp"
#include "enum_types.hpp"
#include "object_name.hpp"
#include <eagine/int_constant.hpp>
#include <array>

namespace eagine::oglp {
//------------------------------------------------------------------------------
/// @brief Class wrapping the constants from the GL API.
/// @ingroup gl_api_wrap
/// @see basic_gl_c_api
/// @see basic_gl_operations
template <typename ApiTraits>
class basic_gl_constants {
public:
    /// @brief Constant wrapper that can also be used to construct instances.
    template <typename Wrap, typename T = typename Wrap::tag_type>
    struct type_constructor_constant : Wrap {
        using Wrap::Wrap;

        /// @brief Creates an instance of the constant type with the specified value.
        template <typename X>
        auto operator()(X&& x) const noexcept
          -> std::enable_if_t<std::is_convertible_v<X, T>, T> {
            return T(std::forward<X>(x));
        }

        /// @var array
        /// @brief Helper that can be used to create arrays of the constant type.
        struct {
            /// @brief Creates an array of the constant type with the specified values.
            template <typename... X>
            auto operator()(X&&... x) const noexcept -> std::enable_if_t<
              ((sizeof...(X) > 0) && ... &&
               std::is_convertible_v<std::decay_t<X>, T>),
              std::array<T, sizeof...(X)>> {
                return {{T(std::forward<X>(x))...}};
            }

            template <std::size_t L>
            auto operator()(size_constant<L> = {}) const noexcept
              -> std::array<T, L> {
                return {{}};
            }
        } array;
    };

    template <typename Wrap, typename T, std::size_t N>
    struct type_constructor_constant<Wrap, T[N]> : Wrap {
        using Wrap::Wrap;

        template <typename... X>
        auto operator()(X&&... x) const noexcept -> std::enable_if_t<
          ((sizeof...(X) == N) && ... && std::is_convertible_v<X, T>),
          tvec<T, N>> {
            return tvec<T, N>(T(std::forward<X>(x))...);
        }
    };

    template <typename Wrap, typename T, std::size_t C, std::size_t R>
    struct type_constructor_constant<Wrap, T[C][R]> : Wrap {
        using Wrap::Wrap;

        template <typename... X>
        auto operator()(X&&... x) const noexcept -> std::enable_if_t<
          ((sizeof...(X) == C * R) && ... && std::is_convertible_v<X, T>),
          tmat<T, C, R>> {
            return tmat<T, C, R>(T(std::forward<X>(x))...);
        }
    };

    using enum_type = typename gl_types::enum_type;
    using enum_type_i = type_identity<enum_type>;
    template <enum_type value>
    using enum_type_c = std::integral_constant<enum_type, value>;

    using bitfield_type = typename gl_types::bitfield_type;
    using bitfield_type_i = type_identity<bitfield_type>;
    template <bitfield_type value>
    using bitfield_type_c = std::integral_constant<bitfield_type, value>;

    using ubyte_type = typename gl_types::ubyte_type;
    using ubyte_type_i = type_identity<ubyte_type>;
    template <ubyte_type value>
    using ubyte_type_c = std::integral_constant<ubyte_type, value>;

    using bool_type = typename gl_types::bool_type;
    using bool_type_i = type_identity<bool_type>;
    template <bool_type value>
    using bool_type_c = std::integral_constant<bool_type, value>;

    /// @var no_error
    /// @glconstwrap{NO_ERROR}
    opt_c_api_constant<
      mp_list<error_code, graphics_reset_status>,
#ifdef GL_NO_ERROR
      enum_type_c<GL_NO_ERROR>>
#else
      enum_type_i>
#endif
      no_error;

    /// @var invalid_enum
    /// @glconstwrap{INVALID_ENUM}
    opt_c_api_constant<
      mp_list<error_code>,
#ifdef GL_INVALID_ENUM
      enum_type_c<GL_INVALID_ENUM>>
#else
      enum_type_i>
#endif
      invalid_enum;

    /// @var invalid_value
    /// @glconstwrap{INVALID_VALUE}
    opt_c_api_constant<
      mp_list<error_code>,
#ifdef GL_INVALID_VALUE
      enum_type_c<GL_INVALID_VALUE>>
#else
      enum_type_i>
#endif
      invalid_value;

    /// @var invalid_operation
    /// @glconstwrap{INVALID_OPERATION}
    opt_c_api_constant<
      mp_list<error_code>,
#ifdef GL_INVALID_OPERATION
      enum_type_c<GL_INVALID_OPERATION>>
#else
      enum_type_i>
#endif
      invalid_operation;

    /// @var invalid_framebuffer_operation
    /// @glconstwrap{INVALID_FRAMEBUFFER_OPERATION}
    opt_c_api_constant<
      mp_list<error_code>,
#ifdef GL_INVALID_FRAMEBUFFER_OPERATION
      enum_type_c<GL_INVALID_FRAMEBUFFER_OPERATION>>
#else
      enum_type_i>
#endif
      invalid_framebuffer_operation;

    /// @var stack_overflow
    /// @glconstwrap{STACK_OVERFLOW}
    opt_c_api_constant<
      mp_list<error_code>,
#ifdef GL_STACK_OVERFLOW
      enum_type_c<GL_STACK_OVERFLOW>>
#else
      enum_type_i>
#endif
      stack_overflow;

    /// @var stack_underflow
    /// @glconstwrap{STACK_UNDERFLOW}
    opt_c_api_constant<
      mp_list<error_code>,
#ifdef GL_STACK_UNDERFLOW
      enum_type_c<GL_STACK_UNDERFLOW>>
#else
      enum_type_i>
#endif
      stack_underflow;

    /// @var table_too_large
    /// @glconstwrap{TABLE_TOO_LARGE}
    opt_c_api_constant<
      mp_list<error_code>,
#ifdef GL_TABLE_TOO_LARGE
      enum_type_c<GL_TABLE_TOO_LARGE>>
#else
      enum_type_i>
#endif
      table_too_large;

    /// @var context_lost
    /// @glconstwrap{CONTEXT_LOST}
    opt_c_api_constant<
      mp_list<error_code>,
#ifdef GL_CONTEXT_LOST
      enum_type_c<GL_CONTEXT_LOST>>
#else
      enum_type_i>
#endif
      context_lost;

    /// @var out_of_memory
    /// @glconstwrap{OUT_OF_MEMORY}
    opt_c_api_constant<
      mp_list<error_code>,
#ifdef GL_OUT_OF_MEMORY
      enum_type_c<GL_OUT_OF_MEMORY>>
#else
      enum_type_i>
#endif
      out_of_memory;

    /// @var true_
    /// @glconstwrap{TRUE}
    opt_c_api_constant<
      mp_list<oglp::true_false>,
#ifdef GL_TRUE
      bool_type_c<GL_TRUE>>
#else
      bool_type_i>
#endif
      true_;

    /// @var false_
    /// @glconstwrap{FALSE}
    opt_c_api_constant<
      mp_list<oglp::true_false>,
#ifdef GL_FALSE
      bool_type_c<GL_FALSE>>
#else
      bool_type_i>
#endif
      false_;

    /// @var context_flag_forward_compatible_bit
    /// @glconstwrap{CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT}
    opt_c_api_constant<
      mp_list<context_flag_bit>,
#ifdef GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT
      bitfield_type_c<GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT>>
#else
      bitfield_type_i>
#endif
      context_flag_forward_compatible_bit;

    /// @var context_flag_debug_bit
    /// @glconstwrap{CONTEXT_FLAG_FORWARD_DEBUG_BIT}
    opt_c_api_constant<
      mp_list<context_flag_bit>,
#ifdef GL_CONTEXT_FLAG_DEBUG_BIT
      bitfield_type_c<GL_CONTEXT_FLAG_DEBUG_BIT>>
#else
      bitfield_type_i>
#endif
      context_flag_debug_bit;

    /// @var context_flag_robust_access_bit
    /// @glconstwrap{CONTEXT_FLAG_ROBUST_ACCESS_BIT}
    opt_c_api_constant<
      mp_list<context_flag_bit>,
#ifdef GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT
      bitfield_type_c<GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT>>
#else
      bitfield_type_i>
#endif
      context_flag_robust_access_bit;

    /// @var context_flag_no_error_bit
    /// @glconstwrap{CONTEXT_FLAG_NO_ERROR_BIT}
    opt_c_api_constant<
      mp_list<context_flag_bit>,
#ifdef GL_CONTEXT_FLAG_NO_ERROR_BIT
      bitfield_type_c<GL_CONTEXT_FLAG_NO_ERROR_BIT>>
#else
      bitfield_type_i>
#endif
      context_flag_no_error_bit;

    /// @var context_core_profile_bit
    /// @glconstwrap{CONTEXT_CORE_PROFILE_BIT}
    opt_c_api_constant<
      mp_list<context_profile_bit>,
#ifdef GL_CONTEXT_CORE_PROFILE_BIT
      bitfield_type_c<GL_CONTEXT_CORE_PROFILE_BIT>>
#else
      bitfield_type_i>
#endif
      context_core_profile_bit;

    /// @var context_compatibility_profile_bit
    /// @glconstwrap{CONTEXT_COMPATIBILITY_PROFILE_BIT}
    opt_c_api_constant<
      mp_list<context_profile_bit>,
#ifdef GL_CONTEXT_COMPATIBILITY_PROFILE_BIT
      bitfield_type_c<GL_CONTEXT_COMPATIBILITY_PROFILE_BIT>>
#else
      bitfield_type_i>
#endif
      context_compatibility_profile_bit;

    /// @var no_reset_notification
    /// @glconstwrap{NO_RESET_NOTIFICATION}
    opt_c_api_constant<
      mp_list<oglp::reset_notification_strategy>,
#ifdef GL_NO_RESET_NOTIFICATION
      enum_type_c<GL_NO_RESET_NOTIFICATION>>
#else
      enum_type_i>
#endif
      no_reset_notification;

    /// @var lose_context_on_reset
    /// @glconstwrap{LOSE_CONTEXT_ON_RESET}
    opt_c_api_constant<
      mp_list<oglp::reset_notification_strategy>,
#ifdef GL_LOSE_CONTEXT_ON_RESET
      enum_type_c<GL_LOSE_CONTEXT_ON_RESET>>
#else
      enum_type_i>
#endif
      lose_context_on_reset;

    /// @var context_release_behavior_flush
    /// @glconstwrap{CONTEXT_RELEASE_BEHAVIOR_FLUSH}
    opt_c_api_constant<
      mp_list<context_release_behavior>,
#ifdef GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH
      enum_type_c<GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH>>
#else
      enum_type_i>
#endif
      context_release_behavior_flush;

    /// @var guilty_context_reset
    /// @glconstwrap{GUILTY_CONTEXT_RESET}
    opt_c_api_constant<
      mp_list<graphics_reset_status>,
#ifdef GL_GUILTY_CONTEXT_RESET
      enum_type_c<GL_GUILTY_CONTEXT_RESET>>
#else
      enum_type_i>
#endif
      guilty_context_reset;

    /// @var innocent_context_reset
    /// @glconstwrap{INNOCENT_CONTEXT_RESET}
    opt_c_api_constant<
      mp_list<graphics_reset_status>,
#ifdef GL_INNOCENT_CONTEXT_RESET
      enum_type_c<GL_INNOCENT_CONTEXT_RESET>>
#else
      enum_type_i>
#endif
      innocent_context_reset;

    /// @var graphics_reset_status
    /// @glconstwrap{GRAPHICS_RESET_STATUS}
    opt_c_api_constant<
      mp_list<graphics_reset_status>,
#ifdef GL_UNKNOWN_CONTEXT_RESET
      enum_type_c<GL_UNKNOWN_CONTEXT_RESET>>
#else
      enum_type_i>
#endif
      unknown_context_reset;

    /// @var vertex_attrib_array_barrier_bit
    /// @glconstwrap{VERTEX_ATTRIB_ARRAY_BARRIER_BIT}
    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT
      bitfield_type_c<GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT>>
#else
      bitfield_type_i>
#endif
      vertex_attrib_array_barrier_bit;

    /// @var element_array_barrier_bit
    /// @glconstwrap{ELEMENT_ARRAY_BARRIER_BIT}
    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_ELEMENT_ARRAY_BARRIER_BIT
      bitfield_type_c<GL_ELEMENT_ARRAY_BARRIER_BIT>>
#else
      bitfield_type_i>
#endif
      element_array_barrier_bit;

    /// @var uniform_barrier_bit
    /// @glconstwrap{UNIFORM_BARRIER_BIT}
    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_UNIFORM_BARRIER_BIT
      bitfield_type_c<GL_UNIFORM_BARRIER_BIT>>
#else
      bitfield_type_i>
#endif
      uniform_barrier_bit;

    /// @var texture_fetch_barrier_bit
    /// @glconstwrap{TEXTURE_FETCH_BARRIER_BIT}
    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_TEXTURE_FETCH_BARRIER_BIT
      bitfield_type_c<GL_TEXTURE_FETCH_BARRIER_BIT>>
#else
      bitfield_type_i>
#endif
      texture_fetch_barrier_bit;

    /// @var shader_image_access_barrier_bit
    /// @glconstwrap{SHADER_IMAGE_ACCESS_BARRIER_BIT}
    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_SHADER_IMAGE_ACCESS_BARRIER_BIT
      bitfield_type_c<GL_SHADER_IMAGE_ACCESS_BARRIER_BIT>>
#else
      bitfield_type_i>
#endif
      shader_image_access_barrier_bit;

    /// @var command_barrier_bit
    /// @glconstwrap{COMMAND_BARRIER_BIT}
    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_COMMAND_BARRIER_BIT
      bitfield_type_c<GL_COMMAND_BARRIER_BIT>>
#else
      bitfield_type_i>
#endif
      command_barrier_bit;

    /// @var pixel_buffer_barrier_bit
    /// @glconstwrap{PIXEL_BUFFER_BARRIER_BIT}
    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_PIXEL_BUFFER_BARRIER_BIT
      bitfield_type_c<GL_PIXEL_BUFFER_BARRIER_BIT>>
#else
      bitfield_type_i>
#endif
      pixel_buffer_barrier_bit;

    /// @var texture_update_barrier_bit
    /// @glconstwrap{TEXTURE_UPDATE_BARRIER_BIT}
    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_TEXTURE_UPDATE_BARRIER_BIT
      bitfield_type_c<GL_TEXTURE_UPDATE_BARRIER_BIT>>
#else
      bitfield_type_i>
#endif
      texture_update_barrier_bit;

    /// @var buffer_update_barrier_bit
    /// @glconstwrap{BUFFER_UPDATE_BARRIER_BIT}
    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_BUFFER_UPDATE_BARRIER_BIT
      bitfield_type_c<GL_BUFFER_UPDATE_BARRIER_BIT>>
#else
      bitfield_type_i>
#endif
      buffer_update_barrier_bit;

    /// @var client_mapped_buffer_barrier_bit
    /// @glconstwrap{CLIENT_MAPPED_BUFFER_BARRIER_BIT}
    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT
      bitfield_type_c<GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT>>
#else
      bitfield_type_i>
#endif
      client_mapped_buffer_barrier_bit;

    /// @var query_buffer_barrier_bit
    /// @glconstwrap{QUERY_BUFFER_BARRIER_BIT}
    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_QUERY_BUFFER_BARRIER_BIT
      bitfield_type_c<GL_QUERY_BUFFER_BARRIER_BIT>>
#else
      bitfield_type_i>
#endif
      query_buffer_barrier_bit;

    /// @var framebuffer_barrier_bit
    /// @glconstwrap{FRAMEBUFFER_BARRIER_BIT}
    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_FRAMEBUFFER_BARRIER_BIT
      bitfield_type_c<GL_FRAMEBUFFER_BARRIER_BIT>>
#else
      bitfield_type_i>
#endif
      framebuffer_barrier_bit;

    /// @var transform_feedback_barrier_bit
    /// @glconstwrap{TRANSFORM_FEEDBACK_BARRIER_BIT}
    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_TRANSFORM_FEEDBACK_BARRIER_BIT
      bitfield_type_c<GL_TRANSFORM_FEEDBACK_BARRIER_BIT>>
#else
      bitfield_type_i>
#endif
      transform_feedback_barrier_bit;

    /// @var atomic_counter_barrier_bit
    /// @glconstwrap{ATOMIC_COUNTER_BARRIER_BIT}
    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_ATOMIC_COUNTER_BARRIER_BIT
      bitfield_type_c<GL_ATOMIC_COUNTER_BARRIER_BIT>>
#else
      bitfield_type_i>
#endif
      atomic_counter_barrier_bit;

    /// @var shader_storage_barrier_bit
    /// @glconstwrap{SHADER_STORAGE_BARRIER_BIT}
    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_SHADER_STORAGE_BARRIER_BIT
      bitfield_type_c<GL_SHADER_STORAGE_BARRIER_BIT>>
#else
      bitfield_type_i>
#endif
      shader_storage_barrier_bit;

    /// @var all_barrier_bits
    /// @glconstwrap{ALL_BARRIER_BITS}
    opt_c_api_constant<
      mp_list<memory_barrier_bit>,
#ifdef GL_ALL_BARRIER_BITS
      bitfield_type_c<GL_ALL_BARRIER_BITS>>
#else
      bitfield_type_i>
#endif
      all_barrier_bits;

    /// @var read_only
    /// @glconstwrap{READ_ONLY}
    opt_c_api_constant<
      mp_list<access_specifier>,
#ifdef GL_READ_ONLY
      enum_type_c<GL_READ_ONLY>>
#else
      enum_type_i>
#endif
      read_only;

    /// @var write_only
    /// @glconstwrap{WRITE_ONLY}
    opt_c_api_constant<
      mp_list<access_specifier>,
#ifdef GL_WRITE_ONLY
      enum_type_c<GL_WRITE_ONLY>>
#else
      enum_type_i>
#endif
      write_only;

    /// @var read_Write
    /// @glconstwrap{READ_WRITE}
    opt_c_api_constant<
      mp_list<access_specifier>,
#ifdef GL_READ_WRITE
      enum_type_c<GL_READ_WRITE>>
#else
      enum_type_i>
#endif
      read_write;

    /// @var low_float
    /// @glconstwrap{LOW_FLOAT}
    opt_c_api_constant<
      mp_list<precision_type>,
#ifdef GL_LOW_FLOAT
      enum_type_c<GL_LOW_FLOAT>>
#else
      enum_type_i>
#endif
      low_float;

    /// @var medium_float
    /// @glconstwrap{MEDIUM_FLOAT}
    opt_c_api_constant<
      mp_list<precision_type>,
#ifdef GL_MEDIUM_FLOAT
      enum_type_c<GL_MEDIUM_FLOAT>>
#else
      enum_type_i>
#endif
      medium_float;

    /// @var high_float
    /// @glconstwrap{HIGH_FLOAT}
    opt_c_api_constant<
      mp_list<precision_type>,
#ifdef GL_HIGH_FLOAT
      enum_type_c<GL_HIGH_FLOAT>>
#else
      enum_type_i>
#endif
      high_float;

    /// @var low_int
    /// @glconstwrap{LOW_INT}
    opt_c_api_constant<
      mp_list<precision_type>,
#ifdef GL_LOW_INT
      enum_type_c<GL_LOW_INT>>
#else
      enum_type_i>
#endif
      low_int;

    /// @var medium_int
    /// @glconstwrap{MEDIUM_INT}
    opt_c_api_constant<
      mp_list<precision_type>,
#ifdef GL_MEDIUM_INT
      enum_type_c<GL_MEDIUM_INT>>
#else
      enum_type_i>
#endif
      medium_int;

    /// @var high_int
    /// @glconstwrap{HIGH_INT}
    opt_c_api_constant<
      mp_list<precision_type>,
#ifdef GL_HIGH_INT
      enum_type_c<GL_HIGH_INT>>
#else
      enum_type_i>
#endif
      high_int;

    /// @var buffer
    /// @glconstwrap{BUFFER}
    opt_c_api_constant<
      mp_list<oglp::object_type>,
#ifdef GL_BUFFER
      enum_type_c<GL_BUFFER>>
#else
      enum_type_i>
#endif
      buffer;

    /// @var framebuffer
    /// @glconstwrap{FRAMEBUFFER}
    opt_c_api_constant<
      mp_list<oglp::object_type>,
#ifdef GL_FRAMEBUFFER
      enum_type_c<GL_FRAMEBUFFER>>
#else
      enum_type_i>
#endif
      framebuffer;

    /// @var program_pipeline
    /// @glconstwrap{PROGRAM_PIPELINE}
    opt_c_api_constant<
      mp_list<oglp::object_type>,
#ifdef GL_PROGRAM_PIPELINE
      enum_type_c<GL_PROGRAM_PIPELINE>>
#else
      enum_type_i>
#endif
      program_pipeline;

    /// @var program
    /// @glconstwrap{PROGRAM}
    opt_c_api_constant<
      mp_list<oglp::object_type>,
#ifdef GL_PROGRAM
      enum_type_c<GL_PROGRAM>>
#else
      enum_type_i>
#endif
      program;

    /// @var query
    /// @glconstwrap{QUERY}
    opt_c_api_constant<
      mp_list<oglp::object_type>,
#ifdef GL_QUERY
      enum_type_c<GL_QUERY>>
#else
      enum_type_i>
#endif
      query;

    /// @var renderbuffer
    /// @glconstwrap{RENDERBUFFER}
    opt_c_api_constant<
      mp_list<oglp::object_type, renderbuffer_target>,
#ifdef GL_RENDERBUFFER
      enum_type_c<GL_RENDERBUFFER>>
#else
      enum_type_i>
#endif
      renderbuffer;

    /// @var sampler
    /// @glconstwrap{SAMPLER}
    opt_c_api_constant<
      mp_list<oglp::object_type>,
#ifdef GL_SAMPLER
      enum_type_c<GL_SAMPLER>>
#else
      enum_type_i>
#endif
      sampler;

    /// @var shader
    /// @glconstwrap{SHADER}
    opt_c_api_constant<
      mp_list<oglp::object_type>,
#ifdef GL_SHADER
      enum_type_c<GL_SHADER>>
#else
      enum_type_i>
#endif
      shader;

    /// @var texture
    /// @glconstwrap{TEXTURE}
    opt_c_api_constant<
      mp_list<oglp::object_type, matrix_mode>,
#ifdef GL_TEXTURE
      enum_type_c<GL_TEXTURE>>
#else
      enum_type_i>
#endif
      texture;

    /// @var transform_feedback
    /// @glconstwrap{TRANSFORM_FEEDBACK}
    opt_c_api_constant<
      mp_list<oglp::object_type, transform_feedback_target>,
#ifdef GL_TRANSFORM_FEEDBACK
      enum_type_c<GL_TRANSFORM_FEEDBACK>>
#else
      enum_type_i>
#endif
      transform_feedback;

    /// @var vertex_array
    /// @glconstwrap{VERTEX_ARRAY}
    opt_c_api_constant<
      mp_list<oglp::object_type, client_capability>,
#ifdef GL_VERTEX_ARRAY
      enum_type_c<GL_VERTEX_ARRAY>>
#else
      enum_type_i>
#endif
      vertex_array;

    /// @var vertex_shader
    /// @glconstwrap{VERTEX_SHADER}
    opt_c_api_constant<
      mp_list<oglp::shader_type, program_pipeline_parameter>,
#ifdef GL_VERTEX_SHADER
      enum_type_c<GL_VERTEX_SHADER>>
#else
      enum_type_i>
#endif
      vertex_shader;

    /// @var tess_control_shader
    /// @glconstwrap{TESS_CONTROL_SHADER}
    opt_c_api_constant<
      mp_list<oglp::shader_type, program_pipeline_parameter>,
#ifdef GL_TESS_CONTROL_SHADER
      enum_type_c<GL_TESS_CONTROL_SHADER>>
#else
      enum_type_i>
#endif
      tess_control_shader;

    /// @var tess_evaluation_shader
    /// @glconstwrap{TESS_EVALUATION_SHADER}
    opt_c_api_constant<
      mp_list<oglp::shader_type, program_pipeline_parameter>,
#ifdef GL_TESS_EVALUATION_SHADER
      enum_type_c<GL_TESS_EVALUATION_SHADER>>
#else
      enum_type_i>
#endif
      tess_evaluation_shader;

    /// @var geometry_shader
    /// @glconstwrap{GEOMETRY_SHADER}
    opt_c_api_constant<
      mp_list<oglp::shader_type, program_pipeline_parameter>,
#ifdef GL_GEOMETRY_SHADER
      enum_type_c<GL_GEOMETRY_SHADER>>
#else
      enum_type_i>
#endif
      geometry_shader;

    /// @var fragment_shader
    /// @glconstwrap{FRAGMENT_SHADER}
    opt_c_api_constant<
      mp_list<oglp::shader_type, program_pipeline_parameter>,
#ifdef GL_FRAGMENT_SHADER
      enum_type_c<GL_FRAGMENT_SHADER>>
#else
      enum_type_i>
#endif
      fragment_shader;

    /// @var compute_shader
    /// @glconstwrap{COMPUTE_SHADER}
    opt_c_api_constant<
      mp_list<oglp::shader_type>,
#ifdef GL_COMPUTE_SHADER
      enum_type_c<GL_COMPUTE_SHADER>>
#else
      enum_type_i>
#endif
      compute_shader;

    /// @var shader_include
    /// @glconstwrap{SHADER_INCLUDE}
    opt_c_api_constant<
      mp_list<named_string_kind>,
#ifdef GL_SHADER_INCLUDE_ARB
      enum_type_c<GL_SHADER_INCLUDE_ARB>>
#else
      enum_type_c<0x8DAE>>
#endif
      shader_include;

    /// @var sync_fence
    /// @glconstwrap{SYNC_FENCE}
    opt_c_api_constant<
      mp_list<sync_type>,
#ifdef GL_SYNC_FENCE
      enum_type_c<GL_SYNC_FENCE>>
#else
      enum_type_i>
#endif
      sync_fence;

    /// @var sync_gpu_commands_complete
    /// @glconstwrap{SYNC_GPU_COMMANDS_COMPLETE}
    opt_c_api_constant<
      mp_list<oglp::sync_condition, sync_parameter>,
#ifdef GL_SYNC_GPU_COMMANDS_COMPLETE
      enum_type_c<GL_SYNC_GPU_COMMANDS_COMPLETE>>
#else
      enum_type_i>
#endif
      sync_gpu_commands_complete;

    /// @var signaled
    /// @glconstwrap{SIGNALED}
    opt_c_api_constant<
      mp_list<oglp::sync_status>,
#ifdef GL_SIGNALED
      enum_type_c<GL_SIGNALED>>
#else
      enum_type_i>
#endif
      signaled;

    /// @var unsignaled
    /// @glconstwrap{UNSIGNALED}
    opt_c_api_constant<
      mp_list<oglp::sync_status>,
#ifdef GL_UNSIGNALED
      enum_type_c<GL_UNSIGNALED>>
#else
      enum_type_i>
#endif
      unsignaled;

    /// @var object_type
    /// @glconstwrap{OBJECT_TYPE}
    opt_c_api_constant<
      mp_list<sync_parameter>,
#ifdef GL_OBJECT_TYPE
      enum_type_c<GL_OBJECT_TYPE>>
#else
      enum_type_i>
#endif
      object_type;

    /// @var sync_status
    /// @glconstwrap{SYNC_STATUS}
    opt_c_api_constant<
      mp_list<sync_parameter>,
#ifdef GL_SYNC_STATUS
      enum_type_c<GL_SYNC_STATUS>>
#else
      enum_type_i>
#endif
      sync_status;

    /// @var sync_condition
    /// @glconstwrap{SYNC_CONDITION}
    opt_c_api_constant<
      mp_list<sync_parameter>,
#ifdef GL_SYNC_CONDITION
      enum_type_c<GL_SYNC_CONDITION>>
#else
      enum_type_i>
#endif
      sync_condition;

    /// @var sync_wait_result
    /// @glconstwrap{SYNC_WAIT_RESULT}
    opt_c_api_constant<
      mp_list<sync_wait_result>,
#ifdef GL_CONDITION_SATISFIED
      enum_type_c<GL_CONDITION_SATISFIED>>
#else
      enum_type_i>
#endif
      condition_satisfied;

    /// @var already_signaled
    /// @glconstwrap{ALREADY_SIGNALED}
    opt_c_api_constant<
      mp_list<sync_wait_result>,
#ifdef GL_ALREADY_SIGNALED
      enum_type_c<GL_ALREADY_SIGNALED>>
#else
      enum_type_i>
#endif
      already_signaled;

    /// @var timeout_expired
    /// @glconstwrap{TIMEOUT_EXPIRED}
    opt_c_api_constant<
      mp_list<sync_wait_result>,
#ifdef GL_TIMEOUT_EXPIRED
      enum_type_c<GL_TIMEOUT_EXPIRED>>
#else
      enum_type_i>
#endif
      timeout_expired;

    /// @var wait_failed
    /// @glconstwrap{WAIT_FAILED}
    opt_c_api_constant<
      mp_list<sync_wait_result>,
#ifdef GL_WAIT_FAILED
      enum_type_c<GL_WAIT_FAILED>>
#else
      enum_type_i>
#endif
      wait_failed;

    /// @var shader_type
    /// @glconstwrap{SHADER_TYPE}
    opt_c_api_constant<
      mp_list<shader_parameter>,
#ifdef GL_SHADER_TYPE
      enum_type_c<GL_SHADER_TYPE>,
#else
      enum_type_i,
#endif
      oglp::shader_type>
      shader_type;

    /// @var compute_shader_bit
    /// @glconstwrap{COMPUTE_SHADER_BIT}
    opt_c_api_constant<
      mp_list<program_stage_bit>,
#ifdef GL_COMPUTE_SHADER_BIT
      bitfield_type_c<GL_COMPUTE_SHADER_BIT>>
#else
      bitfield_type_i>
#endif
      compute_shader_bit;

    /// @var vertex_shader_bit
    /// @glconstwrap{VERTEX_SHADER_BIT}
    opt_c_api_constant<
      mp_list<program_stage_bit>,
#ifdef GL_VERTEX_SHADER_BIT
      bitfield_type_c<GL_VERTEX_SHADER_BIT>>
#else
      bitfield_type_i>
#endif
      vertex_shader_bit;

    /// @var tess_control_shader_bit
    /// @glconstwrap{TESS_CONTROL_SHADER_BIT}
    opt_c_api_constant<
      mp_list<program_stage_bit>,
#ifdef GL_TESS_CONTROL_SHADER_BIT
      bitfield_type_c<GL_TESS_CONTROL_SHADER_BIT>>
#else
      bitfield_type_i>
#endif
      tess_control_shader_bit;

    /// @var tess_evaluation_shader_bit
    /// @glconstwrap{TESS_EVALUATION_SHADER_BIT}
    opt_c_api_constant<
      mp_list<program_stage_bit>,
#ifdef GL_TESS_EVALUATION_SHADER_BIT
      bitfield_type_c<GL_TESS_EVALUATION_SHADER_BIT>>
#else
      bitfield_type_i>
#endif
      tess_evaluation_shader_bit;

    /// @var geometry_shader_bit
    /// @glconstwrap{GEOMETRY_SHADER_BIT}
    opt_c_api_constant<
      mp_list<program_stage_bit>,
#ifdef GL_GEOMETRY_SHADER_BIT
      bitfield_type_c<GL_GEOMETRY_SHADER_BIT>>
#else
      bitfield_type_i>
#endif
      geometry_shader_bit;

    /// @var fragment_shader_bit
    /// @glconstwrap{FRAGMENT_SHADER_BIT}
    opt_c_api_constant<
      mp_list<program_stage_bit>,
#ifdef GL_FRAGMENT_SHADER_BIT
      bitfield_type_c<GL_FRAGMENT_SHADER_BIT>>
#else
      bitfield_type_i>
#endif
      fragment_shader_bit;

    /// @var all_shader_bits
    /// @glconstwrap{ALL_SHADER_BITS}
    opt_c_api_constant<
      mp_list<program_stage_bit>,
#ifdef GL_ALL_SHADER_BITS
      bitfield_type_c<GL_ALL_SHADER_BITS>>
#else
      bitfield_type_i>
#endif
      all_shader_bits;

    /// @var active_subroutine_uniforms
    /// @glconstwrap{ACTIVE_SUBROUTINE_UNIFORMS}
    opt_c_api_constant<
      mp_list<program_stage_parameter>,
#ifdef GL_ACTIVE_SUBROUTINE_UNIFORMS
      enum_type_c<GL_ACTIVE_SUBROUTINE_UNIFORMS>>
#else
      enum_type_i>
#endif
      active_subroutine_uniforms;

    /// @var active_subroutine_uniform_locations
    /// @glconstwrap{ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS}
    opt_c_api_constant<
      mp_list<program_stage_parameter>,
#ifdef GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS
      enum_type_c<GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS>>
#else
      enum_type_i>
#endif
      active_subroutine_uniform_locations;

    /// @var active_subroutines
    /// @glconstwrap{ACTIVE_SUBROUTINES}
    opt_c_api_constant<
      mp_list<program_stage_parameter>,
#ifdef GL_ACTIVE_SUBROUTINES
      enum_type_c<GL_ACTIVE_SUBROUTINES>>
#else
      enum_type_i>
#endif
      active_subroutines;

    /// @var active_subroutine_uniform_max_length
    /// @glconstwrap{ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH}
    opt_c_api_constant<
      mp_list<program_stage_parameter>,
#ifdef GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH
      enum_type_c<GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH>>
#else
      enum_type_i>
#endif
      active_subroutine_uniform_max_length;

    /// @var active_subroutine_max_length
    /// @glconstwrap{ACTIVE_SUBROUTINE_MAX_LENGTH}
    opt_c_api_constant<
      mp_list<program_stage_parameter>,
#ifdef GL_ACTIVE_SUBROUTINE_MAX_LENGTH
      enum_type_c<GL_ACTIVE_SUBROUTINE_MAX_LENGTH>>
#else
      enum_type_i>
#endif
      active_subroutine_max_length;

    /// @var delete_status
    /// @glconstwrap{DELETE_STATUS}
    opt_c_api_constant<
      mp_list<shader_parameter, program_parameter>,
#ifdef GL_DELETE_STATUS
      enum_type_c<GL_DELETE_STATUS>,
#else
      enum_type_i,
#endif
      true_false>
      delete_status;

    /// @var compile_status
    /// @glconstwrap{COMPILE_STATUS}
    opt_c_api_constant<
      mp_list<shader_parameter>,
#ifdef GL_COMPILE_STATUS
      enum_type_c<GL_COMPILE_STATUS>,
#else
      enum_type_i,
#endif
      true_false>
      compile_status;

    /// @var info_log_length
    /// @glconstwrap{INFO_LOG_LENGTH}
    opt_c_api_constant<
      mp_list<shader_parameter, program_parameter, program_pipeline_parameter>,
#ifdef GL_INFO_LOG_LENGTH
      enum_type_c<GL_INFO_LOG_LENGTH>>
#else
      enum_type_i>
#endif
      info_log_length;

    /// @var shader_source_length
    /// @glconstwrap{SHADER_SOURCE_LENGTH}
    opt_c_api_constant<
      mp_list<shader_parameter>,
#ifdef GL_SHADER_SOURCE_LENGTH
      enum_type_c<GL_SHADER_SOURCE_LENGTH>>
#else
      enum_type_i>
#endif
      shader_source_length;

    /// @var spir_v_binary
    /// @glconstwrap{SPIR_V_BINARY}
    opt_c_api_constant<
      mp_list<shader_parameter>,
#ifdef GL_SPIR_V_BINARY
      enum_type_c<GL_SPIR_V_BINARY>,
#else
      enum_type_i,
#endif
      true_false>
      spir_v_binary;

    /// @var program_separable
    /// @glconstwrap{PROGRAM_SEPARABLE}
    opt_c_api_constant<
      mp_list<program_parameter>,
#ifdef GL_PROGRAM_SEPARABLE
      enum_type_c<GL_PROGRAM_SEPARABLE>,
#else
      enum_type_i,
#endif
      true_false>
      program_separable;

    /// @var completion_status
    /// @glconstwrap{COMPLETION_STATUS}
    opt_c_api_constant<
      mp_list<shader_parameter, program_parameter>,
#ifdef GL_COMPLETION_STATUS_ARB
      enum_type_c<GL_COMPLETION_STATUS_ARB>,
#else
      enum_type_i,
#endif
      true_false>
      completion_status;

    /// @var link_status
    /// @glconstwrap{LINK_STATUS}
    opt_c_api_constant<
      mp_list<program_parameter>,
#ifdef GL_LINK_STATUS
      enum_type_c<GL_LINK_STATUS>,
#else
      enum_type_i,
#endif
      true_false>
      link_status;

    /// @var validate_status
    /// @glconstwrap{VALIDATE_STATUS}
    opt_c_api_constant<
      mp_list<program_parameter>,
#ifdef GL_VALIDATE_STATUS
      enum_type_c<GL_VALIDATE_STATUS>,
#else
      enum_type_i,
#endif
      true_false>
      validate_status;

    /// @var attached_shaders
    /// @glconstwrap{ATTACHED_SHADERS}
    opt_c_api_constant<
      mp_list<program_parameter>,
#ifdef GL_ATTACHED_SHADERS
      enum_type_c<GL_ATTACHED_SHADERS>>
#else
      enum_type_i>
#endif
      attached_shaders;

    /// @var active_atomic_counter_buffers
    /// @glconstwrap{ACTIVE_ATOMIC_COUNTER_BUFFERS}
    opt_c_api_constant<
      mp_list<program_parameter>,
#ifdef GL_ACTIVE_ATOMIC_COUNTER_BUFFERS
      enum_type_c<GL_ACTIVE_ATOMIC_COUNTER_BUFFERS>>
#else
      enum_type_i>
#endif
      active_atomic_counter_buffers;

    /// @var active_attributes
    /// @glconstwrap{ACTIVE_ATTRIBUTES}
    opt_c_api_constant<
      mp_list<program_parameter>,
#ifdef GL_ACTIVE_ATTRIBUTES
      enum_type_c<GL_ACTIVE_ATTRIBUTES>>
#else
      enum_type_i>
#endif
      active_attributes;

    /// @var active_attribute_max_length
    /// @glconstwrap{ACTIVE_ATTRIBUTE_MAX_LENGTH}
    opt_c_api_constant<
      mp_list<program_parameter>,
#ifdef GL_ACTIVE_ATTRIBUTE_MAX_LENGTH
      enum_type_c<GL_ACTIVE_ATTRIBUTE_MAX_LENGTH>>
#else
      enum_type_i>
#endif
      active_attribute_max_length;

    /// @var active_uniforms
    /// @glconstwrap{ACTIVE_UNIFORMS}
    opt_c_api_constant<
      mp_list<program_parameter>,
#ifdef GL_ACTIVE_UNIFORMS
      enum_type_c<GL_ACTIVE_UNIFORMS>>
#else
      enum_type_i>
#endif
      active_uniforms;

    /// @var active_uniform_max_length
    /// @glconstwrap{ACTIVE_UNIFORM_MAX_LENGTH}
    opt_c_api_constant<
      mp_list<program_parameter>,
#ifdef GL_ACTIVE_UNIFORM_MAX_LENGTH
      enum_type_c<GL_ACTIVE_UNIFORM_MAX_LENGTH>>
#else
      enum_type_i>
#endif
      active_uniform_max_length;

    /// @var program_binary_length
    /// @glconstwrap{PROGRAM_BINARY_LENGTH}
    opt_c_api_constant<
      mp_list<program_parameter>,
#ifdef GL_PROGRAM_BINARY_LENGTH
      enum_type_c<GL_PROGRAM_BINARY_LENGTH>>
#else
      enum_type_i>
#endif
      program_binary_length;

    /// @var compute_work_group_size
    /// @glconstwrap{COMPUTE_WORK_GROUP_SIZE}
    opt_c_api_constant<
      mp_list<program_parameter>,
#ifdef GL_COMPUTE_WORK_GROUP_SIZE
      enum_type_c<GL_COMPUTE_WORK_GROUP_SIZE>>
#else
      enum_type_i>
#endif
      compute_work_group_size;

    /// @var transform_feedback_buffer_mode
    /// @glconstwrap{TRANSFORM_FEEDBACK_BUFFER_MODE}
    opt_c_api_constant<
      mp_list<program_parameter>,
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_MODE
      enum_type_c<GL_TRANSFORM_FEEDBACK_BUFFER_MODE>>
#else
      enum_type_i>
#endif
      transform_feedback_buffer_mode;

    /// @var transform_feedback_varyings
    /// @glconstwrap{TRANSFORM_FEEDBACK_VARYINGS}
    opt_c_api_constant<
      mp_list<program_parameter>,
#ifdef GL_TRANSFORM_FEEDBACK_VARYINGS
      enum_type_c<GL_TRANSFORM_FEEDBACK_VARYINGS>>
#else
      enum_type_i>
#endif
      transform_feedback_varyings;

    /// @var transform_feedback_varying_max_length
    /// @glconstwrap{TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH}
    opt_c_api_constant<
      mp_list<program_parameter>,
#ifdef GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH
      enum_type_c<GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH>>
#else
      enum_type_i>
#endif
      transform_feedback_varying_max_length;

    /// @var geometry_vertices_out
    /// @glconstwrap{GEOMETRY_VERTICES_OUT}
    opt_c_api_constant<
      mp_list<program_parameter>,
#ifdef GL_GEOMETRY_VERTICES_OUT
      enum_type_c<GL_GEOMETRY_VERTICES_OUT>>
#else
      enum_type_i>
#endif
      geometry_vertices_out;

    /// @var geometry_input_type
    /// @glconstwrap{GEOMETRY_INPUT_TYPE}
    opt_c_api_constant<
      mp_list<program_parameter>,
#ifdef GL_GEOMETRY_INPUT_TYPE
      enum_type_c<GL_GEOMETRY_INPUT_TYPE>>
#else
      enum_type_i>
#endif
      geometry_input_type;

    /// @var geometry_output_type
    /// @glconstwrap{GEOMETRY_OUTPUT_TYPE}
    opt_c_api_constant<
      mp_list<program_parameter>,
#ifdef GL_GEOMETRY_OUTPUT_TYPE
      enum_type_c<GL_GEOMETRY_OUTPUT_TYPE>>
#else
      enum_type_i>
#endif
      geometry_output_type;

    /// @var tess_gen_point_mode
    /// @glconstwrap{TESS_GEN_POINT_MODE}
    opt_c_api_constant<
      mp_list<program_parameter>,
#ifdef GL_TESS_GEN_POINT_MODE
      enum_type_c<GL_TESS_GEN_POINT_MODE>>
#else
      enum_type_i>
#endif
      tess_gen_point_mode;

    /// @var program_binary_format_mesa
    /// @glconstwrap{PROGRAM_BINARY_FORMAT_MESA}
    opt_c_api_constant<
      mp_list<program_binary_format>,
#ifdef GL_PROGRAM_BINARY_FORMAT_MESA
      enum_type_c<GL_PROGRAM_BINARY_FORMAT_MESA>>
#else
      enum_type_i>
#endif
      program_binary_format_mesa;

    /// @var active_program
    /// @glconstwrap{ACTIVE_PROGRAM}
    opt_c_api_constant<
      mp_list<program_pipeline_parameter>,
#ifdef GL_ACTIVE_PROGRAM
      enum_type_c<GL_ACTIVE_PROGRAM>>
#else
      enum_type_i>
#endif
      active_program;

    /// @var renderbuffer_width
    /// @glconstwrap{RENDERBUFFER_WIDTH}
    opt_c_api_constant<
      mp_list<renderbuffer_parameter>,
#ifdef GL_RENDERBUFFER_WIDTH
      enum_type_c<GL_RENDERBUFFER_WIDTH>>
#else
      enum_type_i>
#endif
      renderbuffer_width;

    /// @var renderbuffer_height
    /// @glconstwrap{RENDERBUFFER_HEIGHT}
    opt_c_api_constant<
      mp_list<renderbuffer_parameter>,
#ifdef GL_RENDERBUFFER_HEIGHT
      enum_type_c<GL_RENDERBUFFER_HEIGHT>>
#else
      enum_type_i>
#endif
      renderbuffer_height;

    /// @var renderbuffer_internal_format
    /// @glconstwrap{RENDERBUFFER_INTERNAL_FORMAT}
    opt_c_api_constant<
      mp_list<renderbuffer_parameter>,
#ifdef GL_RENDERBUFFER_INTERNAL_FORMAT
      enum_type_c<GL_RENDERBUFFER_INTERNAL_FORMAT>>
#else
      enum_type_i>
#endif
      renderbuffer_internal_format;

    /// @var renderbuffer_samples
    /// @glconstwrap{RENDERBUFFER_SAMPLES}
    opt_c_api_constant<
      mp_list<renderbuffer_parameter>,
#ifdef GL_RENDERBUFFER_SAMPLES
      enum_type_c<GL_RENDERBUFFER_SAMPLES>>
#else
      enum_type_i>
#endif
      renderbuffer_samples;

    /// @var renderbuffer_red_size
    /// @glconstwrap{RENDERBUFFER_RED_SIZE}
    opt_c_api_constant<
      mp_list<renderbuffer_parameter>,
#ifdef GL_RENDERBUFFER_RED_SIZE
      enum_type_c<GL_RENDERBUFFER_RED_SIZE>>
#else
      enum_type_i>
#endif
      renderbuffer_red_size;

    /// @var renderbuffer_green_size
    /// @glconstwrap{RENDERBUFFER_GREEN_SIZE}
    opt_c_api_constant<
      mp_list<renderbuffer_parameter>,
#ifdef GL_RENDERBUFFER_GREEN_SIZE
      enum_type_c<GL_RENDERBUFFER_GREEN_SIZE>>
#else
      enum_type_i>
#endif
      renderbuffer_green_size;

    /// @var renderbuffer_blue_size
    /// @glconstwrap{RENDERBUFFER_BLUE_SIZE}
    opt_c_api_constant<
      mp_list<renderbuffer_parameter>,
#ifdef GL_RENDERBUFFER_BLUE_SIZE
      enum_type_c<GL_RENDERBUFFER_BLUE_SIZE>>
#else
      enum_type_i>
#endif
      renderbuffer_blue_size;

    /// @var renderbuffer_alpha_size
    /// @glconstwrap{RENDERBUFFER_ALPHA_SIZE}
    opt_c_api_constant<
      mp_list<renderbuffer_parameter>,
#ifdef GL_RENDERBUFFER_ALPHA_SIZE
      enum_type_c<GL_RENDERBUFFER_ALPHA_SIZE>>
#else
      enum_type_i>
#endif
      renderbuffer_alpha_size;

    /// @var renderbuffer_depth_size
    /// @glconstwrap{RENDERBUFFER_DEPTH_SIZE}
    opt_c_api_constant<
      mp_list<renderbuffer_parameter>,
#ifdef GL_RENDERBUFFER_DEPTH_SIZE
      enum_type_c<GL_RENDERBUFFER_DEPTH_SIZE>>
#else
      enum_type_i>
#endif
      renderbuffer_depth_size;

    /// @var renderbuffer_stencil_size
    /// @glconstwrap{RENDERBUFFER_STENCIL_SIZE}
    opt_c_api_constant<
      mp_list<renderbuffer_parameter>,
#ifdef GL_RENDERBUFFER_STENCIL_SIZE
      enum_type_c<GL_RENDERBUFFER_STENCIL_SIZE>>
#else
      enum_type_i>
#endif
      renderbuffer_stencil_size;

    /// @var framebuffer_framebuffer
    /// @glconstwrap{FRAMEBUFFER_FRAMEBUFFER}
    opt_c_api_constant<
      mp_list<framebuffer_target>,
#ifdef GL_FRAMEBUFFER_FRAMEBUFFER
      enum_type_c<GL_FRAMEBUFFER_FRAMEBUFFER>>
#else
      enum_type_i>
#endif
      framebuffer_framebuffer;

    /// @var draw_framebuffer
    /// @glconstwrap{DRAW_FRAMEBUFFER}
    opt_c_api_constant<
      mp_list<framebuffer_target>,
#ifdef GL_DRAW_FRAMEBUFFER
      enum_type_c<GL_DRAW_FRAMEBUFFER>>
#else
      enum_type_i>
#endif
      draw_framebuffer;

    /// @var read_framebuffer
    /// @glconstwrap{READ_FRAMEBUFFER}
    opt_c_api_constant<
      mp_list<framebuffer_target>,
#ifdef GL_READ_FRAMEBUFFER
      enum_type_c<GL_READ_FRAMEBUFFER>>
#else
      enum_type_i>
#endif
      read_framebuffer;

    /// @var framebuffer_complete
    /// @glconstwrap{FRAMEBUFFER_COMPLETE}
    opt_c_api_constant<
      mp_list<framebuffer_status>,
#ifdef GL_FRAMEBUFFER_COMPLETE
      enum_type_c<GL_FRAMEBUFFER_COMPLETE>>
#else
      enum_type_i>
#endif
      framebuffer_complete;

    /// @var framebuffer_undefined
    /// @glconstwrap{FRAMEBUFFER_UNDEFINED}
    opt_c_api_constant<
      mp_list<framebuffer_status>,
#ifdef GL_FRAMEBUFFER_UNDEFINED
      enum_type_c<GL_FRAMEBUFFER_UNDEFINED>>
#else
      enum_type_i>
#endif
      framebuffer_undefined;

    /// @var framebuffer_incomplete_attachment
    /// @glconstwrap{FRAMEBUFFER_INCOMPLETE_ATTACHMENT}
    opt_c_api_constant<
      mp_list<framebuffer_status>,
#ifdef GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT
      enum_type_c<GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT>>
#else
      enum_type_i>
#endif
      framebuffer_incomplete_attachment;

    /// @var framebuffer_incomplete_missing_attachment
    /// @glconstwrap{FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT}
    opt_c_api_constant<
      mp_list<framebuffer_status>,
#ifdef GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT
      enum_type_c<GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT>>
#else
      enum_type_i>
#endif
      framebuffer_incomplete_missing_attachment;

    /// @var framebuffer_unsupported
    /// @glconstwrap{FRAMEBUFFER_UNSUPPORTED}
    opt_c_api_constant<
      mp_list<framebuffer_status>,
#ifdef GL_FRAMEBUFFER_UNSUPPORTED
      enum_type_c<GL_FRAMEBUFFER_UNSUPPORTED>>
#else
      enum_type_i>
#endif
      framebuffer_unsupported;

    /// @var framebuffer_incomplete_multisample
    /// @glconstwrap{FRAMEBUFFER_INCOMPLETE_MULTISAMPLE}
    opt_c_api_constant<
      mp_list<framebuffer_status>,
#ifdef GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE
      enum_type_c<GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE>>
#else
      enum_type_i>
#endif
      framebuffer_incomplete_multisample;

    /// @var framebuffer_incomplete_layer_targets
    /// @glconstwrap{FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS}
    opt_c_api_constant<
      mp_list<framebuffer_status>,
#ifdef GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS
      enum_type_c<GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS>>
#else
      enum_type_i>
#endif
      framebuffer_incomplete_layer_targets;

    /// @var framebuffer_default_width
    /// @glconstwrap{FRAMEBUFFER_DEFAULT_WIDTH}
    opt_c_api_constant<
      mp_list<framebuffer_parameter>,
#ifdef GL_FRAMEBUFFER_DEFAULT_WIDTH
      enum_type_c<GL_FRAMEBUFFER_DEFAULT_WIDTH>>
#else
      enum_type_i>
#endif
      framebuffer_default_width;

    /// @var framebuffer_default_height
    /// @glconstwrap{FRAMEBUFFER_DEFAULT_HEIGHT}
    opt_c_api_constant<
      mp_list<framebuffer_parameter>,
#ifdef GL_FRAMEBUFFER_DEFAULT_HEIGHT
      enum_type_c<GL_FRAMEBUFFER_DEFAULT_HEIGHT>>
#else
      enum_type_i>
#endif
      framebuffer_default_height;

    /// @var framebuffer_default_layers
    /// @glconstwrap{FRAMEBUFFER_DEFAULT_LAYERS}
    opt_c_api_constant<
      mp_list<framebuffer_parameter>,
#ifdef GL_FRAMEBUFFER_DEFAULT_LAYERS
      enum_type_c<GL_FRAMEBUFFER_DEFAULT_LAYERS>>
#else
      enum_type_i>
#endif
      framebuffer_default_layers;

    /// @var framebuffer_default_samples
    /// @glconstwrap{FRAMEBUFFER_DEFAULT_SAMPLES}
    opt_c_api_constant<
      mp_list<framebuffer_parameter>,
#ifdef GL_FRAMEBUFFER_DEFAULT_SAMPLES
      enum_type_c<GL_FRAMEBUFFER_DEFAULT_SAMPLES>>
#else
      enum_type_i>
#endif
      framebuffer_default_samples;

    /// @var framebuffer_default_fixed_sample_locations
    /// @glconstwrap{FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS}
    opt_c_api_constant<
      mp_list<framebuffer_parameter>,
#ifdef GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS
      enum_type_c<GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS>>
#else
      enum_type_i>
#endif
      framebuffer_default_fixed_sample_locations;

    /// @var framebuffer_attachment_red_size
    /// @glconstwrap{FRAMEBUFFER_ATTACHMENT_RED_SIZE}
    opt_c_api_constant<
      mp_list<framebuffer_attachment_parameter>,
#ifdef GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE
      enum_type_c<GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE>>
#else
      enum_type_i>
#endif
      framebuffer_attachment_red_size;

    /// @var framebuffer_attachment_green_size
    /// @glconstwrap{FRAMEBUFFER_ATTACHMENT_GREEN_SIZE}
    opt_c_api_constant<
      mp_list<framebuffer_attachment_parameter>,
#ifdef GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE
      enum_type_c<GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE>>
#else
      enum_type_i>
#endif
      framebuffer_attachment_green_size;

    /// @var framebuffer_attachment_blue_size
    /// @glconstwrap{FRAMEBUFFER_ATTACHMENT_BLUE_SIZE}
    opt_c_api_constant<
      mp_list<framebuffer_attachment_parameter>,
#ifdef GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE
      enum_type_c<GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE>>
#else
      enum_type_i>
#endif
      framebuffer_attachment_blue_size;

    /// @var framebuffer_attachment_alpha_size
    /// @glconstwrap{FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE}
    opt_c_api_constant<
      mp_list<framebuffer_attachment_parameter>,
#ifdef GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE
      enum_type_c<GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE>>
#else
      enum_type_i>
#endif
      framebuffer_attachment_alpha_size;

    /// @var framebuffer_attachment_depth_size
    /// @glconstwrap{FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE}
    opt_c_api_constant<
      mp_list<framebuffer_attachment_parameter>,
#ifdef GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE
      enum_type_c<GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE>>
#else
      enum_type_i>
#endif
      framebuffer_attachment_depth_size;

    /// @var framebuffer_attachment_stencil_size
    /// @glconstwrap{FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE}
    opt_c_api_constant<
      mp_list<framebuffer_attachment_parameter>,
#ifdef GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE
      enum_type_c<GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE>>
#else
      enum_type_i>
#endif
      framebuffer_attachment_stencil_size;

    /// @var framebuffer_attachment_component_type
    /// @glconstwrap{FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE}
    opt_c_api_constant<
      mp_list<framebuffer_attachment_parameter>,
#ifdef GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE
      enum_type_c<GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE>>
#else
      enum_type_i>
#endif
      framebuffer_attachment_component_type;

    /// @var framebuffer_attachment_color_encoding
    /// @glconstwrap{FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING}
    opt_c_api_constant<
      mp_list<framebuffer_attachment_parameter>,
#ifdef GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING
      enum_type_c<GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING>>
#else
      enum_type_i>
#endif
      framebuffer_attachment_color_encoding;

    /// @var framebuffer_attachment_object_type
    /// @glconstwrap{FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE}
    opt_c_api_constant<
      mp_list<framebuffer_attachment_parameter>,
#ifdef GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE
      enum_type_c<GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE>>
#else
      enum_type_i>
#endif
      framebuffer_attachment_object_type;

    /// @var framebuffer_attachment_object_name
    /// @glconstwrap{framebuffer_attachment_object_name}
    opt_c_api_constant<
      mp_list<framebuffer_attachment_parameter>,
#ifdef GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME
      enum_type_c<GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME>>
#else
      enum_type_i>
#endif
      framebuffer_attachment_object_name;

    /// @var framebuffer_attachment_texture_level
    /// @glconstwrap{FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL}
    opt_c_api_constant<
      mp_list<framebuffer_attachment_parameter>,
#ifdef GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL
      enum_type_c<GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL>>
#else
      enum_type_i>
#endif
      framebuffer_attachment_texture_level;

    /// @var framebuffer_attachment_texture_cube_map_face
    /// @glconstwrap{FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE}
    opt_c_api_constant<
      mp_list<framebuffer_attachment_parameter>,
#ifdef GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE
      enum_type_c<GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE>>
#else
      enum_type_i>
#endif
      framebuffer_attachment_texture_cube_map_face;

    /// @var framebuffer_attachment_layered
    /// @glconstwrap{FRAMEBUFFER_ATTACHMENT_LAYERED}
    opt_c_api_constant<
      mp_list<framebuffer_attachment_parameter>,
#ifdef GL_FRAMEBUFFER_ATTACHMENT_LAYERED
      enum_type_c<GL_FRAMEBUFFER_ATTACHMENT_LAYERED>,
#else
      enum_type_i,
#endif
      true_false>
      framebuffer_attachment_layered;

    /// @var framebuffer_attachment_texture_layer
    /// @glconstwrap{FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER}
    opt_c_api_constant<
      mp_list<framebuffer_attachment_parameter>,
#ifdef GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER
      enum_type_c<GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER>>
#else
      enum_type_i>
#endif
      framebuffer_attachment_texture_layer;

    /// @var color_attachment0
    /// @glconstwrap{COLOR_ATTACHMENT0}
    opt_c_api_constant<
      mp_list<framebuffer_attachment>,
#ifdef GL_COLOR_ATTACHMENT0
      enum_type_c<GL_COLOR_ATTACHMENT0>,
#else
      enum_type_i,
#endif
      nothing_t,
      true>
      color_attachment0;

    /// @var depth_attachment
    /// @glconstwrap{DEPTH_ATTACHMENT}
    opt_c_api_constant<
      mp_list<framebuffer_attachment>,
#ifdef GL_DEPTH_ATTACHMENT
      enum_type_c<GL_DEPTH_ATTACHMENT>>
#else
      enum_type_i>
#endif
      depth_attachment;

    /// @var stencil_attachment
    /// @glconstwrap{STENCIL_ATTACHMENT}
    opt_c_api_constant<
      mp_list<framebuffer_attachment>,
#ifdef GL_STENCIL_ATTACHMENT
      enum_type_c<GL_STENCIL_ATTACHMENT>>
#else
      enum_type_i>
#endif
      stencil_attachment;

    /// @var depth_stencil_attachment
    /// @glconstwrap{DEPTH_STENCIL_ATTACHMENT}
    opt_c_api_constant<
      mp_list<framebuffer_attachment>,
#ifdef GL_DEPTH_STENCIL_ATTACHMENT
      enum_type_c<GL_DEPTH_STENCIL_ATTACHMENT>>
#else
      enum_type_i>
#endif
      depth_stencil_attachment;

    /// @var color
    /// @glconstwrap{COLOR}
    opt_c_api_constant<
      mp_list<framebuffer_buffer, matrix_mode>,
#ifdef GL_COLOR
      enum_type_c<GL_COLOR>>
#else
      enum_type_i>
#endif
      color;

    /// @var depth
    /// @glconstwrap{DEPTH}
    opt_c_api_constant<
      mp_list<framebuffer_buffer, framebuffer_attachment>,
#ifdef GL_DEPTH
      enum_type_c<GL_DEPTH>>
#else
      enum_type_i>
#endif
      depth;

    /// @var stencil
    /// @glconstwrap{STENCIL}
    opt_c_api_constant<
      mp_list<framebuffer_buffer, framebuffer_attachment>,
#ifdef GL_STENCIL
      enum_type_c<GL_STENCIL>>
#else
      enum_type_i>
#endif
      stencil;

    /// @var array_buffer
    /// @glconstwrap{ARRAY_BUFFER}
    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_ARRAY_BUFFER
      enum_type_c<GL_ARRAY_BUFFER>>
#else
      enum_type_i>
#endif
      array_buffer;

    /// @var atomic_counter_buffer
    /// @glconstwrap{ATOMIC_COUNTER_BUFFER}
    opt_c_api_constant<
      mp_list<buffer_target, program_interface>,
#ifdef GL_ATOMIC_COUNTER_BUFFER
      enum_type_c<GL_ATOMIC_COUNTER_BUFFER>>
#else
      enum_type_i>
#endif
      atomic_counter_buffer;

    /// @var copy_read_buffer
    /// @glconstwrap{COPY_READ_BUFFER}
    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_COPY_READ_BUFFER
      enum_type_c<GL_COPY_READ_BUFFER>>
#else
      enum_type_i>
#endif
      copy_read_buffer;

    /// @var copy_write_buffer
    /// @glconstwrap{COPY_WRITE_BUFFER}
    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_COPY_WRITE_BUFFER
      enum_type_c<GL_COPY_WRITE_BUFFER>>
#else
      enum_type_i>
#endif
      copy_write_buffer;

    /// @var dispatch_indirect_buffer
    /// @glconstwrap{DISPATCH_INDIRECT_BUFFER}
    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_DISPATCH_INDIRECT_BUFFER
      enum_type_c<GL_DISPATCH_INDIRECT_BUFFER>>
#else
      enum_type_i>
#endif
      dispatch_indirect_buffer;

    /// @var draw_indirect_buffer
    /// @glconstwrap{DRAW_INDIRECT_BUFFER}
    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_DRAW_INDIRECT_BUFFER
      enum_type_c<GL_DRAW_INDIRECT_BUFFER>>
#else
      enum_type_i>
#endif
      draw_indirect_buffer;

    /// @var element_array_buffer
    /// @glconstwrap{ELEMENT_ARRAY_BUFFER}
    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_ELEMENT_ARRAY_BUFFER
      enum_type_c<GL_ELEMENT_ARRAY_BUFFER>>
#else
      enum_type_i>
#endif
      element_array_buffer;

    /// @var parameter_buffer
    /// @glconstwrap{PARAMETER_BUFFER}
    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_PARAMETER_BUFFER
      enum_type_c<GL_PARAMETER_BUFFER>>
#else
      enum_type_i>
#endif
      parameter_buffer;

    /// @var pixel_pack_buffer
    /// @glconstwrap{PIXEL_PACK_BUFFER}
    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_PIXEL_PACK_BUFFER
      enum_type_c<GL_PIXEL_PACK_BUFFER>>
#else
      enum_type_i>
#endif
      pixel_pack_buffer;

    /// @var pixel_unpack_buffer
    /// @glconstwrap{PIXEL_UNPACK_BUFFER}
    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_PIXEL_UNPACK_BUFFER
      enum_type_c<GL_PIXEL_UNPACK_BUFFER>>
#else
      enum_type_i>
#endif
      pixel_unpack_buffer;

    /// @var query_buffer
    /// @glconstwrap{QUERY_BUFFER}
    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_QUERY_BUFFER
      enum_type_c<GL_QUERY_BUFFER>>
#else
      enum_type_i>
#endif
      query_buffer;

    /// @var shader_storage_buffer
    /// @glconstwrap{SHADER_STORAGE_BUFFER}
    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_SHADER_STORAGE_BUFFER
      enum_type_c<GL_SHADER_STORAGE_BUFFER>>
#else
      enum_type_i>
#endif
      shader_storage_buffer;

    /// @var texture_buffer
    /// @glconstwrap{TEXTURE_BUFFER}
    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_TEXTURE_BUFFER
      enum_type_c<GL_TEXTURE_BUFFER>>
#else
      enum_type_i>
#endif
      texture_buffer;

    /// @var transform_feedback_buffer
    /// @glconstwrap{TRANSFORM_FEEDBACK_BUFFER}
    opt_c_api_constant<
      mp_list<buffer_target, program_interface>,
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER
      enum_type_c<GL_TRANSFORM_FEEDBACK_BUFFER>>
#else
      enum_type_i>
#endif
      transform_feedback_buffer;

    /// @var uniform_buffer
    /// @glconstwrap{UNIFORM_BUFFER}
    opt_c_api_constant<
      mp_list<buffer_target>,
#ifdef GL_UNIFORM_BUFFER
      enum_type_c<GL_UNIFORM_BUFFER>>
#else
      enum_type_i>
#endif
      uniform_buffer;

    /// @var buffer_access
    /// @glconstwrap{BUFFER_ACCESS}
    opt_c_api_constant<
      mp_list<buffer_parameter>,
#ifdef GL_BUFFER_ACCESS
      enum_type_c<GL_BUFFER_ACCESS>,
#else
      enum_type_i,
#endif
      access_specifier>
      buffer_access;

    /// @var buffer_access_flags
    /// @glconstwrap{BUFFER_ACCESS_FLAGS}
    opt_c_api_constant<
      mp_list<buffer_parameter>,
#ifdef GL_BUFFER_ACCESS_FLAGS
      enum_type_c<GL_BUFFER_ACCESS_FLAGS>,
#else
      enum_type_i,
#endif
      enum_bitfield<buffer_map_access_bit>>
      buffer_access_flags;

    /// @var buffer_immutable_storage
    /// @glconstwrap{BUFFER_IMMUTABLE_STORAGE}
    opt_c_api_constant<
      mp_list<buffer_parameter>,
#ifdef GL_BUFFER_IMMUTABLE_STORAGE
      enum_type_c<GL_BUFFER_IMMUTABLE_STORAGE>,
#else
      enum_type_i,
#endif
      true_false>
      buffer_immutable_storage;

    /// @var buffer_mapped
    /// @glconstwrap{BUFFER_MAPPED}
    opt_c_api_constant<
      mp_list<buffer_parameter>,
#ifdef GL_BUFFER_MAPPED
      enum_type_c<GL_BUFFER_MAPPED>,
#else
      enum_type_i,
#endif
      true_false>
      buffer_mapped;

    /// @var buffer_map_length
    /// @glconstwrap{buffer_map_length}
    opt_c_api_constant<
      mp_list<buffer_parameter>,
#ifdef GL_BUFFER_MAP_LENGTH
      enum_type_c<GL_BUFFER_MAP_LENGTH>>
#else
      enum_type_i>
#endif
      buffer_map_length;

    /// @var buffer_map_offset
    /// @glconstwrap{BUFFER_MAP_OFFSET}
    opt_c_api_constant<
      mp_list<buffer_parameter>,
#ifdef GL_BUFFER_MAP_OFFSET
      enum_type_c<GL_BUFFER_MAP_OFFSET>>
#else
      enum_type_i>
#endif
      buffer_map_offset;

    /// @var buffer_size
    /// @glconstwrap{BUFFER_SIZE}
    opt_c_api_constant<
      mp_list<buffer_parameter>,
#ifdef GL_BUFFER_SIZE
      enum_type_c<GL_BUFFER_SIZE>>
#else
      enum_type_i>
#endif
      buffer_size;

    /// @var buffer_storage_flags
    /// @glconstwrap{BUFFER_STORAGE_FLAGS}
    opt_c_api_constant<
      mp_list<buffer_parameter>,
#ifdef GL_BUFFER_STORAGE_FLAGS
      enum_type_c<GL_BUFFER_STORAGE_FLAGS>,
#else
      enum_type_i,
#endif
      enum_bitfield<buffer_storage_bit>>
      buffer_storage_flags;

    /// @var buffer_usage
    /// @glconstwrap{BUFFER_USAGE}
    opt_c_api_constant<
      mp_list<buffer_parameter>,
#ifdef GL_BUFFER_USAGE
      enum_type_c<GL_BUFFER_USAGE>,
#else
      enum_type_i,
#endif
      oglp::buffer_usage>
      buffer_usage;

    /// @var stream_draw
    /// @glconstwrap{STREAM_DRAW}
    opt_c_api_constant<
      mp_list<oglp::buffer_usage>,
#ifdef GL_STREAM_DRAW
      enum_type_c<GL_STREAM_DRAW>>
#else
      enum_type_i>
#endif
      stream_draw;

    /// @var stream_read
    /// @glconstwrap{STREAM_READ}
    opt_c_api_constant<
      mp_list<oglp::buffer_usage>,
#ifdef GL_STREAM_READ
      enum_type_c<GL_STREAM_READ>>
#else
      enum_type_i>
#endif
      stream_read;

    /// @var stream_copy
    /// @glconstwrap{STREAM_COPY}
    opt_c_api_constant<
      mp_list<oglp::buffer_usage>,
#ifdef GL_STREAM_COPY
      enum_type_c<GL_STREAM_COPY>>
#else
      enum_type_i>
#endif
      stream_copy;

    /// @var static_draw
    /// @glconstwrap{STATIC_DRAW}
    opt_c_api_constant<
      mp_list<oglp::buffer_usage>,
#ifdef GL_STATIC_DRAW
      enum_type_c<GL_STATIC_DRAW>>
#else
      enum_type_i>
#endif
      static_draw;

    /// @var static_read
    /// @glconstwrap{STATIC_READ}
    opt_c_api_constant<
      mp_list<oglp::buffer_usage>,
#ifdef GL_STATIC_READ
      enum_type_c<GL_STATIC_READ>>
#else
      enum_type_i>
#endif
      static_read;

    /// @var static_copy
    /// @glconstwrap{STATIC_COPY}
    opt_c_api_constant<
      mp_list<oglp::buffer_usage>,
#ifdef GL_STATIC_COPY
      enum_type_c<GL_STATIC_COPY>>
#else
      enum_type_i>
#endif
      static_copy;

    /// @var dynamic_draw
    /// @glconstwrap{DYNAMIC_DRAW}
    opt_c_api_constant<
      mp_list<oglp::buffer_usage>,
#ifdef GL_DYNAMIC_DRAW
      enum_type_c<GL_DYNAMIC_DRAW>>
#else
      enum_type_i>
#endif
      dynamic_draw;

    /// @var dynamic_read
    /// @glconstwrap{DYNAMIC_READ}
    opt_c_api_constant<
      mp_list<oglp::buffer_usage>,
#ifdef GL_DYNAMIC_READ
      enum_type_c<GL_DYNAMIC_READ>>
#else
      enum_type_i>
#endif
      dynamic_read;

    /// @var dynamic_copy
    /// @glconstwrap{DYNAMIC_COPY}
    opt_c_api_constant<
      mp_list<oglp::buffer_usage>,
#ifdef GL_DYNAMIC_COPY
      enum_type_c<GL_DYNAMIC_COPY>>
#else
      enum_type_i>
#endif
      dynamic_copy;

    /// @var map_read_bit
    /// @glconstwrap{MAP_READ_BIT}
    opt_c_api_constant<
      mp_list<buffer_map_access_bit, buffer_storage_bit>,
#ifdef GL_MAP_READ_BIT
      bitfield_type_c<GL_MAP_READ_BIT>>
#else
      bitfield_type_i>
#endif
      map_read_bit;

    /// @var map_write_bit
    /// @glconstwrap{MAP_WRITE_BIT}
    opt_c_api_constant<
      mp_list<buffer_map_access_bit, buffer_storage_bit>,
#ifdef GL_MAP_WRITE_BIT
      bitfield_type_c<GL_MAP_WRITE_BIT>>
#else
      bitfield_type_i>
#endif
      map_write_bit;

    /// @var map_persistent_bit
    /// @glconstwrap{MAP_PERSISTENT_BIT}
    opt_c_api_constant<
      mp_list<buffer_map_access_bit, buffer_storage_bit>,
#ifdef GL_MAP_PERSISTENT_BIT
      bitfield_type_c<GL_MAP_PERSISTENT_BIT>>
#else
      bitfield_type_i>
#endif
      map_persistent_bit;

    /// @var map_coherent_bit
    /// @glconstwrap{MAP_COHERENT_BIT}
    opt_c_api_constant<
      mp_list<buffer_map_access_bit, buffer_storage_bit>,
#ifdef GL_MAP_COHERENT_BIT
      bitfield_type_c<GL_MAP_COHERENT_BIT>>
#else
      bitfield_type_i>
#endif
      map_coherent_bit;

    /// @var map_invalidate_range_bit
    /// @glconstwrap{MAP_INVALIDATE_RANGE_BIT}
    opt_c_api_constant<
      mp_list<buffer_map_access_bit>,
#ifdef GL_MAP_INVALIDATE_RANGE_BIT
      bitfield_type_c<GL_MAP_INVALIDATE_RANGE_BIT>>
#else
      bitfield_type_i>
#endif
      map_invalidate_range_bit;

    /// @var map_invalidate_buffer_bit
    /// @glconstwrap{MAP_INVALIDATE_BUFFER_BIT}
    opt_c_api_constant<
      mp_list<buffer_map_access_bit>,
#ifdef GL_MAP_INVALIDATE_BUFFER_BIT
      bitfield_type_c<GL_MAP_INVALIDATE_BUFFER_BIT>>
#else
      bitfield_type_i>
#endif
      map_invalidate_buffer_bit;

    /// @var map_flush_explicit_bit
    /// @glconstwrap{MAP_FLUSH_EXPLICIT_BIT}
    opt_c_api_constant<
      mp_list<buffer_map_access_bit>,
#ifdef GL_MAP_FLUSH_EXPLICIT_BIT
      bitfield_type_c<GL_MAP_FLUSH_EXPLICIT_BIT>>
#else
      bitfield_type_i>
#endif
      map_flush_explicit_bit;

    /// @var map_unsynchronized_bit
    /// @glconstwrap{MAP_UNSYNCHRONIZED_BIT}
    opt_c_api_constant<
      mp_list<buffer_map_access_bit>,
#ifdef GL_MAP_UNSYNCHRONIZED_BIT
      bitfield_type_c<GL_MAP_UNSYNCHRONIZED_BIT>>
#else
      bitfield_type_i>
#endif
      map_unsynchronized_bit;

    /// @var dynamic_storage_bit
    /// @glconstwrap{DYNAMIC_STORAGE_BIT}
    opt_c_api_constant<
      mp_list<buffer_storage_bit>,
#ifdef GL_DYNAMIC_STORAGE_BIT
      bitfield_type_c<GL_DYNAMIC_STORAGE_BIT>>
#else
      bitfield_type_i>
#endif
      dynamic_storage_bit;

    /// @var client_storage_bit
    /// @glconstwrap{CLIENT_STORAGE_BIT}
    opt_c_api_constant<
      mp_list<buffer_storage_bit>,
#ifdef GL_CLIENT_STORAGE_BIT
      bitfield_type_c<GL_CLIENT_STORAGE_BIT>>
#else
      bitfield_type_i>
#endif
      client_storage_bit;

    /// @var sparse_storage_bit
    /// @glconstwrap{SPARSE_STORAGE_BIT}
    opt_c_api_constant<
      mp_list<buffer_storage_bit>,
#ifdef GL_SPARSE_STORAGE_BIT_ARB
      bitfield_type_c<GL_SPARSE_STORAGE_BIT_ARB>>
#else
      bitfield_type_i>
#endif
      sparse_storage_bit;

    /// @var texture0
    /// @glconstwrap{TEXTURE0}
    opt_c_api_constant<
      mp_list<oglp::texture_unit>,
#ifdef GL_TEXTURE0
      enum_type_c<GL_TEXTURE0>,
#else
      enum_type_i,
#endif
      nothing_t,
      true>
      texture0;

    /// @var texture_3d
    /// @glconstwrap{TEXTURE_3D}
    opt_c_api_constant<
      mp_list<oglp::texture_target>,
#ifdef GL_TEXTURE_3D
      enum_type_c<GL_TEXTURE_3D>>
#else
      enum_type_i>
#endif
      texture_3d;

    /// @var texture_2d
    /// @glconstwrap{TEXTURE_2D}
    opt_c_api_constant<
      mp_list<oglp::texture_target>,
#ifdef GL_TEXTURE_2D
      enum_type_c<GL_TEXTURE_2D>>
#else
      enum_type_i>
#endif
      texture_2d;

    /// @var texture_1d
    /// @glconstwrap{TEXTURE_1D}
    opt_c_api_constant<
      mp_list<oglp::texture_target>,
#ifdef GL_TEXTURE_1D
      enum_type_c<GL_TEXTURE_1D>>
#else
      enum_type_i>
#endif
      texture_1d;

    /// @var texture_2d_array
    /// @glconstwrap{TEXTURE_2D_ARRAY}
    opt_c_api_constant<
      mp_list<oglp::texture_target>,
#ifdef GL_TEXTURE_2D_ARRAY
      enum_type_c<GL_TEXTURE_2D_ARRAY>>
#else
      enum_type_i>
#endif
      texture_2d_array;

    /// @var texture_1d_array
    /// @glconstwrap{TEXTURE_1D_ARRAY}
    opt_c_api_constant<
      mp_list<oglp::texture_target>,
#ifdef GL_TEXTURE_1D_ARRAY
      enum_type_c<GL_TEXTURE_1D_ARRAY>>
#else
      enum_type_i>
#endif
      texture_1d_array;

    /// @var texture_rectangle
    /// @glconstwrap{TEXTURE_RECTANGLE}
    opt_c_api_constant<
      mp_list<oglp::texture_target>,
#ifdef GL_TEXTURE_RECTANGLE
      enum_type_c<GL_TEXTURE_RECTANGLE>>
#else
      enum_type_i>
#endif
      texture_rectangle;

    /// @var texture_cube_map
    /// @glconstwrap{TEXTURE_CUBE_MAP}
    opt_c_api_constant<
      mp_list<oglp::texture_target>,
#ifdef GL_TEXTURE_CUBE_MAP
      enum_type_c<GL_TEXTURE_CUBE_MAP>>
#else
      enum_type_i>
#endif
      texture_cube_map;

    /// @var texture_cube_map_array
    /// @glconstwrap{TEXTURE_CUBE_MAP_ARRAY}
    opt_c_api_constant<
      mp_list<oglp::texture_target>,
#ifdef GL_TEXTURE_CUBE_MAP_ARRAY
      enum_type_c<GL_TEXTURE_CUBE_MAP_ARRAY>>
#else
      enum_type_i>
#endif
      texture_cube_map_array;

    /// @var texture_2d_multisample
    /// @glconstwrap{TEXTURE_2D_MULTISAMPLE}
    opt_c_api_constant<
      mp_list<oglp::texture_target>,
#ifdef GL_TEXTURE_2D_MULTISAMPLE
      enum_type_c<GL_TEXTURE_2D_MULTISAMPLE>>
#else
      enum_type_i>
#endif
      texture_2d_multisample;

    /// @var texture_2d_multisample_array
    /// @glconstwrap{TEXTURE_2D_MULTISAMPLE_ARRAY}
    opt_c_api_constant<
      mp_list<oglp::texture_target>,
#ifdef GL_TEXTURE_2D_MULTISAMPLE_ARRAY
      enum_type_c<GL_TEXTURE_2D_MULTISAMPLE_ARRAY>>
#else
      enum_type_i>
#endif
      texture_2d_multisample_array;

    /// @var texture_cube_map_positive_x
    /// @glconstwrap{TEXTURE_CUBE_MAP_POSITIVE_X}
    opt_c_api_constant<
      mp_list<oglp::texture_target>,
#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_X
      enum_type_c<GL_TEXTURE_CUBE_MAP_POSITIVE_X>>
#else
      enum_type_i>
#endif
      texture_cube_map_positive_x;

    /// @var texture_cube_map_negative_x
    /// @glconstwrap{TEXTURE_CUBE_MAP_NEGATIVE_X}
    opt_c_api_constant<
      mp_list<oglp::texture_target>,
#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_X
      enum_type_c<GL_TEXTURE_CUBE_MAP_NEGATIVE_X>>
#else
      enum_type_i>
#endif
      texture_cube_map_negative_x;

    /// @var texture_cube_map_positive_y
    /// @glconstwrap{TEXTURE_CUBE_MAP_POSITIVE_Y}
    opt_c_api_constant<
      mp_list<oglp::texture_target>,
#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Y
      enum_type_c<GL_TEXTURE_CUBE_MAP_POSITIVE_Y>>
#else
      enum_type_i>
#endif
      texture_cube_map_positive_y;

    /// @var texture_cube_map_negative_y
    /// @glconstwrap{TEXTURE_CUBE_MAP_NEGATIVE_Y}
    opt_c_api_constant<
      mp_list<oglp::texture_target>,
#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
      enum_type_c<GL_TEXTURE_CUBE_MAP_NEGATIVE_Y>>
#else
      enum_type_i>
#endif
      texture_cube_map_negative_y;

    /// @var texture_cube_map_positive_z
    /// @glconstwrap{TEXTURE_CUBE_MAP_POSITIVE_Z}
    opt_c_api_constant<
      mp_list<oglp::texture_target>,
#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Z
      enum_type_c<GL_TEXTURE_CUBE_MAP_POSITIVE_Z>>
#else
      enum_type_i>
#endif
      texture_cube_map_positive_z;

    /// @var texture_cube_map_negative_z
    /// @glconstwrap{TEXTURE_CUBE_MAP_NEGATIVE_Z}
    opt_c_api_constant<
      mp_list<oglp::texture_target>,
#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
      enum_type_c<GL_TEXTURE_CUBE_MAP_NEGATIVE_Z>>
#else
      enum_type_i>
#endif
      texture_cube_map_negative_z;

    /// @var texture_external
    /// @glconstwrap{TEXTURE_EXTERNAL}
    opt_c_api_constant<mp_list<oglp::texture_target>, enum_type_c<0x8D65>>
      texture_external;

    /// @var compare_ref_to_texture
    /// @glconstwrap{COMPARE_REF_TO_TEXTURE}
    opt_c_api_constant<
      mp_list<oglp::texture_compare_mode>,
#ifdef GL_COMPARE_REF_TO_TEXTURE
      enum_type_c<GL_COMPARE_REF_TO_TEXTURE>>
#else
      enum_type_i>
#endif
      compare_ref_to_texture;

    /// @var nearest
    /// @glconstwrap{NEAREST}
    opt_c_api_constant<
      mp_list<
        oglp::texture_min_filter,
        oglp::texture_mag_filter,
        oglp::texture_filter,
        oglp::blit_filter>,
#ifdef GL_NEAREST
      enum_type_c<GL_NEAREST>>
#else
      enum_type_i>
#endif
      nearest;

    /// @var linear
    /// @glconstwrap{LINEAR}
    opt_c_api_constant<
      mp_list<
        oglp::texture_min_filter,
        oglp::texture_mag_filter,
        oglp::texture_filter,
        oglp::blit_filter>,
#ifdef GL_LINEAR
      enum_type_c<GL_LINEAR>>
#else
      enum_type_i>
#endif
      linear;

    /// @var nearest_mipmap_linear
    /// @glconstwrap{NEAREST_MIPMAP_LINEAR}
    opt_c_api_constant<
      mp_list<oglp::texture_min_filter>,
#ifdef GL_NEAREST_MIPMAP_NEAREST
      enum_type_c<GL_NEAREST_MIPMAP_NEAREST>>
#else
      enum_type_i>
#endif
      nearest_mipmap_nearest;

    /// @var nearest_mipmap_linear
    /// @glconstwrap{NEAREST_MIPMAP_LINEAR}
    opt_c_api_constant<
      mp_list<oglp::texture_min_filter>,
#ifdef GL_NEAREST_MIPMAP_LINEAR
      enum_type_c<GL_NEAREST_MIPMAP_LINEAR>>
#else
      enum_type_i>
#endif
      nearest_mipmap_linear;

    /// @var linear_mipmap_nearest
    /// @glconstwrap{LINEAR_MIPMAP_NEAREST}
    opt_c_api_constant<
      mp_list<oglp::texture_min_filter>,
#ifdef GL_LINEAR_MIPMAP_NEAREST
      enum_type_c<GL_LINEAR_MIPMAP_NEAREST>>
#else
      enum_type_i>
#endif
      linear_mipmap_nearest;

    /// @var linear_mipmap_linear
    /// @glconstwrap{LINEAR_MIPMAP_LINEAR}
    opt_c_api_constant<
      mp_list<oglp::texture_min_filter>,
#ifdef GL_LINEAR_MIPMAP_LINEAR
      enum_type_c<GL_LINEAR_MIPMAP_LINEAR>>
#else
      enum_type_i>
#endif
      linear_mipmap_linear;

    /// @var texture_width
    /// @glconstwrap{TEXTURE_WIDTH}
    opt_c_api_constant<
      mp_list<texture_level_parameter>,
#ifdef GL_TEXTURE_WIDTH
      enum_type_c<GL_TEXTURE_WIDTH>>
#else
      enum_type_i>
#endif
      texture_width;

    /// @var texture_height
    /// @glconstwrap{TEXTURE_HEIGHT}
    opt_c_api_constant<
      mp_list<texture_level_parameter>,
#ifdef GL_TEXTURE_HEIGHT
      enum_type_c<GL_TEXTURE_HEIGHT>>
#else
      enum_type_i>
#endif
      texture_height;

    /// @var texture_depth
    /// @glconstwrap{TEXTURE_DEPTH}
    opt_c_api_constant<
      mp_list<texture_level_parameter>,
#ifdef GL_TEXTURE_DEPTH
      enum_type_c<GL_TEXTURE_DEPTH>>
#else
      enum_type_i>
#endif
      texture_depth;

    /// @var texture_red_size
    /// @glconstwrap{TEXTURE_RED_SIZE}
    opt_c_api_constant<
      mp_list<texture_level_parameter>,
#ifdef GL_TEXTURE_RED_SIZE
      enum_type_c<GL_TEXTURE_RED_SIZE>>
#else
      enum_type_i>
#endif
      texture_red_size;

    /// @var texture_green_type
    /// @glconstwrap{TEXTURE_GREEN_TYPE}
    opt_c_api_constant<
      mp_list<texture_level_parameter>,
#ifdef GL_TEXTURE_GREEN_SIZE
      enum_type_c<GL_TEXTURE_GREEN_SIZE>>
#else
      enum_type_i>
#endif
      texture_green_size;

    /// @var texture_blue_size
    /// @glconstwrap{TEXTURE_BLUE_SIZE}
    opt_c_api_constant<
      mp_list<texture_level_parameter>,
#ifdef GL_TEXTURE_BLUE_SIZE
      enum_type_c<GL_TEXTURE_BLUE_SIZE>>
#else
      enum_type_i>
#endif
      texture_blue_size;

    /// @var texture_alpha_size
    /// @glconstwrap{TEXTURE_ALPHA_SIZE}
    opt_c_api_constant<
      mp_list<texture_level_parameter>,
#ifdef GL_TEXTURE_ALPHA_SIZE
      enum_type_c<GL_TEXTURE_ALPHA_SIZE>>
#else
      enum_type_i>
#endif
      texture_alpha_size;

    /// @var texture_depth_size
    /// @glconstwrap{TEXTURE_DEPTH_SIZE}
    opt_c_api_constant<
      mp_list<texture_level_parameter>,
#ifdef GL_TEXTURE_DEPTH_SIZE
      enum_type_c<GL_TEXTURE_DEPTH_SIZE>>
#else
      enum_type_i>
#endif
      texture_depth_size;

    opt_c_api_constant<
      mp_list<texture_level_parameter>,
#ifdef GL_TEXTURE_STENCIL_SIZE
      enum_type_c<GL_TEXTURE_STENCIL_SIZE>>
#else
      enum_type_i>
#endif
      texture_stencil_size;

    /// @var texture_shared_size
    /// @glconstwrap{TEXTURE_SHARED_SIZE}
    opt_c_api_constant<
      mp_list<texture_level_parameter>,
#ifdef GL_TEXTURE_SHARED_SIZE
      enum_type_c<GL_TEXTURE_SHARED_SIZE>>
#else
      enum_type_i>
#endif
      texture_shared_size;

    /// @var texture_red_type
    /// @glconstwrap{texture_red_type}
    opt_c_api_constant<
      mp_list<texture_level_parameter>,
#ifdef GL_TEXTURE_RED_TYPE
      enum_type_c<GL_TEXTURE_RED_TYPE>,
#else
      enum_type_i,
#endif
      pixel_data_type>
      texture_red_type;

    /// @var texture_green_type
    /// @glconstwrap{TEXTURE_GREEN_TYPE}
    opt_c_api_constant<
      mp_list<texture_level_parameter>,
#ifdef GL_TEXTURE_GREEN_TYPE
      enum_type_c<GL_TEXTURE_GREEN_TYPE>,
#else
      enum_type_i,
#endif
      pixel_data_type>
      texture_green_type;

    /// @var texture_blue_type
    /// @glconstwrap{TEXTURE_BLUE_TYPE}
    opt_c_api_constant<
      mp_list<texture_level_parameter>,
#ifdef GL_TEXTURE_BLUE_TYPE
      enum_type_c<GL_TEXTURE_BLUE_TYPE>,
#else
      enum_type_i,
#endif
      pixel_data_type>
      texture_blue_type;

    /// @var texture_alpha_type
    /// @glconstwrap{TEXTURE_ALPHA_TYPE}
    opt_c_api_constant<
      mp_list<texture_level_parameter>,
#ifdef GL_TEXTURE_ALPHA_TYPE
      enum_type_c<GL_TEXTURE_ALPHA_TYPE>,
#else
      enum_type_i,
#endif
      pixel_data_type>
      texture_alpha_type;

    /// @var texture_depth_type
    /// @glconstwrap{TEXTURE_DEPTH_TYPE}
    opt_c_api_constant<
      mp_list<texture_level_parameter>,
#ifdef GL_TEXTURE_DEPTH_TYPE
      enum_type_c<GL_TEXTURE_DEPTH_TYPE>,
#else
      enum_type_i,
#endif
      pixel_data_type>
      texture_depth_type;

    /// @var depth_stencil_texture_mode
    /// @glconstwrap{DEPTH_STENCIL_TEXTURE_MODE}
    opt_c_api_constant<
      mp_list<texture_parameter>,
#ifdef GL_DEPTH_STENCIL_TEXTURE_MODE
      enum_type_c<GL_DEPTH_STENCIL_TEXTURE_MODE>>
#else
      enum_type_i>
#endif
      depth_stencil_texture_mode;

    /// @var image_format_compatibility_type
    /// @glconstwrap{IMAGE_FORMAT_COMPATIBILITY_TYPE}
    opt_c_api_constant<
      mp_list<texture_parameter, internal_format_parameter>,
#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
      enum_type_c<GL_IMAGE_FORMAT_COMPATIBILITY_TYPE>>
#else
      enum_type_i>
#endif
      image_format_compatibility_type;

    /// @var texture_base_level
    /// @glconstwrap{TEXTURE_BASE_LEVEL}
    opt_c_api_constant<
      mp_list<texture_parameter>,
#ifdef GL_TEXTURE_BASE_LEVEL
      enum_type_c<GL_TEXTURE_BASE_LEVEL>>
#else
      enum_type_i>
#endif
      texture_base_level;

    /// @var texture_border_color
    /// @glconstwrap{TEXTURE_BORDER_COLOR}
    opt_c_api_constant<
      mp_list<texture_parameter, sampler_parameter>,
#ifdef GL_TEXTURE_BORDER_COLOR
      enum_type_c<GL_TEXTURE_BORDER_COLOR>>
#else
      enum_type_i>
#endif
      texture_border_color;

    /// @var texture_compare_mode
    /// @glconstwrap{TEXTURE_COMPARE_MODE}
    opt_c_api_constant<
      mp_list<texture_parameter, sampler_parameter>,
#ifdef GL_TEXTURE_COMPARE_MODE
      enum_type_c<GL_TEXTURE_COMPARE_MODE>,
#else
      enum_type_i,
#endif
      oglp::texture_compare_mode>
      texture_compare_mode;

    /// @var texture_compare_func
    /// @glconstwrap{TEXTURE_COMPARE_FUNC}
    opt_c_api_constant<
      mp_list<texture_parameter, sampler_parameter>,
#ifdef GL_TEXTURE_COMPARE_FUNC
      enum_type_c<GL_TEXTURE_COMPARE_FUNC>,
#else
      enum_type_i,
#endif
      oglp::compare_function>
      texture_compare_func;

    /// @var texture_internal_format
    /// @glconstwrap{TEXTURE_INTERNAL_FORMAT}
    opt_c_api_constant<
      mp_list<texture_level_parameter>,
#ifdef GL_TEXTURE_INTERNAL_FORMAT
      enum_type_c<GL_TEXTURE_INTERNAL_FORMAT>,
#else
      enum_type_i,
#endif
      pixel_internal_format>
      texture_internal_format;

    /// @var texture_immutable_format
    /// @glconstwrap{TEXTURE_IMMUTABLE_FORMAT}
    opt_c_api_constant<
      mp_list<texture_parameter>,
#ifdef GL_TEXTURE_IMMUTABLE_FORMAT
      enum_type_c<GL_TEXTURE_IMMUTABLE_FORMAT>,
#else
      enum_type_i,
#endif
      true_false>
      texture_immutable_format;

    /// @var texture_immutable_levels
    /// @glconstwrap{TEXTURE_IMMUTABLE_LEVELS}
    opt_c_api_constant<
      mp_list<texture_parameter>,
#ifdef GL_TEXTURE_IMMUTABLE_LEVELS
      enum_type_c<GL_TEXTURE_IMMUTABLE_LEVELS>>
#else
      enum_type_i>
#endif
      texture_immutable_levels;

    /// @var texture_lod_bias
    /// @glconstwrap{TEXTURE_LOD_BIAS}
    opt_c_api_constant<
      mp_list<texture_parameter, sampler_parameter>,
#ifdef GL_TEXTURE_LOD_BIAS
      enum_type_c<GL_TEXTURE_LOD_BIAS>>
#else
      enum_type_i>
#endif
      texture_lod_bias;

    /// @var texture_mag_filter
    /// @glconstwrap{TEXTURE_MAG_FILTER}
    opt_c_api_constant<
      mp_list<texture_parameter, sampler_parameter>,
#ifdef GL_TEXTURE_MAG_FILTER
      enum_type_c<GL_TEXTURE_MAG_FILTER>,
#else
      enum_type_i,
#endif
      oglp::texture_mag_filter>
      texture_mag_filter;

    /// @var texture_max_level
    /// @glconstwrap{TEXTURE_MAX_LEVEL}
    opt_c_api_constant<
      mp_list<texture_parameter>,
#ifdef GL_TEXTURE_MAX_LEVEL
      enum_type_c<GL_TEXTURE_MAX_LEVEL>>
#else
      enum_type_i>
#endif
      texture_max_level;

    /// @var texture_max_lod
    /// @glconstwrap{TEXTURE_MAX_LOD}
    opt_c_api_constant<
      mp_list<texture_parameter, sampler_parameter>,
#ifdef GL_TEXTURE_MAX_LOD
      enum_type_c<GL_TEXTURE_MAX_LOD>>
#else
      enum_type_i>
#endif
      texture_max_lod;

    /// @var texture_min_filter
    /// @glconstwrap{TEXTURE_MIN_FILTER}
    opt_c_api_constant<
      mp_list<texture_parameter, sampler_parameter>,
#ifdef GL_TEXTURE_MIN_FILTER
      enum_type_c<GL_TEXTURE_MIN_FILTER>,
#else
      enum_type_i,
#endif
      oglp::texture_min_filter>
      texture_min_filter;

    /// @var texture_min_lod
    /// @glconstwrap{TEXTURE_MIN_LOD}
    opt_c_api_constant<
      mp_list<texture_parameter, sampler_parameter>,
#ifdef GL_TEXTURE_MIN_LOD
      enum_type_c<GL_TEXTURE_MIN_LOD>>
#else
      enum_type_i>
#endif
      texture_min_lod;

    /// @var texture_swizzle_r
    /// @glconstwrap{TEXTURE_SWIZZLE_R}
    opt_c_api_constant<
      mp_list<texture_parameter, texture_swizzle_mode>,
#ifdef GL_TEXTURE_SWIZZLE_R
      enum_type_c<GL_TEXTURE_SWIZZLE_R>,
#else
      enum_type_i,
#endif
      texture_swizzle_mode>
      texture_swizzle_r;

    /// @var texture_swizzle_g
    /// @glconstwrap{TEXTURE_SWIZZLE_G}
    opt_c_api_constant<
      mp_list<texture_parameter, texture_swizzle_mode>,
#ifdef GL_TEXTURE_SWIZZLE_G
      enum_type_c<GL_TEXTURE_SWIZZLE_G>,
#else
      enum_type_i,
#endif
      texture_swizzle_mode>
      texture_swizzle_g;

    /// @var texture_swizzle_b
    /// @glconstwrap{TEXTURE_SWIZZLE_B}
    opt_c_api_constant<
      mp_list<texture_parameter, texture_swizzle_mode>,
#ifdef GL_TEXTURE_SWIZZLE_B
      enum_type_c<GL_TEXTURE_SWIZZLE_B>,
#else
      enum_type_i,
#endif
      texture_swizzle_mode>
      texture_swizzle_b;

    /// @var texture_swizzle_a
    /// @glconstwrap{TEXTURE_SWIZZLE_A}
    opt_c_api_constant<
      mp_list<texture_parameter, texture_swizzle_mode>,
#ifdef GL_TEXTURE_SWIZZLE_A
      enum_type_c<GL_TEXTURE_SWIZZLE_A>,
#else
      enum_type_i,
#endif
      texture_swizzle_mode>
      texture_swizzle_a;

    /// @var texture_swizzle_rgba
    /// @glconstwrap{TEXTURE_SWIZZLE_RGBA}
    opt_c_api_constant<
      mp_list<texture_parameter, texture_swizzle_mode>,
#ifdef GL_TEXTURE_SWIZZLE_RGBA
      enum_type_c<GL_TEXTURE_SWIZZLE_RGBA>>
#else
      enum_type_i>
#endif
      texture_swizzle_rgba;

    /// @var texture_target
    /// @glconstwrap{TEXTURE_TARGET}
    opt_c_api_constant<
      mp_list<texture_parameter>,
#ifdef GL_TEXTURE_TARGET
      enum_type_c<GL_TEXTURE_TARGET>,
#else
      enum_type_i,
#endif
      oglp::texture_target>
      texture_target;

    /// @var texture_view_min_layer
    /// @glconstwrap{TEXTURE_VIEW_MIN_LAYER}
    opt_c_api_constant<
      mp_list<texture_parameter>,
#ifdef GL_TEXTURE_VIEW_MIN_LAYER
      enum_type_c<GL_TEXTURE_VIEW_MIN_LAYER>>
#else
      enum_type_i>
#endif
      texture_view_min_layer;

    /// @var texture_view_min_level
    /// @glconstwrap{TEXTURE_VIEW_MIN_LEVEL}
    opt_c_api_constant<
      mp_list<texture_parameter>,
#ifdef GL_TEXTURE_VIEW_MIN_LEVEL
      enum_type_c<GL_TEXTURE_VIEW_MIN_LEVEL>>
#else
      enum_type_i>
#endif
      texture_view_min_level;

    /// @var texture_view_num_layers
    /// @glconstwrap{TEXTURE_VIEW_NUM_LAYERS}
    opt_c_api_constant<
      mp_list<texture_parameter>,
#ifdef GL_TEXTURE_VIEW_NUM_LAYERS
      enum_type_c<GL_TEXTURE_VIEW_NUM_LAYERS>>
#else
      enum_type_i>
#endif
      texture_view_num_layers;

    /// @var texture_view_num_levels
    /// @glconstwrap{TEXTURE_VIEW_NUM_LEVELS}
    opt_c_api_constant<
      mp_list<texture_parameter>,
#ifdef GL_TEXTURE_VIEW_NUM_LEVELS
      enum_type_c<GL_TEXTURE_VIEW_NUM_LEVELS>>
#else
      enum_type_i>
#endif
      texture_view_num_levels;

    /// @var texture_fixed_sample_locations
    /// @glconstwrap{TEXTURE_FIXED_SAMPLE_LOCATIONS}
    opt_c_api_constant<
      mp_list<texture_level_parameter>,
#ifdef GL_TEXTURE_FIXED_SAMPLE_LOCATIONS
      enum_type_c<GL_TEXTURE_FIXED_SAMPLE_LOCATIONS>,
#else
      enum_type_i,
#endif
      true_false>
      texture_fixed_sample_locations;

    /// @var texture_wrap_s
    /// @glconstwrap{TEXTURE_WRAP_S}
    opt_c_api_constant<
      mp_list<texture_parameter, texture_wrap_coord, sampler_parameter>,
#ifdef GL_TEXTURE_WRAP_S
      enum_type_c<GL_TEXTURE_WRAP_S>,
#else
      enum_type_i,
#endif
      oglp::texture_wrap_mode>
      texture_wrap_s;

    /// @var texture_wrap_t
    /// @glconstwrap{TEXTURE_WRAP_T}
    opt_c_api_constant<
      mp_list<texture_parameter, texture_wrap_coord, sampler_parameter>,
#ifdef GL_TEXTURE_WRAP_T
      enum_type_c<GL_TEXTURE_WRAP_T>,
#else
      enum_type_i,
#endif
      oglp::texture_wrap_mode>
      texture_wrap_t;

    /// @var texture_wrap_r
    /// @glconstwrap{TEXTURE_WRAP_R}
    opt_c_api_constant<
      mp_list<texture_parameter, texture_wrap_coord, sampler_parameter>,
#ifdef GL_TEXTURE_WRAP_R
      enum_type_c<GL_TEXTURE_WRAP_R>,
#else
      enum_type_i,
#endif
      oglp::texture_wrap_mode>
      texture_wrap_r;

    /// @var clamp_to_edge
    /// @glconstwrap{CLAMP_TO_EDGE}
    opt_c_api_constant<
      mp_list<texture_wrap_mode>,
#ifdef GL_CLAMP_TO_EDGE
      enum_type_c<GL_CLAMP_TO_EDGE>>
#else
      enum_type_i>
#endif
      clamp_to_edge;

    /// @var repeat
    /// @glconstwrap{REPEAT}
    opt_c_api_constant<
      mp_list<texture_wrap_mode>,
#ifdef GL_REPEAT
      enum_type_c<GL_REPEAT>>
#else
      enum_type_i>
#endif
      repeat;

    /// @var clamp_to_border
    /// @glconstwrap{CLAMP_TO_BORDER}
    opt_c_api_constant<
      mp_list<texture_wrap_mode>,
#ifdef GL_CLAMP_TO_BORDER
      enum_type_c<GL_CLAMP_TO_BORDER>>
#else
      enum_type_i>
#endif
      clamp_to_border;

    /// @var mirrored_repeat
    /// @glconstwrap{MIRRORED_REPEAT}
    opt_c_api_constant<
      mp_list<texture_wrap_mode>,
#ifdef GL_MIRRORED_REPEAT
      enum_type_c<GL_MIRRORED_REPEAT>>
#else
      enum_type_i>
#endif
      mirrored_repeat;

    /// @var mirror_clamp_to_edge
    /// @glconstwrap{MIRROR_CLAMP_TO_EDGE}
    opt_c_api_constant<
      mp_list<texture_wrap_mode>,
#ifdef GL_MIRROR_CLAMP_TO_EDGE
      enum_type_c<GL_MIRROR_CLAMP_TO_EDGE>>
#else
      enum_type_i>
#endif
      mirror_clamp_to_edge;

    /// @var red
    /// @glconstwrap{RED}
    opt_c_api_constant<
      mp_list<texture_swizzle_mode, pixel_internal_format, pixel_format>,
#ifdef GL_RED
      enum_type_c<GL_RED>>
#else
      enum_type_i>
#endif
      red;

    /// @var green
    /// @glconstwrap{GREEN}
    opt_c_api_constant<
      mp_list<texture_swizzle_mode, pixel_format>,
#ifdef GL_GREEN
      enum_type_c<GL_GREEN>>
#else
      enum_type_i>
#endif
      green;

    /// @var blue
    /// @glconstwrap{BLUE}
    opt_c_api_constant<
      mp_list<texture_swizzle_mode, pixel_format>,
#ifdef GL_BLUE
      enum_type_c<GL_BLUE>>
#else
      enum_type_i>
#endif
      blue;

    /// @var alpha
    /// @glconstwrap{ALPHA}
    opt_c_api_constant<
      mp_list<texture_swizzle_mode, path_color_format_nv>,
#ifdef GL_ALPHA
      enum_type_c<GL_ALPHA>>
#else
      enum_type_i>
#endif
      alpha;

    /// @var zero
    /// @glconstwrap{ZERO}
    opt_c_api_constant<
      mp_list<texture_swizzle_mode, blend_function, stencil_operation>,
#ifdef GL_ZERO
      enum_type_c<GL_ZERO>>
#else
      enum_type_i>
#endif
      zero;

    /// @var one
    /// @glconstwrap{ONE}
    opt_c_api_constant<
      mp_list<texture_swizzle_mode, blend_function>,
#ifdef GL_ONE
      enum_type_c<GL_ONE>>
#else
      enum_type_i>
#endif
      one;

    /// @var primitives_generated
    /// @glconstwrap{PRIMITIVES_GENERATED}
    opt_c_api_constant<
      mp_list<query_target>,
#ifdef GL_PRIMITIVES_GENERATED
      enum_type_c<GL_PRIMITIVES_GENERATED>>
#else
      enum_type_i>
#endif
      primitives_generated;

    /// @var transform_feedback_primitives_written
    /// @glconstwrap{TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN}
    opt_c_api_constant<
      mp_list<query_target>,
#ifdef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN
      enum_type_c<GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN>>
#else
      enum_type_i>
#endif
      transform_feedback_primitives_written;

    /// @var transform_feedback_overflow
    /// @glconstwrap{TRANSFORM_FEEDBACK_OVERFLOW}
    opt_c_api_constant<
      mp_list<query_target>,
#ifdef GL_TRANSFORM_FEEDBACK_OVERFLOW
      enum_type_c<GL_TRANSFORM_FEEDBACK_OVERFLOW>>
#else
      enum_type_i>
#endif
      transform_feedback_overflow;

    /// @var transform_feedback_stream_overflow
    /// @glconstwrap{TRANSFORM_FEEDBACK_STREAM_OVERFLOW}
    opt_c_api_constant<
      mp_list<query_target>,
#ifdef GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW
      enum_type_c<GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW>>
#else
      enum_type_i>
#endif
      transform_feedback_stream_overflow;

    /// @var samples_passed
    /// @glconstwrap{SAMPLES_PASSED}
    opt_c_api_constant<
      mp_list<query_target>,
#ifdef GL_SAMPLES_PASSED
      enum_type_c<GL_SAMPLES_PASSED>>
#else
      enum_type_i>
#endif
      samples_passed;

    /// @var any_samples_passed
    /// @glconstwrap{ANY_SAMPLES_PASSED}
    opt_c_api_constant<
      mp_list<query_target>,
#ifdef GL_ANY_SAMPLES_PASSED
      enum_type_c<GL_ANY_SAMPLES_PASSED>>
#else
      enum_type_i>
#endif
      any_samples_passed;

    /// @var any_samples_passed_conservative
    /// @glconstwrap{ANY_SAMPLES_PASSED_CONSERVATIVE}
    opt_c_api_constant<
      mp_list<query_target>,
#ifdef GL_ANY_SAMPLES_PASSED_CONSERVATIVE
      enum_type_c<GL_ANY_SAMPLES_PASSED_CONSERVATIVE>>
#else
      enum_type_i>
#endif
      any_samples_passed_conservative;

    /// @var time_elapsed
    /// @glconstwrap{TIME_ELAPSED}
    opt_c_api_constant<
      mp_list<query_target>,
#ifdef GL_TIME_ELAPSED
      enum_type_c<GL_TIME_ELAPSED>>
#else
      enum_type_i>
#endif
      time_elapsed;

    /// @var timestamp
    /// @glconstwrap{TIMESTAMP}
    opt_c_api_constant<
      mp_list<query_target, counter_query_target>,
#ifdef GL_TIMESTAMP
      enum_type_c<GL_TIMESTAMP>>
#else
      enum_type_i>
#endif
      timestamp;

    /// @var vertices_submitted
    /// @glconstwrap{VERTICES_SUBMITTED}
    opt_c_api_constant<
      mp_list<query_target>,
#ifdef GL_VERTICES_SUBMITTED
      enum_type_c<GL_VERTICES_SUBMITTED>>
#else
      enum_type_i>
#endif
      vertices_submitted;

    /// @var primitives_submitted
    /// @glconstwrap{PRIMITIVES_SUBMITTED}
    opt_c_api_constant<
      mp_list<query_target>,
#ifdef GL_PRIMITIVES_SUBMITTED
      enum_type_c<GL_PRIMITIVES_SUBMITTED>>
#else
      enum_type_i>
#endif
      primitives_submitted;

    /// @var vertex_shader_invocations
    /// @glconstwrap{VERTEX_SHADER_INVOCATIONS}
    opt_c_api_constant<
      mp_list<query_target>,
#ifdef GL_VERTEX_SHADER_INVOCATIONS
      enum_type_c<GL_VERTEX_SHADER_INVOCATIONS>>
#else
      enum_type_i>
#endif
      vertex_shader_invocations;

    /// @var tess_control_shader_patches
    /// @glconstwrap{TESS_CONTROL_SHADER_PATCHES}
    opt_c_api_constant<
      mp_list<query_target>,
#ifdef GL_TESS_CONTROL_SHADER_PATCHES
      enum_type_c<GL_TESS_CONTROL_SHADER_PATCHES>>
#else
      enum_type_i>
#endif
      tess_control_shader_patches;

    /// @var tess_evaluation_shader_invocations
    /// @glconstwrap{TESS_EVALUATION_SHADER_INVOCATIONS}
    opt_c_api_constant<
      mp_list<query_target>,
#ifdef GL_TESS_EVALUATION_SHADER_INVOCATIONS
      enum_type_c<GL_TESS_EVALUATION_SHADER_INVOCATIONS>>
#else
      enum_type_i>
#endif
      tess_evaluation_shader_invocations;

    /// @var geometry_shader_invocations
    /// @glconstwrap{GEOMETRY_SHADER_INVOCATIONS}
    opt_c_api_constant<
      mp_list<query_target>,
#ifdef GL_GEOMETRY_SHADER_INVOCATIONS
      enum_type_c<GL_GEOMETRY_SHADER_INVOCATIONS>>
#else
      enum_type_i>
#endif
      geometry_shader_invocations;

    /// @var geometry_shader_primitives_emitted
    /// @glconstwrap{GEOMETRY_SHADER_PRIMITIVES_EMITTED}
    opt_c_api_constant<
      mp_list<query_target>,
#ifdef GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED
      enum_type_c<GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED>>
#else
      enum_type_i>
#endif
      geometry_shader_primitives_emitted;

    /// @var clipping_input_primitives
    /// @glconstwrap{CLIPPING_INPUT_PRIMITIVES}
    opt_c_api_constant<
      mp_list<query_target>,
#ifdef GL_CLIPPING_INPUT_PRIMITIVES
      enum_type_c<GL_CLIPPING_INPUT_PRIMITIVES>>
#else
      enum_type_i>
#endif
      clipping_input_primitives;

    /// @var clipping_output_primitives
    /// @glconstwrap{CLIPPING_OUTPUT_PRIMITIVES}
    opt_c_api_constant<
      mp_list<query_target>,
#ifdef GL_CLIPPING_OUTPUT_PRIMITIVES
      enum_type_c<GL_CLIPPING_OUTPUT_PRIMITIVES>>
#else
      enum_type_i>
#endif
      clipping_output_primitives;

    /// @var fragment_shader_invocations
    /// @glconstwrap{FRAGMENT_SHADER_INVOCATIONS}
    opt_c_api_constant<
      mp_list<query_target>,
#ifdef GL_FRAGMENT_SHADER_INVOCATIONS
      enum_type_c<GL_FRAGMENT_SHADER_INVOCATIONS>>
#else
      enum_type_i>
#endif
      fragment_shader_invocations;

    /// @var compute_shader_invocations
    /// @glconstwrap{COMPUTE_SHADER_INVOCATIONS}
    opt_c_api_constant<
      mp_list<query_target>,
#ifdef GL_COMPUTE_SHADER_INVOCATIONS
      enum_type_c<GL_COMPUTE_SHADER_INVOCATIONS>>
#else
      enum_type_i>
#endif
      compute_shader_invocations;

    /// @var query_result
    /// @glconstwrap{QUERY_RESULT}
    opt_c_api_constant<
      mp_list<query_parameter>,
#ifdef GL_QUERY_RESULT
      enum_type_c<GL_QUERY_RESULT>>
#else
      enum_type_i>
#endif
      query_result;

    /// @var query_result_available
    /// @glconstwrap{QUERY_RESULT_AVAILABLE}
    opt_c_api_constant<
      mp_list<query_parameter>,
#ifdef GL_QUERY_RESULT_AVAILABLE
      enum_type_c<GL_QUERY_RESULT_AVAILABLE>,
#else
      enum_type_i,
#endif
      true_false>
      query_result_available;

    /// @var interleaved_attribs
    /// @glconstwrap{INTERLEAVED_ATTRIBS}
    opt_c_api_constant<
      mp_list<transform_feedback_mode>,
#ifdef GL_INTERLEAVED_ATTRIBS
      enum_type_c<GL_INTERLEAVED_ATTRIBS>>
#else
      enum_type_i>
#endif
      interleaved_attribs;

    /// @var separate_attribs
    /// @glconstwrap{SEPARATE_ATTRIBS}
    opt_c_api_constant<
      mp_list<transform_feedback_mode>,
#ifdef GL_SEPARATE_ATTRIBS
      enum_type_c<GL_SEPARATE_ATTRIBS>>
#else
      enum_type_i>
#endif
      separate_attribs;

    /// @var transform_feedback_buffer_start
    /// @glconstwrap{TRANSFORM_FEEDBACK_BUFFER_START}
    opt_c_api_constant<
      mp_list<transform_feedback_parameter>,
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
      enum_type_c<GL_TRANSFORM_FEEDBACK_BUFFER_START>>
#else
      enum_type_i>
#endif
      transform_feedback_buffer_start;

    /// @var transform_feedback_buffer_size
    /// @glconstwrap{TRANSFORM_FEEDBACK_BUFFER_SIZE}
    opt_c_api_constant<
      mp_list<transform_feedback_parameter>,
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
      enum_type_c<GL_TRANSFORM_FEEDBACK_BUFFER_SIZE>>
#else
      enum_type_i>
#endif
      transform_feedback_buffer_size;

    /// @var transform_feedback_parameter
    /// @glconstwrap{TRANSFORM_FEEDBACK_PARAMETER}
    opt_c_api_constant<
      mp_list<transform_feedback_parameter>,
#ifdef GL_TRANSFORM_FEEDBACK_PAUSED
      enum_type_c<GL_TRANSFORM_FEEDBACK_PAUSED>,
#else
      enum_type_i,
#endif
      true_false>
      transform_feedback_paused;

    /// @var transform_feedback_active
    /// @glconstwrap{TRANSFORM_FEEDBACK_ACTIVE}
    opt_c_api_constant<
      mp_list<transform_feedback_parameter>,
#ifdef GL_TRANSFORM_FEEDBACK_ACTIVE
      enum_type_c<GL_TRANSFORM_FEEDBACK_ACTIVE>,
#else
      enum_type_i,
#endif
      true_false>
      transform_feedback_active;

    /// @var current_vertex_attrib
    /// @glconstwrap{CURRENT_VERTEX_ATTRIB}
    opt_c_api_constant<
      mp_list<vertex_attrib_parameter>,
#ifdef GL_CURRENT_VERTEX_ATTRIB
      enum_type_c<GL_CURRENT_VERTEX_ATTRIB>>
#else
      enum_type_i>
#endif
      current_vertex_attrib;

    /// @var vertex_attrib_array_buffer_binding
    /// @glconstwrap{VERTEX_ATTRIB_ARRAY_BUFFER_BINDING}
    opt_c_api_constant<
      mp_list<vertex_attrib_parameter>,
#ifdef GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING
      enum_type_c<GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING>>
#else
      enum_type_i>
#endif
      vertex_attrib_array_buffer_binding;

    /// @var vertex_attrib_array_divisor
    /// @glconstwrap{VERTEX_ATTRIB_ARRAY_DIVISOR}
    opt_c_api_constant<
      mp_list<vertex_attrib_parameter>,
#ifdef GL_VERTEX_ATTRIB_ARRAY_DIVISOR
      enum_type_c<GL_VERTEX_ATTRIB_ARRAY_DIVISOR>>
#else
      enum_type_i>
#endif
      vertex_attrib_array_divisor;

    /// @var vertex_attrib_array_enabled
    /// @glconstwrap{VERTEX_ATTRIB_ARRAY_ENABLED}
    opt_c_api_constant<
      mp_list<vertex_attrib_parameter>,
#ifdef GL_VERTEX_ATTRIB_ARRAY_ENABLED
      enum_type_c<GL_VERTEX_ATTRIB_ARRAY_ENABLED>,
#else
      enum_type_i,
#endif
      true_false>
      vertex_attrib_array_enabled;

    /// @var vertex_attrib_array_integer
    /// @glconstwrap{VERTEX_ATTRIB_ARRAY_INTEGER}
    opt_c_api_constant<
      mp_list<vertex_attrib_parameter>,
#ifdef GL_VERTEX_ATTRIB_ARRAY_INTEGER
      enum_type_c<GL_VERTEX_ATTRIB_ARRAY_INTEGER>,
#else
      enum_type_i,
#endif
      true_false>
      vertex_attrib_array_integer;

    /// @var vertex_attrib_array_integer_ext
    /// @glconstwrap{VERTEX_ATTRIB_ARRAY_INTEGER_EXT}
    opt_c_api_constant<
      mp_list<vertex_attrib_parameter>,
#ifdef GL_VERTEX_ATTRIB_ARRAY_INTEGER_EXT
      enum_type_c<GL_VERTEX_ATTRIB_ARRAY_INTEGER_EXT>>
#else
      enum_type_i>
#endif
      vertex_attrib_array_integer_ext;

    /// @var vertex_attrib_array_long
    /// @glconstwrap{VERTEX_ATTRIB_ARRAY_LONG}
    opt_c_api_constant<
      mp_list<vertex_attrib_parameter>,
#ifdef GL_VERTEX_ATTRIB_ARRAY_LONG
      enum_type_c<GL_VERTEX_ATTRIB_ARRAY_LONG>,
#else
      enum_type_i,
#endif
      true_false>
      vertex_attrib_array_long;

    /// @var vertex_attrib_array_normalized
    /// @glconstwrap{VERTEX_ATTRIB_ARRAY_NORMALIZED}
    opt_c_api_constant<
      mp_list<vertex_attrib_parameter>,
#ifdef GL_VERTEX_ATTRIB_ARRAY_NORMALIZED
      enum_type_c<GL_VERTEX_ATTRIB_ARRAY_NORMALIZED>,
#else
      enum_type_i,
#endif
      true_false>
      vertex_attrib_array_normalized;

    /// @var vertex_attrib_array_pointer
    /// @glconstwrap{VERTEX_ATTRIB_ARRAY_POINTER}
    opt_c_api_constant<
      mp_list<vertex_attrib_parameter>,
#ifdef GL_VERTEX_ATTRIB_ARRAY_POINTER
      enum_type_c<GL_VERTEX_ATTRIB_ARRAY_POINTER>>
#else
      enum_type_i>
#endif
      vertex_attrib_array_pointer;

    /// @var vertex_attrib_array_size
    /// @glconstwrap{VERTEX_ATTRIB_ARRAY_SIZE}
    opt_c_api_constant<
      mp_list<vertex_attrib_parameter>,
#ifdef GL_VERTEX_ATTRIB_ARRAY_SIZE
      enum_type_c<GL_VERTEX_ATTRIB_ARRAY_SIZE>>
#else
      enum_type_i>
#endif
      vertex_attrib_array_size;

    /// @var vertex_attrib_array_stride
    /// @glconstwrap{VERTEX_ATTRIB_ARRAY_STRIDE}
    opt_c_api_constant<
      mp_list<vertex_attrib_parameter>,
#ifdef GL_VERTEX_ATTRIB_ARRAY_STRIDE
      enum_type_c<GL_VERTEX_ATTRIB_ARRAY_STRIDE>>
#else
      enum_type_i>
#endif
      vertex_attrib_array_stride;

    /// @var vertex_attrib_array_type
    /// @glconstwrap{VERTEX_ATTRIB_ARRAY_TYPE}
    opt_c_api_constant<
      mp_list<vertex_attrib_parameter>,
#ifdef GL_VERTEX_ATTRIB_ARRAY_TYPE
      enum_type_c<GL_VERTEX_ATTRIB_ARRAY_TYPE>>
#else
      enum_type_i>
#endif
      vertex_attrib_array_type;

    /// @var vertex_attrib_binding
    /// @glconstwrap{VERTEX_ATTRIB_BINDING}
    opt_c_api_constant<
      mp_list<vertex_attrib_parameter>,
#ifdef GL_VERTEX_ATTRIB_BINDING
      enum_type_c<GL_VERTEX_ATTRIB_BINDING>>
#else
      enum_type_i>
#endif
      vertex_attrib_binding;

    /// @var vertex_attrib_relative_offset
    /// @glconstwrap{VERTEX_ATTRIB_RELATIVE_OFFSET}
    opt_c_api_constant<
      mp_list<vertex_attrib_parameter>,
#ifdef GL_VERTEX_ATTRIB_RELATIVE_OFFSET
      enum_type_c<GL_VERTEX_ATTRIB_RELATIVE_OFFSET>>
#else
      enum_type_i>
#endif
      vertex_attrib_relative_offset;

    /// @var uniform
    /// @glconstwrap{UNIFORM}
    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_UNIFORM
      enum_type_c<GL_UNIFORM>>
#else
      enum_type_i>
#endif
      uniform;

    /// @var uniform_block
    /// @glconstwrap{UNIFORM_BLOCK}
    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_UNIFORM_BLOCK
      enum_type_c<GL_UNIFORM_BLOCK>>
#else
      enum_type_i>
#endif
      uniform_block;

    /// @var program_input
    /// @glconstwrap{PROGRAM_INPUT}
    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_PROGRAM_INPUT
      enum_type_c<GL_PROGRAM_INPUT>>
#else
      enum_type_i>
#endif
      program_input;

    /// @var program_output
    /// @glconstwrap{PROGRAM_OUTPUT}
    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_PROGRAM_OUTPUT
      enum_type_c<GL_PROGRAM_OUTPUT>>
#else
      enum_type_i>
#endif
      program_output;

    /// @var vertex_subroutine
    /// @glconstwrap{VERTEX_SUBROUTINE}
    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_VERTEX_SUBROUTINE
      enum_type_c<GL_VERTEX_SUBROUTINE>>
#else
      enum_type_i>
#endif
      vertex_subroutine;

    /// @var tess_control_subroutine
    /// @glconstwrap{TESS_CONTROL_SUBROUTINE}
    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_TESS_CONTROL_SUBROUTINE
      enum_type_c<GL_TESS_CONTROL_SUBROUTINE>>
#else
      enum_type_i>
#endif
      tess_control_subroutine;

    /// @var tess_evaluation_subroutine
    /// @glconstwrap{TESS_EVALUATION_SUBROUTINE}
    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_TESS_EVALUATION_SUBROUTINE
      enum_type_c<GL_TESS_EVALUATION_SUBROUTINE>>
#else
      enum_type_i>
#endif
      tess_evaluation_subroutine;

    /// @var geometry_subroutine
    /// @glconstwrap{GEOMETRY_SUBROUTINE}
    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_GEOMETRY_SUBROUTINE
      enum_type_c<GL_GEOMETRY_SUBROUTINE>>
#else
      enum_type_i>
#endif
      geometry_subroutine;

    /// @var fragment_subroutine
    /// @glconstwrap{FRAGMENT_SUBROUTINE}
    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_FRAGMENT_SUBROUTINE
      enum_type_c<GL_FRAGMENT_SUBROUTINE>>
#else
      enum_type_i>
#endif
      fragment_subroutine;

    /// @var compute_subroutine
    /// @glconstwrap{COMPUTE_SUBROUTINE}
    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_COMPUTE_SUBROUTINE
      enum_type_c<GL_COMPUTE_SUBROUTINE>>
#else
      enum_type_i>
#endif
      compute_subroutine;

    /// @var vertex_subroutine_uniform
    /// @glconstwrap{VERTEX_SUBROUTINE_UNIFORM}
    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_VERTEX_SUBROUTINE_UNIFORM
      enum_type_c<GL_VERTEX_SUBROUTINE_UNIFORM>>
#else
      enum_type_i>
#endif
      vertex_subroutine_uniform;

    /// @var tess_control_subroutine_uniform
    /// @glconstwrap{TESS_CONTROL_SUBROUTINE_UNIFORM}
    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_TESS_CONTROL_SUBROUTINE_UNIFORM
      enum_type_c<GL_TESS_CONTROL_SUBROUTINE_UNIFORM>>
#else
      enum_type_i>
#endif
      tess_control_subroutine_uniform;

    /// @var tess_evaluation_subroutine_uniform
    /// @glconstwrap{TESS_EVALUATION_SUBROUTINE_UNIFORM}
    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_TESS_EVALUATION_SUBROUTINE_UNIFORM
      enum_type_c<GL_TESS_EVALUATION_SUBROUTINE_UNIFORM>>
#else
      enum_type_i>
#endif
      tess_evaluation_subroutine_uniform;

    /// @var geometry_subroutine_uniform
    /// @glconstwrap{GEOMETRY_SUBROUTINE_UNIFORM}
    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_GEOMETRY_SUBROUTINE_UNIFORM
      enum_type_c<GL_GEOMETRY_SUBROUTINE_UNIFORM>>
#else
      enum_type_i>
#endif
      geometry_subroutine_uniform;

    /// @var fragment_subroutine_uniform
    /// @glconstwrap{FRAGMENT_SUBROUTINE_UNIFORM}
    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_FRAGMENT_SUBROUTINE_UNIFORM
      enum_type_c<GL_FRAGMENT_SUBROUTINE_UNIFORM>>
#else
      enum_type_i>
#endif
      fragment_subroutine_uniform;

    /// @var compute_subroutine_uniform
    /// @glconstwrap{COMPUTE_SUBROUTINE_UNIFORM}
    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_COMPUTE_SUBROUTINE_UNIFORM
      enum_type_c<GL_COMPUTE_SUBROUTINE_UNIFORM>>
#else
      enum_type_i>
#endif
      compute_subroutine_uniform;

    /// @var transform_feedback_varying
    /// @glconstwrap{TRANSFORM_FEEDBACK_VARYING}
    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_TRANSFORM_FEEDBACK_VARYING
      enum_type_c<GL_TRANSFORM_FEEDBACK_VARYING>>
#else
      enum_type_i>
#endif
      transform_feedback_varying;

    /// @var buffer_variable
    /// @glconstwrap{BUFFER_VARIABLE}
    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_BUFFER_VARIABLE
      enum_type_c<GL_BUFFER_VARIABLE>>
#else
      enum_type_i>
#endif
      buffer_variable;

    /// @var buffer_storage_block
    /// @glconstwrap{BUFFER_STORAGE_BLOCK}
    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_BUFFER_STORAGE_BLOCK
      enum_type_c<GL_BUFFER_STORAGE_BLOCK>>
#else
      enum_type_i>
#endif
      buffer_storage_block;

    /// @var fragment_input_nv
    /// @glconstwrap{FRAGMENT_INPUT_NV}
    opt_c_api_constant<
      mp_list<program_interface>,
#ifdef GL_FRAGMENT_INPUT_NV
      enum_type_c<GL_FRAGMENT_INPUT_NV>>
#else
      enum_type_i>
#endif
      fragment_input_nv;

    /// @var active_variables
    /// @glconstwrap{ACTIVE_VARIABLES}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_ACTIVE_VARIABLES
      enum_type_c<GL_ACTIVE_VARIABLES>>
#else
      enum_type_i>
#endif
      active_variables;

    /// @var num_active_variables
    /// @glconstwrap{NUM_ACTIVE_VARIABLES}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_NUM_ACTIVE_VARIABLES
      enum_type_c<GL_NUM_ACTIVE_VARIABLES>>
#else
      enum_type_i>
#endif
      num_active_variables;

    /// @var array_size
    /// @glconstwrap{ARRAY_SIZE}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_ARRAY_SIZE
      enum_type_c<GL_ARRAY_SIZE>>
#else
      enum_type_i>
#endif
      array_size;

    /// @var array_stride
    /// @glconstwrap{ARRAY_STRIDE}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_ARRAY_STRIDE
      enum_type_c<GL_ARRAY_STRIDE>>
#else
      enum_type_i>
#endif
      array_stride;

    /// @var block_index
    /// @glconstwrap{BLOCK_INDEX}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_BLOCK_INDEX
      enum_type_c<GL_BLOCK_INDEX>>
#else
      enum_type_i>
#endif
      block_index;

    /// @var is_row_major
    /// @glconstwrap{IS_ROW_MAJOR}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_IS_ROW_MAJOR
      enum_type_c<GL_IS_ROW_MAJOR>>
#else
      enum_type_i>
#endif
      is_row_major;

    /// @var matrix_stride
    /// @glconstwrap{MATRIX_STRIDE}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_MATRIX_STRIDE
      enum_type_c<GL_MATRIX_STRIDE>>
#else
      enum_type_i>
#endif
      matrix_stride;

    /// @var atomic_counter_buffer_index
    /// @glconstwrap{ATOMIC_COUNTER_BUFFER_INDEX}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
      enum_type_c<GL_ATOMIC_COUNTER_BUFFER_INDEX>>
#else
      enum_type_i>
#endif
      atomic_counter_buffer_index;

    /// @var buffer_data_size
    /// @glconstwrap{BUFFER_DATA_SIZE}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_BUFFER_DATA_SIZE
      enum_type_c<GL_BUFFER_DATA_SIZE>>
#else
      enum_type_i>
#endif
      buffer_data_size;

    /// @var num_compatible_subroutines
    /// @glconstwrap{NUM_COMPATIBLE_SUBROUTINES}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_NUM_COMPATIBLE_SUBROUTINES
      enum_type_c<GL_NUM_COMPATIBLE_SUBROUTINES>>
#else
      enum_type_i>
#endif
      num_compatible_subroutines;

    /// @var compatible_subroutines
    /// @glconstwrap{COMPATIBLE_SUBROUTINES}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_COMPATIBLE_SUBROUTINES
      enum_type_c<GL_COMPATIBLE_SUBROUTINES>>
#else
      enum_type_i>
#endif
      compatible_subroutines;

    /// @var is_per_patch
    /// @glconstwrap{IS_PER_PATCH}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_IS_PER_PATCH
      enum_type_c<GL_IS_PER_PATCH>>
#else
      enum_type_i>
#endif
      is_per_patch;

    /// @var location
    /// @glconstwrap{LOCATION}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_LOCATION
      enum_type_c<GL_LOCATION>>
#else
      enum_type_i>
#endif
      location;

    /// @var location_component
    /// @glconstwrap{LOCATION_COMPONENT}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_LOCATION_COMPONENT
      enum_type_c<GL_LOCATION_COMPONENT>>
#else
      enum_type_i>
#endif
      location_component;

    /// @var location_index
    /// @glconstwrap{LOCATION_INDEX}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_LOCATION_INDEX
      enum_type_c<GL_LOCATION_INDEX>>
#else
      enum_type_i>
#endif
      location_index;

    /// @var name_lenght
    /// @glconstwrap{NAME_LENGHT}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_NAME_LENGTH
      enum_type_c<GL_NAME_LENGTH>>
#else
      enum_type_i>
#endif
      name_length;

    /// @var offset
    /// @glconstwrap{OFFSET}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_OFFSET
      enum_type_c<GL_OFFSET>>
#else
      enum_type_i>
#endif
      offset;

    /// @var referenced_by_vertex_shader
    /// @glconstwrap{REFERENCED_BY_VERTEX_SHADER}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_REFERENCED_BY_VERTEX_SHADER
      enum_type_c<GL_REFERENCED_BY_VERTEX_SHADER>>
#else
      enum_type_i>
#endif
      referenced_by_vertex_shader;

    /// @var referenced_by_tess_control_shader
    /// @glconstwrap{REFERENCED_BY_TESS_CONTROL_SHADER}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
      enum_type_c<GL_REFERENCED_BY_TESS_CONTROL_SHADER>>
#else
      enum_type_i>
#endif
      referenced_by_tess_control_shader;

    /// @var referenced_by_tess_evaluation_shader
    /// @glconstwrap{REFERENCED_BY_TESS_EVALUATION_SHADER}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
      enum_type_c<GL_REFERENCED_BY_TESS_EVALUATION_SHADER>>
#else
      enum_type_i>
#endif
      referenced_by_tess_evaluation_shader;

    /// @var referenced_by_geometry_shader
    /// @glconstwrap{REFERENCED_BY_GEOMETRY_SHADER}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
      enum_type_c<GL_REFERENCED_BY_GEOMETRY_SHADER>>
#else
      enum_type_i>
#endif
      referenced_by_geometry_shader;

    /// @var referenced_by_fragment_shader
    /// @glconstwrap{REFERENCED_BY_FRAGMENT_SHADER}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
      enum_type_c<GL_REFERENCED_BY_FRAGMENT_SHADER>>
#else
      enum_type_i>
#endif
      referenced_by_fragment_shader;

    /// @var referenced_by_compute_shader
    /// @glconstwrap{REFERENCED_BY_COMPUTE_SHADER}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_REFERENCED_BY_COMPUTE_SHADER
      enum_type_c<GL_REFERENCED_BY_COMPUTE_SHADER>>
#else
      enum_type_i>
#endif
      referenced_by_compute_shader;

    /// @var transform_feedback_buffer_index
    /// @glconstwrap{TRANSFORM_FEEDBACK_BUFFER_INDEX}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
      enum_type_c<GL_TRANSFORM_FEEDBACK_BUFFER_INDEX>>
#else
      enum_type_i>
#endif
      transform_feedback_buffer_index;

    /// @var transform_feedback_buffer_start
    /// @glconstwrap{TRANSFORM_FEEDBACK_BUFFER_START}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
      enum_type_c<GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE>>
#else
      enum_type_i>
#endif
      transform_feedback_buffer_stride;

    /// @var top_level_array_size
    /// @glconstwrap{TOP_LEVEL_ARRAY_SIZE}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_TOP_LEVEL_ARRAY_SIZE
      enum_type_c<GL_TOP_LEVEL_ARRAY_SIZE>>
#else
      enum_type_i>
#endif
      top_level_array_size;

    /// @var top_level_array_stride
    /// @glconstwrap{TOP_LEVEL_ARRAY_STRIDE}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_TOP_LEVEL_ARRAY_STRIDE
      enum_type_c<GL_TOP_LEVEL_ARRAY_STRIDE>>
#else
      enum_type_i>
#endif
      top_level_array_stride;

    /// @var type
    /// @glconstwrap{TYPE}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_TYPE
      enum_type_c<GL_TYPE>>
#else
      enum_type_i>
#endif
      type;

    /// @var path_gen_mode_nv
    /// @glconstwrap{PATH_GEN_MODE_NV}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_PATH_GEN_MODE_NV
      enum_type_c<GL_PATH_GEN_MODE_NV>>
#else
      enum_type_i>
#endif
      path_gen_mode_nv;

    /// @var path_gen_components_nv
    /// @glconstwrap{PATH_GEN_COMPONENTS_NV}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_PATH_GEN_COMPONENTS_NV
      enum_type_c<GL_PATH_GEN_COMPONENTS_NV>>
#else
      enum_type_i>
#endif
      path_gen_components_nv;

    /// @var path_gen_coeff_nv
    /// @glconstwrap{PATH_GEN_COEFF_NV}
    opt_c_api_constant<
      mp_list<program_property>,
#ifdef GL_PATH_GEN_COEFF_NV
      enum_type_c<GL_PATH_GEN_COEFF_NV>>
#else
      enum_type_i>
#endif
      path_gen_coeff_nv;

    /// @var blend
    /// @glconstwrap{BLEND}
    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_BLEND
      enum_type_c<GL_BLEND>>
#else
      enum_type_i>
#endif
      blend;

    /// @var primitive_restart
    /// @glconstwrap{PRIMITIVE_RESTART}
    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_PRIMITIVE_RESTART
      enum_type_c<GL_PRIMITIVE_RESTART>>
#else
      enum_type_i>
#endif
      primitive_restart;

    /// @var clip_distance0
    /// @glconstwrap{CLIP_DISTANCE0}
    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_CLIP_DISTANCE0
      enum_type_c<GL_CLIP_DISTANCE0>,
#else
      enum_type_i,
#endif
      nothing_t,
      true>
      clip_distance0;

    /// @var cull_face
    /// @glconstwrap{CULL_FACE}
    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_CULL_FACE
      enum_type_c<GL_CULL_FACE>>
#else
      enum_type_i>
#endif
      cull_face;

    /// @var depth_clamp
    /// @glconstwrap{DEPTH_CLAMP}
    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_DEPTH_CLAMP
      enum_type_c<GL_DEPTH_CLAMP>>
#else
      enum_type_i>
#endif
      depth_clamp;

    /// @var depth_test
    /// @glconstwrap{DEPTH_TEST}
    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_DEPTH_TEST
      enum_type_c<GL_DEPTH_TEST>>
#else
      enum_type_i>
#endif
      depth_test;

    /// @var scissor_test
    /// @glconstwrap{SCISSOR_TEST}
    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_SCISSOR_TEST
      enum_type_c<GL_SCISSOR_TEST>>
#else
      enum_type_i>
#endif
      scissor_test;

    /// @var stencil_test
    /// @glconstwrap{STENCIL_TEST}
    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_STENCIL_TEST
      enum_type_c<GL_STENCIL_TEST>>
#else
      enum_type_i>
#endif
      stencil_test;

    /// @var multisample
    /// @glconstwrap{MULTISAMPLE}
    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_MULTISAMPLE
      enum_type_c<GL_MULTISAMPLE>>
#else
      enum_type_i>
#endif
      multisample;

    /// @var debug_output
    /// @glconstwrap{DEBUG_OUTPUT}
    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_DEBUG_OUTPUT
      enum_type_c<GL_DEBUG_OUTPUT>>
#elif defined(GL_DEBUG_OUTPUT_KHR)
      enum_type_c<GL_DEBUG_OUTPUT_KHR>>
#else
      enum_type_i>
#endif
      debug_output;

    /// @var debug_output_synchronous
    /// @glconstwrap{DEBUG_OUTPUT_SYNCHRONOUS}
    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
      enum_type_c<GL_DEBUG_OUTPUT_SYNCHRONOUS>>
#elif defined(GL_DEBUG_OUTPUT_SYNCHRONOUS_KHR)
      enum_type_c<GL_DEBUG_OUTPUT_SYNCHRONOUS_KHR>>
#else
      enum_type_i>
#endif
      debug_output_synchronous;

    /// @var color_array
    /// @glconstwrap{COLOR_ARRAY}
    opt_c_api_constant<
      mp_list<client_capability>,
#ifdef GL_COLOR_ARRAY
      enum_type_c<GL_COLOR_ARRAY>>
#else
      enum_type_i>
#endif
      color_array;

    /// @var edge_flag_array
    /// @glconstwrap{EDGE_FLAG_ARRAY}
    opt_c_api_constant<
      mp_list<client_capability>,
#ifdef GL_EDGE_FLAG_ARRAY
      enum_type_c<GL_EDGE_FLAG_ARRAY>>
#else
      enum_type_i>
#endif
      edge_flag_array;

    /// @var fog_coord_array
    /// @glconstwrap{FOG_COORD_ARRAY}
    opt_c_api_constant<
      mp_list<client_capability>,
#ifdef GL_FOG_COORD_ARRAY
      enum_type_c<GL_FOG_COORD_ARRAY>>
#else
      enum_type_i>
#endif
      fog_coord_array;

    /// @var index_array
    /// @glconstwrap{INDEX_ARRAY}
    opt_c_api_constant<
      mp_list<client_capability>,
#ifdef GL_INDEX_ARRAY
      enum_type_c<GL_INDEX_ARRAY>>
#else
      enum_type_i>
#endif
      index_array;

    /// @var normal_array
    /// @glconstwrap{NORMAL_ARRAY}
    opt_c_api_constant<
      mp_list<client_capability>,
#ifdef GL_NORMAL_ARRAY
      enum_type_c<GL_NORMAL_ARRAY>>
#else
      enum_type_i>
#endif
      normal_array;

    /// @var secondary_color_array
    /// @glconstwrap{SECONDARY_COLOR_ARRAY}
    opt_c_api_constant<
      mp_list<client_capability>,
#ifdef GL_SECONDARY_COLOR_ARRAY
      enum_type_c<GL_SECONDARY_COLOR_ARRAY>>
#else
      enum_type_i>
#endif
      secondary_color_array;

    /// @var texture_coord_array
    /// @glconstwrap{TEXTURE_COORD_ARRAY}
    opt_c_api_constant<
      mp_list<client_capability>,
#ifdef GL_TEXTURE_COORD_ARRAY
      enum_type_c<GL_TEXTURE_COORD_ARRAY>>
#else
      enum_type_i>
#endif
      texture_coord_array;

    /// @var vertex_attrib_array_unified_nv
    /// @glconstwrap{VERTEX_ATTRIB_ARRAY_UNIFIED_NV}
    opt_c_api_constant<
      mp_list<client_capability>,
#ifdef GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV
      enum_type_c<GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV>>
#else
      enum_type_i>
#endif
      vertex_attrib_array_unified_nv;

    /// @var element_array_unified_nv
    /// @glconstwrap{ELEMENT_ARRAY_UNIFIED_NV}
    opt_c_api_constant<
      mp_list<client_capability>,
#ifdef GL_ELEMENT_ARRAY_UNIFIED_NV
      enum_type_c<GL_ELEMENT_ARRAY_UNIFIED_NV>>
#else
      enum_type_i>
#endif
      element_array_unified_nv;

    /// @var uniform_buffer_unified_nv
    /// @glconstwrap{UNIFORM_BUFFER_UNIFIED_NV}
    opt_c_api_constant<
      mp_list<client_capability>,
#ifdef GL_UNIFORM_BUFFER_UNIFIED_NV
      enum_type_c<GL_UNIFORM_BUFFER_UNIFIED_NV>>
#else
      enum_type_i>
#endif
      uniform_buffer_unified_nv;

    /// @var front_left
    /// @glconstwrap{FRONT_LEFT}
    opt_c_api_constant<
      mp_list<surface_buffer, framebuffer_attachment>,
#ifdef GL_FRONT_LEFT
      enum_type_c<GL_FRONT_LEFT>>
#else
      enum_type_i>
#endif
      front_left;

    /// @var front_right
    /// @glconstwrap{FRONT_RIGHT}
    opt_c_api_constant<
      mp_list<surface_buffer, framebuffer_attachment>,
#ifdef GL_FRONT_RIGHT
      enum_type_c<GL_FRONT_RIGHT>>
#else
      enum_type_i>
#endif
      front_right;

    /// @var back_left
    /// @glconstwrap{BACK_LEFT}
    opt_c_api_constant<
      mp_list<surface_buffer, framebuffer_attachment>,
#ifdef GL_BACK_LEFT
      enum_type_c<GL_BACK_LEFT>>
#else
      enum_type_i>
#endif
      back_left;

    /// @var back_right
    /// @glconstwrap{BACK_RIGHT}
    opt_c_api_constant<
      mp_list<surface_buffer, framebuffer_attachment>,
#ifdef GL_BACK_RIGHT
      enum_type_c<GL_BACK_RIGHT>>
#else
      enum_type_i>
#endif
      back_right;

    /// @var front
    /// @glconstwrap{FRONT}
    opt_c_api_constant<
      mp_list<surface_buffer, face_mode, framebuffer_attachment>,
#ifdef GL_FRONT
      enum_type_c<GL_FRONT>>
#else
      enum_type_i>
#endif
      front;

    /// @var back
    /// @glconstwrap{BACK}
    opt_c_api_constant<
      mp_list<surface_buffer, face_mode, framebuffer_attachment>,
#ifdef GL_BACK
      enum_type_c<GL_BACK>>
#else
      enum_type_i>
#endif
      back;

    /// @var left
    /// @glconstwrap{LEFT}
    opt_c_api_constant<
      mp_list<surface_buffer>,
#ifdef GL_LEFT
      enum_type_c<GL_LEFT>>
#else
      enum_type_i>
#endif
      left;

    /// @var right
    /// @glconstwrap{RIGHT}
    opt_c_api_constant<
      mp_list<surface_buffer>,
#ifdef GL_RIGHT
      enum_type_c<GL_RIGHT>>
#else
      enum_type_i>
#endif
      right;

    /// @var front_and_back
    /// @glconstwrap{FRONT_AND_BACK}
    opt_c_api_constant<
      mp_list<surface_buffer, face_mode>,
#ifdef GL_FRONT_AND_BACK
      enum_type_c<GL_FRONT_AND_BACK>>
#else
      enum_type_i>
#endif
      front_and_back;

    /// @var array_buffer_binding
    /// @glconstwrap{ARRAY_BUFFER_BINDING}
    opt_c_api_constant<
      mp_list<binding_query, program_property>,
#ifdef GL_ARRAY_BUFFER_BINDING
      enum_type_c<GL_ARRAY_BUFFER_BINDING>,
#else
      enum_type_i,
#endif
      buffer_name>
      array_buffer_binding;

    /// @var atomic_counter_buffer_binding
    /// @glconstwrap{ATOMIC_COUNTER_BUFFER_BINDING}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_ATOMIC_COUNTER_BUFFER_BINDING
      enum_type_c<GL_ATOMIC_COUNTER_BUFFER_BINDING>,
#else
      enum_type_i,
#endif
      buffer_name>
      atomic_counter_buffer_binding;

    /// @var copy_read_buffer_binding
    /// @glconstwrap{COPY_READ_BUFFER_BINDING}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_COPY_READ_BUFFER_BINDING
      enum_type_c<GL_COPY_READ_BUFFER_BINDING>,
#else
      enum_type_i,
#endif
      buffer_name>
      copy_read_buffer_binding;

    /// @var copy_write_buffer_binding
    /// @glconstwrap{COPY_WRITE_BUFFER_BINDING}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_COPY_WRITE_BUFFER_BINDING
      enum_type_c<GL_COPY_WRITE_BUFFER_BINDING>,
#else
      enum_type_i,
#endif
      buffer_name>
      copy_write_buffer_binding;

    /// @var dispatch_indirect_buffer_binding
    /// @glconstwrap{DISPATCH_INDIRECT_BUFFER_BINDING}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_DISPATCH_INDIRECT_BUFFER_BINDING
      enum_type_c<GL_DISPATCH_INDIRECT_BUFFER_BINDING>,
#else
      enum_type_i,
#endif
      buffer_name>
      dispatch_indirect_buffer_binding;

    /// @var draw_indirect_buffer_binding
    /// @glconstwrap{DRAW_INDIRECT_BUFFER_BINDING}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_DRAW_INDIRECT_BUFFER_BINDING
      enum_type_c<GL_DRAW_INDIRECT_BUFFER_BINDING>,
#else
      enum_type_i,
#endif
      buffer_name>
      draw_indirect_buffer_binding;

    /// @var element_array_buffer_binding
    /// @glconstwrap{ELEMENT_ARRAY_BUFFER_BINDING}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_ELEMENT_ARRAY_BUFFER_BINDING
      enum_type_c<GL_ELEMENT_ARRAY_BUFFER_BINDING>,
#else
      enum_type_i,
#endif
      buffer_name>
      element_array_buffer_binding;

    /// @var pixel_pack_buffer_binding
    /// @glconstwrap{PIXEL_PACK_BUFFER_BINDING}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_PIXEL_PACK_BUFFER_BINDING
      enum_type_c<GL_PIXEL_PACK_BUFFER_BINDING>,
#else
      enum_type_i,
#endif
      buffer_name>
      pixel_pack_buffer_binding;

    /// @var pixel_unpack_buffer_binding
    /// @glconstwrap{PIXEL_UNPACK_BUFFER_BINDING}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_PIXEL_UNPACK_BUFFER_BINDING
      enum_type_c<GL_PIXEL_UNPACK_BUFFER_BINDING>,
#else
      enum_type_i,
#endif
      buffer_name>
      pixel_unpack_buffer_binding;

    /// @var shader_storage_buffer_binding
    /// @glconstwrap{SHADER_STORAGE_BUFFER_BINDING}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_SHADER_STORAGE_BUFFER_BINDING
      enum_type_c<GL_SHADER_STORAGE_BUFFER_BINDING>,
#else
      enum_type_i,
#endif
      buffer_name>
      shader_storage_buffer_binding;

    /// @var texture_buffer_binding
    /// @glconstwrap{TEXTURE_BUFFER_BINDING}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_TEXTURE_BUFFER_BINDING
      enum_type_c<GL_TEXTURE_BUFFER_BINDING>,
#else
      enum_type_i,
#endif
      buffer_name>
      texture_buffer_binding;

    /// @var transform_feedback_buffer_binding
    /// @glconstwrap{TRANSFORM_FEEDBACK_BUFFER_BINDING}
    opt_c_api_constant<
      mp_list<binding_query, transform_feedback_parameter>,
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
      enum_type_c<GL_TRANSFORM_FEEDBACK_BUFFER_BINDING>,
#else
      enum_type_i,
#endif
      buffer_name>
      transform_feedback_buffer_binding;

    /// @var uniform_buffer_binding
    /// @glconstwrap{UNIFORM_BUFFER_BINDING}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_UNIFORM_BUFFER_BINDING
      enum_type_c<GL_UNIFORM_BUFFER_BINDING>,
#else
      enum_type_i,
#endif
      buffer_name>
      uniform_buffer_binding;

    /// @var query_buffer_binding
    /// @glconstwrap{QUERY_BUFFER_BINDING}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_QUERY_BUFFER_BINDING
      enum_type_c<GL_QUERY_BUFFER_BINDING>,
#else
      enum_type_i,
#endif
      buffer_name>
      query_buffer_binding;

    /// @var parameter_buffer_binding
    /// @glconstwrap{PARAMETER_BUFFER_BINDING}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_PARAMETER_BUFFER_BINDING_ARB
      enum_type_c<GL_PARAMETER_BUFFER_BINDING_ARB>,
#else
      enum_type_i,
#endif
      buffer_name>
      parameter_buffer_binding;

    /// @var buffer_binding
    /// @glconstwrap{BUFFER_BINDING}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_BUFFER_BINDING
      enum_type_c<GL_BUFFER_BINDING>>
#else
      enum_type_i>
#endif
      buffer_binding;

    /// @var draw_framebuffer_binding
    /// @glconstwrap{DRAW_FRAMEBUFFER_BINDING}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_DRAW_FRAMEBUFFER_BINDING
      enum_type_c<GL_DRAW_FRAMEBUFFER_BINDING>,
#else
      enum_type_i,
#endif
      framebuffer_name>
      draw_framebuffer_binding;

    /// @var renderbuffer_binding
    /// @glconstwrap{RENDERBUFFER_BINDING}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_RENDERBUFFER_BINDING
      enum_type_c<GL_RENDERBUFFER_BINDING>,
#else
      enum_type_i,
#endif
      renderbuffer_name>
      renderbuffer_binding;

    /// @var sampler_binding
    /// @glconstwrap{SAMPLER_BINDING}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_SAMPLER_BINDING
      enum_type_c<GL_SAMPLER_BINDING>,
#else
      enum_type_i,
#endif
      sampler_name>
      sampler_binding;

    /// @var texture_binding_1d
    /// @glconstwrap{TEXTURE_BINDING_1D}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_TEXTURE_BINDING_1D
      enum_type_c<GL_TEXTURE_BINDING_1D>,
#else
      enum_type_i,
#endif
      texture_name>
      texture_binding_1d;

    /// @var texture_binding_2d
    /// @glconstwrap{TEXTURE_BINDING_2D}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_TEXTURE_BINDING_2D
      enum_type_c<GL_TEXTURE_BINDING_2D>,
#else
      enum_type_i,
#endif
      texture_name>
      texture_binding_2d;

    /// @var texture_binding_3d
    /// @glconstwrap{TEXTURE_BINDING_3D}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_TEXTURE_BINDING_3D
      enum_type_c<GL_TEXTURE_BINDING_3D>,
#else
      enum_type_i,
#endif
      texture_name>
      texture_binding_3d;

    /// @var texture_binding_1d_array
    /// @glconstwrap{TEXTURE_BINDING_1D_ARRAY}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_TEXTURE_BINDING_1D_ARRAY
      enum_type_c<GL_TEXTURE_BINDING_1D_ARRAY>,
#else
      enum_type_i,
#endif
      texture_name>
      texture_binding_1d_array;

    /// @var texture_binding_2d_array
    /// @glconstwrap{TEXTURE_BINDING_2D_ARRAY}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_TEXTURE_BINDING_2D_ARRAY
      enum_type_c<GL_TEXTURE_BINDING_2D_ARRAY>,
#else
      enum_type_i,
#endif
      texture_name>
      texture_binding_2d_array;

    /// @var texture_binding_rectangle
    /// @glconstwrap{TEXTURE_BINDING_RECTANGLE}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_TEXTURE_BINDING_RECTANGLE
      enum_type_c<GL_TEXTURE_BINDING_RECTANGLE>,
#else
      enum_type_i,
#endif
      texture_name>
      texture_binding_rectangle;

    /// @var texture_binding_buffer
    /// @glconstwrap{TEXTURE_BINDING_BUFFER}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_TEXTURE_BINDING_BUFFER
      enum_type_c<GL_TEXTURE_BINDING_BUFFER>,
#else
      enum_type_i,
#endif
      texture_name>
      texture_binding_buffer;

    /// @var texture_binding_cube_map
    /// @glconstwrap{TEXTURE_BINDING_CUBE_MAP}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_TEXTURE_BINDING_CUBE_MAP
      enum_type_c<GL_TEXTURE_BINDING_CUBE_MAP>,
#else
      enum_type_i,
#endif
      texture_name>
      texture_binding_cube_map;

    /// @var texture_binding_cube_map_array
    /// @glconstwrap{TEXTURE_BINDING_CUBE_MAP_ARRAY}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
      enum_type_c<GL_TEXTURE_BINDING_CUBE_MAP_ARRAY>,
#else
      enum_type_i,
#endif
      texture_name>
      texture_binding_cube_map_array;

    /// @var texture_binding_2d_multisample
    /// @glconstwrap{TEXTURE_BINDING_2D_MULTISAMPLE}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
      enum_type_c<GL_TEXTURE_BINDING_2D_MULTISAMPLE>,
#else
      enum_type_i,
#endif
      texture_name>
      texture_binding_2d_multisample;

    /// @var texture_binding_2d_multisample_array
    /// @glconstwrap{TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
      enum_type_c<GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY>,
#else
      enum_type_i,
#endif
      texture_name>
      texture_binding_2d_multisample_array;

    /// @var texture_binding_external
    /// @glconstwrap{TEXTURE_BINDING_EXTERNAL}
    opt_c_api_constant<mp_list<binding_query>, enum_type_c<0x8D67>, texture_name>
      texture_binding_external;

    /// @var transform_feedback_binding
    /// @glconstwrap{TRANSFORM_FEEDBACK_BINDING}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_TRANSFORM_FEEDBACK_BINDING
      enum_type_c<GL_TRANSFORM_FEEDBACK_BINDING>,
#else
      enum_type_i,
#endif
      transform_feedback_name>
      transform_feedback_binding;

    /// @var vertex_array_binding
    /// @glconstwrap{VERTEX_ARRAY_BINDING}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_VERTEX_ARRAY_BINDING
      enum_type_c<GL_VERTEX_ARRAY_BINDING>,
#else
      enum_type_i,
#endif
      vertex_array_name>
      vertex_array_binding;

    /// @var program_pipeline_binding
    /// @glconstwrap{PROGRAM_PIPELINE_BINDING}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_PROGRAM_PIPELINE_BINDING
      enum_type_c<GL_PROGRAM_PIPELINE_BINDING>,
#else
      enum_type_i,
#endif
      program_pipeline_name>
      program_pipeline_binding;

    /// @var current_program
    /// @glconstwrap{CURRENT_PROGRAM}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_CURRENT_PROGRAM
      enum_type_c<GL_CURRENT_PROGRAM>,
#else
      enum_type_i,
#endif
      program_name>
      current_program;

    /// @var draw_buffer0
    /// @glconstwrap{DRAW_BUFFER0}
    opt_c_api_constant<
      mp_list<binding_query>,
#ifdef GL_DRAW_BUFFER0
      enum_type_c<GL_DRAW_BUFFER0>,
#else
      enum_type_i,
#endif
      nothing_t,
      true>
      draw_buffer0;

    /// @var major_version
    /// @glconstwrap{MAJOR_VERSION}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_MAJOR_VERSION
      enum_type_c<GL_MAJOR_VERSION>>
#else
      enum_type_i>
#endif
      major_version;

    /// @var minor_version
    /// @glconstwrap{MINOR_VERSION}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_MINOR_VERSION
      enum_type_c<GL_MINOR_VERSION>>
#else
      enum_type_i>
#endif
      minor_version;

    /// @var reset_notification_strategy
    /// @glconstwrap{RESET_NOTIFICATION_STRATEGY}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_RESET_NOTIFICATION_STRATEGY
      enum_type_c<GL_RESET_NOTIFICATION_STRATEGY>,
#else
      enum_type_i,
#endif
      oglp::reset_notification_strategy>
      reset_notification_strategy;

    /// @var num_shading_language_versions
    /// @glconstwrap{NUM_SHADING_LANGUAGE_VERSIONS}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_NUM_SHADING_LANGUAGE_VERSIONS
      enum_type_c<GL_NUM_SHADING_LANGUAGE_VERSIONS>>
#else
      enum_type_i>
#endif
      num_shading_language_versions;

    /// @var num_extensions
    /// @glconstwrap{NUM_EXTENSIONS}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_NUM_EXTENSIONS
      enum_type_c<GL_NUM_EXTENSIONS>>
#else
      enum_type_i>
#endif
      num_extensions;

    /// @var num_spir_v_extensions
    /// @glconstwrap{NUM_SPIR_V_EXTENSIONS}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_NUM_SPIR_V_EXTENSIONS
      enum_type_c<GL_NUM_SPIR_V_EXTENSIONS>>
#else
      enum_type_i>
#endif
      num_spir_v_extensions;

    /// @var context_flags
    /// @glconstwrap{CONTEXT_FLAGS}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_CONTEXT_FLAGS
      enum_type_c<GL_CONTEXT_FLAGS>,
#else
      enum_type_i,
#endif
      enum_bitfield<context_flag_bit>>
      context_flags;

    /// @var context_profile_mask
    /// @glconstwrap{CONTEXT_PROFILE_MASK}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_CONTEXT_PROFILE_MASK
      enum_type_c<GL_CONTEXT_PROFILE_MASK>,
#else
      enum_type_i,
#endif
      enum_bitfield<context_profile_bit>>
      context_profile_mask;

    /// @var doublebuffer
    /// @glconstwrap{DOUBLEBUFFER}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_DOUBLEBUFFER
      enum_type_c<GL_DOUBLEBUFFER>>
#else
      enum_type_i>
#endif
      doublebuffer;

    /// @var stereo
    /// @glconstwrap{STEREO}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_STEREO
      enum_type_c<GL_STEREO>>
#else
      enum_type_i>
#endif
      stereo;

    /// @var clip_origin
    /// @glconstwrap{CLIP_ORIGIN}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_CLIP_ORIGIN
      enum_type_c<GL_CLIP_ORIGIN>>
#else
      enum_type_i>
#endif
      clip_origin;

    /// @var clip_depth_mode
    /// @glconstwrap{CLIP_DEPTH_MODE}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_CLIP_DEPTH_MODE
      enum_type_c<GL_CLIP_DEPTH_MODE>>
#else
      enum_type_i>
#endif
      clip_depth_mode;

    /// @var clamp_read_color
    /// @glconstwrap{CLAMP_READ_COLOR}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_CLAMP_READ_COLOR
      enum_type_c<GL_CLAMP_READ_COLOR>>
#else
      enum_type_i>
#endif
      clamp_read_color;

    /// @var provoking_vertex
    /// @glconstwrap{PROVOKING_VERTEX}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_PROVOKING_VERTEX
      enum_type_c<GL_PROVOKING_VERTEX>,
#else
      enum_type_i,
#endif
      provoke_mode>
      provoking_vertex;

    /// @var layer_provoking_vertex
    /// @glconstwrap{LAYER_PROVOKING_VERTEX}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_LAYER_PROVOKING_VERTEX
      enum_type_c<GL_LAYER_PROVOKING_VERTEX>,
#else
      enum_type_i,
#endif
      provoke_mode>
      layer_provoking_vertex;

    /// @var viewport_index_provoking_vertex
    /// @glconstwrap{VIEWPORT_INDEX_PROVOKING_VERTEX}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
      enum_type_c<GL_VIEWPORT_INDEX_PROVOKING_VERTEX>,
#else
      enum_type_i,
#endif
      provoke_mode>
      viewport_index_provoking_vertex;

    /// @var cull_face_mode
    /// @glconstwrap{CULL_FACE_MODE}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_CULL_FACE_MODE
      enum_type_c<GL_CULL_FACE_MODE>,
#else
      enum_type_i,
#endif
      face_mode>
      cull_face_mode;

    /// @var front_face
    /// @glconstwrap{FRONT_FACE}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_FRONT_FACE
      enum_type_c<GL_FRONT_FACE>,
#else
      enum_type_i,
#endif
      face_orientation>
      front_face;

    /// @var polygon_mode
    /// @glconstwrap{POLYGON_MODE}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_POLYGON_MODE
      enum_type_c<GL_POLYGON_MODE>,
#else
      enum_type_i,
#endif
      oglp::polygon_mode>
      polygon_mode;

    /// @var active_texture
    /// @glconstwrap{ACTIVE_TEXTURE}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_ACTIVE_TEXTURE
      enum_type_c<GL_ACTIVE_TEXTURE>,
#else
      enum_type_i,
#endif
      texture_unit>
      active_texture;

    /// @var stencil_func
    /// @glconstwrap{STENCIL_FUNC}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_STENCIL_FUNC
      enum_type_c<GL_STENCIL_FUNC>>
#else
      enum_type_i>
#endif
      stencil_func;

    /// @var stencil_value_mask
    /// @glconstwrap{STENCIL_VALUE_MASK}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_STENCIL_VALUE_MASK
      enum_type_c<GL_STENCIL_VALUE_MASK>>
#else
      enum_type_i>
#endif
      stencil_value_mask;

    /// @var stencil_ref
    /// @glconstwrap{STENCIL_REF}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_STENCIL_REF
      enum_type_c<GL_STENCIL_REF>>
#else
      enum_type_i>
#endif
      stencil_ref;

    /// @var stencil_fail
    /// @glconstwrap{STENCIL_FAIL}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_STENCIL_FAIL
      enum_type_c<GL_STENCIL_FAIL>>
#else
      enum_type_i>
#endif
      stencil_fail;

    /// @var stencil_pass_depth_pass
    /// @glconstwrap{STENCIL_PASS_DEPTH_PASS}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_STENCIL_PASS_DEPTH_FAIL
      enum_type_c<GL_STENCIL_PASS_DEPTH_FAIL>>
#else
      enum_type_i>
#endif
      stencil_pass_depth_fail;

    /// @var stencil_pass_depth_pass
    /// @glconstwrap{STENCIL_PASS_DEPTH_PASS}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_STENCIL_PASS_DEPTH_PASS
      enum_type_c<GL_STENCIL_PASS_DEPTH_PASS>>
#else
      enum_type_i>
#endif
      stencil_pass_depth_pass;

    /// @var stencil_back_func
    /// @glconstwrap{STENCIL_BACK_FUNC}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_STENCIL_BACK_FUNC
      enum_type_c<GL_STENCIL_BACK_FUNC>>
#else
      enum_type_i>
#endif
      stencil_back_func;

    /// @var stencil_back_value_mask
    /// @glconstwrap{STENCIL_BACK_VALUE_MASK}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_STENCIL_BACK_VALUE_MASK
      enum_type_c<GL_STENCIL_BACK_VALUE_MASK>>
#else
      enum_type_i>
#endif
      stencil_back_value_mask;

    /// @var stencil_back_ref
    /// @glconstwrap{STENCIL_BACK_REF}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_STENCIL_BACK_REF
      enum_type_c<GL_STENCIL_BACK_REF>>
#else
      enum_type_i>
#endif
      stencil_back_ref;

    /// @var stencil_back_fail
    /// @glconstwrap{STENCIL_BACK_FAIL}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_STENCIL_BACK_FAIL
      enum_type_c<GL_STENCIL_BACK_FAIL>>
#else
      enum_type_i>
#endif
      stencil_back_fail;

    /// @var stencil_back_pass_depth_fail
    /// @glconstwrap{STENCIL_BACK_PASS_DEPTH_FAIL}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
      enum_type_c<GL_STENCIL_BACK_PASS_DEPTH_FAIL>>
#else
      enum_type_i>
#endif
      stencil_back_pass_depth_fail;

    /// @var stencil_back_pass_depth_pass
    /// @glconstwrap{STENCIL_BACK_PASS_DEPTH_PASS}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
      enum_type_c<GL_STENCIL_BACK_PASS_DEPTH_PASS>>
#else
      enum_type_i>
#endif
      stencil_back_pass_depth_pass;

    /// @var stencil_writemask
    /// @glconstwrap{STENCIL_WRITEMASK}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_STENCIL_WRITEMASK
      enum_type_c<GL_STENCIL_WRITEMASK>>
#else
      enum_type_i>
#endif
      stencil_writemask;

    /// @var stencil_back_writemask
    /// @glconstwrap{STENCIL_BACK_WRITEMASK}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_STENCIL_BACK_WRITEMASK
      enum_type_c<GL_STENCIL_BACK_WRITEMASK>>
#else
      enum_type_i>
#endif
      stencil_back_writemask;

    /// @var stencil_clear_value
    /// @glconstwrap{STENCIL_CLEAR_VALUE}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_STENCIL_CLEAR_VALUE
      enum_type_c<GL_STENCIL_CLEAR_VALUE>>
#else
      enum_type_i>
#endif
      stencil_clear_value;

    /// @var depth_func
    /// @glconstwrap{DEPTH_FUNC}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_DEPTH_FUNC
      enum_type_c<GL_DEPTH_FUNC>>
#else
      enum_type_i>
#endif
      depth_func;

    /// @var logic_op_mode
    /// @glconstwrap{LOGIC_OP_MODE}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_LOGIC_OP_MODE
      enum_type_c<GL_LOGIC_OP_MODE>>
#else
      enum_type_i>
#endif
      logic_op_mode;

    /// @var sample_buffers
    /// @glconstwrap{SAMPLE_BUFFERS}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_SAMPLE_BUFFERS
      enum_type_c<GL_SAMPLE_BUFFERS>>
#else
      enum_type_i>
#endif
      sample_buffers;

    /// @var subpixel_bits
    /// @glconstwrap{SUBPIXEL_BITS}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_SUBPIXEL_BITS
      enum_type_c<GL_SUBPIXEL_BITS>>
#else
      enum_type_i>
#endif
      subpixel_bits;

    /// @var viewport_subpixel_bits
    /// @glconstwrap{VIEWPORT_SUBPIXEL_BITS}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_VIEWPORT_SUBPIXEL_BITS
      enum_type_c<GL_VIEWPORT_SUBPIXEL_BITS>>
#else
      enum_type_i>
#endif
      viewport_subpixel_bits;

    /// @var num_compressed_texture_formats
    /// @glconstwrap{NUM_COMPRESSED_TEXTURE_FORMATS}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
      enum_type_c<GL_NUM_COMPRESSED_TEXTURE_FORMATS>>
#else
      enum_type_i>
#endif
      num_compressed_texture_formats;

    /// @var compressed_texture_formats
    /// @glconstwrap{COMPRESSED_TEXTURE_FORMATS}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_COMPRESSED_TEXTURE_FORMATS
      enum_type_c<GL_COMPRESSED_TEXTURE_FORMATS>>
#else
      enum_type_i>
#endif
      compressed_texture_formats;

    /// @var num_program_binary_formats
    /// @glconstwrap{NUM_PROGRAM_BINARY_FORMATS}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_NUM_PROGRAM_BINARY_FORMATS
      enum_type_c<GL_NUM_PROGRAM_BINARY_FORMATS>>
#else
      enum_type_i>
#endif
      num_program_binary_formats;

    /// @var program_binary_formats
    /// @glconstwrap{PROGRAM_BINARY_FORMATS}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_PROGRAM_BINARY_FORMATS
      enum_type_c<GL_PROGRAM_BINARY_FORMATS>>
#else
      enum_type_i>
#endif
      program_binary_formats;

    /// @var num_shader_binary_formats
    /// @glconstwrap{NUM_SHADER_BINARY_FORMATS}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_NUM_SHADER_BINARY_FORMATS
      enum_type_c<GL_NUM_SHADER_BINARY_FORMATS>>
#else
      enum_type_i>
#endif
      num_shader_binary_formats;

    /// @var shader_binary_formats
    /// @glconstwrap{SHADER_BINARY_FORMATS}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_SHADER_BINARY_FORMATS
      enum_type_c<GL_SHADER_BINARY_FORMATS>>
#else
      enum_type_i>
#endif
      shader_binary_formats;

    /// @var texture_buffer_offset_alignment
    /// @glconstwrap{TEXTURE_BUFFER_OFFSET_ALIGNMENT}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
      enum_type_c<GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT>>
#else
      enum_type_i>
#endif
      texture_buffer_offset_alignment;

    /// @var max_vertex_uniform_blocks
    /// @glconstwrap{MAX_VERTEX_UNIFORM_BLOCKS}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
      enum_type_c<GL_MAX_VERTEX_UNIFORM_BLOCKS>>
#else
      enum_type_i>
#endif
      max_vertex_uniform_blocks;

    /// @var max_tess_control_uniform_blocks
    /// @glconstwrap{MAX_TESS_CONTROL_UNIFORM_BLOCKS}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
      enum_type_c<GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS>>
#else
      enum_type_i>
#endif
      max_tess_control_uniform_blocks;

    /// @var max_tess_evaluation_uniform_blocks
    /// @glconstwrap{MAX_TESS_EVALUATION_UNIFORM_BLOCKS}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
      enum_type_c<GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS>>
#else
      enum_type_i>
#endif
      max_tess_evaluation_uniform_blocks;

    /// @var max_geometry_uniform_blocks
    /// @glconstwrap{MAX_GEOMETRY_UNIFORM_BLOCKS}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
      enum_type_c<GL_MAX_GEOMETRY_UNIFORM_BLOCKS>>
#else
      enum_type_i>
#endif
      max_geometry_uniform_blocks;

    /// @var max_fragment_uniform_blocks
    /// @glconstwrap{MAX_FRAGMENT_UNIFORM_BLOCKS}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
      enum_type_c<GL_MAX_FRAGMENT_UNIFORM_BLOCKS>>
#else
      enum_type_i>
#endif
      max_fragment_uniform_blocks;

    /// @var max_compute_uniform_blocks
    /// @glconstwrap{MAX_COMPUTE_UNIFORM_BLOCKS}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_MAX_COMPUTE_UNIFORM_BLOCKS
      enum_type_c<GL_MAX_COMPUTE_UNIFORM_BLOCKS>>
#else
      enum_type_i>
#endif
      max_compute_uniform_blocks;

    /// @var max_combined_uniform_blocks
    /// @glconstwrap{MAX_COMBINED_UNIFORM_BLOCKS}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_MAX_COMBINED_UNIFORM_BLOCKS
      enum_type_c<GL_MAX_COMBINED_UNIFORM_BLOCKS>>
#else
      enum_type_i>
#endif
      max_combined_uniform_blocks;

    /// @var max_uniform_block_size
    /// @glconstwrap{MAX_UNIFORM_BLOCK_SIZE}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_MAX_UNIFORM_BLOCK_SIZE
      enum_type_c<GL_MAX_UNIFORM_BLOCK_SIZE>>
#else
      enum_type_i>
#endif
      max_uniform_block_size;

    /// @var max_debug_message_length
    /// @glconstwrap{MAX_DEBUG_MESSAGE_LENGTH}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_MAX_DEBUG_MESSAGE_LENGTH
      enum_type_c<GL_MAX_DEBUG_MESSAGE_LENGTH>>
#elif defined(GL_MAX_DEBUG_MESSAGE_LENGTH_KHR)
      enum_type_c<GL_MAX_DEBUG_MESSAGE_LENGTH_KHR>>
#else
      enum_type_i>
#endif
      max_debug_message_length;

    /// @var max_debug_logged_messages
    /// @glconstwrap{MAX_DEBUG_LOGGED_MESSAGES}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_MAX_DEBUG_LOGGED_MESSAGES
      enum_type_c<GL_MAX_DEBUG_LOGGED_MESSAGES>>
#elif defined(GL_MAX_DEBUG_LOGGED_MESSAGES_KHR)
      enum_type_c<GL_MAX_DEBUG_LOGGED_MESSAGES_KHR>>
#else
      enum_type_i>
#endif
      max_debug_logged_messages;

    /// @var debug_logged_messages
    /// @glconstwrap{DEBUG_LOGGED_MESSAGES}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_DEBUG_LOGGED_MESSAGES
      enum_type_c<GL_DEBUG_LOGGED_MESSAGES>>
#elif defined(GL_DEBUG_LOGGED_MESSAGES_KHR)
      enum_type_c<GL_DEBUG_LOGGED_MESSAGES_KHR>>
#else
      enum_type_i>
#endif
      debug_logged_messages;

    /// @var debug_next_logged_message_length
    /// @glconstwrap{DEBUG_NEXT_LOGGED_MESSAGE_LENGTH}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH
      enum_type_c<GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH>>
#elif defined(GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_KHR)
      enum_type_c<GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_KHR>>
#else
      enum_type_i>
#endif
      debug_next_logged_message_length;

    /// @var max_debug_group_stack_depth
    /// @glconstwrap{MAX_DEBUG_GROUP_STACK_DEPTH}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_MAX_DEBUG_GROUP_STACK_DEPTH
      enum_type_c<GL_MAX_DEBUG_GROUP_STACK_DEPTH>>
#elif defined(GL_MAX_DEBUG_GROUP_STACK_DEPTH_KHR)
      enum_type_c<GL_MAX_DEBUG_GROUP_STACK_DEPTH_KHR>>
#else
      enum_type_i>
#endif
      max_debug_group_stack_depth;

    /// @var debug_group_stack_depth
    /// @glconstwrap{DEBUG_GROUP_STACK_DEPTH}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_DEBUG_GROUP_STACK_DEPTH
      enum_type_c<GL_DEBUG_GROUP_STACK_DEPTH>>
#elif defined(GL_DEBUG_GROUP_STACK_DEPTH_KHR)
      enum_type_c<GL_DEBUG_GROUP_STACK_DEPTH_KHR>>
#else
      enum_type_i>
#endif
      debug_group_stack_depth;

    /// @var max_label_length
    /// @glconstwrap{MAX_LABEL_LENGTH}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_MAX_LABEL_LENGTH
      enum_type_c<GL_MAX_LABEL_LENGTH>>
#elif defined(GL_MAX_LABEL_LENGTH_KHR)
      enum_type_c<GL_MAX_LABEL_LENGTH_KHR>>
#else
      enum_type_i>
#endif
      max_label_length;

    /// @var shader_compiler
    /// @glconstwrap{SHADER_COMPILER}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_SHADER_COMPILER
      enum_type_c<GL_SHADER_COMPILER>,
#else
      enum_type_i,
#endif
      true_false>
      shader_compiler;

    /// @var max_shader_compiler_threads
    /// @glconstwrap{MAX_SHADER_COMPILER_THREADS}
    opt_c_api_constant<
      mp_list<integer_query>,
#ifdef GL_MAX_SHADER_COMPILER_THREADS_ARB
      enum_type_c<GL_MAX_SHADER_COMPILER_THREADS_ARB>>
#else
      enum_type_i>
#endif
      max_shader_compiler_threads;

    /// @var line_width
    /// @glconstwrap{LINE_WIDTH}
    opt_c_api_constant<
      mp_list<float_query>,
#ifdef GL_LINE_WIDTH
      enum_type_c<GL_LINE_WIDTH>>
#else
      enum_type_i>
#endif
      line_width;

    /// @var point_size
    /// @glconstwrap{POINT_SIZE}
    opt_c_api_constant<
      mp_list<float_query>,
#ifdef GL_POINT_SIZE
      enum_type_c<GL_POINT_SIZE>>
#else
      enum_type_i>
#endif
      point_size;

    /// @var polygon_offset_clamp
    /// @glconstwrap{POLYGON_OFFSET_CLAMP}
    opt_c_api_constant<
      mp_list<float_query>,
#ifdef GL_POLYGON_OFFSET_CLAMP
      enum_type_c<GL_POLYGON_OFFSET_CLAMP>>
#else
      enum_type_i>
#endif
      polygon_offset_clamp;

    /// @var polygon_offset_factor
    /// @glconstwrap{POLYGON_OFFSET_FACTOR}
    opt_c_api_constant<
      mp_list<float_query>,
#ifdef GL_POLYGON_OFFSET_FACTOR
      enum_type_c<GL_POLYGON_OFFSET_FACTOR>>
#else
      enum_type_i>
#endif
      polygon_offset_factor;

    /// @var polygon_offset_units
    /// @glconstwrap{POLYGON_OFFSET_UNITS}
    opt_c_api_constant<
      mp_list<float_query>,
#ifdef GL_POLYGON_OFFSET_UNITS
      enum_type_c<GL_POLYGON_OFFSET_UNITS>>
#else
      enum_type_i>
#endif
      polygon_offset_units;

    /// @var sample_coverage_value
    /// @glconstwrap{SAMPLE_COVERAGE_VALUE}
    opt_c_api_constant<
      mp_list<float_query>,
#ifdef GL_SAMPLE_COVERAGE_VALUE
      enum_type_c<GL_SAMPLE_COVERAGE_VALUE>>
#else
      enum_type_i>
#endif
      sample_coverage_value;

    /// @var blend_color
    /// @glconstwrap{BLEND_COLOR}
    opt_c_api_constant<
      mp_list<float_query>,
#ifdef GL_BLEND_COLOR
      enum_type_c<GL_BLEND_COLOR>>
#else
      enum_type_i>
#endif
      blend_color;

    /// @var color_clear_value
    /// @glconstwrap{COLOR_CLEAR_VALUE}
    opt_c_api_constant<
      mp_list<float_query>,
#ifdef GL_COLOR_CLEAR_VALUE
      enum_type_c<GL_COLOR_CLEAR_VALUE>>
#else
      enum_type_i>
#endif
      color_clear_value;

    /// @var depth_clear_value
    /// @glconstwrap{DEPTH_CLEAR_VALUE}
    opt_c_api_constant<
      mp_list<float_query>,
#ifdef GL_DEPTH_CLEAR_VALUE
      enum_type_c<GL_DEPTH_CLEAR_VALUE>>
#else
      enum_type_i>
#endif
      depth_clear_value;

    /// @var viewport_bounds_range
    /// @glconstwrap{VIEWPORT_BOUNDS_RANGE}
    opt_c_api_constant<
      mp_list<float_query>,
#ifdef GL_VIEWPORT_BOUNDS_RANGE
      enum_type_c<GL_VIEWPORT_BOUNDS_RANGE>>
#else
      enum_type_i>
#endif
      viewport_bounds_range;

    /// @var point_size_range
    /// @glconstwrap{POINT_SIZE_RANGE}
    opt_c_api_constant<
      mp_list<float_query>,
#ifdef GL_POINT_SIZE_RANGE
      enum_type_c<GL_POINT_SIZE_RANGE>>
#else
      enum_type_i>
#endif
      point_size_range;

    /// @var point_size_granularity
    /// @glconstwrap{POINT_SIZE_GRANULARITY}
    opt_c_api_constant<
      mp_list<float_query>,
#ifdef GL_POINT_SIZE_GRANULARITY
      enum_type_c<GL_POINT_SIZE_GRANULARITY>>
#else
      enum_type_i>
#endif
      point_size_granularity;

    /// @var aliased_line_width_range
    /// @glconstwrap{ALIASED_LINE_WIDTH_RANGE}
    opt_c_api_constant<
      mp_list<float_query>,
#ifdef GL_ALIASED_LINE_WIDTH_RANGE
      enum_type_c<GL_ALIASED_LINE_WIDTH_RANGE>>
#else
      enum_type_i>
#endif
      aliased_line_width_range;

    /// @var smooth_line_width_range
    /// @glconstwrap{SMOOTH_LINE_WIDTH_RANGE}
    opt_c_api_constant<
      mp_list<float_query>,
#ifdef GL_SMOOTH_LINE_WIDTH_RANGE
      enum_type_c<GL_SMOOTH_LINE_WIDTH_RANGE>>
#else
      enum_type_i>
#endif
      smooth_line_width_range;

    /// @var smooth_line_width_granularity
    /// @glconstwrap{SMOOTH_LINE_WIDTH_GRANULARITY}
    opt_c_api_constant<
      mp_list<float_query>,
#ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
      enum_type_c<GL_SMOOTH_LINE_WIDTH_GRANULARITY>>
#else
      enum_type_i>
#endif
      smooth_line_width_granularity;

    /// @var min_sample_shading_value
    /// @glconstwrap{MIN_SAMPLE_SHADING_VALUE}
    opt_c_api_constant<
      mp_list<float_query>,
#ifdef GL_MIN_SAMPLE_SHADING_VALUE
      enum_type_c<GL_MIN_SAMPLE_SHADING_VALUE>>
#else
      enum_type_i>
#endif
      min_sample_shading_value;

    /// @var min_fragment_interpolation_offset
    /// @glconstwrap{MIN_FRAGMENT_INTERPOLATION_OFFSET}
    opt_c_api_constant<
      mp_list<float_query>,
#ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
      enum_type_c<GL_MIN_FRAGMENT_INTERPOLATION_OFFSET>>
#else
      enum_type_i>
#endif
      min_fragment_interpolation_offset;

    /// @var max_fragment_interpolation_offset
    /// @glconstwrap{MAX_FRAGMENT_INTERPOLATION_OFFSET}
    opt_c_api_constant<
      mp_list<float_query>,
#ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
      enum_type_c<GL_MAX_FRAGMENT_INTERPOLATION_OFFSET>>
#else
      enum_type_i>
#endif
      max_fragment_interpolation_offset;

    /// @var max_texture_lod_bias
    /// @glconstwrap{MAX_TEXTURE_LOD_BIAS}
    opt_c_api_constant<
      mp_list<float_query>,
#ifdef GL_MAX_TEXTURE_LOD_BIAS
      enum_type_c<GL_MAX_TEXTURE_LOD_BIAS>>
#else
      enum_type_i>
#endif
      max_texture_lod_bias;

    /// @var max_texture_max_anisotropy
    /// @glconstwrap{MAX_TEXTURE_MAX_ANISOTROPY}
    opt_c_api_constant<
      mp_list<float_query>,
#ifdef GL_MAX_TEXTURE_MAX_ANISOTROPY
      enum_type_c<GL_MAX_TEXTURE_MAX_ANISOTROPY>>
#else
      enum_type_i>
#endif
      max_texture_max_anisotropy;

    /// @var max_viewport_dims
    /// @glconstwrap{MAX_VIEWPORT_DIMS}
    opt_c_api_constant<
      mp_list<float_query>,
#ifdef GL_MAX_VIEWPORT_DIMS
      enum_type_c<GL_MAX_VIEWPORT_DIMS>>
#else
      enum_type_i>
#endif
      max_viewport_dims;

    /// @var vendor
    /// @glconstwrap{VENDOR}
    opt_c_api_constant<
      mp_list<string_query>,
#ifdef GL_VENDOR
      enum_type_c<GL_VENDOR>>
#else
      enum_type_i>
#endif
      vendor;

    /// @var renderer
    /// @glconstwrap{RENDERER}
    opt_c_api_constant<
      mp_list<string_query>,
#ifdef GL_RENDERER
      enum_type_c<GL_RENDERER>>
#else
      enum_type_i>
#endif
      renderer;

    /// @var version
    /// @glconstwrap{VERSION}
    opt_c_api_constant<
      mp_list<string_query>,
#ifdef GL_VERSION
      enum_type_c<GL_VERSION>>
#else
      enum_type_i>
#endif
      version;

    /// @var shading_language_version
    /// @glconstwrap{SHADING_LANGUAGE_VERSION}
    opt_c_api_constant<
      mp_list<string_query>,
#ifdef GL_SHADING_LANGUAGE_VERSION
      enum_type_c<GL_SHADING_LANGUAGE_VERSION>>
#else
      enum_type_i>
#endif
      shading_language_version;

    /// @var extensions
    /// @glconstwrap{EXTENSIONS}
    opt_c_api_constant<
      mp_list<string_query>,
#ifdef GL_EXTENSIONS
      enum_type_c<GL_EXTENSIONS>>
#else
      enum_type_i>
#endif
      extensions;

    /// @var named_string_length
    /// @glconstwrap{NAMED_STRING_LENGTH_ARB}
    opt_c_api_constant<
      mp_list<named_string_query>,
#ifdef GL_NAMED_STRING_LENGTH_ARB
      enum_type_c<GL_NAMED_STRING_LENGTH_ARB>>
#else
      enum_type_c<0x8DE9>>
#endif
      named_string_length;

    /// @var named_string_type
    /// @glconstwrap{NAMED_STRING_TYPE_ARB}
    opt_c_api_constant<
      mp_list<named_string_query>,
#ifdef GL_NAMED_STRING_TYPE_ARB
      enum_type_c<GL_NAMED_STRING_TYPE_ARB>,
#else
      enum_type_c<0x8DEA>,
#endif
      named_string_kind>
      named_string_type;

    /// @var color_buffer_bit
    /// @glconstwrap{COLOR_BUFFER_BIT}
    opt_c_api_constant<
      mp_list<buffer_clear_bit, buffer_blit_bit>,
#ifdef GL_COLOR_BUFFER_BIT
      bitfield_type_c<GL_COLOR_BUFFER_BIT>>
#else
      bitfield_type_i>
#endif
      color_buffer_bit;

    /// @var depth_buffer_bit
    /// @glconstwrap{DEPTH_BUFFER_BIT}
    opt_c_api_constant<
      mp_list<buffer_clear_bit, buffer_blit_bit>,
#ifdef GL_DEPTH_BUFFER_BIT
      bitfield_type_c<GL_DEPTH_BUFFER_BIT>>
#else
      bitfield_type_i>
#endif
      depth_buffer_bit;

    /// @var stencil_buffer_bit
    /// @glconstwrap{STENCIL_BUFFER_BIT}
    opt_c_api_constant<
      mp_list<buffer_clear_bit, buffer_blit_bit>,
#ifdef GL_STENCIL_BUFFER_BIT
      bitfield_type_c<GL_STENCIL_BUFFER_BIT>>
#else
      bitfield_type_i>
#endif
      stencil_buffer_bit;

    /// @var lequal
    /// @glconstwrap{LEQUAL}
    opt_c_api_constant<
      mp_list<compare_function>,
#ifdef GL_LEQUAL
      enum_type_c<GL_LEQUAL>>
#else
      enum_type_i>
#endif
      lequal;

    /// @var gequal
    /// @glconstwrap{GEQUAL}
    opt_c_api_constant<
      mp_list<compare_function>,
#ifdef GL_GEQUAL
      enum_type_c<GL_GEQUAL>>
#else
      enum_type_i>
#endif
      gequal;

    /// @var less
    /// @glconstwrap{LESS}
    opt_c_api_constant<
      mp_list<compare_function>,
#ifdef GL_LESS
      enum_type_c<GL_LESS>>
#else
      enum_type_i>
#endif
      less;

    /// @var greater
    /// @glconstwrap{GREATER}
    opt_c_api_constant<
      mp_list<compare_function>,
#ifdef GL_GREATER
      enum_type_c<GL_GREATER>>
#else
      enum_type_i>
#endif
      greater;

    /// @var equal
    /// @glconstwrap{EQUAL}
    opt_c_api_constant<
      mp_list<compare_function, tess_gen_primitive_spacing>,
#ifdef GL_EQUAL
      enum_type_c<GL_EQUAL>>
#else
      enum_type_i>
#endif
      equal;

    /// @var notequal
    /// @glconstwrap{NOTEQUAL}
    opt_c_api_constant<
      mp_list<compare_function>,
#ifdef GL_NOTEQUAL
      enum_type_c<GL_NOTEQUAL>>
#else
      enum_type_i>
#endif
      notequal;

    /// @var always
    /// @glconstwrap{ALWAYS}
    opt_c_api_constant<
      mp_list<compare_function>,
#ifdef GL_ALWAYS
      enum_type_c<GL_ALWAYS>>
#else
      enum_type_i>
#endif
      always;

    /// @var never
    /// @glconstwrap{NEVER}
    opt_c_api_constant<
      mp_list<compare_function>,
#ifdef GL_NEVER
      enum_type_c<GL_NEVER>>
#else
      enum_type_i>
#endif
      never;

    /// @var float_
    /// @glconstwrap{FLOAT}
    type_constructor_constant<opt_c_api_constant<
      mp_list<data_type, sl_data_type, pixel_data_type>,
#ifdef GL_FLOAT
      enum_type_c<GL_FLOAT>,
#else
      enum_type_i,
#endif
      typename gl_types::float_type>>
      float_;

    /// @var float_vec2
    /// @glconstwrap{FLOAT_VEC2}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_FLOAT_VEC2
      enum_type_c<GL_FLOAT_VEC2>,
#else
      enum_type_i,
#endif
      typename gl_types::float_type[2]>>
      float_vec2;

    /// @var float_vec3
    /// @glconstwrap{FLOAT_VEC3}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_FLOAT_VEC3
      enum_type_c<GL_FLOAT_VEC3>,
#else
      enum_type_i,
#endif
      typename gl_types::float_type[3]>>
      float_vec3;

    /// @var float_vec4
    /// @glconstwrap{FLOAT_VEC4}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_FLOAT_VEC4
      enum_type_c<GL_FLOAT_VEC4>,
#else
      enum_type_i,
#endif
      typename gl_types::float_type[4]>>
      float_vec4;

    /// @var double_
    /// @glconstwrap{DOUBLE}
    type_constructor_constant<opt_c_api_constant<
      mp_list<data_type, sl_data_type>,
#ifdef GL_DOUBLE
      enum_type_c<GL_DOUBLE>,
#else
      enum_type_i,
#endif
      typename gl_types::double_type>>
      double_;

    /// @var double_vec2
    /// @glconstwrap{DOUBLE_VEC2}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_DOUBLE_VEC2
      enum_type_c<GL_DOUBLE_VEC2>,
#else
      enum_type_i,
#endif
      typename gl_types::double_type[2]>>
      double_vec2;

    /// @var double_vec3
    /// @glconstwrap{DOUBLE_VEC3}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_DOUBLE_VEC3
      enum_type_c<GL_DOUBLE_VEC3>,
#else
      enum_type_i,
#endif
      typename gl_types::double_type[3]>>
      double_vec3;

    /// @var double_vec4
    /// @glconstwrap{DOUBLE_VEC4}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_DOUBLE_VEC4
      enum_type_c<GL_DOUBLE_VEC4>,
#else
      enum_type_i,
#endif
      typename gl_types::double_type[4]>>
      double_vec4;

    /// @var int_
    /// @glconstwrap{INT}
    type_constructor_constant<opt_c_api_constant<
      mp_list<data_type, sl_data_type, pixel_data_type>,
#ifdef GL_INT
      enum_type_c<GL_INT>,
#else
      enum_type_i,
#endif
      typename gl_types::int_type>>
      int_;

    /// @var int_vec2
    /// @glconstwrap{INT_VEC2}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_INT_VEC2
      enum_type_c<GL_INT_VEC2>,
#else
      enum_type_i,
#endif
      typename gl_types::int_type[2]>>
      int_vec2;

    /// @var int_vec3
    /// @glconstwrap{INT_VEC3}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_INT_VEC3
      enum_type_c<GL_INT_VEC3>,
#else
      enum_type_i,
#endif
      typename gl_types::int_type[3]>>
      int_vec3;

    /// @var int_vec4
    /// @glconstwrap{INT_VEC4}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_INT_VEC4
      enum_type_c<GL_INT_VEC4>,
#else
      enum_type_i,
#endif
      typename gl_types::int_type[4]>>
      int_vec4;

    /// @var unsigned_int_
    /// @glconstwrap{UNSIGNED_INT}
    type_constructor_constant<opt_c_api_constant<
      mp_list<data_type, sl_data_type, pixel_data_type, index_data_type>,
#ifdef GL_UNSIGNED_INT
      enum_type_c<GL_UNSIGNED_INT>,
#else
      enum_type_i,
#endif
      typename gl_types::uint_type>>
      unsigned_int_;

    /// @var unsigned_int_vec2
    /// @glconstwrap{UNSIGNED_INT_VEC2}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_UNSIGNED_INT_VEC2
      enum_type_c<GL_UNSIGNED_INT_VEC2>,
#else
      enum_type_i,
#endif
      typename gl_types::uint_type[2]>>
      unsigned_int_vec2;

    /// @var unsigned_int_vec3
    /// @glconstwrap{UNSIGNED_INT_VEC3}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_UNSIGNED_INT_VEC3
      enum_type_c<GL_UNSIGNED_INT_VEC3>,
#else
      enum_type_i,
#endif
      typename gl_types::uint_type[3]>>
      unsigned_int_vec3;

    /// @var unsigned_int_vec4
    /// @glconstwrap{UNSIGNED_INT_VEC4}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_UNSIGNED_INT_VEC4
      enum_type_c<GL_UNSIGNED_INT_VEC4>,
#else
      enum_type_i,
#endif
      typename gl_types::uint_type[4]>>
      unsigned_int_vec4;

    /// @var bool_
    /// @glconstwrap{BOOL}
    type_constructor_constant<opt_c_api_constant<
      mp_list<data_type, sl_data_type>,
#ifdef GL_BOOL
      enum_type_c<GL_BOOL>,
#else
      enum_type_i,
#endif
      typename gl_types::bool_type>>
      bool_;

    /// @var bool_vec2
    /// @glconstwrap{BOOL_VEC2}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_BOOL_VEC2
      enum_type_c<GL_BOOL_VEC2>,
#else
      enum_type_i,
#endif
      typename gl_types::bool_type[2]>>
      bool_vec2;

    /// @var bool_vec3
    /// @glconstwrap{BOOL_VEC3}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_BOOL_VEC3
      enum_type_c<GL_BOOL_VEC3>,
#else
      enum_type_i,
#endif
      typename gl_types::bool_type[3]>>
      bool_vec3;

    /// @var bool_vec4
    /// @glconstwrap{BOOL_VEC4}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_BOOL_VEC4
      enum_type_c<GL_BOOL_VEC4>,
#else
      enum_type_i,
#endif
      typename gl_types::bool_type[4]>>
      bool_vec4;

    /// @var float_mat2
    /// @glconstwrap{FLOAT_MAT2}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_FLOAT_MAT2
      enum_type_c<GL_FLOAT_MAT2>,
#else
      enum_type_i,
#endif
      typename gl_types::float_type[2][2]>>
      float_mat2;

    /// @var float_mat3
    /// @glconstwrap{FLOAT_MAT3}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_FLOAT_MAT3
      enum_type_c<GL_FLOAT_MAT3>,
#else
      enum_type_i,
#endif
      typename gl_types::float_type[3][3]>>
      float_mat3;

    /// @var float_mat4
    /// @glconstwrap{FLOAT_MAT4}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_FLOAT_MAT4
      enum_type_c<GL_FLOAT_MAT4>,
#else
      enum_type_i,
#endif
      typename gl_types::float_type[4][4]>>
      float_mat4;

    /// @var float_mat2x3
    /// @glconstwrap{FLOAT_MAT2x3}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_FLOAT_MAT2x3
      enum_type_c<GL_FLOAT_MAT2x3>,
#else
      enum_type_i,
#endif
      typename gl_types::float_type[2][3]>>
      float_mat2x3;

    /// @var float_mat2x4
    /// @glconstwrap{FLOAT_MAT2x4}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_FLOAT_MAT2x4
      enum_type_c<GL_FLOAT_MAT2x4>,
#else
      enum_type_i,
#endif
      typename gl_types::float_type[2][4]>>
      float_mat2x4;

    /// @var float_mat3x2
    /// @glconstwrap{FLOAT_MAT3x2}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_FLOAT_MAT3x2
      enum_type_c<GL_FLOAT_MAT3x2>,
#else
      enum_type_i,
#endif
      typename gl_types::float_type[3][2]>>
      float_mat3x2;

    /// @var float_mat3x4
    /// @glconstwrap{FLOAT_MAT3x4}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_FLOAT_MAT3x4
      enum_type_c<GL_FLOAT_MAT3x4>,
#else
      enum_type_i,
#endif
      typename gl_types::float_type[3][4]>>
      float_mat3x4;

    /// @var float_mat4x2
    /// @glconstwrap{FLOAT_MAT4x2}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_FLOAT_MAT4x2
      enum_type_c<GL_FLOAT_MAT4x2>,
#else
      enum_type_i,
#endif
      typename gl_types::float_type[4][2]>>
      float_mat4x2;

    /// @var float_mat4x3
    /// @glconstwrap{FLOAT_MAT4x3}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_FLOAT_MAT4x3
      enum_type_c<GL_FLOAT_MAT4x3>,
#else
      enum_type_i,
#endif
      typename gl_types::float_type[4][3]>>
      float_mat4x3;

    /// @var double_mat2
    /// @glconstwrap{DOUBLE_MAT2}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_DOUBLE_MAT2
      enum_type_c<GL_DOUBLE_MAT2>,
#else
      enum_type_i,
#endif
      typename gl_types::double_type[2][2]>>
      double_mat2;

    /// @var double_mat3
    /// @glconstwrap{DOUBLE_MAT3}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_DOUBLE_MAT3
      enum_type_c<GL_DOUBLE_MAT3>,
#else
      enum_type_i,
#endif
      typename gl_types::double_type[3][3]>>
      double_mat3;

    /// @var double_mat4
    /// @glconstwrap{DOUBLE_MAT4}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_DOUBLE_MAT4
      enum_type_c<GL_DOUBLE_MAT4>,
#else
      enum_type_i,
#endif
      typename gl_types::double_type[4][4]>>
      double_mat4;

    /// @var double_mat2x3
    /// @glconstwrap{DOUBLE_MAT2x3}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_DOUBLE_MAT2x3
      enum_type_c<GL_DOUBLE_MAT2x3>,
#else
      enum_type_i,
#endif
      typename gl_types::double_type[2][3]>>
      double_mat2x3;

    /// @var double_mat2x4
    /// @glconstwrap{DOUBLE_MAT2x4}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_DOUBLE_MAT2x4
      enum_type_c<GL_DOUBLE_MAT2x4>,
#else
      enum_type_i,
#endif
      typename gl_types::double_type[2][4]>>
      double_mat2x4;

    /// @var double_mat3x2
    /// @glconstwrap{DOUBLE_MAT3x2}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_DOUBLE_MAT3x2
      enum_type_c<GL_DOUBLE_MAT3x2>,
#else
      enum_type_i,
#endif
      typename gl_types::double_type[3][2]>>
      double_mat3x2;

    /// @var double_mat3x4
    /// @glconstwrap{DOUBLE_MAT3x4}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_DOUBLE_MAT3x4
      enum_type_c<GL_DOUBLE_MAT3x4>,
#else
      enum_type_i,
#endif
      typename gl_types::double_type[3][4]>>
      double_mat3x4;

    /// @var double_mat4x2
    /// @glconstwrap{DOUBLE_MAT4x2}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_DOUBLE_MAT4x2
      enum_type_c<GL_DOUBLE_MAT4x2>,
#else
      enum_type_i,
#endif
      typename gl_types::double_type[4][2]>>
      double_mat4x2;

    /// @var double_mat4x3
    /// @glconstwrap{DOUBLE_MAT4x3}
    type_constructor_constant<opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_DOUBLE_MAT4x3
      enum_type_c<GL_DOUBLE_MAT4x3>,
#else
      enum_type_i,
#endif
      typename gl_types::double_type[4][3]>>
      double_mat4x3;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_SAMPLER_1D
      enum_type_c<GL_SAMPLER_1D>>
#else
      enum_type_i>
#endif
      sampler_1d;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_SAMPLER_2D
      enum_type_c<GL_SAMPLER_2D>>
#else
      enum_type_i>
#endif
      sampler_2d;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_SAMPLER_3D
      enum_type_c<GL_SAMPLER_3D>>
#else
      enum_type_i>
#endif
      sampler_3d;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_SAMPLER_CUBE
      enum_type_c<GL_SAMPLER_CUBE>>
#else
      enum_type_i>
#endif
      sampler_cube;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_SAMPLER_1D_SHADOW
      enum_type_c<GL_SAMPLER_1D_SHADOW>>
#else
      enum_type_i>
#endif
      sampler_1d_shadow;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_SAMPLER_2D_SHADOW
      enum_type_c<GL_SAMPLER_2D_SHADOW>>
#else
      enum_type_i>
#endif
      sampler_2d_shadow;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_SAMPLER_1D_ARRAY
      enum_type_c<GL_SAMPLER_1D_ARRAY>>
#else
      enum_type_i>
#endif
      sampler_1d_array;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_SAMPLER_2D_ARRAY
      enum_type_c<GL_SAMPLER_2D_ARRAY>>
#else
      enum_type_i>
#endif
      sampler_2d_array;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_SAMPLER_CUBE_MAP_ARRAY
      enum_type_c<GL_SAMPLER_CUBE_MAP_ARRAY>>
#else
      enum_type_i>
#endif
      sampler_cube_map_array;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_SAMPLER_1D_ARRAY_SHADOW
      enum_type_c<GL_SAMPLER_1D_ARRAY_SHADOW>>
#else
      enum_type_i>
#endif
      sampler_1d_array_shadow;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_SAMPLER_2D_ARRAY_SHADOW
      enum_type_c<GL_SAMPLER_2D_ARRAY_SHADOW>>
#else
      enum_type_i>
#endif
      sampler_2d_array_shadow;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_SAMPLER_2D_MULTISAMPLE
      enum_type_c<GL_SAMPLER_2D_MULTISAMPLE>>
#else
      enum_type_i>
#endif
      sampler_2d_multisample;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
      enum_type_c<GL_SAMPLER_2D_MULTISAMPLE_ARRAY>>
#else
      enum_type_i>
#endif
      sampler_2d_multisample_array;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_SAMPLER_CUBE_SHADOW
      enum_type_c<GL_SAMPLER_CUBE_SHADOW>>
#else
      enum_type_i>
#endif
      sampler_cube_shadow;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
      enum_type_c<GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW>>
#else
      enum_type_i>
#endif
      sampler_cube_map_array_shadow;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_SAMPLER_BUFFER
      enum_type_c<GL_SAMPLER_BUFFER>>
#else
      enum_type_i>
#endif
      sampler_buffer;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_SAMPLER_2D_RECT
      enum_type_c<GL_SAMPLER_2D_RECT>>
#else
      enum_type_i>
#endif
      sampler_2d_rect;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_SAMPLER_2D_RECT_SHADOW
      enum_type_c<GL_SAMPLER_2D_RECT_SHADOW>>
#else
      enum_type_i>
#endif
      sampler_2d_rect_shadow;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_INT_SAMPLER_1D
      enum_type_c<GL_INT_SAMPLER_1D>>
#else
      enum_type_i>
#endif
      int_sampler_1d;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_INT_SAMPLER_2D
      enum_type_c<GL_INT_SAMPLER_2D>>
#else
      enum_type_i>
#endif
      int_sampler_2d;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_INT_SAMPLER_3D
      enum_type_c<GL_INT_SAMPLER_3D>>
#else
      enum_type_i>
#endif
      int_sampler_3d;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_INT_SAMPLER_CUBE
      enum_type_c<GL_INT_SAMPLER_CUBE>>
#else
      enum_type_i>
#endif
      int_sampler_cube;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_INT_SAMPLER_1D_ARRAY
      enum_type_c<GL_INT_SAMPLER_1D_ARRAY>>
#else
      enum_type_i>
#endif
      int_sampler_1d_array;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_INT_SAMPLER_2D_ARRAY
      enum_type_c<GL_INT_SAMPLER_2D_ARRAY>>
#else
      enum_type_i>
#endif
      int_sampler_2d_array;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
      enum_type_c<GL_INT_SAMPLER_CUBE_MAP_ARRAY>>
#else
      enum_type_i>
#endif
      int_sampler_cube_map_array;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
      enum_type_c<GL_INT_SAMPLER_2D_MULTISAMPLE>>
#else
      enum_type_i>
#endif
      int_sampler_2d_multisample;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
      enum_type_c<GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY>>
#else
      enum_type_i>
#endif
      int_sampler_2d_multisample_array;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_INT_SAMPLER_BUFFER
      enum_type_c<GL_INT_SAMPLER_BUFFER>>
#else
      enum_type_i>
#endif
      int_sampler_buffer;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_INT_SAMPLER_2D_RECT
      enum_type_c<GL_INT_SAMPLER_2D_RECT>>
#else
      enum_type_i>
#endif
      int_sampler_2d_rect;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_UNSIGNED_INT_SAMPLER_1D
      enum_type_c<GL_UNSIGNED_INT_SAMPLER_1D>>
#else
      enum_type_i>
#endif
      unsigned_int_sampler_1d;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_UNSIGNED_INT_SAMPLER_2D
      enum_type_c<GL_UNSIGNED_INT_SAMPLER_2D>>
#else
      enum_type_i>
#endif
      unsigned_int_sampler_2d;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_UNSIGNED_INT_SAMPLER_3D
      enum_type_c<GL_UNSIGNED_INT_SAMPLER_3D>>
#else
      enum_type_i>
#endif
      unsigned_int_sampler_3d;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
      enum_type_c<GL_UNSIGNED_INT_SAMPLER_CUBE>>
#else
      enum_type_i>
#endif
      unsigned_int_sampler_cube;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
      enum_type_c<GL_UNSIGNED_INT_SAMPLER_1D_ARRAY>>
#else
      enum_type_i>
#endif
      unsigned_int_sampler_1d_array;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
      enum_type_c<GL_UNSIGNED_INT_SAMPLER_2D_ARRAY>>
#else
      enum_type_i>
#endif
      unsigned_int_sampler_2d_array;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
      enum_type_c<GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY>>
#else
      enum_type_i>
#endif
      unsigned_int_sampler_cube_map_array;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
      enum_type_c<GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE>>
#else
      enum_type_i>
#endif
      unsigned_int_sampler_2d_multisample;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
      enum_type_c<GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY>>
#else
      enum_type_i>
#endif
      unsigned_int_sampler_2d_multisample_array;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
      enum_type_c<GL_UNSIGNED_INT_SAMPLER_BUFFER>>
#else
      enum_type_i>
#endif
      unsigned_int_sampler_buffer;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
      enum_type_c<GL_UNSIGNED_INT_SAMPLER_2D_RECT>>
#else
      enum_type_i>
#endif
      unsigned_int_sampler_2d_rect;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_IMAGE_1D
      enum_type_c<GL_IMAGE_1D>>
#else
      enum_type_i>
#endif
      image_1d;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_IMAGE_2D
      enum_type_c<GL_IMAGE_2D>>
#else
      enum_type_i>
#endif
      image_2d;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_IMAGE_3D
      enum_type_c<GL_IMAGE_3D>>
#else
      enum_type_i>
#endif
      image_3d;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_IMAGE_2D_RECT
      enum_type_c<GL_IMAGE_2D_RECT>>
#else
      enum_type_i>
#endif
      image_2d_rect;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_IMAGE_CUBE
      enum_type_c<GL_IMAGE_CUBE>>
#else
      enum_type_i>
#endif
      image_cube;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_IMAGE_BUFFER
      enum_type_c<GL_IMAGE_BUFFER>>
#else
      enum_type_i>
#endif
      image_buffer;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_IMAGE_1D_ARRAY
      enum_type_c<GL_IMAGE_1D_ARRAY>>
#else
      enum_type_i>
#endif
      image_1d_array;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_IMAGE_2D_ARRAY
      enum_type_c<GL_IMAGE_2D_ARRAY>>
#else
      enum_type_i>
#endif
      image_2d_array;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_IMAGE_2D_MULTISAMPLE
      enum_type_c<GL_IMAGE_2D_MULTISAMPLE>>
#else
      enum_type_i>
#endif
      image_2d_multisample;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
      enum_type_c<GL_IMAGE_2D_MULTISAMPLE_ARRAY>>
#else
      enum_type_i>
#endif
      image_2d_multisample_array;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_INT_IMAGE_1D
      enum_type_c<GL_INT_IMAGE_1D>>
#else
      enum_type_i>
#endif
      int_image_1d;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_INT_IMAGE_2D
      enum_type_c<GL_INT_IMAGE_2D>>
#else
      enum_type_i>
#endif
      int_image_2d;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_INT_IMAGE_3D
      enum_type_c<GL_INT_IMAGE_3D>>
#else
      enum_type_i>
#endif
      int_image_3d;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_INT_IMAGE_2D_RECT
      enum_type_c<GL_INT_IMAGE_2D_RECT>>
#else
      enum_type_i>
#endif
      int_image_2d_rect;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_INT_IMAGE_CUBE
      enum_type_c<GL_INT_IMAGE_CUBE>>
#else
      enum_type_i>
#endif
      int_image_cube;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_INT_IMAGE_BUFFER
      enum_type_c<GL_INT_IMAGE_BUFFER>>
#else
      enum_type_i>
#endif
      int_image_buffer;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_INT_IMAGE_1D_ARRAY
      enum_type_c<GL_INT_IMAGE_1D_ARRAY>>
#else
      enum_type_i>
#endif
      int_image_1d_array;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_INT_IMAGE_2D_ARRAY
      enum_type_c<GL_INT_IMAGE_2D_ARRAY>>
#else
      enum_type_i>
#endif
      int_image_2d_array;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_INT_IMAGE_2D_MULTISAMPLE
      enum_type_c<GL_INT_IMAGE_2D_MULTISAMPLE>>
#else
      enum_type_i>
#endif
      int_image_2d_multisample;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
      enum_type_c<GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY>>
#else
      enum_type_i>
#endif
      int_image_2d_multisample_array;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_UNSIGNED_INT_IMAGE_1D
      enum_type_c<GL_UNSIGNED_INT_IMAGE_1D>>
#else
      enum_type_i>
#endif
      unsigned_int_image_1d;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_UNSIGNED_INT_IMAGE_2D
      enum_type_c<GL_UNSIGNED_INT_IMAGE_2D>>
#else
      enum_type_i>
#endif
      unsigned_int_image_2d;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_UNSIGNED_INT_IMAGE_3D
      enum_type_c<GL_UNSIGNED_INT_IMAGE_3D>>
#else
      enum_type_i>
#endif
      unsigned_int_image_3d;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
      enum_type_c<GL_UNSIGNED_INT_IMAGE_2D_RECT>>
#else
      enum_type_i>
#endif
      unsigned_int_image_2d_rect;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_UNSIGNED_INT_IMAGE_CUBE
      enum_type_c<GL_UNSIGNED_INT_IMAGE_CUBE>>
#else
      enum_type_i>
#endif
      unsigned_int_image_cube;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
      enum_type_c<GL_UNSIGNED_INT_IMAGE_BUFFER>>
#else
      enum_type_i>
#endif
      unsigned_int_image_buffer;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
      enum_type_c<GL_UNSIGNED_INT_IMAGE_1D_ARRAY>>
#else
      enum_type_i>
#endif
      unsigned_int_image_1d_array;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
      enum_type_c<GL_UNSIGNED_INT_IMAGE_2D_ARRAY>>
#else
      enum_type_i>
#endif
      unsigned_int_image_2d_array;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
      enum_type_c<GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE>>
#else
      enum_type_i>
#endif
      unsigned_int_image_2d_multisample;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
      enum_type_c<GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY>>
#else
      enum_type_i>
#endif
      unsigned_int_image_2d_multisample_array;

    opt_c_api_constant<
      mp_list<sl_data_type>,
#ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
      enum_type_c<GL_UNSIGNED_INT_ATOMIC_COUNTER>>
#else
      enum_type_i>
#endif
      unsigned_int_atomic_counter;

    opt_c_api_constant<
      mp_list<primitive_type, transform_feedback_primitive_type, old_primitive_type>,
#ifdef GL_POINTS
      enum_type_c<GL_POINTS>>
#else
      enum_type_i>
#endif
      points;

    opt_c_api_constant<
      mp_list<primitive_type, old_primitive_type>,
#ifdef GL_LINE_STRIP
      enum_type_c<GL_LINE_STRIP>>
#else
      enum_type_i>
#endif
      line_strip;

    opt_c_api_constant<
      mp_list<primitive_type, old_primitive_type>,
#ifdef GL_LINE_LOOP
      enum_type_c<GL_LINE_LOOP>>
#else
      enum_type_i>
#endif
      line_loop;

    opt_c_api_constant<
      mp_list<primitive_type, old_primitive_type, transform_feedback_primitive_type>,
#ifdef GL_LINES
      enum_type_c<GL_LINES>>
#else
      enum_type_i>
#endif
      lines;

    opt_c_api_constant<
      mp_list<primitive_type, old_primitive_type>,
#ifdef GL_TRIANGLE_STRIP
      enum_type_c<GL_TRIANGLE_STRIP>>
#else
      enum_type_i>
#endif
      triangle_strip;

    opt_c_api_constant<
      mp_list<primitive_type, old_primitive_type>,
#ifdef GL_TRIANGLE_FAN
      enum_type_c<GL_TRIANGLE_FAN>>
#else
      enum_type_i>
#endif
      triangle_fan;

    opt_c_api_constant<
      mp_list<
        primitive_type,
        old_primitive_type,
        tess_gen_primitive_type,
        transform_feedback_primitive_type>,
#ifdef GL_TRIANGLES
      enum_type_c<GL_TRIANGLES>>
#else
      enum_type_i>
#endif
      triangles;

    opt_c_api_constant<
      mp_list<old_primitive_type, tess_gen_primitive_type>,
#ifdef GL_QUADS
      enum_type_c<GL_QUADS>>
#else
      enum_type_i>
#endif
      quads;

    opt_c_api_constant<
      mp_list<old_primitive_type>,
#ifdef GL_QUAD_STRIP
      enum_type_c<GL_QUAD_STRIP>>
#else
      enum_type_i>
#endif
      quad_strip;

    opt_c_api_constant<
      mp_list<old_primitive_type>,
#ifdef GL_POLYGON
      enum_type_c<GL_POLYGON>>
#else
      enum_type_i>
#endif
      polygon;

    opt_c_api_constant<
      mp_list<primitive_type>,
#ifdef GL_LINES_ADJACENCY
      enum_type_c<GL_LINES_ADJACENCY>>
#else
      enum_type_i>
#endif
      lines_adjacency;

    opt_c_api_constant<
      mp_list<primitive_type>,
#ifdef GL_LINE_STRIP_ADJACENCY
      enum_type_c<GL_LINE_STRIP_ADJACENCY>>
#else
      enum_type_i>
#endif
      line_strip_adjacency;

    opt_c_api_constant<
      mp_list<primitive_type>,
#ifdef GL_TRIANGLES_ADJACENCY
      enum_type_c<GL_TRIANGLES_ADJACENCY>>
#else
      enum_type_i>
#endif
      triangles_adjacency;

    opt_c_api_constant<
      mp_list<primitive_type>,
#ifdef GL_TRIANGLE_STRIP_ADJACENCY
      enum_type_c<GL_TRIANGLE_STRIP_ADJACENCY>>
#else
      enum_type_i>
#endif
      triangle_strip_adjacency;

    opt_c_api_constant<
      mp_list<primitive_type>,
#ifdef GL_PATCHES
      enum_type_c<GL_PATCHES>>
#else
      enum_type_i>
#endif
      patches;

    opt_c_api_constant<
      mp_list<tess_gen_primitive_type>,
#ifdef GL_ISOLINES
      enum_type_c<GL_ISOLINES>>
#else
      enum_type_i>
#endif
      isolines;

    opt_c_api_constant<
      mp_list<tess_gen_primitive_spacing>,
#ifdef GL_FRACTIONAL_EVEN
      enum_type_c<GL_FRACTIONAL_EVEN>>
#else
      enum_type_i>
#endif
      fractional_even;

    opt_c_api_constant<
      mp_list<tess_gen_primitive_spacing>,
#ifdef GL_FRACTIONAL_ODD
      enum_type_c<GL_FRACTIONAL_ODD>>
#else
      enum_type_i>
#endif
      fractional_odd;

    opt_c_api_constant<
      mp_list<patch_parameter, integer_query>,
#ifdef GL_PATCH_VERTICES
      enum_type_c<GL_PATCH_VERTICES>>
#else
      enum_type_i>
#endif
      patch_vertices;

    opt_c_api_constant<
      mp_list<patch_parameter, float_query>,
#ifdef GL_PATCH_DEFAULT_OUTER_LEVEL
      enum_type_c<GL_PATCH_DEFAULT_OUTER_LEVEL>>
#else
      enum_type_i>
#endif
      patch_default_outer_level;

    opt_c_api_constant<
      mp_list<patch_parameter, float_query>,
#ifdef GL_PATCH_DEFAULT_INNER_LEVEL
      enum_type_c<GL_PATCH_DEFAULT_INNER_LEVEL>>
#else
      enum_type_i>
#endif
      patch_default_inner_level;

    opt_c_api_constant<
      mp_list<face_orientation>,
#ifdef GL_CW
      enum_type_c<GL_CW>>
#else
      enum_type_i>
#endif
      cw;

    opt_c_api_constant<
      mp_list<face_orientation>,
#ifdef GL_CCW
      enum_type_c<GL_CCW>>
#else
      enum_type_i>
#endif
      ccw;

    opt_c_api_constant<
      mp_list<provoke_mode>,
#ifdef GL_FIRST_VERTEX_CONVENTION
      enum_type_c<GL_FIRST_VERTEX_CONVENTION>>
#else
      enum_type_i>
#endif
      first_vertex_convention;

    opt_c_api_constant<
      mp_list<provoke_mode>,
#ifdef GL_LAST_VERTEX_CONVENTION
      enum_type_c<GL_LAST_VERTEX_CONVENTION>>
#else
      enum_type_i>
#endif
      last_vertex_convention;

    opt_c_api_constant<
      mp_list<conditional_render_mode>,
#ifdef GL_QUERY_WAIT
      enum_type_c<GL_QUERY_WAIT>>
#else
      enum_type_i>
#endif
      query_wait;

    opt_c_api_constant<
      mp_list<conditional_render_mode>,
#ifdef GL_QUERY_NO_WAIT
      enum_type_c<GL_QUERY_NO_WAIT>>
#else
      enum_type_i>
#endif
      query_no_wait;

    opt_c_api_constant<
      mp_list<conditional_render_mode>,
#ifdef GL_QUERY_BY_REGION_WAIT
      enum_type_c<GL_QUERY_BY_REGION_WAIT>>
#else
      enum_type_i>
#endif
      query_by_region_wait;

    opt_c_api_constant<
      mp_list<conditional_render_mode>,
#ifdef GL_QUERY_BY_REGION_NO_WAIT
      enum_type_c<GL_QUERY_BY_REGION_NO_WAIT>>
#else
      enum_type_i>
#endif
      query_by_region_no_wait;

    opt_c_api_constant<
      mp_list<conditional_render_mode>,
#ifdef GL_QUERY_WAIT_INVERTED
      enum_type_c<GL_QUERY_WAIT_INVERTED>>
#else
      enum_type_i>
#endif
      query_wait_inverted;

    opt_c_api_constant<
      mp_list<conditional_render_mode>,
#ifdef GL_QUERY_NO_WAIT_INVERTED
      enum_type_c<GL_QUERY_NO_WAIT_INVERTED>>
#else
      enum_type_i>
#endif
      query_no_wait_inverted;

    opt_c_api_constant<
      mp_list<conditional_render_mode>,
#ifdef GL_QUERY_BY_REGION_WAIT_INVERTED
      enum_type_c<GL_QUERY_BY_REGION_WAIT_INVERTED>>
#else
      enum_type_i>
#endif
      query_by_region_wait_inverted;

    opt_c_api_constant<
      mp_list<conditional_render_mode>,
#ifdef GL_QUERY_BY_REGION_NO_WAIT_INVERTED
      enum_type_c<GL_QUERY_BY_REGION_NO_WAIT_INVERTED>>
#else
      enum_type_i>
#endif
      query_by_region_no_wait_inverted;

    opt_c_api_constant<
      mp_list<point_parameter>,
#ifdef GL_POINT_SIZE_MIN
      enum_type_c<GL_POINT_SIZE_MIN>>
#else
      enum_type_i>
#endif
      point_size_min;

    opt_c_api_constant<
      mp_list<point_parameter>,
#ifdef GL_POINT_SIZE_MAX
      enum_type_c<GL_POINT_SIZE_MAX>>
#else
      enum_type_i>
#endif
      point_size_max;

    opt_c_api_constant<
      mp_list<point_parameter, float_query>,
#ifdef GL_POINT_FADE_THRESHOLD_SIZE
      enum_type_c<GL_POINT_FADE_THRESHOLD_SIZE>>
#else
      enum_type_i>
#endif
      point_fade_threshold_size;

    opt_c_api_constant<
      mp_list<point_parameter, integer_query>,
#ifdef GL_POINT_SPRITE_COORD_ORIGIN
      enum_type_c<GL_POINT_SPRITE_COORD_ORIGIN>,
#else
      enum_type_i,
#endif
      oglp::point_sprite_coord_origin>
      point_sprite_coord_origin;

    opt_c_api_constant<
      mp_list<oglp::point_sprite_coord_origin>,
#ifdef GL_LOWER_LEFT
      enum_type_c<GL_LOWER_LEFT>>
#else
      enum_type_i>
#endif
      lower_left;

    opt_c_api_constant<
      mp_list<oglp::point_sprite_coord_origin>,
#ifdef GL_UPPER_LEFT
      enum_type_c<GL_UPPER_LEFT>>
#else
      enum_type_i>
#endif
      upper_left;

    opt_c_api_constant<
      mp_list<oglp::polygon_mode>,
#ifdef GL_POINT
      enum_type_c<GL_POINT>>
#else
      enum_type_i>
#endif
      point;

    opt_c_api_constant<
      mp_list<oglp::polygon_mode>,
#ifdef GL_LINE
      enum_type_c<GL_LINE>>
#else
      enum_type_i>
#endif
      line;

    opt_c_api_constant<
      mp_list<oglp::polygon_mode>,
#ifdef GL_FILL
      enum_type_c<GL_FILL>>
#else
      enum_type_i>
#endif
      fill;

    opt_c_api_constant<
      mp_list<oglp::polygon_mode>,
#ifdef GL_FILL_RECTANGLE_NV
      enum_type_c<GL_FILL_RECTANGLE_NV>>
#else
      enum_type_i>
#endif
      fill_rectangle_nv;

    opt_c_api_constant<
      mp_list<stencil_operation>,
#ifdef GL_KEEP
      enum_type_c<GL_KEEP>>
#else
      enum_type_i>
#endif
      keep;

    opt_c_api_constant<
      mp_list<stencil_operation>,
#ifdef GL_REPLACE
      enum_type_c<GL_REPLACE>>
#else
      enum_type_i>
#endif
      replace;

    opt_c_api_constant<
      mp_list<stencil_operation>,
#ifdef GL_INCR
      enum_type_c<GL_INCR>>
#else
      enum_type_i>
#endif
      incr;

    opt_c_api_constant<
      mp_list<stencil_operation>,
#ifdef GL_DECR
      enum_type_c<GL_DECR>>
#else
      enum_type_i>
#endif
      decr;

    opt_c_api_constant<
      mp_list<stencil_operation, logic_operation, oglp::path_fill_mode_nv>,
#ifdef GL_INVERT
      enum_type_c<GL_INVERT>>
#else
      enum_type_i>
#endif
      invert;

    opt_c_api_constant<
      mp_list<stencil_operation>,
#ifdef GL_INCR_WRAP
      enum_type_c<GL_INCR_WRAP>>
#else
      enum_type_i>
#endif
      incr_wrap;

    opt_c_api_constant<
      mp_list<stencil_operation>,
#ifdef GL_DECR_WRAP
      enum_type_c<GL_DECR_WRAP>>
#else
      enum_type_i>
#endif
      decr_wrap;

    opt_c_api_constant<
      mp_list<logic_operation>,
#ifdef GL_CLEAR
      enum_type_c<GL_CLEAR>>
#else
      enum_type_i>
#endif
      clear;

    opt_c_api_constant<
      mp_list<logic_operation>,
#ifdef GL_AND
      enum_type_c<GL_AND>>
#else
      enum_type_i>
#endif
      and_;

    opt_c_api_constant<
      mp_list<logic_operation>,
#ifdef GL_AND_REVERSE
      enum_type_c<GL_AND_REVERSE>>
#else
      enum_type_i>
#endif
      and_reverse;

    opt_c_api_constant<
      mp_list<logic_operation>,
#ifdef GL_COPY
      enum_type_c<GL_COPY>>
#else
      enum_type_i>
#endif
      copy;

    opt_c_api_constant<
      mp_list<logic_operation>,
#ifdef GL_AND_INVERTED
      enum_type_c<GL_AND_INVERTED>>
#else
      enum_type_i>
#endif
      and_inverted;

    opt_c_api_constant<
      mp_list<logic_operation>,
#ifdef GL_NOOP
      enum_type_c<GL_NOOP>>
#else
      enum_type_i>
#endif
      noop;

    opt_c_api_constant<
      mp_list<logic_operation>,
#ifdef GL_XOR
      enum_type_c<GL_XOR>>
#else
      enum_type_i>
#endif
      xor_;

    opt_c_api_constant<
      mp_list<logic_operation>,
#ifdef GL_OR
      enum_type_c<GL_OR>>
#else
      enum_type_i>
#endif
      or_;

    opt_c_api_constant<
      mp_list<logic_operation>,
#ifdef GL_NOR
      enum_type_c<GL_NOR>>
#else
      enum_type_i>
#endif
      nor;

    opt_c_api_constant<
      mp_list<logic_operation>,
#ifdef GL_EQUIV
      enum_type_c<GL_EQUIV>>
#else
      enum_type_i>
#endif
      equiv;

    opt_c_api_constant<
      mp_list<logic_operation>,
#ifdef GL_OR_REVERSE
      enum_type_c<GL_OR_REVERSE>>
#else
      enum_type_i>
#endif
      or_reverse;

    opt_c_api_constant<
      mp_list<logic_operation>,
#ifdef GL_COPY_INVERTED
      enum_type_c<GL_COPY_INVERTED>>
#else
      enum_type_i>
#endif
      copy_inverted;

    opt_c_api_constant<
      mp_list<logic_operation>,
#ifdef GL_OR_INVERTED
      enum_type_c<GL_OR_INVERTED>>
#else
      enum_type_i>
#endif
      or_inverted;

    opt_c_api_constant<
      mp_list<logic_operation>,
#ifdef GL_NAND
      enum_type_c<GL_NAND>>
#else
      enum_type_i>
#endif
      nand;

    opt_c_api_constant<
      mp_list<logic_operation>,
#ifdef GL_SET
      enum_type_c<GL_SET>>
#else
      enum_type_i>
#endif
      set;

    opt_c_api_constant<
      mp_list<blend_equation>,
#ifdef GL_FUNC_ADD
      enum_type_c<GL_FUNC_ADD>>
#else
      enum_type_i>
#endif
      func_add;

    opt_c_api_constant<
      mp_list<blend_equation>,
#ifdef GL_FUNC_SUBTRACT
      enum_type_c<GL_FUNC_SUBTRACT>>
#else
      enum_type_i>
#endif
      func_subtract;

    opt_c_api_constant<
      mp_list<blend_equation>,
#ifdef GL_FUNC_REVERSE_SUBTRACT
      enum_type_c<GL_FUNC_REVERSE_SUBTRACT>>
#else
      enum_type_i>
#endif
      func_reverse_subtract;

    opt_c_api_constant<
      mp_list<blend_equation>,
#ifdef GL_MIN
      enum_type_c<GL_MIN>>
#else
      enum_type_i>
#endif
      min;

    opt_c_api_constant<
      mp_list<blend_equation>,
#ifdef GL_MAX
      enum_type_c<GL_MAX>>
#else
      enum_type_i>
#endif
      max;

    opt_c_api_constant<
      mp_list<blend_equation_advanced>,
#ifdef GL_MULTIPLY_KHR
      enum_type_c<GL_MULTIPLY_KHR>>
#else
      enum_type_i>
#endif
      multiply_khr;

    opt_c_api_constant<
      mp_list<blend_equation_advanced>,
#ifdef GL_SCREEN_KHR
      enum_type_c<GL_SCREEN_KHR>>
#else
      enum_type_i>
#endif
      screen_khr;

    opt_c_api_constant<
      mp_list<blend_equation_advanced>,
#ifdef GL_OVERLAY_KHR
      enum_type_c<GL_OVERLAY_KHR>>
#else
      enum_type_i>
#endif
      overlay_khr;

    opt_c_api_constant<
      mp_list<blend_equation_advanced>,
#ifdef GL_DARKEN_KHR
      enum_type_c<GL_DARKEN_KHR>>
#else
      enum_type_i>
#endif
      darken_khr;

    opt_c_api_constant<
      mp_list<blend_equation_advanced>,
#ifdef GL_LIGHTEN_KHR
      enum_type_c<GL_LIGHTEN_KHR>>
#else
      enum_type_i>
#endif
      lighten_khr;

    opt_c_api_constant<
      mp_list<blend_equation_advanced>,
#ifdef GL_COLORDODGE_KHR
      enum_type_c<GL_COLORDODGE_KHR>>
#else
      enum_type_i>
#endif
      colordodge_khr;

    opt_c_api_constant<
      mp_list<blend_equation_advanced>,
#ifdef GL_COLORBURN_KHR
      enum_type_c<GL_COLORBURN_KHR>>
#else
      enum_type_i>
#endif
      colorburn_khr;

    opt_c_api_constant<
      mp_list<blend_equation_advanced>,
#ifdef GL_HARDLIGHT_KHR
      enum_type_c<GL_HARDLIGHT_KHR>>
#else
      enum_type_i>
#endif
      hardlight_khr;

    opt_c_api_constant<
      mp_list<blend_equation_advanced>,
#ifdef GL_SOFTLIGHT_KHR
      enum_type_c<GL_SOFTLIGHT_KHR>>
#else
      enum_type_i>
#endif
      softlight_khr;

    opt_c_api_constant<
      mp_list<blend_equation_advanced>,
#ifdef GL_DIFFERENCE_KHR
      enum_type_c<GL_DIFFERENCE_KHR>>
#else
      enum_type_i>
#endif
      difference_khr;

    opt_c_api_constant<
      mp_list<blend_equation_advanced>,
#ifdef GL_EXCLUSION_KHR
      enum_type_c<GL_EXCLUSION_KHR>>
#else
      enum_type_i>
#endif
      exclusion_khr;

    opt_c_api_constant<
      mp_list<blend_equation_advanced>,
#ifdef GL_HSL_HUE_KHR
      enum_type_c<GL_HSL_HUE_KHR>>
#else
      enum_type_i>
#endif
      hsl_hue_khr;

    opt_c_api_constant<
      mp_list<blend_equation_advanced>,
#ifdef GL_HSL_SATURATION_KHR
      enum_type_c<GL_HSL_SATURATION_KHR>>
#else
      enum_type_i>
#endif
      hsl_saturation_khr;

    opt_c_api_constant<
      mp_list<blend_equation_advanced>,
#ifdef GL_HSL_COLOR_KHR
      enum_type_c<GL_HSL_COLOR_KHR>>
#else
      enum_type_i>
#endif
      hsl_color_khr;

    opt_c_api_constant<
      mp_list<blend_equation_advanced>,
#ifdef GL_HSL_LUMINOSITY_KHR
      enum_type_c<GL_HSL_LUMINOSITY_KHR>>
#else
      enum_type_i>
#endif
      hsl_luminosity_khr;

    opt_c_api_constant<
      mp_list<blend_function>,
#ifdef GL_SRC_COLOR
      enum_type_c<GL_SRC_COLOR>>
#else
      enum_type_i>
#endif
      src_color;

    opt_c_api_constant<
      mp_list<blend_function>,
#ifdef GL_ONE_MINUS_SRC_COLOR
      enum_type_c<GL_ONE_MINUS_SRC_COLOR>>
#else
      enum_type_i>
#endif
      one_minus_src_color;

    opt_c_api_constant<
      mp_list<blend_function>,
#ifdef GL_DST_COLOR
      enum_type_c<GL_DST_COLOR>>
#else
      enum_type_i>
#endif
      dst_color;

    opt_c_api_constant<
      mp_list<blend_function>,
#ifdef GL_ONE_MINUS_DST_COLOR
      enum_type_c<GL_ONE_MINUS_DST_COLOR>>
#else
      enum_type_i>
#endif
      one_minus_dst_color;

    opt_c_api_constant<
      mp_list<blend_function>,
#ifdef GL_SRC_ALPHA
      enum_type_c<GL_SRC_ALPHA>>
#else
      enum_type_i>
#endif
      src_alpha;

    opt_c_api_constant<
      mp_list<blend_function>,
#ifdef GL_ONE_MINUS_SRC_ALPHA
      enum_type_c<GL_ONE_MINUS_SRC_ALPHA>>
#else
      enum_type_i>
#endif
      one_minus_src_alpha;

    opt_c_api_constant<
      mp_list<blend_function>,
#ifdef GL_DST_ALPHA
      enum_type_c<GL_DST_ALPHA>>
#else
      enum_type_i>
#endif
      dst_alpha;

    opt_c_api_constant<
      mp_list<blend_function>,
#ifdef GL_ONE_MINUS_DST_ALPHA
      enum_type_c<GL_ONE_MINUS_DST_ALPHA>>
#else
      enum_type_i>
#endif
      one_minus_dst_alpha;

    opt_c_api_constant<
      mp_list<blend_function>,
#ifdef GL_CONSTANT_COLOR
      enum_type_c<GL_CONSTANT_COLOR>>
#else
      enum_type_i>
#endif
      constant_color;

    opt_c_api_constant<
      mp_list<blend_function>,
#ifdef GL_ONE_MINUS_CONSTANT_COLOR
      enum_type_c<GL_ONE_MINUS_CONSTANT_COLOR>>
#else
      enum_type_i>
#endif
      one_minus_constant_color;

    opt_c_api_constant<
      mp_list<blend_function>,
#ifdef GL_CONSTANT_ALPHA
      enum_type_c<GL_CONSTANT_ALPHA>>
#else
      enum_type_i>
#endif
      constant_alpha;

    opt_c_api_constant<
      mp_list<blend_function>,
#ifdef GL_ONE_MINUS_CONSTANT_ALPHA
      enum_type_c<GL_ONE_MINUS_CONSTANT_ALPHA>>
#else
      enum_type_i>
#endif
      one_minus_constant_alpha;

    opt_c_api_constant<
      mp_list<blend_function>,
#ifdef GL_SRC_ALPHA_SATURATE
      enum_type_c<GL_SRC_ALPHA_SATURATE>>
#else
      enum_type_i>
#endif
      src_alpha_saturate;

    opt_c_api_constant<
      mp_list<blend_function>,
#ifdef GL_SRC1_COLOR
      enum_type_c<GL_SRC1_COLOR>>
#else
      enum_type_i>
#endif
      src1_color;

    opt_c_api_constant<
      mp_list<blend_function>,
#ifdef GL_ONE_MINUS_SRC1_COLOR
      enum_type_c<GL_ONE_MINUS_SRC1_COLOR>>
#else
      enum_type_i>
#endif
      one_minus_src1_color;

    opt_c_api_constant<
      mp_list<blend_function>,
#ifdef GL_SRC1_ALPHA
      enum_type_c<GL_SRC1_ALPHA>>
#else
      enum_type_i>
#endif
      src1_alpha;

    opt_c_api_constant<
      mp_list<blend_function>,
#ifdef GL_ONE_MINUS_SRC1_ALPHA
      enum_type_c<GL_ONE_MINUS_SRC1_ALPHA>>
#else
      enum_type_i>
#endif
      one_minus_src1_alpha;

    /// @var unsigned_byte_
    /// @glconstwrap{UNSIGNED_BYTE}
    type_constructor_constant<opt_c_api_constant<
      mp_list<data_type, pixel_data_type, index_data_type>,
#ifdef GL_UNSIGNED_BYTE
      enum_type_c<GL_UNSIGNED_BYTE>,
#else
      enum_type_i,
#endif
      typename gl_types::ubyte_type>>
      unsigned_byte_;

    /// @var byte_
    /// @glconstwrap{BYTE}
    opt_c_api_constant<
      mp_list<data_type, pixel_data_type>,
#ifdef GL_BYTE
      enum_type_c<GL_BYTE>>
#else
      enum_type_i>
#endif
      byte_;

    opt_c_api_constant<
      mp_list<pixel_data_type, data_type, index_data_type>,
#ifdef GL_UNSIGNED_SHORT
      enum_type_c<GL_UNSIGNED_SHORT>>
#else
      enum_type_i>
#endif
      unsigned_short_;

    type_constructor_constant<opt_c_api_constant<
      mp_list<pixel_data_type, data_type>,
#ifdef GL_SHORT
      enum_type_c<GL_SHORT>,
#else
      enum_type_i,
#endif
      typename gl_types::short_type>>
      short_;

    opt_c_api_constant<
      mp_list<pixel_data_type>,
#ifdef GL_HALF_FLOAT
      enum_type_c<GL_HALF_FLOAT>>
#else
      enum_type_i>
#endif
      half_float_;

    opt_c_api_constant<
      mp_list<pixel_data_type>,
#ifdef GL_UNSIGNED_BYTE_3_3_2
      enum_type_c<GL_UNSIGNED_BYTE_3_3_2>>
#else
      enum_type_i>
#endif
      unsigned_byte_3_3_2;

    opt_c_api_constant<
      mp_list<pixel_data_type>,
#ifdef GL_UNSIGNED_BYTE_2_3_3_REV
      enum_type_c<GL_UNSIGNED_BYTE_2_3_3_REV>>
#else
      enum_type_i>
#endif
      unsigned_byte_2_3_3_rev;

    opt_c_api_constant<
      mp_list<pixel_data_type>,
#ifdef GL_UNSIGNED_SHORT_5_6_5
      enum_type_c<GL_UNSIGNED_SHORT_5_6_5>>
#else
      enum_type_i>
#endif
      unsigned_short_5_6_5;

    opt_c_api_constant<
      mp_list<pixel_data_type>,
#ifdef GL_UNSIGNED_SHORT_5_6_5_REV
      enum_type_c<GL_UNSIGNED_SHORT_5_6_5_REV>>
#else
      enum_type_i>
#endif
      unsigned_short_5_6_5_rev;

    opt_c_api_constant<
      mp_list<pixel_data_type>,
#ifdef GL_UNSIGNED_SHORT_4_4_4_4
      enum_type_c<GL_UNSIGNED_SHORT_4_4_4_4>>
#else
      enum_type_i>
#endif
      unsigned_short_4_4_4_4;

    opt_c_api_constant<
      mp_list<pixel_data_type>,
#ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
      enum_type_c<GL_UNSIGNED_SHORT_4_4_4_4_REV>>
#else
      enum_type_i>
#endif
      unsigned_short_4_4_4_4_rev;

    opt_c_api_constant<
      mp_list<pixel_data_type>,
#ifdef GL_UNSIGNED_SHORT_5_5_5_1
      enum_type_c<GL_UNSIGNED_SHORT_5_5_5_1>>
#else
      enum_type_i>
#endif
      unsigned_short_5_5_5_1;

    opt_c_api_constant<
      mp_list<pixel_data_type>,
#ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
      enum_type_c<GL_UNSIGNED_SHORT_1_5_5_5_REV>>
#else
      enum_type_i>
#endif
      unsigned_short_1_5_5_5_rev;

    opt_c_api_constant<
      mp_list<pixel_data_type>,
#ifdef GL_UNSIGNED_INT_8_8_8_8
      enum_type_c<GL_UNSIGNED_INT_8_8_8_8>>
#else
      enum_type_i>
#endif
      unsigned_int_8_8_8_8;

    opt_c_api_constant<
      mp_list<pixel_data_type>,
#ifdef GL_UNSIGNED_INT_8_8_8_8_REV
      enum_type_c<GL_UNSIGNED_INT_8_8_8_8_REV>>
#else
      enum_type_i>
#endif
      unsigned_int_8_8_8_8_rev;

    opt_c_api_constant<
      mp_list<pixel_data_type>,
#ifdef GL_UNSIGNED_INT_10_10_10_2
      enum_type_c<GL_UNSIGNED_INT_10_10_10_2>>
#else
      enum_type_i>
#endif
      unsigned_int_10_10_10_2;

    opt_c_api_constant<
      mp_list<pixel_data_type>,
#ifdef GL_UNSIGNED_INT_2_10_10_10_REV
      enum_type_c<GL_UNSIGNED_INT_2_10_10_10_REV>>
#else
      enum_type_i>
#endif
      unsigned_int_2_10_10_10_rev;

    opt_c_api_constant<
      mp_list<pixel_data_type>,
#ifdef GL_UNSIGNED_INT_24_8
      enum_type_c<GL_UNSIGNED_INT_24_8>>
#else
      enum_type_i>
#endif
      unsigned_int_24_8;

    opt_c_api_constant<
      mp_list<pixel_data_type>,
#ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
      enum_type_c<GL_UNSIGNED_INT_10F_11F_11F_REV>>
#else
      enum_type_i>
#endif
      unsigned_int_10f_11f_11f_rev;

    opt_c_api_constant<
      mp_list<pixel_data_type>,
#ifdef GL_UNSIGNED_INT_5_9_9_9_REV
      enum_type_c<GL_UNSIGNED_INT_5_9_9_9_REV>>
#else
      enum_type_i>
#endif
      unsigned_int_5_9_9_9_rev;

    opt_c_api_constant<
      mp_list<pixel_data_type>,
#ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
      enum_type_c<GL_FLOAT_32_UNSIGNED_INT_24_8_REV>>
#else
      enum_type_i>
#endif
      float_32_unsigned_int_24_8_rev;

    opt_c_api_constant<
      mp_list<pixel_format>,
#ifdef GL_STENCIL_INDEX
      enum_type_c<GL_STENCIL_INDEX>>
#else
      enum_type_i>
#endif
      stencil_index;

    opt_c_api_constant<
      mp_list<pixel_format>,
#ifdef GL_BGR
      enum_type_c<GL_BGR>>
#else
      enum_type_i>
#endif
      bgr;

    opt_c_api_constant<
      mp_list<pixel_format>,
#ifdef GL_BGRA
      enum_type_c<GL_BGRA>>
#else
      enum_type_i>
#endif
      bgra;

    opt_c_api_constant<
      mp_list<pixel_format>,
#ifdef GL_RED_INTEGER
      enum_type_c<GL_RED_INTEGER>>
#else
      enum_type_i>
#endif
      red_integer;

    opt_c_api_constant<
      mp_list<pixel_format>,
#ifdef GL_GREEN_INTEGER
      enum_type_c<GL_GREEN_INTEGER>>
#else
      enum_type_i>
#endif
      green_integer;

    opt_c_api_constant<
      mp_list<pixel_format>,
#ifdef GL_BLUE_INTEGER
      enum_type_c<GL_BLUE_INTEGER>>
#else
      enum_type_i>
#endif
      blue_integer;

    opt_c_api_constant<
      mp_list<pixel_format>,
#ifdef GL_RG_INTEGER
      enum_type_c<GL_RG_INTEGER>>
#else
      enum_type_i>
#endif
      rg_integer;

    opt_c_api_constant<
      mp_list<pixel_format>,
#ifdef GL_RGB_INTEGER
      enum_type_c<GL_RGB_INTEGER>>
#else
      enum_type_i>
#endif
      rgb_integer;

    opt_c_api_constant<
      mp_list<pixel_format>,
#ifdef GL_RGBA_INTEGER
      enum_type_c<GL_RGBA_INTEGER>>
#else
      enum_type_i>
#endif
      rgba_integer;

    opt_c_api_constant<
      mp_list<pixel_format>,
#ifdef GL_BGR_INTEGER
      enum_type_c<GL_BGR_INTEGER>>
#else
      enum_type_i>
#endif
      bgr_integer;

    opt_c_api_constant<
      mp_list<pixel_format>,
#ifdef GL_BGRA_INTEGER
      enum_type_c<GL_BGRA_INTEGER>>
#else
      enum_type_i>
#endif
      bgra_integer;

    opt_c_api_constant<
      mp_list<pixel_internal_format, pixel_format>,
#ifdef GL_DEPTH_COMPONENT
      enum_type_c<GL_DEPTH_COMPONENT>>
#else
      enum_type_i>
#endif
      depth_component;

    opt_c_api_constant<
      mp_list<pixel_internal_format, pixel_format, framebuffer_buffer>,
#ifdef GL_DEPTH_STENCIL
      enum_type_c<GL_DEPTH_STENCIL>>
#else
      enum_type_i>
#endif
      depth_stencil;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_STENCIL_INDEX8
      enum_type_c<GL_STENCIL_INDEX8>>
#else
      enum_type_i>
#endif
      stencil_index8;

    opt_c_api_constant<
      mp_list<pixel_internal_format, pixel_format>,
#ifdef GL_RG
      enum_type_c<GL_RG>>
#else
      enum_type_i>
#endif
      rg;

    opt_c_api_constant<
      mp_list<pixel_internal_format, pixel_format, path_color_format_nv>,
#ifdef GL_RGB
      enum_type_c<GL_RGB>>
#else
      enum_type_i>
#endif
      rgb;

    opt_c_api_constant<
      mp_list<pixel_internal_format, pixel_format, path_color_format_nv>,
#ifdef GL_RGBA
      enum_type_c<GL_RGBA>>
#else
      enum_type_i>
#endif
      rgba;

    opt_c_api_constant<
      mp_list<pixel_internal_format, image_unit_format>,
#ifdef GL_R8
      enum_type_c<GL_R8>>
#else
      enum_type_i>
#endif
      r8;

    opt_c_api_constant<
      mp_list<pixel_internal_format, image_unit_format>,
#ifdef GL_R8_SNORM
      enum_type_c<GL_R8_SNORM>>
#else
      enum_type_i>
#endif
      r8_snorm;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_R16
      enum_type_c<GL_R16>>
#else
      enum_type_i>
#endif
      r16;

    opt_c_api_constant<
      mp_list<pixel_internal_format, image_unit_format>,
#ifdef GL_R16_SNORM
      enum_type_c<GL_R16_SNORM>>
#else
      enum_type_i>
#endif
      r16_snorm;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_RG8
      enum_type_c<GL_RG8>>
#else
      enum_type_i>
#endif
      rg8;

    opt_c_api_constant<
      mp_list<image_unit_format>,
#ifdef GL_RG8UI
      enum_type_c<GL_RG8UI>>
#else
      enum_type_i>
#endif
      rg8ui;

    opt_c_api_constant<
      mp_list<pixel_internal_format, image_unit_format>,
#ifdef GL_RG8_SNORM
      enum_type_c<GL_RG8_SNORM>>
#else
      enum_type_i>
#endif
      rg8_snorm;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_RG16
      enum_type_c<GL_RG16>>
#else
      enum_type_i>
#endif
      rg16;

    opt_c_api_constant<
      mp_list<image_unit_format>,
#ifdef GL_RG16UI
      enum_type_c<GL_RG16UI>>
#else
      enum_type_i>
#endif
      rg16ui;

    opt_c_api_constant<
      mp_list<pixel_internal_format, image_unit_format>,
#ifdef GL_RG16_SNORM
      enum_type_c<GL_RG16_SNORM>>
#else
      enum_type_i>
#endif
      rg16_snorm;

    opt_c_api_constant<
      mp_list<image_unit_format>,
#ifdef GL_RG32UI
      enum_type_c<GL_RG32UI>>
#else
      enum_type_i>
#endif
      rg32ui;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_R3_G3_B2
      enum_type_c<GL_R3_G3_B2>>
#else
      enum_type_i>
#endif
      r3_g3_b2;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_RGB4
      enum_type_c<GL_RGB4>>
#else
      enum_type_i>
#endif
      rgb4;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_RGB5
      enum_type_c<GL_RGB5>>
#else
      enum_type_i>
#endif
      rgb5;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_RGB8
      enum_type_c<GL_RGB8>>
#else
      enum_type_i>
#endif
      rgb8;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_RGB8_SNORM
      enum_type_c<GL_RGB8_SNORM>>
#else
      enum_type_i>
#endif
      rgb8_snorm;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_RGB10
      enum_type_c<GL_RGB10>>
#else
      enum_type_i>
#endif
      rgb10;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_RGB12
      enum_type_c<GL_RGB12>>
#else
      enum_type_i>
#endif
      rgb12;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_RGB16
      enum_type_c<GL_RGB16>>
#else
      enum_type_i>
#endif
      rgb16;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_RGB16_SNORM
      enum_type_c<GL_RGB16_SNORM>>
#else
      enum_type_i>
#endif
      rgb16_snorm;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_RGBA2
      enum_type_c<GL_RGBA2>>
#else
      enum_type_i>
#endif
      rgba2;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_RGBA4
      enum_type_c<GL_RGBA4>>
#else
      enum_type_i>
#endif
      rgba4;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_RGB5_A1
      enum_type_c<GL_RGB5_A1>>
#else
      enum_type_i>
#endif
      rgb5_a1;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_RGBA8
      enum_type_c<GL_RGBA8>>
#else
      enum_type_i>
#endif
      rgba8;

    opt_c_api_constant<
      mp_list<image_unit_format>,
#ifdef GL_RGBA8
      enum_type_c<GL_RGBA8UI>>
#else
      enum_type_i>
#endif
      rgba8ui;

    opt_c_api_constant<
      mp_list<pixel_internal_format, image_unit_format>,
#ifdef GL_RGBA8_SNORM
      enum_type_c<GL_RGBA8_SNORM>>
#else
      enum_type_i>
#endif
      rgba8_snorm;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_RGB10_A2
      enum_type_c<GL_RGB10_A2>>
#else
      enum_type_i>
#endif
      rgb10_a2;

    opt_c_api_constant<
      mp_list<pixel_internal_format, image_unit_format>,
#ifdef GL_RGB10_A2UI
      enum_type_c<GL_RGB10_A2UI>>
#else
      enum_type_i>
#endif
      rgb10_a2ui;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_RGBA12
      enum_type_c<GL_RGBA12>>
#else
      enum_type_i>
#endif
      rgba12;

    opt_c_api_constant<
      mp_list<pixel_internal_format, image_unit_format>,
#ifdef GL_RGBA16
      enum_type_c<GL_RGBA16>>
#else
      enum_type_i>
#endif
      rgba16;

    opt_c_api_constant<
      mp_list<pixel_internal_format, image_unit_format>,
#ifdef GL_RGBA16UI
      enum_type_c<GL_RGBA16UI>>
#else
      enum_type_i>
#endif
      rgba16ui;

    opt_c_api_constant<
      mp_list<pixel_internal_format, image_unit_format>,
#ifdef GL_RGBA16_SNORM
      enum_type_c<GL_RGBA16_SNORM>>
#else
      enum_type_i>
#endif
      rgba16_snorm;

    opt_c_api_constant<
      mp_list<pixel_internal_format, image_unit_format>,
#ifdef GL_R16F
      enum_type_c<GL_R16F>>
#else
      enum_type_i>
#endif
      r16f;

    opt_c_api_constant<
      mp_list<pixel_internal_format, image_unit_format>,
#ifdef GL_RG16F
      enum_type_c<GL_RG16F>>
#else
      enum_type_i>
#endif
      rg16f;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_RGB16F
      enum_type_c<GL_RGB16F>>
#else
      enum_type_i>
#endif
      rgb16f;

    opt_c_api_constant<
      mp_list<pixel_internal_format, image_unit_format>,
#ifdef GL_RGBA16F
      enum_type_c<GL_RGBA16F>>
#else
      enum_type_i>
#endif
      rgba16f;

    opt_c_api_constant<
      mp_list<pixel_internal_format, image_unit_format>,
#ifdef GL_R32F
      enum_type_c<GL_R32F>>
#else
      enum_type_i>
#endif
      r32f;

    opt_c_api_constant<
      mp_list<pixel_internal_format, image_unit_format>,
#ifdef GL_RG32F
      enum_type_c<GL_RG32F>>
#else
      enum_type_i>
#endif
      rg32f;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_RGB32F
      enum_type_c<GL_RGB32F>>
#else
      enum_type_i>
#endif
      rgb32f;

    opt_c_api_constant<
      mp_list<pixel_internal_format, image_unit_format>,
#ifdef GL_RGBA32F
      enum_type_c<GL_RGBA32F>>
#else
      enum_type_i>
#endif
      rgba32f;

    opt_c_api_constant<
      mp_list<pixel_internal_format, image_unit_format>,
#ifdef GL_RGBA32UI
      enum_type_c<GL_RGBA32UI>>
#else
      enum_type_i>
#endif
      rgba32ui;

    opt_c_api_constant<
      mp_list<pixel_internal_format, image_unit_format>,
#ifdef GL_R11F_G11F_B10F
      enum_type_c<GL_R11F_G11F_B10F>>
#else
      enum_type_i>
#endif
      r11f_g11f_b10f;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_RGB9_E5
      enum_type_c<GL_RGB9_E5>>
#else
      enum_type_i>
#endif
      rgb9_e5;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_R8I
      enum_type_c<GL_R8I>>
#else
      enum_type_i>
#endif
      r8i;

    opt_c_api_constant<
      mp_list<pixel_internal_format, image_unit_format>,
#ifdef GL_R8UI
      enum_type_c<GL_R8UI>>
#else
      enum_type_i>
#endif
      r8ui;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_R16I
      enum_type_c<GL_R16I>>
#else
      enum_type_i>
#endif
      r16i;

    opt_c_api_constant<
      mp_list<pixel_internal_format, image_unit_format>,
#ifdef GL_R16UI
      enum_type_c<GL_R16UI>>
#else
      enum_type_i>
#endif
      r16ui;

    opt_c_api_constant<
      mp_list<pixel_internal_format, image_unit_format>,
#ifdef GL_R32I
      enum_type_c<GL_R32I>>
#else
      enum_type_i>
#endif
      r32i;

    opt_c_api_constant<
      mp_list<pixel_internal_format, image_unit_format>,
#ifdef GL_R16UI
      enum_type_c<GL_R32UI>>
#else
      enum_type_i>
#endif
      r32ui;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_SRGB
      enum_type_c<GL_SRGB>>
#else
      enum_type_i>
#endif
      srgb;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_SRGB8
      enum_type_c<GL_SRGB8>>
#else
      enum_type_i>
#endif
      srgb8;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_SRGB_ALPHA
      enum_type_c<GL_SRGB_ALPHA>>
#else
      enum_type_i>
#endif
      srgb_alpha;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_SRGB8_ALPHA8
      enum_type_c<GL_SRGB8_ALPHA8>>
#else
      enum_type_i>
#endif
      srgb8_alpha8;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_COMPRESSED_SRGB
      enum_type_c<GL_COMPRESSED_SRGB>>
#else
      enum_type_i>
#endif
      compressed_srgb;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_COMPRESSED_SRGB8_ETC2
      enum_type_c<GL_COMPRESSED_SRGB8_ETC2>>
#else
      enum_type_i>
#endif
      compressed_srgb8_etc2;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_COMPRESSED_SRGB_ALPHA
      enum_type_c<GL_COMPRESSED_SRGB_ALPHA>>
#else
      enum_type_i>
#endif
      compressed_srgb_alpha;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
      enum_type_c<GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC>>
#else
      enum_type_i>
#endif
      compressed_srgb8_alpha8_etc2_eac;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
      enum_type_c<GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2>>
#else
      enum_type_i>
#endif
      compressed_srgb8_punchthrough_alpha1_etc2;

    opt_c_api_constant<
      mp_list<pixel_internal_format>,
#ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
      enum_type_c<GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM>>
#else
      enum_type_i>
#endif
      compressed_srgb_alpha_bptc_unorm;

    opt_c_api_constant<
      mp_list<pixel_store_parameter>,
#ifdef GL_PACK_SWAP_BYTES
      enum_type_c<GL_PACK_SWAP_BYTES>,
#else
      enum_type_i,
#endif
      true_false>
      pack_swap_bytes;

    opt_c_api_constant<
      mp_list<pixel_store_parameter>,
#ifdef GL_PACK_LSB_FIRST
      enum_type_c<GL_PACK_LSB_FIRST>,
#else
      enum_type_i,
#endif
      true_false>
      pack_lsb_first;

    opt_c_api_constant<
      mp_list<pixel_store_parameter>,
#ifdef GL_PACK_ROW_LENGTH
      enum_type_c<GL_PACK_ROW_LENGTH>>
#else
      enum_type_i>
#endif
      pack_row_length;

    opt_c_api_constant<
      mp_list<pixel_store_parameter>,
#ifdef GL_PACK_SKIP_ROWS
      enum_type_c<GL_PACK_SKIP_ROWS>>
#else
      enum_type_i>
#endif
      pack_skip_rows;

    opt_c_api_constant<
      mp_list<pixel_store_parameter>,
#ifdef GL_PACK_SKIP_PIXELS
      enum_type_c<GL_PACK_SKIP_PIXELS>>
#else
      enum_type_i>
#endif
      pack_skip_pixels;

    opt_c_api_constant<
      mp_list<pixel_store_parameter>,
#ifdef GL_PACK_ALIGNMENT
      enum_type_c<GL_PACK_ALIGNMENT>>
#else
      enum_type_i>
#endif
      pack_alignment;

    opt_c_api_constant<
      mp_list<pixel_store_parameter>,
#ifdef GL_PACK_IMAGE_HEIGHT
      enum_type_c<GL_PACK_IMAGE_HEIGHT>>
#else
      enum_type_i>
#endif
      pack_image_height;

    opt_c_api_constant<
      mp_list<pixel_store_parameter>,
#ifdef GL_PACK_SKIP_IMAGES
      enum_type_c<GL_PACK_SKIP_IMAGES>>
#else
      enum_type_i>
#endif
      pack_skip_images;

    opt_c_api_constant<
      mp_list<pixel_store_parameter>,
#ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
      enum_type_c<GL_PACK_COMPRESSED_BLOCK_WIDTH>>
#else
      enum_type_i>
#endif
      pack_compressed_block_width;

    opt_c_api_constant<
      mp_list<pixel_store_parameter>,
#ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
      enum_type_c<GL_PACK_COMPRESSED_BLOCK_HEIGHT>>
#else
      enum_type_i>
#endif
      pack_compressed_block_height;

    opt_c_api_constant<
      mp_list<pixel_store_parameter>,
#ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
      enum_type_c<GL_PACK_COMPRESSED_BLOCK_DEPTH>>
#else
      enum_type_i>
#endif
      pack_compressed_block_depth;

    opt_c_api_constant<
      mp_list<pixel_store_parameter>,
#ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
      enum_type_c<GL_PACK_COMPRESSED_BLOCK_SIZE>>
#else
      enum_type_i>
#endif
      pack_compressed_block_size;

    opt_c_api_constant<
      mp_list<pixel_store_parameter>,
#ifdef GL_UNPACK_SWAP_BYTES
      enum_type_c<GL_UNPACK_SWAP_BYTES>,
#else
      enum_type_i,
#endif
      true_false>
      unpack_swap_bytes;

    opt_c_api_constant<
      mp_list<pixel_store_parameter>,
#ifdef GL_UNPACK_LSB_FIRST
      enum_type_c<GL_UNPACK_LSB_FIRST>,
#else
      enum_type_i,
#endif
      true_false>
      unpack_lsb_first;

    opt_c_api_constant<
      mp_list<pixel_store_parameter>,
#ifdef GL_UNPACK_ROW_LENGTH
      enum_type_c<GL_UNPACK_ROW_LENGTH>>
#else
      enum_type_i>
#endif
      unpack_row_length;

    opt_c_api_constant<
      mp_list<pixel_store_parameter>,
#ifdef GL_UNPACK_SKIP_ROWS
      enum_type_c<GL_UNPACK_SKIP_ROWS>>
#else
      enum_type_i>
#endif
      unpack_skip_rows;

    opt_c_api_constant<
      mp_list<pixel_store_parameter>,
#ifdef GL_UNPACK_SKIP_PIXELS
      enum_type_c<GL_UNPACK_SKIP_PIXELS>>
#else
      enum_type_i>
#endif
      unpack_skip_pixels;

    opt_c_api_constant<
      mp_list<pixel_store_parameter>,
#ifdef GL_UNPACK_ALIGNMENT
      enum_type_c<GL_UNPACK_ALIGNMENT>>
#else
      enum_type_i>
#endif
      unpack_alignment;

    opt_c_api_constant<
      mp_list<pixel_store_parameter>,
#ifdef GL_UNPACK_IMAGE_HEIGHT
      enum_type_c<GL_UNPACK_IMAGE_HEIGHT>>
#else
      enum_type_i>
#endif
      unpack_image_height;

    opt_c_api_constant<
      mp_list<pixel_store_parameter>,
#ifdef GL_UNPACK_SKIP_IMAGES
      enum_type_c<GL_UNPACK_SKIP_IMAGES>>
#else
      enum_type_i>
#endif
      unpack_skip_images;

    opt_c_api_constant<
      mp_list<pixel_store_parameter>,
#ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
      enum_type_c<GL_UNPACK_COMPRESSED_BLOCK_WIDTH>>
#else
      enum_type_i>
#endif
      unpack_compressed_block_width;

    opt_c_api_constant<
      mp_list<pixel_store_parameter>,
#ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
      enum_type_c<GL_UNPACK_COMPRESSED_BLOCK_HEIGHT>>
#else
      enum_type_i>
#endif
      unpack_compressed_block_height;

    opt_c_api_constant<
      mp_list<pixel_store_parameter>,
#ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
      enum_type_c<GL_UNPACK_COMPRESSED_BLOCK_DEPTH>>
#else
      enum_type_i>
#endif
      unpack_compressed_block_depth;

    opt_c_api_constant<
      mp_list<pixel_store_parameter>,
#ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
      enum_type_c<GL_UNPACK_COMPRESSED_BLOCK_SIZE>>
#else
      enum_type_i>
#endif
      unpack_compressed_block_size;

    opt_c_api_constant<
      mp_list<oglp::image_compatibility_class>,
#ifdef GL_IMAGE_CLASS_4_X_32
      enum_type_c<GL_IMAGE_CLASS_4_X_32>>
#else
      enum_type_i>
#endif
      image_class_4_x_32;

    opt_c_api_constant<
      mp_list<oglp::image_compatibility_class>,
#ifdef GL_IMAGE_CLASS_2_X_32
      enum_type_c<GL_IMAGE_CLASS_2_X_32>>
#else
      enum_type_i>
#endif
      image_class_2_x_32;

    opt_c_api_constant<
      mp_list<oglp::image_compatibility_class>,
#ifdef GL_IMAGE_CLASS_1_X_32
      enum_type_c<GL_IMAGE_CLASS_1_X_32>>
#else
      enum_type_i>
#endif
      image_class_1_x_32;

    opt_c_api_constant<
      mp_list<oglp::image_compatibility_class>,
#ifdef GL_IMAGE_CLASS_4_X_16
      enum_type_c<GL_IMAGE_CLASS_4_X_16>>
#else
      enum_type_i>
#endif
      image_class_4_x_16;

    opt_c_api_constant<
      mp_list<oglp::image_compatibility_class>,
#ifdef GL_IMAGE_CLASS_2_X_16
      enum_type_c<GL_IMAGE_CLASS_2_X_16>>
#else
      enum_type_i>
#endif
      image_class_2_x_16;

    opt_c_api_constant<
      mp_list<oglp::image_compatibility_class>,
#ifdef GL_IMAGE_CLASS_1_X_16
      enum_type_c<GL_IMAGE_CLASS_1_X_16>>
#else
      enum_type_i>
#endif
      image_class_1_x_16;

    opt_c_api_constant<
      mp_list<oglp::image_compatibility_class>,
#ifdef GL_IMAGE_CLASS_4_X_8
      enum_type_c<GL_IMAGE_CLASS_4_X_8>>
#else
      enum_type_i>
#endif
      image_class_4_x_8;

    opt_c_api_constant<
      mp_list<oglp::image_compatibility_class>,
#ifdef GL_IMAGE_CLASS_2_X_8
      enum_type_c<GL_IMAGE_CLASS_2_X_8>>
#else
      enum_type_i>
#endif
      image_class_2_x_8;

    opt_c_api_constant<
      mp_list<oglp::image_compatibility_class>,
#ifdef GL_IMAGE_CLASS_1_X_8
      enum_type_c<GL_IMAGE_CLASS_1_X_8>>
#else
      enum_type_i>
#endif
      image_class_1_x_8;

    opt_c_api_constant<
      mp_list<oglp::image_compatibility_class>,
#ifdef GL_IMAGE_CLASS_11_11_10
      enum_type_c<GL_IMAGE_CLASS_11_11_10>>
#else
      enum_type_i>
#endif
      image_class_11_11_10;

    opt_c_api_constant<
      mp_list<oglp::image_compatibility_class>,
#ifdef GL_IMAGE_CLASS_10_10_10_2
      enum_type_c<GL_IMAGE_CLASS_10_10_10_2>>
#else
      enum_type_i>
#endif
      image_class_10_10_10_2;

    opt_c_api_constant<
      mp_list<oglp::view_compatibility_class>,
#ifdef GL_VIEW_CLASS_128_BITS
      enum_type_c<GL_VIEW_CLASS_128_BITS>>
#else
      enum_type_i>
#endif
      view_class_128_bits;

    opt_c_api_constant<
      mp_list<oglp::view_compatibility_class>,
#ifdef GL_VIEW_CLASS_96_BITS
      enum_type_c<GL_VIEW_CLASS_96_BITS>>
#else
      enum_type_i>
#endif
      view_class_96_bits;

    opt_c_api_constant<
      mp_list<oglp::view_compatibility_class>,
#ifdef GL_VIEW_CLASS_64_BITS
      enum_type_c<GL_VIEW_CLASS_64_BITS>>
#else
      enum_type_i>
#endif
      view_class_64_bits;

    opt_c_api_constant<
      mp_list<oglp::view_compatibility_class>,
#ifdef GL_VIEW_CLASS_48_BITS
      enum_type_c<GL_VIEW_CLASS_48_BITS>>
#else
      enum_type_i>
#endif
      view_class_48_bits;

    opt_c_api_constant<
      mp_list<oglp::view_compatibility_class>,
#ifdef GL_VIEW_CLASS_32_BITS
      enum_type_c<GL_VIEW_CLASS_32_BITS>>
#else
      enum_type_i>
#endif
      view_class_32_bits;

    opt_c_api_constant<
      mp_list<oglp::view_compatibility_class>,
#ifdef GL_VIEW_CLASS_24_BITS
      enum_type_c<GL_VIEW_CLASS_24_BITS>>
#else
      enum_type_i>
#endif
      view_class_24_bits;

    opt_c_api_constant<
      mp_list<oglp::view_compatibility_class>,
#ifdef GL_VIEW_CLASS_16_BITS
      enum_type_c<GL_VIEW_CLASS_16_BITS>>
#else
      enum_type_i>
#endif
      view_class_16_bits;

    opt_c_api_constant<
      mp_list<oglp::view_compatibility_class>,
#ifdef GL_VIEW_CLASS_8_BITS
      enum_type_c<GL_VIEW_CLASS_8_BITS>>
#else
      enum_type_i>
#endif
      view_class_8_bits;

    opt_c_api_constant<
      mp_list<oglp::view_compatibility_class>,
#ifdef GL_VIEW_CLASS_S3TC_DXT1_RGB
      enum_type_c<GL_VIEW_CLASS_S3TC_DXT1_RGB>>
#else
      enum_type_i>
#endif
      view_class_s3tc_dxt1_rgb;

    opt_c_api_constant<
      mp_list<oglp::view_compatibility_class>,
#ifdef GL_VIEW_CLASS_S3TC_DXT1_RGBA
      enum_type_c<GL_VIEW_CLASS_S3TC_DXT1_RGBA>>
#else
      enum_type_i>
#endif
      view_class_s3tc_dxt1_rgba;

    opt_c_api_constant<
      mp_list<oglp::view_compatibility_class>,
#ifdef GL_VIEW_CLASS_S3TC_DXT3_RGBA
      enum_type_c<GL_VIEW_CLASS_S3TC_DXT3_RGBA>>
#else
      enum_type_i>
#endif
      view_class_s3tc_dxt3_rgba;

    opt_c_api_constant<
      mp_list<oglp::view_compatibility_class>,
#ifdef GL_VIEW_CLASS_S3TC_DXT5_RGBA
      enum_type_c<GL_VIEW_CLASS_S3TC_DXT5_RGBA>>
#else
      enum_type_i>
#endif
      view_class_s3tc_dxt5_rgba;

    opt_c_api_constant<
      mp_list<oglp::view_compatibility_class>,
#ifdef GL_VIEW_CLASS_RGTC1_RED
      enum_type_c<GL_VIEW_CLASS_RGTC1_RED>>
#else
      enum_type_i>
#endif
      view_class_rgtc1_red;

    opt_c_api_constant<
      mp_list<oglp::view_compatibility_class>,
#ifdef GL_VIEW_CLASS_RGTC2_RG
      enum_type_c<GL_VIEW_CLASS_RGTC2_RG>>
#else
      enum_type_i>
#endif
      view_class_rgtc2_rg;

    opt_c_api_constant<
      mp_list<oglp::view_compatibility_class>,
#ifdef GL_VIEW_CLASS_BPTC_UNORM
      enum_type_c<GL_VIEW_CLASS_BPTC_UNORM>>
#else
      enum_type_i>
#endif
      view_class_bptc_unorm;

    opt_c_api_constant<
      mp_list<oglp::view_compatibility_class>,
#ifdef GL_VIEW_CLASS_BPTC_FLOAT
      enum_type_c<GL_VIEW_CLASS_BPTC_FLOAT>>
#else
      enum_type_i>
#endif
      view_class_bptc_float;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_NUM_SAMPLE_COUNTS
      enum_type_c<GL_NUM_SAMPLE_COUNTS>>
#else
      enum_type_i>
#endif
      num_sample_counts;

    opt_c_api_constant<
      mp_list<internal_format_parameter, integer_query>,
#ifdef GL_SAMPLES
      enum_type_c<GL_SAMPLES>>
#else
      enum_type_i>
#endif
      samples;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_INTERNALFORMAT_SUPPORTED
      enum_type_c<GL_INTERNALFORMAT_SUPPORTED>>
#else
      enum_type_i>
#endif
      internalformat_supported;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_INTERNALFORMAT_PREFERRED
      enum_type_c<GL_INTERNALFORMAT_PREFERRED>>
#else
      enum_type_i>
#endif
      internalformat_preferred;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_INTERNALFORMAT_RED_SIZE
      enum_type_c<GL_INTERNALFORMAT_RED_SIZE>>
#else
      enum_type_i>
#endif
      internalformat_red_size;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
      enum_type_c<GL_INTERNALFORMAT_GREEN_SIZE>>
#else
      enum_type_i>
#endif
      internalformat_green_size;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_INTERNALFORMAT_BLUE_SIZE
      enum_type_c<GL_INTERNALFORMAT_BLUE_SIZE>>
#else
      enum_type_i>
#endif
      internalformat_blue_size;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
      enum_type_c<GL_INTERNALFORMAT_ALPHA_SIZE>>
#else
      enum_type_i>
#endif
      internalformat_alpha_size;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
      enum_type_c<GL_INTERNALFORMAT_DEPTH_SIZE>>
#else
      enum_type_i>
#endif
      internalformat_depth_size;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
      enum_type_c<GL_INTERNALFORMAT_STENCIL_SIZE>>
#else
      enum_type_i>
#endif
      internalformat_stencil_size;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
      enum_type_c<GL_INTERNALFORMAT_SHARED_SIZE>>
#else
      enum_type_i>
#endif
      internalformat_shared_size;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_INTERNALFORMAT_RED_TYPE
      enum_type_c<GL_INTERNALFORMAT_RED_TYPE>>
#else
      enum_type_i>
#endif
      internalformat_red_type;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
      enum_type_c<GL_INTERNALFORMAT_GREEN_TYPE>>
#else
      enum_type_i>
#endif
      internalformat_green_type;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_INTERNALFORMAT_BLUE_TYPE
      enum_type_c<GL_INTERNALFORMAT_BLUE_TYPE>>
#else
      enum_type_i>
#endif
      internalformat_blue_type;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
      enum_type_c<GL_INTERNALFORMAT_ALPHA_TYPE>>
#else
      enum_type_i>
#endif
      internalformat_alpha_type;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
      enum_type_c<GL_INTERNALFORMAT_DEPTH_TYPE>>
#else
      enum_type_i>
#endif
      internalformat_depth_type;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
      enum_type_c<GL_INTERNALFORMAT_STENCIL_TYPE>>
#else
      enum_type_i>
#endif
      internalformat_stencil_type;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_MAX_WIDTH
      enum_type_c<GL_MAX_WIDTH>>
#else
      enum_type_i>
#endif
      max_width;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_MAX_HEIGHT
      enum_type_c<GL_MAX_HEIGHT>>
#else
      enum_type_i>
#endif
      max_height;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_MAX_DEPTH
      enum_type_c<GL_MAX_DEPTH>>
#else
      enum_type_i>
#endif
      max_depth;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_MAX_LAYERS
      enum_type_c<GL_MAX_LAYERS>>
#else
      enum_type_i>
#endif
      max_layers;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_MAX_COMBINED_DIMENSIONS
      enum_type_c<GL_MAX_COMBINED_DIMENSIONS>>
#else
      enum_type_i>
#endif
      max_combined_dimensions;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_COLOR_COMPONENTS
      enum_type_c<GL_COLOR_COMPONENTS>>
#else
      enum_type_i>
#endif
      color_components;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_DEPTH_COMPONENTS
      enum_type_c<GL_DEPTH_COMPONENTS>>
#else
      enum_type_i>
#endif
      depth_components;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_STENCIL_COMPONENTS
      enum_type_c<GL_STENCIL_COMPONENTS>>
#else
      enum_type_i>
#endif
      stencil_components;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_COLOR_RENDERABLE
      enum_type_c<GL_COLOR_RENDERABLE>>
#else
      enum_type_i>
#endif
      color_renderable;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_DEPTH_RENDERABLE
      enum_type_c<GL_DEPTH_RENDERABLE>>
#else
      enum_type_i>
#endif
      depth_renderable;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_STENCIL_RENDERABLE
      enum_type_c<GL_STENCIL_RENDERABLE>>
#else
      enum_type_i>
#endif
      stencil_renderable;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_FRAMEBUFFER_RENDERABLE
      enum_type_c<GL_FRAMEBUFFER_RENDERABLE>>
#else
      enum_type_i>
#endif
      framebuffer_renderable;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_FRAMEBUFFER_RENDERABLE_LAYERED
      enum_type_c<GL_FRAMEBUFFER_RENDERABLE_LAYERED>>
#else
      enum_type_i>
#endif
      framebuffer_renderable_layered;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_FRAMEBUFFER_BLEND
      enum_type_c<GL_FRAMEBUFFER_BLEND>>
#else
      enum_type_i>
#endif
      framebuffer_blend;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_READ_PIXELS
      enum_type_c<GL_READ_PIXELS>>
#else
      enum_type_i>
#endif
      read_pixels;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_READ_PIXELS_FORMAT
      enum_type_c<GL_READ_PIXELS_FORMAT>>
#else
      enum_type_i>
#endif
      read_pixels_format;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_READ_PIXELS_TYPE
      enum_type_c<GL_READ_PIXELS_TYPE>>
#else
      enum_type_i>
#endif
      read_pixels_type;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_TEXTURE_IMAGE_FORMAT
      enum_type_c<GL_TEXTURE_IMAGE_FORMAT>>
#else
      enum_type_i>
#endif
      texture_image_format;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_TEXTURE_IMAGE_TYPE
      enum_type_c<GL_TEXTURE_IMAGE_TYPE>>
#else
      enum_type_i>
#endif
      texture_image_type;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_GET_TEXTURE_IMAGE_FORMAT
      enum_type_c<GL_GET_TEXTURE_IMAGE_FORMAT>>
#else
      enum_type_i>
#endif
      get_texture_image_format;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_GET_TEXTURE_IMAGE_TYPE
      enum_type_c<GL_GET_TEXTURE_IMAGE_TYPE>>
#else
      enum_type_i>
#endif
      get_texture_image_type;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_MIPMAP
      enum_type_c<GL_MIPMAP>>
#else
      enum_type_i>
#endif
      mipmap;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_GENERATE_MIPMAP
      enum_type_c<GL_GENERATE_MIPMAP>>
#else
      enum_type_i>
#endif
      generate_mipmap;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_AUTO_GENERATE_MIPMAP
      enum_type_c<GL_AUTO_GENERATE_MIPMAP>>
#else
      enum_type_i>
#endif
      auto_generate_mipmap;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_COLOR_ENCODING
      enum_type_c<GL_COLOR_ENCODING>>
#else
      enum_type_i>
#endif
      color_encoding;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_SRGB_READ
      enum_type_c<GL_SRGB_READ>>
#else
      enum_type_i>
#endif
      srgb_read;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_SRGB_WRITE
      enum_type_c<GL_SRGB_WRITE>>
#else
      enum_type_i>
#endif
      srgb_write;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_FILTER
      enum_type_c<GL_FILTER>>
#else
      enum_type_i>
#endif
      filter;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_VERTEX_TEXTURE
      enum_type_c<GL_VERTEX_TEXTURE>>
#else
      enum_type_i>
#endif
      vertex_texture;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_TESS_CONTROL_TEXTURE
      enum_type_c<GL_TESS_CONTROL_TEXTURE>>
#else
      enum_type_i>
#endif
      tess_control_texture;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_TESS_EVALUATION_TEXTURE
      enum_type_c<GL_TESS_EVALUATION_TEXTURE>>
#else
      enum_type_i>
#endif
      tess_evaluation_texture;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_GEOMETRY_TEXTURE
      enum_type_c<GL_GEOMETRY_TEXTURE>>
#else
      enum_type_i>
#endif
      geometry_texture;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_FRAGMENT_TEXTURE
      enum_type_c<GL_FRAGMENT_TEXTURE>>
#else
      enum_type_i>
#endif
      fragment_texture;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_COMPUTE_TEXTURE
      enum_type_c<GL_COMPUTE_TEXTURE>>
#else
      enum_type_i>
#endif
      compute_texture;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_TEXTURE_SHADOW
      enum_type_c<GL_TEXTURE_SHADOW>>
#else
      enum_type_i>
#endif
      texture_shadow;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_TEXTURE_GATHER
      enum_type_c<GL_TEXTURE_GATHER>>
#else
      enum_type_i>
#endif
      texture_gather;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_TEXTURE_GATHER_SHADOW
      enum_type_c<GL_TEXTURE_GATHER_SHADOW>>
#else
      enum_type_i>
#endif
      texture_gather_shadow;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_SHADER_IMAGE_LOAD
      enum_type_c<GL_SHADER_IMAGE_LOAD>>
#else
      enum_type_i>
#endif
      shader_image_load;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_SHADER_IMAGE_STORE
      enum_type_c<GL_SHADER_IMAGE_STORE>>
#else
      enum_type_i>
#endif
      shader_image_store;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_SHADER_IMAGE_ATOMIC
      enum_type_c<GL_SHADER_IMAGE_ATOMIC>>
#else
      enum_type_i>
#endif
      shader_image_atomic;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_IMAGE_TEXEL_SIZE
      enum_type_c<GL_IMAGE_TEXEL_SIZE>>
#else
      enum_type_i>
#endif
      image_texel_size;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_IMAGE_COMPATIBILITY_CLASS
      enum_type_c<GL_IMAGE_COMPATIBILITY_CLASS>>
#else
      enum_type_i>
#endif
      image_compatibility_class;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_IMAGE_PIXEL_FORMAT
      enum_type_c<GL_IMAGE_PIXEL_FORMAT>>
#else
      enum_type_i>
#endif
      image_pixel_format;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_IMAGE_PIXEL_TYPE
      enum_type_c<GL_IMAGE_PIXEL_TYPE>>
#else
      enum_type_i>
#endif
      image_pixel_type;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
      enum_type_c<GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST>>
#else
      enum_type_i>
#endif
      simultaneous_texture_and_depth_test;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
      enum_type_c<GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST>>
#else
      enum_type_i>
#endif
      simultaneous_texture_and_stencil_test;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
      enum_type_c<GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE>>
#else
      enum_type_i>
#endif
      simultaneous_texture_and_depth_write;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
      enum_type_c<GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE>>
#else
      enum_type_i>
#endif
      simultaneous_texture_and_stencil_write;

    opt_c_api_constant<
      mp_list<internal_format_parameter, texture_level_parameter>,
#ifdef GL_TEXTURE_COMPRESSED
      enum_type_c<GL_TEXTURE_COMPRESSED>,
#else
      enum_type_i,
#endif
      true_false>
      texture_compressed;

    opt_c_api_constant<
      mp_list<texture_level_parameter>,
#ifdef GL_TEXTURE_COMPRESSED_IMAGE_SIZE
      enum_type_c<GL_TEXTURE_COMPRESSED_IMAGE_SIZE>>
#else
      enum_type_i>
#endif
      texture_compressed_image_size;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
      enum_type_c<GL_TEXTURE_COMPRESSED_BLOCK_WIDTH>>
#else
      enum_type_i>
#endif
      texture_compressed_block_width;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
      enum_type_c<GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT>>
#else
      enum_type_i>
#endif
      texture_compressed_block_height;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
      enum_type_c<GL_TEXTURE_COMPRESSED_BLOCK_SIZE>>
#else
      enum_type_i>
#endif
      texture_compressed_block_size;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_CLEAR_BUFFER
      enum_type_c<GL_CLEAR_BUFFER>>
#else
      enum_type_i>
#endif
      clear_buffer;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_CLEAR_TEXTURE
      enum_type_c<GL_CLEAR_TEXTURE>>
#else
      enum_type_i>
#endif
      clear_texture;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_TEXTURE_VIEW
      enum_type_c<GL_TEXTURE_VIEW>>
#else
      enum_type_i>
#endif
      texture_view;

    opt_c_api_constant<
      mp_list<internal_format_parameter>,
#ifdef GL_VIEW_COMPATIBILITY_CLASS
      enum_type_c<GL_VIEW_COMPATIBILITY_CLASS>>
#else
      enum_type_i>
#endif
      view_compatibility_class;

    opt_c_api_constant<
      mp_list<sample_parameter>,
#ifdef GL_SAMPLE_POSITION
      enum_type_c<GL_SAMPLE_POSITION>>
#else
      enum_type_i>
#endif
      sample_position;

    opt_c_api_constant<
      mp_list<matrix_mode>,
#ifdef GL_PROJECTION
      enum_type_c<GL_PROJECTION>>
#else
      enum_type_i>
#endif
      projection;

    opt_c_api_constant<
      mp_list<matrix_mode>,
#ifdef GL_MODELVIEW
      enum_type_c<GL_MODELVIEW>>
#else
      enum_type_i>
#endif
      modelview;

    opt_c_api_constant<
      mp_list<debug_output_severity>,
#ifdef GL_DEBUG_SEVERITY_HIGH
      enum_type_c<GL_DEBUG_SEVERITY_HIGH>>
#elif defined(GL_DEBUG_SEVERITY_HIGH_KHR)
      enum_type_c<GL_DEBUG_SEVERITY_HIGH_KHR>>
#else
      enum_type_i>
#endif
      debug_severity_high;

    opt_c_api_constant<
      mp_list<debug_output_severity>,
#ifdef GL_DEBUG_SEVERITY_MEDIUM
      enum_type_c<GL_DEBUG_SEVERITY_MEDIUM>>
#elif defined(GL_DEBUG_SEVERITY_MEDIUM_KHR)
      enum_type_c<GL_DEBUG_SEVERITY_MEDIUM_KHR>>
#else
      enum_type_i>
#endif
      debug_severity_medium;

    opt_c_api_constant<
      mp_list<debug_output_severity>,
#ifdef GL_DEBUG_SEVERITY_LOW
      enum_type_c<GL_DEBUG_SEVERITY_LOW>>
#elif defined(GL_DEBUG_SEVERITY_LOW_KHR)
      enum_type_c<GL_DEBUG_SEVERITY_LOW_KHR>>
#else
      enum_type_i>
#endif
      debug_severity_low;

    opt_c_api_constant<
      mp_list<debug_output_severity>,
#ifdef GL_DEBUG_SEVERITY_NOTIFICATION
      enum_type_c<GL_DEBUG_SEVERITY_NOTIFICATION>>
#elif defined(GL_DEBUG_SEVERITY_NOTIFICATION_KHR)
      enum_type_c<GL_DEBUG_SEVERITY_NOTIFICATION_KHR>>
#else
      enum_type_i>
#endif
      debug_severity_notification;

    opt_c_api_constant<
      mp_list<debug_output_source>,
#ifdef GL_DEBUG_SOURCE_API
      enum_type_c<GL_DEBUG_SOURCE_API>>
#elif defined(GL_DEBUG_SOURCE_API_KHR)
      enum_type_c<GL_DEBUG_SOURCE_API_KHR>>
#else
      enum_type_i>
#endif
      debug_source_api;

    opt_c_api_constant<
      mp_list<debug_output_source>,
#ifdef GL_DEBUG_SOURCE_WINDOW_SYSTEM
      enum_type_c<GL_DEBUG_SOURCE_WINDOW_SYSTEM>>
#elif defined(GL_DEBUG_SOURCE_WINDOW_SYSTEM_KHR)
      enum_type_c<GL_DEBUG_SOURCE_WINDOW_SYSTEM_KHR>>
#else
      enum_type_i>
#endif
      debug_source_window_system;

    opt_c_api_constant<
      mp_list<debug_output_source>,
#ifdef GL_DEBUG_SOURCE_SHADER_COMPILER
      enum_type_c<GL_DEBUG_SOURCE_SHADER_COMPILER>>
#elif defined(GL_DEBUG_SOURCE_SHADER_COMPILER_KHR)
      enum_type_c<GL_DEBUG_SOURCE_SHADER_COMPILER_KHR>>
#else
      enum_type_i>
#endif
      debug_source_shader_compiler;

    opt_c_api_constant<
      mp_list<debug_output_source>,
#ifdef GL_DEBUG_SOURCE_THIRD_PARTY
      enum_type_c<GL_DEBUG_SOURCE_THIRD_PARTY>>
#elif defined(GL_DEBUG_SOURCE_THIRD_PARTY_KHR)
      enum_type_c<GL_DEBUG_SOURCE_THIRD_PARTY_KHR>>
#else
      enum_type_i>
#endif
      debug_source_third_party;

    opt_c_api_constant<
      mp_list<debug_output_source>,
#ifdef GL_DEBUG_SOURCE_APPLICATION
      enum_type_c<GL_DEBUG_SOURCE_APPLICATION>>
#elif defined(GL_DEBUG_SOURCE_APPLICATION_KHR)
      enum_type_c<GL_DEBUG_SOURCE_APPLICATION_KHR>>
#else
      enum_type_i>
#endif
      debug_source_application;

    opt_c_api_constant<
      mp_list<debug_output_source>,
#ifdef GL_DEBUG_SOURCE_OTHER
      enum_type_c<GL_DEBUG_SOURCE_OTHER>>
#elif defined(GL_DEBUG_SOURCE_OTHER_KHR)
      enum_type_c<GL_DEBUG_SOURCE_OTHER_KHR>>
#else
      enum_type_i>
#endif
      debug_source_other;

    opt_c_api_constant<
      mp_list<debug_output_type>,
#ifdef GL_DEBUG_TYPE_ERROR
      enum_type_c<GL_DEBUG_TYPE_ERROR>>
#elif defined(GL_DEBUG_TYPE_ERROR_KHR)
      enum_type_c<GL_DEBUG_TYPE_ERROR_KHR>>
#else
      enum_type_i>
#endif
      debug_type_error;

    opt_c_api_constant<
      mp_list<debug_output_type>,
#ifdef GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR
      enum_type_c<GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR>>
#elif defined(GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_KHR)
      enum_type_c<GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_KHR>>
#else
      enum_type_i>
#endif
      debug_type_deprecated_behavior;

    opt_c_api_constant<
      mp_list<debug_output_type>,
#ifdef GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR
      enum_type_c<GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR>>
#elif defined(GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_KHR)
      enum_type_c<GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_KHR>>
#else
      enum_type_i>
#endif
      debug_type_undefined_behavior;

    opt_c_api_constant<
      mp_list<debug_output_type>,
#ifdef GL_DEBUG_TYPE_PORTABILITY
      enum_type_c<GL_DEBUG_TYPE_PORTABILITY>>
#elif defined(GL_DEBUG_TYPE_PORTABILITY_KHR)
      enum_type_c<GL_DEBUG_TYPE_PORTABILITY_KHR>>
#else
      enum_type_i>
#endif
      debug_type_portability;

    opt_c_api_constant<
      mp_list<debug_output_type>,
#ifdef GL_DEBUG_TYPE_PERFORMANCE
      enum_type_c<GL_DEBUG_TYPE_PERFORMANCE>>
#elif defined(GL_DEBUG_TYPE_PERFORMANCE_KHR)
      enum_type_c<GL_DEBUG_TYPE_PERFORMANCE_KHR>>
#else
      enum_type_i>
#endif
      debug_type_performance;

    opt_c_api_constant<
      mp_list<debug_output_type>,
#ifdef GL_DEBUG_TYPE_MARKER
      enum_type_c<GL_DEBUG_TYPE_MARKER>>
#elif defined(GL_DEBUG_TYPE_MARKER_KHR)
      enum_type_c<GL_DEBUG_TYPE_MARKER_KHR>>
#else
      enum_type_i>
#endif
      debug_type_marker;

    opt_c_api_constant<
      mp_list<debug_output_type>,
#ifdef GL_DEBUG_TYPE_PUSH_GROUP
      enum_type_c<GL_DEBUG_TYPE_PUSH_GROUP>>
#elif defined(GL_DEBUG_TYPE_PUSH_GROUP_KHR)
      enum_type_c<GL_DEBUG_TYPE_PUSH_GROUP_KHR>>
#else
      enum_type_i>
#endif
      debug_type_push_group;

    opt_c_api_constant<
      mp_list<debug_output_type>,
#ifdef GL_DEBUG_TYPE_POP_GROUP
      enum_type_c<GL_DEBUG_TYPE_POP_GROUP>>
#elif defined(GL_DEBUG_TYPE_POP_GROUP_KHR)
      enum_type_c<GL_DEBUG_TYPE_POP_GROUP_KHR>>
#else
      enum_type_i>
#endif
      debug_type_pop_group;

    opt_c_api_constant<
      mp_list<debug_output_type>,
#ifdef GL_DEBUG_TYPE_OTHER
      enum_type_c<GL_DEBUG_TYPE_OTHER>>
#elif defined(GL_DEBUG_TYPE_OTHER_KHR)
      enum_type_c<GL_DEBUG_TYPE_OTHER_KHR>>
#else
      enum_type_i>
#endif
      debug_type_other;

    // hint target
    opt_c_api_constant<
      mp_list<hint_target>,
#ifdef GL_LINE_SMOOTH_HINT
      enum_type_c<GL_LINE_SMOOTH_HINT>,
#else
      enum_type_i,
#endif
      hint_option>
      line_smooth_hint;

    opt_c_api_constant<
      mp_list<hint_target>,
#ifdef GL_POLYGON_SMOOTH_HINT
      enum_type_c<GL_POLYGON_SMOOTH_HINT>,
#else
      enum_type_i,
#endif
      hint_option>
      polygon_smooth_hint;

    opt_c_api_constant<
      mp_list<hint_target>,
#ifdef GL_TEXTURE_COMPRESSION_HINT
      enum_type_c<GL_TEXTURE_COMPRESSION_HINT>,
#else
      enum_type_i,
#endif
      hint_option>
      texture_compression_hint;

    opt_c_api_constant<
      mp_list<hint_target>,
#ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
      enum_type_c<GL_FRAGMENT_SHADER_DERIVATIVE_HINT>,
#else
      enum_type_i,
#endif
      hint_option>
      fragment_shader_derivative_hint;

    // hint option
    opt_c_api_constant<
      mp_list<hint_option>,
#ifdef GL_FASTEST
      enum_type_c<GL_FASTEST>>
#else
      enum_type_i>
#endif
      fastest;

    opt_c_api_constant<
      mp_list<hint_option>,
#ifdef GL_NICEST
      enum_type_c<GL_NICEST>>
#else
      enum_type_i>
#endif
      nicest;

    opt_c_api_constant<
      mp_list<
        debug_output_severity,
        debug_output_source,
        debug_output_type,
        hint_option>,
#ifdef GL_DONT_CARE
      enum_type_c<GL_DONT_CARE>>
#else
      enum_type_i>
#endif
      dont_care;

    opt_c_api_constant<
      mp_list<support_level>,
#ifdef GL_FULL_SUPPORT
      enum_type_c<GL_FULL_SUPPORT>>
#else
      enum_type_i>
#endif
      full_support;

    opt_c_api_constant<
      mp_list<support_level>,
#ifdef GL_CAVEAT_SUPPORT
      enum_type_c<GL_CAVEAT_SUPPORT>>
#else
      enum_type_i>
#endif
      caveat_support;

    // path command
    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_CLOSE_PATH_NV
      ubyte_type_c<GL_CLOSE_PATH_NV>>
#else
      ubyte_type_i>
#endif
      close_path_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_MOVE_TO_NV
      ubyte_type_c<GL_MOVE_TO_NV>>
#else
      ubyte_type_i>
#endif
      move_to_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_RELATIVE_MOVE_TO_NV
      ubyte_type_c<GL_RELATIVE_MOVE_TO_NV>>
#else
      ubyte_type_i>
#endif
      relative_move_to_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_LINE_TO_NV
      ubyte_type_c<GL_LINE_TO_NV>>
#else
      ubyte_type_i>
#endif
      line_to_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_RELATIVE_LINE_TO_NV
      ubyte_type_c<GL_RELATIVE_LINE_TO_NV>>
#else
      ubyte_type_i>
#endif
      relative_line_to_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_HORIZONTAL_LINE_TO_NV
      ubyte_type_c<GL_HORIZONTAL_LINE_TO_NV>>
#else
      ubyte_type_i>
#endif
      horizontal_line_to_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_RELATIVE_HORIZONTAL_LINE_TO_NV
      ubyte_type_c<GL_RELATIVE_HORIZONTAL_LINE_TO_NV>>
#else
      ubyte_type_i>
#endif
      relative_horizontal_line_to_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_VERTICAL_LINE_TO_NV
      ubyte_type_c<GL_VERTICAL_LINE_TO_NV>>
#else
      ubyte_type_i>
#endif
      vertical_line_to_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
      ubyte_type_c<GL_RELATIVE_VERTICAL_LINE_TO_NV>>
#else
      ubyte_type_i>
#endif
      relative_vertical_line_to_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_QUADRATIC_CURVE_TO_NV
      ubyte_type_c<GL_QUADRATIC_CURVE_TO_NV>>
#else
      ubyte_type_i>
#endif
      quadratic_curve_to_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
      ubyte_type_c<GL_RELATIVE_QUADRATIC_CURVE_TO_NV>>
#else
      ubyte_type_i>
#endif
      relative_quadratic_curve_to_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_CUBIC_CURVE_TO_NV
      ubyte_type_c<GL_CUBIC_CURVE_TO_NV>>
#else
      ubyte_type_i>
#endif
      cubic_curve_to_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_RELATIVE_CUBIC_CURVE_TO_NV
      ubyte_type_c<GL_RELATIVE_CUBIC_CURVE_TO_NV>>
#else
      ubyte_type_i>
#endif
      relative_cubic_curve_to_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
      ubyte_type_c<GL_SMOOTH_QUADRATIC_CURVE_TO_NV>>
#else
      ubyte_type_i>
#endif
      smooth_quadratic_curve_to_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
      ubyte_type_c<GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV>>
#else
      ubyte_type_i>
#endif
      relative_smooth_quadratic_curve_to_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
      ubyte_type_c<GL_SMOOTH_CUBIC_CURVE_TO_NV>>
#else
      ubyte_type_i>
#endif
      smooth_cubic_curve_to_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
      ubyte_type_c<GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV>>
#else
      ubyte_type_i>
#endif
      relative_smooth_cubic_curve_to_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_SMALL_CCW_ARC_TO_NV
      ubyte_type_c<GL_SMALL_CCW_ARC_TO_NV>>
#else
      ubyte_type_i>
#endif
      small_ccw_arc_to_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
      ubyte_type_c<GL_RELATIVE_SMALL_CCW_ARC_TO_NV>>
#else
      ubyte_type_i>
#endif
      relative_small_ccw_arc_to_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_SMALL_CW_ARC_TO_NV
      ubyte_type_c<GL_SMALL_CW_ARC_TO_NV>>
#else
      ubyte_type_i>
#endif
      small_cw_arc_to_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
      ubyte_type_c<GL_RELATIVE_SMALL_CW_ARC_TO_NV>>
#else
      ubyte_type_i>
#endif
      relative_small_cw_arc_to_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_LARGE_CCW_ARC_TO_NV
      ubyte_type_c<GL_LARGE_CCW_ARC_TO_NV>>
#else
      ubyte_type_i>
#endif
      large_ccw_arc_to_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_RELATIVE_LARGE_CCW_ARC_TO_NV
      ubyte_type_c<GL_RELATIVE_LARGE_CCW_ARC_TO_NV>>
#else
      ubyte_type_i>
#endif
      relative_large_ccw_arc_to_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_LARGE_CW_ARC_TO_NV
      ubyte_type_c<GL_LARGE_CW_ARC_TO_NV>>
#else
      ubyte_type_i>
#endif
      large_cw_arc_to_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_RELATIVE_LARGE_CW_ARC_TO_NV
      ubyte_type_c<GL_RELATIVE_LARGE_CW_ARC_TO_NV>>
#else
      ubyte_type_i>
#endif
      relative_large_cw_arc_to_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_RESTART_PATH_NV
      ubyte_type_c<GL_RESTART_PATH_NV>>
#else
      ubyte_type_i>
#endif
      restart_path_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_DUP_FIRST_CUBIC_CURVE_TO_NV
      ubyte_type_c<GL_DUP_FIRST_CUBIC_CURVE_TO_NV>>
#else
      ubyte_type_i>
#endif
      dup_first_cubic_curve_to_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_DUP_LAST_CUBIC_CURVE_TO_NV
      ubyte_type_c<GL_DUP_LAST_CUBIC_CURVE_TO_NV>>
#else
      ubyte_type_i>
#endif
      dup_last_cubic_curve_to_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_RECT_NV
      ubyte_type_c<GL_RECT_NV>>
#else
      ubyte_type_i>
#endif
      rect_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_CIRCULAR_CCW_ARC_TO_NV
      ubyte_type_c<GL_CIRCULAR_CCW_ARC_TO_NV>>
#else
      ubyte_type_i>
#endif
      circular_ccw_arc_to_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_CIRCULAR_CW_ARC_TO_NV
      ubyte_type_c<GL_CIRCULAR_CW_ARC_TO_NV>>
#else
      ubyte_type_i>
#endif
      circular_cw_arc_to_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_CIRCULAR_TANGENT_ARC_TO_NV
      ubyte_type_c<GL_CIRCULAR_TANGENT_ARC_TO_NV>>
#else
      ubyte_type_i>
#endif
      circular_tangent_arc_to_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_ARC_TO_NV
      ubyte_type_c<GL_ARC_TO_NV>>
#else
      ubyte_type_i>
#endif
      arc_to_nv;

    opt_c_api_constant<
      mp_list<path_command_nv>,
#ifdef GL_RELATIVE_ARC_TO_NV
      ubyte_type_c<GL_RELATIVE_ARC_TO_NV>>
#else
      ubyte_type_i>
#endif
      relative_arc_to_nv;

    opt_c_api_constant<
      mp_list<path_cap_style_nv>,
#ifdef GL_FLAT
      enum_type_c<GL_FLAT>>
#else
      enum_type_i>
#endif
      flat;

    opt_c_api_constant<
      mp_list<path_cap_style_nv>,
#ifdef GL_SQUARE_NV
      enum_type_c<GL_SQUARE_NV>>
#else
      enum_type_i>
#endif
      square_nv;

    opt_c_api_constant<
      mp_list<path_cap_style_nv, oglp::path_join_style_nv>,
#ifdef GL_ROUND_NV
      enum_type_c<GL_ROUND_NV>>
#else
      enum_type_i>
#endif
      round_nv;

    opt_c_api_constant<
      mp_list<path_cap_style_nv>,
#ifdef GL_TRIANGULAR_NV
      enum_type_c<GL_TRIANGULAR_NV>>
#else
      enum_type_i>
#endif
      triangular_nv;

    opt_c_api_constant<
      mp_list<path_color_format_nv>,
#ifdef GL_LUMINANCE
      enum_type_c<GL_LUMINANCE>>
#else
      enum_type_i>
#endif
      luminance;

    opt_c_api_constant<
      mp_list<path_color_format_nv>,
#ifdef GL_INTENSITY
      enum_type_c<GL_INTENSITY>>
#else
      enum_type_i>
#endif
      intensity;

    opt_c_api_constant<
      mp_list<path_color_format_nv>,
#ifdef GL_LUMINANCE_ALPHA
      enum_type_c<GL_LUMINANCE_ALPHA>>
#else
      enum_type_i>
#endif
      luminance_alpha;

    opt_c_api_constant<
      mp_list<path_color_nv>,
#ifdef GL_PRIMARY_COLOR_NV
      enum_type_c<GL_PRIMARY_COLOR_NV>>
#else
      enum_type_i>
#endif
      primary_color_nv;

    opt_c_api_constant<
      mp_list<path_color_nv>,
#ifdef GL_SECONDARY_COLOR_NV
      enum_type_c<GL_SECONDARY_COLOR_NV>>
#else
      enum_type_i>
#endif
      secondary_color_nv;

    opt_c_api_constant<
      mp_list<oglp::path_dash_offset_reset_nv>,
#ifdef GL_MOVE_TO_RESET_NV
      enum_type_c<GL_MOVE_TO_RESET_NV>>
#else
      enum_type_i>
#endif
      move_to_reset_nv;

    opt_c_api_constant<
      mp_list<oglp::path_dash_offset_reset_nv>,
#ifdef GL_MOVE_TO_CONTINUES_NV
      enum_type_c<GL_MOVE_TO_CONTINUES_NV>>
#else
      enum_type_i>
#endif
      move_to_continues_nv;

    opt_c_api_constant<
      mp_list<oglp::path_stroke_cover_mode_nv, oglp::path_fill_cover_mode_nv>,
#ifdef GL_CONVEX_HULL_NV
      enum_type_c<GL_CONVEX_HULL_NV>>
#else
      enum_type_i>
#endif
      convex_hull_nv;

    opt_c_api_constant<
      mp_list<oglp::path_stroke_cover_mode_nv, oglp::path_fill_cover_mode_nv>,
#ifdef GL_BOUNDING_BOX_NV
      enum_type_c<GL_BOUNDING_BOX_NV>>
#else
      enum_type_i>
#endif
      bounding_box_nv;

    opt_c_api_constant<
      mp_list<oglp::path_stroke_cover_mode_nv, oglp::path_fill_cover_mode_nv>,
#ifdef GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV
      enum_type_c<GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV>>
#else
      enum_type_i>
#endif
      bounding_box_of_bounding_boxes_nv;

    opt_c_api_constant<
      mp_list<oglp::path_fill_mode_nv>,
#ifdef GL_COUNT_UP_NV
      enum_type_c<GL_COUNT_UP_NV>>
#else
      enum_type_i>
#endif
      count_up_nv;

    opt_c_api_constant<
      mp_list<oglp::path_fill_mode_nv>,
#ifdef GL_COUNT_DOWN_NV
      enum_type_c<GL_COUNT_DOWN_NV>>
#else
      enum_type_i>
#endif
      count_down_nv;

    opt_c_api_constant<
      mp_list<oglp::path_join_style_nv>,
#ifdef GL_BEVEL_NV
      enum_type_c<GL_BEVEL_NV>>
#else
      enum_type_i>
#endif
      bevel_nv;

    opt_c_api_constant<
      mp_list<oglp::path_join_style_nv>,
#ifdef GL_MITER_REVERT_NV
      enum_type_c<GL_MITER_REVERT_NV>>
#else
      enum_type_i>
#endif
      miter_revert_nv;

    opt_c_api_constant<
      mp_list<oglp::path_join_style_nv>,
#ifdef GL_MITER_TRUNCATE_NV
      enum_type_c<GL_MITER_TRUNCATE_NV>>
#else
      enum_type_i>
#endif
      miter_truncate_nv;

    opt_c_api_constant<
      mp_list<path_font_style_nv>,
#ifdef GL_BOLD_BIT_NV
      bitfield_type_c<GL_BOLD_BIT_NV>>
#else
      bitfield_type_i>
#endif
      bold_bit_nv;

    opt_c_api_constant<
      mp_list<path_font_style_nv>,
#ifdef GL_ITALIC_BIT_NV
      bitfield_type_c<GL_ITALIC_BIT_NV>>
#else
      bitfield_type_i>
#endif
      italic_bit_nv;

    opt_c_api_constant<
      mp_list<path_font_target_nv>,
#ifdef GL_STANDARD_FONT_NAME_NV
      enum_type_c<GL_STANDARD_FONT_NAME_NV>>
#else
      enum_type_i>
#endif
      standard_font_name_nv;

    opt_c_api_constant<
      mp_list<path_font_target_nv>,
#ifdef GL_SYSTEM_FONT_NAME_NV
      enum_type_c<GL_SYSTEM_FONT_NAME_NV>>
#else
      enum_type_i>
#endif
      system_font_name_nv;

    opt_c_api_constant<
      mp_list<path_font_target_nv>,
#ifdef GL_FILE_NAME_NV
      enum_type_c<GL_FILE_NAME_NV>>
#else
      enum_type_i>
#endif
      file_name_nv;

    opt_c_api_constant<
      mp_list<path_format_nv>,
#ifdef GL_PATH_FORMAT_SVG_NV
      enum_type_c<GL_PATH_FORMAT_SVG_NV>>
#else
      enum_type_i>
#endif
      path_format_svg_nv;

    opt_c_api_constant<
      mp_list<path_format_nv>,
#ifdef GL_PATH_FORMAT_PS_NV
      enum_type_c<GL_PATH_FORMAT_PS_NV>>
#else
      enum_type_i>
#endif
      path_format_ps_nv;

    opt_c_api_constant<
      mp_list<oglp::path_gen_mode_nv>,
#ifdef GL_EYE_LINEAR
      enum_type_c<GL_EYE_LINEAR>>
#else
      enum_type_i>
#endif
      eye_linear;

    opt_c_api_constant<
      mp_list<oglp::path_gen_mode_nv>,
#ifdef GL_OBJECT_LINEAR
      enum_type_c<GL_OBJECT_LINEAR>>
#else
      enum_type_i>
#endif
      object_linear;

    opt_c_api_constant<
      mp_list<oglp::path_gen_mode_nv, path_parameter_nv>,
#ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
      enum_type_c<GL_PATH_OBJECT_BOUNDING_BOX_NV>>
#else
      enum_type_i>
#endif
      path_object_bounding_box_nv;

    opt_c_api_constant<
      mp_list<path_list_mode_nv>,
#ifdef GL_ACCUM_ADJACENT_PAIRS_NV
      enum_type_c<GL_ACCUM_ADJACENT_PAIRS_NV>>
#else
      enum_type_i>
#endif
      accum_adjacent_pairs_nv;

    opt_c_api_constant<
      mp_list<path_list_mode_nv>,
#ifdef GL_ADJACENT_PAIRS_NV
      enum_type_c<GL_ADJACENT_PAIRS_NV>>
#else
      enum_type_i>
#endif
      adjacent_pairs_nv;

    opt_c_api_constant<
      mp_list<path_list_mode_nv>,
#ifdef GL_FIRST_TO_REST_NV
      enum_type_c<GL_FIRST_TO_REST_NV>>
#else
      enum_type_i>
#endif
      first_to_rest_nv;

    opt_c_api_constant<
      mp_list<path_metric_query_nv>,
#ifdef GL_GLYPH_WIDTH_BIT_NV
      bitfield_type_c<GL_GLYPH_WIDTH_BIT_NV>>
#else
      bitfield_type_i>
#endif
      glyph_width_bit_nv;

    opt_c_api_constant<
      mp_list<path_metric_query_nv>,
#ifdef GL_GLYPH_HEIGHT_BIT_NV
      bitfield_type_c<GL_GLYPH_HEIGHT_BIT_NV>>
#else
      bitfield_type_i>
#endif
      glyph_height_bit_nv;

    opt_c_api_constant<
      mp_list<path_metric_query_nv>,
#ifdef GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV
      bitfield_type_c<GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV>>
#else
      bitfield_type_i>
#endif
      glyph_horizontal_bearing_x_bit_nv;

    opt_c_api_constant<
      mp_list<path_metric_query_nv>,
#ifdef GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV
      bitfield_type_c<GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV>>
#else
      bitfield_type_i>
#endif
      glyph_horizontal_bearing_y_bit_nv;

    opt_c_api_constant<
      mp_list<path_metric_query_nv>,
#ifdef GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV
      bitfield_type_c<GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV>>
#else
      bitfield_type_i>
#endif
      glyph_horizontal_bearing_advance_bit_nv;

    opt_c_api_constant<
      mp_list<path_metric_query_nv>,
#ifdef GL_GLYPH_VERTICAL_BEARING_X_BIT_NV
      bitfield_type_c<GL_GLYPH_VERTICAL_BEARING_X_BIT_NV>>
#else
      bitfield_type_i>
#endif
      glyph_vertical_bearing_x_bit_nv;

    opt_c_api_constant<
      mp_list<path_metric_query_nv>,
#ifdef GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV
      bitfield_type_c<GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV>>
#else
      bitfield_type_i>
#endif
      glyph_vertical_bearing_y_bit_nv;

    opt_c_api_constant<
      mp_list<path_metric_query_nv>,
#ifdef GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV
      bitfield_type_c<GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV>>
#else
      bitfield_type_i>
#endif
      glyph_vertical_bearing_advance_bit_nv;

    opt_c_api_constant<
      mp_list<path_metric_query_nv>,
#ifdef GL_GLYPH_HAS_KERNING_BIT_NV
      bitfield_type_c<GL_GLYPH_HAS_KERNING_BIT_NV>>
#else
      bitfield_type_i>
#endif
      glyph_has_kerning_bit_nv;

    opt_c_api_constant<
      mp_list<path_metric_query_nv>,
#ifdef GL_FONT_X_MIN_BOUNDS_BIT_NV
      bitfield_type_c<GL_FONT_X_MIN_BOUNDS_BIT_NV>>
#else
      bitfield_type_i>
#endif
      font_x_min_bounds_bit_nv;

    opt_c_api_constant<
      mp_list<path_metric_query_nv>,
#ifdef GL_FONT_Y_MIN_BOUNDS_BIT_NV
      bitfield_type_c<GL_FONT_Y_MIN_BOUNDS_BIT_NV>>
#else
      bitfield_type_i>
#endif
      font_y_min_bounds_bit_nv;

    opt_c_api_constant<
      mp_list<path_metric_query_nv>,
#ifdef GL_FONT_X_MAX_BOUNDS_BIT_NV
      bitfield_type_c<GL_FONT_X_MAX_BOUNDS_BIT_NV>>
#else
      bitfield_type_i>
#endif
      font_x_max_bounds_bit_nv;

    opt_c_api_constant<
      mp_list<path_metric_query_nv>,
#ifdef GL_FONT_Y_MAX_BOUNDS_BIT_NV
      bitfield_type_c<GL_FONT_Y_MAX_BOUNDS_BIT_NV>>
#else
      bitfield_type_i>
#endif
      font_y_max_bounds_bit_nv;

    opt_c_api_constant<
      mp_list<path_metric_query_nv>,
#ifdef GL_FONT_UNITS_PER_EM_BIT_NV
      bitfield_type_c<GL_FONT_UNITS_PER_EM_BIT_NV>>
#else
      bitfield_type_i>
#endif
      font_units_per_em_bit_nv;

    opt_c_api_constant<
      mp_list<path_metric_query_nv>,
#ifdef GL_FONT_ASCENDER_BIT_NV
      bitfield_type_c<GL_FONT_ASCENDER_BIT_NV>>
#else
      bitfield_type_i>
#endif
      font_ascender_bit_nv;

    opt_c_api_constant<
      mp_list<path_metric_query_nv>,
#ifdef GL_FONT_DESCENDER_BIT_NV
      bitfield_type_c<GL_FONT_DESCENDER_BIT_NV>>
#else
      bitfield_type_i>
#endif
      font_descender_bit_nv;

    opt_c_api_constant<
      mp_list<path_metric_query_nv>,
#ifdef GL_FONT_HEIGHT_BIT_NV
      bitfield_type_c<GL_FONT_HEIGHT_BIT_NV>>
#else
      bitfield_type_i>
#endif
      font_height_bit_nv;

    opt_c_api_constant<
      mp_list<path_metric_query_nv>,
#ifdef GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV
      bitfield_type_c<GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV>>
#else
      bitfield_type_i>
#endif
      font_max_advance_width_bit_nv;

    opt_c_api_constant<
      mp_list<path_metric_query_nv>,
#ifdef GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV
      bitfield_type_c<GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV>>
#else
      bitfield_type_i>
#endif
      font_max_advance_height_bit_nv;

    opt_c_api_constant<
      mp_list<path_metric_query_nv>,
#ifdef GL_FONT_UNDERLINE_POSITION_BIT_NV
      bitfield_type_c<GL_FONT_UNDERLINE_POSITION_BIT_NV>>
#else
      bitfield_type_i>
#endif
      font_underline_position_bit_nv;

    opt_c_api_constant<
      mp_list<path_metric_query_nv>,
#ifdef GL_FONT_UNDERLINE_THICKNESS_BIT_NV
      bitfield_type_c<GL_FONT_UNDERLINE_THICKNESS_BIT_NV>>
#else
      bitfield_type_i>
#endif
      font_underline_thickness_bit_nv;

    opt_c_api_constant<
      mp_list<path_metric_query_nv>,
#ifdef GL_FONT_HAS_KERNING_BIT_NV
      bitfield_type_c<GL_FONT_HAS_KERNING_BIT_NV>>
#else
      bitfield_type_i>
#endif
      font_has_kerning_bit_nv;

    opt_c_api_constant<
      mp_list<path_missing_glyph_nv>,
#ifdef GL_SKIP_MISSING_GLYPH_NV
      enum_type_c<GL_SKIP_MISSING_GLYPH_NV>>
#else
      enum_type_i>
#endif
      skip_missing_glyph_nv;

    opt_c_api_constant<
      mp_list<path_missing_glyph_nv>,
#ifdef GL_USE_MISSING_GLYPH_NV
      enum_type_c<GL_USE_MISSING_GLYPH_NV>>
#else
      enum_type_i>
#endif
      use_missing_glyph_nv;

    opt_c_api_constant<
      mp_list<path_parameter_nv>,
#ifdef GL_PATH_COMMAND_COUNT_NV
      enum_type_c<GL_PATH_COMMAND_COUNT_NV>>
#else
      enum_type_i>
#endif
      path_command_count_nv;

    opt_c_api_constant<
      mp_list<path_parameter_nv>,
#ifdef GL_PATH_COORD_COUNT_NV
      enum_type_c<GL_PATH_COORD_COUNT_NV>>
#else
      enum_type_i>
#endif
      path_coord_count_nv;

    opt_c_api_constant<
      mp_list<path_parameter_nv>,
#ifdef GL_PATH_COMPUTED_LENGTH_NV
      enum_type_c<GL_PATH_COMPUTED_LENGTH_NV>>
#else
      enum_type_i>
#endif
      path_computed_length_nv;

    opt_c_api_constant<
      mp_list<path_parameter_nv>,
#ifdef GL_PATH_STROKE_WIDTH_NV
      enum_type_c<GL_PATH_STROKE_WIDTH_NV>>
#else
      enum_type_i>
#endif
      path_stroke_width_nv;

    opt_c_api_constant<
      mp_list<path_parameter_nv>,
#ifdef GL_PATH_INITIAL_END_CAP_NV
      enum_type_c<GL_PATH_INITIAL_END_CAP_NV>>
#else
      enum_type_i>
#endif
      path_initial_end_cap_nv;

    opt_c_api_constant<
      mp_list<path_parameter_nv>,
#ifdef GL_PATH_TERMINAL_END_CAP_NV
      enum_type_c<GL_PATH_TERMINAL_END_CAP_NV>>
#else
      enum_type_i>
#endif
      path_terminal_end_cap_nv;

    opt_c_api_constant<
      mp_list<path_parameter_nv>,
#ifdef GL_PATH_JOIN_STYLE_NV
      enum_type_c<GL_PATH_JOIN_STYLE_NV>>
#else
      enum_type_i>
#endif
      path_join_style_nv;

    opt_c_api_constant<
      mp_list<path_parameter_nv>,
#ifdef GL_PATH_MITER_LIMIT_NV
      enum_type_c<GL_PATH_MITER_LIMIT_NV>>
#else
      enum_type_i>
#endif
      path_miter_limit_nv;

    opt_c_api_constant<
      mp_list<path_parameter_nv>,
#ifdef GL_PATH_DASH_ARRAY_COUNT_NV
      enum_type_c<GL_PATH_DASH_ARRAY_COUNT_NV>>
#else
      enum_type_i>
#endif
      path_dash_array_count_nv;

    opt_c_api_constant<
      mp_list<path_parameter_nv>,
#ifdef GL_PATH_DASH_OFFSET_NV
      enum_type_c<GL_PATH_DASH_OFFSET_NV>>
#else
      enum_type_i>
#endif
      path_dash_offset_nv;

    opt_c_api_constant<
      mp_list<path_parameter_nv>,
#ifdef GL_PATH_DASH_OFFSET_RESET_NV
      enum_type_c<GL_PATH_DASH_OFFSET_RESET_NV>>
#else
      enum_type_i>
#endif
      path_dash_offset_reset_nv;

    opt_c_api_constant<
      mp_list<path_parameter_nv>,
#ifdef GL_PATH_CLIENT_LENGTH_NV
      enum_type_c<GL_PATH_CLIENT_LENGTH_NV>>
#else
      enum_type_i>
#endif
      path_client_length_nv;

    opt_c_api_constant<
      mp_list<path_parameter_nv>,
#ifdef GL_PATH_INITIAL_DASH_CAP_NV
      enum_type_c<GL_PATH_INITIAL_DASH_CAP_NV>>
#else
      enum_type_i>
#endif
      path_initial_dash_cap_nv;

    opt_c_api_constant<
      mp_list<path_parameter_nv>,
#ifdef GL_PATH_TERMINAL_DASH_CAP_NV
      enum_type_c<GL_PATH_TERMINAL_DASH_CAP_NV>>
#else
      enum_type_i>
#endif
      path_terminal_dash_cap_nv;

    opt_c_api_constant<
      mp_list<path_parameter_nv>,
#ifdef GL_PATH_FILL_MODE_NV
      enum_type_c<GL_PATH_FILL_MODE_NV>>
#else
      enum_type_i>
#endif
      path_fill_mode_nv;

    opt_c_api_constant<
      mp_list<path_parameter_nv>,
#ifdef GL_PATH_FILL_MASK_NV
      enum_type_c<GL_PATH_FILL_MASK_NV>>
#else
      enum_type_i>
#endif
      path_fill_mask_nv;

    opt_c_api_constant<
      mp_list<path_parameter_nv>,
#ifdef GL_PATH_FILL_COVER_MODE_NV
      enum_type_c<GL_PATH_FILL_COVER_MODE_NV>>
#else
      enum_type_i>
#endif
      path_fill_cover_mode_nv;

    opt_c_api_constant<
      mp_list<path_parameter_nv>,
#ifdef GL_PATH_STROKE_COVER_MODE_NV
      enum_type_c<GL_PATH_STROKE_COVER_MODE_NV>>
#else
      enum_type_i>
#endif
      path_stroke_cover_mode_nv;

    opt_c_api_constant<
      mp_list<path_parameter_nv>,
#ifdef GL_PATH_STROKE_MASK_NV
      enum_type_c<GL_PATH_STROKE_MASK_NV>>
#else
      enum_type_i>
#endif
      path_stroke_mask_nv;

    opt_c_api_constant<
      mp_list<path_parameter_nv>,
#ifdef GL_PATH_STROKE_BOUND_NV
      enum_type_c<GL_PATH_STROKE_BOUND_NV>>
#else
      enum_type_i>
#endif
      path_stroke_bound_nv;

    opt_c_api_constant<
      mp_list<path_parameter_nv>,
#ifdef GL_PATH_FILL_BOUNDING_BOX_NV
      enum_type_c<GL_PATH_FILL_BOUNDING_BOX_NV>>
#else
      enum_type_i>
#endif
      path_fill_bounding_box_nv;

    opt_c_api_constant<
      mp_list<path_parameter_nv>,
#ifdef GL_PATH_STROKE_BOUNDING_BOX_NV
      enum_type_c<GL_PATH_STROKE_BOUNDING_BOX_NV>>
#else
      enum_type_i>
#endif
      path_stroke_bounding_box_nv;

    opt_c_api_constant<
      mp_list<path_transform_type_nv>,
#ifdef GL_TRANSLATE_X_NV
      enum_type_c<GL_TRANSLATE_X_NV>>
#else
      enum_type_i>
#endif
      translate_x_nv;

    opt_c_api_constant<
      mp_list<path_transform_type_nv>,
#ifdef GL_TRANSLATE_Y_NV
      enum_type_c<GL_TRANSLATE_Y_NV>>
#else
      enum_type_i>
#endif
      translate_y_nv;

    opt_c_api_constant<
      mp_list<path_transform_type_nv>,
#ifdef GL_TRANSLATE_2D_NV
      enum_type_c<GL_TRANSLATE_2D_NV>>
#else
      enum_type_i>
#endif
      translate_2d_nv;

    opt_c_api_constant<
      mp_list<path_transform_type_nv>,
#ifdef GL_TRANSLATE_3D_NV
      enum_type_c<GL_TRANSLATE_3D_NV>>
#else
      enum_type_i>
#endif
      translate_3d_nv;

    opt_c_api_constant<
      mp_list<path_transform_type_nv>,
#ifdef GL_AFFINE_2D_NV
      enum_type_c<GL_AFFINE_2D_NV>>
#else
      enum_type_i>
#endif
      affine_2d_nv;

    opt_c_api_constant<
      mp_list<path_transform_type_nv>,
#ifdef GL_AFFINE_3D_NV
      enum_type_c<GL_AFFINE_3D_NV>>
#else
      enum_type_i>
#endif
      affine_3d_nv;

    opt_c_api_constant<
      mp_list<path_transform_type_nv>,
#ifdef GL_TRANSPOSE_AFFINE_2D_NV
      enum_type_c<GL_TRANSPOSE_AFFINE_2D_NV>>
#else
      enum_type_i>
#endif
      transpose_affine_2d_nv;

    opt_c_api_constant<
      mp_list<path_transform_type_nv>,
#ifdef GL_TRANSPOSE_AFFINE_3D_NV
      enum_type_c<GL_TRANSPOSE_AFFINE_3D_NV>>
#else
      enum_type_i>
#endif
      transpose_affine_3d_nv;

    opt_c_api_constant<
      mp_list<path_text_encoding_nv>,
#ifdef GL_UTF8_NV
      enum_type_c<GL_UTF8_NV>>
#else
      enum_type_i>
#endif
      utf8_nv;

    opt_c_api_constant<
      mp_list<path_text_encoding_nv>,
#ifdef GL_UTF16_NV
      enum_type_c<GL_UTF16_NV>>
#else
      enum_type_i>
#endif
      utf16_nv;

    // none
    opt_c_api_constant<
      mp_list<
        support_level,
        surface_buffer,
        sl_data_type,
        index_data_type,
        oglp::texture_compare_mode,
        oglp::context_release_behavior,
        oglp::path_join_style_nv,
        oglp::path_gen_mode_nv,
        oglp::path_transform_type_nv>,
#ifdef GL_NONE
      bitfield_type_c<GL_NONE>>
#else
      bitfield_type_i>
#endif
      none;

    basic_gl_constants(ApiTraits& traits, basic_gl_c_api<ApiTraits>& api);
};
//------------------------------------------------------------------------------
} // namespace eagine::oglp

#endif // OGLPLUS_GL_API_CONSTANTS_HPP
