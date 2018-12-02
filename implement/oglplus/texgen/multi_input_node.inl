/**
 *  @file oglplus/texgen/multi_input_node.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <cassert>
#include <iostream>

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
multi_input_output::multi_input_output(node_intf& parent)
  : base_output(parent)
  , _input(parent, cstr_ref("Input"), 0.f, 0.f, 0.f, 0.f) {
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type
multi_input_output::common_param_type() {
    slot_data_type result = _input.value_type();

    for(auto i = _inputs.begin(); i != _inputs.end(); ++i) {
        result = common_data_type(result, i->second.value_type());
    }

    return result;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
span_size_t
multi_input_node::input_count() {
    return 1 + span_size(single_output()._inputs.size());
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
input_intf&
multi_input_node::input(span_size_t index) {
    if(index == 0)
        return single_output()._input;
    assert(index < input_count());

    auto p = single_output()._inputs.begin();
    while(--index > 0) {
        assert(p != single_output()._inputs.end());
        p++;
    }
    assert(p != single_output()._inputs.end());
    return p->second;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
eagine::optional_reference_wrapper<input_intf>
multi_input_node::input_by_name(const cstr_ref& name) {
    auto p = single_output()._inputs.find(name.str());
    if(p != single_output()._inputs.end()) {
        return p->second;
    }
    return nullptr;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
multi_input_node::can_add_input() {
    return true;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
input_with_const_default<float[4]>&
multi_input_node::add_input(const cstr_ref& name) {
    auto p = single_output()._inputs.emplace(
      name.str(),
      input_with_const_default<float[4]>(*this, name, 0.f, 0.f, 0.f, 0.f));
    p.first->second.set_name(cstr_ref(
      p.first->first.data(), eagine::span_size_t(p.first->first.size())));
    return p.first->second;
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------
