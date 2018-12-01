/**
 *  @file oglplus/texgen/blur2d_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_BLUR_NODE_1509260923_HPP
#define OGLPLUS_TEXGEN_BLUR_NODE_1509260923_HPP

#include "base_node.hpp"
#include "fallback_input.hpp"

namespace oglplus {
namespace texgen {

class blur2d_output : public base_output {
public:
    input_with_const_default<float[4]> input;

    blur2d_output(node_intf& parent);

    cstr_ref type_name(void) override;

    slot_data_type value_type(void) override;

    std::ostream& definitions(
      std::ostream& out, compile_context& ctxt) override;
};

using blur2d_node = unary_single_output_node<
  blur2d_output,
  decltype(blur2d_output::input),
  &blur2d_output::input>;

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/blur2d_node.inl>
#endif

#endif // include guard
