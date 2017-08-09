/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/gl_fixed.hpp>

#if defined(GL_NV_path_rendering)

#include <oglplus/path_nv.hpp>
#include "helper/object_c.hpp"

using namespace oglplus;

void oglplus_path_nv_test_1(void)
{
	oglplus_object_name_test<path_nv_name>();
	oglplus_object_test<path_nv>();
}

void oglplus_path_nv_test_ops1(void)
{
	oper::path_nv_ops gl;
	path_nv pnv;
	path_nv_array<4> pnvs;
	GLfloat f;

	gl.path_commands(pnv, path_nv_spec<GLint>());
	gl.path_commands(pnv, path_nv_spec<GLfloat>());
	gl.path_commands(pnvs[0], path_nv_spec<GLint>());
	gl.path_commands(pnvs[0], path_nv_spec<GLfloat>());
	gl.path_sub_commands(pnv, 0, 0, path_nv_spec<GLint>());
	gl.path_sub_commands(pnv, 0, 0, path_nv_spec<GLfloat>());
	gl.path_coords(pnv, span<const GLint>());
	gl.path_coords(pnv, span<const GLfloat>());
	gl.path_string(pnv, path_format_nv(GL_PATH_FORMAT_SVG_NV), "");
	gl.path_svg_string(pnv, "");
	gl.path_ps_string(pnv, "");
	gl.is_point_in_fill_path(pnv, 0, 0.0f, 0.0f);
	gl.is_point_in_stroke_path(pnv, 0.0f, 0.0f);
	gl.get_path_length(pnv, 0, 0);
	gl.point_along_path(pnv, 0, 0, 0, f, f, f, f);
	gl.stencil_fill_path(pnv, path_fill_mode_nv(GL_COUNT_UP_NV), 0);
	gl.cover_fill_path(pnv, path_fill_cover_mode_nv(GL_CONVEX_HULL_NV));
	gl.stencil_stroke_path(pnv, 0, 0);
	gl.cover_stroke_path(pnv, path_stroke_cover_mode_nv(GL_CONVEX_HULL_NV));
	gl.get_path_computed_length(pnv);
	gl.path_stroke_width(pnv, 1.f);
	gl.get_path_stroke_width(pnv);
	gl.path_miter_limit(pnv, 4.f);
	gl.get_path_miter_limit(pnv);
	gl.path_join_style(pnv, path_join_style_nv(GL_ROUND_NV));
	gl.get_path_join_style(pnv);
	gl.path_initial_end_cap(pnv, path_cap_style_nv(GL_ROUND_NV));
	gl.get_path_initial_end_cap(pnv);
	gl.path_terminal_end_cap(pnv, path_cap_style_nv(GL_ROUND_NV));
	gl.get_path_terminal_end_cap(pnv);
	gl.path_initial_dash_cap(pnv, path_cap_style_nv(GL_ROUND_NV));
	gl.get_path_initial_dash_cap(pnv);
	gl.path_terminal_dash_cap(pnv, path_cap_style_nv(GL_ROUND_NV));
	gl.get_path_terminal_dash_cap(pnv);
	gl.path_dash_offset(pnv, 1.f);
	gl.get_path_dash_offset(pnv);
	gl.path_dash_offset_reset(pnv, path_dash_offset_reset_nv(GL_MOVE_TO_RESETS_NV));
	gl.get_path_dash_offset_reset(pnv);
	gl.path_dash_array(pnv, span<const GLfloat>());

	gl.copy_path(pnv, pnv);
	gl.interpolate_path(pnv, pnv, pnv, 0.5f);
	gl.transform_path(pnv, pnv, path_transform_type_nv(GL_NONE), span<GLfloat>());

	pnv.commands(path_nv_spec<GLint>());
	pnv.commands(path_nv_spec<GLfloat>());
	pnv.sub_commands(0, 0, path_nv_spec<GLint>());
	pnv.sub_commands(0, 0, path_nv_spec<GLfloat>());
	pnv.coords(span<const GLint>());
	pnv.coords(span<const GLfloat>());
	pnv.string(path_format_nv(GL_PATH_FORMAT_SVG_NV), "");
	pnv.svg_string("");
	pnv.ps_string("");
	pnv.is_point_in_fill(0, 0.0f, 0.0f);
	pnv.is_point_in_stroke(0.0f, 0.0f);
	pnv.get_length(0, 0);
	pnv.point_along(0, 0, 0, f, f, f, f);
	pnv.stencil_fill(path_fill_mode_nv(GL_COUNT_UP_NV), 0);
	pnv.cover_fill(path_fill_cover_mode_nv(GL_CONVEX_HULL_NV));
	pnv.cover_stroke(path_stroke_cover_mode_nv(GL_CONVEX_HULL_NV));
	pnv.stencil_stroke(0, 0);
	pnv.get_computed_length();
	pnv.stroke_width(1.f);
	pnv.get_stroke_width();
	pnv.miter_limit(4.f);
	pnv.get_miter_limit();
	pnv.join_style(path_join_style_nv(GL_ROUND_NV));
	pnv.get_join_style();
	pnv.initial_end_cap(path_cap_style_nv(GL_ROUND_NV));
	pnv.get_initial_end_cap();
	pnv.terminal_end_cap(path_cap_style_nv(GL_ROUND_NV));
	pnv.get_terminal_end_cap();
	pnv.initial_dash_cap(path_cap_style_nv(GL_ROUND_NV));
	pnv.get_initial_dash_cap();
	pnv.terminal_dash_cap(path_cap_style_nv(GL_ROUND_NV));
	pnv.get_terminal_dash_cap();
	pnv.dash_offset(1.f);
	pnv.get_dash_offset();
	pnv.dash_offset_reset(path_dash_offset_reset_nv(GL_MOVE_TO_RESETS_NV));
	pnv.get_dash_offset_reset();
	pnv.dash_array(span<const GLfloat>());
	pnv.dashes(1.0f, 2.0f, 3.0f);

	pnv.copy_from(pnv);
	pnv.interpolate_from(pnv, pnv, 0.5f);
	pnv.transform_from(pnv, path_transform_type_nv(GL_NONE), span<GLfloat>());
}

// TODO
#endif // NV_path_rendering
