/**
 *  @file oglplus/texgen/coord_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_COORD_NODE_1509260923_HPP
#define OGLPLUS_TEXGEN_COORD_NODE_1509260923_HPP

#include "base_node.hpp"

namespace oglplus {
namespace texgen {

enum class coord_type
{
	normalized,
	frag_coord
};

class coord_output
 : public base_output
{
private:
	friend class coord_node;

	coord_type _type;

	cstr_ref _func_name(void) const;
public:
	coord_output(node_intf& parent, coord_type);

	coord_output(node_intf& parent)
	 : coord_output(parent, coord_type::normalized)
	{ }

	cstr_ref type_name(void)
	override;

	slot_data_type value_type(void)
	override;

	std::ostream& definitions(std::ostream& out, compile_context& ctxt)
	override;
};

class coord_node
 : public single_output_node<coord_output>
{
public:
	coord_node&
	set_type(coord_type type) {
		_output._type = type;
		return *this;
	}
};

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/coord_node.inl>
#endif

#endif // include guard
