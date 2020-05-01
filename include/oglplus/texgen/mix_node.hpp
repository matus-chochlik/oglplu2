/**
 *  @file oglplus/texgen/mix_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_MIX_NODE_HPP
#define OGLPLUS_TEXGEN_MIX_NODE_HPP

#include "base_node.hpp"
#include "fallback_input.hpp"

namespace eagine {
namespace oglp {
namespace texgen {

class mix_output : public base_output {
public:
    input_with_const_default<float[4]> zero;
    input_with_const_default<float[4]> one;
    input_with_const_default<float[1]> value;

    mix_output(node_intf& parent);

    string_view type_name() override;

    slot_data_type value_type() override;

    std::ostream& definitions(
      std::ostream& out, compile_context& ctxt) override;
};

class mix_node : public single_output_node<mix_output> {
public:
    mix_node& set_zero(float x, float y, float z, float w) {
        _output.zero.fallback().set(x, y, z, w);
        return *this;
    }

    mix_node& set_one(float x, float y, float z, float w) {
        _output.one.fallback().set(x, y, z, w);
        return *this;
    }

    mix_node& set_value(float v) {
        _output.value.fallback().set(v);
        return *this;
    }

    span_size_t input_count() override;

    input_intf& input(span_size_t index) override;
};

} // namespace texgen
} // namespace oglp
} // namespace eagine

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/mix_node.inl>
#endif

#endif // OGLPLUS_TEXGEN_MIX_NODE_HPP
