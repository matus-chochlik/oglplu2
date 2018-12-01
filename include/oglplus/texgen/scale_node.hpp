/**
 *  @file oglplus/texgen/scale_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_SCALE_NODE_1509260923_HPP
#define OGLPLUS_TEXGEN_SCALE_NODE_1509260923_HPP

#include "base_node.hpp"
#include "fallback_input.hpp"

namespace oglplus {
namespace texgen {

class scale_output : public base_output {
public:
    input_with_const_default<float[4]> input;
    input_with_const_default<float[3]> scale;

    scale_output(node_intf& parent);

    cstr_ref type_name(void) override;

    slot_data_type value_type(void) override;

    std::ostream& definitions(
      std::ostream& out, compile_context& ctxt) override;
};

class scale_node
  : public binary_single_output_node<
      scale_output,
      decltype(scale_output::input),
      &scale_output::input,
      decltype(scale_output::scale),
      &scale_output::scale> {
public:
    scale_node& set_scale(float x, float y, float z) {
        _output.scale.fallback().set(x, y, z);
        return *this;
    }
};

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/scale_node.inl>
#endif

#endif // include guard
