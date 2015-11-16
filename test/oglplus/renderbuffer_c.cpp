/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/gl.hpp>
#include <oglplus/renderbuffer.hpp>
#include "helper/object_c.hpp"

using namespace oglplus;

void oglplus_renderbuffer_test_1(void)
{
	oglplus_object_name_test<renderbuffer_name>();
	oglplus_object_test<renderbuffer>();
}

void oglplus_renderbuffer_test_ops1(void)
{
	oper::renderbuffer_ops gl;
	renderbuffer rbo;
	renderbuffer_array<4> rbos;
	renderbuffer_target tgt(GL_RENDERBUFFER);
	bound_renderbuffer currbo(tgt);
	pixel_data_internal_format ifmt(GL_RGBA);

	gl.renderbuffer_storage(tgt, ifmt, 32, 32);
	gl.renderbuffer_storage_multisample(tgt, 4, ifmt, 32, 32);
	gl.renderbuffer_width(tgt);
	gl.renderbuffer_height(tgt);
	gl.renderbuffer_red_size(tgt);
	gl.renderbuffer_green_size(tgt);
	gl.renderbuffer_blue_size(tgt);
	gl.renderbuffer_alpha_size(tgt);
	gl.renderbuffer_depth_size(tgt);
	gl.renderbuffer_stencil_size(tgt);
	gl.renderbuffer_samples(tgt);
	gl.renderbuffer_internal_format(tgt);

	currbo.storage(ifmt, 32, 32);
	currbo.storage_multisample(4, ifmt, 32, 32);
	currbo.width();
	currbo.height();
	currbo.red_size();
	currbo.green_size();
	currbo.blue_size();
	currbo.alpha_size();
	currbo.depth_size();
	currbo.stencil_size();
	currbo.samples();
	currbo.internal_format();

#if defined(GL_VERSION_4_5) ||\
	defined(GL_ARB_direct_state_access) ||\
	defined(GL_EXT_direct_state_access)

	gl.renderbuffer_storage(rbo, ifmt, 32, 32);
	gl.renderbuffer_storage_multisample(rbo, 4, ifmt, 32, 32);
	gl.renderbuffer_width(rbo);
	gl.renderbuffer_height(rbo);
	gl.renderbuffer_red_size(rbo);
	gl.renderbuffer_green_size(rbo);
	gl.renderbuffer_blue_size(rbo);
	gl.renderbuffer_alpha_size(rbo);
	gl.renderbuffer_depth_size(rbo);
	gl.renderbuffer_stencil_size(rbo);
	gl.renderbuffer_samples(rbo);
	gl.renderbuffer_internal_format(rbo);

	rbo.storage(ifmt, 32, 32);
	rbo.storage_multisample(4, ifmt, 32, 32);
	rbo.width();
	rbo.height();
	rbo.red_size();
	rbo.green_size();
	rbo.blue_size();
	rbo.alpha_size();
	rbo.depth_size();
	rbo.stencil_size();
	rbo.samples();
	rbo.internal_format();

#endif
}

// TODO
