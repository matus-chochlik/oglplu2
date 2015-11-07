/**
 *  @file oglplus/renderbuffer_name.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_RENDERBUFFER_NAME_1509260923_HPP
#define OGLPLUS_RENDERBUFFER_NAME_1509260923_HPP

#include "object/gl_name.hpp"
#include "enum/types.hpp"

#ifndef GL_RENDERBUFFER
#define GL_RENDERBUFFER 0x8D41
#endif

namespace oglplus {
namespace tag {

using renderbuffer = gl_obj_tag<GL_RENDERBUFFER>;

} // namespace tag

using renderbuffer_name = object_name<tag::renderbuffer>;

template <>
struct get_obj_binding_point<tag::renderbuffer>
{
	typedef renderbuffer_target type;
};

} // namespace oglplus

#endif // include guard
