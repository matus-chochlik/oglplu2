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
private:
	friend class unary_function_node;

	input_with_const_default<float[4]> _input;
	unary_function _func;
public:

	unary_function_output(node_intf& parent, unary_function);

	unary_function_output(node_intf& parent)
	 : unary_function_output(parent, unary_function::none)
	{ }

	cstr_ref type_name(void)
	override;

	slot_data_type value_type(void)
	override;

	std::ostream& definitions(std::ostream& out, compile_context& ctxt)
	override;
};

class unary_function_node
 : public unary_single_output_node<
	unary_function_output,
	decltype(unary_function_output::_input),
	&unary_function_output::_input
>
{
public:
	unary_function_node&
	set_function(unary_function func)
	{
		_output._func = func;
		return *this;
	}

	unary_function_node&
	set_value(float x, float y, float z, float w)
	{
		_output._input.fallback().set(x, y, z, w);
		return *this;
	}
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
	dot,
	average
};

class binary_function_output
 : public base_output
{
private:
	friend class binary_function_node;

	input_with_const_default<float[4]> _input_a;
	input_with_const_default<float[4]> _input_b;
	binary_function _func;
public:
	binary_function_output(node_intf& parent, binary_function);

	binary_function_output(node_intf& parent)
	 : binary_function_output(parent, binary_function::average)
	{ }

	cstr_ref type_name(void)
	override;

	slot_data_type value_type(void)
	override;

	std::ostream& definitions(std::ostream& out, compile_context& ctxt)
	override;
};

class binary_function_node
 : public binary_single_output_node<
	binary_function_output,
	decltype(binary_function_output::_input_a),
	&binary_function_output::_input_a,
	decltype(binary_function_output::_input_b),
	&binary_function_output::_input_b
>
{
public:
	binary_function_node&
	set_function(binary_function func)
	{
		_output._func = func;
		return *this;
	}

	binary_function_node&
	set_value_a(float x, float y, float z, float w)
	{
		_output._input_a.fallback().set(x, y, z, w);
		return *this;
	}

	binary_function_node&
	set_value_b(float x, float y, float z, float w)
	{
		_output._input_b.fallback().set(x, y, z, w);
		return *this;
	}
};

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/functional_node.inl>
#endif

#endif // include guard
