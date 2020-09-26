/**
 *  @file oglplus/texgen/swizzle_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_SWIZZLE_NODE_HPP
#define OGLPLUS_TEXGEN_SWIZZLE_NODE_HPP

#include "base_node.hpp"
#include "fallback_input.hpp"
#include <string>

namespace eagine::oglp::texgen {

bool is_valid_swizzle(string_view) noexcept;

class swizzle_output : public base_output {
public:
    std::string swizzle;
    input_with_const_default<float[4]> input;

    swizzle_output(node_intf& parent);
    swizzle_output(node_intf& parent, std::string swizzle);

    string_view type_name() override;

    slot_data_type value_type() override;

    std::ostream& definitions(std::ostream& out, compile_context& ctxt) override;
};

class swizzle_node
  : public unary_single_output_node<
      swizzle_output,
      decltype(swizzle_output::input),
      &swizzle_output::input> {
public:
    swizzle_node() = default;

    swizzle_node& set_swizzle(const std::string& swizzle) {
        if(is_valid_swizzle(string_view(swizzle))) {
            _output.swizzle = swizzle;
        }
        return *this;
    }
};

} // namespace eagine::oglp::texgen

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/swizzle_node.inl>
#endif

#endif // OGLPLUS_TEXGEN_SWIZZLE_NODE_HPP
