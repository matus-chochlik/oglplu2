/**
 *  @file oglplus/query.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/utils/gl_func.hpp>

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
inline
outcome<void>
query_ops::
begin_query(query_target target, query_name qry)
noexcept
{
	OGLPLUS_GLFUNC(BeginQuery)(
		GLenum(target),
		get_raw_name(qry)
	);
	OGLPLUS_VERIFY(
		BeginQuery,
		gl_enum_value(target).
		gl_object(qry),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
query_ops::
end_query(query_target target)
noexcept
{
	OGLPLUS_GLFUNC(EndQuery)(GLenum(target));
	OGLPLUS_VERIFY(
		EndQuery,
		gl_enum_value(target),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_0)
//------------------------------------------------------------------------------
inline
outcome<void>
query_ops::
begin_query_indexed(query_target target, GLuint index, query_name qry)
noexcept
{
	OGLPLUS_GLFUNC(BeginQueryIndexed)(
		GLenum(target),
		index,
		get_raw_name(qry)
	);
	OGLPLUS_VERIFY(
		BeginQueryIndexed,
		gl_enum_value(target).
		gl_object(qry).
		gl_index(index),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
query_ops::
end_query_indexed(query_target target, GLuint index)
noexcept
{
	OGLPLUS_GLFUNC(EndQueryIndexed)(GLenum(target), index);
	OGLPLUS_VERIFY(
		EndQueryIndexed,
		gl_enum_value(target).
		gl_index(index),
		debug
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_0)
inline
outcome<void>
query_ops::
begin_conditional_render(query_name qry, conditional_render_mode mode)
noexcept
{
	OGLPLUS_GLFUNC(BeginConditionalRender)(
		get_raw_name(qry),
		GLenum(mode)
	);
	OGLPLUS_VERIFY(
		BeginConditionalRender,
		gl_object(qry).
		gl_enum_value(mode),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
query_ops::
end_conditional_render(void)
noexcept
{
	OGLPLUS_GLFUNC(EndConditionalRender)();
	OGLPLUS_VERIFY_SIMPLE(EndConditionalRender, debug);
	return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_3) || defined (GL_ARB_timer_query)
inline
outcome<void>
query_ops::
query_counter(query_name qry, query_target target)
noexcept
{
	OGLPLUS_GLFUNC(QueryCounter)(
		get_raw_name(qry),
		GLenum(target)
	);
	OGLPLUS_VERIFY(
		QueryCounter,
		gl_object(qry).
		gl_enum_value(target),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
query_ops::
query_timestamp(query_name qry)
noexcept
{
	return query_counter(qry, query_target(GL_TIMESTAMP));
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_0)
inline
outcome<void>
query_ops::
get_query_object_iv(
	query_name qry,
	oglplus::query_parameter param,
	span<GLint> values
) noexcept
{
	assert(values.size() > 0);
	OGLPLUS_GLFUNC(GetQueryObjectiv)(
		get_raw_name(qry),
		GLenum(param),
		values.data()
	);
	OGLPLUS_VERIFY(
		GetQueryObjectiv,
		gl_object(qry).
		gl_enum_value(param),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
query_ops::
get_query_object_uiv(
	query_name qry,
	oglplus::query_parameter param,
	span<GLuint> values
) noexcept
{
	assert(values.size() > 0);
	OGLPLUS_GLFUNC(GetQueryObjectuiv)(
		get_raw_name(qry),
		GLenum(param),
		values.data()
	);
	OGLPLUS_VERIFY(
		GetQueryObjectuiv,
		gl_object(qry).
		gl_enum_value(param),
		always
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_3) || defined (GL_ARB_timer_query)
inline
outcome<void>
query_ops::
get_query_object_i64v(
	query_name qry,
	oglplus::query_parameter param,
	span<GLint64> values
) noexcept
{
	assert(values.size() > 0);
	OGLPLUS_GLFUNC(GetQueryObjecti64v)(
		get_raw_name(qry),
		GLenum(param),
		values.data()
	);
	OGLPLUS_VERIFY(
		GetQueryObjecti64v,
		gl_object(qry).
		gl_enum_value(param),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
query_ops::
get_query_object_ui64v(
	query_name qry,
	oglplus::query_parameter param,
	span<GLuint64> values
) noexcept
{
	assert(values.size() > 0);
	OGLPLUS_GLFUNC(GetQueryObjectui64v)(
		get_raw_name(qry),
		GLenum(param),
		values.data()
	);
	OGLPLUS_VERIFY(
		GetQueryObjectui64v,
		gl_object(qry).
		gl_enum_value(param),
		always
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_0)
inline
outcome<boolean>
query_ops::
query_result_available(query_name qry)
noexcept
{
	GLint result = GLint(GL_FALSE);
	return get_query_object_iv(
		qry,
		query_parameter(GL_QUERY_RESULT_AVAILABLE),
		{&result, 1}
	).add(boolean(GLboolean(result)));
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_0)
inline
outcome<void>
query_ops::
query_result(query_name qry, GLint& result)
noexcept
{
	return get_query_object_iv(
		qry,
		query_parameter(GL_QUERY_RESULT),
		{&result, 1}
	);
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_0)
inline
outcome<void>
query_ops::
query_result(query_name qry, GLuint& result)
noexcept
{
	return get_query_object_uiv(
		qry,
		query_parameter(GL_QUERY_RESULT),
		{&result, 1}
	);
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_3) || defined (GL_ARB_timer_query)
inline
outcome<void>
query_ops::
query_result(query_name qry, GLint64& result)
noexcept
{
	return get_query_object_i64v(
		qry,
		query_parameter(GL_QUERY_RESULT),
		{&result, 1}
	);
}
//------------------------------------------------------------------------------
inline
outcome<void>
query_ops::
query_result(query_name qry, GLuint64& result)
noexcept
{
	return get_query_object_ui64v(
		qry,
		query_parameter(GL_QUERY_RESULT),
		{&result, 1}
	);
}
#endif
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
// obj_gen_del_ops::_gen
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::query>::
_gen(span<GLuint> names)
noexcept
{
	OGLPLUS_GLFUNC(GenQueries)(
		GLsizei(names.size()),
		names.data()
	);
	OGLPLUS_VERIFY_SIMPLE(GenQueries,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_create
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_5)
inline
deferred_error_handler
obj_gen_del_ops<tag::query>::
_create(query_target target, span<GLuint> names)
noexcept
{
	OGLPLUS_GLFUNC(CreateQueries)(
		GLenum(target),
		GLsizei(names.size()),
		names.data()
	);
	OGLPLUS_VERIFY_SIMPLE(CreateQueries, debug);
	return {};
}
#endif
//------------------------------------------------------------------------------
// obj_gen_del_ops::_delete
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::query>::
_delete(span<GLuint> names)
noexcept
{
	OGLPLUS_GLFUNC(DeleteQueries)(
		GLsizei(names.size()),
		names.data()
	);
	OGLPLUS_VERIFY_SIMPLE(DeleteQueries,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_is_a
//------------------------------------------------------------------------------
inline
outcome<boolean>
obj_gen_del_ops<tag::query>::
_is_a(GLuint name)
noexcept
{
	GLboolean res = OGLPLUS_GLFUNC(IsQuery)(name);
	OGLPLUS_VERIFY_SIMPLE(IsQuery,debug);
	return boolean(res);
}
//------------------------------------------------------------------------------
} // namespace oglplus
