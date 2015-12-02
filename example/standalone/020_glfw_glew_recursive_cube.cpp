/**
 *  @example standalone/020_glfw_glew_recursive_cube.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <GL/glew.h>

#include <oglplus/operations.hpp>
#include <oglplus/constants.hpp>
#include <oglplus/constant_defs.hpp>
#include <oglplus/glsl/string_ref.hpp>
#include <oglplus/error/format.hpp>

#include <oglplus/math/vector.hpp>
#include <oglplus/math/matrix.hpp>
#include <oglplus/math/matrix_ctrs.hpp>

#include <eagine/scope_exit.hpp>

#include <GL/glfw.h>

#include <iostream>
#include <stdexcept>
#include <cmath>

static oglplus::constants GL;
static oglplus::operations gl;

static
void run_loop(int width, int height)
{
	using namespace oglplus;

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
	"	float d = 0.3*dot(vertNormal, normalize(vertLightDir));\n"
	"	float i = 0.6 + max(d, 0.0);\n"
	"	fragColor = texture(CubeTex, vertTexCoord)*i;\n"
	"}\n"
	));
	fs.compile();

	program prog;

	prog.attach(vs);
	prog.attach(fs);
	prog.link();

	gl.use_program(prog);

	uniform_location projection, modelview, light_pos, cube_tex;

	gl.query_location(projection, prog, "Projection");
	gl.query_location(modelview, prog, "Modelview");
	gl.query_location(light_pos, prog, "LightPos");
	gl.query_location(cube_tex, prog, "CubeTex");

	vertex_array vao;

	gl.bind(vao);

	// positions
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

	const GLuint vertex_count = 6 * 2 * 3;
	GLfloat cube_vertices[vertex_count * 3];

	for(GLuint fi=0;fi!=6;++fi)
	{
		for(GLuint ti=0;ti!=2;++ti)
		{
			for(GLuint vi=0;vi!=3;++vi)
			{
				for(GLuint ci=0;ci!=3;++ci)
				{
					cube_vertices[fi*2*3*3+ti*3*3+vi*3+ci] =
						v[f[fi][ti][vi]][ci];
				}
			}
		}
	}

	buffer pos;
	gl.bind(GL.array_buffer, pos);
	gl.buffer_data(GL.array_buffer, cube_vertices, GL.static_draw);

	gl.vertex_array_attrib_pointer(
		vertex_attrib_location(0),
		3, GL.float_,
		false, 0, nullptr
	);
	gl.enable_vertex_array_attrib(vertex_attrib_location(0));

	vertex_attrib_location va_p;
	gl.query_location(va_p, prog, "Position");
	gl.vertex_array_attrib_pointer(va_p, 3, GL.float_, false, 0, nullptr);
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
	GLfloat cube_normals[vertex_count * 3];
	for(GLuint fi=0;fi!=6;++fi)
	{
		for(GLuint vi=0;vi!=6;++vi)
		{
			for(GLuint ci=0;ci!=3;++ci)
			{
				cube_normals[(fi*6+vi)*3+ci] = n[fi][ci];
			}
		}
	}

	buffer nml;
	gl.bind(GL.array_buffer, nml);
	gl.buffer_data(GL.array_buffer, cube_normals, GL.static_draw);

	vertex_attrib_location va_n;
	gl.query_location(va_n, prog, "Normal");
	gl.vertex_array_attrib_pointer(va_n, 3, GL.float_, false, 0, nullptr);
	gl.enable_vertex_array_attrib(va_n);

	// face-coords
	const GLfloat c[6][2] = {
		{0.0f, 0.0f},
		{1.0f, 0.0f},
		{0.0f, 1.0f},
		{0.0f, 1.0f},
		{1.0f, 0.0f},
		{1.0f, 1.0f}
	};

	GLfloat cube_coords[vertex_count * 2];

	for(GLuint fi=0;fi!=6;++fi)
	{
		for(GLuint vi=0;vi!=6;++vi)
		{
			for(GLuint ci=0;ci!=2;++ci)
			{
				cube_coords[(fi*6+vi)*2+ci] = c[vi][ci];
			}
		}
	}

	buffer crd;
	gl.bind(GL.array_buffer, crd);
	gl.buffer_data(GL.array_buffer, cube_coords, GL.static_draw);

	vertex_attrib_location va_c;
	gl.query_location(va_c, prog, "TexCoord");
	gl.vertex_array_attrib_pointer(va_c, 2, GL.float_, false, 0, nullptr);
	gl.enable_vertex_array_attrib(va_c);

	gl.clear_color(0.8f, 0.8f, 0.8f, 0.0f);
	gl.clear_depth(1.0f);

	GLsizei tex_side = 512;
	texture_array<2> texs;
	renderbuffer_array<2> rbos;
	framebuffer_array<2> fbos;

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

	gl.enable(GL.depth_test);
	gl.enable(GL.cull_face);
	// TODO
	//gl.cull_face(GL.back);
	//gl.front_face(GL.ccw);

	unsigned current_buf = 0;
	float rad = 0.0f;

	while(true)
	{
		current_buf = (current_buf+1)%2;

		gl.uniform(
			light_pos,
			vec3(std::cos(rad)*4, std::sin(rad)*4, 8)
		);

		gl.uniform(
			modelview,
			matrix_rotation_x(eagine::radians(rad*1))*
			matrix_rotation_y(eagine::radians(rad*2))*
			matrix_rotation_z(eagine::radians(rad*3))
		);

		rad += 0.01f;

		// draw into the texture
		gl.bind(GL.draw_framebuffer, fbos[current_buf]);
		gl.viewport(tex_side, tex_side);

		GLfloat s = 0.5f;

		gl.uniform(
			projection,
			oglplus::matrix_perspective(-s,+s, -s,+s, 1.0f, 5)*
			oglplus::matrix_translation(0,0,-2)
		);

		gl.clear(GL.color_buffer_bit|GL.depth_buffer_bit);
		gl.draw_arrays(GL.triangles, 0, 6 * 2 * 3);

		// draw on screen
		gl.bind(GL.draw_framebuffer, default_framebuffer);
		gl.viewport(width, height);

		gl.uniform(cube_tex, GLint(current_buf));

		GLfloat asp = GLfloat(width)/height;

		GLfloat h = 0.55f;
		GLfloat w = h*asp;

		gl.uniform(
			projection,
			oglplus::matrix_perspective(-w,+w, -h,+h, 1, 3)*
			oglplus::matrix_translation(0,0,-2)
		);

		gl.clear(GL.color_buffer_bit|GL.depth_buffer_bit);
		gl.draw_arrays(GL.triangles, 0, 6 * 2 * 3);

		glfwSwapBuffers();

		glfwGetWindowSize(&width, &height);

		if(glfwGetKey(GLFW_KEY_ESC))
		{
			glfwCloseWindow();
			break;
		}
		if(!glfwGetWindowParam(GLFW_OPENED))
		{
			break;
		}
	}
}

static
void init_and_run(void)
{
	if(!glfwInit())
	{
		throw std::runtime_error("GLFW initialization error");
	}
	else
	{
		auto ensure_glfw_cleanup = eagine::finally(glfwTerminate);

		int width = 800, height = 600;

		if(!glfwOpenWindow(width, height, 8, 8, 8, 0, 24, 0, GLFW_WINDOW))
		{
			throw std::runtime_error("Error creating GLFW window");
		}
		else
		{
			glfwSetWindowTitle("OGLplus example");

			glewExperimental = GL_TRUE;
			GLenum init_result = glewInit();
			glGetError();
			if(init_result != GLEW_OK)
			{
				throw std::runtime_error(
					"OpenGL/GLEW initialization error."
				);
			}
			else
			{
				run_loop(width, height);
			}
		}
	}
}

int main(void)
{
	try { init_and_run(); return 0; }
	catch(oglplus::error& gle)
	{
		oglplus::format_error(
			gle,
			"OpenGL error\n"
			"in GL function: %(gl_function_name)\n"
			"with object: %(gl_object)\n"
			"with enum parameter: %(gl_enum_value)\n"
			"with index: %(gl_index)\n"
			"from source file: %(source_file)\n"
			"%(message)\n",
			std::cerr
		) << std::endl;
	}
	catch(std::runtime_error& sre)
	{
		std::cerr
			<< "Runtime error: "
			<< sre.what()
			<< std::endl;
	}
	catch(std::exception& se)
	{
		std::cerr
			<< "Unknown error: "
			<< se.what()
			<< std::endl;
	}
	return 1;
}
