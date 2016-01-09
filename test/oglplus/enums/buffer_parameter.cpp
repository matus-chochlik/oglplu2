//  File test/oglplus/enums/buffer_parameter.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_buffer_parameter

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_buffer_parameter_tests)

BOOST_AUTO_TEST_CASE(enum_buffer_parameter_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	buffer_parameter x;
	(void)x;

#ifdef GL_BUFFER_ACCESS
	x = ev.buffer_access;
	BOOST_CHECK(x == ev.buffer_access);
# ifdef GL_BUFFER_ACCESS_FLAGS
	BOOST_CHECK(x != ev.buffer_access_flags);
# endif
# ifdef GL_BUFFER_IMMUTABLE_STORAGE
	BOOST_CHECK(x != ev.buffer_immutable_storage);
# endif
# ifdef GL_BUFFER_MAP_LENGTH
	BOOST_CHECK(x != ev.buffer_map_length);
# endif
# ifdef GL_BUFFER_MAP_OFFSET
	BOOST_CHECK(x != ev.buffer_map_offset);
# endif
# ifdef GL_BUFFER_MAPPED
	BOOST_CHECK(x != ev.buffer_mapped);
# endif
# ifdef GL_BUFFER_SIZE
	BOOST_CHECK(x != ev.buffer_size);
# endif
# ifdef GL_BUFFER_STORAGE_FLAGS
	BOOST_CHECK(x != ev.buffer_storage_flags);
# endif
# ifdef GL_BUFFER_USAGE
	BOOST_CHECK(x != ev.buffer_usage);
# endif
#endif

#ifdef GL_BUFFER_ACCESS_FLAGS
	x = ev.buffer_access_flags;
	BOOST_CHECK(x == ev.buffer_access_flags);
# ifdef GL_BUFFER_IMMUTABLE_STORAGE
	BOOST_CHECK(x != ev.buffer_immutable_storage);
# endif
# ifdef GL_BUFFER_MAP_LENGTH
	BOOST_CHECK(x != ev.buffer_map_length);
# endif
# ifdef GL_BUFFER_MAP_OFFSET
	BOOST_CHECK(x != ev.buffer_map_offset);
# endif
# ifdef GL_BUFFER_MAPPED
	BOOST_CHECK(x != ev.buffer_mapped);
# endif
# ifdef GL_BUFFER_SIZE
	BOOST_CHECK(x != ev.buffer_size);
# endif
# ifdef GL_BUFFER_STORAGE_FLAGS
	BOOST_CHECK(x != ev.buffer_storage_flags);
# endif
# ifdef GL_BUFFER_USAGE
	BOOST_CHECK(x != ev.buffer_usage);
# endif
#endif

#ifdef GL_BUFFER_IMMUTABLE_STORAGE
	x = ev.buffer_immutable_storage;
	BOOST_CHECK(x == ev.buffer_immutable_storage);
# ifdef GL_BUFFER_MAP_LENGTH
	BOOST_CHECK(x != ev.buffer_map_length);
# endif
# ifdef GL_BUFFER_MAP_OFFSET
	BOOST_CHECK(x != ev.buffer_map_offset);
# endif
# ifdef GL_BUFFER_MAPPED
	BOOST_CHECK(x != ev.buffer_mapped);
# endif
# ifdef GL_BUFFER_SIZE
	BOOST_CHECK(x != ev.buffer_size);
# endif
# ifdef GL_BUFFER_STORAGE_FLAGS
	BOOST_CHECK(x != ev.buffer_storage_flags);
# endif
# ifdef GL_BUFFER_USAGE
	BOOST_CHECK(x != ev.buffer_usage);
# endif
#endif

#ifdef GL_BUFFER_MAP_LENGTH
	x = ev.buffer_map_length;
	BOOST_CHECK(x == ev.buffer_map_length);
# ifdef GL_BUFFER_MAP_OFFSET
	BOOST_CHECK(x != ev.buffer_map_offset);
# endif
# ifdef GL_BUFFER_MAPPED
	BOOST_CHECK(x != ev.buffer_mapped);
# endif
# ifdef GL_BUFFER_SIZE
	BOOST_CHECK(x != ev.buffer_size);
# endif
# ifdef GL_BUFFER_STORAGE_FLAGS
	BOOST_CHECK(x != ev.buffer_storage_flags);
# endif
# ifdef GL_BUFFER_USAGE
	BOOST_CHECK(x != ev.buffer_usage);
# endif
#endif

#ifdef GL_BUFFER_MAP_OFFSET
	x = ev.buffer_map_offset;
	BOOST_CHECK(x == ev.buffer_map_offset);
# ifdef GL_BUFFER_MAPPED
	BOOST_CHECK(x != ev.buffer_mapped);
# endif
# ifdef GL_BUFFER_SIZE
	BOOST_CHECK(x != ev.buffer_size);
# endif
# ifdef GL_BUFFER_STORAGE_FLAGS
	BOOST_CHECK(x != ev.buffer_storage_flags);
# endif
# ifdef GL_BUFFER_USAGE
	BOOST_CHECK(x != ev.buffer_usage);
# endif
#endif

#ifdef GL_BUFFER_MAPPED
	x = ev.buffer_mapped;
	BOOST_CHECK(x == ev.buffer_mapped);
# ifdef GL_BUFFER_SIZE
	BOOST_CHECK(x != ev.buffer_size);
# endif
# ifdef GL_BUFFER_STORAGE_FLAGS
	BOOST_CHECK(x != ev.buffer_storage_flags);
# endif
# ifdef GL_BUFFER_USAGE
	BOOST_CHECK(x != ev.buffer_usage);
# endif
#endif

#ifdef GL_BUFFER_SIZE
	x = ev.buffer_size;
	BOOST_CHECK(x == ev.buffer_size);
# ifdef GL_BUFFER_STORAGE_FLAGS
	BOOST_CHECK(x != ev.buffer_storage_flags);
# endif
# ifdef GL_BUFFER_USAGE
	BOOST_CHECK(x != ev.buffer_usage);
# endif
#endif

#ifdef GL_BUFFER_STORAGE_FLAGS
	x = ev.buffer_storage_flags;
	BOOST_CHECK(x == ev.buffer_storage_flags);
# ifdef GL_BUFFER_USAGE
	BOOST_CHECK(x != ev.buffer_usage);
# endif
#endif

#ifdef GL_BUFFER_USAGE
	x = ev.buffer_usage;
	BOOST_CHECK(x == ev.buffer_usage);
#endif
}

BOOST_AUTO_TEST_CASE(enum_buffer_parameter_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	buffer_parameter x;
	(void)x;

#ifdef GL_BUFFER_ACCESS
	x = ev.buffer_access;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BUFFER_ACCESS"
	) == 0);
#endif

#ifdef GL_BUFFER_ACCESS_FLAGS
	x = ev.buffer_access_flags;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BUFFER_ACCESS_FLAGS"
	) == 0);
#endif

#ifdef GL_BUFFER_IMMUTABLE_STORAGE
	x = ev.buffer_immutable_storage;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BUFFER_IMMUTABLE_STORAGE"
	) == 0);
#endif

#ifdef GL_BUFFER_MAP_LENGTH
	x = ev.buffer_map_length;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BUFFER_MAP_LENGTH"
	) == 0);
#endif

#ifdef GL_BUFFER_MAP_OFFSET
	x = ev.buffer_map_offset;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BUFFER_MAP_OFFSET"
	) == 0);
#endif

#ifdef GL_BUFFER_MAPPED
	x = ev.buffer_mapped;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BUFFER_MAPPED"
	) == 0);
#endif

#ifdef GL_BUFFER_SIZE
	x = ev.buffer_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BUFFER_SIZE"
	) == 0);
#endif

#ifdef GL_BUFFER_STORAGE_FLAGS
	x = ev.buffer_storage_flags;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BUFFER_STORAGE_FLAGS"
	) == 0);
#endif

#ifdef GL_BUFFER_USAGE
	x = ev.buffer_usage;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BUFFER_USAGE"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_buffer_parameter_range)
{
	using namespace oglplus;
	auto count = enum_value_range<buffer_parameter>().size();

#ifdef GL_BUFFER_ACCESS
{
	--count;
	auto r = enum_value_range<buffer_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_parameter(GL_BUFFER_ACCESS)
	) != r.end());
}
#endif

#ifdef GL_BUFFER_ACCESS_FLAGS
{
	--count;
	auto r = enum_value_range<buffer_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_parameter(GL_BUFFER_ACCESS_FLAGS)
	) != r.end());
}
#endif

#ifdef GL_BUFFER_IMMUTABLE_STORAGE
{
	--count;
	auto r = enum_value_range<buffer_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_parameter(GL_BUFFER_IMMUTABLE_STORAGE)
	) != r.end());
}
#endif

#ifdef GL_BUFFER_MAP_LENGTH
{
	--count;
	auto r = enum_value_range<buffer_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_parameter(GL_BUFFER_MAP_LENGTH)
	) != r.end());
}
#endif

#ifdef GL_BUFFER_MAP_OFFSET
{
	--count;
	auto r = enum_value_range<buffer_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_parameter(GL_BUFFER_MAP_OFFSET)
	) != r.end());
}
#endif

#ifdef GL_BUFFER_MAPPED
{
	--count;
	auto r = enum_value_range<buffer_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_parameter(GL_BUFFER_MAPPED)
	) != r.end());
}
#endif

#ifdef GL_BUFFER_SIZE
{
	--count;
	auto r = enum_value_range<buffer_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_parameter(GL_BUFFER_SIZE)
	) != r.end());
}
#endif

#ifdef GL_BUFFER_STORAGE_FLAGS
{
	--count;
	auto r = enum_value_range<buffer_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_parameter(GL_BUFFER_STORAGE_FLAGS)
	) != r.end());
}
#endif

#ifdef GL_BUFFER_USAGE
{
	--count;
	auto r = enum_value_range<buffer_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_parameter(GL_BUFFER_USAGE)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_buffer_parameter_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	buffer_parameter x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_BUFFER_ACCESS
	x = ev.buffer_access;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.buffer_access);
#endif

#ifdef GL_BUFFER_ACCESS_FLAGS
	x = ev.buffer_access_flags;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.buffer_access_flags);
#endif

#ifdef GL_BUFFER_IMMUTABLE_STORAGE
	x = ev.buffer_immutable_storage;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.buffer_immutable_storage);
#endif

#ifdef GL_BUFFER_MAP_LENGTH
	x = ev.buffer_map_length;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.buffer_map_length);
#endif

#ifdef GL_BUFFER_MAP_OFFSET
	x = ev.buffer_map_offset;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.buffer_map_offset);
#endif

#ifdef GL_BUFFER_MAPPED
	x = ev.buffer_mapped;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.buffer_mapped);
#endif

#ifdef GL_BUFFER_SIZE
	x = ev.buffer_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.buffer_size);
#endif

#ifdef GL_BUFFER_STORAGE_FLAGS
	x = ev.buffer_storage_flags;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.buffer_storage_flags);
#endif

#ifdef GL_BUFFER_USAGE
	x = ev.buffer_usage;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.buffer_usage);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
