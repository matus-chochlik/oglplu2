/**
 *  @file oglplus/texgen/base_node.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/assert.hpp>
#include <eagine/maybe_unused.hpp>

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
span_size_t
base_node::input_count(void) {
    return 0;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
input_intf&
base_node::input(span_size_t) {
    EAGINE_ABORT("Node does not have any inputs");
    input_intf* dummy = nullptr;
    assert(dummy != nullptr);
    return *dummy;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
base_node::can_add_input(void) {
    return false;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
input_intf&
base_node::add_input(const cstr_ref&) {
    EAGINE_ABORT("Node cannot add any inputs");
    return input(0);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
span_size_t
base_node::output_count(void) {
    return 0;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
output_intf&
base_node::output(span_size_t) {
    EAGINE_ABORT("Node does not have any outputs");
    output_intf* dummy = nullptr;
    assert(dummy != nullptr);
    return *dummy;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void
base_node::update_needed(void) {
    for(span_size_t i = 0, n = output_count(); i < n; ++i) {
        output(i).notify_connected();
    }
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void
base_node::prepare(void) {
    for(span_size_t i = 0, n = input_count(); i < n; ++i) {
        input(i).prepare_connected();
    }
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
base_node::render(const render_params& params) {
    if(auto n = input_count()) {
        while(_render_input < n) {
            if(input(_render_input).render_connected(params)) {
                ++_render_input;
            } else
                return false;
        }
        _render_input = 0;
    }
    return true;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
base_single_output_node::type_name(void) {
    return single_output().type_name();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
span_size_t
base_single_output_node::output_count(void) {
    return 1;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
output_intf&
base_single_output_node::output(span_size_t index) {
    EAGINE_MAYBE_UNUSED(index);
    assert(index == 0);
    return single_output();
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------
