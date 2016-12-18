/**
 *  @file eagine/shapes/screen.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPES_SCREEN_1509260923_HPP
#define EAGINE_SHAPES_SCREEN_1509260923_HPP

#include "gen_base.hpp"
#include <eagine/config/basic.hpp>
#include <cassert>

namespace eagine {
namespace shapes {

class unit_screen_gen
 : public centered_unit_shape_generator_base
{
private:
	typedef centered_unit_shape_generator_base _base;

	static
	vertex_attrib_bits _attr_mask(void)
	noexcept;
public:
	unit_screen_gen(vertex_attrib_bits attr_bits)
	noexcept;

	bool cw_face_winding(void)
	override;

	span_size_t vertex_count(void)
	override;

	void positions(const span<float>& dest)
	noexcept;

	void normals(const span<float>& dest)
	noexcept;

	void tangentials(const span<float>& dest)
	noexcept;

	void bitangentials(const span<float>& dest)
	noexcept;

	void face_coords(const span<float>& dest)
	noexcept;

	void attrib_values(vertex_attrib_kind attr, const span<float>& dest)
	override;

	index_data_type index_type(void)
	override;

	span_size_t index_count(void)
	override;

	void indices(const span<unsigned>& dest)
	override;

	span_size_t operation_count(void)
	override;

	void instructions(const span<draw_operation>& ops)
	override;
};

} // namespace shapes
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/shapes/screen.inl>
#endif

#endif // include guard
