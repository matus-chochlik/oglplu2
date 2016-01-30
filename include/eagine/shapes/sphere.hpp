/**
 *  @file eagine/shapes/sphere.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPES_SPHERE_1509260923_HPP
#define EAGINE_SHAPES_SPHERE_1509260923_HPP

#include "gen_base.hpp"
#include "../config/basic.hpp"
#include "../valid_if.hpp"
#include <cassert>

namespace eagine {
namespace shapes {

class unit_sphere_gen
 : public generator_base
{
private:
	unsigned _rings;
	unsigned _sections;

	static
	vertex_attrib_bits _attr_mask(void)
	noexcept;
public:
	unit_sphere_gen(
		vertex_attrib_bits attr_bits,
		valid_if_greater_than<int, 2> rings,
		valid_if_greater_than<int, 3> sections
	) noexcept;

	unit_sphere_gen(vertex_attrib_bits attr_bits)
	noexcept
	 : unit_sphere_gen(attr_bits, 12, 18)
	{ }

	bool cw_face_winding(void)
	override;

	unsigned vertex_count(void)
	override;

	void positions(span<float> dest)
	noexcept;

	void normals(span<float> dest)
	noexcept;

	void tangentials(span<float> dest)
	noexcept;

	void bitangentials(span<float> dest)
	noexcept;

	void box_coords(span<float> dest)
	noexcept;

	void wrap_coords(span<float> dest)
	noexcept;

	void attrib_values(vertex_attrib_kind attr, span<float> dest)
	override;

	index_data_type index_type(void)
	override;

	unsigned index_count(void)
	override;

	void indices(span<unsigned> dest)
	override;

	unsigned operation_count(void)
	override;

	void instructions(span<draw_operation> ops)
	override;
};

} // namespace shapes
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/shapes/sphere.inl>
#endif

#endif // include guard
