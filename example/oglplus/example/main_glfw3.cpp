/**
 *  file. oglplus/example/main_glfw3.cpp
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

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#endif
#include <GLFW/glfw3.h>
#ifdef __clang__
#pragma clang diagnostic pop
#endif

#include <cmath>
#include <iostream>
#include <stdexcept>

static int example_scroll_y = 0;

void example_scroll_callback(GLFWwindow*, double /*x*/, double y)
{
	example_scroll_y += int(std::ceil(y));
}

void example_loop(
	GLFWwindow* window,
	oglplus::example_state& state,
	oglplus::example_wrapper& example
)
{
	int w = state.width();
	int h = state.height();
	double x, y;

	while(true)
	{
		glfwPollEvents();

		if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, 1);
			break;
		}

		if(glfwWindowShouldClose(window))
		{
			break;
		}

		glfwGetWindowSize(window, &w, &h);
		example.set_size(w, h);

		glfwGetCursorPos(window, &x, &y);
		example.set_mouse_pos(int(x), h-int(y));

		example.set_mouse_btn(
			1,
			glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) ==
			GLFW_PRESS
		);

		example.set_mouse_wheel(example_scroll_y);

		example.update();

		example.render();
		glfwSwapBuffers(window);

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

		glfwWindowHint(GLFW_DOUBLEBUFFER, GL_TRUE);
		glfwWindowHint(GLFW_RED_BITS, params.color_bits());
		glfwWindowHint(GLFW_BLUE_BITS, params.color_bits());
		glfwWindowHint(GLFW_GREEN_BITS, params.color_bits());
		glfwWindowHint(GLFW_ALPHA_BITS, params.alpha_bits());
		glfwWindowHint(GLFW_DEPTH_BITS, params.depth_bits());
		glfwWindowHint(GLFW_STENCIL_BITS, params.stencil_bits());

		glfwWindowHint(GLFW_SAMPLES, params.samples()/GLFW_DONT_CARE);

		GLFWwindow* window = glfwCreateWindow(
			state.width(), state.height(),
			"OGLplus example",
			NULL,
			NULL
		);

		if(!window)
		{
			errstr()
				<< "Failed to create GLFW window"
				<< std::endl;
			return 2;
		}
		else
		{
			glfwMakeContextCurrent(window);
			glfwSetWindowTitle(window, "OGLplus example");
			glfwSetWindowPos(
				window,
				params.window_x_pos(),
				params.window_y_pos()
			);
			glfwSetScrollCallback(window, example_scroll_callback);

			oglplus::api_initializer gl_api_init;

			std::srand(params.rand_seed());
			state.set_depth(16);
			oglplus::example_wrapper example(args, params, state);

			example_loop(window, state, example);
		}
	}
	return 0;
}

