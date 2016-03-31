/**
 *  @file oglplus/texgen/data_type.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
data_type_name(slot_data_type type)
noexcept
{
	switch(type)
	{
		case slot_data_type::bool_ :  return cstr_ref("bool");
		case slot_data_type::bool_2:  return cstr_ref("bvec2");
		case slot_data_type::bool_3:  return cstr_ref("bvec3");
		case slot_data_type::bool_4:  return cstr_ref("bvec4");
		case slot_data_type::int_ :   return cstr_ref("int");
		case slot_data_type::int_2:   return cstr_ref("ivec2");
		case slot_data_type::int_3:   return cstr_ref("ivec3");
		case slot_data_type::int_4:   return cstr_ref("ivec4");
		case slot_data_type::float_ : return cstr_ref("float");
		case slot_data_type::float_2: return cstr_ref("vec2");
		case slot_data_type::float_3: return cstr_ref("vec3");
		case slot_data_type::float_4: return cstr_ref("vec4");
	}
	return cstr_ref("_unknown_type_");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
scalar_data_type
elem_data_type(slot_data_type type)
noexcept
{
	switch(type)
	{
		case slot_data_type::bool_ :
		case slot_data_type::bool_2: 
		case slot_data_type::bool_3: 
		case slot_data_type::bool_4: 
			return scalar_data_type::bool_;
		case slot_data_type::int_ : 
		case slot_data_type::int_2: 
		case slot_data_type::int_3: 
		case slot_data_type::int_4: 
			return scalar_data_type::int_;
		case slot_data_type::float_ : 
		case slot_data_type::float_2:
		case slot_data_type::float_3:
		case slot_data_type::float_4:
			return scalar_data_type::float_;
	}
	return scalar_data_type();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
unsigned
data_type_dims(slot_data_type type)
noexcept
{
	switch(type)
	{
		case slot_data_type::bool_ :
		case slot_data_type::int_ : 
		case slot_data_type::float_ : 
			return 1u;
		case slot_data_type::bool_2: 
		case slot_data_type::int_2: 
		case slot_data_type::float_2:
			return 2u;
		case slot_data_type::bool_3: 
		case slot_data_type::int_3: 
		case slot_data_type::float_3:
			return 3u;
		case slot_data_type::bool_4: 
		case slot_data_type::int_4: 
		case slot_data_type::float_4:
			return 4u;
	}
	return 0u;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type
make_data_type(
	scalar_data_type type,
	eagine::valid_if_between<unsigned, 1, 4> dims
) noexcept
{
	switch(type)
	{
		case scalar_data_type::bool_:
		switch(dims.value())
		{
			case 1: return slot_data_type::bool_;
			case 2: return slot_data_type::bool_2;
			case 3: return slot_data_type::bool_3;
			case 4: return slot_data_type::bool_4;
		}
		case scalar_data_type::int_:
		switch(dims.value())
		{
			case 1: return slot_data_type::int_;
			case 2: return slot_data_type::int_2;
			case 3: return slot_data_type::int_3;
			case 4: return slot_data_type::int_4;
		}
		case scalar_data_type::float_:
		switch(dims.value())
		{
			case 1: return slot_data_type::float_;
			case 2: return slot_data_type::float_2;
			case 3: return slot_data_type::float_3;
			case 4: return slot_data_type::float_4;
		}
	}
	return slot_data_type();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type
common_data_type(slot_data_type a, slot_data_type b)
noexcept
{
	if(a == b) return a;

	unsigned da = data_type_dims(a);
	unsigned db = data_type_dims(b);
	unsigned dc = da>db?da:db;

	scalar_data_type ta = elem_data_type(a);
	scalar_data_type tb = elem_data_type(b);
	scalar_data_type tc = int(ta)>int(tb)?ta:tb;

	return make_data_type(tc, dc);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
conversion_prefix(
	std::ostream& out,
	slot_data_type from,
	slot_data_type to
) noexcept
{
	if(from != to)
	{
		out << data_type_name(to) << "(";
	}
	return out;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
conversion_suffix(
	std::ostream& out,
	slot_data_type from,
	slot_data_type to
) noexcept
{
	if(from != to)
	{
		out << ")";
	}
	return out;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
conversion_suffix(
	std::ostream& out,
	slot_data_type from,
	slot_data_type to,
	cstr_ref x, cstr_ref y, cstr_ref z, cstr_ref w
) noexcept
{
	if(from != to)
	{
		unsigned df = data_type_dims(from);
		unsigned dt = data_type_dims(to);

		if((df < 1) && (dt >= 1)) out << "," << x;
		if((df < 2) && (dt >= 2)) out << "," << y;
		if((df < 3) && (dt >= 3)) out << "," << z;
		if((df < 4) && (dt >= 4)) out << "," << w;

		out << ")";
	}
	return out;
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------

