/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
// clang-format off
#include "helper/object_c.hpp"
#include <oglplus/gl_fixed.hpp>
#include <oglplus/renderbuffer.hpp>
// clang-format on

using namespace oglplus;

void
oglplus_renderbuffer_test_1(void) {
    oglplus_object_name_test<renderbuffer_name>();
    oglplus_object_test<renderbuffer>();
}

void
oglplus_renderbuffer_test_ops1(void) {
    oper::renderbuffer_ops gl;
    renderbuffer rbo;
    renderbuffer_array<4> rbos;
    renderbuffer_target tgt(GL_RENDERBUFFER);
    bound_renderbuffer currbo(tgt);
    pixel_data_internal_format ifmt(GL_RGBA);

    gl.renderbuffer_storage(tgt, ifmt, 32, 32);
    gl.renderbuffer_storage_multisample(tgt, 4, ifmt, 32, 32);
    gl.get_renderbuffer_width(tgt);
    gl.get_renderbuffer_height(tgt);
    gl.get_renderbuffer_red_size(tgt);
    gl.get_renderbuffer_green_size(tgt);
    gl.get_renderbuffer_blue_size(tgt);
    gl.get_renderbuffer_alpha_size(tgt);
    gl.get_renderbuffer_depth_size(tgt);
    gl.get_renderbuffer_stencil_size(tgt);
    gl.get_renderbuffer_samples(tgt);
    gl.get_renderbuffer_internal_format(tgt);

    currbo.storage(ifmt, 32, 32);
    currbo.storage_multisample(4, ifmt, 32, 32);
    currbo.get_width();
    currbo.get_height();
    currbo.get_red_size();
    currbo.get_green_size();
    currbo.get_blue_size();
    currbo.get_alpha_size();
    currbo.get_depth_size();
    currbo.get_stencil_size();
    currbo.get_samples();
    currbo.get_internal_format();

#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access) || \
  defined(GL_EXT_direct_state_access)

    gl.renderbuffer_storage(rbo, ifmt, 32, 32);
    gl.renderbuffer_storage_multisample(rbo, 4, ifmt, 32, 32);
    gl.get_renderbuffer_width(rbo);
    gl.get_renderbuffer_height(rbo);
    gl.get_renderbuffer_red_size(rbo);
    gl.get_renderbuffer_green_size(rbo);
    gl.get_renderbuffer_blue_size(rbo);
    gl.get_renderbuffer_alpha_size(rbo);
    gl.get_renderbuffer_depth_size(rbo);
    gl.get_renderbuffer_stencil_size(rbo);
    gl.get_renderbuffer_samples(rbo);
    gl.get_renderbuffer_internal_format(rbo);

    rbo.storage(ifmt, 32, 32);
    rbo.storage_multisample(4, ifmt, 32, 32);
    rbo.get_width();
    rbo.get_height();
    rbo.get_red_size();
    rbo.get_green_size();
    rbo.get_blue_size();
    rbo.get_alpha_size();
    rbo.get_depth_size();
    rbo.get_stencil_size();
    rbo.get_samples();
    rbo.get_internal_format();

#endif
}

// TODO
