/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
// clang-format off
#include "helper/object_c.hpp"
#include <oglplus/gl_fixed.hpp>

#if defined(GL_NV_command_list)

#include <oglplus/command_list_nv.hpp>
// clang-format on

using namespace oglplus;

void
oglplus_command_list_nv_test_1(void) {
    oglplus_object_name_test<command_list_nv_name>();
    oglplus_object_test<command_list_nv>();
}

void
oglplus_command_list_nv_test_ops1(void) {
    oper::command_list_nv_ops gl;
    command_list_nv lst;
    command_list_nv_array<4> lsts;

    gl.command_list_segments(lst, 4);
    gl.command_list_segments(lsts[0], 4);
    gl.compile_command_list(lst);
    gl.call_command_list(lst);

    lst.segments(4);
    lst.compile();
    lst.call();
}

    // TODO

#endif
