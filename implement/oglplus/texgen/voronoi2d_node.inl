/**
 *  @file oglplus/texgen/voronoi2d_node.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <set>
#include <string>
#include <iostream>
#include <cassert>

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
voronoi2d_output::voronoi2d_output(
	node_intf& parent,
	input_with_const_default<float[2]>& input,
	input_with_const_default<float[2]>& cells,
	voronoi_output_type type
)
 : base_output(parent)
 , _input(input)
 , _cells(cells)
 , _type(type)
{ }
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
voronoi2d_output::type_abbr(void) const
{
	switch(_type)
	{
		case voronoi_output_type::distance:
			return cstr_ref("Dist");
		case voronoi_output_type::cell_coord:
			return cstr_ref("CelC");
	}
	return cstr_ref();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
voronoi2d_output::type_name(void)
{
	return cstr_ref("Voronoi2d");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type
voronoi2d_output::value_type(void)
{
	switch(_type)
	{
		case voronoi_output_type::distance:
			return slot_data_type::float_;
		case voronoi_output_type::cell_coord:
			return slot_data_type::float_2;
	}
	return slot_data_type::float_;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
voronoi2d_output::definitions(std::ostream& out, compile_context& ctxt)
{
	if(already_defined(ctxt)) return out;

	input_defs(out, ctxt);

	cstr_ref tag("nhood2d_cells");
	if(!ctxt.has_tag(tag))
	{
		out << "vec2 oglptgNHood2dCellOffs[9] = vec2[9](" << std::endl;
		out << "\tvec2(-1,-1)," << std::endl;
		out << "\tvec2(-1, 0)," << std::endl;
		out << "\tvec2(-1, 1)," << std::endl;
		out << "\tvec2( 0,-1)," << std::endl;
		out << "\tvec2( 0, 0)," << std::endl;
		out << "\tvec2( 0, 1)," << std::endl;
		out << "\tvec2( 1,-1)," << std::endl;
		out << "\tvec2( 1, 0)," << std::endl;
		out << "\tvec2( 1, 1)"  << std::endl;
		out << ");" << std::endl;
		out << std::endl;
		ctxt.add_tag(tag);
	}

	opening_expr(out, ctxt);

	slot_data_type v2 = slot_data_type::float_2;

	out << "\tfloat min_dist = 2.0;" << std::endl;
	out << "\tint min_index = 5;" << std::endl;

	if(_type == voronoi_output_type::cell_coord)
	{
		out << "\tvec2 min_cell_coord;" << std::endl;
	}

	out << "\tvec2 norm_coord = vec2(";
	out << expr::normalized_coord{*this} << ");" << std::endl;
	out << "\tvec2 cell_count = ";
	out << expr::conversion_prefix{_cells.value_type(), v2};
	out << expr::output_id{_cells.output(), ctxt};
	out << expr::render_param_pass{_cells.output()};
	out << expr::conversion_suffix{_cells.value_type(), v2};
	out << ";" << std::endl;
	out << "\tvec2 cell_size = vec2(1)/max(cell_count,vec2(1));";
	out << std::endl;
	out << "\tfor(int i=0; i<9; ++i)" << std::endl;
	out << "\t{" << std::endl;
	out << "\t\tvec2 cell_offs = oglptgNHood2dCellOffs[i];" << std::endl;
	out << "\t\tvec2 cell_coord = floor(norm_coord*cell_count+cell_offs)*";
	out << "cell_size;" << std::endl;
	out << "\t\tvec2 rel_cell_center = ";
	out << expr::conversion_prefix{_input.value_type(), v2};
	out << expr::output_id{_input.output(), ctxt};

	if(_input.output().needs_params())
	{
		out << "(" << std::endl;
		out << "\t\t\tvec3(cell_coord,0)," << std::endl;
		out << "\t\t\tvec3(cell_size, 1)," << std::endl;
		out << "\t\t\tvec3(0)" << std::endl;
		out << "\t\t)";
	}

	out << expr::conversion_suffix{_input.value_type(), v2};
	out << ";" << std::endl;
	out << "\t\tfloat dist = distance(" << std::endl;
	out << "\t\t\tnorm_coord," << std::endl;
	out << "\t\t\tcell_coord+rel_cell_center*cell_size" << std::endl;
	out << "\t\t);";
	out << std::endl;
	out << "\t\tif(min_dist > dist)" << std::endl;
	out << "\t\t{" << std::endl;
	out << "\t\t\tmin_dist = dist;" << std::endl;
	out << "\t\t\tmin_index = i;" << std::endl;

	if(_type == voronoi_output_type::cell_coord)
	{
		out << "\t\t\tmin_cell_coord = cell_coord;" << std::endl;
	}

	out << "\t\t}" << std::endl;
	out << "\t}" << std::endl;

	switch(_type)
	{
		case voronoi_output_type::distance:
			out << "\treturn min_dist*";
			out << "max(cell_count.x, cell_count.y);";
			break;
		case voronoi_output_type::cell_coord:
			out << "\treturn min_cell_coord;";
			break;
	}
	out << std::endl;

	return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
voronoi2d_output::expression(std::ostream& out, compile_context&)
{
	append_id(out);
	return out << type_abbr();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
voronoi2d_node::voronoi2d_node(void)
 : base_node()
 , _input(*this, cstr_ref("Input"), 0.5f, 0.5f)
 , _cells(*this, cstr_ref("Cells"), 32.f, 32.f)
 , _distance(*this, _input, _cells, voronoi_output_type::distance)
 , _cell_coord(*this, _input, _cells, voronoi_output_type::cell_coord)
{ }
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
voronoi2d_node::type_name(void)
{
	return cstr_ref("Voronoi2D");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::size_t
voronoi2d_node::input_count(void)
{
	return 2u;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
input_intf&
voronoi2d_node::input(std::size_t index)
{
	if(index == 0) return _input;
	assert(index < input_count());
	return _cells;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::size_t
voronoi2d_node::output_count(void)
{
	return 2u;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
output_intf&
voronoi2d_node::output(std::size_t index)
{
	if(index == 0) return _distance;
	assert(index < output_count());
	return _cell_coord;
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------

