/**
 *  @file oglplus/vertex_attrib_slot.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_VERTEX_ATTRIB_SLOT_1509260923_HPP
#define OGLPLUS_VERTEX_ATTRIB_SLOT_1509260923_HPP

#include "utils/limited_value.hpp"

namespace oglplus {

using vertex_attrib_slot = limited_value<GL_MAX_VERTEX_ATTRIBS, GLuint>;

} // namespace oglplus

#endif // include guard
