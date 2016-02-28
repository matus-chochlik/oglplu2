/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef UTILS_OGLPLUS_OS_CONTEXT_GLFW3_1107121519_HPP
#define UTILS_OGLPLUS_OS_CONTEXT_GLFW3_1107121519_HPP

#include <GLFW/glfw3.h>
#include <stdexcept>

namespace oglplus {

class offscreen_context_glfw3
{
private:
	::GLFWwindow* window;
public:
	offscreen_context_glfw3(int /*ver_major*/, int /*ver_minor*/)
	{
		if(!glfwInit())
		{
			throw
			std::runtime_error("Failed to initialize GLFW3.");
		}

		window = glfwCreateWindow(64, 64, "", NULL, NULL);

		if(!window)
		{
			glfwTerminate();
			throw
			std::runtime_error("Failed to create GLFW3 window.");
		}
		glfwMakeContextCurrent(window);
	}

	~offscreen_context_glfw3(void)
	noexcept
	{
		try { glfwTerminate(); }
		catch(...) { }
	}
};

} // namespace oglplus

#endif
