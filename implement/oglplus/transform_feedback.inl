/**
 *  @file oglplus/transform_feedback.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/utils/gl_func.hpp>
#include <oglplus/oper/numeric_queries.hpp>

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include "enum/transform_feedback_target_bq.inl"
#endif

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
inline
outcome<void>
transform_feedback_ops::
bind_transform_feedback(
	transform_feedback_target target,
	transform_feedback_name xfb
) noexcept
{
	OGLPLUS_GLFUNC(BindTransformFeedback)(
		GLenum(target),
		get_raw_name(xfb)
	);
	OGLPLUS_VERIFY(
		BindTransformFeedback,
		gl_enum_value(target).
		gl_object(xfb),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<transform_feedback_name>
transform_feedback_ops::
transform_feedback_binding(transform_feedback_target target)
noexcept
{
	GLint result;
	return numeric_queries::get_integer_v(
		get_binding_query(target),
		{&result, 1}
	), transform_feedback_name(GLuint(result));
}
//------------------------------------------------------------------------------
inline
outcome<void>
transform_feedback_ops::
begin_transform_feedback(transform_feedback_primitive_type mode)
noexcept
{
	OGLPLUS_GLFUNC(BeginTransformFeedback)(GLenum(mode));
	OGLPLUS_VERIFY(
		BeginTransformFeedback,
		gl_enum_value(mode),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
transform_feedback_ops::
end_transform_feedback(void)
noexcept
{
	OGLPLUS_GLFUNC(EndTransformFeedback)();
	OGLPLUS_VERIFY_SIMPLE(EndTransformFeedback, debug);
	return {};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access)
inline
outcome<void>
transform_feedback_ops::
get_transform_feedback_iv(
	transform_feedback_name xfb,
	transform_feedback_parameter param,
	span<GLint> values
) noexcept
{
	assert(values.size() > 0);
	OGLPLUS_GLFUNC(GetTransformFeedbackiv)(
		get_raw_name(xfb),
		GLenum(param),
		values.data()
	);
	OGLPLUS_VERIFY(
		GetTransformFeedbackiv,
		gl_object(xfb).
		gl_enum_value(param),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
transform_feedback_ops::
get_transform_feedback_iv(
	transform_feedback_name xfb,
	transform_feedback_parameter param,
	GLuint index,
	span<GLint> values
) noexcept
{
	assert(values.size() > 0);
	OGLPLUS_GLFUNC(GetTransformFeedbacki_v)(
		get_raw_name(xfb),
		GLenum(param),
		index,
		values.data()
	);
	OGLPLUS_VERIFY(
		GetTransformFeedbacki_v,
		gl_index(index).
		gl_object(xfb).
		gl_enum_value(param),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
transform_feedback_ops::
get_transform_feedback_i64v(
	transform_feedback_name xfb,
	transform_feedback_parameter param,
	GLuint index,
	span<GLint64> values
) noexcept
{
	assert(values.size() > 0);
	OGLPLUS_GLFUNC(GetTransformFeedbacki64_v)(
		get_raw_name(xfb),
		GLenum(param),
		index,
		values.data()
	);
	OGLPLUS_VERIFY(
		GetTransformFeedbacki64_v,
		gl_index(index).
		gl_object(xfb).
		gl_enum_value(param),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<boolean>
transform_feedback_ops::
transform_feedback_active(transform_feedback_name xfb)
noexcept
{
	GLint result = 0;
	return get_transform_feedback_iv(
		xfb,
		transform_feedback_parameter(GL_TRANSFORM_FEEDBACK_ACTIVE),
		{&result, 1}
	), boolean(GLboolean(result));
}
//------------------------------------------------------------------------------
inline
outcome<boolean>
transform_feedback_ops::
transform_feedback_paused(transform_feedback_name xfb)
noexcept
{
	GLint result = 0;
	return get_transform_feedback_iv(
		xfb,
		transform_feedback_parameter(GL_TRANSFORM_FEEDBACK_PAUSED),
		{&result, 1}
	), boolean(GLboolean(result));
}
//------------------------------------------------------------------------------
inline
outcome<buffer_name>
transform_feedback_ops::
transform_feedback_buffer_binding(transform_feedback_name xfb)
noexcept
{
	GLint result = 0;
	return get_transform_feedback_iv(
		xfb,
		transform_feedback_parameter(
			GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
		), {&result, 1}
	), buffer_name(GLuint(result));
}
//------------------------------------------------------------------------------
inline
outcome<GLint64>
transform_feedback_ops::
transform_feedback_buffer_start(
	transform_feedback_name xfb,
	GLuint index
) noexcept
{
	GLint64 result = 0;
	return get_transform_feedback_i64v(
		xfb,
		transform_feedback_parameter(
			GL_TRANSFORM_FEEDBACK_BUFFER_START
		), index,
		{&result, 1}
	), result;
}
//------------------------------------------------------------------------------
inline
outcome<GLint64>
transform_feedback_ops::
transform_feedback_buffer_size(
	transform_feedback_name xfb,
	GLuint index
) noexcept
{
	GLint64 result = 0;
	return get_transform_feedback_i64v(
		xfb,
		transform_feedback_parameter(GL_TRANSFORM_FEEDBACK_BUFFER_SIZE),
		index,
		{&result, 1}
	), result;
}
//------------------------------------------------------------------------------
inline
outcome<void>
transform_feedback_ops::
transform_feedback_buffer_base(
	transform_feedback_name xfb,
	GLuint index,
	buffer_name buf
) noexcept
{
	OGLPLUS_GLFUNC(TransformFeedbackBufferBase)(
		get_raw_name(xfb),
		index,
		get_raw_name(buf)
	);
	OGLPLUS_VERIFY(
		TransformFeedbackBufferBase,
		gl_index(index).
		gl_subject(buf).
		gl_object(xfb),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
transform_feedback_ops::
transform_feedback_buffer_range(
	transform_feedback_name xfb,
	GLuint index,
	buffer_name buf,
	GLintptr offset,
	GLsizeiptr size
) noexcept
{
	OGLPLUS_GLFUNC(TransformFeedbackBufferRange)(
		get_raw_name(xfb),
		index,
		get_raw_name(buf),
		offset,
		size
	);
	OGLPLUS_VERIFY(
		TransformFeedbackBufferRange,
		gl_index(index).
		gl_subject(buf).
		gl_object(xfb),
		always
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
// obj_gen_del_ops::_gen
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::transform_feedback>::
_gen(span<GLuint> names)
noexcept
{
	OGLPLUS_GLFUNC(GenTransformFeedbacks)(
		GLsizei(names.size()),
		names.data()
	);
	OGLPLUS_VERIFY_SIMPLE(GenTransformFeedbacks,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_delete
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::transform_feedback>::
_delete(span<GLuint> names)
noexcept
{
	OGLPLUS_GLFUNC(DeleteTransformFeedbacks)(
		GLsizei(names.size()),
		names.data()
	);
	OGLPLUS_VERIFY_SIMPLE(DeleteTransformFeedbacks,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_is_a
//------------------------------------------------------------------------------
inline
outcome<boolean>
obj_gen_del_ops<tag::transform_feedback>::
_is_a(GLuint name)
noexcept
{
	GLboolean res = OGLPLUS_GLFUNC(IsTransformFeedback)(name);
	OGLPLUS_VERIFY_SIMPLE(IsTransformFeedback,debug);
	return boolean(res);
}
//------------------------------------------------------------------------------
} // namespace oglplus
