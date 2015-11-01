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

#include "object/gl_name.hpp"
#include "object/owner.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "utils/gl_func.hpp"
#include "utils/boolean.hpp"

#ifndef GL_PROGRAM_PIPELINE
#define GL_PROGRAM_PIPELINE 0x82E4
#endif

namespace oglplus {
namespace tag {

using program_pipeline = gl_obj_tag<GL_PROGRAM_PIPELINE>;

} // namespace tag

using program_pipeline_name = object_name<tag::program_pipeline>;

namespace oper {

struct program_pipeline_ops
{
	static
	outcome<void>
	bind_program_pipeline(program_pipeline_name ppo)
	noexcept
	{
		OGLPLUS_GLFUNC(BindProgramPipeline)(get_raw_name(ppo));
		OGLPLUS_VERIFY(BindProgramPipeline, gl_object(ppo), debug);
		return {};
	}

	static
	outcome<program_pipeline_name>
	program_pipeline_binding(void)
	noexcept;
};

} // namespace oper

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
