/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/gl_fixed.hpp>
#include <oglplus/program_pipeline.hpp>
#include "helper/object_c.hpp"

using namespace oglplus;

void oglplus_program_pipeline_test_1(void)
{
#if defined(GL_VERSION_4_1) || defined(GL_ARB_separate_shared_objects)
	oglplus_object_name_test<program_pipeline_name>();
	oglplus_object_test<program_pipeline>();
#endif
}

void oglplus_program_pipeline_test_ops1(void)
{
}

// TODO
