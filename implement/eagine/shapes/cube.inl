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
unit_cube_gen::
_attr_mask(void)
noexcept
{
	return	vertex_attrib_kind::position|
		vertex_attrib_kind::normal|
		vertex_attrib_kind::box_coord;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
vertex_attrib_bits
unit_cube_gen::
_shared_attrs(void)
noexcept
{
	return	vertex_attrib_kind::position|
		vertex_attrib_kind::box_coord;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool
unit_cube_gen::
_only_shared_attribs(void) const
noexcept
{
	return !(attrib_bits() & ~_shared_attrs());
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
unsigned
unit_cube_gen::
_face_vert(unsigned f, unsigned t, unsigned v)
noexcept
{
	assert(f < 6);
	assert(t < 2);
	assert(v < 3);

	/*
	 *    (2)-----(3)    (Y)
	 *    /|      /|      ^
	 *   / |     / |      |
	 * (6)-|---(7) |      |
	 *  | (0)---|-(1)     O----> (X)
	 *  | /     | /      /
	 *  |/      |/      /
	 * (4)-----(5)     L (Z)
	 *
	 *        (-)        (+)
	 *    (2)----(6) (7)----(3)
	 *     | \ II |   | \ II |
	 *     |  \   |   |  \   |
	 * (X) |   \  |   |   \  |
	 *     | I  \ |   | I  \ |
	 *    (0)----(4) (5)----(1)
	 *
	 *        (-)        (+)
	 *    (4)----(5) (2)----(3)
	 *     | \ II |   | \ II |
	 *     |  \   |   |  \   |
	 * (Y) |   \  |   |   \  |
	 *     | I  \ |   | I  \ |
	 *    (0)----(1) (6)----(7)
	 *
	 *        (-)        (+)
	 *    (3)----(2) (6)----(7)
	 *     | \ II |   | \ II |
	 *     |  \   |   |  \   |
	 * (Z) |   \  |   |   \  |
	 *     | I  \ |   | I  \ |
	 *    (1)----(0) (4)----(5)
	 */

	static const unsigned fv[6][2][3] = {
		//  (I)       (II)
		{{0, 4, 2}, {2, 4, 6}}, // (-X)
		{{5, 1, 7}, {7, 1, 3}}, // (+X)
		{{0, 1, 4}, {4, 1, 5}}, // (-Y)
		{{6, 7, 2}, {2, 7, 3}}, // (+Y)
		{{1, 0, 3}, {3, 0, 2}}, // (-Z)
		{{4, 5, 6}, {6, 5, 7}}  // (+Z)
	};
	return fv[f][t][v];
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
unit_cube_gen::
unit_cube_gen(vertex_attrib_bits attr_bits)
noexcept
 : generator_base(attr_bits & _attr_mask())
{ }
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool
unit_cube_gen::
cw_face_winding(void)
{
	return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
unsigned
unit_cube_gen::
vertex_count(void)
{
	if(_only_shared_attribs())
	{
		return 8;
	}
	else
	{
		return 6*2*3;
	}
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
int
unit_cube_gen::
_coord_c(unsigned v, unsigned c)
noexcept
{
	assert(v < 8);
	assert(c < 3);

	static const unsigned char _coord_bits[3] = {0xAA, 0xCC, 0xF0};

	unsigned char b = static_cast<unsigned char>(1 << v);
	return ((_coord_bits[c] & b) == b)?1:0;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_cube_gen::
box_coords(span<float> dest)
noexcept
{
	unsigned k = 0;

	assert(dest.size() >= vertex_count()*3);

	if(_only_shared_attribs())
	{
		assert(dest.size() >= 8*3);

		for(unsigned v=0; v<8; ++v)
		{
			for(unsigned c=0; c<3; ++c)
			{
				dest[k++] = _coord_c(v, c);
			}
		}
	}
	else
	{
		assert(dest.size() >= 6*2*3*3);

		for(unsigned f=0; f<6; ++f)
		for(unsigned t=0; t<2; ++t)
		for(unsigned i=0; i<3; ++i)
		{
			unsigned v = _face_vert(f, t, i);
			for(unsigned c=0; c<3; ++c)
			{
				dest[k++] = _coord_c(v, c);
			}
		}
	}

	assert(k == vertex_count()*3);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_cube_gen::
positions(span<float> dest)
noexcept
{
	box_coords(dest);
	for(unsigned i=0, n = vertex_count()*3; i<n; ++i)
	{
		dest[i] -= 0.5f;
	}
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
int
unit_cube_gen::
_normal_c(unsigned f, unsigned c)
noexcept
{
	assert(f < 6);
	assert(c < 3);

	static const unsigned char _nml_bits[3] = {0x03, 0x0C, 0x30};
	static const unsigned char _nml_sign[3] = {0x02, 0x08, 0x20};
	
	unsigned char b = static_cast<unsigned char>(1 << f);
	return (((_nml_bits[c] & b) == b)?1:0)*(((_nml_sign[c] & b) == b)?1:-1);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_cube_gen::
normals(span<float> dest)
noexcept
{
	assert(has(vertex_attrib_kind::normal));
	assert(dest.size() >= vertex_count()*3);

	unsigned k = 0;
	unsigned n = 2*3;

	for(unsigned f=0; f<6; ++f)
	for(unsigned i=0; i<n; ++i)
	{
		for(unsigned c=0; c<3; ++c)
		{
			dest[k++] = _normal_c(f, c);
		}
	}

	assert(k == vertex_count()*3);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_cube_gen::
attrib_values(vertex_attrib_kind attr, span<float> dest)
{
	switch(attr)
	{
		case vertex_attrib_kind::position:
			positions(dest);
			break;
		case vertex_attrib_kind::normal:
			normals(dest);
			break;
		case vertex_attrib_kind::box_coord:
			box_coords(dest);
			break;
		case vertex_attrib_kind::tangential:
		case vertex_attrib_kind::bitangential:
		case vertex_attrib_kind::tex_coord:
			assert(has(attr));
	}
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
index_data_type
unit_cube_gen::
index_type(void)
{
	if(_only_shared_attribs())
	{
		return index_data_type::unsigned_byte;
	}
	return index_data_type::none;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
unsigned
unit_cube_gen::
index_count(void)
{
	if(_only_shared_attribs())
	{
		return 6*2*3;
	}
	return 0;
}
//------------------------------------------------------------------------------
template <typename T>
inline
void
unit_cube_gen::
_indices(span<T>& dest)
noexcept
{
	assert(dest.size() >= index_count());

	unsigned k = 0;

	if(_only_shared_attribs())
	{
		for(unsigned f=0; f<6; ++f)
		for(unsigned t=0; t<2; ++t)
		for(unsigned v=0; v<3; ++v)
		{
			dest[k++] = T(_face_vert(f, t, v));
		}
	}

	assert(k == index_count());
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_cube_gen::
indices(span<unsigned> dest)
{
	_indices(dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
unsigned
unit_cube_gen::
operation_count(void)
{
	return 1;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_cube_gen::
instructions(span<draw_operation> ops)
{
	assert(ops.size() >= operation_count());

	if(_only_shared_attribs())
	{
		draw_operation& op = ops[0];
		op.mode = primitive_type::triangles;
		op.idx_type = index_data_type::unsigned_byte;
		op.first = 0;
		op.count = index_count();
		op.primitive_restart = false;
	}
	else
	{
		draw_operation& op = ops[0];
		op.mode = primitive_type::triangles;
		op.idx_type = index_data_type::none;
		op.first = 0;
		op.count = vertex_count();
		op.primitive_restart = false;
	}
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine
