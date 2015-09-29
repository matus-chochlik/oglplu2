/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_error_info
#include <boost/test/unit_test.hpp>

#include <oglplus/gl.hpp>
#include <oglplus/error/info.hpp>
#include <cstring>

BOOST_AUTO_TEST_SUITE(error_info)

BOOST_AUTO_TEST_CASE(error_info_1)
{
	using namespace oglplus;
	using std::strcmp;

	oglplus::error_info ei1(GL_NO_ERROR);
	BOOST_CHECK(ei1.gl_error_code() == GL_NO_ERROR);

	ei1.gl_error_code(GL_OUT_OF_MEMORY);
	BOOST_CHECK(ei1.gl_error_code() == GL_OUT_OF_MEMORY);

	ei1.gl_library_name("GL");
	BOOST_CHECK((
		(ei1.gl_library_name() == nullptr) ||
		(strcmp(ei1.gl_library_name(), "GL") == 0)
	));

	ei1.gl_function_name("Function");
	BOOST_CHECK((
		(ei1.gl_function_name() == nullptr) ||
		(strcmp(ei1.gl_function_name(), "Function") == 0)
	));

	ei1.source_func("function");
	BOOST_CHECK((
		(ei1.source_func() == nullptr) ||
		(strcmp(ei1.source_func(), "function") == 0)
	));

	ei1.source_file("file.cpp");
	BOOST_CHECK((
		(ei1.source_file() == nullptr) ||
		(strcmp(ei1.source_file(), "file.cpp") == 0)
	));

	ei1.source_line(12345);
	BOOST_CHECK((
		(ei1.source_line() == 0) ||
		(ei1.source_line() ==  12345)
	));

	ei1.gl_object_name(23456);
	BOOST_CHECK((
		(ei1.gl_object_name() == ei1.invalid_gl_obj_name()) ||
		(ei1.gl_object_name(), 23456)
	));

	ei1.gl_subject_name(34567);
	BOOST_CHECK((
		(ei1.gl_subject_name() == ei1.invalid_gl_obj_name()) ||
		(ei1.gl_subject_name(), 34567)
	));
}

BOOST_AUTO_TEST_CASE(error_info_2)
{
	using namespace oglplus;
	oglplus::error_info ei1;

	ei1
		.gl_library_name("GL")
		.gl_function_name("Function")
		.source_func("function")
		.source_file("file.cpp")
		.source_line(12345)
		.gl_object_name(23456)
		.gl_subject_name(34567)
		.gl_error_code(GL_OUT_OF_MEMORY);

	oglplus::error_info ei2(ei1);

	BOOST_CHECK(ei2.gl_error_code() == GL_OUT_OF_MEMORY);

	BOOST_CHECK((
		(ei2.gl_library_name() == nullptr) ||
		(strcmp(ei2.gl_library_name(), "GL") == 0)
	));

	BOOST_CHECK((
		(ei2.gl_function_name() == nullptr) ||
		(strcmp(ei2.gl_function_name(), "Function") == 0)
	));

	BOOST_CHECK((
		(ei2.source_func() == nullptr) ||
		(strcmp(ei2.source_func(), "function") == 0)
	));

	BOOST_CHECK((
		(ei2.source_file() == nullptr) ||
		(strcmp(ei2.source_file(), "file.cpp") == 0)
	));

	BOOST_CHECK((
		(ei2.source_line() == 0) ||
		(ei2.source_line() ==  12345)
	));

	BOOST_CHECK((
		(ei2.gl_object_name() == ei2.invalid_gl_obj_name()) ||
		(ei2.gl_object_name(), 23456)
	));

	BOOST_CHECK((
		(ei2.gl_subject_name() == ei2.invalid_gl_obj_name()) ||
		(ei2.gl_subject_name(), 34567)
	));
}

BOOST_AUTO_TEST_SUITE_END()
