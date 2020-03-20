/**
 *  @file oglplus/gl_api/object_name.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_GL_API_OBJECT_NAME_HPP
#define OGLPLUS_GL_API_OBJECT_NAME_HPP

#include "config.hpp"
#include <eagine/handle.hpp>
#include <eagine/message_id.hpp>

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
template <typename Tag>
using gl_object_name = basic_handle<Tag, gl_types::name_type>;

template <typename Tag>
using gl_owned_object_name = basic_owned_handle<Tag, gl_types::name_type>;
//------------------------------------------------------------------------------
using buffer_tag = EAGINE_MSG_TYPE(gl, Buffer);
using framebuffer_tag = EAGINE_MSG_TYPE(gl, Frmebuffer);
using program_pipeline_tag = EAGINE_MSG_TYPE(gl, PrgPpline);
using program_tag = EAGINE_MSG_TYPE(gl, Program);
using query_tag = EAGINE_MSG_TYPE(gl, Query);
using renderbuffer_tag = EAGINE_MSG_TYPE(gl, Rndrbuffer);
using sampler_tag = EAGINE_MSG_TYPE(gl, Sampler);
using shader_tag = EAGINE_MSG_TYPE(gl, Shader);
using texture_tag = EAGINE_MSG_TYPE(gl, Texture);
using transform_feedback_tag = EAGINE_MSG_TYPE(gl, TransfFdbk);
using vertex_array_tag = EAGINE_MSG_TYPE(gl, VertexArry);
using path_nv_tag = EAGINE_MSG_TYPE(gl, PathNV);
//------------------------------------------------------------------------------
using buffer_name = gl_object_name<buffer_tag>;
using framebuffer_name = gl_object_name<framebuffer_tag>;
using program_pipeline_name = gl_object_name<program_pipeline_tag>;
using program_name = gl_object_name<program_tag>;
using query_name = gl_object_name<query_tag>;
using renderbuffer_name = gl_object_name<renderbuffer_tag>;
using sampler_name = gl_object_name<sampler_tag>;
using shader_name = gl_object_name<shader_tag>;
using texture_name = gl_object_name<texture_tag>;
using transform_feedback_name = gl_object_name<transform_feedback_tag>;
using vertex_array_name = gl_object_name<vertex_array_tag>;
using path_nv_name = gl_object_name<path_nv_tag>;
//------------------------------------------------------------------------------
using owned_buffer_name = gl_owned_object_name<buffer_tag>;
using owned_framebuffer_name = gl_owned_object_name<framebuffer_tag>;
using owned_program_pipeline_name = gl_owned_object_name<program_pipeline_tag>;
using owned_program_name = gl_owned_object_name<program_tag>;
using owned_query_name = gl_owned_object_name<query_tag>;
using owned_renderbuffer_name = gl_owned_object_name<renderbuffer_tag>;
using owned_sampler_name = gl_owned_object_name<sampler_tag>;
using owned_shader_name = gl_owned_object_name<shader_tag>;
using owned_texture_name = gl_owned_object_name<texture_tag>;
using owned_transform_feedback_name =
  gl_owned_object_name<transform_feedback_tag>;
using owned_vertex_array_name = gl_owned_object_name<vertex_array_tag>;
using owned_path_nv_name = gl_owned_object_name<path_nv_tag>;
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine

#endif // OGLPLUS_GL_API_OBJECT_NAME_HPP

