/**
 *  example oglplus/014_voronoi.cpp
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
#include <eagine/random_bytes.hpp>

#include "example.hpp"
#include <vector>

namespace oglplus {

static constants  GL;
static operations gl;

class voronoi_program
 : public program
{
public:
	uniform<GLfloat> offset_loc;
	uniform<GLfloat> scale_loc;

	voronoi_program(void)
	{
		shader vs(GL.vertex_shader);
		vs.source(glsl_literal(
		"#version 140\n"

		"uniform vec2 Offset;\n"
		"uniform vec2 Scale;\n"

		"in vec4 Position;\n"
		"in vec2 TexCoord;\n"

		"out vec2 vertTexCoord;\n"

		"void main(void)\n"
		"{\n"
		"	gl_Position = Position;\n"
		"	vertTexCoord = Scale*TexCoord + Offset;\n"
		"}\n"
		));
		vs.compile();
		vs.report_compile_error();

		shader fs(GL.fragment_shader);
		fs.source(glsl_literal(
		"#version 140\n"

		"uniform vec2 Scale;\n"
		"uniform sampler2D Tex;\n"

		"in vec2 vertTexCoord;\n"

		"out vec3 fragColor;\n"

		"const vec2 offs[9] = vec2[9]("
		"	vec2(-1,-1),"
		"	vec2(-1, 0),"
		"	vec2(-1, 1),"
		"	vec2( 0,-1),"
		"	vec2( 0, 0),"
		"	vec2( 0, 1),"
		"	vec2( 1,-1),"
		"	vec2( 1, 0),"
		"	vec2( 1, 1) "
		");\n"

		"float dist(vec2 tc, vec2 ofs)\n"
		"{\n"
		"	vec2 cc = floor(tc+ofs);\n"
		"	vec2 cp = texture(Tex, cc/textureSize(Tex, 0)).xy;\n"
		"	return distance(tc, cc+cp);\n"
		"}\n"

		"vec3 point_color(vec2 tc, vec2 ofs)\n"
		"{\n"
		"	vec2 cc = floor(tc+ofs);\n"
		"	return texture(Tex, cc/textureSize(Tex, 0)).rgb;\n"
		"}\n"

		"vec3 voronoi(vec2 tc)\n"
		"{\n"
		"	float md = 2.0;\n"
		"	int mc = 9;\n"
		"	for(int c=0; c<9; ++c)\n"
		"	{\n"
		"		float d = dist(tc, offs[c]);\n"
		"		if(md > d)\n"
		"		{\n"
		"			md = d;\n"
		"			mc = c;\n"
		"		}\n"
		"	}\n"
		"	return mix(\n"
		"		point_color(tc, offs[mc])*mix(1.4, 0.5, md),\n"
		"		vec3(0, 0, 0),\n"
		"		pow(exp(1-md*128/sqrt(length(Scale))), 2.0)\n"
		"	);\n"
		"}\n"

		"void main(void)\n"
		"{\n"
		"	fragColor = voronoi(vertTexCoord);\n"
		"}\n"
		));
		fs.compile();
		fs.report_compile_error();

		attach(vs);
		attach(fs);
		link();
		report_link_error();

		gl.use(*this);

		gl.query_location(offset_loc, *this, "Offset");
		gl.query_location(scale_loc, *this, "Scale");
	}
};

class random_texture
 : public texture
{
public:
	random_texture(GLsizei width, GLsizei height)
	{
		std::vector<GLubyte> random_bytes(std::size_t(width*height*3));
		eagine::fill_with_random_bytes(random_bytes);

		gl.bind(GL.texture_2d, *this);
		gl.texture_min_filter(GL.texture_2d, GL.nearest);
		gl.texture_mag_filter(GL.texture_2d, GL.nearest);
		gl.texture_wrap(
			GL.texture_2d,
			GL.texture_wrap_s,
			GL.repeat
		);
		gl.texture_image_2d(
			GL.texture_2d,
			0, GL.rgb,
			width, height,
			0, GL.rgb,
			GL.unsigned_byte,
			const_memory_block{
				random_bytes.data(),
				random_bytes.size()
			}
		);
	}
};

class screen_shape
{
private:
	buffer positions;
	buffer coords;
public:
	vertex_array vao;

	screen_shape(const program& prog)
	{
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
		gl.query_location(va_c, prog, "TexCoord");
		gl.vertex_array_attrib_pointer(
			va_c,
			2, GL.float_,
			false, 0, nullptr
		);
		gl.enable_vertex_array_attrib(va_c);
	}
};

class example_mandelbrot
 : public example
{
private:
	random_texture tex;
	voronoi_program prog;
	screen_shape screen;


	GLfloat ofs_x_dir, ofs_y_dir, offset_x, offset_y;
	GLfloat scale_dir, scale, aspect;

	static constexpr const float min_scale = 1.0f;
	static constexpr const float max_scale = 100.0f;
public:
	example_mandelbrot(void)
	 : tex(256, 256)
	 , screen(prog)
	 , ofs_x_dir(1.f)
	 , ofs_y_dir(1.f)
	 , offset_x(-0.5f)
	 , offset_y(0.0f)
	 , scale_dir(1.f)
	 , scale(10.0f)
	 , aspect(1.0f)
	{

		gl.disable(GL.depth_test);
	}

	void pointer_motion(const example_state_view& state)
	override
	{
		if(state.pointer_dragging())
		{
			offset_x -= 2*state.norm_delta_pointer_x()*scale;
			offset_y -= 2*state.norm_delta_pointer_y()*scale;

			gl.uniform(prog.offset_loc, offset_x, offset_y);
		}
	}

	void pointer_scrolling(const example_state_view& state)
	override
	{

		scale *= float(std::pow(2,-state.norm_delta_pointer_z()));
		if(scale < min_scale) scale = min_scale;
		if(scale > max_scale) scale = max_scale;

		gl.uniform(prog.scale_loc, scale*aspect, scale);
	}

	void resize(const example_state_view& state)
	override
	{
		gl.viewport(state.width(), state.height());

		aspect = state.aspect();
		gl.uniform(prog.scale_loc, scale*aspect, scale);
	}

	void user_idle(const example_state_view& state)
	override
	{
		if(state.user_idle_time() > seconds_(1))
		{
			const float t = value(state.frame_duration())*60;

			scale *= std::pow(1.f+0.05f*t, scale_dir);
			if(scale < min_scale)
			{
				scale_dir *= -1.f;
				ofs_x_dir *= -1.f;
				ofs_y_dir *= ofs_x_dir;
				scale = min_scale;
			}
			if(scale > max_scale)
			{
				scale_dir *= -1.f;
				ofs_y_dir *= -1.f;
				ofs_x_dir *= ofs_y_dir;
				scale = max_scale;
			}

			offset_x += ofs_x_dir*t*scale/30;
			offset_y += ofs_y_dir*t*scale/30;

			gl.uniform(prog.offset_loc, offset_x, offset_y);
			gl.uniform(prog.scale_loc, scale*aspect, scale);
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
make_example(
	const example_args&,
	const example_params&,
	const example_state_view&
)
{
	return std::unique_ptr<example>(new example_mandelbrot());
}

void adjust_params(example_params& params)
{
	params.rand_seed(1234);
	params.depth_buffer(false);
	params.stencil_buffer(false);
}

bool is_example_param(const example_arg&) { return false; }

} // namespace oglplus
