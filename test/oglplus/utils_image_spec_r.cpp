/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_utils_image_spec
#include <boost/test/unit_test.hpp>

#include <oglplus/gl.hpp>
#include <oglplus/utils/image_spec.hpp>
#include <oglplus/utils/make_view.hpp>
#include <cstring>

BOOST_AUTO_TEST_SUITE(utils_image_spec)

BOOST_AUTO_TEST_CASE(utils_image_spec_1)
{
	using namespace oglplus;

	GLfloat x[64];

	image_spec is({64},{pixel_data_format(GL_RED)},make_view(x));

	BOOST_CHECK_EQUAL(is.width(), 64);
	BOOST_CHECK_EQUAL(is.height(), 1);
	BOOST_CHECK_EQUAL(is.depth(), 1);

	BOOST_CHECK(is.format() == GL_RED);
	BOOST_CHECK(is.internal_format() == GL_RED);
	BOOST_CHECK(is.type() == GL_FLOAT);

	BOOST_CHECK(is.data() != nullptr);
}

BOOST_AUTO_TEST_CASE(utils_image_spec_2)
{
	using namespace oglplus;

	GLint x[32*64*2];

	image_spec is({32,64},{pixel_data_format(GL_RG)},make_view(x));

	BOOST_CHECK_EQUAL(is.width(), 32);
	BOOST_CHECK_EQUAL(is.height(), 64);
	BOOST_CHECK_EQUAL(is.depth(), 1);

	BOOST_CHECK(is.format() == GL_RG);
	BOOST_CHECK(is.internal_format() == GL_RG);
	BOOST_CHECK(is.type() == GL_INT);

	BOOST_CHECK(is.data() != nullptr);
}

BOOST_AUTO_TEST_CASE(utils_image_spec_3)
{
	using namespace oglplus;

	GLubyte x[16*32*64*3];

	image_spec is({16,32,64},{pixel_data_format(GL_RGB)},make_view(x));

	BOOST_CHECK_EQUAL(is.width(), 16);
	BOOST_CHECK_EQUAL(is.height(), 32);
	BOOST_CHECK_EQUAL(is.depth(), 64);

	BOOST_CHECK(is.format() == GL_RGB);
	BOOST_CHECK(is.internal_format() == GL_RGB);
	BOOST_CHECK(is.type() == GL_UNSIGNED_BYTE);

	BOOST_CHECK(is.data() != nullptr);
}

BOOST_AUTO_TEST_CASE(utils_image_spec_4)
{
	using namespace oglplus;

	GLuint x[64*64*64*4];

	image_spec is({64,64,64},{pixel_data_format(GL_RGBA)},make_view(x));

	BOOST_CHECK_EQUAL(is.width(), 64);
	BOOST_CHECK_EQUAL(is.height(), 64);
	BOOST_CHECK_EQUAL(is.depth(), 64);

	BOOST_CHECK(is.format() == GL_RGBA);
	BOOST_CHECK(is.internal_format() == GL_RGBA);
	BOOST_CHECK(is.type() == GL_UNSIGNED_INT);

	BOOST_CHECK(is.data() != nullptr);
}

// TODO

BOOST_AUTO_TEST_SUITE_END()
