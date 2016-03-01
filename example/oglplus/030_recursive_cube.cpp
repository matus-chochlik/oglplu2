/**
 *  example oglplus/018_recursive_cube.cpp
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

#include <oglplus/math/vector.hpp>
#include <oglplus/math/matrix.hpp>
#include <oglplus/math/matrix_ctrs.hpp>

#include "example.hpp"
#include <iostream>

namespace oglplus {

static constants  GL;
static operations gl;

class example_program
 : public program
{
public:
	uniform_location projection, modelview, light_pos, cube_tex;

	example_program(void)
	{
		shader vs(GL.vertex_shader);

		vs.source(glsl_literal(
		"#version 140\n"

		"uniform mat4 Projection;"
		"uniform mat4 Modelview;"
		"uniform vec3 LightPos;"

		"in vec4 Position;\n"
		"in vec3 Normal;\n"
		"in vec2 TexCoord;\n"

		"out vec3 vertNormal;\n"
		"out vec3 vertLightDir;\n"
		"out vec2 vertTexCoord;\n"

		"void main(void)\n"
		"{\n"
		"	gl_Position = Modelview*Position;\n"
		"	vertNormal = mat3(Modelview)*Normal;\n"
		"	vertLightDir = LightPos - gl_Position.xyz;\n"
		"	vertTexCoord = TexCoord;\n"
		"	gl_Position = Projection*gl_Position;\n"
		"}\n"
		));
		vs.compile();
		vs.report_compile_error();

		shader fs(GL.fragment_shader);

		fs.source(glsl_literal(
		"#version 140\n"

		"uniform sampler2D CubeTex;"
		"in vec3 vertNormal;\n"
		"in vec3 vertLightDir;\n"
		"in vec2 vertTexCoord;\n"
		"out vec4 fragColor;\n"

		"void main(void)\n"
		"{\n"
		"	float d=0.3*dot(vertNormal, normalize(vertLightDir));\n"
		"	float i=0.6 + max(d, 0.0);\n"
		"	fragColor = texture(CubeTex, vertTexCoord)*i;\n"
		"}\n"
		));
		fs.compile();
		fs.report_compile_error();

		attach(vs);
		attach(fs);
		link();
		report_link_error();

		gl.use(*this);

		gl.query_location(projection, *this, "Projection");
		gl.query_location(modelview, *this, "Modelview");
		gl.query_location(light_pos, *this, "LightPos");
		gl.query_location(cube_tex, *this, "CubeTex");
	}
};

class cube_model
{
private:
	buffer positions;
	buffer normals;
	buffer texcoords;
public:
	vertex_array vao;

	cube_model(const program& prog)
	{
		const GLfloat v[8][3] = {
			{-0.5f, -0.5f, -0.5f},
			{+0.5f, -0.5f, -0.5f},
			{-0.5f, +0.5f, -0.5f},
			{+0.5f, +0.5f, -0.5f},
			{-0.5f, -0.5f, +0.5f},
			{+0.5f, -0.5f, +0.5f},
			{-0.5f, +0.5f, +0.5f},
			{+0.5f, +0.5f, +0.5f}
		};

		const GLint f[6][2][3] = {
			{{0, 4, 2}, {2, 4, 6}},
			{{5, 1, 7}, {7, 1, 3}},
			{{0, 1, 4}, {4, 1, 5}},
			{{6, 7, 2}, {2, 7, 3}},
			{{1, 0, 3}, {3, 0, 2}},
			{{4, 5, 6}, {6, 5, 7}}
		};

		gl.bind(vao);
	
		const GLuint vertex_count = 6 * 2 * 3;

		// positions
		GLfloat vertex_data[vertex_count * 3];

		for(GLuint fi=0;fi!=6;++fi)
		for(GLuint ti=0;ti!=2;++ti)
		for(GLuint vi=0;vi!=3;++vi)
		{
			for(GLuint ci=0;ci!=3;++ci)
			{
				vertex_data[fi*2*3*3+ti*3*3+vi*3+ci] =
					v[f[fi][ti][vi]][ci];
			}
		}

		gl.bind(GL.array_buffer, positions);
		gl.buffer_data(GL.array_buffer, vertex_data, GL.static_draw);

		gl.vertex_array_attrib_pointer(
			vertex_attrib_location(0),
			3, GL.float_,
			false, 0, nullptr
		);
		gl.enable_vertex_array_attrib(vertex_attrib_location(0));

		vertex_attrib_location va_p;
		gl.query_location(va_p, prog, "Position");
		gl.vertex_array_attrib_pointer(
			va_p, 3, GL.float_,
			false, 0, nullptr
		);
		gl.enable_vertex_array_attrib(va_p);

		// normals
		const GLfloat n[6][3] = {
			{-1.0f,  0.0f,  0.0f},
			{ 1.0f,  0.0f,  0.0f},
			{ 0.0f, -1.0f,  0.0f},
			{ 0.0f,  1.0f,  0.0f},
			{ 0.0f,  0.0f, -1.0f},
			{ 0.0f,  0.0f,  1.0f}
		};
		for(GLuint fi=0;fi!=6;++fi)
		for(GLuint vi=0;vi!=6;++vi)
		{
			for(GLuint ci=0;ci!=3;++ci)
			{
				vertex_data[(fi*6+vi)*3+ci] = n[fi][ci];
			}
		}

		gl.bind(GL.array_buffer, normals);
		gl.buffer_data(GL.array_buffer, vertex_data, GL.static_draw);

		vertex_attrib_location va_n;
		gl.query_location(va_n, prog, "Normal");
		gl.vertex_array_attrib_pointer(
			va_n, 3, GL.float_,
			false, 0, nullptr
		);
		gl.enable_vertex_array_attrib(va_n);

		// tex-coords
		const GLfloat c[6][2] = {
			{0.0f, 0.0f},
			{1.0f, 0.0f},
			{0.0f, 1.0f},
			{0.0f, 1.0f},
			{1.0f, 0.0f},
			{1.0f, 1.0f}
		};

		for(GLuint fi=0;fi!=6;++fi)
		{
			for(GLuint vi=0;vi!=6;++vi)
			{
				for(GLuint ci=0;ci!=2;++ci)
				{
					vertex_data[(fi*6+vi)*2+ci] = c[vi][ci];
				}
			}
		}

		gl.bind(GL.array_buffer, texcoords);
		gl.buffer_data(
			GL.array_buffer,
			buffer_data_spec{vertex_data, vertex_count * 2},
			GL.static_draw
		);

		vertex_attrib_location va_c;
		gl.query_location(va_c, prog, "TexCoord");
		gl.vertex_array_attrib_pointer(
			va_c, 2, GL.float_,
			false, 0, nullptr
		);
		gl.enable_vertex_array_attrib(va_c);
	}
};

class rendered_textures
{
public:
	texture_array<2> texs;
	renderbuffer_array<2> rbos;
	framebuffer_array<2> fbos;

	rendered_textures(GLsizei tex_side)
	{

		for(GLuint i=0; i<2u; ++i)
		{
			texture_name tex = texs[i];

			gl.active_texture(GL.texture0+i);
			gl.bind(GL.texture_2d, tex);
			gl.texture_min_filter(GL.texture_2d, GL.linear);
			gl.texture_mag_filter(GL.texture_2d, GL.linear);
			gl.texture_image_2d(
				GL.texture_2d,
				0,
				GL.rgb, 
				tex_side, tex_side,
				0,
				GL.rgb,
				GL.unsigned_byte,
				const_memory_block()
			);

			renderbuffer_name rbo = rbos[i];

			gl.bind(GL.renderbuffer, rbo);
			gl.renderbuffer_storage(
				GL.renderbuffer,
				GL.depth_component,
				tex_side, tex_side
			);

			framebuffer_name fbo = fbos[i];

			gl.bind(GL.draw_framebuffer, fbo);
			gl.framebuffer_texture_2d(
				GL.draw_framebuffer,
				GL.color_attachment0,
				GL.texture_2d,
				tex, 0
			);
			gl.framebuffer_renderbuffer(
				GL.draw_framebuffer,
				GL.depth_attachment,
				GL.renderbuffer,
				rbo
			);

			gl.viewport(tex_side, tex_side);
			gl.clear(GL.color_buffer_bit);
		}

		gl.bind(GL.draw_framebuffer, default_framebuffer);
		gl.bind(GL.renderbuffer, no_renderbuffer);
	}
};

class example_recursive_cube
 : public example
{
private:
	const GLsizei tex_side;
	rendered_textures rnd_tex;
	example_program prog;
	cube_model cube;

	unsigned current_buf;
	radians_t<float> rad;
public:
	example_recursive_cube(void)
	 : tex_side(512)
	 , rnd_tex(tex_side)
	 , cube(prog)
	 , current_buf(0)
	 , rad(0.0f)
	{
		gl.clear_color(0.8f, 0.8f, 0.8f, 0.0f);
		gl.clear_depth(1.0f);

		gl.enable(GL.depth_test);
		gl.enable(GL.cull_face);
		gl.cull_face(GL.back);
		gl.front_face(GL.ccw);
	}

	void resize(const example_state_view& state)
	override
	{
		gl.viewport(state.width(), state.height());
	}

	bool continue_running(const example_state_view& state)
	override
	{
		return state.user_idle_time() < seconds_(20);
	}

	void render(const example_state_view& state)
	override
	{
		rad += radians_(0.5f*state.frame_duration().value());

		current_buf = (current_buf+1)%2;

		gl.uniform(
			prog.light_pos,
			vec3(cos(rad)*4, sin(rad)*4, 8)
		);

		gl.uniform(
			prog.modelview,
			matrix_rotation_x(rad*1)*
			matrix_rotation_y(rad*2)*
			matrix_rotation_z(rad*3)
		);

		// draw into the texture
		gl.bind(GL.draw_framebuffer, rnd_tex.fbos[current_buf]);
		gl.viewport(tex_side, tex_side);

		GLfloat s = 0.5f;

		gl.uniform(
			prog.projection,
			oglplus::matrix_perspective(-s,+s, -s,+s, 1.0f, 5)*
			oglplus::matrix_translation(0,0,-2)
		);

		gl.clear(GL.color_buffer_bit|GL.depth_buffer_bit);
		gl.draw_arrays(GL.triangles, 0, 6 * 2 * 3);

		// draw on screen
		gl.bind(GL.draw_framebuffer, default_framebuffer);
		gl.viewport(state.width(), state.height());

		gl.uniform(prog.cube_tex, GLint(current_buf));

		GLfloat h = 0.55f;
		GLfloat w = h*state.aspect();

		gl.uniform(
			prog.projection,
			oglplus::matrix_perspective(-w,+w, -h,+h, 1, 3)*
			oglplus::matrix_translation(0,0,-2)
		);

		gl.clear(GL.color_buffer_bit|GL.depth_buffer_bit);
		gl.draw_arrays(GL.triangles, 0, 6 * 2 * 3);

	}
};

std::unique_ptr<example>
make_example(
	const example_args&,
	const example_params&,
	const example_state_view&
)
{
	return std::unique_ptr<example>(new example_recursive_cube());
}

void adjust_params(example_params& params)
{
	params.depth_buffer(true);
	params.stencil_buffer(false);
}

bool is_example_param(const example_arg&) { return false; }

} // namespace oglplus
