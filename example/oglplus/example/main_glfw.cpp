/**
 *  file. oglplus/example/main_glfw.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/gl_fixed.hpp>
#include "wrapper.hpp"
#include "state.hpp"

#include <eagine/scope_exit.hpp>
#include <eagine/program_args.hpp>

#include <GL/glfw.h>

#include <iostream>
#include <stdexcept>

void example_loop(
	oglplus::example_state& state,
	oglplus::example_wrapper& example
)
{
	int w = state.width();
	int h = state.height();
	int x, y;

	while(true)
	{
		if(!glfwGetWindowParam(GLFW_OPENED))
		{
			break;
		}

		if(glfwGetKey(GLFW_KEY_ESC))
		{
			glfwCloseWindow();
			break;
		}

		glfwGetWindowSize(&w, &h);
		example.set_size(w, h);

		glfwGetMousePos(&x, &y);
		example.set_mouse_pos(x, h-y);

		example.set_mouse_btn(
			1,
			glfwGetMouseButton(GLFW_MOUSE_BUTTON_1) == GLFW_PRESS
		);

		example.set_mouse_wheel(glfwGetMouseWheel());

		example.update();

		example.render();
		glfwSwapBuffers();

		if(!example.next_frame())
		{
			break;
		}
	}
}

int example_main(
	oglplus::example_args& args,
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
			glfwSetWindowPos(
				params.window_x_pos(),
				params.window_y_pos()
			);

			oglplus::api_initializer gl_api_init;

			std::srand(params.rand_seed());
			state.set_depth(16);
			oglplus::example_wrapper example(args, params, state);

			example_loop(state, example);
		}
	}
	return 0;
}

