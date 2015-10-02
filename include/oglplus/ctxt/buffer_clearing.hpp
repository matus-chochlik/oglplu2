/**
 *  @file oglplus/ctxt/buffer_clearing.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_CTXT_BUFFER_CLEARING_1509260923_HPP
#define OGLPLUS_CTXT_BUFFER_CLEARING_1509260923_HPP

#include "../utils/gl_func.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../enum_types.hpp"

namespace oglplus {
namespace ctxt {

struct rgba_value
{
	GLfloat _v[4];

	GLfloat red(void) const
	noexcept
	{
		return _v[0];
	}

	GLfloat green(void) const
	noexcept
	{
		return _v[1];
	}

	GLfloat blue(void) const
	noexcept
	{
		return _v[2];
	}

	GLfloat alpha(void) const
	noexcept
	{
		return _v[2];
	}
};

struct buffer_clearing
{
	static
	outcome<void>
	clear(enum_bitfield<buffer_select_bits> bits)
	noexcept
	{
		OGLPLUS_GLFUNC(Clear)(GLbitfield(bits));
		OGLPLUS_VERIFY_SIMPLE(Clear,warning);
		return {};
	}

	static
	outcome<void>
	clear_color(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
	noexcept
	{
		OGLPLUS_GLFUNC(ClearColor)(r,g,b,a);
		OGLPLUS_VERIFY_SIMPLE(ClearColor,warning);
		return {};
	}

	static
	outcome<void>
	clear_depth(GLfloat d)
	noexcept
	{
		OGLPLUS_GLFUNC(ClearDepthf)(d);
		OGLPLUS_VERIFY_SIMPLE(ClearDepthf,warning);
		return {};
	}

	static
	outcome<void>
	clear_stencil(GLint s)
	noexcept
	{
		OGLPLUS_GLFUNC(ClearStencil)(s);
		OGLPLUS_VERIFY_SIMPLE(ClearStencil,warning);
		return {};
	}

	static
	outcome<rgba_value>
	color_clear_value(void)
	noexcept
	{
		rgba_value result;
		OGLPLUS_GLFUNC(GetFloatv)(GL_COLOR_CLEAR_VALUE, result._v);
		OGLPLUS_VERIFY_SIMPLE(GetFloatv,warning);
		return {result};
	}

	static
	outcome<GLfloat>
	depth_clear_value(void)
	noexcept
	{
		GLfloat result;
		OGLPLUS_GLFUNC(GetFloatv)(GL_DEPTH_CLEAR_VALUE, &result);
		OGLPLUS_VERIFY_SIMPLE(GetFloatv,warning);
		return {result};
	}

	static
	outcome<GLint>
	stencil_clear_value(void)
	noexcept
	{
		GLfloat result;
		OGLPLUS_GLFUNC(GetIntegerv)(GL_STENCIL_CLEAR_VALUE, &result);
		OGLPLUS_VERIFY_SIMPLE(GetIntegerv,warning);
		return {result};
	}
};

} // namespace ctxt
} // namespace oglplus

#endif // include guard
