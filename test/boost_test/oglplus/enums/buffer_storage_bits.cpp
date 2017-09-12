//  File test/boost_test/oglplus/enums/buffer_storage_bits.cpp
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
#include "common.hpp"
#define BOOST_TEST_MODULE OGLPLUS_buffer_storage_bits

#include "../../unit_test_begin.inl"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_buffer_storage_bits_tests)

BOOST_AUTO_TEST_CASE(enum_buffer_storage_bits_values)
{
	using namespace oglplus;
	enum_values ev;
	EAGINE_MAYBE_UNUSED(ev);
	buffer_storage_bits x;
	EAGINE_MAYBE_UNUSED(x);

#ifdef GL_CLIENT_STORAGE_BIT
	x = ev.client_storage_bit;
	BOOST_CHECK(x == ev.client_storage_bit);
# ifdef GL_DYNAMIC_STORAGE_BIT
	BOOST_CHECK(x != ev.dynamic_storage_bit);
# endif
# ifdef GL_MAP_COHERENT_BIT
	BOOST_CHECK(x != ev.map_coherent_bit);
# endif
# ifdef GL_MAP_PERSISTENT_BIT
	BOOST_CHECK(x != ev.map_persistent_bit);
# endif
# ifdef GL_MAP_READ_BIT
	BOOST_CHECK(x != ev.map_read_bit);
# endif
# ifdef GL_MAP_WRITE_BIT
	BOOST_CHECK(x != ev.map_write_bit);
# endif
# ifdef GL_SPARSE_STORAGE_BIT_ARB
	BOOST_CHECK(x != ev.sparse_storage_bit);
# endif
#endif

#ifdef GL_DYNAMIC_STORAGE_BIT
	x = ev.dynamic_storage_bit;
	BOOST_CHECK(x == ev.dynamic_storage_bit);
# ifdef GL_MAP_COHERENT_BIT
	BOOST_CHECK(x != ev.map_coherent_bit);
# endif
# ifdef GL_MAP_PERSISTENT_BIT
	BOOST_CHECK(x != ev.map_persistent_bit);
# endif
# ifdef GL_MAP_READ_BIT
	BOOST_CHECK(x != ev.map_read_bit);
# endif
# ifdef GL_MAP_WRITE_BIT
	BOOST_CHECK(x != ev.map_write_bit);
# endif
# ifdef GL_SPARSE_STORAGE_BIT_ARB
	BOOST_CHECK(x != ev.sparse_storage_bit);
# endif
#endif

#ifdef GL_MAP_COHERENT_BIT
	x = ev.map_coherent_bit;
	BOOST_CHECK(x == ev.map_coherent_bit);
# ifdef GL_MAP_PERSISTENT_BIT
	BOOST_CHECK(x != ev.map_persistent_bit);
# endif
# ifdef GL_MAP_READ_BIT
	BOOST_CHECK(x != ev.map_read_bit);
# endif
# ifdef GL_MAP_WRITE_BIT
	BOOST_CHECK(x != ev.map_write_bit);
# endif
# ifdef GL_SPARSE_STORAGE_BIT_ARB
	BOOST_CHECK(x != ev.sparse_storage_bit);
# endif
#endif

#ifdef GL_MAP_PERSISTENT_BIT
	x = ev.map_persistent_bit;
	BOOST_CHECK(x == ev.map_persistent_bit);
# ifdef GL_MAP_READ_BIT
	BOOST_CHECK(x != ev.map_read_bit);
# endif
# ifdef GL_MAP_WRITE_BIT
	BOOST_CHECK(x != ev.map_write_bit);
# endif
# ifdef GL_SPARSE_STORAGE_BIT_ARB
	BOOST_CHECK(x != ev.sparse_storage_bit);
# endif
#endif

#ifdef GL_MAP_READ_BIT
	x = ev.map_read_bit;
	BOOST_CHECK(x == ev.map_read_bit);
# ifdef GL_MAP_WRITE_BIT
	BOOST_CHECK(x != ev.map_write_bit);
# endif
# ifdef GL_SPARSE_STORAGE_BIT_ARB
	BOOST_CHECK(x != ev.sparse_storage_bit);
# endif
#endif

#ifdef GL_MAP_WRITE_BIT
	x = ev.map_write_bit;
	BOOST_CHECK(x == ev.map_write_bit);
# ifdef GL_SPARSE_STORAGE_BIT_ARB
	BOOST_CHECK(x != ev.sparse_storage_bit);
# endif
#endif

#ifdef GL_SPARSE_STORAGE_BIT_ARB
	x = ev.sparse_storage_bit;
	BOOST_CHECK(x == ev.sparse_storage_bit);
#endif
}

BOOST_AUTO_TEST_CASE(enum_buffer_storage_bits_names)
{
	using namespace oglplus;
	enum_values ev;
	EAGINE_MAYBE_UNUSED(ev);
	buffer_storage_bits x;
	EAGINE_MAYBE_UNUSED(x);

#ifdef GL_CLIENT_STORAGE_BIT
	x = ev.client_storage_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CLIENT_STORAGE_BIT"
	) == 0);
#endif

#ifdef GL_DYNAMIC_STORAGE_BIT
	x = ev.dynamic_storage_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DYNAMIC_STORAGE_BIT"
	) == 0);
#endif

#ifdef GL_MAP_COHERENT_BIT
	x = ev.map_coherent_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAP_COHERENT_BIT"
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

#ifdef GL_MAP_WRITE_BIT
	x = ev.map_write_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MAP_WRITE_BIT"
	) == 0);
#endif

#ifdef GL_SPARSE_STORAGE_BIT_ARB
	x = ev.sparse_storage_bit;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SPARSE_STORAGE_BIT_ARB"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_buffer_storage_bits_range)
{
	using namespace oglplus;
	auto count = enum_value_range<buffer_storage_bits>().size();

#ifdef GL_CLIENT_STORAGE_BIT
{
	--count;
	auto r = enum_value_range<buffer_storage_bits>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_storage_bits(GL_CLIENT_STORAGE_BIT)
	) != r.end());
}
#endif

#ifdef GL_DYNAMIC_STORAGE_BIT
{
	--count;
	auto r = enum_value_range<buffer_storage_bits>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_storage_bits(GL_DYNAMIC_STORAGE_BIT)
	) != r.end());
}
#endif

#ifdef GL_MAP_COHERENT_BIT
{
	--count;
	auto r = enum_value_range<buffer_storage_bits>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_storage_bits(GL_MAP_COHERENT_BIT)
	) != r.end());
}
#endif

#ifdef GL_MAP_PERSISTENT_BIT
{
	--count;
	auto r = enum_value_range<buffer_storage_bits>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_storage_bits(GL_MAP_PERSISTENT_BIT)
	) != r.end());
}
#endif

#ifdef GL_MAP_READ_BIT
{
	--count;
	auto r = enum_value_range<buffer_storage_bits>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_storage_bits(GL_MAP_READ_BIT)
	) != r.end());
}
#endif

#ifdef GL_MAP_WRITE_BIT
{
	--count;
	auto r = enum_value_range<buffer_storage_bits>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_storage_bits(GL_MAP_WRITE_BIT)
	) != r.end());
}
#endif

#ifdef GL_SPARSE_STORAGE_BIT_ARB
{
	--count;
	auto r = enum_value_range<buffer_storage_bits>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		buffer_storage_bits(GL_SPARSE_STORAGE_BIT_ARB)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_buffer_storage_bits_any)
{
	using namespace oglplus;
	enum_values ev;
	EAGINE_MAYBE_UNUSED(ev);
	buffer_storage_bits x, y;
	EAGINE_MAYBE_UNUSED(x);
	EAGINE_MAYBE_UNUSED(y);
	any_enum_value a;
	EAGINE_MAYBE_UNUSED(a);

#ifdef GL_CLIENT_STORAGE_BIT
	x = ev.client_storage_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.client_storage_bit);
#endif

#ifdef GL_DYNAMIC_STORAGE_BIT
	x = ev.dynamic_storage_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.dynamic_storage_bit);
#endif

#ifdef GL_MAP_COHERENT_BIT
	x = ev.map_coherent_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.map_coherent_bit);
#endif

#ifdef GL_MAP_PERSISTENT_BIT
	x = ev.map_persistent_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.map_persistent_bit);
#endif

#ifdef GL_MAP_READ_BIT
	x = ev.map_read_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.map_read_bit);
#endif

#ifdef GL_MAP_WRITE_BIT
	x = ev.map_write_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.map_write_bit);
#endif

#ifdef GL_SPARSE_STORAGE_BIT_ARB
	x = ev.sparse_storage_bit;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.sparse_storage_bit);
#endif
}

BOOST_AUTO_TEST_SUITE_END()

#include "../../unit_test_end.inl"
