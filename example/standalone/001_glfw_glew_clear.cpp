/**
 *  @example standalone/001_glfw_glew_clear.cpp
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

#include <eagine/scope_exit.hpp>

#include <GL/glfw.h>

#include <iostream>
#include <stdexcept>

static
void run_loop(int width, int height)
{
	using namespace oglplus;

	constants GL;
	operations gl;

	gl.viewport(0, 0, width, height);
	gl.clear_color(0.3f, 0.3f, 0.9f, 0.0f);
	gl.clear_depth(1.0f);

	while(true)
	{
		gl.clear(GL.color_buffer_bit|GL.depth_buffer_bit);

		glfwSwapBuffers();

		int new_width, new_height;
		glfwGetWindowSize(&new_width, &new_height);

		if((width != new_width) || (height != new_height))
		{
			width = new_width;
			height = new_height;

			gl.viewport(width, height);
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
		auto cleanup_glfw = [](void) { glfwTerminate(); };
		eagine::on_scope_exit<> ensure_glfw_cleanup(cleanup_glfw);

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
