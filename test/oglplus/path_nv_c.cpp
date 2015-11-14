/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/gl.hpp>
#include <oglplus/path_nv.hpp>
#include "helper/object_c.hpp"

using namespace oglplus;

void oglplus_path_nv_test_1(void)
{
	oglplus_object_name_test<path_nv_name>();
	oglplus_object_test<path_nv>();
}

void oglplus_path_nv_test_ops1(void)
{
	oper::path_nv_ops gl;
	path_nv pnv;

	gl.path_commands(pnv, path_nv_spec<GLint>());
	gl.path_commands(pnv, path_nv_spec<GLfloat>());
	gl.path_sub_commands(pnv, 0, 0, path_nv_spec<GLint>());
	gl.path_sub_commands(pnv, 0, 0, path_nv_spec<GLfloat>());
	gl.path_coords(pnv, array_view<const GLint>());
	gl.path_coords(pnv, array_view<const GLfloat>());

	pnv.commands(path_nv_spec<GLint>());
	pnv.commands(path_nv_spec<GLfloat>());
	pnv.sub_commands(0, 0, path_nv_spec<GLint>());
	pnv.sub_commands(0, 0, path_nv_spec<GLfloat>());
	pnv.coords(array_view<const GLint>());
	pnv.coords(array_view<const GLfloat>());
}

// TODO
