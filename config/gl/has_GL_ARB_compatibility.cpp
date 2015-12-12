/**
 * Copyright Matus Chochlik.
 * Distributed under the Boost Software License, Version 1.0.
 * See accompanying file LICENSE_1_0.txt or copy at
 *  http://www.boost.org/LICENSE_1_0.txt
 */
#define OGLPLUS_CONFIG_QUERY_GL_VER_MAJOR 3
#define OGLPLUS_CONFIG_QUERY_GL_VER_MINOR 2

#include "init_GL.ipp"
#include "has_GL_ARB_compatibility.ipp"

bool do_query_gl(void)
{
	if(!does_have_ARB_compatibility())
	{
		return false;
	}

	unsigned missing_gl_symbols = 0;

	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glBegin);
	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glEnd);

	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glVertex2s);
	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glVertex3s);
	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glVertex4s);
	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glVertex2sv);
	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glVertex3sv);
	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glVertex4sv);

	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glVertex2i);
	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glVertex3i);
	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glVertex4i);
	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glVertex2iv);
	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glVertex3iv);
	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glVertex4iv);

	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glVertex2f);
	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glVertex3f);
	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glVertex4f);
	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glVertex2fv);
	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glVertex3fv);
	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glVertex4fv);

	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glMatrixMode);
	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glPushMatrix);
	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glPopMatrix);
	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glLoadMatrixf);
	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glLoadMatrixd);
	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glTranslatef);
	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glTranslated);
	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glRotatef);
	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glRotated);
	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glScalef);
	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glScaled);

	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glEnableClientState);
	OGLPLUS_CONFIG_ASSERT_GL_FUNC(glDisableClientState);
	// TODO:

	return missing_gl_symbols == 0;
}
