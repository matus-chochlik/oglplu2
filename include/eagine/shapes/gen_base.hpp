/**
 *  @file eagine/shapes/gen_base.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPES_GEN_BASE_1509260923_HPP
#define EAGINE_SHAPES_GEN_BASE_1509260923_HPP

#include "drawing.hpp"
#include "vertex_attrib.hpp"
#include "../span.hpp"

namespace eagine {
namespace shapes {

struct generator_params
{
	bool allow_strips;
	bool allow_fans;
	bool allow_primitive_restart;

	generator_params(void)
	noexcept
	 : allow_strips(false)
	 , allow_fans(false)
	 , allow_primitive_restart(false)
	{ }
};

class generator_base
{
private:
	vertex_attrib_bits _attr_bits;
	generator_params _params;

protected:
	generator_base(vertex_attrib_bits attr_bits)
	noexcept
	 : _attr_bits(attr_bits)
	{ }
public:
	generator_base(const generator_base&) = default;

	virtual ~generator_base(void) = default;

	vertex_attrib_bits attrib_bits(void) const
	noexcept
	{
		return _attr_bits;
	}

	generator_params& parameters(void)
	noexcept
	{
		return _params;
	}

	bool strips_allowed(void) const
	noexcept
	{
		return _params.allow_strips;
	}

	bool fans_allowed(void) const
	noexcept
	{
		return _params.allow_fans;
	}

	bool primitive_restart(void) const
	noexcept
	{
		return _params.allow_primitive_restart;
	}

	bool has(vertex_attrib_kind attr) const
	noexcept
	{
		return bool(attrib_bits() | attr);
	}

	virtual
	unsigned values_per_vertex(vertex_attrib_kind attr)
	{
		return has(attr)?attrib_values_per_vertex(attr):0u;
	}

	virtual
	bool cw_face_winding(void) = 0;

	virtual
	unsigned vertex_count(void) = 0;

	unsigned value_count(vertex_attrib_kind attr)
	{
		return vertex_count()*values_per_vertex(attr);
	}

	virtual
	void attrib_values(vertex_attrib_kind attr, span<float> dest) = 0;

	virtual
	index_data_type index_type(void) = 0;

	virtual
	unsigned index_count(void) = 0;

	virtual
	void indices(span<unsigned> dest) = 0;

	virtual
	unsigned operation_count(void) = 0;

	virtual
	void instructions(span<draw_operation> dest) = 0;
};

} // namespace shapes
} // namespace eagine

#endif // include guard
