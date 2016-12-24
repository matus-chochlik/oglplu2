/**
 *  @file oglplus/texgen/wrap_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_WRAP_NODE_1509260923_HPP
#define OGLPLUS_TEXGEN_WRAP_NODE_1509260923_HPP

#include "fallback_input.hpp"
#include "coord_node.hpp"
#include "base_node.hpp"
#include <string>

namespace oglplus {
namespace texgen {

enum class wrap_mode
{
	repeat,
	mirror,
	clamp
};

class wrap_output
 : public base_output
{
public:
	wrap_mode mode;
	fallback_input<coord_output> input;

	wrap_output(node_intf& parent);

	cstr_ref type_name(void)
	override;

	slot_data_type value_type(void)
	override;

	std::ostream& definitions(std::ostream& out, compile_context& ctxt)
	override;
};

class wrap_node
 : public unary_single_output_node<
	wrap_output,
	decltype(wrap_output::input), &wrap_output::input
>
{
public:
	wrap_node(void) = default;

	wrap_node&
	set_mode(wrap_mode mode) {
		_output.mode = mode;
		return *this;
	}
};

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/wrap_node.inl>
#endif

#endif // include guard
