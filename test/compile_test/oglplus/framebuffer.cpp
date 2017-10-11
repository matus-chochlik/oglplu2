/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/gl_fixed.hpp>
#include <oglplus/framebuffer.hpp>
#include "helper/object_c.hpp"

using namespace oglplus;

void oglplus_framebuffer_test_1(void)
{
	oglplus_object_name_test<framebuffer_name>();
	oglplus_object_test<framebuffer>();
}

void oglplus_framebuffer_test_ops1(void)
{
	using namespace oglplus;

	oper::framebuffer_ops gl;
	framebuffer fbo;
	framebuffer_array<4> fbos;
	framebuffer_target tgt(GL_DRAW_FRAMEBUFFER);
	bound_framebuffer curfbo(tgt);
	framebuffer_attachment attch(GL_DEPTH_ATTACHMENT);
	framebuffer_color_attachment cattch(GL_COLOR_ATTACHMENT0);
	framebuffer_buffer fbb(GL_COLOR);
	color_buffer cbuf(GL_FRONT);
	renderbuffer_target rbt(GL_RENDERBUFFER);
	renderbuffer_name rbo(0);

#if defined(GL_VERSION_4_2) || defined(GL_ARB_texture_storage)
	texture_target textgt1(GL_TEXTURE_1D);
	texture_target textgt3(GL_TEXTURE_3D);
#endif
	texture_target textgt2(GL_TEXTURE_2D);
	texture_name tex(0);

	gl.bind_framebuffer(tgt, fbo);
	gl.framebuffer_binding(tgt);
	gl.bind_framebuffer(tgt, fbos[0]);

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
#endif
	gl.read_buffer(cbuf);

#if defined(GL_VERSION_3_0)
	gl.clear_buffer(fbb, 1, 1.0f, 0);
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

#if defined(GL_VERSION_4_5) ||\
	defined(GL_ARB_direct_state_access) ||\
	defined(GL_EXT_direct_state_access)

	gl.check_framebuffer_status(fbo, tgt);
	gl.is_framebuffer_complete(fbo, tgt);
	gl.framebuffer_renderbuffer(fbo, attch, rbt, rbo);
#if defined(GL_VERSION_4_2) || defined(GL_ARB_texture_storage)
	gl.framebuffer_texture_1d(fbo, attch, textgt1, tex, 0);
	gl.framebuffer_texture_3d(fbo, attch, textgt1, tex, 0, 0);
#endif
	gl.framebuffer_texture_2d(fbo, attch, textgt1, tex, 0);
#if defined(GL_VERSION_3_2)
	gl.framebuffer_texture(fbo, attch, tex, 0);
#endif
	gl.framebuffer_draw_buffer(fbo, cattch);
	gl.framebuffer_read_buffer(fbo, cattch);

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
	fbo.clear_buffer(fbb, 1, 1.0f, 0);
#endif

#if defined(GL_EXT_direct_state_access)
	fbo.texture_1d(attch, textgt1, tex, 0);
	fbo.texture_2d(attch, textgt1, tex, 0);
	fbo.texture_3d(attch, textgt1, tex, 0, 0);
#endif
}

// TODO
