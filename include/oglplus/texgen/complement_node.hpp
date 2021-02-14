/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OGLPLUS_TEXGEN_COMPLEMENT_NODE_HPP
#define OGLPLUS_TEXGEN_COMPLEMENT_NODE_HPP

#include "base_node.hpp"
#include "fallback_input.hpp"

namespace eagine::oglp::texgen {

class complement_input : public input_with_const_default<float[4]> {
private:
    using _base = input_with_const_default<float[4]>;

public:
    complement_input(
      node_intf& parent,
      string_view name,
      float r,
      float g,
      float b,
      float a)
      : _base(parent, name, r, g, b, a) {}

    bool accepts_value_type(slot_data_type type) override {
        return data_type_dims(type) == data_type_dims(output().value_type());
    }
};

class complement_output : public base_output {
public:
    input_with_const_default<float[4]> input;
    input_with_const_default<float[4]> complement;

    complement_output(node_intf& parent);

    string_view type_name() override;

    slot_data_type value_type() override;

    std::ostream& definitions(std::ostream& out, compile_context& ctxt) override;
};

class complement_node
  : public binary_single_output_node<
      complement_output,
      decltype(complement_output::input),
      &complement_output::input,
      decltype(complement_output::complement),
      &complement_output::complement> {
public:
    complement_node& set_complement(float r, float g, float b, float a) {
        _output.complement.fallback().set(r, g, b, a);
        return *this;
    }
};

} // namespace eagine::oglp::texgen

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/complement_node.inl>
#endif

#endif // OGLPLUS_TEXGEN_COMPLEMENT_NODE_HPP
