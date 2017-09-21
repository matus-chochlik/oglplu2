/**
 *  @file oglplus/transform_feedback.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TRANSFORM_FEEDBACK_1509260923_HPP
#define OGLPLUS_TRANSFORM_FEEDBACK_1509260923_HPP

#include "transform_feedback_name.hpp"
#include "buffer_name.hpp"
#include "object/owner.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "utils/gl_func.hpp"
#include "utils/boolean.hpp"

namespace oglplus {

binding_query
get_binding_query(transform_feedback_target tgt)
noexcept;

namespace oper {

struct transform_feedback_ops
{
	static
	outcome<void>
	bind_transform_feedback(
		transform_feedback_target target,
		transform_feedback_name xfb
	) noexcept;

	static
	outcome<transform_feedback_name>
	transform_feedback_binding(transform_feedback_target target)
	noexcept;

	static
	outcome<void>
	begin_transform_feedback(transform_feedback_primitive_type)
	noexcept;

	static
	outcome<void>
	end_transform_feedback(void)
	noexcept;

	static
	outcome<void>
	pause_transform_feedback(void)
	noexcept;

	static
	outcome<void>
	resume_transform_feedback(void)
	noexcept;

#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access)
	static
	outcome<void>
	get_transform_feedback_iv(
		transform_feedback_name xfb,
		transform_feedback_parameter param,
		span<GLint> values
	) noexcept;

	static
	outcome<void>
	get_transform_feedback_iv(
		transform_feedback_name xfb,
		transform_feedback_parameter param,
		GLuint index,
		span<GLint> values
	) noexcept;

	static
	outcome<void>
	get_transform_feedback_i64v(
		transform_feedback_name xfb,
		transform_feedback_parameter param,
		GLuint index,
		span<GLint64> values
	) noexcept;

	static
	outcome<boolean>
	transform_feedback_active(transform_feedback_name xfb)
	noexcept;

	static
	outcome<boolean>
	transform_feedback_paused(transform_feedback_name xfb)
	noexcept;

	static
	outcome<buffer_name>
	transform_feedback_buffer_binding(transform_feedback_name xfb)
	noexcept;

	static
	outcome<GLint64>
	transform_feedback_buffer_start(
		transform_feedback_name xfb,
		GLuint index
	) noexcept;

	static
	outcome<GLint64>
	transform_feedback_buffer_size(
		transform_feedback_name xfb,
		GLuint index
	) noexcept;

	static
	outcome<void>
	transform_feedback_buffer_base(
		transform_feedback_name xfb,
		GLuint index,
		buffer_name buf
	) noexcept;

	static
	outcome<void>
	transform_feedback_buffer_range(
		transform_feedback_name xfb,
		GLuint index,
		buffer_name buf,
		GLintptr offset,
		GLsizeiptr size
	) noexcept;
#endif
	// TODO
};

} // namespace oper

template <>
struct obj_zero_dsa_ops<tag::transform_feedback>
 : object_zero_name<tag::transform_feedback>
{
	typedef oper::transform_feedback_ops _ops;

	obj_zero_dsa_ops(void) = default;

	obj_zero_dsa_ops(transform_feedback_name name)
	noexcept
	 : object_zero_name<tag::transform_feedback>(name)
	{ }

	outcome<void>
	begin(transform_feedback_primitive_type mode)
	noexcept
	{
		return _ops::begin_transform_feedback(mode);
	}

	outcome<void>
	end(void)
	noexcept
	{
		return _ops::end_transform_feedback();
	}

	outcome<void>
	pause(void)
	noexcept
	{
		return _ops::pause_transform_feedback();
	}

	outcome<void>
	resume(void)
	noexcept
	{
		return _ops::resume_transform_feedback();
	}
};

// obj_dsa_ops
template <>
struct obj_dsa_ops<tag::transform_feedback>
 : obj_zero_dsa_ops<tag::transform_feedback>
{
	typedef oper::transform_feedback_ops _ops;

	using obj_zero_dsa_ops<tag::transform_feedback>::obj_zero_dsa_ops;

#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access)
	outcome<boolean>
	active(void) const
	noexcept
	{
		return _ops::transform_feedback_active(*this);
	}

	outcome<boolean>
	paused(void) const
	noexcept
	{
		return _ops::transform_feedback_paused(*this);
	}

	outcome<buffer_name>
	buffer_binding(void) const
	noexcept
	{
		return _ops::transform_feedback_buffer_binding(*this);
	}

	outcome<GLint64>
	buffer_start(GLuint index)
	noexcept
	{
		return _ops::transform_feedback_buffer_start(*this, index);
	}

	outcome<GLint64>
	buffer_size(GLuint index)
	noexcept
	{
		return _ops::transform_feedback_buffer_size(*this, index);
	}

	outcome<void>
	buffer_base(GLuint index, buffer_name buf)
	noexcept
	{
		return _ops::transform_feedback_buffer_base(*this, index, buf);
	}

	outcome<void>
	buffer_range(
		GLuint index,
		buffer_name buf,
		GLintptr offset,
		GLsizeiptr size
	) noexcept
	{
		return _ops::transform_feedback_buffer_range(
				*this,
				index,
				buf, offset, size
		);
	}
#endif
};


template <>
struct obj_gen_del_ops<tag::transform_feedback>
{
	static
	deferred_error_handler
	_gen(span<GLuint> names)
	noexcept;

#if defined(GL_VERSION_4_5)
	static
	deferred_error_handler
	_create(span<GLuint> names)
	noexcept;
#endif

	static
	deferred_error_handler
	_delete(span<GLuint> names)
	noexcept;

	static
	outcome<boolean> _is_a(GLuint name)
	noexcept;
};

using transform_feedback = object_owner<tag::transform_feedback>;
template <std::size_t N>
using transform_feedback_array = object_array_owner<tag::transform_feedback, N>;

static const object_zero_and_ops<tag::transform_feedback>
	default_transform_feedback = {};

} // namespace oglplus

#include <oglplus/transform_feedback.inl>

#endif // include guard
