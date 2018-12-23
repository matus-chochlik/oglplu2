/**
 *  @file oglplus/command_list_nv_name.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_COMMAND_LIST_NV_NAME_HPP
#define OGLPLUS_COMMAND_LIST_NV_NAME_HPP

#ifndef GL_NV_command_list
#error NV_command_list API is not defined
#endif

#include "object/gl_name.hpp"

namespace oglplus {
namespace tag {

using command_list_nv = gl_obj_tag<0x1157>;

} // namespace tag

using command_list_nv_name = object_name<tag::command_list_nv>;

} // namespace oglplus

#endif // OGLPLUS_COMMAND_LIST_NV_NAME_HPP
