/**
 *  file. oglplus/example/main_glut.cpp
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

#if OGLPLUS_FREEGLUT_FOUND
# include <GL/freeglut.h>
#elif defined(__APPLE__) && __APPLE__
# include <GLUT/glut.h>
#else
# include <GL/glut.h>
#endif

#include <iostream>
#include <cassert>

class single_glut_context
{
private:
	single_glut_context(const single_glut_context&);

	static single_glut_context*& instance_ptr(void)
	{
		static single_glut_context* pinst = nullptr;
		return pinst;
	}

	static single_glut_context& instance(void)
	{
		assert(instance_ptr());
		return *instance_ptr();
	}


	oglplus::example_wrapper example;
	int _height;
	int _wheel;
public:
	single_glut_context(
		oglplus::example_params& params,
		oglplus::example_state& state
	): example(params, state)
	 , _height(state.height())
	 , _wheel(0)
	{
		assert(!instance_ptr());
		instance_ptr() = this;

		glutDisplayFunc(&display_func);
		glutIdleFunc(&display_func);
		glutReshapeFunc(&reshape_func);

		glutMotionFunc(&motion_func);
		glutPassiveMotionFunc(&motion_func);

		glutMouseFunc(&mouse_func);
		glutKeyboardFunc(&keyboard_func);

#ifdef FREEGLUT
		glutSetOption(
			GLUT_ACTION_ON_WINDOW_CLOSE,
			GLUT_ACTION_GLUTMAINLOOP_RETURNS
		);
		glutCloseFunc(&close_func);
#endif
	}

	~single_glut_context(void)
	{
		assert(instance_ptr());
		instance_ptr() = nullptr;
	}

	void quit(void)
	{
#ifdef FREEGLUT
		glutLeaveMainLoop();
#else
		exit(0);
#endif
	}

private:
	void close(void)
	{
		example.destroy();
	}

	static void close_func(void)
	{
		instance().close();
	}

	void display(void)
	{
		example.update();

		example.render();
		glutSwapBuffers();

		if(!example.next_frame())
		{
			quit();
		}
	}

	static void display_func(void)
	{
		instance().display();
	}

	void reshape(int width, int height)
	{
		_height = height;
		example.set_size(width, height);
	}

	static void reshape_func(int width, int height)
	{
		instance().reshape(width, height);
	}

	void motion(int x, int y)
	{
		example.set_mouse_pos(x, _height-y);
	}

	static void motion_func(int x, int y)
	{
		instance().motion(x, y);
	}

	void mouse_press(int button, int state, int x, int y)
	{
		example.set_mouse_pos(x, _height-y);
		if(button == GLUT_LEFT_BUTTON)
		{
			example.set_mouse_btn(1, state == GLUT_DOWN);
		}
		else if(button == 3)
		{
			if(state == GLUT_DOWN)
			{
				example.set_mouse_wheel(++_wheel);
			}
		}
		else if(button == 4)
		{
			if(state == GLUT_DOWN)
			{
				example.set_mouse_wheel(--_wheel);
			}
		}
	}

	static void mouse_func(int button, int state, int x, int y)
	{
		instance().mouse_press(button, state, x, y);
	}

	void key_press(unsigned char k)
	{
		if(k == 0x1B) // Escape
		{
			quit();
		}
		// TODO
	}

	static void keyboard_func(unsigned char k, int, int)
	{
		instance().key_press(k);
	}
};

int example_main(
	const eagine::program_args& args,
	oglplus::example_params& params,
	oglplus::example_state& state
)
{
	int argc = args.argc();
	char** argv = const_cast<char**>(args.argv());

	glutInit(&argc, argv);
	glutInitDisplayMode(
#if defined(__APPLE__) && __APPLE__
		GLUT_3_2_CORE_PROFILE |
#endif
		GLUT_DOUBLE |
		GLUT_RGBA |
		(params.depth_buffer()?GLUT_DEPTH:0) |
		(params.stencil_buffer()?GLUT_STENCIL:0)
	);
#ifdef FREEGLUT
	glutInitContextVersion(
		OGLPLUS_GL_VERSION_MAJOR,
		OGLPLUS_GL_VERSION_MINOR
	);
#endif
	glutInitWindowSize(state.width(), state.height());
	glutInitWindowPosition(params.window_x_pos(), params.window_y_pos());
	glutCreateWindow("OGLplus example");

	oglplus::api_initializer gl_api_init;

	std::srand(params.rand_seed());
	state.set_depth(16);

	single_glut_context ctx(params, state);
	glutMainLoop();

	return 0;
}

