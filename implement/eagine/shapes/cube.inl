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
		vertex_attrib_kind::tangential|
		vertex_attrib_kind::bitangential|
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
	 *    (2)----(3)   (2)  (0)---(2)
	 *     ^ \ II |     | \   \ II |
	 *     |  \   | <=> |  \   \   |
	 *     |   \  |     |   \   \  |
	 *     | I  \ |     | I  \   \ |
	 *    (0)--->(1)   (0)-->(1)  (1)
	 *
	 *        (-)        (+)
	 *    (2)----(6) (7)----(3)
	 *     ^ \ II |   ^ \ II |
	 *     |  \   |   |  \   |
	 * (X) |   \  |   |   \  |
	 *     | I  \ |   | I  \ |
	 *    (0)--->(4) (5)--->(1)
	 *
	 *        (-)        (+)
	 *    (4)----(5) (2)----(3)
	 *     ^ \ II |   ^ \ II |
	 *     |  \   |   |  \   |
	 * (Y) |   \  |   |   \  |
	 *     | I  \ |   | I  \ |
	 *    (0)--->(1) (6)--->(7)
	 *
	 *        (-)        (+)
	 *    (3)----(2) (6)----(7)
	 *     ^ \ II |   ^ \ II |
	 *     |  \   |   |  \   |
	 * (Z) |   \  |   |   \  |
	 *     | I  \ |   | I  \ |
	 *    (1)--->(0) (4)--->(5)
	 */

	static const unsigned ftvi[2][3] = {
		{0, 1, 2}, // ( I)
		{2, 1, 3}  // (II)
	};

	static const unsigned fv[6][4] = {
		{0, 4, 2, 6}, // (-X)
		{5, 1, 7, 3}, // (+X)
		{0, 1, 4, 5}, // (-Y)
		{6, 7, 2, 3}, // (+Y)
		{1, 0, 3, 2}, // (-Z)
		{4, 5, 6, 7}  // (+Z)
	};
	return fv[f][ftvi[t][v]];
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
unit_cube_gen::
unit_cube_gen(vertex_attrib_bits attr_bits)
noexcept
 : _base(attr_bits & _attr_mask())
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
positions(const span<float>& dest)
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
				dest[k++] = _coord_c(v, c)-0.5f;
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
				dest[k++] = _coord_c(v, c)-0.5f;
			}
		}
	}

	assert(k == vertex_count()*3);
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

	//    f =  5, 4, 3, 2, 1, 0
	//  face: +Z,-Z,+Y,-Y,+X,-X
	//   vec: +Z,-Z,+Y,-Y,+X,-X
	// X c=0:  0  0  0  0  1  1 = 0x03
	// Y c=1:  0  0  1  1  0  0 = 0x0C
	// Z c=2:  1  1  0  0  0  0 = 0x30
	static const unsigned char _vec_bits[3] = {0x03, 0x0C, 0x30};
	// X c=0:  0  0  0  0  1  0 = 0x02
	// Y c=1:  0  0  1  0  0  0 = 0x08
	// Z c=2:  1  0  0  0  0  0 = 0x20
	static const unsigned char _vec_sign[3] = {0x02, 0x08, 0x20};
	
	const unsigned char b = static_cast<unsigned char>(1 << f);
	return (((_vec_bits[c] & b) == b)?1:0)*(((_vec_sign[c] & b) == b)?1:-1);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_cube_gen::
normals(const span<float>& dest)
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
int
unit_cube_gen::
_tangential_c(unsigned f, unsigned c)
noexcept
{
	assert(f < 6);
	assert(c < 3);

	//    f =  5, 4, 3, 2, 1, 0
	//  face: +Z,-Z,+Y,-Y,+X,-X
	//   vec: +X,-X,+X,+X,-Z,+Z
	// X c=0:  1  1  1  1  0  0 = 0x3C
	// Y c=1:  0  0  0  0  0  0 = 0x00
	// Z c=2:  0  0  0  0  1  1 = 0x03
	static const unsigned char _vec_bits[3] = {0x3C, 0x00, 0x03};
	// X c=0:  1  0  1  1  0  0 = 0x2C
	// Y c=1:  0  0  0  0  0  0 = 0x00
	// Z c=2:  0  0  0  0  0  1 = 0x01
	static const unsigned char _vec_sign[3] = {0x2C, 0x00, 0x01};
	
	const unsigned char b = static_cast<unsigned char>(1 << f);
	return (((_vec_bits[c] & b) == b)?1:0)*(((_vec_sign[c] & b) == b)?1:-1);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_cube_gen::
tangentials(const span<float>& dest)
noexcept
{
	assert(has(vertex_attrib_kind::tangential));
	assert(dest.size() >= vertex_count()*3);

	unsigned k = 0;
	unsigned n = 2*3;

	for(unsigned f=0; f<6; ++f)
	for(unsigned i=0; i<n; ++i)
	{
		for(unsigned c=0; c<3; ++c)
		{
			dest[k++] = _tangential_c(f, c);
		}
	}

	assert(k == vertex_count()*3);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
int
unit_cube_gen::
_bitangential_c(unsigned f, unsigned c)
noexcept
{
	assert(f < 6);
	assert(c < 3);

	//    f =  5, 4, 3, 2, 1, 0
	//  face: +Z,-Z,+Y,-Y,+X,-X
	//   vec: +Y,+Y,-Z,+Z,+Y,+Y
	// X c=0:  0  0  0  0  0  0 = 0x00
	// Y c=1:  1  1  0  0  1  1 = 0x33
	// Z c=2:  0  0  1  1  0  0 = 0x0C
	static const unsigned char _vec_bits[3] = {0x00, 0x33, 0x0C};
	// X c=0:  0  0  0  0  0  0 = 0x00
	// Y c=1:  1  1  0  0  1  1 = 0x33
	// Z c=2:  0  0  0  1  0  0 = 0x04
	static const unsigned char _vec_sign[3] = {0x00, 0x33, 0x04};
	
	const unsigned char b = static_cast<unsigned char>(1 << f);
	return (((_vec_bits[c] & b) == b)?1:0)*(((_vec_sign[c] & b) == b)?1:-1);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_cube_gen::
bitangentials(const span<float>& dest)
noexcept
{
	assert(has(vertex_attrib_kind::bitangential));
	assert(dest.size() >= vertex_count()*3);

	unsigned k = 0;
	unsigned n = 2*3;

	for(unsigned f=0; f<6; ++f)
	for(unsigned i=0; i<n; ++i)
	{
		for(unsigned c=0; c<3; ++c)
		{
			dest[k++] = _bitangential_c(f, c);
		}
	}

	assert(k == vertex_count()*3);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_cube_gen::
face_coords(const span<float>& dest)
noexcept
{
	assert(has(vertex_attrib_kind::face_coord));
	assert(dest.size() >= vertex_count()*3);

	/*
	 *     (0,1,f) (1,1,f)
	 *       (2)----(3)
	 *        ^ \ II |
	 *        |  \   |
	 *        |   \  |
	 *        | I  \ |
	 *       (0)--->(1)
	 *     (0,0,f) (1,0,f)
	 */

	static const unsigned ftvi[2][3] = {
		{0, 1, 2}, // ( I)
		{2, 1, 3}  // (II)
	};

	const float uv[4][2] = {
		{0.f, 0.f},
		{1.f, 0.f},
		{0.f, 1.f},
		{1.f, 1.f}
	};

	unsigned k = 0;

	for(unsigned f=0; f<6; ++f)
	for(unsigned t=0; t<2; ++t)
	for(unsigned v=0; v<3; ++v)
	{
		dest[k++] = uv[ftvi[t][v]][0];
		dest[k++] = uv[ftvi[t][v]][1];
		dest[k++] = float(f);
	}

	assert(k == vertex_count()*3);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_cube_gen::
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
		case vertex_attrib_kind::face_coord:
			face_coords(dest);
			break;
		case vertex_attrib_kind::box_coord:
		case vertex_attrib_kind::wrap_coord:
			_base::attrib_values(attr, dest);
			break;
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
_indices(const span<T>& dest)
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
indices(const span<unsigned>& dest)
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
instructions(const span<draw_operation>& ops)
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
