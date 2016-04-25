//  File test/oglplus/enums/pixel_data_type.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_pixel_data_type

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_pixel_data_type_tests)

BOOST_AUTO_TEST_CASE(enum_pixel_data_type_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	pixel_data_type x;
	(void)x;

#ifdef GL_BYTE
	x = ev.byte_;
	BOOST_CHECK(x == ev.byte_);
# ifdef GL_DOUBLE
	BOOST_CHECK(x != ev.double_);
# endif
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	BOOST_CHECK(x != ev.float_32_unsigned_int_24_8_rev);
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
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_DOUBLE
	x = ev.double_;
	BOOST_CHECK(x == ev.double_);
# ifdef GL_FLOAT
	BOOST_CHECK(x != ev.float_);
# endif
# ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	BOOST_CHECK(x != ev.float_32_unsigned_int_24_8_rev);
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
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_FLOAT
	x = ev.float_;
	BOOST_CHECK(x == ev.float_);
# ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	BOOST_CHECK(x != ev.float_32_unsigned_int_24_8_rev);
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
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	x = ev.float_32_unsigned_int_24_8_rev;
	BOOST_CHECK(x == ev.float_32_unsigned_int_24_8_rev);
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
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_HALF_FLOAT
	x = ev.half_float;
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
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_INT
	x = ev.int_;
	BOOST_CHECK(x == ev.int_);
# ifdef GL_SHORT
	BOOST_CHECK(x != ev.short_);
# endif
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_SHORT
	x = ev.short_;
	BOOST_CHECK(x == ev.short_);
# ifdef GL_UNSIGNED_BYTE
	BOOST_CHECK(x != ev.unsigned_byte);
# endif
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_BYTE
	x = ev.unsigned_byte;
	BOOST_CHECK(x == ev.unsigned_byte);
# ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	BOOST_CHECK(x != ev.unsigned_byte_2_3_3_rev);
# endif
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	x = ev.unsigned_byte_2_3_3_rev;
	BOOST_CHECK(x == ev.unsigned_byte_2_3_3_rev);
# ifdef GL_UNSIGNED_BYTE_3_3_2
	BOOST_CHECK(x != ev.unsigned_byte_3_3_2);
# endif
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_BYTE_3_3_2
	x = ev.unsigned_byte_3_3_2;
	BOOST_CHECK(x == ev.unsigned_byte_3_3_2);
# ifdef GL_UNSIGNED_INT
	BOOST_CHECK(x != ev.unsigned_int);
# endif
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_INT
	x = ev.unsigned_int;
	BOOST_CHECK(x == ev.unsigned_int);
# ifdef GL_UNSIGNED_INT_10_10_10_2
	BOOST_CHECK(x != ev.unsigned_int_10_10_10_2);
# endif
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_INT_10_10_10_2
	x = ev.unsigned_int_10_10_10_2;
	BOOST_CHECK(x == ev.unsigned_int_10_10_10_2);
# ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	BOOST_CHECK(x != ev.unsigned_int_10f_11f_11f_rev);
# endif
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	x = ev.unsigned_int_10f_11f_11f_rev;
	BOOST_CHECK(x == ev.unsigned_int_10f_11f_11f_rev);
# ifdef GL_UNSIGNED_INT_24_8
	BOOST_CHECK(x != ev.unsigned_int_24_8);
# endif
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_INT_24_8
	x = ev.unsigned_int_24_8;
	BOOST_CHECK(x == ev.unsigned_int_24_8);
# ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	BOOST_CHECK(x != ev.unsigned_int_2_10_10_10_rev);
# endif
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	x = ev.unsigned_int_2_10_10_10_rev;
	BOOST_CHECK(x == ev.unsigned_int_2_10_10_10_rev);
# ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	BOOST_CHECK(x != ev.unsigned_int_5_9_9_9_rev);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	x = ev.unsigned_int_5_9_9_9_rev;
	BOOST_CHECK(x == ev.unsigned_int_5_9_9_9_rev);
# ifdef GL_UNSIGNED_INT_8_8_8_8
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8);
# endif
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_INT_8_8_8_8
	x = ev.unsigned_int_8_8_8_8;
	BOOST_CHECK(x == ev.unsigned_int_8_8_8_8);
# ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	BOOST_CHECK(x != ev.unsigned_int_8_8_8_8_rev);
# endif
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	x = ev.unsigned_int_8_8_8_8_rev;
	BOOST_CHECK(x == ev.unsigned_int_8_8_8_8_rev);
# ifdef GL_UNSIGNED_SHORT
	BOOST_CHECK(x != ev.unsigned_short);
# endif
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_SHORT
	x = ev.unsigned_short;
	BOOST_CHECK(x == ev.unsigned_short);
# ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	BOOST_CHECK(x != ev.unsigned_short_1_5_5_5_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	x = ev.unsigned_short_1_5_5_5_rev;
	BOOST_CHECK(x == ev.unsigned_short_1_5_5_5_rev);
# ifdef GL_UNSIGNED_SHORT_4_4_4_4
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4);
# endif
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_SHORT_4_4_4_4
	x = ev.unsigned_short_4_4_4_4;
	BOOST_CHECK(x == ev.unsigned_short_4_4_4_4);
# ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	BOOST_CHECK(x != ev.unsigned_short_4_4_4_4_rev);
# endif
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	x = ev.unsigned_short_4_4_4_4_rev;
	BOOST_CHECK(x == ev.unsigned_short_4_4_4_4_rev);
# ifdef GL_UNSIGNED_SHORT_5_5_5_1
	BOOST_CHECK(x != ev.unsigned_short_5_5_5_1);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_SHORT_5_5_5_1
	x = ev.unsigned_short_5_5_5_1;
	BOOST_CHECK(x == ev.unsigned_short_5_5_5_1);
# ifdef GL_UNSIGNED_SHORT_5_6_5
	BOOST_CHECK(x != ev.unsigned_short_5_6_5);
# endif
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_SHORT_5_6_5
	x = ev.unsigned_short_5_6_5;
	BOOST_CHECK(x == ev.unsigned_short_5_6_5);
# ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	BOOST_CHECK(x != ev.unsigned_short_5_6_5_rev);
# endif
#endif

#ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	x = ev.unsigned_short_5_6_5_rev;
	BOOST_CHECK(x == ev.unsigned_short_5_6_5_rev);
#endif
}

BOOST_AUTO_TEST_CASE(enum_pixel_data_type_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	pixel_data_type x;
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

#ifdef GL_FLOAT
	x = ev.float_;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FLOAT"
	) == 0);
#endif

#ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	x = ev.float_32_unsigned_int_24_8_rev;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"FLOAT_32_UNSIGNED_INT_24_8_REV"
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

#ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	x = ev.unsigned_byte_2_3_3_rev;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNSIGNED_BYTE_2_3_3_REV"
	) == 0);
#endif

#ifdef GL_UNSIGNED_BYTE_3_3_2
	x = ev.unsigned_byte_3_3_2;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNSIGNED_BYTE_3_3_2"
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

#ifdef GL_UNSIGNED_INT_10_10_10_2
	x = ev.unsigned_int_10_10_10_2;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNSIGNED_INT_10_10_10_2"
	) == 0);
#endif

#ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	x = ev.unsigned_int_10f_11f_11f_rev;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNSIGNED_INT_10F_11F_11F_REV"
	) == 0);
#endif

#ifdef GL_UNSIGNED_INT_24_8
	x = ev.unsigned_int_24_8;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNSIGNED_INT_24_8"
	) == 0);
#endif

#ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	x = ev.unsigned_int_2_10_10_10_rev;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNSIGNED_INT_2_10_10_10_REV"
	) == 0);
#endif

#ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	x = ev.unsigned_int_5_9_9_9_rev;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNSIGNED_INT_5_9_9_9_REV"
	) == 0);
#endif

#ifdef GL_UNSIGNED_INT_8_8_8_8
	x = ev.unsigned_int_8_8_8_8;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNSIGNED_INT_8_8_8_8"
	) == 0);
#endif

#ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	x = ev.unsigned_int_8_8_8_8_rev;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNSIGNED_INT_8_8_8_8_REV"
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

#ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	x = ev.unsigned_short_1_5_5_5_rev;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNSIGNED_SHORT_1_5_5_5_REV"
	) == 0);
#endif

#ifdef GL_UNSIGNED_SHORT_4_4_4_4
	x = ev.unsigned_short_4_4_4_4;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNSIGNED_SHORT_4_4_4_4"
	) == 0);
#endif

#ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	x = ev.unsigned_short_4_4_4_4_rev;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNSIGNED_SHORT_4_4_4_4_REV"
	) == 0);
#endif

#ifdef GL_UNSIGNED_SHORT_5_5_5_1
	x = ev.unsigned_short_5_5_5_1;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNSIGNED_SHORT_5_5_5_1"
	) == 0);
#endif

#ifdef GL_UNSIGNED_SHORT_5_6_5
	x = ev.unsigned_short_5_6_5;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNSIGNED_SHORT_5_6_5"
	) == 0);
#endif

#ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	x = ev.unsigned_short_5_6_5_rev;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNSIGNED_SHORT_5_6_5_REV"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_pixel_data_type_range)
{
	using namespace oglplus;
	auto count = enum_value_range<pixel_data_type>().size();

#ifdef GL_BYTE
{
	--count;
	auto r = enum_value_range<pixel_data_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_type(GL_BYTE)
	) != r.end());
}
#endif

#ifdef GL_DOUBLE
{
	--count;
	auto r = enum_value_range<pixel_data_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_type(GL_DOUBLE)
	) != r.end());
}
#endif

#ifdef GL_FLOAT
{
	--count;
	auto r = enum_value_range<pixel_data_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_type(GL_FLOAT)
	) != r.end());
}
#endif

#ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
{
	--count;
	auto r = enum_value_range<pixel_data_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_type(GL_FLOAT_32_UNSIGNED_INT_24_8_REV)
	) != r.end());
}
#endif

#ifdef GL_HALF_FLOAT
{
	--count;
	auto r = enum_value_range<pixel_data_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_type(GL_HALF_FLOAT)
	) != r.end());
}
#endif

#ifdef GL_INT
{
	--count;
	auto r = enum_value_range<pixel_data_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_type(GL_INT)
	) != r.end());
}
#endif

#ifdef GL_SHORT
{
	--count;
	auto r = enum_value_range<pixel_data_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_type(GL_SHORT)
	) != r.end());
}
#endif

#ifdef GL_UNSIGNED_BYTE
{
	--count;
	auto r = enum_value_range<pixel_data_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_type(GL_UNSIGNED_BYTE)
	) != r.end());
}
#endif

#ifdef GL_UNSIGNED_BYTE_2_3_3_REV
{
	--count;
	auto r = enum_value_range<pixel_data_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_type(GL_UNSIGNED_BYTE_2_3_3_REV)
	) != r.end());
}
#endif

#ifdef GL_UNSIGNED_BYTE_3_3_2
{
	--count;
	auto r = enum_value_range<pixel_data_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_type(GL_UNSIGNED_BYTE_3_3_2)
	) != r.end());
}
#endif

#ifdef GL_UNSIGNED_INT
{
	--count;
	auto r = enum_value_range<pixel_data_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_type(GL_UNSIGNED_INT)
	) != r.end());
}
#endif

#ifdef GL_UNSIGNED_INT_10_10_10_2
{
	--count;
	auto r = enum_value_range<pixel_data_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_type(GL_UNSIGNED_INT_10_10_10_2)
	) != r.end());
}
#endif

#ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
{
	--count;
	auto r = enum_value_range<pixel_data_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_type(GL_UNSIGNED_INT_10F_11F_11F_REV)
	) != r.end());
}
#endif

#ifdef GL_UNSIGNED_INT_24_8
{
	--count;
	auto r = enum_value_range<pixel_data_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_type(GL_UNSIGNED_INT_24_8)
	) != r.end());
}
#endif

#ifdef GL_UNSIGNED_INT_2_10_10_10_REV
{
	--count;
	auto r = enum_value_range<pixel_data_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_type(GL_UNSIGNED_INT_2_10_10_10_REV)
	) != r.end());
}
#endif

#ifdef GL_UNSIGNED_INT_5_9_9_9_REV
{
	--count;
	auto r = enum_value_range<pixel_data_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_type(GL_UNSIGNED_INT_5_9_9_9_REV)
	) != r.end());
}
#endif

#ifdef GL_UNSIGNED_INT_8_8_8_8
{
	--count;
	auto r = enum_value_range<pixel_data_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_type(GL_UNSIGNED_INT_8_8_8_8)
	) != r.end());
}
#endif

#ifdef GL_UNSIGNED_INT_8_8_8_8_REV
{
	--count;
	auto r = enum_value_range<pixel_data_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_type(GL_UNSIGNED_INT_8_8_8_8_REV)
	) != r.end());
}
#endif

#ifdef GL_UNSIGNED_SHORT
{
	--count;
	auto r = enum_value_range<pixel_data_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_type(GL_UNSIGNED_SHORT)
	) != r.end());
}
#endif

#ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
{
	--count;
	auto r = enum_value_range<pixel_data_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_type(GL_UNSIGNED_SHORT_1_5_5_5_REV)
	) != r.end());
}
#endif

#ifdef GL_UNSIGNED_SHORT_4_4_4_4
{
	--count;
	auto r = enum_value_range<pixel_data_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_type(GL_UNSIGNED_SHORT_4_4_4_4)
	) != r.end());
}
#endif

#ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
{
	--count;
	auto r = enum_value_range<pixel_data_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_type(GL_UNSIGNED_SHORT_4_4_4_4_REV)
	) != r.end());
}
#endif

#ifdef GL_UNSIGNED_SHORT_5_5_5_1
{
	--count;
	auto r = enum_value_range<pixel_data_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_type(GL_UNSIGNED_SHORT_5_5_5_1)
	) != r.end());
}
#endif

#ifdef GL_UNSIGNED_SHORT_5_6_5
{
	--count;
	auto r = enum_value_range<pixel_data_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_type(GL_UNSIGNED_SHORT_5_6_5)
	) != r.end());
}
#endif

#ifdef GL_UNSIGNED_SHORT_5_6_5_REV
{
	--count;
	auto r = enum_value_range<pixel_data_type>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_data_type(GL_UNSIGNED_SHORT_5_6_5_REV)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_pixel_data_type_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	pixel_data_type x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_BYTE
	x = ev.byte_;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.byte_);
#endif

#ifdef GL_DOUBLE
	x = ev.double_;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.double_);
#endif

#ifdef GL_FLOAT
	x = ev.float_;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.float_);
#endif

#ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	x = ev.float_32_unsigned_int_24_8_rev;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.float_32_unsigned_int_24_8_rev);
#endif

#ifdef GL_HALF_FLOAT
	x = ev.half_float;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.half_float);
#endif

#ifdef GL_INT
	x = ev.int_;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.int_);
#endif

#ifdef GL_SHORT
	x = ev.short_;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.short_);
#endif

#ifdef GL_UNSIGNED_BYTE
	x = ev.unsigned_byte;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unsigned_byte);
#endif

#ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	x = ev.unsigned_byte_2_3_3_rev;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unsigned_byte_2_3_3_rev);
#endif

#ifdef GL_UNSIGNED_BYTE_3_3_2
	x = ev.unsigned_byte_3_3_2;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unsigned_byte_3_3_2);
#endif

#ifdef GL_UNSIGNED_INT
	x = ev.unsigned_int;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unsigned_int);
#endif

#ifdef GL_UNSIGNED_INT_10_10_10_2
	x = ev.unsigned_int_10_10_10_2;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unsigned_int_10_10_10_2);
#endif

#ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	x = ev.unsigned_int_10f_11f_11f_rev;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unsigned_int_10f_11f_11f_rev);
#endif

#ifdef GL_UNSIGNED_INT_24_8
	x = ev.unsigned_int_24_8;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unsigned_int_24_8);
#endif

#ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	x = ev.unsigned_int_2_10_10_10_rev;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unsigned_int_2_10_10_10_rev);
#endif

#ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	x = ev.unsigned_int_5_9_9_9_rev;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unsigned_int_5_9_9_9_rev);
#endif

#ifdef GL_UNSIGNED_INT_8_8_8_8
	x = ev.unsigned_int_8_8_8_8;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unsigned_int_8_8_8_8);
#endif

#ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	x = ev.unsigned_int_8_8_8_8_rev;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unsigned_int_8_8_8_8_rev);
#endif

#ifdef GL_UNSIGNED_SHORT
	x = ev.unsigned_short;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unsigned_short);
#endif

#ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	x = ev.unsigned_short_1_5_5_5_rev;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unsigned_short_1_5_5_5_rev);
#endif

#ifdef GL_UNSIGNED_SHORT_4_4_4_4
	x = ev.unsigned_short_4_4_4_4;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unsigned_short_4_4_4_4);
#endif

#ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	x = ev.unsigned_short_4_4_4_4_rev;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unsigned_short_4_4_4_4_rev);
#endif

#ifdef GL_UNSIGNED_SHORT_5_5_5_1
	x = ev.unsigned_short_5_5_5_1;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unsigned_short_5_5_5_1);
#endif

#ifdef GL_UNSIGNED_SHORT_5_6_5
	x = ev.unsigned_short_5_6_5;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unsigned_short_5_6_5);
#endif

#ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	x = ev.unsigned_short_5_6_5_rev;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unsigned_short_5_6_5_rev);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
