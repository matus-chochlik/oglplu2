/**
 *  @file oglplus/vertex_array_name.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_VERTEX_ARRAY_NAME_HPP
#define OGLPLUS_VERTEX_ARRAY_NAME_HPP

#include "object/gl_name.hpp"

#ifndef GL_VERTEX_ARRAY
#define GL_VERTEX_ARRAY 0x8074
#endif

namespace oglplus {
namespace tag {

using vertex_array = gl_obj_tag<GL_VERTEX_ARRAY>;

} // namespace tag

using vertex_array_name = object_name<tag::vertex_array>;

} // namespace oglplus

#endif // OGLPLUS_VERTEX_ARRAY_NAME_HPP
