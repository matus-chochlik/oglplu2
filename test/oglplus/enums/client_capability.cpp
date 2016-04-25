//  File test/oglplus/enums/client_capability.cpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt
//
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_client_capability

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_client_capability_tests)

BOOST_AUTO_TEST_CASE(enum_client_capability_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	client_capability x;
	(void)x;

#ifdef GL_COLOR_ARRAY
	x = ev.color_array;
	BOOST_CHECK(x == ev.color_array);
# ifdef GL_EDGE_FLAG_ARRAY
	BOOST_CHECK(x != ev.edge_flag_array);
# endif
# ifdef GL_ELEMENT_ARRAY_UNIFIED_NV
	BOOST_CHECK(x != ev.element_array_unified_nv);
# endif
# ifdef GL_FOG_COORD_ARRAY
	BOOST_CHECK(x != ev.fog_coord_array);
# endif
# ifdef GL_INDEX_ARRAY
	BOOST_CHECK(x != ev.index_array);
# endif
# ifdef GL_NORMAL_ARRAY
	BOOST_CHECK(x != ev.normal_array);
# endif
# ifdef GL_SECONDARY_COLOR_ARRAY
	BOOST_CHECK(x != ev.secondary_color_array);
# endif
# ifdef GL_TEXTURE_COORD_ARRAY
	BOOST_CHECK(x != ev.texture_coord_array);
# endif
# ifdef GL_UNIFORM_BUFFER_UNIFIED_NV
	BOOST_CHECK(x != ev.uniform_buffer_unified_nv);
# endif
# ifdef GL_VERTEX_ARRAY
	BOOST_CHECK(x != ev.vertex_array);
# endif
# ifdef GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV
	BOOST_CHECK(x != ev.vertex_attrib_array_unified_nv);
# endif
#endif

#ifdef GL_EDGE_FLAG_ARRAY
	x = ev.edge_flag_array;
	BOOST_CHECK(x == ev.edge_flag_array);
# ifdef GL_ELEMENT_ARRAY_UNIFIED_NV
	BOOST_CHECK(x != ev.element_array_unified_nv);
# endif
# ifdef GL_FOG_COORD_ARRAY
	BOOST_CHECK(x != ev.fog_coord_array);
# endif
# ifdef GL_INDEX_ARRAY
	BOOST_CHECK(x != ev.index_array);
# endif
# ifdef GL_NORMAL_ARRAY
	BOOST_CHECK(x != ev.normal_array);
# endif
# ifdef GL_SECONDARY_COLOR_ARRAY
	BOOST_CHECK(x != ev.secondary_color_array);
# endif
# ifdef GL_TEXTURE_COORD_ARRAY
	BOOST_CHECK(x != ev.texture_coord_array);
# endif
# ifdef GL_UNIFORM_BUFFER_UNIFIED_NV
	BOOST_CHECK(x != ev.uniform_buffer_unified_nv);
# endif
# ifdef GL_VERTEX_ARRAY
	BOOST_CHECK(x != ev.vertex_array);
# endif
# ifdef GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV
	BOOST_CHECK(x != ev.vertex_attrib_array_unified_nv);
# endif
#endif

#ifdef GL_ELEMENT_ARRAY_UNIFIED_NV
	x = ev.element_array_unified_nv;
	BOOST_CHECK(x == ev.element_array_unified_nv);
# ifdef GL_FOG_COORD_ARRAY
	BOOST_CHECK(x != ev.fog_coord_array);
# endif
# ifdef GL_INDEX_ARRAY
	BOOST_CHECK(x != ev.index_array);
# endif
# ifdef GL_NORMAL_ARRAY
	BOOST_CHECK(x != ev.normal_array);
# endif
# ifdef GL_SECONDARY_COLOR_ARRAY
	BOOST_CHECK(x != ev.secondary_color_array);
# endif
# ifdef GL_TEXTURE_COORD_ARRAY
	BOOST_CHECK(x != ev.texture_coord_array);
# endif
# ifdef GL_UNIFORM_BUFFER_UNIFIED_NV
	BOOST_CHECK(x != ev.uniform_buffer_unified_nv);
# endif
# ifdef GL_VERTEX_ARRAY
	BOOST_CHECK(x != ev.vertex_array);
# endif
# ifdef GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV
	BOOST_CHECK(x != ev.vertex_attrib_array_unified_nv);
# endif
#endif

#ifdef GL_FOG_COORD_ARRAY
	x = ev.fog_coord_array;
	BOOST_CHECK(x == ev.fog_coord_array);
# ifdef GL_INDEX_ARRAY
	BOOST_CHECK(x != ev.index_array);
# endif
# ifdef GL_NORMAL_ARRAY
	BOOST_CHECK(x != ev.normal_array);
# endif
# ifdef GL_SECONDARY_COLOR_ARRAY
	BOOST_CHECK(x != ev.secondary_color_array);
# endif
# ifdef GL_TEXTURE_COORD_ARRAY
	BOOST_CHECK(x != ev.texture_coord_array);
# endif
# ifdef GL_UNIFORM_BUFFER_UNIFIED_NV
	BOOST_CHECK(x != ev.uniform_buffer_unified_nv);
# endif
# ifdef GL_VERTEX_ARRAY
	BOOST_CHECK(x != ev.vertex_array);
# endif
# ifdef GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV
	BOOST_CHECK(x != ev.vertex_attrib_array_unified_nv);
# endif
#endif

#ifdef GL_INDEX_ARRAY
	x = ev.index_array;
	BOOST_CHECK(x == ev.index_array);
# ifdef GL_NORMAL_ARRAY
	BOOST_CHECK(x != ev.normal_array);
# endif
# ifdef GL_SECONDARY_COLOR_ARRAY
	BOOST_CHECK(x != ev.secondary_color_array);
# endif
# ifdef GL_TEXTURE_COORD_ARRAY
	BOOST_CHECK(x != ev.texture_coord_array);
# endif
# ifdef GL_UNIFORM_BUFFER_UNIFIED_NV
	BOOST_CHECK(x != ev.uniform_buffer_unified_nv);
# endif
# ifdef GL_VERTEX_ARRAY
	BOOST_CHECK(x != ev.vertex_array);
# endif
# ifdef GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV
	BOOST_CHECK(x != ev.vertex_attrib_array_unified_nv);
# endif
#endif

#ifdef GL_NORMAL_ARRAY
	x = ev.normal_array;
	BOOST_CHECK(x == ev.normal_array);
# ifdef GL_SECONDARY_COLOR_ARRAY
	BOOST_CHECK(x != ev.secondary_color_array);
# endif
# ifdef GL_TEXTURE_COORD_ARRAY
	BOOST_CHECK(x != ev.texture_coord_array);
# endif
# ifdef GL_UNIFORM_BUFFER_UNIFIED_NV
	BOOST_CHECK(x != ev.uniform_buffer_unified_nv);
# endif
# ifdef GL_VERTEX_ARRAY
	BOOST_CHECK(x != ev.vertex_array);
# endif
# ifdef GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV
	BOOST_CHECK(x != ev.vertex_attrib_array_unified_nv);
# endif
#endif

#ifdef GL_SECONDARY_COLOR_ARRAY
	x = ev.secondary_color_array;
	BOOST_CHECK(x == ev.secondary_color_array);
# ifdef GL_TEXTURE_COORD_ARRAY
	BOOST_CHECK(x != ev.texture_coord_array);
# endif
# ifdef GL_UNIFORM_BUFFER_UNIFIED_NV
	BOOST_CHECK(x != ev.uniform_buffer_unified_nv);
# endif
# ifdef GL_VERTEX_ARRAY
	BOOST_CHECK(x != ev.vertex_array);
# endif
# ifdef GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV
	BOOST_CHECK(x != ev.vertex_attrib_array_unified_nv);
# endif
#endif

#ifdef GL_TEXTURE_COORD_ARRAY
	x = ev.texture_coord_array;
	BOOST_CHECK(x == ev.texture_coord_array);
# ifdef GL_UNIFORM_BUFFER_UNIFIED_NV
	BOOST_CHECK(x != ev.uniform_buffer_unified_nv);
# endif
# ifdef GL_VERTEX_ARRAY
	BOOST_CHECK(x != ev.vertex_array);
# endif
# ifdef GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV
	BOOST_CHECK(x != ev.vertex_attrib_array_unified_nv);
# endif
#endif

#ifdef GL_UNIFORM_BUFFER_UNIFIED_NV
	x = ev.uniform_buffer_unified_nv;
	BOOST_CHECK(x == ev.uniform_buffer_unified_nv);
# ifdef GL_VERTEX_ARRAY
	BOOST_CHECK(x != ev.vertex_array);
# endif
# ifdef GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV
	BOOST_CHECK(x != ev.vertex_attrib_array_unified_nv);
# endif
#endif

#ifdef GL_VERTEX_ARRAY
	x = ev.vertex_array;
	BOOST_CHECK(x == ev.vertex_array);
# ifdef GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV
	BOOST_CHECK(x != ev.vertex_attrib_array_unified_nv);
# endif
#endif

#ifdef GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV
	x = ev.vertex_attrib_array_unified_nv;
	BOOST_CHECK(x == ev.vertex_attrib_array_unified_nv);
#endif
}

BOOST_AUTO_TEST_CASE(enum_client_capability_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	client_capability x;
	(void)x;

#ifdef GL_COLOR_ARRAY
	x = ev.color_array;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COLOR_ARRAY"
	) == 0);
#endif

#ifdef GL_EDGE_FLAG_ARRAY
	x = ev.edge_flag_array;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"EDGE_FLAG_ARRAY"
	) == 0);
#endif

#ifdef GL_ELEMENT_ARRAY_UNIFIED_NV
	x = ev.element_array_unified_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ELEMENT_ARRAY_UNIFIED_NV"
	) == 0);
#endif

#ifdef GL_FOG_COORD_ARRAY
	x = ev.fog_coord_array;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FOG_COORD_ARRAY"
	) == 0);
#endif

#ifdef GL_INDEX_ARRAY
	x = ev.index_array;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"INDEX_ARRAY"
	) == 0);
#endif

#ifdef GL_NORMAL_ARRAY
	x = ev.normal_array;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NORMAL_ARRAY"
	) == 0);
#endif

#ifdef GL_SECONDARY_COLOR_ARRAY
	x = ev.secondary_color_array;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SECONDARY_COLOR_ARRAY"
	) == 0);
#endif

#ifdef GL_TEXTURE_COORD_ARRAY
	x = ev.texture_coord_array;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_COORD_ARRAY"
	) == 0);
#endif

#ifdef GL_UNIFORM_BUFFER_UNIFIED_NV
	x = ev.uniform_buffer_unified_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNIFORM_BUFFER_UNIFIED_NV"
	) == 0);
#endif

#ifdef GL_VERTEX_ARRAY
	x = ev.vertex_array;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"VERTEX_ARRAY"
	) == 0);
#endif

#ifdef GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV
	x = ev.vertex_attrib_array_unified_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"VERTEX_ATTRIB_ARRAY_UNIFIED_NV"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_client_capability_range)
{
	using namespace oglplus;
	auto count = enum_value_range<client_capability>().size();

#ifdef GL_COLOR_ARRAY
{
	--count;
	auto r = enum_value_range<client_capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		client_capability(GL_COLOR_ARRAY)
	) != r.end());
}
#endif

#ifdef GL_EDGE_FLAG_ARRAY
{
	--count;
	auto r = enum_value_range<client_capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		client_capability(GL_EDGE_FLAG_ARRAY)
	) != r.end());
}
#endif

#ifdef GL_ELEMENT_ARRAY_UNIFIED_NV
{
	--count;
	auto r = enum_value_range<client_capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		client_capability(GL_ELEMENT_ARRAY_UNIFIED_NV)
	) != r.end());
}
#endif

#ifdef GL_FOG_COORD_ARRAY
{
	--count;
	auto r = enum_value_range<client_capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		client_capability(GL_FOG_COORD_ARRAY)
	) != r.end());
}
#endif

#ifdef GL_INDEX_ARRAY
{
	--count;
	auto r = enum_value_range<client_capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		client_capability(GL_INDEX_ARRAY)
	) != r.end());
}
#endif

#ifdef GL_NORMAL_ARRAY
{
	--count;
	auto r = enum_value_range<client_capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		client_capability(GL_NORMAL_ARRAY)
	) != r.end());
}
#endif

#ifdef GL_SECONDARY_COLOR_ARRAY
{
	--count;
	auto r = enum_value_range<client_capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		client_capability(GL_SECONDARY_COLOR_ARRAY)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_COORD_ARRAY
{
	--count;
	auto r = enum_value_range<client_capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		client_capability(GL_TEXTURE_COORD_ARRAY)
	) != r.end());
}
#endif

#ifdef GL_UNIFORM_BUFFER_UNIFIED_NV
{
	--count;
	auto r = enum_value_range<client_capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		client_capability(GL_UNIFORM_BUFFER_UNIFIED_NV)
	) != r.end());
}
#endif

#ifdef GL_VERTEX_ARRAY
{
	--count;
	auto r = enum_value_range<client_capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		client_capability(GL_VERTEX_ARRAY)
	) != r.end());
}
#endif

#ifdef GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV
{
	--count;
	auto r = enum_value_range<client_capability>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		client_capability(GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_client_capability_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	client_capability x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_COLOR_ARRAY
	x = ev.color_array;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.color_array);
#endif

#ifdef GL_EDGE_FLAG_ARRAY
	x = ev.edge_flag_array;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.edge_flag_array);
#endif

#ifdef GL_ELEMENT_ARRAY_UNIFIED_NV
	x = ev.element_array_unified_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.element_array_unified_nv);
#endif

#ifdef GL_FOG_COORD_ARRAY
	x = ev.fog_coord_array;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.fog_coord_array);
#endif

#ifdef GL_INDEX_ARRAY
	x = ev.index_array;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.index_array);
#endif

#ifdef GL_NORMAL_ARRAY
	x = ev.normal_array;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.normal_array);
#endif

#ifdef GL_SECONDARY_COLOR_ARRAY
	x = ev.secondary_color_array;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.secondary_color_array);
#endif

#ifdef GL_TEXTURE_COORD_ARRAY
	x = ev.texture_coord_array;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_coord_array);
#endif

#ifdef GL_UNIFORM_BUFFER_UNIFIED_NV
	x = ev.uniform_buffer_unified_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.uniform_buffer_unified_nv);
#endif

#ifdef GL_VERTEX_ARRAY
	x = ev.vertex_array;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.vertex_array);
#endif

#ifdef GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV
	x = ev.vertex_attrib_array_unified_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.vertex_attrib_array_unified_nv);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
