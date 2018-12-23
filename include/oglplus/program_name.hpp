/**
 *  @file oglplus/program_name.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_PROGRAM_NAME_HPP
#define OGLPLUS_PROGRAM_NAME_HPP

#include "shader.hpp"

#ifndef GL_PROGRAM
#define GL_PROGRAM 0x82E2
#endif

namespace oglplus {
namespace tag {

using program = gl_obj_tag<GL_PROGRAM>;

} // namespace tag

using program_name = object_name<tag::program>;

} // namespace oglplus

#endif // OGLPLUS_PROGRAM_NAME_HPP
