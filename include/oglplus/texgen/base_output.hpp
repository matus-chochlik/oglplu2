/**
 *  @file oglplus/texgen/base_output.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_BASE_OUTPUT_1509260923_HPP
#define OGLPLUS_TEXGEN_BASE_OUTPUT_1509260923_HPP

#include "interface.hpp"
#include <set>

namespace oglplus {
namespace texgen {

class base_output
 : public output_intf
{
private:
	node_intf& _parent;
	std::set<input_intf*> _inputs;

public:
	base_output(node_intf& parent)
	noexcept
	 : _parent(parent)
	{ }

	node_intf& parent(void)
	noexcept
	{
		return _parent;
	}

	virtual
	cstr_ref type_name(void) = 0;

	cstr_ref name(void)
	noexcept
	override;

	render_params required_params(void)
	override;

	std::ostream& definitions(std::ostream&, compile_context&)
	override;

	std::ostream& expression(std::ostream&, compile_context&)
	override;

	bool is_connected(input_intf&)
	override;

	bool connect(input_intf&)
	override;

	bool disconnect(input_intf&)
	override;

	void notify_connected(void)
	override;

	std::intptr_t get_id(void) const
	noexcept;

	void append_id(std::ostream&, const cstr_ref&);
	void append_id(std::ostream&);
	
};

struct output_id_expr
{
	output_intf& output;
	compile_context& context;
};
std::ostream& operator << (std::ostream& out, const output_id_expr& expr);

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/base_output.inl>
#endif

#endif // include guard
