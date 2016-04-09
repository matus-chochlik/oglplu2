/**
 *  @file oglplus/texgen/complement_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_COMPLEMENT_NODE_1509260923_HPP
#define OGLPLUS_TEXGEN_COMPLEMENT_NODE_1509260923_HPP

#include "fallback_input.hpp"
#include "base_node.hpp"

namespace oglplus {
namespace texgen {

class complement_input
 : public input_with_const_default<float[4]>
{
private:
	typedef input_with_const_default<float[4]> _base;
public:
	complement_input(
		node_intf& parent,
		const cstr_ref& name,
		float r, float g, float b, float a
	): _base(parent, name, r, g, b, a)
	{ }

	bool accepts_value_type(slot_data_type type)
	override
	{
		return data_type_dims(type) ==
			data_type_dims(output().value_type());
	}
};

class complement_output
 : public base_output
{
public:
	input_with_const_default<float[4]> input;
	input_with_const_default<float[4]> complement;

	complement_output(node_intf& parent);

	cstr_ref type_name(void)
	override;

	slot_data_type value_type(void)
	override;

	std::ostream& definitions(std::ostream& out, compile_context& ctxt)
	override;
};

class complement_node
 : public base_single_output_node
{
private:
	complement_output _output;
public:
	complement_node(void);

	complement_node&
	set_complement(float r, float g, float b, float a)
	{
		_output.complement.fallback().set(r, g, b, a);
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
#include <oglplus/texgen/complement_node.inl>
#endif

#endif // include guard
