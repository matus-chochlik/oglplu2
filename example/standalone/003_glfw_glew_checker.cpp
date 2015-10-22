/**
 *  @example standalone/003_glfw_glew_checker.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <GL/glew.h>

#include <oglplus/context.hpp>
#include <oglplus/enum/values.hpp>
#include <oglplus/glsl/string_ref.hpp>
#include <oglplus/error/format.hpp>
#include <oglplus/utils/make_view.hpp>
#include <oglplus/math/vector.hpp>

#include <eagine/scope_exit.hpp>

#include <GL/glfw.h>

#include <iostream>
#include <stdexcept>

static oglplus::enum_values GL;
static oglplus::context gl;

static
void handle_resize(int width, int height)
{
	gl.viewport(0, 0, width, height);
	GLfloat asp = GLfloat(width)/height;

	GLfloat h = 2;
	GLfloat w = h*asp;

	gl.matrix_mode(GL.projection);
	gl.load_identity();
	gl.ortho(-w,+w, -h,+h, 0,1);
}

static
void run_loop(int width, int height)
{
	using namespace oglplus;

	shader fs(GL.fragment_shader);

	gl.shader_source(fs, glsl_literal(
	"#version 120\n"

	"uniform vec3 Color1;\n"
	"uniform vec3 Color2;\n"

	"float checker(vec2 c)\n"
	"{\n"
	"	return mod(int(c.x*8)+int(c.y*8), 2);\n"
	"}\n"

	"void main(void)\n"
	"{\n"
	"	float c = checker(gl_TexCoord[0].st);\n"
	"	gl_FragColor = vec4(mix(Color1, Color2, c),1);\n"
	"}\n"
	));
	gl.compile_shader(fs);

	program prog;

	gl.attach_shader(prog, fs);
	gl.link_program(prog);
	gl.use_program(prog);

	gl.uniform(uniform<GLfloat>(prog, "Color1"), 0.2f, 0.2f, 0.2f);
	gl.uniform(uniform<GLfloat[3]>(prog, "Color2"), 1, make_view({0.4f, 0.4f, 0.6f}));

	gl.clear_color(vec4(0.6f, 0.7f, 0.6f, 0.0f));

	handle_resize(width, height);

	int deg = 0;

	while(true)
	{
		gl.clear(GL.color_buffer_bit);

		gl.matrix_mode(GL.modelview);
		gl.load_identity();
		gl.rotate_f(degrees(deg++), 0, 0, 1);

		gl.begin(GL.quads);
			gl.tex_coord_i( 0, 0);
			gl.vertex_i(-1,-1);

			gl.tex_coord_i( 1, 0);
			gl.vertex_i( 1,-1);

			gl.tex_coord_i( 1, 1);
			gl.vertex_i( 1, 1);

			gl.tex_coord_i( 0, 1);
			gl.vertex_i(-1, 1);
		gl.end();

		gl.begin(GL.line_loop);
			gl.color_f( 1, 1, 1);

			gl.vertex_i(-1,-1);

			gl.vertex_i( 1,-1);

			gl.vertex_i( 1, 1);

			gl.vertex_i(-1, 1);
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
			"with enum parameter: %(gl_enum_value)\n"
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
