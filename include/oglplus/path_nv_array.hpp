/**
 *  @file oglplus/path_nv_array.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_PATH_NV_ARRAY_1509260923_HPP
#define OGLPLUS_PATH_NV_ARRAY_1509260923_HPP

#include "path_nv.hpp"
#include "utils/cstr_ref.hpp"

namespace oglplus {
namespace oper {

struct path_nv_array_ops
{
	template <typename S, typename T>
	static
	outcome<void>
	path_glyphs(
		const object_names<tag::path_nv, S>& paths,
		path_font_target_nv font_target,
		cstr_ref font_name,
		enum_bitfield<path_font_style_nv> font_style,
		array_view<const T> char_codes,
		path_missing_glyph_nv handle_missing_glyphs,
		GLuint parameter_template,
		GLfloat em_scale
	) noexcept;

	template <typename S>
	static
	outcome<void>
	path_glyphs(
		const object_names<tag::path_nv, S>& paths,
		path_font_target_nv font_target,
		cstr_ref font_name,
		enum_bitfield<path_font_style_nv> font_style,
		cstring_view<> char_codes,
		path_missing_glyph_nv handle_missing_glyphs,
		GLuint parameter_template,
		GLfloat em_scale
	) noexcept;

	template <typename S>
	static
	outcome<void>
	path_glyph_range(
		const object_names<tag::path_nv, S>& paths,
		path_font_target_nv font_target,
		cstr_ref font_name,
		enum_bitfield<path_font_style_nv> font_style,
		GLuint first_glyph,
		GLsizei num_glyphs,
		path_missing_glyph_nv handle_missing_glyphs,
		GLuint parameter_template,
		GLfloat em_scale
	) noexcept;

	template <typename S, typename T>
	static
	outcome<void>
	get_path_spacing(
		path_list_mode_nv list_mode,
		array_view<const T> indices,
		const object_names<tag::path_nv, S>& paths,
		GLfloat advance_scale,
		GLfloat kerning_scale,
		path_transform_type_nv transform_type,
		array_view<GLfloat> returned_values
	) noexcept;

	template <typename S>
	static
	outcome<void>
	get_path_spacing(
		path_list_mode_nv list_mode,
		cstring_view<> indices,
		const object_names<tag::path_nv, S>& paths,
		GLfloat advance_scale,
		GLfloat kerning_scale,
		path_transform_type_nv transform_type,
		array_view<GLfloat> returned_values
	) noexcept;

	template <typename S, typename T>
	static
	outcome<void>
	get_path_metrics(
		enum_bitfield<path_metric_query_nv> query_mask,
		array_view<const T> indices,
		const object_names<tag::path_nv, S>& paths,
		GLsizei stride,
		array_view<GLfloat> returned_values
	) noexcept;

	template <typename S>
	static
	outcome<void>
	get_path_metrics(
		enum_bitfield<path_metric_query_nv> query_mask,
		cstring_view<> indices,
		const object_names<tag::path_nv, S>& paths,
		GLsizei stride,
		array_view<GLfloat> returned_values
	) noexcept;

	template <typename S, typename T>
	static
	outcome<void>
	stencil_fill_path_instanced(
		array_view<const T> indices,
		const object_names<tag::path_nv, S>& paths,
		path_fill_mode_nv mode,
		GLuint mask,
		path_transform_type_nv transform_type,
		array_view<const GLfloat> transform_values
	) noexcept;

	template <typename S>
	static
	outcome<void>
	stencil_fill_path_instanced(
		cstring_view<> indices,
		const object_names<tag::path_nv, S>& paths,
		path_fill_mode_nv mode,
		GLuint mask,
		path_transform_type_nv transform_type,
		array_view<const GLfloat> transform_values
	) noexcept;

	template <typename S, typename T>
	static
	outcome<void>
	cover_fill_path_instanced(
		array_view<const T> indices,
		const object_names<tag::path_nv, S>& paths,
		path_fill_cover_mode_nv mode,
		path_transform_type_nv transform_type,
		array_view<const GLfloat> transform_values
	) noexcept;

	template <typename S>
	static
	outcome<void>
	cover_fill_path_instanced(
		cstring_view<> indices,
		const object_names<tag::path_nv, S>& paths,
		path_fill_cover_mode_nv mode,
		path_transform_type_nv transform_type,
		array_view<const GLfloat> transform_values
	) noexcept;

	template <typename S, typename T>
	static
	outcome<void>
	stencil_stroke_path_instanced(
		array_view<const T> indices,
		const object_names<tag::path_nv, S>& paths,
		GLint reference,
		GLuint mask,
		path_transform_type_nv transform_type,
		array_view<const GLfloat> transform_values
	) noexcept;

	template <typename S>
	static
	outcome<void>
	stencil_stroke_path_instanced(
		cstring_view<> indices,
		const object_names<tag::path_nv, S>& paths,
		GLint reference,
		GLuint mask,
		path_transform_type_nv transform_type,
		array_view<const GLfloat> transform_values
	) noexcept;

	template <typename S, typename T>
	static
	outcome<void>
	cover_stroke_path_instanced(
		array_view<const T> indices,
		const object_names<tag::path_nv, S>& paths,
		path_stroke_cover_mode_nv mode,
		path_transform_type_nv transform_type,
		array_view<const GLfloat> transform_values
	) noexcept;

	template <typename S>
	static
	outcome<void>
	cover_stroke_path_instanced(
		cstring_view<> indices,
		const object_names<tag::path_nv, S>& paths,
		path_stroke_cover_mode_nv mode,
		path_transform_type_nv transform_type,
		array_view<const GLfloat> transform_values
	) noexcept;
};

} // namespace oper


} // namespace oglplus

#include <oglplus/path_nv_array.inl>

#endif // include guard
