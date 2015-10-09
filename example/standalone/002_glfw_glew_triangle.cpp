/**
 *  @example standalone/001_glfw_glew_triangle.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <GL/glew.h>

#include <oglplus/context.hpp>
#include <oglplus/enum_values.hpp>

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

#ifdef GL_EXT_direct_state_access
	gl.load_identity(GL.projection);
	gl.ortho(GL.projection, -w,+w, -h,+h, 0,1);
#else
	gl.matrix_mode(GL.projection);
	gl.load_identity();
	gl.ortho(-w,+w, -h,+h, 0,1);
#endif
}

static
void run_loop(int width, int height)
{
	using namespace oglplus;

	gl.clear_color(0.4f, 0.4f, 0.4f, 0.0f);

	handle_resize(width, height);

	int deg = 0;

	while(true)
	{
		gl.clear(GL.color_buffer_bit);

#ifdef GL_EXT_direct_state_access
		gl.load_identity(GL.modelview);
		gl.rotate_f(GL.modelview, degrees(deg++), 0, 0, 1);
#else
		gl.matrix_mode(GL.modelview);
		gl.load_identity();
		gl.rotate_f(degrees(deg++), 0, 0, 1);
#endif

		gl.begin(GL.triangles);
			gl.color_f( 1, 0, 0);
			gl.vertex_f( 0, 1);

			gl.color_f( 0, 1, 0);
			gl.vertex_f(-0.866f,-0.5f);

			gl.color_f( 0, 0, 1);
			gl.vertex_f( 0.866f,-0.5f);
		gl.end();

		gl.begin(GL.line_loop);
			gl.color_f( 0, 0, 0);
			gl.vertex_f( 0, 1);

			gl.vertex_f(-0.866f,-0.5f);

			gl.vertex_f( 0.866f,-0.5f);
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

		if(!glfwOpenWindow(width, height, 8, 8, 8, 8, 24, 8, GLFW_WINDOW))
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
		std::cerr
			<< "OpenGL error: "
			<< gle.what()
			<< " in "
			<< gle.info().gl_function_name()
			<< std::endl;
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
