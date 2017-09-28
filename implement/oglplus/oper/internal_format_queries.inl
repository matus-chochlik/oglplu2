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
//------------------------------------------------------------------------------
template <typename Result, typename Temp>
inline
outcome<Result>
internal_format_queries::
return_internal_format_i(
	internal_format_target target,
	pixel_data_internal_format iformat,
	internal_format_parameter param
) noexcept {
	GLint result = 0;

	return get_internal_format_iv(
		target,
		iformat,
		param,
		{&result, 1}
	).add(Result(Temp(result)));
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
//------------------------------------------------------------------------------
template <typename Result, typename Temp>
inline
outcome<Result>
internal_format_queries::
return_internal_format_i64(
	internal_format_target target,
	pixel_data_internal_format iformat,
	internal_format_parameter param
) noexcept {
	GLint64 result = 0;

	return get_internal_format_i64v(
		target,
		iformat,
		param,
		{&result, 1}
	).add(Result(Temp(result)));
}
//------------------------------------------------------------------------------
inline
outcome<boolean>
internal_format_queries::
is_internal_format_supported(
	internal_format_target target,
	pixel_data_internal_format iformat
) noexcept {
	return return_internal_format_i<boolean, GLboolean>(
		target, iformat,
		internal_format_parameter(GL_INTERNALFORMAT_SUPPORTED)
	);
}
//------------------------------------------------------------------------------
inline
outcome<boolean>
internal_format_queries::
is_internal_format_preferred(
	internal_format_target target,
	pixel_data_internal_format iformat
) noexcept {
	return return_internal_format_i<boolean, GLboolean>(
		target, iformat,
		internal_format_parameter(GL_INTERNALFORMAT_PREFERRED)
	);
}
//------------------------------------------------------------------------------
inline
outcome<boolean>
internal_format_queries::
is_internal_format_compressed(
	internal_format_target target,
	pixel_data_internal_format iformat
) noexcept {
	return return_internal_format_i<boolean, GLboolean>(
		target, iformat,
		internal_format_parameter(GL_TEXTURE_COMPRESSED)
	);
}
//------------------------------------------------------------------------------
inline
outcome<boolean>
internal_format_queries::
has_internal_format_color_components(
	internal_format_target target,
	pixel_data_internal_format iformat
) noexcept {
	return return_internal_format_i<boolean, GLboolean>(
		target, iformat,
		internal_format_parameter(GL_COLOR_COMPONENTS)
	);
}
//------------------------------------------------------------------------------
inline
outcome<boolean>
internal_format_queries::
has_internal_format_depth_components(
	internal_format_target target,
	pixel_data_internal_format iformat
) noexcept {
	return return_internal_format_i<boolean, GLboolean>(
		target, iformat,
		internal_format_parameter(GL_DEPTH_COMPONENTS)
	);
}
//------------------------------------------------------------------------------
inline
outcome<boolean>
internal_format_queries::
has_internal_format_stencil_components(
	internal_format_target target,
	pixel_data_internal_format iformat
) noexcept {
	return return_internal_format_i<boolean, GLboolean>(
		target, iformat,
		internal_format_parameter(GL_STENCIL_COMPONENTS)
	);
}
//------------------------------------------------------------------------------
inline
outcome<boolean>
internal_format_queries::
supports_internal_format_framebuffer_blend(
	internal_format_target target,
	pixel_data_internal_format iformat
) noexcept {
	return return_internal_format_i<boolean, GLboolean>(
		target, iformat,
		internal_format_parameter(GL_FRAMEBUFFER_BLEND)
	);
}
//------------------------------------------------------------------------------
inline
outcome<boolean>
internal_format_queries::
supports_internal_format_mipmap(
	internal_format_target target,
	pixel_data_internal_format iformat
) noexcept {
	return return_internal_format_i<boolean, GLboolean>(
		target, iformat,
		internal_format_parameter(GL_MIPMAP)
	);
}
//------------------------------------------------------------------------------
inline
outcome<boolean>
internal_format_queries::
supports_internal_format_filter(
	internal_format_target target,
	pixel_data_internal_format iformat
) noexcept {
	return return_internal_format_i<boolean, GLboolean>(
		target, iformat,
		internal_format_parameter(GL_FILTER)
	);
}
#endif
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
} // namespace oglplus
