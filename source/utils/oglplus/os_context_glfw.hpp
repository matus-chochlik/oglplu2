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
#include "os_context_common.hpp"

namespace oglplus {

class offscreen_context_glfw
{
public:
	offscreen_context_glfw(const offscreen_context_params& p)
	{
		if(!glfwInit())
		{
			throw
			std::runtime_error("Failed to initialize GLFW.");
		}

		if(!glfwOpenWindow(
			p.width, p.height,
			8, 8, 8, 8, 24, 8,
			GLFW_WINDOW
		))
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
