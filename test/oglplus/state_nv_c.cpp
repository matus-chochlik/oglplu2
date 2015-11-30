/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/gl.hpp>

#if defined(GL_NV_command_list)

#include <oglplus/state_nv.hpp>
#include "helper/object_c.hpp"

using namespace oglplus;

void oglplus_state_nv_test_1(void)
{
	oglplus_object_name_test<state_nv_name>();
	oglplus_object_test<state_nv>();
}

void oglplus_state_nv_test_ops1(void)
{
/*
	oper::state_nv_ops gl;
	state_nv sam;
	state_nv_array<4> sams;
*/
}

// TODO

#endif
