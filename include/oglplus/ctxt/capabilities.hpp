/**
 *  @file oglplus/ctxt/capabilities.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_CTXT_CAPABILITIES_1509260923_HPP
#define OGLPLUS_CTXT_CAPABILITIES_1509260923_HPP

#include "../utils/gl_func.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../enum/types.hpp"

namespace oglplus {
namespace ctxt {

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
		OGLPLUS_VERIFY(
			Disable,
			gl_enum_value(cap),
			debug
		);
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
	enable(functionality func, GLuint idx)
	noexcept
	{
		OGLPLUS_GLFUNC(Enable)(GLenum(func)+idx);
		OGLPLUS_VERIFY(
			Enable,
			index(idx).
			gl_enum_value(func),
			debug
		);
		return {};
	}

	static
	outcome<void>
	disable(functionality func, GLuint idx)
	noexcept
	{
		OGLPLUS_GLFUNC(Disable)(GLenum(func)+idx);
		OGLPLUS_VERIFY(
			Disable,
			index(idx).
			gl_enum_value(func),
			debug
		);
		return {};
	}

	static
	outcome<bool>
	is_enabled(functionality func, GLuint idx)
	noexcept
	{
		GLboolean result = OGLPLUS_GLFUNC(IsEnabled)(GLenum(func)+idx);
		OGLPLUS_VERIFY(
			IsEnabled,
			index(idx).
			gl_enum_value(func),
			always
		);
		return {result == GL_TRUE};
	}
};

} // namespace ctxt
} // namespace oglplus

#endif // include guard
