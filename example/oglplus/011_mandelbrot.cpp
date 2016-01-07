/**
 *  example oglplus/011_mandelbrot.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <oglplus/gl_fixed.hpp>
#include <oglplus/constants.hpp>
#include <oglplus/operations.hpp>
#include <oglplus/glsl/string_ref.hpp>

#include "example.hpp"
#include <iostream>

namespace oglplus {

class example_mandelbrot
 : public example
{
private:
	constants  GL;
	operations gl;

	program prog;

	uniform<GLfloat> offset_loc;
	uniform<GLfloat> scale_loc;

	vertex_array vao;

	buffer positions;
	buffer coords;

	texture gradient;

	GLfloat offset_x, offset_y;
	GLfloat scale, aspect;

	static constexpr const float min_scale = 0.00001f;
	static constexpr const float max_scale = 10.0f;
public:
	example_mandelbrot(void)
	 : offset_x(-0.5f)
	 , offset_y(0.0f)
	 , scale(1.0f)
	 , aspect(1.0f)
	{
		shader vs(GL.vertex_shader);
		vs.source(glsl_literal(
			"#version 130\n"
			"uniform vec2 Offset;\n"
			"uniform vec2 Scale;\n"
			"in vec2 Position;\n"
			"in vec2 Coord;\n"
			"out vec2 vertCoord;\n"
			"void main(void)\n"
			"{\n"
			"	vertCoord = Coord*Scale+Offset;\n"
			"	gl_Position = vec4(Position, 0.0, 1.0);\n"
			"}\n"
		));
		vs.compile();

		shader fs(GL.fragment_shader);
		fs.source(glsl_literal(
		"#version 130\n"
		"uniform sampler1D gradient;\n"
		"in vec2 vertCoord;\n"
		"out vec4 fragColor;\n"
		"void main(void)\n"
		"{\n"
		"	vec2 z = vec2(0.0, 0.0);\n"
		"	vec2 c = vertCoord;\n"
		"	int i = 0, max = 256;\n"
		"	while((i != max) && (distance(z, c) < 2.0))\n"
		"	{\n"
		"		vec2 zn = vec2(\n"
		"			z.x * z.x - z.y * z.y + c.x,\n"
		"			2.0 * z.x * z.y + c.y\n"
		"		);\n"
		"		z = zn;\n"
		"		++i;\n"
		"	}\n"
		"	float a = float(i)/float(max);\n"
		"	fragColor = texture(gradient, a+sqrt(length(c))*0.1);\n"
		"} \n"
		));
		fs.compile();

		prog.attach(vs);
		prog.attach(fs);
		prog.link();

		gl.use(prog);

		gl.query_location(offset_loc, prog, "Offset");
		gl.query_location(scale_loc, prog, "Scale");
		gl.uniform(offset_loc, offset_x, offset_y);


		gl.bind(vao);

		GLfloat position_data[4*2] = {
			-1.0f, -1.0f,
			-1.0f,  1.0f,
			 1.0f, -1.0f,
			 1.0f,  1.0f
		};

		gl.bind(GL.array_buffer, positions);
		gl.buffer_data(GL.array_buffer, position_data, GL.static_draw);

		vertex_attrib_location va_p;
		gl.query_location(va_p, prog, "Position");
		gl.vertex_array_attrib_pointer(
			va_p,
			2, GL.float_,
			false, 0, nullptr
		);
		gl.enable_vertex_array_attrib(va_p);


		GLfloat coord_data[4*2] = {
			-1.0f, -1.0f,
			-1.0f,  1.0f,
			 1.0f, -1.0f,
			 1.0f,  1.0f
		};

		gl.bind(GL.array_buffer, coords);
		gl.buffer_data(GL.array_buffer, coord_data, GL.static_draw);

		vertex_attrib_location va_c;
		gl.query_location(va_c, prog, "Coord");
		gl.vertex_array_attrib_pointer(
			va_c,
			2, GL.float_,
			false, 0, nullptr
		);
		gl.enable_vertex_array_attrib(va_c);

		GLfloat gradient_data[8*3];

		for(int i=0; i<8*3; ++i)
		{
			gradient_data[i] = (std::rand() % 10000) / 10000.f;
		}

		gl.bind(GL.texture_1d, gradient);
		gl.texture_min_filter(GL.texture_1d, GL.linear);
		gl.texture_mag_filter(GL.texture_1d, GL.linear);
		gl.texture_wrap(
			GL.texture_1d,
			GL.texture_wrap_s,
			GL.repeat
		);
		gl.texture_image_1d(
			GL.texture_1d,
			0, GL.rgb,
			8,
			0, GL.rgb,
			GL.float_,
			const_memory_block{gradient_data}
		);

		gl.disable(GL.depth_test);
	}

	void pointer_motion(const example_state_view& state)
	override
	{
		if(state.pointer_dragging())
		{
			offset_x -= 2*state.norm_delta_pointer_x()*scale;
			offset_y -= 2*state.norm_delta_pointer_y()*scale;

			gl.uniform(offset_loc, offset_x, offset_y);
		}
	}

	void pointer_scrolling(const example_state_view& state)
	override
	{

		scale *= float(std::pow(2,-state.norm_delta_pointer_z()));
		if(scale < min_scale) scale = min_scale;
		if(scale > max_scale) scale = max_scale;

		gl.uniform(scale_loc, scale*aspect, scale);
	}

	void resize(const example_state_view& state)
	override
	{
		gl.viewport(0, 0, state.width(), state.height());

		aspect = state.aspect();
		gl.uniform(scale_loc, scale*aspect, scale);
	}

	void user_idle(const example_state_view& state)
	override
	{
		if(state.user_idle_time() > seconds_(1))
		{
			const float s = value(state.frame_duration())*60;
			const float dest_offset_x = -0.525929f;
			const float dest_offset_y = -0.668547f;
			const float c = 0.02f * s;

			offset_x = c*dest_offset_x + (1-c)*offset_x;
			offset_y = c*dest_offset_y + (1-c)*offset_y; 

			scale *= (1-0.01f*s);
			if(scale < min_scale) scale = min_scale;

			gl.uniform(offset_loc, offset_x, offset_y);
			gl.uniform(scale_loc, scale*aspect, scale);
		}
	}

	bool continue_running(const example_state_view& state)
	override
	{
		return state.user_idle_time() < seconds_(20);
	}

	void render(const example_state_view& /*state*/)
	override
	{
		gl.draw_arrays(GL.triangle_strip, 0, 4);
	}
};

std::unique_ptr<example>
make_example(const example_params&, const example_state_view&)
{
	return std::unique_ptr<example>(new example_mandelbrot());
}

void adjust_params(example_params& params)
{
	params.rand_seed(1234);
	params.depth_buffer(false);
	params.stencil_buffer(false);
}

} // namespace oglplus
