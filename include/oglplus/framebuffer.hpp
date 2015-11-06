/**
 *  @file oglplus/framebuffer.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_FRAMEBUFFER_1509260923_HPP
#define OGLPLUS_FRAMEBUFFER_1509260923_HPP

#include "framebuffer_name.hpp"
#include "renderbuffer_name.hpp"
#include "texture_name.hpp"
#include "object/owner.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "enum/combined_types.hpp"
#include "utils/gl_func.hpp"
#include "utils/boolean.hpp"

namespace oglplus {

binding_query
get_binding_query(framebuffer_target tgt)
noexcept;

namespace oper {

struct framebuffer_ops
{
	static
	outcome<void>
	bind_framebuffer(framebuffer_target target, framebuffer_name fbo)
	noexcept;

	static
	outcome<framebuffer_name>
	framebuffer_binding(framebuffer_target target)
	noexcept;

	static
	outcome<framebuffer_status>
	check_framebuffer_status(framebuffer_target target)
	noexcept;

	static
	outcome<bool>
	is_framebuffer_complete(framebuffer_target target)
	noexcept;

#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
	static
	outcome<framebuffer_status>
	check_framebuffer_status(framebuffer_name, framebuffer_target target)
	noexcept;

	static
	outcome<bool>
	is_framebuffer_complete(framebuffer_name fb, framebuffer_target target)
	noexcept;
#endif

	static
	outcome<void>
	framebuffer_renderbuffer(
		framebuffer_target fb_target,
		framebuffer_attachment fb_attch,
		renderbuffer_target rb_target,
		renderbuffer_name rbo
	) noexcept;

#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
	static
	outcome<void>
	framebuffer_renderbuffer(
		framebuffer_name fbo,
		framebuffer_attachment fb_attch,
		renderbuffer_target rb_target,
		renderbuffer_name rbo
	) noexcept;
#endif

	static
	outcome<void>
	framebuffer_texture_2d(
		framebuffer_target fb_target,
		framebuffer_attachment fb_attch,
		texture_target tx_target,
		texture_name tex,
		GLint level
	) noexcept;

#if defined(GL_EXT_direct_state_access)
	static
	outcome<void>
	framebuffer_texture_2d(
		framebuffer_name fbo,
		framebuffer_attachment fb_attch,
		texture_target tx_target,
		texture_name tex,
		GLint level
	) noexcept;
#endif

	static
	outcome<void>
	framebuffer_texture_3d(
		framebuffer_target fb_target,
		framebuffer_attachment fb_attch,
		texture_target tx_target,
		texture_name tex,
		GLint level,
		GLint layer
	) noexcept;

#if defined(GL_EXT_direct_state_access)
	static
	outcome<void>
	framebuffer_texture_3d(
		framebuffer_name fbo,
		framebuffer_attachment fb_attch,
		texture_target tx_target,
		texture_name tex,
		GLint level,
		GLint layer
	) noexcept;
#endif

	static
	outcome<void>
	framebuffer_texture(
		framebuffer_target fb_target,
		framebuffer_attachment fb_attch,
		texture_name tex,
		GLint level
	) noexcept;

#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
	static
	outcome<void>
	framebuffer_texture(
		framebuffer_name fbo,
		framebuffer_attachment fb_attch,
		texture_name tex,
		GLint level
	) noexcept;
#endif

	static
	outcome<void>
	draw_buffer(color_buffer buf)
	noexcept;

#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
	static
	outcome<void>
	framebuffer_draw_buffer(framebuffer_name fbo, color_buffer buf)
	noexcept;
#endif

	static
	outcome<void>
	read_buffer(color_buffer buf)
	noexcept;

#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
	static
	outcome<void>
	framebuffer_read_buffer(framebuffer_name fbo, color_buffer buf)
	noexcept;
#endif
};

} // namespace oper

#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
template <>
struct obj_zero_dsa_ops<framebuffer_name>
 : framebuffer_name
{
	typedef oper::framebuffer_ops _ops;

	obj_zero_dsa_ops(void)
	noexcept
	 : framebuffer_name(0)
	{ }

	outcome<obj_zero_dsa_ops&>
	draw_buffer(color_buffer buf)
	noexcept
	{
		return {_ops::framebuffer_draw_buffer(*this, buf), *this};
	}

	outcome<obj_zero_dsa_ops&>
	read_buffer(color_buffer buf)
	noexcept
	{
		return {_ops::framebuffer_read_buffer(*this, buf), *this};
	}
};

template <>
struct obj_dsa_ops<framebuffer_name>
 : obj_zero_dsa_ops<framebuffer_name>
{
	typedef oper::framebuffer_ops _ops;

	using obj_zero_dsa_ops<framebuffer_name>::obj_zero_dsa_ops;

	outcome<framebuffer_status>
	check_status(framebuffer_target target)
	noexcept
	{
		return _ops::check_framebuffer_status(*this, target);
	}

	outcome<bool>
	is_complete(framebuffer_target target)
	noexcept
	{
		return _ops::is_framebuffer_complete(*this, target);
	}

	outcome<obj_dsa_ops&>
	renderbuffer(
		framebuffer_attachment fb_attch,
		renderbuffer_target rb_target,
		renderbuffer_name rbo
	) noexcept
	{
		return {_ops::framebuffer_renderbuffer(
			*this, fb_attch,
			rb_target, rbo
		), *this};
	}

#if defined(GL_EXT_direct_state_access)
	outcome<obj_dsa_ops&>
	texture_2d(
		framebuffer_attachment fb_attch,
		texture_target tx_target,
		texture_name tex,
		GLint level
	) noexcept
	{
		return {_ops::framebuffer_texture_2d(
			*this, fb_attch, 
			tx_target, tex,
			level
		), *this};
	}

	outcome<obj_dsa_ops&>
	texture_3d(
		framebuffer_attachment fb_attch,
		texture_target tx_target,
		texture_name tex,
		GLint level,
		GLint layer
	) noexcept
	{
		return {_ops::framebuffer_texture_3d(
			*this, fb_attch, 
			tx_target, tex,
			level, layer
		), *this};
	}
#endif

	outcome<obj_dsa_ops&>
	texture(
		framebuffer_attachment fb_attch,
		texture_name tex,
		GLint level
	) noexcept
	{
		return {_ops::framebuffer_texture(
			*this, fb_attch, 
			tex, level
		), *this};
	}
};
#endif

template <>
struct obj_gen_del_ops<tag::framebuffer>
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

using framebuffer = object_owner<tag::framebuffer>;

static const object_zero_and_ops<tag::framebuffer>
	default_framebuffer = {};

} // namespace oglplus

#include <oglplus/framebuffer.inl>

#endif // include guard
