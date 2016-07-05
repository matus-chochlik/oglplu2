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
	base_input(base_input&&) = default;

	base_input(node_intf& par_node, const cstr_ref& name_str)
	noexcept
	 : _parent(par_node)
	 , _name(name_str)
	 , _output(nullptr)
	{ }

	~base_input(void)
	noexcept
	override;

	node_intf& parent(void)
	noexcept
	{
		return _parent;
	}

	void set_name(const cstr_ref& name)
	noexcept
	{
		_name = name;
	}

	cstr_ref name(void)
	noexcept
	override;

	bool is_connected(void)
	noexcept
	override;

	bool is_connected(output_intf&)
	override;

	bool can_connect(output_intf&)
	override;

	bool do_connect(output_intf&);

	bool connect(output_intf&)
	override;

	void disconnect(void)
	override;

	bool disconnect(output_intf&)
	override;

	output_intf& connected_output(void)
	override;

	bool set_default_value(
		eagine::valid_if_between<unsigned, 0, 3> cmp,
		float val
	) override;

	void update_needed(void)
	override;

	void prepare_connected(void)
	override;

	bool render_connected(const render_params&)
	override;
};

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/base_input.inl>
#endif

#endif // include guard
