/**
 *  @file oglplus/texture.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *  https://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXTURE_1509260923_HPP
#define OGLPLUS_TEXTURE_1509260923_HPP

#include "object/gl_name.hpp"
#include "utils/gl_func.hpp"
#include "error/handling.hpp"

namespace oglplus {
namespace tag {

using texture = gl_obj_tag<GL_TEXTURE>;

} // namespace tag

using texture_name = object_name<tag::texture>;

template <>
struct obj_gen_del_ops<tag::texture>
{
	deferred_error_handler
	static
	_gen(std::size_t count, GLuint* names)
	noexcept
	{
		assert(names != nullptr);

		OGLPLUS_GLFUNC(GenTextures)(GLsizei(count), names);
		OGLPLUS_VERIFY_SIMPLE(GenTextures,severe);
		return {};
	}

	deferred_error_handler
	static
	_delete(std::size_t count, GLuint* names)
	noexcept
	{
		assert(names != nullptr);

		OGLPLUS_GLFUNC(DeleteTextures)(GLsizei(count), names);
		OGLPLUS_VERIFY_SIMPLE(DeleteTextures,severe);
		return {};
	}
};

} // namespace oglplus

#endif // include guard
