/**
 *  @file oglplus/texgen/functional_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_FUNCTIONAL_NODE_1509260923_HPP
#define OGLPLUS_TEXGEN_FUNCTIONAL_NODE_1509260923_HPP

#include "fallback_input.hpp"
#include "base_node.hpp"

namespace oglplus {
namespace texgen {

enum class unary_function
{
	radians,
	degrees,
	sin,
	cos,
	tan,
	asin,
	acos,
	atan,
	abs,
	sign,
	sqrt,
	inversesqrt,
	floor,
	ceil,
	exp,
	exp2,
	log,
	log2,
	negate,
	length,
	none
};

class unary_function_output
 : public base_output
{
public:
	input_with_const_default<float[4]> input;
	unary_function func;

	unary_function_output(node_intf& parent, unary_function);

	cstr_ref type_name(void)
	override;

	slot_data_type value_type(void)
	override;

	std::ostream& definitions(std::ostream& out, compile_context& ctxt)
	override;
};

class unary_function_node
 : public base_single_output_node
{
private:
	unary_function_output _output;
public:
	unary_function_node(unary_function);

	unary_function_node(void)
	 : unary_function_node(unary_function::none)
	{ }

	unary_function_node&
	set_function(unary_function func)
	{
		_output.func = func;
		return *this;
	}

	base_output& single_output(void)
	override;

	std::size_t input_count(void)
	override;

	input_intf& input(std::size_t index)
	override;
};

enum class binary_function
{
	equal,
	not_equal,
	less,
	less_equal,
	greater,
	greater_equal,
	add,
	subtract,
	multiply,
	divide,
	modulo,
	max,
	min,
	distance,
	power,
	dot
};

class binary_function_output
 : public base_output
{
public:
	input_with_const_default<float[4]> input_a;
	input_with_const_default<float[4]> input_b;
	binary_function func;

	binary_function_output(node_intf& parent, binary_function);

	cstr_ref type_name(void)
	override;

	slot_data_type value_type(void)
	override;

	std::ostream& definitions(std::ostream& out, compile_context& ctxt)
	override;
};

class binary_function_node
 : public base_single_output_node
{
private:
	binary_function_output _output;
public:
	binary_function_node(binary_function);

	binary_function_node(void)
	 : binary_function_node(binary_function::dot)
	{ }

	binary_function_node&
	set_function(binary_function func)
	{
		_output.func = func;
		return *this;
	}

	base_output& single_output(void)
	override;

	std::size_t input_count(void)
	override;

	input_intf& input(std::size_t index)
	override;
};

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/functional_node.inl>
#endif

#endif // include guard
