/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OGLPLUS_GL_API_OBJECT_NAME_HPP
#define OGLPLUS_GL_API_OBJECT_NAME_HPP

#include "config.hpp"
#include <eagine/handle.hpp>
#include <eagine/message_id.hpp>

namespace eagine::oglp {
//------------------------------------------------------------------------------
/// @brief Alias for template wrapping GL object handles.
/// @ingroup gl_api_wrap
/// @see gl_owned_object_name
/// @see gl_object_name_view
/// @see gl_object_name_span
/// @see gl_object_name_array
template <typename Tag>
using gl_object_name = basic_handle<Tag, gl_types::name_type>;

/// @brief Alias for template wrapping owned GL object handles.
/// @ingroup gl_api_wrap
/// @see gl_object_name
template <typename Tag>
using gl_owned_object_name = basic_owned_handle<Tag, gl_types::name_type>;

/// @brief Alias for template wrapping a mutable span of GL object handles.
/// @ingroup gl_api_wrap
/// @see gl_object_name_view
/// @see gl_object_name_array
template <typename Tag>
using gl_object_name_span = basic_handle_span<gl_object_name<Tag>>;

/// @brief Alias for template wrapping a const span of GL object handles.
/// @ingroup gl_api_wrap
/// @see gl_object_name_span
/// @see gl_object_name_array
template <typename Tag>
using gl_object_name_view = basic_handle_view<gl_object_name<Tag>>;

/// @brief Alias for template wrapping an array of GL object handles.
/// @ingroup gl_api_wrap
/// @see gl_object_name_vector
/// @see gl_object_name_span
/// @see gl_object_name_view
template <typename Tag, std::size_t N>
using gl_object_name_array = basic_handle_array<gl_object_name<Tag>, N>;

/// @brief Alias for template wrapping a vector of GL object handles.
/// @ingroup gl_api_wrap
/// @see gl_object_name_array
/// @see gl_object_name_span
/// @see gl_object_name_view
template <typename Tag>
using gl_object_name_vector = basic_handle_vector<gl_object_name<Tag>>;
//------------------------------------------------------------------------------
/// @brief Tag type denoting GL buffer objects.
/// @ingroup gl_api_wrap
using buffer_tag = EAGINE_MSG_TYPE(gl, Buffer);

/// @brief Tag type denoting GL framebuffer objects.
/// @ingroup gl_api_wrap
using framebuffer_tag = EAGINE_MSG_TYPE(gl, Frmebuffer);

/// @brief Tag type denoting GL program pipeline objects.
/// @ingroup gl_api_wrap
using program_pipeline_tag = EAGINE_MSG_TYPE(gl, PrgPpline);

/// @brief Tag type denoting GL program objects.
/// @ingroup gl_api_wrap
using program_tag = EAGINE_MSG_TYPE(gl, Program);

/// @brief Tag type denoting GL query objects.
/// @ingroup gl_api_wrap
using query_tag = EAGINE_MSG_TYPE(gl, Query);

/// @brief Tag type denoting GL renderbuffer objects.
/// @ingroup gl_api_wrap
using renderbuffer_tag = EAGINE_MSG_TYPE(gl, Rndrbuffer);

/// @brief Tag type denoting GL sampler objects.
/// @ingroup gl_api_wrap
using sampler_tag = EAGINE_MSG_TYPE(gl, Sampler);

/// @brief Tag type denoting GL shader objects.
/// @ingroup gl_api_wrap
using shader_tag = EAGINE_MSG_TYPE(gl, Shader);

/// @brief Tag type denoting GL texture objects.
/// @ingroup gl_api_wrap
using texture_tag = EAGINE_MSG_TYPE(gl, Texture);

/// @brief Tag type denoting GL transform feedback objects.
/// @ingroup gl_api_wrap
using transform_feedback_tag = EAGINE_MSG_TYPE(gl, TransfFdbk);

/// @brief Tag type denoting GL vertex array objects.
/// @ingroup gl_api_wrap
using vertex_array_tag = EAGINE_MSG_TYPE(gl, VertexArry);

/// @brief Tag type denoting GL path objects.
/// @ingroup gl_api_wrap
using path_nv_tag = EAGINE_MSG_TYPE(gl, PathNV);
//------------------------------------------------------------------------------
/// @brief Alias for GL buffer object handle.
/// @ingroup gl_api_wrap
/// @see owned_buffer_name
using buffer_name = gl_object_name<buffer_tag>;

/// @brief Alias for GL framebuffer object handle.
/// @ingroup gl_api_wrap
/// @see owned_framebuffer_name
using framebuffer_name = gl_object_name<framebuffer_tag>;

/// @brief Alias for GL program pipeline object handle.
/// @ingroup gl_api_wrap
/// @see owned_program_pipeline_name
using program_pipeline_name = gl_object_name<program_pipeline_tag>;

/// @brief Alias for GL program object handle.
/// @ingroup gl_api_wrap
/// @see owned_program_name
using program_name = gl_object_name<program_tag>;

/// @brief Alias for GL query object handle.
/// @ingroup gl_api_wrap
/// @see owned_query_name
using query_name = gl_object_name<query_tag>;

/// @brief Alias for GL renderbuffer object handle.
/// @ingroup gl_api_wrap
/// @see owned_renderbuffer_name
using renderbuffer_name = gl_object_name<renderbuffer_tag>;

/// @brief Alias for GL sampler object handle.
/// @ingroup gl_api_wrap
/// @see owned_sampler_name
using sampler_name = gl_object_name<sampler_tag>;

/// @brief Alias for GL shader object handle.
/// @ingroup gl_api_wrap
/// @see owned_shader_name
using shader_name = gl_object_name<shader_tag>;

/// @brief Alias for GL texture object handle.
/// @ingroup gl_api_wrap
/// @see owned_texture_name
using texture_name = gl_object_name<texture_tag>;

/// @brief Alias for GL transform feedback object handle.
/// @ingroup gl_api_wrap
/// @see owned_transform_feedback_name
using transform_feedback_name = gl_object_name<transform_feedback_tag>;

/// @brief Alias for GL vertex array object handle.
/// @ingroup gl_api_wrap
/// @see owned_vertex_array_name
using vertex_array_name = gl_object_name<vertex_array_tag>;

/// @brief Alias for GL path object handle.
/// @ingroup gl_api_wrap
/// @see owned_path_nv_name
using path_nv_name = gl_object_name<path_nv_tag>;
//------------------------------------------------------------------------------
/// @brief Alias for owned GL buffer object handle.
/// @ingroup gl_api_wrap
/// @see buffer_name
using owned_buffer_name = gl_owned_object_name<buffer_tag>;

/// @brief Alias for owned GL framebuffer object handle.
/// @ingroup gl_api_wrap
/// @see framebuffer_name
using owned_framebuffer_name = gl_owned_object_name<framebuffer_tag>;

/// @brief Alias for owned GL program_pipeline object handle.
/// @ingroup gl_api_wrap
/// @see program_pipeline_name
using owned_program_pipeline_name = gl_owned_object_name<program_pipeline_tag>;

/// @brief Alias for owned GL program object handle.
/// @ingroup gl_api_wrap
/// @see program_name
using owned_program_name = gl_owned_object_name<program_tag>;

/// @brief Alias for owned GL query object handle.
/// @ingroup gl_api_wrap
/// @see query_name
using owned_query_name = gl_owned_object_name<query_tag>;

/// @brief Alias for owned GL renderbuffer object handle.
/// @ingroup gl_api_wrap
/// @see renderbuffer_name
using owned_renderbuffer_name = gl_owned_object_name<renderbuffer_tag>;

/// @brief Alias for owned GL sampler object handle.
/// @ingroup gl_api_wrap
/// @see sampler_name
using owned_sampler_name = gl_owned_object_name<sampler_tag>;

/// @brief Alias for owned GL shader object handle.
/// @ingroup gl_api_wrap
/// @see shader_name
using owned_shader_name = gl_owned_object_name<shader_tag>;

/// @brief Alias for owned GL texture object handle.
/// @ingroup gl_api_wrap
/// @see texture_name
using owned_texture_name = gl_owned_object_name<texture_tag>;

/// @brief Alias for owned GL transform feedback  object handle.
/// @ingroup gl_api_wrap
/// @see transform_feedback_name
using owned_transform_feedback_name =
  gl_owned_object_name<transform_feedback_tag>;

/// @brief Alias for owned GL vertex array object handle.
/// @ingroup gl_api_wrap
/// @see vertex_array_name
using owned_vertex_array_name = gl_owned_object_name<vertex_array_tag>;

/// @brief Alias for owned GL path object handle.
/// @ingroup gl_api_wrap
/// @see path_nv_name
using owned_path_nv_name = gl_owned_object_name<path_nv_tag>;
//------------------------------------------------------------------------------
/// @brief Alias for array of N GL buffer object handles.
/// @ingroup gl_api_wrap
/// @see buffer_name
template <std::size_t N>
using buffer_name_array = gl_object_name_array<buffer_tag, N>;

/// @brief Alias for array of N GL framebuffer object handles.
/// @ingroup gl_api_wrap
/// @see framebuffer_name
template <std::size_t N>
using framebuffer_name_array = gl_object_name_array<framebuffer_tag, N>;

/// @brief Alias for array of N GL program pipeline  object handles.
/// @ingroup gl_api_wrap
/// @see program_pipeline_name
template <std::size_t N>
using program_pipeline_name_array =
  gl_object_name_array<program_pipeline_tag, N>;

/// @brief Alias for array of N GL program object handles.
/// @ingroup gl_api_wrap
/// @see program_name
template <std::size_t N>
using program_name_array = gl_object_name_array<program_tag, N>;

/// @brief Alias for array of N GL query object handles.
/// @ingroup gl_api_wrap
/// @see query_name
template <std::size_t N>
using query_name_array = gl_object_name_array<query_tag, N>;

/// @brief Alias for array of N GL renderbuffer object handles.
/// @ingroup gl_api_wrap
/// @see renderbuffer_name
template <std::size_t N>
using renderbuffer_name_array = gl_object_name_array<renderbuffer_tag, N>;

/// @brief Alias for array of N GL sampler object handles.
/// @ingroup gl_api_wrap
/// @see sampler_name
template <std::size_t N>
using sampler_name_array = gl_object_name_array<sampler_tag, N>;

/// @brief Alias for array of N GL shader object handles.
/// @ingroup gl_api_wrap
/// @see shader_name
template <std::size_t N>
using shader_name_array = gl_object_name_array<shader_tag, N>;

/// @brief Alias for array of N GL texture object handles.
/// @ingroup gl_api_wrap
/// @see texture_name
template <std::size_t N>
using texture_name_array = gl_object_name_array<texture_tag, N>;

/// @brief Alias for array of N GL transform feedback object handles.
/// @ingroup gl_api_wrap
/// @see transform_feedback_name
template <std::size_t N>
using transform_feedback_name_array =
  gl_object_name_array<transform_feedback_tag, N>;

/// @brief Alias for array of N GL vertex array object handles.
/// @ingroup gl_api_wrap
/// @see vertex_array_name
template <std::size_t N>
using vertex_array_name_array = gl_object_name_array<vertex_array_tag, N>;
//------------------------------------------------------------------------------
} // namespace eagine::oglp

#endif // OGLPLUS_GL_API_OBJECT_NAME_HPP
