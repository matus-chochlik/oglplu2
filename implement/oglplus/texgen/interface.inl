/**
 *  @file oglplus/texgen/interface.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/assert.hpp>
#include <set>
#include <string>

namespace eagine::oglp::texgen {
//------------------------------------------------------------------------------
class compile_context_impl {
private:
    unsigned _glsl_version{0};

    // TODO: string / string_view compare
    std::set<std::string> _tags;
    std::set<std::intptr_t> _outputs;

public:
    compile_context_impl()
      : _glsl_version(150) {
    }

    unsigned glsl_version() const noexcept {
        return _glsl_version;
    }

    void add_tag(string_view tag) {
        _tags.insert(tag.to_string());
    }

    bool has_tag(string_view tag) const noexcept {
        return _tags.find(tag.to_string()) != _tags.end();
    }

    void remember_output(std::intptr_t oid) {
        _outputs.insert(oid);
    }

    bool remembers_output(std::intptr_t oid) const noexcept {
        return _outputs.find(oid) != _outputs.end();
    }
};
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
const compile_context_impl& compile_context::_impl() const noexcept {
    EAGINE_ASSERT(_pimpl != nullptr);
    return *_pimpl;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
compile_context_impl& compile_context::_impl() noexcept {
    EAGINE_ASSERT(_pimpl != nullptr);
    return *_pimpl;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
compile_context::compile_context()
  : _pimpl(std::make_unique<compile_context_impl>()) {
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
compile_context::~compile_context() noexcept {
    _pimpl = {};
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
unsigned compile_context::glsl_version() const {
    return _impl().glsl_version();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void compile_context::add_tag(string_view tag) {
    _impl().add_tag(tag);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool compile_context::has_tag(string_view tag) const noexcept {
    return _impl().has_tag(tag);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void compile_context::remember_constant(const constant_intf& constant) {
    _impl().add_tag(constant.name());
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool compile_context::remembers_constant(
  const constant_intf& constant) const noexcept {
    return _impl().has_tag(constant.name());
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void compile_context::remember_output(const output_intf& output) {
    return _impl().remember_output(
      reinterpret_cast<std::intptr_t>(std::addressof(output)));
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool compile_context::remembers_output(
  const output_intf& output) const noexcept {
    return _impl().remembers_output(
      reinterpret_cast<std::intptr_t>(std::addressof(output)));
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& node_intf::input_definitions(
  std::ostream& out, compile_context& ctxt) {
    for(span_size_t i = 0, n = input_count(); i < n; ++i) {
        input(i).definitions(out, ctxt);
    }
    return out;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
optional_reference_wrapper<input_intf> node_intf::input_by_name(
  string_view name) {
    for(span_size_t i = 0, n = input_count(); i < n; ++i) {
        input_intf& inp = input(i);
        if(are_equal(inp.name(), name)) {
            return inp;
        }
    }
    return nothing;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
optional_reference_wrapper<output_intf> node_intf::output_by_name(
  string_view name) {
    for(span_size_t i = 0, n = output_count(); i < n; ++i) {
        output_intf& outp = output(i);
        if(are_equal(outp.name(), name)) {
            return outp;
        }
    }
    return nothing;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void node_intf::disconnect_all() {
    for(span_size_t i = 0; i < input_count(); ++i) {
        input(i).disconnect();
    }
    for(span_size_t o = 0; o < output_count(); ++o) {
        output(o).disconnect_all();
    }
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool input_slot::is_connected(output_slot& output) {
    return _impl().is_connected(output._impl());
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool input_slot::connect(output_slot& output) {
    return _impl().connect(output._impl());
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool input_slot::disconnect(output_slot& output) {
    return _impl().disconnect(output._impl());
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool output_slot::is_connected(input_slot& input) {
    return _impl().is_connected(input._impl());
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool output_slot::connect(input_slot& input) {
    return _impl().connect(input._impl());
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool output_slot::disconnect(input_slot& input) {
    return _impl().disconnect(input._impl());
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool connect_output_to_input(output_intf& output, input_intf& input) {
    if(input.can_connect(output)) {
        if(output.connect(input)) {
            if(input.connect(output)) {
                return true;
            }
            output.disconnect(input);
        }
    }
    return false;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool disconnect_output_from_input(output_intf& output, input_intf& input) {
    if(input.is_connected(output)) {
        EAGINE_ASSERT(output.is_connected(input));
        input.disconnect(output);
        output.disconnect(input);
    }
    return false;
}
//------------------------------------------------------------------------------
} // namespace eagine::oglp::texgen
//------------------------------------------------------------------------------
