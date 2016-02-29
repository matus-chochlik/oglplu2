/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef UTILS_OGLPLUS_OS_CONTEXT_COMMON_1107121519_HPP
#define UTILS_OGLPLUS_OS_CONTEXT_COMMON_1107121519_HPP

#include <oglplus/config/site.hpp>

namespace oglplus {

struct offscreen_context_params
{
	int argc;
	char** argv;
	const char* title;
	int version_major;
	int version_minor;
	int width;
	int height;

	static
	char** fake_argv(void)
	noexcept
	{
		static char name[64] = {'<','N','/','A','>','\0'};
		static char* av[2] = {name, nullptr};
		return av;
	}

	offscreen_context_params(void)
	 : argc(1)
	 , argv(fake_argv())
	 , title("")
	 , version_major(OGLPLUS_GL_VERSION_MAJOR)
	 , version_minor(OGLPLUS_GL_VERSION_MINOR)
	 , width(64)
	 , height(64)
	{ }
};

} // namespace oglplus

#endif
