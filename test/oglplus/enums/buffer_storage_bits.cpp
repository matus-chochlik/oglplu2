//  File test/oglplus/enums/buffer_storage_bits.cpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_buffer_storage_bits

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_buffer_storage_bits)

BOOST_AUTO_TEST_CASE(enum_buffer_storage_bits_values)
{
	using namespace oglplus;
	enum_values ev;
	buffer_storage_bits x;

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
# ifdef GL_CLIENT_STORAGE_BIT
	BOOST_CHECK(x != ev.client_storage_bit);
# endif
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
# ifdef GL_CLIENT_STORAGE_BIT
	BOOST_CHECK(x != ev.client_storage_bit);
# endif
# ifdef GL_DYNAMIC_STORAGE_BIT
	BOOST_CHECK(x != ev.dynamic_storage_bit);
# endif
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
# ifdef GL_CLIENT_STORAGE_BIT
	BOOST_CHECK(x != ev.client_storage_bit);
# endif
# ifdef GL_DYNAMIC_STORAGE_BIT
	BOOST_CHECK(x != ev.dynamic_storage_bit);
# endif
# ifdef GL_MAP_COHERENT_BIT
	BOOST_CHECK(x != ev.map_coherent_bit);
# endif
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
# ifdef GL_CLIENT_STORAGE_BIT
	BOOST_CHECK(x != ev.client_storage_bit);
# endif
# ifdef GL_DYNAMIC_STORAGE_BIT
	BOOST_CHECK(x != ev.dynamic_storage_bit);
# endif
# ifdef GL_MAP_COHERENT_BIT
	BOOST_CHECK(x != ev.map_coherent_bit);
# endif
# ifdef GL_MAP_PERSISTENT_BIT
	BOOST_CHECK(x != ev.map_persistent_bit);
# endif
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
# ifdef GL_CLIENT_STORAGE_BIT
	BOOST_CHECK(x != ev.client_storage_bit);
# endif
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
	BOOST_CHECK(x == ev.map_write_bit);
# ifdef GL_SPARSE_STORAGE_BIT_ARB
	BOOST_CHECK(x != ev.sparse_storage_bit);
# endif
#endif

#ifdef GL_SPARSE_STORAGE_BIT_ARB
	x = ev.sparse_storage_bit;
# ifdef GL_CLIENT_STORAGE_BIT
	BOOST_CHECK(x != ev.client_storage_bit);
# endif
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
	BOOST_CHECK(x == ev.sparse_storage_bit);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
