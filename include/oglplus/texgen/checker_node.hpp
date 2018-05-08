/**
 *  @file oglplus/texgen/checker_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_CHECKER_NODE_1509260923_HPP
#define OGLPLUS_TEXGEN_CHECKER_NODE_1509260923_HPP

#include "base_node.hpp"
#include "fallback_input.hpp"

namespace oglplus {
namespace texgen {

class checker_output : public base_output {
public:
    input_with_const_default<float[3]> repeat;

    checker_output(node_intf& parent);

    cstr_ref type_name(void) override;

    slot_data_type value_type(void) override;

    std::ostream& definitions(
      std::ostream& out, compile_context& ctxt) override;
};

class checker_node
  : public unary_single_output_node<checker_output,
      decltype(checker_output::repeat),
      &checker_output::repeat> {
public:
    checker_node& set_repeat(float x, float y, float z) {
	_output.repeat.fallback().set(x, y, z);
	return *this;
    }
};

class pixel_checker_output : public base_output {
public:
    pixel_checker_output(node_intf& parent);

    cstr_ref type_name(void) override;

    slot_data_type value_type(void) override;

    std::ostream& definitions(
      std::ostream& out, compile_context& ctxt) override;
};

using pixel_checker_node = single_output_node<pixel_checker_output>;

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/checker_node.inl>
#endif

#endif // include guard
