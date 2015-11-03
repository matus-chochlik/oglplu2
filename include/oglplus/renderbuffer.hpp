/**
 *  @file oglplus/renderbuffer.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_RENDERBUFFER_1509260923_HPP
#define OGLPLUS_RENDERBUFFER_1509260923_HPP

#include "renderbuffer_name.hpp"
#include "object/owner.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "utils/gl_func.hpp"
#include "utils/boolean.hpp"

namespace oglplus {

binding_query
get_binding_query(renderbuffer_target tgt)
noexcept;

namespace oper {

struct renderbuffer_ops
{
	static
	outcome<void>
	bind_renderbuffer(renderbuffer_target target, renderbuffer_name rbo)
	noexcept
	{
		OGLPLUS_GLFUNC(BindRenderbuffer)(
			GLenum(target),
			get_raw_name(rbo)
		);
		OGLPLUS_VERIFY(
			BindRenderbuffer,
			gl_enum_value(target).
			gl_object(rbo),
			debug
		);
		return {};
	}

	static
	outcome<renderbuffer_name>
	renderbuffer_binding(renderbuffer_target target)
	noexcept;

	static
	outcome<void>
	renderbuffer_storage(
		renderbuffer_target tgt,
		pixel_data_internal_format ifmt,
		GLsizei width,
		GLsizei height
	) noexcept;

#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
	static
	outcome<void>
	renderbuffer_storage(
		renderbuffer_name rbo,
		pixel_data_internal_format ifmt,
		GLsizei width,
		GLsizei height
	) noexcept;
#endif
	static
	outcome<void>
	renderbuffer_storage_multisample(
		renderbuffer_target tgt,
		GLsizei samples,
		pixel_data_internal_format ifmt,
		GLsizei width,
		GLsizei height
	) noexcept;

#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
	static
	outcome<void>
	renderbuffer_storage_multisample(
		renderbuffer_name rbo,
		GLsizei samples,
		pixel_data_internal_format ifmt,
		GLsizei width,
		GLsizei height
	) noexcept;
#endif

	static
	outcome<void>
	get_renderbuffer_parameter_iv(
		renderbuffer_target tgt,
		oglplus::renderbuffer_parameter param,
		array_view<GLint> values
	) noexcept;

#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
	static
	outcome<void>
	get_renderbuffer_parameter_iv(
		renderbuffer_name buf,
		oglplus::renderbuffer_parameter param,
		array_view<GLint> values
	) noexcept;
#endif

	template <typename R, typename T, typename RNT>
	static
	outcome<R>
	return_renderbuffer_parameter_i(
		RNT rnt,
		oglplus::renderbuffer_parameter parameter
	) noexcept
	{
		GLint result;
		return get_renderbuffer_parameter_iv(
			rnt,
			parameter,
			{&result, 1}
		), R(T(result));
	}

	template <typename RNT>
	static 
	outcome<GLsizei>
	renderbuffer_width(RNT rnt)
	noexcept
	{
		return return_renderbuffer_parameter_i<GLsizei, GLsizei>(
			rnt, 
			renderbuffer_parameter(GL_RENDERBUFFER_WIDTH)
		);
	}

	template <typename RNT>
	static 
	outcome<GLsizei>
	renderbuffer_height(RNT rnt)
	noexcept
	{
		return return_renderbuffer_parameter_i<GLsizei, GLsizei>(
			rnt, 
			renderbuffer_parameter(GL_RENDERBUFFER_HEIGHT)
		);
	}

	template <typename RNT>
	static 
	outcome<GLsizei>
	renderbuffer_red_size(RNT rnt)
	noexcept
	{
		return return_renderbuffer_parameter_i<GLsizei, GLsizei>(
			rnt, 
			renderbuffer_parameter(GL_RENDERBUFFER_RED_SIZE)
		);
	}

	template <typename RNT>
	static 
	outcome<GLsizei>
	renderbuffer_green_size(RNT rnt)
	noexcept
	{
		return return_renderbuffer_parameter_i<GLsizei, GLsizei>(
			rnt, 
			renderbuffer_parameter(GL_RENDERBUFFER_GREEN_SIZE)
		);
	}

	template <typename RNT>
	static 
	outcome<GLsizei>
	renderbuffer_blue_size(RNT rnt)
	noexcept
	{
		return return_renderbuffer_parameter_i<GLsizei, GLsizei>(
			rnt, 
			renderbuffer_parameter(GL_RENDERBUFFER_BLUE_SIZE)
		);
	}

	template <typename RNT>
	static 
	outcome<GLsizei>
	renderbuffer_alpha_size(RNT rnt)
	noexcept
	{
		return return_renderbuffer_parameter_i<GLsizei, GLsizei>(
			rnt, 
			renderbuffer_parameter(GL_RENDERBUFFER_ALPHA_SIZE)
		);
	}

	template <typename RNT>
	static 
	outcome<GLsizei>
	renderbuffer_depth_size(RNT rnt)
	noexcept
	{
		return return_renderbuffer_parameter_i<GLsizei, GLsizei>(
			rnt, 
			renderbuffer_parameter(GL_RENDERBUFFER_DEPTH_SIZE)
		);
	}

	template <typename RNT>
	static 
	outcome<GLsizei>
	renderbuffer_stencil_size(RNT rnt)
	noexcept
	{
		return return_renderbuffer_parameter_i<GLsizei, GLsizei>(
			rnt, 
			renderbuffer_parameter(GL_RENDERBUFFER_STENCIL_SIZE)
		);
	}

	template <typename RNT>
	static 
	outcome<GLsizei>
	renderbuffer_samples(RNT rnt)
	noexcept
	{
		return return_renderbuffer_parameter_i<GLsizei, GLsizei>(
			rnt, 
			renderbuffer_parameter(GL_RENDERBUFFER_SAMPLES)
		);
	}

	template <typename RNT>
	static 
	outcome<pixel_data_internal_format>
	renderbuffer_internal_format(RNT rnt)
	noexcept
	{
		return return_renderbuffer_parameter_i<
			pixel_data_internal_format,
			GLenum
		>(
			rnt, 
			renderbuffer_parameter(GL_RENDERBUFFER_INTERNAL_FORMAT)
		);
	}
};

} // namespace oper

#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
template <>
struct obj_dsa_ops<renderbuffer_name>
 : obj_zero_dsa_ops<renderbuffer_name>
{
	using obj_zero_dsa_ops<renderbuffer_name>::obj_zero_dsa_ops;

	outcome<void>
	storage(
		pixel_data_internal_format ifmt,
		GLsizei width,
		GLsizei height
	)
	noexcept
	{
		return oper::renderbuffer_ops::renderbuffer_storage(
			*this,
			ifmt,
			width, height
		);
	}

	outcome<void>
	storage_multisample(
		GLsizei samples,
		pixel_data_internal_format ifmt,
		GLsizei width,
		GLsizei height
	)
	noexcept
	{
		return oper::renderbuffer_ops::renderbuffer_storage_multisample(
			*this,
			samples,
			ifmt,
			width, height
		);
	}

	outcome<GLsizei>
	width(void) const
	noexcept
	{
		return oper::renderbuffer_ops::renderbuffer_width(*this);
	}

	outcome<GLsizei>
	height(void) const
	noexcept
	{
		return oper::renderbuffer_ops::renderbuffer_height(*this);
	}

	outcome<GLsizei>
	red_size(void) const
	noexcept
	{
		return oper::renderbuffer_ops::renderbuffer_red_size(*this);
	}

	outcome<GLsizei>
	green_size(void) const
	noexcept
	{
		return oper::renderbuffer_ops::renderbuffer_green_size(*this);
	}

	outcome<GLsizei>
	blue_size(void) const
	noexcept
	{
		return oper::renderbuffer_ops::renderbuffer_blue_size(*this);
	}

	outcome<GLsizei>
	alpha_size(void) const
	noexcept
	{
		return oper::renderbuffer_ops::renderbuffer_alpha_size(*this);
	}

	outcome<GLsizei>
	depth_size(void) const
	noexcept
	{
		return oper::renderbuffer_ops::renderbuffer_depth_size(*this);
	}

	outcome<GLsizei>
	stencil_size(void) const
	noexcept
	{
		return oper::renderbuffer_ops::renderbuffer_stencil_size(*this);
	}

	outcome<GLsizei>
	samples(void) const
	noexcept
	{
		return oper::renderbuffer_ops::renderbuffer_samples(*this);
	}

	outcome<pixel_data_internal_format>
	internal_format(void) const
	noexcept
	{
		return oper::renderbuffer_ops::renderbuffer_internal_format(
			*this
		);
	}
};
#endif

template <>
struct obj_gen_del_ops<tag::renderbuffer>
{
	static
	deferred_error_handler
	_gen(array_view<GLuint> names)
	noexcept;

	static
	deferred_error_handler
	_delete(array_view<GLuint> names)
	noexcept;

	static
	outcome<boolean> _is_a(GLuint name)
	noexcept;
};

using renderbuffer = object_owner<tag::renderbuffer>;

static const object_zero_and_ops<tag::renderbuffer>
	no_renderbuffer = {};

} // namespace oglplus

#include <oglplus/renderbuffer.inl>

#endif // include guard
