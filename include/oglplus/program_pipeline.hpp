/**
 *  @file oglplus/program_pipeline.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_PROGRAM_PIPELINE_1509260923_HPP
#define OGLPLUS_PROGRAM_PIPELINE_1509260923_HPP

#include "program_pipeline_name.hpp"
#include "program_name.hpp"
#include "object/owner.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "utils/gl_func.hpp"
#include "utils/boolean.hpp"

namespace oglplus {
namespace oper {

struct program_pipeline_ops
{
	static
	outcome<void>
	bind_program_pipeline(program_pipeline_name ppo)
	noexcept;

	static
	outcome<program_pipeline_name>
	program_pipeline_binding(void)
	noexcept;

	static
	outcome<void>
	get_program_pipeline_iv(
		program_pipeline_name buf,
		program_pipeline_parameter param,
		array_view<GLint> values
	) noexcept;

	template <typename R, typename T>
	static
	outcome<R>
	return_program_pipeline_i(
		program_pipeline_name ppl,
		program_pipeline_parameter parameter
	) noexcept;

	static
	outcome<program_name>
	program_pipeline_active_program(program_pipeline_name ppl)
	noexcept;

	static
	outcome<GLsizei>
	program_pipeline_info_log_length(program_pipeline_name ppl)
	noexcept;
};

} // namespace oper

// obj_dsa_ops
template <>
struct obj_dsa_ops<program_pipeline_name>
 : obj_zero_dsa_ops<program_pipeline_name>
{
	typedef oper::program_pipeline_ops _ops;

	outcome<program_name>
	active_program(void) const
	noexcept
	{
		return _ops::program_pipeline_active_program(*this);
	}

	outcome<GLsizei>
	info_log_length(void) const
	noexcept
	{
		return _ops::program_pipeline_info_log_length(*this);
	}
};

template <>
struct obj_gen_del_ops<tag::program_pipeline>
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

using program_pipeline = object_owner<tag::program_pipeline>;

static const object_zero_and_ops<tag::program_pipeline>
	no_program_pipeline = {};

} // namespace oglplus

#include <oglplus/program_pipeline.inl>

#endif // include guard
