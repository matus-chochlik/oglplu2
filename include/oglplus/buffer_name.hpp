/**
 *  @file oglplus/buffer_name.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_BUFFER_NAME_1509260923_HPP
#define OGLPLUS_BUFFER_NAME_1509260923_HPP

#include "object/gl_name.hpp"

#ifndef GL_BUFFER
#define GL_BUFFER 0x82E0
#endif

namespace oglplus {
namespace tag {

using buffer = gl_obj_tag<GL_BUFFER>;

} // namespace tag

using buffer_name = object_name<tag::buffer>;

} // namespace oglplus

#endif // include guard
