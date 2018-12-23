/**
 *  @file oglplus/state_nv_name.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_STATE_NV_NAME_HPP
#define OGLPLUS_STATE_NV_NAME_HPP

#ifndef GL_NV_command_list
#error NV_command_list API is not defined
#endif

#include "object/gl_name.hpp"

namespace oglplus {
namespace tag {

using state_nv = gl_obj_tag<0x57A7>;

} // namespace tag

using state_nv_name = object_name<tag::state_nv>;

} // namespace oglplus

#endif // OGLPLUS_STATE_NV_NAME_HPP
