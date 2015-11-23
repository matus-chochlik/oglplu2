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
	noexcept;

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
		span<GLint> values
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
		span<GLfloat> values
	) noexcept;

	template <typename R, typename T>
	static
	outcome<R>
	return_sampler_parameter_i(
		sampler_name sam,
		sampler_parameter parameter
	) noexcept;

	template <typename R>
	static
	outcome<R>
	return_sampler_parameter_f(
		sampler_name sam,
		sampler_parameter parameter
	) noexcept;

	static
	outcome<void>
	sampler_min_filter(sampler_name sam, texture_min_filter value)
	noexcept;

	static
	outcome<texture_min_filter>
	sampler_min_filter(sampler_name sam)
	noexcept;

	static
	outcome<void>
	sampler_mag_filter(sampler_name sam, texture_mag_filter value)
	noexcept;

	static
	outcome<texture_mag_filter>
	sampler_mag_filter(sampler_name sam)
	noexcept;

	static
	outcome<void>
	sampler_compare_mode(sampler_name sam, texture_compare_mode value)
	noexcept;

	static
	outcome<texture_compare_mode>
	sampler_compare_mode(sampler_name sam)
	noexcept;

	static
	outcome<void>
	sampler_compare_func(sampler_name sam, compare_function value)
	noexcept;

	static
	outcome<compare_function>
	sampler_compare_func(sampler_name sam)
	noexcept;

	static
	outcome<void>
	sampler_wrap(
		sampler_name sam,
		texture_wrap_coord coord,
		texture_wrap_mode value
	) noexcept;

	static
	outcome<texture_wrap_mode>
	sampler_wrap(sampler_name sam, texture_wrap_coord coord)
	noexcept;

	static
	outcome<void>
	sampler_wrap_s(sampler_name sam, texture_wrap_mode value)
	noexcept;

	static
	outcome<texture_wrap_mode>
	sampler_wrap_s(sampler_name sam)
	noexcept;

	static
	outcome<void>
	sampler_wrap_t(sampler_name sam, texture_wrap_mode value)
	noexcept;

	static
	outcome<texture_wrap_mode>
	sampler_wrap_t(sampler_name sam)
	noexcept;

	static
	outcome<void>
	sampler_wrap_r(sampler_name sam, texture_wrap_mode value)
	noexcept;

	static
	outcome<texture_wrap_mode>
	sampler_wrap_r(sampler_name sam)
	noexcept;

	static
	outcome<void>
	sampler_lod_bias(sampler_name sam, GLfloat value)
	noexcept;

	static
	outcome<GLfloat>
	sampler_lod_bias(sampler_name sam)
	noexcept;

	static
	outcome<void>
	sampler_min_lod(sampler_name sam, GLfloat value)
	noexcept;

	static
	outcome<GLfloat>
	sampler_min_lod(sampler_name sam)
	noexcept;

	static
	outcome<void>
	sampler_max_lod(sampler_name sam, GLfloat value)
	noexcept;

	static
	outcome<GLfloat>
	sampler_max_lod(sampler_name sam)
	noexcept;
};

} // namespace oper

template <>
struct obj_dsa_ops<tag::sampler>
 : obj_zero_dsa_ops<tag::sampler>
{
	typedef oper::sampler_ops _ops;

	using obj_zero_dsa_ops<tag::sampler>::obj_zero_dsa_ops;

	outcome<obj_dsa_ops&>
	min_filter(texture_min_filter value)
	noexcept
	{
		return {_ops::sampler_min_filter(*this, value), *this};
	}

	outcome<texture_min_filter>
	min_filter(void) const
	noexcept
	{
		return _ops::sampler_min_filter(*this);
	}

	outcome<obj_dsa_ops&>
	mag_filter(texture_mag_filter value)
	noexcept
	{
		return {_ops::sampler_mag_filter(*this, value), *this};
	}

	outcome<texture_mag_filter>
	mag_filter(void) const
	noexcept
	{
		return _ops::sampler_mag_filter(*this);
	}

	outcome<obj_dsa_ops&>
	compare_mode(texture_compare_mode value)
	noexcept
	{
		return {_ops::sampler_compare_mode(*this, value), *this};
	}

	outcome<texture_compare_mode>
	compare_mode(void) const
	noexcept
	{
		return _ops::sampler_compare_mode(*this);
	}

	outcome<obj_dsa_ops&>
	compare_func(compare_function value)
	noexcept
	{
		return {_ops::sampler_compare_func(*this, value), *this};
	}

	outcome<compare_function>
	compare_func(void) const
	noexcept
	{
		return _ops::sampler_compare_func(*this);
	}

	outcome<obj_dsa_ops&>
	wrap(texture_wrap_coord coord, texture_wrap_mode value)
	noexcept
	{
		return {_ops::sampler_wrap(*this, coord, value), *this};
	}

	outcome<texture_wrap_mode>
	wrap(texture_wrap_coord coord) const
	noexcept
	{
		return _ops::sampler_wrap(*this, coord);
	}

	outcome<obj_dsa_ops&>
	wrap_s(texture_wrap_mode value)
	noexcept
	{
		return {_ops::sampler_wrap_s(*this, value), *this};
	}

	outcome<texture_wrap_mode>
	wrap_s(void) const
	noexcept
	{
		return _ops::sampler_wrap_s(*this);
	}

	outcome<obj_dsa_ops&>
	wrap_t(texture_wrap_mode value)
	noexcept
	{
		return {_ops::sampler_wrap_t(*this, value), *this};
	}

	outcome<texture_wrap_mode>
	wrap_t(void) const
	noexcept
	{
		return _ops::sampler_wrap_t(*this);
	}

	outcome<obj_dsa_ops&>
	wrap_r(texture_wrap_mode value)
	noexcept
	{
		return {_ops::sampler_wrap_r(*this, value), *this};
	}

	outcome<texture_wrap_mode>
	wrap_r(void) const
	noexcept
	{
		return _ops::sampler_wrap_r(*this);
	}

	outcome<obj_dsa_ops&>
	lod_bias(GLfloat value)
	noexcept
	{
		return {_ops::sampler_lod_bias(*this, value), *this};
	}

	outcome<GLfloat>
	lod_bias(void) const
	noexcept
	{
		return _ops::sampler_lod_bias(*this);
	}

	outcome<obj_dsa_ops&>
	min_lod(GLfloat value)
	noexcept
	{
		return {_ops::sampler_min_lod(*this, value), *this};
	}

	outcome<GLfloat>
	min_lod(void) const
	noexcept
	{
		return _ops::sampler_min_lod(*this);
	}

	outcome<obj_dsa_ops&>
	max_lod(GLfloat value)
	noexcept
	{
		return {_ops::sampler_max_lod(*this, value), *this};
	}

	outcome<GLfloat>
	max_lod(void) const
	noexcept
	{
		return _ops::sampler_max_lod(*this);
	}
};

template <>
struct obj_gen_del_ops<tag::sampler>
{
	static
	deferred_error_handler
	_gen(span<GLuint> names)
	noexcept;

	static
	deferred_error_handler
	_delete(span<GLuint> names)
	noexcept;

	static
	outcome<boolean> _is_a(GLuint name)
	noexcept;
};

using sampler = object_owner<tag::sampler>;
template <std::size_t N>
using sampler_array = object_array_owner<tag::sampler, N>;

static const object_zero_and_ops<tag::sampler>
	no_sampler = {};

} // namespace oglplus

#include <oglplus/sampler.inl>

#endif // include guard
