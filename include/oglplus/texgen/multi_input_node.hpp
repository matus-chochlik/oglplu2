/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OGLPLUS_TEXGEN_MULTI_INPUT_NODE_HPP
#define OGLPLUS_TEXGEN_MULTI_INPUT_NODE_HPP

#include "base_node.hpp"
#include "fallback_input.hpp"
#include <map>

namespace eagine::oglp::texgen {

class multi_input_output : public base_output {
protected:
    friend class multi_input_node;

    input_with_const_default<float[4]> _input;
    std::map<std::string, input_with_const_default<float[4]>> _inputs;

public:
    multi_input_output(node_intf& parent);

    slot_data_type common_param_type();
};

class multi_input_node : public base_single_output_node {
public:
    multi_input_output& single_output() override = 0;

    span_size_t input_count() override;

    input_intf& input(span_size_t) override;

    optional_reference_wrapper<input_intf> input_by_name(string_view) override;

    bool can_add_input() override;

    input_with_const_default<float[4]>& add_input(string_view) override;

    multi_input_node&
    add_input(string_view name, float x, float y, float z, float w) {
        add_input(name).fallback().set(x, y, z, w);
        return *this;
    }

    multi_input_node& set_value(float x, float y, float z, float w) {
        single_output()._input.fallback().set(x, y, z, w);
        return *this;
    }
};

} // namespace eagine::oglp::texgen

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/multi_input_node.inl>
#endif

#endif // OGLPLUS_TEXGEN_MULTI_INPUT_NODE_HPP
