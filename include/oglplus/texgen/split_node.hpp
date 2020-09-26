/**
 *  @file oglplus/texgen/split_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_SPLIT_NODE_HPP
#define OGLPLUS_TEXGEN_SPLIT_NODE_HPP

#include "base_node.hpp"
#include "fallback_input.hpp"
#include <eagine/types.hpp>

namespace eagine::oglp::texgen {

class split_output : public base_output {
private:
    input_with_const_default<float[4]>& _input;
    span_size_t _index;

public:
    split_output(
      node_intf& parent,
      input_with_const_default<float[4]>& input,
      valid_if_between<span_size_t, 0, 3> index);

    string_view type_name() override;

    slot_data_type value_type() override;

    std::ostream& definitions(std::ostream& out, compile_context& ctxt) override;
};

class split_node : public base_node {
private:
    input_with_const_default<float[4]> _input;
    split_output _output_r;
    split_output _output_g;
    split_output _output_b;
    split_output _output_a;

public:
    split_node();

    string_view type_name() override;

    span_size_t input_count() override;

    input_intf& input(span_size_t index) override;

    span_size_t output_count() override;

    output_intf& output(span_size_t index) override;
};

} // namespace eagine::oglp::texgen

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/split_node.inl>
#endif

#endif // OGLPLUS_TEXGEN_SPLIT_NODE_HPP
