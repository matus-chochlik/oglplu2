/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <cassert>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
vertex_attrib_bits
unit_screen_gen::
_attr_mask(void)
noexcept
{
	return	vertex_attrib_kind::position|
		vertex_attrib_kind::normal|
		vertex_attrib_kind::tangential|
		vertex_attrib_kind::bitangential|
		vertex_attrib_kind::wrap_coord|
		vertex_attrib_kind::face_coord|
		vertex_attrib_kind::box_coord;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
unit_screen_gen::
unit_screen_gen(vertex_attrib_bits attr_bits)
noexcept
 : _base(attr_bits & _attr_mask())
{ }
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool
unit_screen_gen::
cw_face_winding(void)
{
	return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
span_size_t
unit_screen_gen::
vertex_count(void)
{
	return 4;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_screen_gen::
positions(const span<float>& dest)
noexcept
{
	assert(dest.size() >= vertex_count()*3);

	/*
	 * [-1, 1] [ 1, 1]
	 *    (1)---(3)
	 *     | \   |
	 *     |  \  |
	 *     |   \ |
	 *    (0)---(2)
	 * [-1,-1] [ 1,-1]
	 */

	span_size_t k = 0;
	// (0)
	dest[k++] = -1.f;
	dest[k++] = -1.f;
	dest[k++] =  0.f;
	// (1)
	dest[k++] = -1.f;
	dest[k++] =  1.f;
	dest[k++] =  0.f;
	// (2)
	dest[k++] =  1.f;
	dest[k++] = -1.f;
	dest[k++] =  0.f;
	// (3)
	dest[k++] =  1.f;
	dest[k++] =  1.f;
	dest[k++] =  0.f;
	
	assert(k == vertex_count()*3);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_screen_gen::
normals(const span<float>& dest)
noexcept
{
	assert(has(vertex_attrib_kind::normal));
	assert(dest.size() >= vertex_count()*3);

	span_size_t k = 0;
	for(span_size_t i=0; i<4; ++i)
	{
		dest[k++] = 0.f;
		dest[k++] = 0.f;
		dest[k++] = 1.f;
	}

	assert(k == vertex_count()*3);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_screen_gen::
tangentials(const span<float>& dest)
noexcept
{
	assert(has(vertex_attrib_kind::tangential));
	assert(dest.size() >= vertex_count()*3);

	span_size_t k = 0;
	for(span_size_t i=0; i<4; ++i)
	{
		dest[k++] = 1.f;
		dest[k++] = 0.f;
		dest[k++] = 0.f;
	}

	assert(k == vertex_count()*3);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_screen_gen::
bitangentials(const span<float>& dest)
noexcept
{
	assert(has(vertex_attrib_kind::bitangential));
	assert(dest.size() >= vertex_count()*3);

	span_size_t k = 0;
	for(span_size_t i=0; i<4; ++i)
	{
		dest[k++] = 0.f;
		dest[k++] = 1.f;
		dest[k++] = 0.f;
	}

	assert(k == vertex_count()*3);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_screen_gen::
face_coords(const span<float>& dest)
noexcept
{
	assert(has(vertex_attrib_kind::face_coord));
	assert(dest.size() >= vertex_count()*3);

	/*
	 *  [0, 1]  [1, 1]
	 *    (1)---(3)
	 *     | \   |
	 *     |  \  |
	 *     |   \ |
	 *    (0)---(2)
	 *  [0, 0]  [1, 0]
	 */

	span_size_t k = 0;
	// (0)
	dest[k++] = 0.f;
	dest[k++] = 0.f;
	dest[k++] = 0.f;
	// (1)
	dest[k++] = 0.f;
	dest[k++] = 1.f;
	dest[k++] = 0.f;
	// (2)
	dest[k++] = 1.f;
	dest[k++] = 0.f;
	dest[k++] = 0.f;
	// (3)
	dest[k++] = 1.f;
	dest[k++] = 1.f;
	dest[k++] = 0.f;

	assert(k == vertex_count()*3);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_screen_gen::
attrib_values(vertex_attrib_kind attr, const span<float>& dest)
{
	switch(attr)
	{
		case vertex_attrib_kind::position:
			positions(dest);
			break;
		case vertex_attrib_kind::normal:
			normals(dest);
			break;
		case vertex_attrib_kind::tangential:
			tangentials(dest);
			break;
		case vertex_attrib_kind::bitangential:
			bitangentials(dest);
			break;
		case vertex_attrib_kind::box_coord:
		case vertex_attrib_kind::wrap_coord:
		case vertex_attrib_kind::face_coord:
			face_coords(dest);
			break;
	}
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
index_data_type
unit_screen_gen::
index_type(void)
{
	return index_data_type::none;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
span_size_t
unit_screen_gen::
index_count(void)
{
	return 0;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_screen_gen::
indices(const span<unsigned>&)
{ }
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
span_size_t
unit_screen_gen::
operation_count(void)
{
	return 1;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_screen_gen::
instructions(const span<draw_operation>& ops)
{
	assert(ops.size() >= operation_count());

	draw_operation& op = ops[0];
	op.mode = primitive_type::triangle_strip;
	op.idx_type = index_data_type::none;
	op.first = 0;
	op.count = vertex_count();
	op.primitive_restart = false;
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine
