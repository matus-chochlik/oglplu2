/**
 *  @file oglplus/texture_name.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXTURE_NAME_1509260923_HPP
#define OGLPLUS_TEXTURE_NAME_1509260923_HPP

#include "object/gl_name.hpp"
#include "enum/types.hpp"

#ifndef GL_TEXTURE
#define GL_TEXTURE 0x1702
#endif

namespace oglplus {
namespace tag {

using texture = gl_obj_tag<GL_TEXTURE>;

} // namespace tag

using texture_name = object_name<tag::texture>;

template <>
struct get_obj_binding_point<tag::texture>
{
	typedef texture_target type;
};

} // namespace oglplus

#endif // include guard
