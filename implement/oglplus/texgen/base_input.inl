/**
 *  @file oglplus/texgen/base_input.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <cassert>
#include <string>

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
base_input::name() noexcept {
    return _name;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
base_input::~base_input() noexcept {
    assert(!is_connected());
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
base_input::is_connected() noexcept {
    return _output != nullptr;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
base_input::is_connected(output_intf& output) {
    return _output == std::addressof(output);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
base_input::can_connect(output_intf& output) {
    return accepts_value_type(output.value_type());
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
base_input::do_connect(output_intf& output) {
    if(can_connect(output)) {
        assert(!is_connected());
        _output = std::addressof(output);
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
base_input::connect(output_intf& output) {
    if(do_connect(output)) {
        try {
            parent().update_needed();
            return true;
        } catch(...) {
            _output = nullptr;
            throw;
        }
    }
    return false;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void
base_input::disconnect() {
    _output = nullptr;
    parent().update_needed();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
base_input::disconnect(output_intf& output) {
    if(is_connected(output)) {
        disconnect();
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
output_intf&
base_input::connected_output() {
    assert(is_connected());
    return *_output;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
base_input::set_default_value(
  eagine::valid_if_between<span_size_t, 0, 3>, float) {
    return false;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void
base_input::update_needed() {
    parent().update_needed();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void
base_input::prepare_connected() {
    if(is_connected()) {
        return connected_output().prepare_parent();
    }
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
base_input::render_connected(const render_params& params) {
    if(is_connected()) {
        return connected_output().render_parent(params);
    }
    return true;
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------
