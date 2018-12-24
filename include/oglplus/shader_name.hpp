/**
 *  @file oglplus/shader_name.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_SHADER_NAME_HPP
#define OGLPLUS_SHADER_NAME_HPP

#include "object/gl_name.hpp"

#ifndef GL_SHADER
#define GL_SHADER 0x82E1
#endif

namespace oglplus {
namespace tag {

using shader = gl_obj_tag<GL_SHADER>;

} // namespace tag

using shader_name = object_name<tag::shader>;

} // namespace oglplus

#endif // OGLPLUS_SHADER_NAME_HPP
