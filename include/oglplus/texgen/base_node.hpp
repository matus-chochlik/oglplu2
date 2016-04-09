/**
 *  @file oglplus/texgen/base_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_BASE_NODE_1509260923_HPP
#define OGLPLUS_TEXGEN_BASE_NODE_1509260923_HPP

#include "interface.hpp"

namespace oglplus {
namespace texgen {

class base_node
 : public node_intf
{
private:
	std::size_t _render_input;
public:
	base_node(void)
	noexcept
	 : _render_input(0u)
	{ }

	std::size_t input_count(void)
	override;

	input_intf& input(std::size_t)
	override;

	std::size_t output_count(void)
	override;

	output_intf& output(std::size_t)
	override;

	void update_needed(void)
	override;

	void prepare(void)
	override;

	bool render(const render_params&)
	override;
};

class base_single_output_node
 : public base_node
{
public:
	virtual
	base_output& single_output(void) = 0;

	cstr_ref type_name(void)
	override;

	std::size_t output_count(void)
	override;

	output_intf& output(std::size_t index)
	override;
};

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/base_node.inl>
#endif

#endif // include guard
