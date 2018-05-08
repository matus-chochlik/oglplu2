/**
 *  @file oglplus/texgen/split_node.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <cassert>
#include <iostream>
#include <string>

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
split_output::split_output(node_intf& parent,
  input_with_const_default<float[4]>& input,
  eagine::valid_if_between<span_size_t, 0, 3> index)
  : base_output(parent)
  , _input(input)
  , _index(index.value()) {
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
split_output::type_name(void) {
    const cstr_ref names[4] = {
      cstr_ref("Red"), cstr_ref("Green"), cstr_ref("Blue"), cstr_ref("Alpha")};
    return names[_index];
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type
split_output::value_type(void) {
    return make_data_type(elem_data_type(_input.value_type()), 1);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
split_output::definitions(std::ostream& out, compile_context& ctxt) {
    if(already_defined(ctxt))
	return out;

    input_defs(out, ctxt);
    opening_expr(out, ctxt);

    slot_data_type tmp_dt =
      make_data_type(elem_data_type(_input.value_type()), 4);

    out << "\treturn ";
    out << expr::conversion_prefix{_input.value_type(), tmp_dt};
    out << expr::output_id{_input.output(), ctxt};
    out << expr::render_param_pass{_input.output()};
    out << expr::conversion_suffix{_input.value_type(), tmp_dt};
    out << "[" << _index << "]";
    out << ";" << std::endl;

    return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
split_node::type_name(void) {
    return cstr_ref("Split");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
split_node::split_node(void)
  : _input(*this, cstr_ref("Input"))
  , _output_r(*this, _input, 0)
  , _output_g(*this, _input, 1)
  , _output_b(*this, _input, 2)
  , _output_a(*this, _input, 3) {
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
span_size_t
split_node::input_count(void) {
    return 1;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
input_intf&
split_node::input(span_size_t index) {
    assert(index < input_count());
    return _input;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
span_size_t
split_node::output_count(void) {
    return 4u;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
output_intf&
split_node::output(span_size_t index) {
    if(index == 0)
	return _output_r;
    if(index == 1)
	return _output_g;
    if(index == 2)
	return _output_b;
    assert(index < output_count());
    return _output_a;
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------
