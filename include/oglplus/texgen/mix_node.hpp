/**
 *  @file oglplus/texgen/mix_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_MIX_NODE_1509260923_HPP
#define OGLPLUS_TEXGEN_MIX_NODE_1509260923_HPP

#include "fallback_input.hpp"
#include "base_node.hpp"

namespace oglplus {
namespace texgen {

class mix_output
 : public base_output
{
public:
	input_with_const_default<float[4]> zero;
	input_with_const_default<float[4]> one;
	input_with_const_default<float[1]> value;

	mix_output(node_intf& parent);

	cstr_ref type_name(void)
	override;

	slot_data_type value_type(void)
	override;

	std::ostream& definitions(std::ostream& out, compile_context& ctxt)
	override;
};

class mix_node
 : public single_output_node<mix_output>
{
public:
	std::size_t input_count(void)
	override;

	input_intf& input(std::size_t index)
	override;
};

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/mix_node.inl>
#endif

#endif // include guard
