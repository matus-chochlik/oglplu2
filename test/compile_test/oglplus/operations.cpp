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

