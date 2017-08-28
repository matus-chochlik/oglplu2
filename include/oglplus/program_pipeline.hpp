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
#if defined(GL_VERSION_4_1) || defined(GL_ARB_separate_shared_objects)
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
		span<GLint> values
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
	get_program_pipeline_active_program(program_pipeline_name ppl)
	noexcept;

	static
	outcome<GLsizei>
	get_program_pipeline_info_log_length(program_pipeline_name ppl)
	noexcept;
#endif
};

} // namespace oper

// obj_dsa_ops
template <>
struct obj_dsa_ops<tag::program_pipeline>
 : obj_zero_dsa_ops<tag::program_pipeline>
{
	typedef oper::program_pipeline_ops _ops;

#if defined(GL_VERSION_4_1) || defined(GL_ARB_separate_shared_objects)
	outcome<program_name>
	get_active_program(void) const
	noexcept { return _ops::get_program_pipeline_active_program(*this); }

	outcome<GLsizei>
	get_info_log_length(void) const
	noexcept { return _ops::get_program_pipeline_info_log_length(*this); }
#endif
};

#if defined(GL_VERSION_4_1) || defined(GL_ARB_separate_shared_objects)
template <>
struct obj_gen_del_ops<tag::program_pipeline>
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

using program_pipeline = object_owner<tag::program_pipeline>;
template <std::size_t N>
using program_pipeline_array = object_array_owner<tag::program_pipeline, N>;

static const object_zero_and_ops<tag::program_pipeline>
	no_program_pipeline = {};
#endif

} // namespace oglplus

#include <oglplus/program_pipeline.inl>

#endif // include guard
