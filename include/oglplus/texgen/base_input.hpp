/**
 *  @file oglplus/texgen/base_input.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_BASE_INPUT_1509260923_HPP
#define OGLPLUS_TEXGEN_BASE_INPUT_1509260923_HPP

#include "interface.hpp"

namespace oglplus {
namespace texgen {

class base_input
 : public input_intf
{
private:
	node_intf& _parent;
	cstr_ref _name;
	output_intf* _output;
public:
	base_input(node_intf& par_node, const cstr_ref& name_str)
	noexcept
	 : _parent(par_node)
	 , _name(name_str)
	 , _output(nullptr)
	{ }

	~base_input(void)
	noexcept
	override;

	node_intf& parent(void) const
	noexcept
	{
		return _parent;
	}

	cstr_ref name(void) const
	noexcept
	override;

	bool is_connected(void)
	noexcept;

	bool is_connected(output_intf&)
	noexcept
	override;

	bool do_connect(output_intf&);

	bool connect(output_intf&)
	override;

	void disconnect(void);

	bool disconnect(output_intf&)
	override;

	void update_needed(void)
	override;
};

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/base_input.inl>
#endif

#endif // include guard
