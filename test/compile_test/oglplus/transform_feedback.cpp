/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/gl_fixed.hpp>
#include <oglplus/transform_feedback.hpp>
#include "helper/object_c.hpp"

using namespace oglplus;

void oglplus_transform_feedback_test_1(void)
{
	oglplus_object_name_test<transform_feedback_name>();
	oglplus_object_test<transform_feedback>();
}

void oglplus_transform_feedback_test_ops1(void)
{
	using namespace oglplus;

	oper::transform_feedback_ops gl;
	transform_feedback xfb;
	transform_feedback_target tgt(GL_TRANSFORM_FEEDBACK);
	transform_feedback_primitive_type xfbm(GL_TRIANGLES);
	buffer_name buf(1);

	gl.bind_transform_feedback(tgt, xfb);
	gl.transform_feedback_binding(tgt);

	gl.begin_transform_feedback(xfbm);
	gl.pause_transform_feedback();
	gl.resume_transform_feedback();
	gl.end_transform_feedback();

	xfb.begin(xfbm);
	xfb.pause();
	xfb.resume();
	xfb.end();
#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access)
	gl.transform_feedback_buffer_base(xfb, 0, buf);
	gl.transform_feedback_buffer_range(xfb, 0, buf, 10, 20);

	gl.transform_feedback_buffer_binding(xfb);
	gl.transform_feedback_active(xfb);
	gl.transform_feedback_paused(xfb);

	gl.transform_feedback_buffer_start(xfb, 0);
	gl.transform_feedback_buffer_size(xfb, 0);

	xfb.buffer_base(0, buf);
	xfb.buffer_range(0, buf, 10, 20);

	xfb.buffer_binding();
	xfb.active();
	xfb.paused();

	xfb.buffer_start(0);
	xfb.buffer_size(0);
#endif
}

// TODO
