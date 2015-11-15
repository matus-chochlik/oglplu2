/**
 *  @file oglplus/oper/buffer_clearing.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_BUFFER_CLEARING_1509260923_HPP
#define OGLPLUS_OPER_BUFFER_CLEARING_1509260923_HPP

#include "../utils/gl_func.hpp"
#include "../utils/vec_mat_traits.hpp"
#include "../utils/array_view.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../enum/types.hpp"

namespace oglplus {
namespace oper {

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
		return _v[3];
	}
};

struct buffer_clearing_state
{
	static
	outcome<void>
	clear_color(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
	noexcept
	{
		OGLPLUS_GLFUNC(ClearColor)(r,g,b,a);
		OGLPLUS_VERIFY_SIMPLE(ClearColor,always);
		return {};
	}

	template <
		typename V,
		typename = typename std::enable_if<
			has_canonical_type<V, GLfloat[4]>::value
		>::type
	>
	static
	outcome<void>
	clear_color(const V& cc)
	noexcept
	{
		auto ccv = element_view(cc);
		return clear_color(ccv[0],ccv[1],ccv[2],ccv[3]);
	}

	static
	outcome<void>
	clear_depth(GLfloat d)
	noexcept
	{
		OGLPLUS_GLFUNC(ClearDepthf)(d);
		OGLPLUS_VERIFY_SIMPLE(ClearDepthf,always);
		return {};
	}

	static
	outcome<void>
	clear_stencil(GLint s)
	noexcept
	{
		OGLPLUS_GLFUNC(ClearStencil)(s);
		OGLPLUS_VERIFY_SIMPLE(ClearStencil,always);
		return {};
	}

	static
	outcome<rgba_value>
	color_clear_value(void)
	noexcept
	{
		rgba_value result;
		OGLPLUS_GLFUNC(GetFloatv)(GL_COLOR_CLEAR_VALUE, result._v);
		OGLPLUS_VERIFY_SIMPLE(GetFloatv,debug);
		return {result};
	}

	static
	outcome<GLfloat>
	depth_clear_value(void)
	noexcept
	{
		GLfloat result;
		OGLPLUS_GLFUNC(GetFloatv)(GL_DEPTH_CLEAR_VALUE, &result);
		OGLPLUS_VERIFY_SIMPLE(GetFloatv,debug);
		return {result};
	}

	static
	outcome<GLint>
	stencil_clear_value(void)
	noexcept
	{
		GLint result;
		OGLPLUS_GLFUNC(GetIntegerv)(GL_STENCIL_CLEAR_VALUE, &result);
		OGLPLUS_VERIFY_SIMPLE(GetIntegerv,debug);
		return {result};
	}
};

struct buffer_clearing_ops
{
	static
	outcome<void>
	clear(enum_bitfield<buffer_select_bits> bits)
	noexcept
	{
		OGLPLUS_GLFUNC(Clear)(GLbitfield(bits));
		OGLPLUS_VERIFY_SIMPLE(Clear,debug);
		return {};
	}
};

} // namespace oper
} // namespace oglplus

#endif // include guard
