/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef UTILS_OGLPLUS_OS_CONTEXT_GLFW_1107121519_HPP
#define UTILS_OGLPLUS_OS_CONTEXT_GLFW_1107121519_HPP

#include <GL/glfw.h>
#include <stdexcept>

namespace oglplus {

class offscreen_context_glfw
{
private:
	::GLFWwindow* window;
public:
	offscreen_context_glfw(int /*ver_major*/, int /*ver_minor*/)
	{
		if(!glfwInit())
		{
			throw
			std::runtime_error("Failed to initialize GLFW.");
		}

		if(!glfwOpenWindow(64, 64, 8, 8, 8, 8, 24, 8, GLFW_WINDOW))
		{
			glfwTerminate();
			throw
			std::runtime_error("Failed to create GLFW window.");
		}
	}

	~offscreen_context_glfw(void)
	noexcept
	{
		try { glfwTerminate(); }
		catch(...) { }
	}
};

} // namespace oglplus

#endif
