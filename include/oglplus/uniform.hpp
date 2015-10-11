/**
 *  @file oglplus/uniform.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_UNIFORM_1509260923_HPP
#define OGLPLUS_UNIFORM_1509260923_HPP

#include "prog_var/location.hpp"
#include "prog_var/wrapper.hpp"
#include "utils/cstr_ref.hpp"

namespace oglplus {
namespace tag {

struct uniform { };

} // namespace tag

using uniform_location = prog_var_loc<tag::uniform>;

template <typename T>
using uniform = prog_var_wrapper<uniform_location, T>;

template <>
struct prog_var_loc_ops<tag::uniform>
{
	typedef tag::uniform tag;

	static
	outcome<prog_var_loc<tag>>
	get_location(program_name prog, cstr_ref identifier)
	noexcept
	{
		GLint loc = OGLPLUS_GLFUNC(GetUniformLocation)(
			get_raw_name(prog),
			identifier.c_str()
		);
		OGLPLUS_VERIFY(
			GetAttribLocation,
			gl_object(prog), // TODO identifier
			debug
		);

		return {prog_var_loc<tag>{loc}};
	}
};

} // namespace oglplus

#endif // include guard
