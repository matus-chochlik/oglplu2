/**
 *  @file oglplus/texgen/stripes_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_STRIPES_NODE_1509260923_HPP
#define OGLPLUS_TEXGEN_STRIPES_NODE_1509260923_HPP

#include "fallback_input.hpp"
#include "base_node.hpp"

namespace oglplus {
namespace texgen {

class stripes_output
 : public base_output
{
public:
	input_with_const_default<float[3]> repeat;

	stripes_output(node_intf& parent);

	cstr_ref type_name(void)
	override;

	slot_data_type value_type(void)
	override;

	std::ostream& definitions(std::ostream& out, compile_context& ctxt)
	override;
};

class stripes_node
 : public unary_single_output_node<
	stripes_output,
	decltype(stripes_output::repeat), &stripes_output::repeat
>
{
public:
	stripes_node&
	set_repeat(float x, float y, float z) {
		_output.repeat.fallback().set(x, y, z);
		return *this;
	}
};

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/stripes_node.inl>
#endif

#endif // include guard
