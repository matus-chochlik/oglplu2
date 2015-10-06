//  File test/oglplus/enums/buffer_map_access.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_buffer_map_access

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_buffer_map_access)

BOOST_AUTO_TEST_CASE(enum_buffer_map_access_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	buffer_map_access x;
	(void)x;

#ifdef GL_MAP_COHERENT_BIT
	x = ev.map_coherent_bit;
	BOOST_CHECK(x == ev.map_coherent_bit);
# ifdef GL_MAP_FLUSH_EXPLICIT_BIT
	BOOST_CHECK(x != ev.map_flush_explicit_bit);
# endif
# ifdef GL_MAP_INVALIDATE_BUFFER_BIT
	BOOST_CHECK(x != ev.map_invalidate_buffer_bit);
# endif
# ifdef GL_MAP_INVALIDATE_RANGE_BIT
	BOOST_CHECK(x != ev.map_invalidate_range_bit);
# endif
# ifdef GL_MAP_PERSISTENT_BIT
	BOOST_CHECK(x != ev.map_persistent_bit);
# endif
# ifdef GL_MAP_READ_BIT
	BOOST_CHECK(x != ev.map_read_bit);
# endif
# ifdef GL_MAP_UNSYNCHRONIZED_BIT
	BOOST_CHECK(x != ev.map_unsynchronized_bit);
# endif
# ifdef GL_MAP_WRITE_BIT
	BOOST_CHECK(x != ev.map_write_bit);
# endif
#endif

#ifdef GL_MAP_FLUSH_EXPLICIT_BIT
	x = ev.map_flush_explicit_bit;
# ifdef GL_MAP_COHERENT_BIT
	BOOST_CHECK(x != ev.map_coherent_bit);
# endif
	BOOST_CHECK(x == ev.map_flush_explicit_bit);
# ifdef GL_MAP_INVALIDATE_BUFFER_BIT
	BOOST_CHECK(x != ev.map_invalidate_buffer_bit);
# endif
# ifdef GL_MAP_INVALIDATE_RANGE_BIT
	BOOST_CHECK(x != ev.map_invalidate_range_bit);
# endif
# ifdef GL_MAP_PERSISTENT_BIT
	BOOST_CHECK(x != ev.map_persistent_bit);
# endif
# ifdef GL_MAP_READ_BIT
	BOOST_CHECK(x != ev.map_read_bit);
# endif
# ifdef GL_MAP_UNSYNCHRONIZED_BIT
	BOOST_CHECK(x != ev.map_unsynchronized_bit);
# endif
# ifdef GL_MAP_WRITE_BIT
	BOOST_CHECK(x != ev.map_write_bit);
# endif
#endif

#ifdef GL_MAP_INVALIDATE_BUFFER_BIT
	x = ev.map_invalidate_buffer_bit;
# ifdef GL_MAP_COHERENT_BIT
	BOOST_CHECK(x != ev.map_coherent_bit);
# endif
# ifdef GL_MAP_FLUSH_EXPLICIT_BIT
	BOOST_CHECK(x != ev.map_flush_explicit_bit);
# endif
	BOOST_CHECK(x == ev.map_invalidate_buffer_bit);
# ifdef GL_MAP_INVALIDATE_RANGE_BIT
	BOOST_CHECK(x != ev.map_invalidate_range_bit);
# endif
# ifdef GL_MAP_PERSISTENT_BIT
	BOOST_CHECK(x != ev.map_persistent_bit);
# endif
# ifdef GL_MAP_READ_BIT
	BOOST_CHECK(x != ev.map_read_bit);
# endif
# ifdef GL_MAP_UNSYNCHRONIZED_BIT
	BOOST_CHECK(x != ev.map_unsynchronized_bit);
# endif
# ifdef GL_MAP_WRITE_BIT
	BOOST_CHECK(x != ev.map_write_bit);
# endif
#endif

#ifdef GL_MAP_INVALIDATE_RANGE_BIT
	x = ev.map_invalidate_range_bit;
# ifdef GL_MAP_COHERENT_BIT
	BOOST_CHECK(x != ev.map_coherent_bit);
# endif
# ifdef GL_MAP_FLUSH_EXPLICIT_BIT
	BOOST_CHECK(x != ev.map_flush_explicit_bit);
# endif
# ifdef GL_MAP_INVALIDATE_BUFFER_BIT
	BOOST_CHECK(x != ev.map_invalidate_buffer_bit);
# endif
	BOOST_CHECK(x == ev.map_invalidate_range_bit);
# ifdef GL_MAP_PERSISTENT_BIT
	BOOST_CHECK(x != ev.map_persistent_bit);
# endif
# ifdef GL_MAP_READ_BIT
	BOOST_CHECK(x != ev.map_read_bit);
# endif
# ifdef GL_MAP_UNSYNCHRONIZED_BIT
	BOOST_CHECK(x != ev.map_unsynchronized_bit);
# endif
# ifdef GL_MAP_WRITE_BIT
	BOOST_CHECK(x != ev.map_write_bit);
# endif
#endif

#ifdef GL_MAP_PERSISTENT_BIT
	x = ev.map_persistent_bit;
# ifdef GL_MAP_COHERENT_BIT
	BOOST_CHECK(x != ev.map_coherent_bit);
# endif
# ifdef GL_MAP_FLUSH_EXPLICIT_BIT
	BOOST_CHECK(x != ev.map_flush_explicit_bit);
# endif
# ifdef GL_MAP_INVALIDATE_BUFFER_BIT
	BOOST_CHECK(x != ev.map_invalidate_buffer_bit);
# endif
# ifdef GL_MAP_INVALIDATE_RANGE_BIT
	BOOST_CHECK(x != ev.map_invalidate_range_bit);
# endif
	BOOST_CHECK(x == ev.map_persistent_bit);
# ifdef GL_MAP_READ_BIT
	BOOST_CHECK(x != ev.map_read_bit);
# endif
# ifdef GL_MAP_UNSYNCHRONIZED_BIT
	BOOST_CHECK(x != ev.map_unsynchronized_bit);
# endif
# ifdef GL_MAP_WRITE_BIT
	BOOST_CHECK(x != ev.map_write_bit);
# endif
#endif

#ifdef GL_MAP_READ_BIT
	x = ev.map_read_bit;
# ifdef GL_MAP_COHERENT_BIT
	BOOST_CHECK(x != ev.map_coherent_bit);
# endif
# ifdef GL_MAP_FLUSH_EXPLICIT_BIT
	BOOST_CHECK(x != ev.map_flush_explicit_bit);
# endif
# ifdef GL_MAP_INVALIDATE_BUFFER_BIT
	BOOST_CHECK(x != ev.map_invalidate_buffer_bit);
# endif
# ifdef GL_MAP_INVALIDATE_RANGE_BIT
	BOOST_CHECK(x != ev.map_invalidate_range_bit);
# endif
# ifdef GL_MAP_PERSISTENT_BIT
	BOOST_CHECK(x != ev.map_persistent_bit);
# endif
	BOOST_CHECK(x == ev.map_read_bit);
# ifdef GL_MAP_UNSYNCHRONIZED_BIT
	BOOST_CHECK(x != ev.map_unsynchronized_bit);
# endif
# ifdef GL_MAP_WRITE_BIT
	BOOST_CHECK(x != ev.map_write_bit);
# endif
#endif

#ifdef GL_MAP_UNSYNCHRONIZED_BIT
	x = ev.map_unsynchronized_bit;
# ifdef GL_MAP_COHERENT_BIT
	BOOST_CHECK(x != ev.map_coherent_bit);
# endif
# ifdef GL_MAP_FLUSH_EXPLICIT_BIT
	BOOST_CHECK(x != ev.map_flush_explicit_bit);
# endif
# ifdef GL_MAP_INVALIDATE_BUFFER_BIT
	BOOST_CHECK(x != ev.map_invalidate_buffer_bit);
# endif
# ifdef GL_MAP_INVALIDATE_RANGE_BIT
	BOOST_CHECK(x != ev.map_invalidate_range_bit);
# endif
# ifdef GL_MAP_PERSISTENT_BIT
	BOOST_CHECK(x != ev.map_persistent_bit);
# endif
# ifdef GL_MAP_READ_BIT
	BOOST_CHECK(x != ev.map_read_bit);
# endif
	BOOST_CHECK(x == ev.map_unsynchronized_bit);
# ifdef GL_MAP_WRITE_BIT
	BOOST_CHECK(x != ev.map_write_bit);
# endif
#endif

#ifdef GL_MAP_WRITE_BIT
	x = ev.map_write_bit;
# ifdef GL_MAP_COHERENT_BIT
	BOOST_CHECK(x != ev.map_coherent_bit);
# endif
# ifdef GL_MAP_FLUSH_EXPLICIT_BIT
	BOOST_CHECK(x != ev.map_flush_explicit_bit);
# endif
# ifdef GL_MAP_INVALIDATE_BUFFER_BIT
	BOOST_CHECK(x != ev.map_invalidate_buffer_bit);
# endif
# ifdef GL_MAP_INVALIDATE_RANGE_BIT
	BOOST_CHECK(x != ev.map_invalidate_range_bit);
# endif
# ifdef GL_MAP_PERSISTENT_BIT
	BOOST_CHECK(x != ev.map_persistent_bit);
# endif
# ifdef GL_MAP_READ_BIT
	BOOST_CHECK(x != ev.map_read_bit);
# endif
# ifdef GL_MAP_UNSYNCHRONIZED_BIT
	BOOST_CHECK(x != ev.map_unsynchronized_bit);
# endif
	BOOST_CHECK(x == ev.map_write_bit);
#endif
}

BOOST_AUTO_TEST_CASE(enum_buffer_map_access_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	buffer_map_access x;
	(void)x;

#ifdef GL_MAP_COHERENT_BIT
	x = ev.map_coherent_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAP_COHERENT_BIT"
	) == 0);
#endif

#ifdef GL_MAP_FLUSH_EXPLICIT_BIT
	x = ev.map_flush_explicit_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAP_FLUSH_EXPLICIT_BIT"
	) == 0);
#endif

#ifdef GL_MAP_INVALIDATE_BUFFER_BIT
	x = ev.map_invalidate_buffer_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAP_INVALIDATE_BUFFER_BIT"
	) == 0);
#endif

#ifdef GL_MAP_INVALIDATE_RANGE_BIT
	x = ev.map_invalidate_range_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAP_INVALIDATE_RANGE_BIT"
	) == 0);
#endif

#ifdef GL_MAP_PERSISTENT_BIT
	x = ev.map_persistent_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAP_PERSISTENT_BIT"
	) == 0);
#endif

#ifdef GL_MAP_READ_BIT
	x = ev.map_read_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAP_READ_BIT"
	) == 0);
#endif

#ifdef GL_MAP_UNSYNCHRONIZED_BIT
	x = ev.map_unsynchronized_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAP_UNSYNCHRONIZED_BIT"
	) == 0);
#endif

#ifdef GL_MAP_WRITE_BIT
	x = ev.map_write_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAP_WRITE_BIT"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_buffer_map_access_range)
{
	using namespace oglplus;
	buffer_map_access x;
	(void)x;
	auto count = enum_value_range(x).size();

#ifdef GL_MAP_COHERENT_BIT
{
	--count;
	array_view<const GLbitfield> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_MAP_COHERENT_BIT
	) != r.end());
}
#endif

#ifdef GL_MAP_FLUSH_EXPLICIT_BIT
{
	--count;
	array_view<const GLbitfield> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_MAP_FLUSH_EXPLICIT_BIT
	) != r.end());
}
#endif

#ifdef GL_MAP_INVALIDATE_BUFFER_BIT
{
	--count;
	array_view<const GLbitfield> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_MAP_INVALIDATE_BUFFER_BIT
	) != r.end());
}
#endif

#ifdef GL_MAP_INVALIDATE_RANGE_BIT
{
	--count;
	array_view<const GLbitfield> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_MAP_INVALIDATE_RANGE_BIT
	) != r.end());
}
#endif

#ifdef GL_MAP_PERSISTENT_BIT
{
	--count;
	array_view<const GLbitfield> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_MAP_PERSISTENT_BIT
	) != r.end());
}
#endif

#ifdef GL_MAP_READ_BIT
{
	--count;
	array_view<const GLbitfield> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_MAP_READ_BIT
	) != r.end());
}
#endif

#ifdef GL_MAP_UNSYNCHRONIZED_BIT
{
	--count;
	array_view<const GLbitfield> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_MAP_UNSYNCHRONIZED_BIT
	) != r.end());
}
#endif

#ifdef GL_MAP_WRITE_BIT
{
	--count;
	array_view<const GLbitfield> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_MAP_WRITE_BIT
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_SUITE_END()
