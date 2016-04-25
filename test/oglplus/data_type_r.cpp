/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_data_type
#include <boost/test/unit_test.hpp>

#include <oglplus/gl_fixed.hpp>
#include <oglplus/data_type.hpp>
#include <oglplus/enum/values.hpp>
#include <oglplus/enum/value_defs.inl>
#include <cstring>

BOOST_AUTO_TEST_SUITE(data_type_tests)

BOOST_AUTO_TEST_CASE(data_type_1)
{
	using namespace oglplus;

	static const enum_values GL = {};

	BOOST_CHECK(
		get_data_type(identity<GLbyte>()) ==
		GL.byte_
	);

	BOOST_CHECK(
		get_data_type(identity<GLubyte>()) ==
		GL.unsigned_byte
	);

	BOOST_CHECK(
		get_data_type(identity<GLshort>()) ==
		GL.short_
	);

	BOOST_CHECK(
		get_data_type(identity<GLushort>()) ==
		GL.unsigned_short
	);

	BOOST_CHECK(
		get_data_type(identity<GLint>()) ==
		GL.int_
	);

	BOOST_CHECK(
		get_data_type(identity<GLuint>()) ==
		GL.unsigned_int
	);

	BOOST_CHECK(
		get_data_type(identity<GLfloat>()) ==
		GL.float_
	);

#ifdef GL_DOUBLE
	BOOST_CHECK(
		get_data_type(identity<GLdouble>()) ==
		GL.double_
	);
#endif
}

BOOST_AUTO_TEST_CASE(data_type_2)
{
	using namespace oglplus;

	static const enum_values GL = {};

	BOOST_CHECK(
		get_data_type<GLbyte>() ==
		GL.byte_
	);

	BOOST_CHECK(
		get_data_type<GLubyte>() ==
		GL.unsigned_byte
	);

	BOOST_CHECK(
		get_data_type<GLshort>() ==
		GL.short_
	);

	BOOST_CHECK(
		get_data_type<GLushort>() ==
		GL.unsigned_short
	);

	BOOST_CHECK(
		get_data_type<GLint>() ==
		GL.int_
	);

	BOOST_CHECK(
		get_data_type<GLuint>() ==
		GL.unsigned_int
	);

	BOOST_CHECK(
		get_data_type<GLfloat>() ==
		GL.float_
	);

#ifdef GL_DOUBLE
	BOOST_CHECK(
		get_data_type<GLdouble>() ==
		GL.double_
	);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
