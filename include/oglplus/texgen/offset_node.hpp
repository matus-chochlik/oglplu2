/**
 *  @file oglplus/texgen/offset_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_OFFSET_NODE_1509260923_HPP
#define OGLPLUS_TEXGEN_OFFSET_NODE_1509260923_HPP

#include "fallback_input.hpp"
#include "base_node.hpp"

namespace oglplus {
namespace texgen {

class offset_output
 : public base_output
{
public:
	input_with_const_default<float[4]> input;
	input_with_const_default<float[3]> offset;

	offset_output(node_intf& parent);

	cstr_ref type_name(void)
	override;

	slot_data_type value_type(void)
	override;

	std::ostream& definitions(std::ostream& out, compile_context& ctxt)
	override;
};

class offset_node
 : public base_single_output_node
{
private:
	offset_output _output;
public:
	offset_node(void);

	bool set_offset(float x, float y, float z)
	{
		if(!_output.offset.is_connected())
		{
			_output.offset.fallback().set(x, y, z);
			return true;
		}
		return false;
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
#include <oglplus/texgen/offset_node.inl>
#endif

#endif // include guard
