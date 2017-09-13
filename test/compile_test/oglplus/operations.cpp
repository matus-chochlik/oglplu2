/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/maybe_unused.hpp>
#include <oglplus/gl_fixed.hpp>
#include <oglplus/operations.hpp>

using namespace oglplus;

void oglplus_synchronization_test(void)
{
	using namespace oglplus;

	oper::synchronization gl;

#if defined(GL_VERSION_4_2) || defined(GL_ARB_shader_image_load_store)
	gl.memory_barrier(enum_bitfield<memory_barrier_bits>(0));
#endif

#if defined(GL_VERSION_4_5)
	gl.texture_barrier();
#endif

	gl.flush();
	gl.finish();
}

void oglplus_buffer_clearing_state_test(void)
{
	using namespace oglplus;

	oper::buffer_clearing_state gl;

	gl.clear_color(1.f, 1.f, 1.f, 0.f);
	gl.clear_color(oper::rgba_value(0.f, 0.f, 0.f, 0.f));
	gl.clear_depth(0.f);
	gl.clear_stencil(0);

	oper::rgba_value cc = gl.get_color_clear_value();
	GLfloat cd = gl.get_depth_clear_value();
	GLint cs = gl.get_stencil_clear_value();
	EAGINE_MAYBE_UNUSED(cc);
	EAGINE_MAYBE_UNUSED(cd);
	EAGINE_MAYBE_UNUSED(cs);
}

void oglplus_buffer_clearing_ops_test(void)
{
	using namespace oglplus;

	oper::buffer_clearing_ops gl;

	gl.clear(enum_bitfield<buffer_select_bits>(0));
}

void oglplus_capability_state_test(void)
{
	using namespace oglplus;

	oper::capability_state gl;

	gl.enable(capability(GL_DEPTH_TEST));
	gl.disable(capability(GL_DEPTH_TEST));
	gl.is_enabled(capability(GL_DEPTH_TEST));

#if defined(GL_VERSION_3_0)
	gl.enable(capability(GL_BLEND), 1);
	gl.disable(capability(GL_BLEND), 1);
	gl.is_enabled(capability(GL_BLEND), 1);
#endif

#if defined(GL_CLIP_DISTANCE0)
	gl.enable(clip_plane(0));
	gl.disable(clip_plane(0));
	gl.is_enabled(clip_plane(0));
#endif

#if defined(GL_ARB_compatibility)
	gl.enable_client_state(client_capability(GL_COLOR_ARRAY));
	gl.disable_client_state(client_capability(GL_COLOR_ARRAY));
	gl.is_enabled(client_capability(GL_COLOR_ARRAY));

	gl.get_red_bits();
	gl.get_green_bits();
	gl.get_blue_bits();
	gl.get_alpha_bits();
	gl.get_depth_bits();
	gl.get_stencil_bits();
	gl.has_doublebuffer();
	gl.is_stereo();
#endif
}

void oglplus_compatibility_test(void)
{
	using namespace oglplus;

#if defined(GL_ARB_compatibility)
	oper::compatibility_drawing gl;

	gl.begin(old_primitive_type(GL_QUADS));
	gl.end();

	// vertex
	gl.vertex_s(0, 1);
	gl.vertex_s(0, 1, 2);
	gl.vertex_s(0, 1, 2, 1);
	gl.vertex(std::array<GLshort, 4>{{0, 1, 2, 1}});

	gl.vertex_i(0, 1);
	gl.vertex_i(0, 1, 2);
	gl.vertex_i(0, 1, 2, 1);
	gl.vertex(std::array<GLint, 4>{{0, 1, 2, 1}});

	gl.vertex_f(0.f, 1.f);
	gl.vertex_f(0.f, 1.f, 2.f);
	gl.vertex_f(0.f, 1.f, 2.f, 1.f);
	gl.vertex(std::array<GLfloat, 4>{{0.f, 1.f, 2.f, 1.f}});

	gl.vertex_d(0.0, 1.0);
	gl.vertex_d(0.0, 1.0, 2.0);
	gl.vertex_d(0.0, 1.0, 2.0, 1.0);
	gl.vertex(std::array<GLdouble, 4>{{0.0, 1.0, 2.0, 1.0}});

	// color
	gl.color_ub(0x00, 0x00, 0x00);
	gl.color_ub(0x00, 0x00, 0x00, 0x00);
	gl.color(std::array<GLubyte, 4>{{0x00, 0x00, 0x00, 0x00}});

	gl.color_i(0, 0, 0);
	gl.color_i(0, 0, 0, 1);
	gl.color(std::array<GLint, 4>{{0, 0, 0, 1}});

	gl.color_f(0.f, 0.f, 0.f);
	gl.color_f(0.f, 0.f, 0.f, 0.f);
	gl.color(std::array<GLfloat, 4>{{0.f, 0.f, 0.f, 0.f}});

	gl.color_d(0.0, 0.0, 0.0);
	gl.color_d(0.0, 0.0, 0.0, 0.0);
	gl.color(std::array<GLdouble, 4>{{0.0, 0.0, 0.0, 0.0}});

	// tex_coord
	gl.tex_coord_s(0, 1);
	gl.tex_coord_s(0, 1, 2);
	gl.tex_coord_s(0, 1, 2, 1);
	gl.tex_coord(std::array<GLshort, 4>{{0, 1, 2, 1}});

	gl.tex_coord_i(0, 1);
	gl.tex_coord_i(0, 1, 2);
	gl.tex_coord_i(0, 1, 2, 1);
	gl.tex_coord(std::array<GLint, 4>{{0, 1, 2, 1}});

	gl.tex_coord_f(0.f, 1.f);
	gl.tex_coord_f(0.f, 1.f, 2.f);
	gl.tex_coord_f(0.f, 1.f, 2.f, 1.f);
	gl.tex_coord(std::array<GLfloat, 4>{{0.f, 1.f, 2.f, 1.f}});

	gl.tex_coord_d(0.0, 1.0);
	gl.tex_coord_d(0.0, 1.0, 2.0);
	gl.tex_coord_d(0.0, 1.0, 2.0, 1.0);
	gl.tex_coord(std::array<GLdouble, 4>{{0.0, 1.0, 2.0, 1.0}});

#endif
}

