/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OGLPLUS_TEXGEN_RANDOM_NODE_HPP
#define OGLPLUS_TEXGEN_RANDOM_NODE_HPP

#include "base_node.hpp"
#include "fallback_input.hpp"

namespace eagine::oglp::texgen {

class random_output : public base_output {
public:
    input_with_const_default<float[3]> seed;
    span_size_t dims;

    random_output(node_intf& parent);

    string_view type_name() override;

    slot_data_type value_type() override;

    std::ostream& definitions(std::ostream& out, compile_context& ctxt) override;
};

using random_node = unary_single_output_node<
  random_output,
  decltype(random_output::seed),
  &random_output::seed>;

} // namespace eagine::oglp::texgen

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/random_node.inl>
#endif

#endif // OGLPLUS_TEXGEN_RANDOM_NODE_HPP
