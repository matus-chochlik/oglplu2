/// @file oglplus/texgen/concentric_node.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OGLPLUS_TEXGEN_CONCENTRIC_NODE_HPP
#define OGLPLUS_TEXGEN_CONCENTRIC_NODE_HPP

#include "base_node.hpp"
#include "fallback_input.hpp"

namespace eagine::oglp::texgen {

class concentric_output : public base_output {
public:
    input_with_const_default<float[3]> repeat;

    concentric_output(node_intf& parent);

    string_view type_name() override;

    slot_data_type value_type() override;

    std::ostream& definitions(std::ostream& out, compile_context& ctxt) override;
};

class concentric_node
  : public unary_single_output_node<
      concentric_output,
      decltype(concentric_output::repeat),
      &concentric_output::repeat> {
public:
    concentric_node& set_repeat(float x, float y, float z) {
        _output.repeat.fallback().set(x, y, z);
        return *this;
    }
};

class pixel_concentric_output : public base_output {
public:
    pixel_concentric_output(node_intf& parent);

    string_view type_name() override;

    slot_data_type value_type() override;

    std::ostream& definitions(std::ostream& out, compile_context& ctxt) override;
};

using pixel_concentric_node = single_output_node<pixel_concentric_output>;

} // namespace eagine::oglp::texgen

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/concentric_node.inl>
#endif

#endif // OGLPLUS_TEXGEN_CONCENTRIC_NODE_HPP
