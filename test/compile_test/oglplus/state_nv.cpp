/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
// clang-format off
#include "helper/object_c.hpp"
#include <oglplus/gl.hpp>

#if defined(GL_NV_command_list)

#include <oglplus/state_nv.hpp>
// clang-format on

using namespace oglplus;

void oglplus_state_nv_test_1() {
    oglplus_object_name_test<state_nv_name>();
    oglplus_object_test<state_nv>();
}

void oglplus_state_nv_test_ops1() {
    oper::state_nv_ops gl;
    state_nv ste;
    state_nv_array<4> stes;
    old_primitive_type cpt(GL_TRIANGLES);

    gl.get_command_header(command_token_nv(GL_NOP_COMMAND_NV), 0);
    gl.get_stage_index(shader_type(GL_VERTEX_SHADER));

    gl.state_capture(ste, cpt);
    gl.state_capture(stes[0], cpt);

    ste.capture(cpt);
}

// TODO

#endif
