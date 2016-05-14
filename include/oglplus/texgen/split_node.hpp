/**
 *  @file oglplus/texgen/split_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_SPLIT_NODE_1509260923_HPP
#define OGLPLUS_TEXGEN_SPLIT_NODE_1509260923_HPP

#include "fallback_input.hpp"
#include "base_node.hpp"

namespace oglplus {
namespace texgen {

class split_output
 : public base_output
{
private:
	input_with_const_default<float[4]>& _input;
	unsigned _index;
public:
	split_output(
		node_intf& parent,
		input_with_const_default<float[4]>& input,
		eagine::valid_if_between<unsigned, 0, 3> index
	);

	cstr_ref type_name(void)
	override;

	slot_data_type value_type(void)
	override;

	std::ostream& definitions(std::ostream& out, compile_context& ctxt)
	override;
};

class split_node
 : public base_node
{
private:
	input_with_const_default<float[4]> _input;
	split_output _output_r;
	split_output _output_g;
	split_output _output_b;
	split_output _output_a;
public:
	split_node(void);

	cstr_ref type_name(void)
	override;

	std::size_t input_count(void)
	override;

	input_intf& input(std::size_t index)
	override;

	std::size_t output_count(void)
	override;

	output_intf& output(std::size_t index)
	override;
};

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/split_node.inl>
#endif

#endif // include guard
