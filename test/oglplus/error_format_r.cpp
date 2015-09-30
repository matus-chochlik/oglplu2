/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_error_format
#include <boost/test/unit_test.hpp>

#include <oglplus/gl.hpp>
#include <oglplus/error/format.hpp>
#include <sstream>

BOOST_AUTO_TEST_SUITE(error_format)

BOOST_AUTO_TEST_CASE(error_format_1)
{
	using namespace oglplus;
	oglplus::error_info info;

	info
		.gl_library_name("GL")
		.gl_function_name("Function")
		.source_function("function")
		.source_file("file.cpp")
		.source_line(12345)
		.gl_object_name(23456)
		.gl_subject_name(34567)
		.gl_error_code(GL_OUT_OF_MEMORY);

	//std::stringstream out;
	// TODO
	(void)info;
}

BOOST_AUTO_TEST_SUITE_END()
