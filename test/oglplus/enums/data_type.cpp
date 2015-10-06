//  File test/oglplus/enums/data_type.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_data_type

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_data_type)

BOOST_AUTO_TEST_CASE(enum_data_type_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	data_type x;
	(void)x;

#ifdef GL_BYTE
	x = ev.byte_;
	BOOST_CHECK(x == ev.byte_);
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_FIXED
	BOOST_CHECK(x != ev.fixed);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
#endif

#ifdef GL_DOUBLE
	x = ev.double_;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
	BOOST_CHECK(x == ev.double_);
# ifdef GL_FIXED
	BOOST_CHECK(x != ev.fixed);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
#endif

#ifdef GL_FIXED
	x = ev.fixed;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
	BOOST_CHECK(x == ev.fixed);
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
#endif

#ifdef GL_FLOAT
	x = ev.float_;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_FIXED
	BOOST_CHECK(x != ev.fixed);
# endif
	BOOST_CHECK(x == ev.float_);
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
#endif

#ifdef GL_HALF_FLOAT
	x = ev.half_float;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_FIXED
	BOOST_CHECK(x != ev.fixed);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
	BOOST_CHECK(x == ev.half_float);
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
#endif

#ifdef GL_INT
	x = ev.int_;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_FIXED
	BOOST_CHECK(x != ev.fixed);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
	BOOST_CHECK(x == ev.int_);
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
#endif

#ifdef GL_SHORT
	x = ev.short_;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_FIXED
	BOOST_CHECK(x != ev.fixed);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
	BOOST_CHECK(x == ev.short_);
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
#endif

#ifdef GL_UNSIGNED_BYTE
	x = ev.unsigned_byte;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_FIXED
	BOOST_CHECK(x != ev.fixed);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
	BOOST_CHECK(x == ev.unsigned_byte);
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
#endif

#ifdef GL_UNSIGNED_INT
	x = ev.unsigned_int;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_FIXED
	BOOST_CHECK(x != ev.fixed);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
	BOOST_CHECK(x == ev.unsigned_int);
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
#endif

#ifdef GL_UNSIGNED_SHORT
	x = ev.unsigned_short;
# ifdef GL_BYTE
	BOOST_CHECK(x != ev.byte_);
# endif
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_FIXED
	BOOST_CHECK(x != ev.fixed);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_HALF_FLOAT
	BOOST_CHECK(x != ev.half_float);
# endif
# ifdef GL_INT
	BOOST_CHECK(x != ev.int_);
# endif
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
	BOOST_CHECK(x == ev.unsigned_short);
#endif
}

BOOST_AUTO_TEST_CASE(enum_data_type_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	data_type x;
	(void)x;

#ifdef GL_BYTE
	x = ev.byte_;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"BYTE"
	) == 0);
#endif

#ifdef GL_DOUBLE
	x = ev.double_;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DOUBLE"
	) == 0);
#endif

#ifdef GL_FIXED
	x = ev.fixed;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FIXED"
	) == 0);
#endif

#ifdef GL_FLOAT
	x = ev.float_;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FLOAT"
	) == 0);
#endif

#ifdef GL_HALF_FLOAT
	x = ev.half_float;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"HALF_FLOAT"
	) == 0);
#endif

#ifdef GL_INT
	x = ev.int_;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"INT"
	) == 0);
#endif

#ifdef GL_SHORT
	x = ev.short_;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SHORT"
	) == 0);
#endif

#ifdef GL_UNSIGNED_BYTE
	x = ev.unsigned_byte;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNSIGNED_BYTE"
	) == 0);
#endif

#ifdef GL_UNSIGNED_INT
	x = ev.unsigned_int;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNSIGNED_INT"
	) == 0);
#endif

#ifdef GL_UNSIGNED_SHORT
	x = ev.unsigned_short;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNSIGNED_SHORT"
	) == 0);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
