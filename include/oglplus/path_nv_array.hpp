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
	template <typename S>
	static
	outcome<void>
	path_glyphs(
		const object_names<tag::path_nv, S>& paths,
		path_font_target_nv font_target,
		cstr_ref font_name,
		enum_bitfield<path_font_style_nv> font_style,
		cstring_span<> char_codes,
		path_missing_glyph_nv handle_missing_glyphs,
		GLuint parameter_template,
		GLfloat em_scale
	) noexcept;

	template <typename S, typename T>
	static
	outcome<void>
	path_glyphs(
		const object_names<tag::path_nv, S>& paths,
		path_font_target_nv font_target,
		cstr_ref font_name,
		enum_bitfield<path_font_style_nv> font_style,
		span<T> char_codes,
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
		span<T> indices,
		const object_names<tag::path_nv, S>& paths,
		GLfloat advance_scale,
		GLfloat kerning_scale,
		path_transform_type_nv transform_type,
		span<GLfloat> returned_values
	) noexcept;

	template <typename S>
	static
	outcome<void>
	get_path_spacing(
		path_list_mode_nv list_mode,
		cstring_span<> indices,
		const object_names<tag::path_nv, S>& paths,
		GLfloat advance_scale,
		GLfloat kerning_scale,
		path_transform_type_nv transform_type,
		span<GLfloat> returned_values
	) noexcept;

	template <typename S, typename T>
	static
	outcome<void>
	get_path_metrics(
		enum_bitfield<path_metric_query_nv> query_mask,
		span<T> indices,
		const object_names<tag::path_nv, S>& paths,
		GLsizei stride,
		span<GLfloat> returned_values
	) noexcept;

	template <typename S>
	static
	outcome<void>
	get_path_metrics(
		enum_bitfield<path_metric_query_nv> query_mask,
		cstring_span<> indices,
		const object_names<tag::path_nv, S>& paths,
		GLsizei stride,
		span<GLfloat> returned_values
	) noexcept;

	template <typename S>
	static
	outcome<void>
	get_path_metric_range(
		enum_bitfield<path_metric_query_nv> query_mask,
		const object_names<tag::path_nv, S>& paths,
		GLsizei num_paths,
		GLsizei stride,
		span<GLfloat> returned_values
	) noexcept;

	template <typename S, typename T>
	static
	outcome<void>
	stencil_fill_path_instanced(
		span<T> indices,
		const object_names<tag::path_nv, S>& paths,
		path_fill_mode_nv mode,
		GLuint mask,
		path_transform_type_nv transform_type,
		span<const GLfloat> transform_values
	) noexcept;

	template <typename S>
	static
	outcome<void>
	stencil_fill_path_instanced(
		cstring_span<> indices,
		const object_names<tag::path_nv, S>& paths,
		path_fill_mode_nv mode,
		GLuint mask,
		path_transform_type_nv transform_type,
		span<const GLfloat> transform_values
	) noexcept;

	template <typename S, typename T>
	static
	outcome<void>
	cover_fill_path_instanced(
		span<T> indices,
		const object_names<tag::path_nv, S>& paths,
		path_fill_cover_mode_nv mode,
		path_transform_type_nv transform_type,
		span<const GLfloat> transform_values
	) noexcept;

	template <typename S>
	static
	outcome<void>
	cover_fill_path_instanced(
		cstring_span<> indices,
		const object_names<tag::path_nv, S>& paths,
		path_fill_cover_mode_nv mode,
		path_transform_type_nv transform_type,
		span<const GLfloat> transform_values
	) noexcept;

	template <typename S, typename T>
	static
	outcome<void>
	stencil_stroke_path_instanced(
		span<T> indices,
		const object_names<tag::path_nv, S>& paths,
		GLint reference,
		GLuint mask,
		path_transform_type_nv transform_type,
		span<const GLfloat> transform_values
	) noexcept;

	template <typename S>
	static
	outcome<void>
	stencil_stroke_path_instanced(
		cstring_span<> indices,
		const object_names<tag::path_nv, S>& paths,
		GLint reference,
		GLuint mask,
		path_transform_type_nv transform_type,
		span<const GLfloat> transform_values
	) noexcept;

	template <typename S, typename T>
	static
	outcome<void>
	cover_stroke_path_instanced(
		span<T> indices,
		const object_names<tag::path_nv, S>& paths,
		path_stroke_cover_mode_nv mode,
		path_transform_type_nv transform_type,
		span<const GLfloat> transform_values
	) noexcept;

	template <typename S>
	static
	outcome<void>
	cover_stroke_path_instanced(
		cstring_span<> indices,
		const object_names<tag::path_nv, S>& paths,
		path_stroke_cover_mode_nv mode,
		path_transform_type_nv transform_type,
		span<const GLfloat> transform_values
	) noexcept;
};

} // namespace oper

template <typename Derived, typename Base>
struct path_nv_array_member_ops
 : Base
{
private:
	Derived& _self()
	noexcept
	{
		return *static_cast<Derived*>(this);
	}

	typedef oper::path_nv_array_ops _ops;
protected:
	using Base::Base;
public:
	template <typename T>
	outcome<Derived&>
	glyphs(
		path_font_target_nv font_target,
		cstr_ref font_name,
		enum_bitfield<path_font_style_nv> font_style,
		T&& char_codes,
		path_missing_glyph_nv handle_missing_glyphs,
		GLuint parameter_template,
		GLfloat em_scale
	) noexcept
	{
		return {_ops::path_glyphs(
			*this,
			font_target, font_name,
			font_style,
			std::forward<T>(char_codes),
			handle_missing_glyphs,
			parameter_template,
			em_scale
		), _self()};
	}

	outcome<Derived&>
	glyph_range(
		path_font_target_nv font_target,
		cstr_ref font_name,
		enum_bitfield<path_font_style_nv> font_style,
		GLuint first_glyph,
		GLsizei num_glyphs,
		path_missing_glyph_nv handle_missing_glyphs,
		GLuint parameter_template,
		GLfloat em_scale
	) noexcept
	{
		return {_ops::path_glyph_range(
			*this,
			font_target, font_name,
			font_style,
			first_glyph,
			num_glyphs,
			handle_missing_glyphs,
			parameter_template,
			em_scale
		), _self()};
	}

	template <typename T>
	outcome<Derived&>
	get_spacing(
		path_list_mode_nv list_mode,
		T&& indices,
		GLfloat advance_scale,
		GLfloat kerning_scale,
		path_transform_type_nv transform_type,
		span<GLfloat> returned_values
	) noexcept
	{
		return {_ops::get_path_spacing(
			list_mode,
			std::forward<T>(indices),
			*this,
			advance_scale,
			kerning_scale,
			transform_type,
			returned_values
		), _self()};
	}

	template <typename T>
	outcome<Derived&>
	get_metrics(
		enum_bitfield<path_metric_query_nv> query_mask,
		T&& indices,
		GLsizei stride,
		span<GLfloat> returned_values
	) noexcept
	{
		return {_ops::get_path_metrics(
			query_mask,
			std::forward<T>(indices),
			*this,
			stride,
			returned_values
		), _self()};
	}

	outcome<Derived&>
	get_metric_range(
		enum_bitfield<path_metric_query_nv> query_mask,
		GLsizei num_paths,
		GLsizei stride,
		span<GLfloat> returned_values
	) noexcept
	{
		return {_ops::get_path_metric_range(
			query_mask,
			*this,
			num_paths,
			stride,
			returned_values
		), _self()};
	}

	template <typename T>
	outcome<Derived&>
	stencil_fill_instanced(
		T&& indices,
		path_fill_mode_nv mode,
		GLuint mask,
		path_transform_type_nv transform_type,
		span<const GLfloat> transform_values
	) noexcept
	{
		return {_ops::stencil_fill_path_instanced(
			std::forward<T>(indices),
			*this,
			mode,
			mask,
			transform_type,
			transform_values
		), _self()};
	}

	template <typename T>
	outcome<Derived&>
	cover_fill_instanced(
		T&& indices,
		path_fill_cover_mode_nv mode,
		path_transform_type_nv transform_type,
		span<const GLfloat> transform_values
	) noexcept
	{
		return {_ops::cover_fill_path_instanced(
			std::forward<T>(indices),
			*this,
			mode,
			transform_type,
			transform_values
		), _self()};
	}

	template <typename T>
	outcome<Derived&>
	stencil_stroke_instanced(
		T&& indices,
		GLint reference,
		GLuint mask,
		path_transform_type_nv transform_type,
		span<const GLfloat> transform_values
	) noexcept
	{
		return {_ops::stencil_stroke_path_instanced(
			std::forward<T>(indices),
			*this,
			reference,
			mask,
			transform_type,
			transform_values
		), _self()};
	}

	template <typename T>
	outcome<Derived&>
	cover_stroke_instanced(
		T&& indices,
		path_stroke_cover_mode_nv mode,
		path_transform_type_nv transform_type,
		span<const GLfloat> transform_values
	) noexcept
	{
		return {_ops::cover_stroke_path_instanced(
			std::forward<T>(indices),
			*this,
			mode,
			transform_type,
			transform_values
		), _self()};
	}
};

class paths_nv
 : public path_nv_array_member_ops<paths_nv, path_nv_vector>
{
public:
	paths_nv(std::size_t count)
	 : path_nv_array_member_ops<paths_nv, path_nv_vector>(count)
	{ }
};

} // namespace oglplus

#include <oglplus/path_nv_array.inl>

#endif // include guard
