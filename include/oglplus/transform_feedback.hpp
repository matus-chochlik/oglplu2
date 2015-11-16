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
	) noexcept
	{
		OGLPLUS_GLFUNC(BindTransformFeedback)(
			GLenum(target),
			get_raw_name(xfb)
		);
		OGLPLUS_VERIFY(
			BindTransformFeedback,
			gl_enum_value(target).
			gl_object(xfb),
			debug
		);
		return {};
	}

	static
	outcome<transform_feedback_name>
	transform_feedback_binding(transform_feedback_target target)
	noexcept;
};

} // namespace oper

template <>
struct obj_gen_del_ops<tag::transform_feedback>
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

using transform_feedback = object_owner<tag::transform_feedback>;
template <std::size_t N>
using transform_feedback_array = object_array_owner<tag::transform_feedback, N>;

static const object_zero_and_ops<tag::transform_feedback>
	default_transform_feedback = {};

} // namespace oglplus

#include <oglplus/transform_feedback.inl>

#endif // include guard
