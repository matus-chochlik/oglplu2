/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/gl.hpp>
#include <oglplus/query.hpp>
#include "helper/object_c.hpp"

using namespace oglplus;

void oglplus_query_test_1(void)
{
	oglplus_object_name_test<query_name>();
	oglplus_object_test<query>();
}

// TODO
