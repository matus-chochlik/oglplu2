/**
 *  @file oglplus/texgen/posterize_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_LEVELS_NODE_1509260923_HPP
#define OGLPLUS_TEXGEN_LEVELS_NODE_1509260923_HPP

#include "base_node.hpp"
#include "fallback_input.hpp"

namespace oglplus {
namespace texgen {

class posterize_output : public base_output {
public:
    input_with_const_default<float[4]> input;
    input_with_const_default<float[4]> levels;

    posterize_output(node_intf& parent);

    cstr_ref type_name() override;

    slot_data_type value_type() override;

    std::ostream& definitions(
      std::ostream& out, compile_context& ctxt) override;
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

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/posterize_node.inl>
#endif

#endif // include guard
