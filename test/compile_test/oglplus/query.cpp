/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/gl_fixed.hpp>
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
#if defined(GL_VERSION_3_0)
	GLint ri;
	GLuint rui;
#endif

#if defined(GL_VERSION_3_3) || defined (GL_ARB_timer_query)
	GLint64 ri64;
	GLuint64 rui64;
#endif

#if defined(GL_SAMPLES_PASSED)
	gl.begin_query(query_target(GL_SAMPLES_PASSED), qry);
	gl.end_query(query_target(GL_SAMPLES_PASSED));
	gl.begin_query(query_target(GL_SAMPLES_PASSED), qrys[0]);

	qry.begin(query_target(GL_SAMPLES_PASSED));
	qry.end(query_target(GL_SAMPLES_PASSED));

#if defined(GL_VERSION_4_0)
	gl.begin_query_indexed(query_target(GL_SAMPLES_PASSED), 1, qry);
	gl.end_query_indexed(query_target(GL_SAMPLES_PASSED), 1);
#endif
#endif

#if defined(GL_VERSION_3_0)
	gl.begin_conditional_render(qry, conditional_render_mode(GL_QUERY_WAIT));
	gl.end_conditional_render();
#endif

#if defined(GL_VERSION_3_3) || defined (GL_ARB_timer_query)
	gl.query_counter(qry, query_target(GL_TIMESTAMP));
	gl.query_timestamp(qry);

	qry.counter(query_target(GL_TIMESTAMP));
	qry.timestamp();
#endif
	gl.query_result_available(qry);
#if defined(GL_VERSION_3_0)
	gl.query_result(qry, ri);
	gl.query_result(qry, rui);
#endif

	qry.result_available();
#if defined(GL_VERSION_3_0)
	qry.result(ri);
	qry.result(rui);
#endif

#if defined(GL_VERSION_3_3) || defined (GL_ARB_timer_query)
	gl.query_result(qry, ri64);
	gl.query_result(qry, rui64);

	qry.result(ri64);
	qry.result(rui64);
#endif
}

// TODO
