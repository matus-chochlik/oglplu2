/**
 *  @file oglplus/texgen/combine_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_COMBINE_NODE_1509260923_HPP
#define OGLPLUS_TEXGEN_COMBINE_NODE_1509260923_HPP

#include "base_node.hpp"
#include "fallback_input.hpp"

namespace oglplus {
namespace texgen {

class combine_output : public base_output {
private:
    typedef input_with_const_default<float[1]> _input_t;
    std::string _input_expr(_input_t&, slot_data_type, compile_context&);

public:
    _input_t input_r;
    _input_t input_g;
    _input_t input_b;
    _input_t input_a;

    combine_output(node_intf& parent);

    string_view type_name() override;

    scalar_data_type component_type();

    slot_data_type value_type() override;

    std::ostream&
    definitions(std::ostream& out, compile_context& ctxt) override;
};

class combine_node : public single_output_node<combine_output> {
public:
    span_size_t input_count() override;

    input_intf& input(span_size_t index) override;
};

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/combine_node.inl>
#endif

#endif // include guard
