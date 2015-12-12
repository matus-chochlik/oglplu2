/**
 *  file. oglplus/glfw_main.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/gl.hpp>
#include "example_wrapper.hpp"

#include <eagine/scope_exit.hpp>
#include <eagine/program_args.hpp>

#include <GL/glfw.h>

#include <iostream>
#include <stdexcept>

int example_main(
	const eagine::program_args& args,
	oglplus::example_params& params,
	oglplus::example_state& state
)
{
	auto errstr = [&args](void) -> std::ostream&
	{
		return std::cerr
			<< args.command()
			<< ": ";
	};

	if(!glfwInit())
	{
		errstr()
			<< "GLFW initialization error."
			<< std::endl;
		return 2;
	}
	else
	{
		auto ensure_glfw_cleanup = eagine::finally(glfwTerminate);

		if(!glfwOpenWindow(
			state.width(),
			state.height(),
			params.color_bits(),
			params.color_bits(),
			params.color_bits(),
			params.alpha_bits(),
			params.depth_bits(),
			params.stencil_bits(),
			GLFW_WINDOW
		))
		{
			errstr()
				<< "Failed to create GLFW window"
				<< std::endl;
			return 2;
		}
		else
		{
			glfwSetWindowTitle("OGLplus example");

			oglplus::api_initializer gl_api_init;

			oglplus::example_wrapper example(params, state);

			int width = state.width();
			int height = state.height();

			while(true)
			{
				if(!example.next_frame()) break;

				example.render();

				glfwSwapBuffers();

				glfwGetWindowSize(&width, &height);

				example.set_size(width, height);

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
	}
	return 0;
}

