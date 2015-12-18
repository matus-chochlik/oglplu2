/**
 *  example oglplus/009_mandelbrot.cpp
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

namespace oglplus {

class example_mandelbrot
 : public example
{
private:
	constants  GL;
	operations gl;

	program prog;

	vertex_array vao;

	buffer positions;
	buffer coords;

	texture gradient;
public:
	example_mandelbrot(void)
	{
		shader vs(GL.vertex_shader);
		vs.source(glsl_literal(
			"#version 130\n"
			"in vec2 Position;\n"
			"in vec2 Coord;\n"
			"out vec2 vertCoord;\n"
			"void main(void)\n"
			"{\n"
			"	vertCoord = Coord;\n"
			"	gl_Position = vec4(Position, 0.0, 1.0);\n"
			"}\n"
		));
		vs.compile();

		shader fs(GL.fragment_shader);
		fs.source(glsl_literal(
		"#version 130\n"
		"in vec2 vertCoord;\n"
		"out vec4 fragColor;\n"
		"uniform sampler1D gradient;\n"
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
		"	float a = sqrt(float(i) / float(max));\n"
		"	fragColor = texture(gradient, a);\n"
		"} \n"
		));
		fs.compile();

		prog.attach(vs);
		prog.attach(fs);
		prog.link();

		gl.use(prog);

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
			-1.5f, -0.5f,
			-1.5f,  1.0f,
			 0.5f, -0.5f,
			 0.5f,  1.0f
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

	void resize(const example_state_view& state)
	override
	{
		gl.viewport(0, 0, state.width(), state.height());
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
	params.depth_bits(0);
	params.stencil_bits(0);
}

} // namespace oglplus
