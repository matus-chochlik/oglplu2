/**
 *  @file oglplus/texgen/spheres_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_SPHERES_NODE_1509260923_HPP
#define OGLPLUS_TEXGEN_SPHERES_NODE_1509260923_HPP

#include "base_node.hpp"
#include "fallback_input.hpp"

namespace oglplus {
namespace texgen {

class spheres_output : public base_output {
public:
    input_with_const_default<float[3]> repeat;

    spheres_output(node_intf& parent);

    string_view type_name() override;

    slot_data_type value_type() override;

    std::ostream&
    definitions(std::ostream& out, compile_context& ctxt) override;
};

using spheres_node = unary_single_output_node<
  spheres_output,
  decltype(spheres_output::repeat),
  &spheres_output::repeat>;

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/spheres_node.inl>
#endif

#endif // include guard
