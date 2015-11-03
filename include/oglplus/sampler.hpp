/**
 *  @file oglplus/sampler.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_SAMPLER_1509260923_HPP
#define OGLPLUS_SAMPLER_1509260923_HPP

#include "sampler_name.hpp"
#include "object/owner.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "utils/gl_func.hpp"
#include "utils/boolean.hpp"
#include "enum/indexed_types.hpp"

namespace oglplus {
namespace oper {

struct sampler_ops
{
	static
	outcome<void>
	bind_sampler(texture_unit unit, sampler_name sam)
	noexcept
	{
		OGLPLUS_GLFUNC(BindFramebuffer)(
			GLenum(unit),
			get_raw_name(sam)
		);
		OGLPLUS_VERIFY(
			BindFramebuffer,
			gl_enum_value(unit).
			gl_object(sam),
			debug
		);
		return {};
	}

	static
	outcome<sampler_name>
	sampler_binding(texture_unit unit)
	noexcept;

	static
	outcome<void>
	sampler_parameter_i(
		sampler_name sam,
		sampler_parameter param,
		GLint value
	) noexcept;

	static
	outcome<void>
	get_sampler_parameter_iv(
		sampler_name sam,
		sampler_parameter param,
		array_view<GLint> values
	) noexcept;

	static
	outcome<void>
	sampler_parameter_f(
		sampler_name sam,
		sampler_parameter param,
		GLfloat value
	) noexcept;

	static
	outcome<void>
	get_sampler_parameter_fv(
		sampler_name sam,
		sampler_parameter param,
		array_view<GLfloat> values
	) noexcept;

	template <typename R, typename T>
	static
	outcome<R>
	return_sampler_parameter_i(
		sampler_name sam,
		sampler_parameter parameter
	) noexcept
	{
		GLint result;
		return get_sampler_parameter_iv(
			sam,
			parameter,
			{&result, 1}
		), R(T(result));
	}

	template <typename R>
	static
	outcome<R>
	return_sampler_parameter_f(
		sampler_name sam,
		sampler_parameter parameter
	) noexcept
	{
		GLfloat result;
		return get_sampler_parameter_fv(
			sam,
			parameter,
			{&result, 1}
		), R(result);
	}

	static
	outcome<void>
	sampler_min_filter(sampler_name sam, texture_min_filter value)
	noexcept
	{
		return sampler_parameter_i(
			sam,
			sampler_parameter(GL_TEXTURE_MIN_FILTER),
			GLint(GLenum(value))
		);
	}

	static
	outcome<texture_min_filter>
	sampler_min_filter(sampler_name sam)
	noexcept
	{
		return return_sampler_parameter_i<
			texture_min_filter,
			GLenum
		>(
			sam,
			sampler_parameter(GL_TEXTURE_MIN_FILTER)
		);
	}

	static
	outcome<void>
	sampler_mag_filter(sampler_name sam, texture_mag_filter value)
	noexcept
	{
		return sampler_parameter_i(
			sam,
			sampler_parameter(GL_TEXTURE_MAG_FILTER),
			GLint(GLenum(value))
		);
	}

	static
	outcome<texture_mag_filter>
	sampler_mag_filter(sampler_name sam)
	noexcept
	{
		return return_sampler_parameter_i<
			texture_mag_filter,
			GLenum
		>(
			sam,
			sampler_parameter(GL_TEXTURE_MAG_FILTER)
		);
	}

	static
	outcome<void>
	sampler_compare_mode(sampler_name sam, texture_compare_mode value)
	noexcept
	{
		return sampler_parameter_i(
			sam,
			sampler_parameter(GL_TEXTURE_COMPARE_MODE),
			GLint(GLenum(value))
		);
	}

	static
	outcome<texture_compare_mode>
	sampler_compare_mode(sampler_name sam)
	noexcept
	{
		return return_sampler_parameter_i<
			texture_compare_mode,
			GLenum
		>(
			sam,
			sampler_parameter(GL_TEXTURE_COMPARE_MODE)
		);
	}

	static
	outcome<void>
	sampler_compare_func(sampler_name sam, compare_function value)
	noexcept
	{
		return sampler_parameter_i(
			sam,
			sampler_parameter(GL_TEXTURE_COMPARE_FUNC),
			GLint(GLenum(value))
		);
	}

	static
	outcome<compare_function>
	sampler_compare_func(sampler_name sam)
	noexcept
	{
		return return_sampler_parameter_i<
			compare_function,
			GLenum
		>(
			sam,
			sampler_parameter(GL_TEXTURE_COMPARE_FUNC)
		);
	}

	static
	outcome<void>
	sampler_wrap(
		sampler_name sam,
		texture_wrap_coord coord,
		texture_wrap value
	) noexcept
	{
		return sampler_parameter_i(
			sam,
			sampler_parameter(GLenum(coord)),
			GLint(GLenum(value))
		);
	}

	static
	outcome<texture_wrap>
	sampler_wrap(sampler_name sam, texture_wrap_coord coord)
	noexcept
	{
		return return_sampler_parameter_i<
			texture_wrap,
			GLenum
		>(sam, sampler_parameter(GLenum(coord)));
	}

	static
	outcome<void>
	sampler_wrap_s(sampler_name sam, texture_wrap value)
	noexcept
	{
		return sampler_parameter_i(
			sam,
			sampler_parameter(GL_TEXTURE_WRAP_S),
			GLint(GLenum(value))
		);
	}

	static
	outcome<texture_wrap>
	sampler_wrap_s(sampler_name sam)
	noexcept
	{
		return return_sampler_parameter_i<texture_wrap, GLenum>(
			sam,
			sampler_parameter(GL_TEXTURE_WRAP_S)
		);
	}

	static
	outcome<void>
	sampler_wrap_t(sampler_name sam, texture_wrap value)
	noexcept
	{
		return sampler_parameter_i(
			sam,
			sampler_parameter(GL_TEXTURE_WRAP_T),
			GLint(GLenum(value))
		);
	}

	static
	outcome<texture_wrap>
	sampler_wrap_t(sampler_name sam)
	noexcept
	{
		return return_sampler_parameter_i<texture_wrap, GLenum>(
			sam,
			sampler_parameter(GL_TEXTURE_WRAP_T)
		);
	}

	static
	outcome<void>
	sampler_wrap_r(sampler_name sam, texture_wrap value)
	noexcept
	{
		return sampler_parameter_i(
			sam,
			sampler_parameter(GL_TEXTURE_WRAP_R),
			GLint(GLenum(value))
		);
	}

	static
	outcome<texture_wrap>
	sampler_wrap_r(sampler_name sam)
	noexcept
	{
		return return_sampler_parameter_i<texture_wrap, GLenum>(
			sam,
			sampler_parameter(GL_TEXTURE_WRAP_R)
		);
	}

	static
	outcome<void>
	sampler_min_lod(sampler_name sam, GLfloat value)
	noexcept
	{
		return sampler_parameter_f(
			sam,
			sampler_parameter(GL_TEXTURE_MIN_LOD),
			value
		);
	}

	static
	outcome<GLfloat>
	sampler_min_lod(sampler_name sam)
	noexcept
	{
		return return_sampler_parameter_f<GLfloat>(
			sam,
			sampler_parameter(GL_TEXTURE_MIN_LOD)
		);
	}

	static
	outcome<void>
	sampler_max_lod(sampler_name sam, GLfloat value)
	noexcept
	{
		return sampler_parameter_f(
			sam,
			sampler_parameter(GL_TEXTURE_MAX_LOD),
			value
		);
	}

	static
	outcome<GLfloat>
	sampler_max_lod(sampler_name sam)
	noexcept
	{
		return return_sampler_parameter_f<GLfloat>(
			sam,
			sampler_parameter(GL_TEXTURE_MAX_LOD)
		);
	}
};

} // namespace oper

template <>
struct obj_dsa_ops<sampler_name>
 : obj_zero_dsa_ops<sampler_name>
{
	using obj_zero_dsa_ops<sampler_name>::obj_zero_dsa_ops;

	outcome<void>
	min_filter(texture_min_filter value)
	noexcept
	{
		return oper::sampler_ops::sampler_min_filter(*this, value);
	}

	outcome<texture_min_filter>
	min_filter(void) const
	noexcept
	{
		return oper::sampler_ops::sampler_min_filter(*this);
	}

	outcome<void>
	mag_filter(texture_mag_filter value)
	noexcept
	{
		return oper::sampler_ops::sampler_mag_filter(*this, value);
	}

	outcome<texture_mag_filter>
	mag_filter(void) const
	noexcept
	{
		return oper::sampler_ops::sampler_mag_filter(*this);
	}

	outcome<void>
	compare_mode(texture_compare_mode value)
	noexcept
	{
		return oper::sampler_ops::sampler_compare_mode(*this, value);
	}

	outcome<texture_compare_mode>
	compare_mode(void) const
	noexcept
	{
		return oper::sampler_ops::sampler_compare_mode(*this);
	}

	outcome<void>
	compare_func(compare_function value)
	noexcept
	{
		return oper::sampler_ops::sampler_compare_func(*this, value);
	}

	outcome<compare_function>
	compare_func(void) const
	noexcept
	{
		return oper::sampler_ops::sampler_compare_func(*this);
	}

	outcome<void>
	wrap(texture_wrap_coord coord, texture_wrap value)
	noexcept
	{
		return oper::sampler_ops::sampler_wrap(*this, coord, value);
	}

	outcome<texture_wrap>
	wrap(texture_wrap_coord coord) const
	noexcept
	{
		return oper::sampler_ops::sampler_wrap(*this, coord);
	}

	outcome<void>
	wrap_s(texture_wrap value)
	noexcept
	{
		return oper::sampler_ops::sampler_wrap_s(*this, value);
	}

	outcome<texture_wrap>
	wrap_s(void) const
	noexcept
	{
		return oper::sampler_ops::sampler_wrap_s(*this);
	}

	outcome<void>
	wrap_t(texture_wrap value)
	noexcept
	{
		return oper::sampler_ops::sampler_wrap_t(*this, value);
	}

	outcome<texture_wrap>
	wrap_t(void) const
	noexcept
	{
		return oper::sampler_ops::sampler_wrap_t(*this);
	}

	outcome<void>
	wrap_r(texture_wrap value)
	noexcept
	{
		return oper::sampler_ops::sampler_wrap_r(*this, value);
	}

	outcome<texture_wrap>
	wrap_r(void) const
	noexcept
	{
		return oper::sampler_ops::sampler_wrap_r(*this);
	}

	outcome<void>
	min_lod(GLfloat value)
	noexcept
	{
		return oper::sampler_ops::sampler_min_lod(*this, value);
	}

	outcome<GLfloat>
	min_lod(void) const
	noexcept
	{
		return oper::sampler_ops::sampler_min_lod(*this);
	}

	outcome<void>
	max_lod(GLfloat value)
	noexcept
	{
		return oper::sampler_ops::sampler_max_lod(*this, value);
	}

	outcome<GLfloat>
	max_lod(void) const
	noexcept
	{
		return oper::sampler_ops::sampler_max_lod(*this);
	}
};

template <>
struct obj_gen_del_ops<tag::sampler>
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

using sampler = object_owner<tag::sampler>;

static const object_zero_and_ops<tag::sampler>
	no_sampler = {};

} // namespace oglplus

#include <oglplus/sampler.inl>

#endif // include guard
