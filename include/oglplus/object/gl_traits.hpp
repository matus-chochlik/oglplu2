/**
 *  @file oglplus/object/gl_traits.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OBJECT_GL_TRAITS_1509260923_HPP
#define OGLPLUS_OBJECT_GL_TRAITS_1509260923_HPP

#include "fwd.hpp"

namespace oglplus {
namespace tag {

template <GLenum Tag>
struct gl_obj_tag;

} // namespace tag
} // namespace oglplus

namespace eagine {

template <GLenum Tag>
struct object_traits<oglplus::tag::gl_obj_tag<Tag>>
{
	typedef GLuint name_type;
	typedef oglplus::tag::gl_obj_tag<Tag> tag;

	typedef oglplus::obj_gen_del_ops<tag> gen_del_ops;

	static inline constexpr
	GLuint invalid_name(void)
	noexcept
	{
		return ~GLuint(0);
	}
};

} // namespace eagine

#endif // include guard
