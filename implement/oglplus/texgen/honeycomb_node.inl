/**
 *  @file oglplus/texgen/honeycomb_node.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/assert.hpp>
#include <eagine/maybe_unused.hpp>
#include <iostream>

namespace eagine {
namespace oglp {
namespace texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
honeycomb_output::honeycomb_output(
  node_intf& parent,
  input_with_const_default<float[2]>& cells,
  honeycomb_direction& direction,
  honeycomb_output_type type)
  : base_output(parent)
  , _cells(cells)
  , _direction(direction)
  , _type(type) {
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
string_view honeycomb_output::type_abbr() const {
    switch(_type) {
        case honeycomb_output_type::distance:
            return string_view("Dist");
        case honeycomb_output_type::cell_coord:
            return string_view("CCrd");
        case honeycomb_output_type::cell_center:
            return string_view("CCtr");
    }
    return string_view();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
string_view honeycomb_output::type_name() {
    return string_view("Honeycomb");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type honeycomb_output::value_type() {
    switch(_type) {
        case honeycomb_output_type::cell_coord:
        case honeycomb_output_type::cell_center:
            return slot_data_type::float_2;
        case honeycomb_output_type::distance:
            break;
    }
    return slot_data_type::float_;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& honeycomb_output::definitions(
  std::ostream& out, compile_context& ctxt) {
    if(already_defined(ctxt)) {
        return out;
    }

    input_defs(out, ctxt);

    out << expr::nhood2d_offs_decl{ctxt} << std::endl;

    opening_expr(out, ctxt);

    slot_data_type v2 = slot_data_type::float_2;

    out << "\tfloat min_dist = 2.0;" << std::endl;

    if(_type == honeycomb_output_type::cell_coord) {
        out << "\tvec2 min_cell_coord;" << std::endl;
    } else if(_type == honeycomb_output_type::cell_center) {
        out << "\tvec2 min_cell_center;" << std::endl;
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

    /*
        out << "\tvec2 cell_coord = floor(norm_coord*cell_count);";
        out << "\t\tfloat stripes = mod(floor(cell_coord.";
        switch(_direction)
        {
            case honeycomb_direction::vertical:
                out << "y";
                break;
            case honeycomb_direction::horizontal:
                out << "x";
                break;
        }
        out << "), 2.0);" << std::endl;
        out << "\treturn vec2(stripes);" << std::endl;
    */
    out << "\tfor(int i=0; i<9; ++i)" << std::endl;
    out << "\t{" << std::endl;
    out << "\t\tvec2 cell_offs = " << expr::nhood2d_offs{} << "[i];";
    out << std::endl;
    out << "\t\tvec2 cell_coord = floor(norm_coord*cell_count+cell_offs);";
    out << std::endl;

    out << "\t\tfloat stripes = mod(floor(cell_coord.";
    switch(_direction) {
        case honeycomb_direction::vertical:
            out << "y";
            break;
        case honeycomb_direction::horizontal:
            out << "x";
            break;
    }
    out << "), 2.0);" << std::endl;

    out << "\t\tvec2 rel_cell_center = mix(";
    switch(_direction) {
        case honeycomb_direction::vertical:
            out << "vec2(0.5, 0.5), vec2(0.0, 0.5),";
            break;
        case honeycomb_direction::horizontal:
            out << "vec2(0.5, 0.0), vec2(0.5, 0.5),";
            break;
    }
    out << "stripes);" << std::endl;

    out << "\t\tcell_coord *= cell_size;" << std::endl;

    out << "\t\tvec2 abs_cell_center = cell_coord+";
    out << "(cell_size*rel_cell_center);" << std::endl;
    out << "\t\tfloat dist = distance(";
    out << "norm_coord, abs_cell_center);" << std::endl;
    out << std::endl;
    out << "\t\tif(min_dist > dist)" << std::endl;
    out << "\t\t{" << std::endl;
    out << "\t\t\tmin_dist = dist;" << std::endl;

    if(_type == honeycomb_output_type::cell_coord) {
        out << "\t\t\tmin_cell_coord = cell_coord;";
        out << std::endl;
    } else if(_type == honeycomb_output_type::cell_center) {
        out << "\t\t\tmin_cell_center = abs_cell_center;";
        out << std::endl;
    }

    out << "\t\t}" << std::endl;
    out << "\t}" << std::endl;

    switch(_type) {
        case honeycomb_output_type::distance:
            out << "\treturn min_dist*";
            out << "min(cell_count.x, cell_count.y)/sqrt(2.0);";
            break;
        case honeycomb_output_type::cell_coord:
            out << "\treturn min_cell_coord;";
            break;
        case honeycomb_output_type::cell_center:
            out << "\treturn min_cell_center;";
            break;
    }
    out << std::endl;

    return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& honeycomb_output::expression(
  std::ostream& out, compile_context&) {
    append_id(out);
    return out << type_abbr();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
honeycomb_node::honeycomb_node()
  : base_node()
  , _cells(*this, string_view("Cells"), 32.f, 32.f)
  , _cell_coord(*this, _cells, _direction, honeycomb_output_type::cell_coord)
  , _cell_center(*this, _cells, _direction, honeycomb_output_type::cell_center)
  , _distance(*this, _cells, _direction, honeycomb_output_type::distance) {
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
string_view honeycomb_node::type_name() {
    return string_view("Honeycomb");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
span_size_t honeycomb_node::input_count() {
    return 1;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
input_intf& honeycomb_node::input(span_size_t index) {
    EAGINE_MAYBE_UNUSED(index);
    EAGINE_ASSERT(index < input_count());
    return _cells;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
span_size_t honeycomb_node::output_count() {
    return 3;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
output_intf& honeycomb_node::output(span_size_t index) {
    if(index == 0) {
        return _cell_coord;
    }
    if(index == 1) {
        return _cell_center;
    }
    EAGINE_ASSERT(index < output_count());
    return _distance;
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglp
} // namespace eagine
//------------------------------------------------------------------------------
