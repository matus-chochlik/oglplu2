/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef UTILS_OGLPLUS_OS_CONTEXT_GLUT_1107121519_HPP
#define UTILS_OGLPLUS_OS_CONTEXT_GLUT_1107121519_HPP

# if defined(__APPLE__) && __APPLE__
# include <GLUT/glut.h>
# else
# include <GL/glut.h>
# endif
#include "os_context_common.hpp"

namespace oglplus {

#if defined(__APPLE__) && __APPLE__ && defined(__clang__)
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wdeprecated-declarations"
#endif

class offscreen_context_glut
{
public:
	offscreen_context_glut(const offscreen_context_params& p)
	{
		int argc = p.argc;
		char** argv = p.argv;
		glutInit(&argc, argv);
		glutInitDisplayMode(
#if defined(__APPLE__) && __APPLE__ && defined(GLUT_3_2_CORE_PROFILE)
			GLUT_3_2_CORE_PROFILE|
#endif
			GLUT_DOUBLE|
			GLUT_RGBA|
			GLUT_DEPTH|
			GLUT_STENCIL
		);
		glutInitWindowSize(p.width, p.height);
		glutCreateWindow(p.title);
	}
};

#if defined(__APPLE__) && __APPLE__ && defined(__clang__)
# pragma clang diagnostic pop
#endif

} // namespace oglplus

#endif
