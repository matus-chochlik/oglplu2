/**
 *  @file oglplus/texgen/uniform_node.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/program.hpp>
#include <cassert>
#include <iostream>
#include <sstream>

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
uniform_output::uniform_output(node_intf& parent, slot_data_type type)
  : base_output(parent)
  , _value_type(type) {
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void uniform_output::bind_location() {
    std::stringstream id;
    append_id(id);
    id << "u";

    _location = prog_var_loc_ops<tag::uniform>::get_location(
      oper::program_ops::current_program(), string_view(id.str()));
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
string_view uniform_output::type_name() {
    return string_view("Uniform");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type uniform_output::value_type() {
    return _value_type;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
uniform_output::definitions(std::ostream& out, compile_context& ctxt) {
    if(already_defined(ctxt))
        return out;

    input_defs(out, ctxt);

    out << "uniform " << data_type_name(value_type()) << " ";
    out << expr::output_id{*this, ctxt} << "u;" << std::endl;

    opening_expr(out, ctxt);

    out << "\treturn ";
    out << expr::output_id{*this, ctxt} << "u;" << std::endl;

    return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
uniform_node::uniform_node(slot_data_type type)
  : single_output_node<uniform_output>(type) {
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
uniform_node::uniform_node()
  : uniform_node(slot_data_type::float_4) {
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void uniform_node::prepare() {
    _output.bind_location();
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------
