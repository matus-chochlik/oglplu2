/**
 *  @file oglplus/framebuffer_name.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_FRAMEBUFFER_NAME_1509260923_HPP
#define OGLPLUS_FRAMEBUFFER_NAME_1509260923_HPP

#include "object/gl_name.hpp"
#include "enum/types.hpp"

#ifndef GL_FRAMEBUFFER
#define GL_FRAMEBUFFER 0x8D40
#endif

namespace oglplus {
namespace tag {

using framebuffer = gl_obj_tag<GL_FRAMEBUFFER>;

} // namespace tag

using framebuffer_name = object_name<tag::framebuffer>;

template <>
struct get_obj_binding_point<tag::framebuffer>
{
	typedef framebuffer_target type;
};

} // namespace oglplus

#endif // include guard
