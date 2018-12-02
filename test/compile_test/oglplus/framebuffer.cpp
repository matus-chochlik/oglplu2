/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
// clang-format off
#include "helper/object_c.hpp"
#include <oglplus/gl.hpp>
#include <oglplus/framebuffer.hpp>
// clang-format on

using namespace oglplus;

void
oglplus_framebuffer_test_1(void) {
    oglplus_object_name_test<framebuffer_name>();
    oglplus_object_test<framebuffer>();
}

void
oglplus_framebuffer_test_ops1(void) {
    using namespace oglplus;

    oper::framebuffer_ops gl;
    framebuffer fbo;
    framebuffer_array<4> fbos;
    framebuffer_target tgt(GL_DRAW_FRAMEBUFFER);
    bound_framebuffer curfbo(tgt);
    framebuffer_attachment attch(GL_DEPTH_ATTACHMENT);
    framebuffer_color_attachment cattch(GL_COLOR_ATTACHMENT0);
    enum_list<framebuffer_attachment> attchs(attch, cattch);
    framebuffer_buffer fbb(GL_COLOR);
    color_buffer cbuf(GL_FRONT);
    enum_list<color_buffer> cbufs(color_buffer(GL_NONE), color_buffer(GL_NONE));
    renderbuffer_target rbt(GL_RENDERBUFFER);
    renderbuffer_name rbo(0);
#if defined(GL_VERSION_4_3)
    framebuffer_parameter param(GL_FRAMEBUFFER_DEFAULT_WIDTH);
#endif

#if defined(GL_VERSION_4_2) || defined(GL_ARB_texture_storage)
    texture_target textgt1(GL_TEXTURE_1D);
    texture_target textgt3(GL_TEXTURE_3D);
#endif
    texture_target textgt2(GL_TEXTURE_2D);
    texture_name tex(0);

    gl.bind_framebuffer(tgt, fbo);
    gl.framebuffer_binding(tgt);
    gl.bind_framebuffer(tgt, fbos[0]);

#if defined(GL_VERSION_4_3)
    gl.framebuffer_parameter_i(tgt, param, 1024);
#endif
#if defined(GL_VERSION_4_3)
    gl.framebuffer_parameter_i(fbo, param, 1024);
#endif

    gl.check_framebuffer_status(tgt);
    gl.is_framebuffer_complete(tgt);
    gl.framebuffer_renderbuffer(tgt, attch, rbt, rbo);
#if defined(GL_VERSION_4_2) || defined(GL_ARB_texture_storage)
    gl.framebuffer_texture_1d(tgt, attch, textgt1, tex, 0);
    gl.framebuffer_texture_3d(tgt, attch, textgt1, tex, 0, 0);
    gl.framebuffer_texture_2d(tgt, attch, textgt1, tex, 0);
#endif
#if defined(GL_VERSION_3_0)
    gl.draw_buffer(cbuf);
    gl.draw_buffers(cbufs);
#endif
    gl.read_buffer(cbuf);

#if defined(GL_VERSION_3_0)
    gl.clear_buffer(fbb, 0, span<GLint>());
    gl.clear_buffer(fbb, 1, span<GLuint>());
    gl.clear_buffer(fbb, 2, span<GLfloat>());
    gl.clear_buffer(fbb, 3, 1.0f, 0);
    gl.blit_framebuffer(
      0,
      0,
      128,
      128,
      0,
      0,
      128,
      128,
      enum_bitfield<buffer_select_bits>(0),
      blit_filter(GL_NEAREST));
#endif

#if defined(GL_VERSION_4_3)
    gl.invalidate_framebuffer_data(tgt, attchs);
    gl.invalidate_framebuffer_sub_data(tgt, attchs, 32, 32, 64, 64);
#endif

#if defined(GL_VERSION_4_5)
    gl.clear_framebuffer(fbo, fbb, 0, span<GLint>());
    gl.clear_framebuffer(fbo, fbb, 1, span<GLuint>());
    gl.clear_framebuffer(fbo, fbb, 2, span<GLfloat>());
    gl.clear_framebuffer(fbo, fbb, 3, 1.0f, 0);
    gl.invalidate_framebuffer_data(fbo, attchs);
    gl.blit_framebuffer(
      fbos[1],
      fbos[2],
      0,
      0,
      128,
      128,
      0,
      0,
      128,
      128,
      enum_bitfield<buffer_select_bits>(0),
      blit_filter(GL_NEAREST));
#endif

    curfbo.check_status();
    curfbo.is_complete();
    curfbo.renderbuffer(attch, rbt, rbo);
#if defined(GL_VERSION_3_2)
    curfbo.texture(attch, tex, 0);
#endif

#if defined(GL_VERSION_4_2) || defined(GL_ARB_texture_storage)
    curfbo.texture_1d(attch, textgt1, tex, 0);
    curfbo.texture_3d(attch, textgt3, tex, 0, 0);
#endif
    curfbo.texture_2d(attch, textgt2, tex, 0);

#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access) || \
  defined(GL_EXT_direct_state_access)

    gl.check_framebuffer_status(fbo, tgt);
    gl.is_framebuffer_complete(fbo, tgt);
    gl.framebuffer_renderbuffer(fbo, attch, rbt, rbo);
#if defined(GL_VERSION_3_0) && defined(GL_EXT_direct_state_access)
    gl.framebuffer_texture_1d(fbo, attch, textgt1, tex, 0);
    gl.framebuffer_texture_2d(fbo, attch, textgt1, tex, 0);
    gl.framebuffer_texture_3d(fbo, attch, textgt1, tex, 0, 0);
#endif

#if defined(GL_VERSION_3_0)
    gl.framebuffer_texture_layer(tgt, attch, tex, 0, 1);
#endif
#if defined(GL_VERSION_3_2)
    gl.framebuffer_texture(fbo, attch, tex, 0);
#endif

#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access) || \
  defined(GL_EXT_direct_state_access)
    gl.framebuffer_texture_layer(fbo, attch, tex, 0, 1);
    gl.framebuffer_texture(fbo, attch, tex, 0);
#endif

    gl.framebuffer_draw_buffer(fbo, cattch);
    gl.framebuffer_read_buffer(fbo, cattch);
#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access) || \
  defined(GL_EXT_direct_state_access)
    gl.framebuffer_draw_buffers(fbo, attchs);
#endif

    fbo.check_status(tgt);
    fbo.is_complete(tgt);
    fbo.renderbuffer(attch, rbt, rbo);
#if defined(GL_VERSION_3_2)
    fbo.texture(attch, tex, 0);
#endif
    fbo.draw_buffer(cattch);
    fbo.read_buffer(cattch);
#endif

#if defined(GL_VERSION_4_5)
    fbo.clear_buffer(fbb, 0, span<GLint>());
    fbo.clear_buffer(fbb, 1, span<GLuint>());
    fbo.clear_buffer(fbb, 2, span<GLfloat>());
    fbo.clear_buffer(fbb, 3, 1.0f, 0);
#endif

#if defined(GL_EXT_direct_state_access)
    fbo.texture_1d(attch, textgt1, tex, 0);
    fbo.texture_2d(attch, textgt1, tex, 0);
    fbo.texture_3d(attch, textgt1, tex, 0, 0);
#endif
}

// TODO
