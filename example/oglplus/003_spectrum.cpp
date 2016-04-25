/**
 *  example oglplus/003_spectrum.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <oglplus/gl_fixed.hpp>
#include <oglplus/constants.hpp>
#include <oglplus/operations.hpp>

#include "example.hpp"

namespace oglplus {

class example_clear
 : public example
{
private:
	constants  GL;
	operations gl;
public:
	example_clear(void)
	{
		gl.clear_color(0.4f, 0.4f, 0.4f, 0.0f);
	}

	void resize(const example_state_view& state)
	override
	{
		gl.viewport(0, 0, state.width(), state.height());

		float h = 2;
		float w = h*state.aspect();

		gl.load_identity(GL.projection);
		gl.ortho(GL.projection, -w,+w, -h,+h, 0,1);
	}

	void render(const example_state_view& state)
	override
	{
		gl.clear(GL.color_buffer_bit);

		gl.load_identity(GL.modelview);
		gl.rotate_f(
			GL.modelview,
			degrees_(state.exec_time().value()*90),
			0, 0, 1
		);

		gl.begin(GL.triangle_fan);
			gl.color_f( 0.5f, 0.5f, 0.5f);
			gl.vertex_f( 0.000f, 0.000f);

			gl.color_f( 1.0f, 0.0f, 0.0f);
			gl.vertex_f( 0.000f, 1.000f);

			gl.color_f( 1.0f, 0.7f, 0.0f);
			gl.vertex_f( 0.707f, 0.707f);

			gl.color_f( 0.7f, 1.0f, 0.0f);
			gl.vertex_f( 1.000f, 0.000f);

			gl.color_f( 0.0f, 1.0f, 0.0f);
			gl.vertex_f( 0.707f,-0.707f);

			gl.color_f( 0.0f, 1.0f, 0.7f);
			gl.vertex_f( 0.000f,-1.000f);

			gl.color_f( 0.0f, 0.7f, 1.0f);
			gl.vertex_f(-0.707f,-0.707f);

			gl.color_f( 0.0f, 0.0f, 1.0f);
			gl.vertex_f(-1.000f, 0.000f);

			gl.color_f( 0.7f, 0.0f, 0.7f);
			gl.vertex_f(-0.707f, 0.707f);

			gl.color_f( 1.0f, 0.0f, 0.0f);
			gl.vertex_f( 0.000f, 1.000f);

		gl.end();

		gl.begin(GL.line_loop);
			gl.color_f( 0, 0, 0);

			gl.vertex_f( 0.000f, 1.000f);
			gl.vertex_f( 0.707f, 0.707f);
			gl.vertex_f( 1.000f, 0.000f);
			gl.vertex_f( 0.707f,-0.707f);
			gl.vertex_f( 0.000f,-1.000f);
			gl.vertex_f(-0.707f,-0.707f);
			gl.vertex_f(-1.000f, 0.000f);
			gl.vertex_f(-0.707f, 0.707f);
			gl.vertex_f( 0.000f, 1.000f);
		gl.end();
	}
};

std::unique_ptr<example>
make_example(
	const example_args&,
	const example_params&,
	const example_state_view&
)
{
	return std::unique_ptr<example>(new example_clear());
}

void adjust_params(example_params& params)
{
	params.compatibility_context(true);
	params.depth_buffer(false);
	params.stencil_buffer(false);
}

bool is_example_param(const example_arg&) { return false; }

} // namespace oglplus
