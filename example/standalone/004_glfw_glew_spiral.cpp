/**
 *  @example standalone/004_glfw_glew_spiral.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <GL/glew.h>

#include <oglplus/context.hpp>
#include <oglplus/enum_values.hpp>
#include <oglplus/glsl/string_ref.hpp>
#include <oglplus/error/format.hpp>
#include <oglplus/utils/make_view.hpp>

#include <eagine/scope_exit.hpp>

#include <GL/glfw.h>

#include <iostream>
#include <stdexcept>
#include <cmath>

static oglplus::enum_values GL;
static oglplus::context gl;

static
void handle_resize(int width, int height)
{
	gl.viewport(0, 0, width, height);
	GLfloat asp = GLfloat(width)/height;

	GLfloat h = 1.618f;
	GLfloat w = h*asp;

	gl.matrix_mode(GL.projection);
	gl.load_identity();
	gl.ortho(-w,+w, -h,+h, 0,1);
}

static
void run_loop(int width, int height)
{
	using namespace oglplus;

	shader vs(GL.vertex_shader);

	gl.shader_source(vs, glsl_literal(
	"#version 120\n"

	"attribute vec2 Coord;\n"
	"attribute vec3 Color1;\n"
	"attribute vec3 Color2;\n"
	"varying vec2 vertCoord;\n"
	"varying vec3 vertColor1;\n"
	"varying vec3 vertColor2;\n"

	"void main(void)\n"
	"{\n"
	"	gl_Position = ftransform();\n"
	"	vertCoord = Coord;\n"
	"	vertColor1 = Color1;\n"
	"	vertColor2 = Color2;\n"
	"}\n"
	));

	shader fs(GL.fragment_shader);

	gl.shader_source(fs, glsl_literal(
	"#version 120\n"

	"varying vec2 vertCoord;\n"
	"varying vec3 vertColor1;\n"
	"varying vec3 vertColor2;\n"

	"float spiral(vec2 c)\n"
	"{\n"
	"	return max(sign(mod(8*(sqrt(c.x)+c.y), 2)-1),0);\n"
	"}\n"

	"void main(void)\n"
	"{\n"
	"	gl_FragColor = vec4(mix(\n"
	"		vertColor1,\n"
	"		vertColor2,\n"
	"		spiral(vertCoord)\n"
	"	), 1);\n"
	"}\n"
	));

	gl.compile(fs);

	program p;

	gl.attach_shader(p, vs);
	gl.attach_shader(p, fs);
	gl.link(p);
	gl.use(p);

	vertex_attrib<GLfloat[2]> coord(p, "Coord");
	vertex_attrib<GLfloat> color1(p, "Color1");
	vertex_attrib<GLfloat> color2(p, "Color2");

	gl.clear_color(0.7f, 0.7f, 0.6f, 0.0f);

	handle_resize(width, height);

	int deg = 0;

	const auto twopi = std::atan(1)*8;
	const int nseg = 72;
	const float sstep = float(twopi/nseg);
	const float spart = float(1.0f/nseg);
	const float z = 0, o = 1;
	float a;

	while(true)
	{
		using std::cos;
		using std::sin;

		gl.clear(GL.color_buffer_bit);

		gl.matrix_mode(GL.modelview);
		gl.load_identity();
		gl.rotate_f(degrees(deg+=2), 0, 0, 1);

		gl.begin(GL.triangle_strip);
		for(int s=0; s<nseg; ++s)
		{
			a = (s+0)*spart;

			gl.vertex_attrib(coord, make_view({z, a}), false);
			gl.vertex_attrib(color1, 0.2f, 0.1f, 0.1f, false);
			gl.vertex_attrib(color2, 0.3f, 0.1f, 0.2f, false);
			gl.vertex_f(0, 0);

			gl.vertex_attrib(coord, make_view({o, a}), false);
			gl.vertex_attrib(color1, 0.0f, 0.0f, 0.0f, false);
			gl.vertex_attrib(color2, 0.9f, 0.3f, 0.4f, false);
			gl.vertex_f(cos((s+0)*sstep), sin((s+0)*sstep));

			a = (s+1)*spart;

			gl.vertex_attrib(coord, make_view({z, a}), false);
			gl.vertex_attrib(color1, 0.2f, 0.1f, 0.1f, false);
			gl.vertex_attrib(color2, 0.3f, 0.1f, 0.2f, false);
			gl.vertex_f(0, 0);

			gl.vertex_attrib(coord, make_view({o, a}), false);
			gl.vertex_attrib(color1, 0.0f, 0.0f, 0.0f, false);
			gl.vertex_attrib(color2, 0.9f, 0.3f, 0.4f, false);
			gl.vertex_f(cos((s+1)*sstep), sin((s+1)*sstep));
		}
		gl.end();

		gl.vertex_attrib(color1, 0.2f, 0.1f, 0.1f, true);

		const GLfloat c2[3] = {0.3f, 0.1f, 0.2f};
		gl.vertex_attrib(color2, c2, true);

		gl.begin(GL.line_loop);
		for(int s=0; s<nseg; ++s)
		{
			gl.vertex_attrib(coord, make_view({o, s*spart}), false);
			gl.vertex_f(cos(s*sstep), sin(s*sstep));
		}
		gl.end();

		glfwSwapBuffers();

		int new_width, new_height;
		glfwGetWindowSize(&new_width, &new_height);

		if((width != new_width) || (height != new_height))
		{
			width = new_width;
			height = new_height;

			handle_resize(width, height);
		}
		

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

		if(!glfwOpenWindow(width, height, 8, 8, 8, 0, 0, 0, GLFW_WINDOW))
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
			"with enum parameter: %(enum_value)\n"
			"from source file: %(source_file)\n"
			"%(message)",
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
