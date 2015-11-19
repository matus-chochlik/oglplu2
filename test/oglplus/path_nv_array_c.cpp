/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/gl.hpp>
#include <oglplus/path_nv_array.hpp>

using namespace oglplus;

void oglplus_path_nv_array_test_ops1(void)
{
	paths_nv pnvs(4);
	oper::path_nv_array_ops gl;

	gl.path_glyphs(
		pnvs,
		path_font_target_nv(GL_FILE_NAME_NV),
		"font.ttf",
		path_font_style_nv(),
		span<const GLubyte>(),
		path_missing_glyph_nv(GL_USE_MISSING_GLYPH_NV),
		~0u, 1.0f
	);

	gl.path_glyphs(
		pnvs,
		path_font_target_nv(GL_FILE_NAME_NV),
		"font.ttf",
		path_font_style_nv(),
		"blah",
		path_missing_glyph_nv(GL_USE_MISSING_GLYPH_NV),
		~0u, 1.0f
	);

	gl.path_glyph_range(
		pnvs,
		path_font_target_nv(GL_FILE_NAME_NV),
		"font.ttf",
		path_font_style_nv(),
		60, 4,
		path_missing_glyph_nv(GL_USE_MISSING_GLYPH_NV),
		~0u, 1.0f
	);

	gl.get_path_spacing(
		path_list_mode_nv(GL_ACCUM_ADJACENT_PAIRS_NV),
		span<const GLushort>(),
		pnvs,
		1.0f, 1.0f,
		path_transform_type_nv(GL_NONE),
		span<GLfloat>()
	);

	gl.get_path_spacing(
		path_list_mode_nv(GL_ACCUM_ADJACENT_PAIRS_NV),
		"blah",
		pnvs,
		1.0f, 1.0f,
		path_transform_type_nv(GL_NONE),
		span<GLfloat>()
	);

	gl.stencil_fill_path_instanced(
		span<const GLuint>(),
		pnvs,
		path_fill_mode_nv(GL_INVERT),
		~0u,
		path_transform_type_nv(GL_NONE),
		span<GLfloat>()
	);

	gl.stencil_fill_path_instanced(
		"blah",
		pnvs,
		path_fill_mode_nv(GL_INVERT),
		~0u,
		path_transform_type_nv(GL_NONE),
		span<GLfloat>()
	);

	gl.cover_fill_path_instanced(
		span<const GLuint>(),
		pnvs,
		path_fill_cover_mode_nv(GL_CONVEX_HULL_NV),
		path_transform_type_nv(GL_NONE),
		span<GLfloat>()
	);

	gl.cover_fill_path_instanced(
		"blah",
		pnvs,
		path_fill_cover_mode_nv(GL_BOUNDING_BOX_NV),
		path_transform_type_nv(GL_NONE),
		span<GLfloat>()
	);

	gl.stencil_stroke_path_instanced(
		span<const GLuint>(),
		pnvs,
		0, ~0u,
		path_transform_type_nv(GL_NONE),
		span<GLfloat>()
	);

	gl.stencil_stroke_path_instanced(
		"blah",
		pnvs,
		0, ~0u,
		path_transform_type_nv(GL_NONE),
		span<GLfloat>()
	);

	gl.cover_stroke_path_instanced(
		span<const GLuint>(),
		pnvs,
		path_stroke_cover_mode_nv(GL_CONVEX_HULL_NV),
		path_transform_type_nv(GL_NONE),
		span<GLfloat>()
	);

	gl.cover_stroke_path_instanced(
		"blah",
		pnvs,
		path_stroke_cover_mode_nv(GL_BOUNDING_BOX_NV),
		path_transform_type_nv(GL_NONE),
		span<GLfloat>()
	);

	//

	pnvs.glyphs(
		path_font_target_nv(GL_FILE_NAME_NV),
		"font.ttf",
		path_font_style_nv(),
		span<const GLubyte>(),
		path_missing_glyph_nv(GL_USE_MISSING_GLYPH_NV),
		~0u, 1.0f
	);

	pnvs.glyphs(
		path_font_target_nv(GL_FILE_NAME_NV),
		"font.ttf",
		path_font_style_nv(),
		"blah",
		path_missing_glyph_nv(GL_USE_MISSING_GLYPH_NV),
		~0u, 1.0f
	);

	pnvs.glyph_range(
		path_font_target_nv(GL_FILE_NAME_NV),
		"font.ttf",
		path_font_style_nv(),
		60, 4,
		path_missing_glyph_nv(GL_USE_MISSING_GLYPH_NV),
		~0u, 1.0f
	);

	pnvs.get_spacing(
		path_list_mode_nv(GL_ACCUM_ADJACENT_PAIRS_NV),
		span<const GLushort>(),
		1.0f, 1.0f,
		path_transform_type_nv(GL_NONE),
		span<GLfloat>()
	);

	pnvs.get_spacing(
		path_list_mode_nv(GL_ACCUM_ADJACENT_PAIRS_NV),
		"blah",
		1.0f, 1.0f,
		path_transform_type_nv(GL_NONE),
		span<GLfloat>()
	);

	pnvs.stencil_fill_instanced(
		span<const GLuint>(),
		path_fill_mode_nv(GL_INVERT),
		~0u,
		path_transform_type_nv(GL_NONE),
		span<GLfloat>()
	);

	pnvs.stencil_fill_instanced(
		"blah",
		path_fill_mode_nv(GL_INVERT),
		~0u,
		path_transform_type_nv(GL_NONE),
		span<GLfloat>()
	);

	pnvs.cover_fill_instanced(
		span<const GLuint>(),
		path_fill_cover_mode_nv(GL_CONVEX_HULL_NV),
		path_transform_type_nv(GL_NONE),
		span<GLfloat>()
	);

	pnvs.cover_fill_instanced(
		"blah",
		path_fill_cover_mode_nv(GL_BOUNDING_BOX_NV),
		path_transform_type_nv(GL_NONE),
		span<GLfloat>()
	);

	pnvs.stencil_stroke_instanced(
		span<const GLuint>(),
		0, ~0u,
		path_transform_type_nv(GL_NONE),
		span<GLfloat>()
	);

	pnvs.stencil_stroke_instanced(
		"blah",
		0, ~0u,
		path_transform_type_nv(GL_NONE),
		span<GLfloat>()
	);

	pnvs.cover_stroke_instanced(
		span<const GLuint>(),
		path_stroke_cover_mode_nv(GL_CONVEX_HULL_NV),
		path_transform_type_nv(GL_NONE),
		span<GLfloat>()
	);

	pnvs.cover_stroke_instanced(
		"blah",
		path_stroke_cover_mode_nv(GL_BOUNDING_BOX_NV),
		path_transform_type_nv(GL_NONE),
		span<GLfloat>()
	);
}

// TODO
