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

void oglplus_query_test_ops1(void)
{
	oper::query_ops gl;
	query qry;
	query_array<4> qrys;
	GLint ri;
	GLuint rui;

#if defined(GL_VERSION_3_3) || defined (GL_ARB_timer_query)
	GLint64 ri64;
	GLuint64 rui64;
#endif

	gl.begin_query(query_target(GL_SAMPLES_PASSED), qry);
	gl.end_query(query_target());
	gl.begin_query(query_target(GL_SAMPLES_PASSED), qrys[0]);

#if defined(GL_VERSION_3_0)
	gl.begin_conditional_render(qry, conditional_render_mode(GL_QUERY_WAIT));
	gl.end_conditional_render();
#endif

#if defined(GL_VERSION_3_3) || defined (GL_ARB_timer_query)
	gl.query_counter(qry, query_target(GL_TIMESTAMP));
	gl.query_timestamp(qry);
#endif
	gl.query_result_available(qry);
	gl.query_result(qry, ri);
	gl.query_result(qry, rui);

#if defined(GL_VERSION_3_3) || defined (GL_ARB_timer_query)
	gl.query_result(qry, ri64);
	gl.query_result(qry, rui64);
#endif
}

// TODO
