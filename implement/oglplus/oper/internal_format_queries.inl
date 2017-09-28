/**
 *  @file oglplus/oper/internal_format_queries.inl
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
#if defined(GL_VERSION_4_2)
inline
outcome<void>
internal_format_queries::
get_internal_format_iv(
	internal_format_target target,
	pixel_data_internal_format iformat,
	internal_format_parameter query,
	span<GLint> data
) noexcept {
	assert(data.size() > 0);
	OGLPLUS_GLFUNC(GetInternalformativ)(
		GLenum(target),
		GLenum(iformat),
		GLenum(query),
		GLsizei(data.size()),
		data.data()
	);
	OGLPLUS_VERIFY(
		GetInternalFormativ,
		gl_enum_value(query),
		always
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_3)
inline
outcome<void>
internal_format_queries::
get_internal_format_i64v(
	internal_format_target target,
	pixel_data_internal_format iformat,
	internal_format_parameter query,
	span<GLint64> data
) noexcept {
	assert(data.size() > 0);
	OGLPLUS_GLFUNC(GetInternalformati64v)(
		GLenum(target),
		GLenum(iformat),
		GLenum(query),
		GLsizei(data.size()),
		data.data()
	);
	OGLPLUS_VERIFY(
		GetInternalFormati64v,
		gl_enum_value(query),
		always
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
} // namespace oglplus
