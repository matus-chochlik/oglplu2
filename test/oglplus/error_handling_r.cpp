/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_error_handling
#include <boost/test/unit_test.hpp>

#include <oglplus/gl_fixed.hpp>
#include <oglplus/error/handling.hpp>
#include "helper/mock_object.hpp"

BOOST_AUTO_TEST_SUITE(error_handling_tests)

BOOST_AUTO_TEST_CASE(error_handling_1)
{
	using namespace oglplus;

	int passed = 0;

	try
	{
		handle_gl_error(
			error_info()
				.gl_library_name("GL")
				.gl_function_name("Function")
				.source_function("function")
				.source_file("file.cpp")
				.source_line(12345)
				.gl_object(mock_object_name(23456))
				.gl_subject(mock_object_name(34567))
				.gl_error_code(GL_OUT_OF_MEMORY)
		);
		BOOST_CHECK_MESSAGE(
			false,
			"Should not get past handle_gl_error"
		);
	}
	catch(oglplus::error& e)
	{
		BOOST_CHECK(e.info().gl_error_code() == GL_OUT_OF_MEMORY);

		BOOST_CHECK((
			(e.info().gl_library_name() == nullptr) ||
			(strcmp(e.info().gl_library_name(), "GL") == 0)
		));

		BOOST_CHECK((
			(e.info().gl_function_name() == nullptr) ||
			(strcmp(e.info().gl_function_name(), "Function") == 0)
		));

		BOOST_CHECK((
			(e.info().source_function() == nullptr) ||
			(strcmp(e.info().source_function(), "function") == 0)
		));

		BOOST_CHECK((
			(e.info().source_file() == nullptr) ||
			(strcmp(e.info().source_file(), "file.cpp") == 0)
		));

		BOOST_CHECK((
			(e.info().source_line() == 0) ||
			(e.info().source_line() ==  12345)
		));

		BOOST_CHECK((
			(e.info().gl_object() == mock_object_name()) ||
			(e.info().gl_object(), mock_object_name(23456))
		));

		BOOST_CHECK((
			(e.info().gl_subject() == mock_object_name()) ||
			(e.info().gl_subject(), mock_object_name(34567))
		));
		++passed;
	}
	BOOST_CHECK_EQUAL(passed,1);
}

BOOST_AUTO_TEST_CASE(error_handling_2)
{
	using namespace oglplus;

	int passed = 0;

	try
	{
		{
			auto dh = deferred_error_handler(std::move(
				error_info()
					.gl_library_name("GLX")
					.gl_function_name("Func")
					.source_function("func")
					.source_file("file.hpp")
					.source_line(54321)
					.gl_object(mock_object_name(65432))
					.gl_subject(mock_object_name(76543))
					.gl_error_code(GL_INVALID_OPERATION)
			));
			++passed;
		}
		BOOST_CHECK_MESSAGE(
			false,
			"Should not get past handle_gl_error"
		);
	}
	catch(oglplus::error& e)
	{
		BOOST_CHECK(e.info().gl_error_code() == GL_INVALID_OPERATION);

		BOOST_CHECK((
			(e.info().gl_library_name() == nullptr) ||
			(strcmp(e.info().gl_library_name(), "GLX") == 0)
		));

		BOOST_CHECK((
			(e.info().gl_function_name() == nullptr) ||
			(strcmp(e.info().gl_function_name(), "Func") == 0)
		));

		BOOST_CHECK((
			(e.info().source_function() == nullptr) ||
			(strcmp(e.info().source_function(), "func") == 0)
		));

		BOOST_CHECK((
			(e.info().source_file() == nullptr) ||
			(strcmp(e.info().source_file(), "file.hpp") == 0)
		));

		BOOST_CHECK((
			(e.info().source_line() == 0) ||
			(e.info().source_line() ==  54321)
		));

		BOOST_CHECK((
			(e.info().gl_object() == mock_object_name()) ||
			(e.info().gl_object(), mock_object_name(65432))
		));

		BOOST_CHECK((
			(e.info().gl_subject() == mock_object_name()) ||
			(e.info().gl_subject(), mock_object_name(76543))
		));
		++passed;
	}
	BOOST_CHECK_EQUAL(passed,2);
}

BOOST_AUTO_TEST_CASE(error_handling_3)
{
	using namespace oglplus;

	int passed = 0;

	try
	{
		auto fn = [](void) -> deferred_error_handler
		{
			return deferred_error_handler(std::move(
				error_info()
					.gl_library_name("WGL")
					.gl_function_name("FunctionW")
					.source_function("func")
					.source_file("file.h")
					.source_line(11111)
					.gl_object(mock_object_name(22222))
					.gl_subject(mock_object_name(33333))
					.gl_error_code(GL_INVALID_VALUE)
			));
		};
		++passed;
		fn();
		BOOST_CHECK_MESSAGE(
			false,
			"Should not get past handle_gl_error"
		);
	}
	catch(oglplus::error& e)
	{
		BOOST_CHECK(e.info().gl_error_code() == GL_INVALID_VALUE);

		BOOST_CHECK((
			(e.info().gl_library_name() == nullptr) ||
			(strcmp(e.info().gl_library_name(), "WGL") == 0)
		));

		BOOST_CHECK((
			(e.info().gl_function_name() == nullptr) ||
			(strcmp(e.info().gl_function_name(), "FunctionW") == 0)
		));

		BOOST_CHECK((
			(e.info().source_function() == nullptr) ||
			(strcmp(e.info().source_function(), "func") == 0)
		));

		BOOST_CHECK((
			(e.info().source_file() == nullptr) ||
			(strcmp(e.info().source_file(), "file.h") == 0)
		));

		BOOST_CHECK((
			(e.info().source_line() == 0) ||
			(e.info().source_line() ==  11111)
		));

		BOOST_CHECK((
			(e.info().gl_object() == mock_object_name()) ||
			(e.info().gl_object(), mock_object_name(22222))
		));

		BOOST_CHECK((
			(e.info().gl_subject() == mock_object_name()) ||
			(e.info().gl_subject(), mock_object_name(33333))
		));
		++passed;
	}
	BOOST_CHECK_EQUAL(passed,2);
}

BOOST_AUTO_TEST_SUITE_END()
