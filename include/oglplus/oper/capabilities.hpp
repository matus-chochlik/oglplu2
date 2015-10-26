/**
 *  @file oglplus/oper/capabilities.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_CAPABILITIES_1509260923_HPP
#define OGLPLUS_OPER_CAPABILITIES_1509260923_HPP

#include "../utils/gl_func.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../enum/types.hpp"
#include "../enum/indexed_types.hpp"
#include "numeric_queries.hpp"

namespace oglplus {
namespace oper {

struct capability_state
{
	static
	outcome<void>
	enable(capability cap)
	noexcept
	{
		OGLPLUS_GLFUNC(Enable)(GLenum(cap));
		OGLPLUS_VERIFY(Enable, gl_enum_value(cap), debug);
		return {};
	}

	static
	outcome<void>
	disable(capability cap)
	noexcept
	{
		OGLPLUS_GLFUNC(Disable)(GLenum(cap));
		OGLPLUS_VERIFY(Disable, gl_enum_value(cap), debug);
		return {};
	}

	static
	outcome<bool>
	is_enabled(capability cap)
	noexcept
	{
		GLboolean result = OGLPLUS_GLFUNC(IsEnabled)(GLenum(cap));
		OGLPLUS_VERIFY(IsEnabled, gl_enum_value(cap), always);
		return {result == GL_TRUE};
	}

	static
	outcome<void>
	enable(clip_plane cap)
	noexcept
	{
		OGLPLUS_GLFUNC(Enable)(GLenum(cap));
		OGLPLUS_VERIFY(Enable, gl_enum_value(cap), debug);
		return {};
	}

	static
	outcome<void>
	disable(clip_plane cap)
	noexcept
	{
		OGLPLUS_GLFUNC(Disable)(GLenum(cap));
		OGLPLUS_VERIFY(Disable, gl_enum_value(cap), debug);
		return {};
	}

	static
	outcome<bool>
	is_enabled(clip_plane cap)
	noexcept
	{
		GLboolean result = OGLPLUS_GLFUNC(IsEnabled)(GLenum(cap));
		OGLPLUS_VERIFY(IsEnabled, gl_enum_value(cap), always);
		return {result == GL_TRUE};
	}

	static
	outcome<GLint>
	red_bits(void)
	noexcept
	{
		return numeric_queries::get_integer(
			numeric_query(GL_RED_BITS)
		);
	}

	static
	outcome<GLint>
	green_bits(void)
	noexcept
	{
		return numeric_queries::get_integer(
			numeric_query(GL_GREEN_BITS)
		);
	}

	static
	outcome<GLint>
	blue_bits(void)
	noexcept
	{
		return numeric_queries::get_integer(
			numeric_query(GL_BLUE_BITS)
		);
	}

	static
	outcome<GLint>
	alpha_bits(void)
	noexcept
	{
		return numeric_queries::get_integer(
			numeric_query(GL_ALPHA_BITS)
		);
	}

	static
	outcome<GLint>
	depth_bits(void)
	noexcept
	{
		return numeric_queries::get_integer(
			numeric_query(GL_DEPTH_BITS)
		);
	}

	static
	outcome<GLint>
	stencil_bits(void)
	noexcept
	{
		return numeric_queries::get_integer(
			numeric_query(GL_STENCIL_BITS)
		);
	}

	static
	outcome<bool>
	doublebuffer(void)
	noexcept
	{
		return numeric_queries::get_boolean(
			numeric_query(GL_DOUBLEBUFFER)
		);
	}

	static
	outcome<bool>
	stereo(void)
	noexcept
	{
		return numeric_queries::get_boolean(
			numeric_query(GL_STEREO)
		);
	}

};

} // namespace oper
} // namespace oglplus

#endif // include guard
