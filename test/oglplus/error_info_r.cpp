/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_error_info
#include <boost/test/unit_test.hpp>

# define OGLPLUS_ERROR_NO_GL_LIB 0
# define OGLPLUS_ERROR_NO_GL_FUNC 0
# define OGLPLUS_ERROR_NO_SRC_FILE 0
# define OGLPLUS_ERROR_NO_SRC_LINE 0
# define OGLPLUS_ERROR_NO_SRC_FUNC 0
# define OGLPLUS_ERROR_NO_OBJECT 0
# define OGLPLUS_ERROR_NO_SUBJECT 0
# define OGLPLUS_ERROR_NO_INDEX 0
# define OGLPLUS_ERROR_NO_ENUM_VALUE 0
# define OGLPLUS_ERROR_NO_INFO_LOG 0

#include <oglplus/gl_fixed.hpp>
#include <oglplus/error/info.hpp>
#include "helper/mock_object.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(error_info_tests)

BOOST_AUTO_TEST_CASE(error_info_1)
{
	using namespace oglplus;
	using std::strcmp;

	error_info ei1(GL_NO_ERROR);
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

	ei1.source_function("function");
	BOOST_CHECK((
		(ei1.source_function() == nullptr) ||
		(strcmp(ei1.source_function(), "function") == 0)
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

	ei1.gl_object(mock_object_name(23456));
	BOOST_CHECK((
		(ei1.gl_object() == mock_object_name()) ||
		(ei1.gl_object(), mock_object_name(23456))
	));

	ei1.gl_subject(mock_object_name(34567));
	BOOST_CHECK((
		(ei1.gl_subject() == mock_object_name()) ||
		(ei1.gl_subject(), mock_object_name(34567))
	));
}

BOOST_AUTO_TEST_CASE(error_info_2)
{
	using namespace oglplus;
	error_info ei1;

	ei1
		.gl_library_name("GL")
		.gl_function_name("Function")
		.source_function("function")
		.source_file("file.cpp")
		.source_line(12345)
		.gl_object(mock_object_name(23456))
		.gl_subject(mock_object_name(34567))
		.gl_error_code(GL_OUT_OF_MEMORY);

	error_info ei2(std::move(ei1));

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
		(ei2.source_function() == nullptr) ||
		(strcmp(ei2.source_function(), "function") == 0)
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
		(ei2.gl_object() == mock_object_name()) ||
		(ei2.gl_object(), mock_object_name(23456))
	));

	BOOST_CHECK((
		(ei2.gl_subject() == mock_object_name()) ||
		(ei2.gl_subject(), mock_object_name(34567))
	));
}

BOOST_AUTO_TEST_SUITE_END()
