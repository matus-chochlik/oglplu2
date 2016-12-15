/**
 *  @file oglplus/texgen/voronoi2d_node.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
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
short
voronoi2d_output::order(void) const
{
	switch(_type)
	{
		case voronoi_output_type::distance3:
			return 3;
		case voronoi_output_type::distance2:
			return 2;
		case voronoi_output_type::distance1:
		case voronoi_output_type::cell_coord:
		case voronoi_output_type::cell_center:
			return 1;
		case voronoi_output_type::input_cell_center:
			break;
	}
	return 0;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
voronoi2d_output::type_abbr(void) const
{
	switch(_type)
	{
		case voronoi_output_type::distance1:
			return cstr_ref("Dist");
		case voronoi_output_type::distance2:
			return cstr_ref("Dist2");
		case voronoi_output_type::distance3:
			return cstr_ref("Dist3");
		case voronoi_output_type::cell_coord:
			return cstr_ref("CCrd");
		case voronoi_output_type::cell_center:
			return cstr_ref("CCtr");
		case voronoi_output_type::input_cell_center:
			return cstr_ref("InCell");
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
		case voronoi_output_type::distance1:
		case voronoi_output_type::distance2:
		case voronoi_output_type::distance3:
			return slot_data_type::float_;
		case voronoi_output_type::cell_coord:
		case voronoi_output_type::cell_center:
			return slot_data_type::float_2;
		case voronoi_output_type::input_cell_center:
			break;
	}
	return _input.value_type();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
voronoi2d_output::name(void)
noexcept
{
	return type_abbr();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
voronoi2d_output::definitions(std::ostream& out, compile_context& ctxt)
{
	if(already_defined(ctxt)) return out;

	input_defs(out, ctxt);

	out << expr::nhood2d_offs_decl{ctxt} << std::endl;

	opening_expr(out, ctxt);

	slot_data_type v2 = slot_data_type::float_2;
	const short ord = order();

	if(_type != voronoi_output_type::input_cell_center)
	{
		out << "\tfloat min_dist[" << ord << "];" << std::endl;
		for(short o=0; o<ord; ++o)
		{
			out << "\tmin_dist[" << o << "] = 2.0;" << std::endl;
		}
	}

	if(_type == voronoi_output_type::cell_coord)
	{
		out << "\tvec2 min_cell_coord[" << ord << "];" << std::endl;
	}
	else if(_type == voronoi_output_type::cell_center)
	{
		out << "\tvec2 min_cell_center[" << ord << "];" << std::endl;
	}

	out << "\tvec2 norm_coord = vec2(";
	out << expr::norm_sample_coord{*this} << ");" << std::endl;
	out << "\tvec2 cell_count = ";
	out << expr::conversion_prefix{_cells.value_type(), v2};
	out << expr::output_id{_cells.output(), ctxt};
	out << expr::render_param_pass{_cells.output()};
	out << expr::conversion_suffix{_cells.value_type(), v2};
	out << ";" << std::endl;
	out << "\tvec2 cell_size = vec2(1)/max(cell_count,vec2(1));";
	out << std::endl;

	if(_type == voronoi_output_type::input_cell_center)
	{
		slot_data_type vt = value_type();

		out << "\tvec2 cell_coord = floor(norm_coord*cell_count)*";
		out << "cell_size;" << std::endl;
		out << "\treturn ";
		out << expr::conversion_prefix{_input.value_type(), vt};
		out << expr::output_id{_input.output(), ctxt};

		if(_input.output().needs_params())
		{
			out << "(" << std::endl;
			out << "\t\tvec3(cell_coord,0)," << std::endl;
			out << "\t\tvec3(cell_size, 1)," << std::endl;
			out << "\t\tvec3(0)" << std::endl;
			out << "\t)";
		}
		out << expr::conversion_suffix{_input.value_type(), vt};
		out << ";" << std::endl;
		return closing_expr(out, ctxt);
	}

	out << "\tfor(int i=0; i<9; ++i)" << std::endl;
	out << "\t{" << std::endl;
	out << "\t\tvec2 cell_offs = " << expr::nhood2d_offs{} << "[i];";
	out << std::endl;
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
	out << "\t\tvec2 abs_cell_center = cell_coord+";
	out << "rel_cell_center*cell_size;" << std::endl;
	out << "\t\tfloat dist = distance(";
	out << "norm_coord, abs_cell_center);" << std::endl;
	out << std::endl;
	out << "\t\tfor(int o=0; o<" << ord << "; ++o)" << std::endl;
	out << "\t\t{" << std::endl;
	out << "\t\t\tif(min_dist[o] > dist)" << std::endl;
	out << "\t\t\t{" << std::endl;
	out << "\t\t\t\tfor(int k=" << ord-1 << "; k>o; --k)" << std::endl;
	out << "\t\t\t\t{" << std::endl;
	out << "\t\t\t\t\tmin_dist[k] = min_dist[k-1];" << std::endl;

	if(_type == voronoi_output_type::cell_coord)
	{
		out << "\t\t\t\t\tmin_cell_coord[k] = min_cell_coord[k-1];";
		out << std::endl;
	}
	else if(_type == voronoi_output_type::cell_center)
	{
		out << "\t\t\t\t\tmin_cell_center[k] = min_cell_center[k-1];";
		out << std::endl;
	}

	out << "\t\t\t\t}" << std::endl;
	out << "\t\t\t\tmin_dist[o] = dist;" << std::endl;

	if(_type == voronoi_output_type::cell_coord)
	{
		out << "\t\t\t\tmin_cell_coord[o] = cell_coord;";
		out << std::endl;
	}
	else if(_type == voronoi_output_type::cell_center)
	{
		out << "\t\t\t\tmin_cell_center[o] = abs_cell_center;";
		out << std::endl;
	}

	out << "\t\t\t\tbreak;" << std::endl;
	out << "\t\t\t}" << std::endl;
	out << "\t\t}" << std::endl;
	out << "\t}" << std::endl;

	switch(_type)
	{
		case voronoi_output_type::distance1:
		case voronoi_output_type::distance2:
		case voronoi_output_type::distance3:
			out << "\treturn min_dist[" << (ord-1) << "]*";
			out << "min(cell_count.x, cell_count.y)/sqrt(2.0);";
			break;
		case voronoi_output_type::cell_coord:
			out << "\treturn min_cell_coord[" << (ord-1) << "];";
			break;
		case voronoi_output_type::cell_center:
			out << "\treturn min_cell_center[" << (ord-1) << "];";
			break;
		case voronoi_output_type::input_cell_center:
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
 , _distance1(*this, _input, _cells, voronoi_output_type::distance1)
 , _distance2(*this, _input, _cells, voronoi_output_type::distance2)
 , _distance3(*this, _input, _cells, voronoi_output_type::distance3)
 , _cell_coord(*this, _input, _cells, voronoi_output_type::cell_coord)
 , _cell_center(*this, _input, _cells, voronoi_output_type::cell_center)
 , _input_cell_center(*this, _input, _cells, voronoi_output_type::input_cell_center)
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
span_size_t
voronoi2d_node::input_count(void)
{
	return 2;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
input_intf&
voronoi2d_node::input(span_size_t index)
{
	if(index == 0) return _input;
	assert(index < input_count());
	return _cells;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
span_size_t
voronoi2d_node::output_count(void)
{
	return 6;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
output_intf&
voronoi2d_node::output(span_size_t index)
{
	if(index == 0) return _distance1;
	if(index == 1) return _distance2;
	if(index == 2) return _distance3;
	if(index == 3) return _cell_coord;
	if(index == 4) return _cell_center;
	assert(index < output_count());
	return _input_cell_center;
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------

