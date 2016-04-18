/**
 *  @file oglplus/texgen/fold_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_FOLD_NODE_1509260923_HPP
#define OGLPLUS_TEXGEN_FOLD_NODE_1509260923_HPP

#include "fallback_input.hpp"
#include "base_node.hpp"
#include <map>

namespace oglplus {
namespace texgen {

enum class fold_function
{
	add,
	multiply,
	max,
	min
	// TODO
};

class fold_output
 : public base_output
{
private:
	friend class fold_node;

	input_with_const_default<float[4]> _input;
	std::map<std::string, input_with_const_default<float[4]>> _inputs;
	fold_function _func;
public:
	fold_output(node_intf& parent, fold_function);

	fold_output(node_intf& parent)
	 : fold_output(parent, fold_function::multiply)
	{ }

	cstr_ref type_name(void)
	override;

	slot_data_type param_type(void);

	slot_data_type value_type(void)
	override;

	std::ostream& definitions(std::ostream& out, compile_context& ctxt)
	override;
};

class fold_node
 : public single_output_node<fold_output>
{
public:
	fold_node&
	set_function(fold_function func)
	{
		_output._func = func;
		return *this;
	}

	std::size_t input_count(void)
	override;

	input_intf& input(std::size_t)
	override;

	eagine::optional_reference_wrapper<input_intf>
	input_by_name(const cstr_ref&)
	override;

	bool can_add_input(void)
	override;

	input_with_const_default<float[4]>&
	add_input(const cstr_ref&)
	override;

	fold_node&
	add_input(const cstr_ref& name, float x, float y, float z, float w)
	{
		add_input(name).fallback().set(x, y, z, w);
		return *this;
	}

	fold_node&
	set_value(float x, float y, float z, float w)
	{
		_output._input.fallback().set(x, y, z, w);
		return *this;
	}
};

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/fold_node.inl>
#endif

#endif // include guard
