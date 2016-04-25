/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <eagine/math/constants.hpp>
#include <cmath>
#include <cassert>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
vertex_attrib_bits
unit_torus_gen::
_attr_mask(void)
noexcept
{
	return	vertex_attrib_kind::position|
		vertex_attrib_kind::normal|
		vertex_attrib_kind::tangential|
		vertex_attrib_kind::bitangential|
		vertex_attrib_kind::box_coord|
		vertex_attrib_kind::wrap_coord;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
unit_torus_gen::
unit_torus_gen(
	vertex_attrib_bits attr_bits,
	valid_if_greater_than<int, 4> rings,
	valid_if_greater_than<int, 3> sections,
	valid_if_ge0_lt1<float> radius_ratio
) noexcept
 : _base(attr_bits & _attr_mask())
 , _rings(unsigned(rings.value()))
 , _sections(unsigned(sections.value()))
 , _radius_ratio(radius_ratio.value())
{ }
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool
unit_torus_gen::
cw_face_winding(void)
{
	return true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
unsigned
unit_torus_gen::
vertex_count(void)
{
	return (_rings + 1) * (_sections + 1);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_torus_gen::
positions(const span<float>& dest)
noexcept
{
	assert(has(vertex_attrib_kind::position));
	assert(dest.size() >= vertex_count()*3);

	unsigned k = 0;

	const auto ro = 0.50;
	const auto ri = ro*_radius_ratio;
	const auto r1 = ri;
	const auto r2 = ro-ri;

	const auto s_step = 2 * math::pi / _sections;
	const auto r_step = 2 * math::pi / _rings;

	for(unsigned s=0; s<(_sections+1); ++s)
	{
		const auto vx =  std::cos(s*s_step);
		const auto vz = -std::sin(s*s_step);

		for(unsigned r=0; r<(_rings+1); ++r)
		{
			const auto vr = std::cos(r*r_step);
			const auto vy = std::sin(r*r_step);

			dest[k++] = float(vx*(r1 + r2*(1+vr)));
			dest[k++] = float(vy*r2);
			dest[k++] = float(vz*(r1 + r2*(1+vr)));
		}
	}
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_torus_gen::
normals(const span<float>& dest)
noexcept
{
	assert(has(vertex_attrib_kind::normal));
	assert(dest.size() >= vertex_count()*3);

	unsigned k = 0;

	const auto s_step = 2 * math::pi / _sections;
	const auto r_step = 2 * math::pi / _rings;

	for(unsigned s=0; s<(_sections+1); ++s)
	{
		const auto nx =  std::cos(s*s_step);
		const auto nz = -std::sin(s*s_step);

		for(unsigned r=0; r<(_rings+1); ++r)
		{
			const auto nr = std::cos(r*r_step);
			const auto ny = std::sin(r*r_step);

			dest[k++] = float(nx*nr);
			dest[k++] = float(ny);
			dest[k++] = float(nz*nr);
		}
	}
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_torus_gen::
tangentials(const span<float>& dest)
noexcept
{
	assert(has(vertex_attrib_kind::tangential));
	assert(dest.size() >= vertex_count()*3);

	unsigned k = 0;

	const auto s_step = 2 * math::pi / _sections;

	for(unsigned s=0; s<(_sections+1); ++s)
	{
		const auto tx = -std::sin(s*s_step);
		const auto tz = -std::cos(s*s_step);

		for(unsigned r=0; r<(_rings+1); ++r)
		{
			dest[k++] = float(tx);
			dest[k++] = float(0);
			dest[k++] = float(tz);
		}
	}
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_torus_gen::
bitangentials(const span<float>& dest)
noexcept
{
	assert(has(vertex_attrib_kind::bitangential));
	assert(dest.size() >= vertex_count()*3);

	unsigned k = 0;

	const auto s_step = 2 * math::pi / _sections;
	const auto r_step = 2 * math::pi / _rings;
	const auto ty = 0;

	for(unsigned s=0; s<(_sections+1); ++s)
	{
		const auto tx = -std::sin(s*s_step);
		const auto tz = -std::cos(s*s_step);

		for(unsigned r=0; r<(_rings+1); ++r)
		{
			const auto nr = std::cos(r*r_step);
			const auto ny = std::sin(r*r_step);
			const auto nx = -tz*nr;
			const auto nz =  tx*nr;

			dest[k++] = float(ny*tz-nz*ty);
			dest[k++] = float(nz*tx-nx*tz);
			dest[k++] = float(nx*ty-ny*tx);
		}
	}
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_torus_gen::
wrap_coords(const span<float>& dest)
noexcept
{
	assert(has(vertex_attrib_kind::wrap_coord));
	assert(dest.size() >= vertex_count()*2);

	unsigned k = 0;

	const auto s_step = 1.f / _sections;
	const auto r_step = 1.f / _rings;

	for(unsigned s=0; s<(_sections+1); ++s)
	{
		for(unsigned r=0; r<(_rings+1); ++r)
		{
			dest[k++] = s*s_step;
			dest[k++] = r*r_step;
		}
	}
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_torus_gen::
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
		case vertex_attrib_kind::wrap_coord:
			wrap_coords(dest);
			break;
		case vertex_attrib_kind::box_coord:
		case vertex_attrib_kind::face_coord:
			generator_base::attrib_values(attr, dest);
			break;
	}
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
index_data_type
unit_torus_gen::
index_type(void)
{
	return index_data_type::unsigned_byte;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
unsigned
unit_torus_gen::
index_count(void)
{
	return _sections * ((_rings + 1) * 2 + (primitive_restart()?1:0));
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_torus_gen::
indices(const span<unsigned>& dest)
{
	assert(dest.size() >= index_count());

	const unsigned pri = index_count();
	unsigned k = 0;
	unsigned step = _rings + 1;

	for(unsigned s=0; s<_sections; ++s)
	{
		for(unsigned r=0; r<step; ++r)
		{
			dest[k++] = (s+0)*step + r;
			dest[k++] = (s+1)*step + r;
		}

		if(primitive_restart())
		{
			dest[k++] = pri;
		}
	}
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
unsigned
unit_torus_gen::
operation_count(void)
{
	if(primitive_restart())
	{
		return 1;
	}
	else
	{
		return _sections;
	}
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void
unit_torus_gen::
instructions(const span<draw_operation>& ops)
{
	assert(ops.size() >= operation_count());

	if(primitive_restart())
	{
		draw_operation& op = ops[0];
		op.mode = primitive_type::triangle_strip;
		op.idx_type = index_data_type::unsigned_int;
		op.first = 0;
		op.count = index_count();
		op.primitive_restart_index = index_count();
		op.primitive_restart = true;
	}
	else
	{
		unsigned step = 2*(_rings + 1);
		for(unsigned s=0; s<_sections; ++s)
		{
			draw_operation& op = ops[s];
			op.mode = primitive_type::triangle_strip;
			op.idx_type = index_data_type::unsigned_int;
			op.first = s*step;
			op.count = step;
			op.primitive_restart = false;
		}
	}
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine
