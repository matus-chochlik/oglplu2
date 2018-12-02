/**
 *  @file oglplus/texgen/border2d_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_BORDER2D_NODE_1509260923_HPP
#define OGLPLUS_TEXGEN_BORDER2D_NODE_1509260923_HPP

#include <string>
#include "base_node.hpp"
#include "fallback_input.hpp"

namespace oglplus {
namespace texgen {

enum class border2d_mode { min, max };

class border2d_output : public base_output {
public:
    border2d_mode mode;
    input_with_const_default<float[4]> input;

    border2d_output(node_intf& parent);

    cstr_ref type_name() override;

    slot_data_type value_type() override;

    std::ostream& definitions(
      std::ostream& out, compile_context& ctxt) override;
};

class border2d_node
  : public unary_single_output_node<
      border2d_output,
      decltype(border2d_output::input),
      &border2d_output::input> {
public:
    border2d_node() = default;

    border2d_node& set_type(border2d_mode mode) {
        _output.mode = mode;
        return *this;
    }
};

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/border2d_node.inl>
#endif

#endif // include guard
