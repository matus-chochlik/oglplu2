/**
 *  @file eagine/shapes/cube.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPES_CUBE_1509260923_HPP
#define EAGINE_SHAPES_CUBE_1509260923_HPP

#include "gen_base.hpp"
#include <eagine/config/basic.hpp>
#include <cassert>

namespace eagine {
namespace shapes {

class unit_cube_gen
 : public generator_base
{
private:
	static
	vertex_attrib_bits _attr_mask(void)
	noexcept;

	static
	vertex_attrib_bits _shared_attrs(void)
	noexcept;

	bool _only_shared_attribs(void) const
	noexcept;

	static
	int _coord_c(unsigned v, unsigned c)
	noexcept;

	static
	int _normal_c(unsigned f, unsigned c)
	noexcept;

	static
	int _tangential_c(unsigned f, unsigned c)
	noexcept;

	static
	int _bitangential_c(unsigned f, unsigned c)
	noexcept;

	template <typename T>
	void _indices(span<T>& dest)
	noexcept;

	static
	unsigned _face_vert(unsigned f, unsigned t, unsigned v)
	noexcept;
public:
	unit_cube_gen(vertex_attrib_bits attr_bits)
	noexcept;

	bool cw_face_winding(void)
	override;

	unsigned vertex_count(void)
	override;

	void box_coords(span<float> dest)
	noexcept;

	void positions(span<float> dest)
	noexcept;

	void normals(span<float> dest)
	noexcept;

	void tangentials(span<float> dest)
	noexcept;

	void bitangentials(span<float> dest)
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
#include <eagine/shapes/cube.inl>
#endif

#endif // include guard
