/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/gl.hpp>

#if defined(GL_NV_command_list)

#include <oglplus/command_list_nv.hpp>
#include "helper/object_c.hpp"

using namespace oglplus;

void oglplus_command_list_nv_test_1(void)
{
	oglplus_object_name_test<command_list_nv_name>();
	oglplus_object_test<command_list_nv>();
}

void oglplus_command_list_nv_test_ops1(void)
{
/*
	oper::command_list_nv_ops gl;
	command_list_nv sam;
	command_list_nv_array<4> sams;
*/
}

// TODO

#endif
