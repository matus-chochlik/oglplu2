/**
 *  @example standalone/003_glfw_glew_path_nv.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <GL/glew.h>

#include <oglplus/operations.hpp>
#include <oglplus/constants.hpp>
#include <oglplus/glsl/string_ref.hpp>
#include <oglplus/error/format.hpp>
#include <oglplus/utils/make_view.hpp>
#include <oglplus/math/vector.hpp>

#include <eagine/scope_exit.hpp>

#include <GL/glfw.h>

#include <iostream>
#include <stdexcept>

static oglplus::constants GL;
static oglplus::operations gl;

static
void handle_resize(int width, int height)
{
	gl.viewport(0, 0, width, height);
	GLfloat asp = GLfloat(width)/height;

	GLfloat h = 2;
	GLfloat w = h*asp;

	gl.matrix_mode(GL.projection);
	gl.load_identity();
	gl.ortho(-w,+w, -h,+h, 0,1);
}

static
void run_loop(int width, int height)
{
	using namespace oglplus;

	path_nv path;

	path.commands(path_nv_spec<GLfloat>(6, 10)
		.move_to( 0.00f, 0.85f)
		.line_to( 0.65f,-0.80f)
		.line_to(-0.85f, 0.30f)
		.line_to( 0.85f, 0.30f)
		.line_to(-0.65f,-0.80f)
		.close()
	);

	path.stroke_width(0.01f);
	path.join_style(GL.round_nv);

	gl.clear_color(vec4(0.6f, 0.7f, 0.6f, 0.0f));
	gl.clear_stencil(0);
	gl.stencil_mask(~0u);
	gl.stencil_func(GL.notequal, 0, 0x1F);
	gl.stencil_op(GL.keep, GL.keep, GL.zero);

	gl.enable(GL.stencil_test);

	handle_resize(width, height);

	int deg = 0;

	while(true)
	{
		gl.clear(GL.color_buffer_bit|GL.stencil_buffer_bit);

		gl.matrix_mode(GL.modelview);
		gl.load_identity();
		gl.rotate_f(degrees(deg++), 0, 0, 1);

		gl.color_f(0.2f, 0.2f, 1.0f);

		path.stencil_fill(GL.count_up_nv, 0x1F);
		path.cover_fill(GL.bounding_box_nv);

		gl.color_f(0.1f, 0.1f, 0.1f);

		path.stencil_stroke(1, ~0u);
		path.cover_stroke(GL.convex_hull_nv);

		glfwSwapBuffers();

		int new_width, new_height;
		glfwGetWindowSize(&new_width, &new_height);

		if((width != new_width) || (height != new_height))
		{
			width = new_width;
			height = new_height;

			handle_resize(width, height);
		}
		

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

static
void init_and_run(void)
{
	if(!glfwInit())
	{
		throw std::runtime_error("GLFW initialization error");
	}
	else
	{
		auto ensure_glfw_cleanup = eagine::finally(glfwTerminate);

		int width = 800, height = 600;

		if(!glfwOpenWindow(width, height, 8, 8, 8, 0, 0, 8, GLFW_WINDOW))
		{
			throw std::runtime_error("Error creating GLFW window");
		}
		else
		{
			glfwSetWindowTitle("OGLplus example");

			glewExperimental = GL_TRUE;
			GLenum init_result = glewInit();
			glGetError();
			if(init_result != GLEW_OK)
			{
				throw std::runtime_error(
					"OpenGL/GLEW initialization error."
				);
			}
			else
			{
				run_loop(width, height);
			}
		}
	}
}

int main(void)
{
	try { init_and_run(); return 0; }
	catch(oglplus::error& gle)
	{
		oglplus::format_error(
			gle,
			"OpenGL error\n"
			"in GL function: %(gl_function_name)\n"
			"with enum parameter: %(gl_enum_value)\n"
			"from source file: %(source_file)\n"
			"%(message)",
			std::cerr
		) << std::endl;
	}
	catch(std::runtime_error& sre)
	{
		std::cerr
			<< "Runtime error: "
			<< sre.what()
			<< std::endl;
	}
	catch(std::exception& se)
	{
		std::cerr
			<< "Unknown error: "
			<< se.what()
			<< std::endl;
	}
	return 1;
}
