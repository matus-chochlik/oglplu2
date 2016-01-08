/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/gl_fixed.hpp>
#include <oglplus/texture.hpp>
#include "helper/object_c.hpp"

using namespace oglplus;

void oglplus_texture_test_1(void)
{
	oglplus_object_name_test<texture_name>();
	oglplus_object_test<texture>();
}

void oglplus_texture_test_ops1(void)
{
	using namespace oglplus;

	oper::texture_ops gl;
	texture tex;
	texture_array<4> texs;
	texture_target tgt(GL_TEXTURE_2D);
	texture_name_and_target tnt(tex,tgt);
	bound_texture curtex(tgt);

	pixel_data_internal_format ifmt(GL_RGBA);
	pixel_data_format fmt(GL_RGBA);
	pixel_data_type typ(GL_UNSIGNED_BYTE);
	texture_wrap_coord wrap_s(GL_TEXTURE_WRAP_S);
	texture_swizzle_coord swizzle_r(GL_TEXTURE_SWIZZLE_R);
	const_memory_block blk;

	gl.bind_texture(tgt, tex);
	gl.texture_binding(tgt);
	gl.bind_texture(tgt, texs[0]);

	gl.texture_image_1d(tgt, 0, ifmt, 64, 0, fmt, typ, blk);
	gl.texture_image_2d(tgt, 0, ifmt, 64, 64, 0, fmt, typ, blk);
	gl.texture_image_3d(tgt, 0, ifmt, 64, 64, 64, 0, fmt, typ, blk);

#if defined(GL_EXT_direct_state_access)
	gl.texture_image_1d(tnt, 0, ifmt, 64, 0, fmt, typ, blk);
	gl.texture_image_2d(tnt, 0, ifmt, 64, 64, 0, fmt, typ, blk);
	gl.texture_image_3d(tnt, 0, ifmt, 64, 64, 64, 0, fmt, typ, blk);
#endif

#if defined(GL_VERSION_4_2) || defined(GL_ARB_texture_storage)
	gl.texture_storage_1d(tgt, 1, ifmt, 64);
	gl.texture_storage_2d(tgt, 1, ifmt, 64, 64);
	gl.texture_storage_3d(tgt, 1, ifmt, 64, 64, 64);
#endif

#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access)
	gl.texture_storage_1d(tex, 1, ifmt, 64);
	gl.texture_storage_2d(tex, 1, ifmt, 64, 64);
	gl.texture_storage_3d(tex, 1, ifmt, 64, 64, 64);
#endif

	gl.texture_width(tgt);
	gl.texture_height(tgt);
	gl.texture_depth(tgt);

	gl.texture_red_type(tgt);
	gl.texture_red_size(tgt);
	gl.texture_green_type(tgt);
	gl.texture_green_size(tgt);
	gl.texture_blue_type(tgt);
	gl.texture_blue_size(tgt);
	gl.texture_alpha_type(tgt);
	gl.texture_alpha_size(tgt);
	gl.texture_depth_type(tgt);
	gl.texture_depth_size(tgt);
	gl.texture_stencil_size(tgt);
	gl.texture_shared_size(tgt);
	gl.texture_compressed(tgt);
	gl.texture_compressed_image_size(tgt);
	gl.texture_internal_format(tgt);

	gl.texture_min_filter(tgt, texture_min_filter(GL_LINEAR));
	gl.texture_min_filter(tgt);
	gl.texture_mag_filter(tgt, texture_mag_filter(GL_LINEAR));
	gl.texture_mag_filter(tgt);
	gl.texture_compare_mode(tgt, texture_compare_mode(GL_NONE));
	gl.texture_compare_mode(tgt);
	gl.texture_compare_func(tgt, compare_function(GL_EQUAL));
	gl.texture_compare_func(tgt);
	gl.texture_wrap(tgt, wrap_s, texture_wrap_mode(GL_REPEAT));
	gl.texture_wrap(tgt, wrap_s);
	gl.texture_swizzle(tgt, swizzle_r, texture_swizzle_mode(GL_ONE));
	gl.texture_swizzle(tgt, swizzle_r);

	gl.texture_lod_bias(tgt, 1.0f);
	gl.texture_lod_bias(tgt);
	gl.texture_min_lod(tgt,-1000.0f);
	gl.texture_min_lod(tgt);
	gl.texture_max_lod(tgt, 1000.0f);
	gl.texture_max_lod(tgt);

#if defined(GL_EXT_direct_state_access)
	gl.texture_width(tnt);
	gl.texture_height(tnt);
	gl.texture_depth(tnt);

	gl.texture_red_type(tnt);
	gl.texture_red_size(tnt);
	gl.texture_green_type(tnt);
	gl.texture_green_size(tnt);
	gl.texture_blue_type(tnt);
	gl.texture_blue_size(tnt);
	gl.texture_alpha_type(tnt);
	gl.texture_alpha_size(tnt);
	gl.texture_depth_type(tnt);
	gl.texture_depth_size(tnt);
	gl.texture_stencil_size(tnt);
	gl.texture_shared_size(tnt);
	gl.texture_compressed(tnt);
	gl.texture_compressed_image_size(tnt);
	gl.texture_internal_format(tnt);

	gl.texture_min_filter(tnt, texture_min_filter(GL_LINEAR));
	gl.texture_min_filter(tnt);
	gl.texture_mag_filter(tnt, texture_mag_filter(GL_LINEAR));
	gl.texture_mag_filter(tnt);
	gl.texture_compare_mode(tnt, texture_compare_mode(GL_NONE));
	gl.texture_compare_mode(tnt);
	gl.texture_compare_func(tnt, compare_function(GL_EQUAL));
	gl.texture_compare_func(tnt);
	gl.texture_wrap(tnt, wrap_s, texture_wrap_mode(GL_REPEAT));
	gl.texture_wrap(tnt, wrap_s);
	gl.texture_swizzle(tnt, swizzle_r, texture_swizzle_mode(GL_ONE));
	gl.texture_swizzle(tnt, swizzle_r);

	gl.texture_lod_bias(tnt, 1.0f);
	gl.texture_lod_bias(tnt);
	gl.texture_min_lod(tnt,-1000.0f);
	gl.texture_min_lod(tnt);
	gl.texture_max_lod(tnt, 1000.0f);
	gl.texture_max_lod(tnt);
#endif

#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access)
	gl.texture_width(tex);
	gl.texture_height(tex);
	gl.texture_depth(tex);

	gl.texture_red_type(tex);
	gl.texture_red_size(tex);
	gl.texture_green_type(tex);
	gl.texture_green_size(tex);
	gl.texture_blue_type(tex);
	gl.texture_blue_size(tex);
	gl.texture_alpha_type(tex);
	gl.texture_alpha_size(tex);
	gl.texture_depth_type(tex);
	gl.texture_depth_size(tex);
	gl.texture_stencil_size(tex);
	gl.texture_shared_size(tex);
	gl.texture_compressed(tex);
	gl.texture_compressed_image_size(tex);
	gl.texture_internal_format(tex);

	gl.texture_min_filter(tex, texture_min_filter(GL_LINEAR));
	gl.texture_min_filter(tex);
	gl.texture_mag_filter(tex, texture_mag_filter(GL_LINEAR));
	gl.texture_mag_filter(tex);
	gl.texture_compare_mode(tex, texture_compare_mode(GL_NONE));
	gl.texture_compare_mode(tex);
	gl.texture_compare_func(tex, compare_function(GL_EQUAL));
	gl.texture_compare_func(tex);
	gl.texture_wrap(tex, wrap_s, texture_wrap_mode(GL_REPEAT));
	gl.texture_wrap(tex, wrap_s);
	gl.texture_swizzle(tex, swizzle_r, texture_swizzle_mode(GL_ONE));
	gl.texture_swizzle(tex, swizzle_r);

	gl.texture_lod_bias(tex, 1.0f);
	gl.texture_lod_bias(tex);
	gl.texture_min_lod(tex,-1000.0f);
	gl.texture_min_lod(tex);
	gl.texture_max_lod(tex, 1000.0f);
	gl.texture_max_lod(tex);
#endif

	curtex.width();
	curtex.height();
	curtex.depth();

	curtex.red_type();
	curtex.red_size();
	curtex.green_type();
	curtex.green_size();
	curtex.blue_type();
	curtex.blue_size();
	curtex.alpha_type();
	curtex.alpha_size();
	curtex.depth_type();
	curtex.depth_size();
	curtex.stencil_size();
	curtex.shared_size();

	curtex.min_filter(texture_min_filter(GL_NEAREST));
	curtex.min_filter();
	curtex.mag_filter(texture_mag_filter(GL_NEAREST));
	curtex.mag_filter();

	curtex.compare_mode(texture_compare_mode(GL_NONE));
	curtex.compare_mode();
	curtex.compare_func(compare_function(GL_LESS));
	curtex.compare_func();
	curtex.wrap(wrap_s, texture_wrap_mode(GL_REPEAT));
	curtex.wrap(wrap_s);
	curtex.swizzle(swizzle_r, texture_swizzle_mode(GL_ONE));
	curtex.swizzle(swizzle_r);

	curtex.lod_bias(1.0f);
	curtex.lod_bias();
	curtex.min_lod(-1000.0f);
	curtex.min_lod();
	curtex.max_lod(1000.0f);
	curtex.max_lod();

#if defined(GL_VERSION_4_5) ||\
	defined(GL_ARB_direct_state_access) ||\
	defined(GL_EXT_direct_state_access)

	tex.width();
	tex.height();
	tex.depth();

	tex.red_type();
	tex.red_size();
	tex.green_type();
	tex.green_size();
	tex.blue_type();
	tex.blue_size();
	tex.alpha_type();
	tex.alpha_size();
	tex.depth_type();
	tex.depth_size();
	tex.stencil_size();
	tex.shared_size();

	tex.min_filter(texture_min_filter(GL_NEAREST));
	tex.min_filter();
	tex.mag_filter(texture_mag_filter(GL_NEAREST));
	tex.mag_filter();

	tex.compare_mode(texture_compare_mode(GL_NONE));
	tex.compare_mode();
	tex.compare_func(compare_function(GL_LESS));
	tex.compare_func();
	tex.wrap(wrap_s, texture_wrap_mode(GL_REPEAT));
	tex.wrap(wrap_s);
	tex.swizzle(swizzle_r, texture_swizzle_mode(GL_ONE));
	tex.swizzle(swizzle_r);

	tex.lod_bias(1.0f);
	tex.lod_bias();
	tex.min_lod(-1000.0f);
	tex.min_lod();
	tex.max_lod(1000.0f);
	tex.max_lod();
#endif
}

// TODO
