/**
 *  @file oglplus/texgen/voronoi2d_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_VORONOI2D_NODE_1509260923_HPP
#define OGLPLUS_TEXGEN_VORONOI2D_NODE_1509260923_HPP

#include "fallback_input.hpp"
#include "base_node.hpp"

namespace oglplus {
namespace texgen {

enum class voronoi_output_type
{
	distance1,
	distance2,
	distance3,
	cell_coord,
	cell_center
};

class voronoi2d_output
 : public base_output
{
private:
	input_with_const_default<float[2]>& _input;
	input_with_const_default<float[2]>& _cells;
	voronoi_output_type _type;

	short order(void) const;

	cstr_ref type_abbr(void) const;
public:

	voronoi2d_output(
		node_intf& parent,
		input_with_const_default<float[2]>&,
		input_with_const_default<float[2]>&,
		voronoi_output_type type
	);

	cstr_ref type_name(void)
	override;

	slot_data_type value_type(void)
	override;

	std::ostream& definitions(std::ostream& out, compile_context& ctxt)
	override;

	std::ostream& expression(std::ostream& out, compile_context& ctxt)
	override;
};

class voronoi2d_node
 : public base_node
{
private:
	input_with_const_default<float[2]> _input;
	input_with_const_default<float[2]> _cells;

	voronoi2d_output _distance1;
	voronoi2d_output _distance2;
	voronoi2d_output _distance3;
	voronoi2d_output _cell_coord;
	voronoi2d_output _cell_center;
public:
	voronoi2d_node(void);

	voronoi2d_node&
	set_cell_count(float x, float y)
	{
		_cells.fallback().set(x, y);
		return *this;
	}

	cstr_ref type_name(void)
	override;

	std::size_t input_count(void)
	override;

	input_intf& input(std::size_t index)
	override;

	std::size_t output_count(void)
	override;

	output_intf& output(std::size_t index)
	override;
};

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/voronoi2d_node.inl>
#endif

#endif // include guard
