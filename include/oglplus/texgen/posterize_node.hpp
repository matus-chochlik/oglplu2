/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OGLPLUS_TEXGEN_POSTERIZE_NODE_HPP
#define OGLPLUS_TEXGEN_POSTERIZE_NODE_HPP

#include "base_node.hpp"
#include "fallback_input.hpp"

namespace eagine::oglp::texgen {

class posterize_output : public base_output {
public:
    input_with_const_default<float[4]> input;
    input_with_const_default<float[4]> levels;

    posterize_output(node_intf& parent);

    string_view type_name() override;

    slot_data_type value_type() override;

    std::ostream& definitions(std::ostream& out, compile_context& ctxt) override;
};

class posterize_node
  : public binary_single_output_node<
      posterize_output,
      decltype(posterize_output::input),
      &posterize_output::input,
      decltype(posterize_output::levels),
      &posterize_output::levels> {
public:
    posterize_node& set_levels(float r, float g, float b, float a) {
        _output.levels.fallback().set(r, g, b, a);
        return *this;
    }
};

} // namespace eagine::oglp::texgen

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/posterize_node.inl>
#endif

#endif // OGLPLUS_TEXGEN_POSTERIZE_NODE_HPP
