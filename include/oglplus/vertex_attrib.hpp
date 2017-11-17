/**
 *  @file oglplus/vertex_attrib.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_VERTEX_ATTRIB_1509260923_HPP
#define OGLPLUS_VERTEX_ATTRIB_1509260923_HPP

#include "prog_var/location.hpp"
#include "prog_var/wrapper.hpp"
#include "utils/identity.hpp"

namespace oglplus {
namespace tag {

struct vertex_attrib { };

} // namespace tag

using vertex_attrib_location = prog_var_loc<tag::vertex_attrib>;
using program_vertex_attrib_location = dsa_prog_var_loc<tag::vertex_attrib>;

template <typename T>
using vertex_attrib = prog_var_wrapper<vertex_attrib_location, T>;

template <>
struct prog_var_loc_ops<tag::vertex_attrib>
{
	typedef tag::vertex_attrib tag;

	static
	outcome<prog_var_loc<tag>>
	get_location(program_name prog, cstr_ref identifier)
	noexcept
	{
		GLint loc = OGLPLUS_GLFUNC(GetAttribLocation)(
			get_raw_name(prog),
			identifier.c_str()
		);
		OGLPLUS_VERIFY(
			GetAttribLocation,
			identifier(identifier).
			gl_object(prog),
			always
		);

		return {prog_var_loc<tag>{loc}};
	}
};

} // namespace oglplus

#include <oglplus/vertex_attrib_get_set.inl>

#endif // include guard
