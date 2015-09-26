/**
 *  @file oglplus/object/gl_names.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *  https://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OBJECT_GL_NAMES_1509260923_HPP
#define OGLPLUS_OBJECT_GL_NAMES_1509260923_HPP

#include "names.hpp"
#include "gl_traits.hpp"

namespace oglplus {

template <typename ObjTag, std::size_t N>
using object_name_array = object_names<ObjTag, std::array<GLuint, N>>;

} // namespace oglplus

#endif // include guard
