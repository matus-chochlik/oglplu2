/**
 *  @file oglplus/texgen/swizzle_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_SWIZZLE_NODE_1509260923_HPP
#define OGLPLUS_TEXGEN_SWIZZLE_NODE_1509260923_HPP

#include "fallback_input.hpp"
#include "base_node.hpp"
#include <string>

namespace oglplus {
namespace texgen {

bool is_valid_swizzle(const cstr_ref&)
noexcept;

class swizzle_output
 : public base_output
{
public:
	std::string swizzle;
	input_with_const_default<float[4]> input;

	swizzle_output(node_intf& parent);
	swizzle_output(node_intf& parent, const std::string& swizzle);

	cstr_ref type_name(void)
	override;

	slot_data_type value_type(void)
	override;

	std::ostream& definitions(std::ostream& out, compile_context& ctxt)
	override;
};

class swizzle_node
 : public single_output_node<swizzle_output>
{
public:
	swizzle_node(void) = default;
	swizzle_node(const std::string& swizzle);

	bool set_swizzle(const std::string& swizzle)
	{
		if(!is_valid_swizzle(cstr_ref(swizzle)))
		{
			_output.swizzle = swizzle;
			return true;
		}
		return false;
	}

	std::size_t input_count(void)
	override;

	input_intf& input(std::size_t index)
	override;
};

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/swizzle_node.inl>
#endif

#endif // include guard
