/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/gl.hpp>
#include <oglplus/sampler.hpp>
#include "helper/object_c.hpp"

using namespace oglplus;

void oglplus_sampler_test_1(void)
{
	oglplus_object_name_test<sampler_name>();
	oglplus_object_test<sampler>();
}

void oglplus_sampler_test_ops1(void)
{
	oper::sampler_ops gl;
	sampler sam;

	texture_wrap_coord wrap_s(GL_TEXTURE_WRAP_S);

	gl.sampler_min_filter(sam, texture_min_filter(GL_LINEAR));
	gl.sampler_min_filter(sam);
	gl.sampler_mag_filter(sam, texture_mag_filter(GL_LINEAR));
	gl.sampler_mag_filter(sam);
	gl.sampler_compare_mode(sam, texture_compare_mode(GL_NONE));
	gl.sampler_compare_mode(sam);
	gl.sampler_compare_func(sam, compare_function(GL_EQUAL));
	gl.sampler_compare_func(sam);
	gl.sampler_wrap(sam, wrap_s, texture_wrap_mode(GL_REPEAT));
	gl.sampler_wrap(sam, wrap_s);

	gl.sampler_lod_bias(sam, 1.0f);
	gl.sampler_lod_bias(sam);
	gl.sampler_min_lod(sam,-1000.0f);
	gl.sampler_min_lod(sam);
	gl.sampler_max_lod(sam, 1000.0f);
	gl.sampler_max_lod(sam);

	sam.min_filter(texture_min_filter(GL_NEAREST));
	sam.min_filter();
	sam.mag_filter(texture_mag_filter(GL_NEAREST));
	sam.mag_filter();

	sam.compare_mode(texture_compare_mode(GL_NONE));
	sam.compare_mode();
	sam.compare_func(compare_function(GL_LESS));
	sam.compare_func();
	sam.wrap(wrap_s, texture_wrap_mode(GL_REPEAT));
	sam.wrap(wrap_s);

	sam.lod_bias(1.0f);
	sam.lod_bias();
	sam.min_lod(-1000.0f);
	sam.min_lod();
	sam.max_lod(1000.0f);
	sam.max_lod();
}

// TODO
