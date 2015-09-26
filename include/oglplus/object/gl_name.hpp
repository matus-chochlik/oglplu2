/**
 *  @file oglplus/object/gl_name.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *  https://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OBJECT_GL_NAME_1509260923_HPP
#define OGLPLUS_OBJECT_GL_NAME_1509260923_HPP

#include "name.hpp"
#include "gl_traits.hpp"

namespace oglplus {

template <typename ObjTag>
using object_name = object_names<ObjTag, GLuint>;

} // namespace oglplus

#endif // include guard
