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
#include "helper/mock_object.hpp"
#include <sstream>

BOOST_AUTO_TEST_SUITE(error_format)

oglplus::error_info
get_error_info(void)
{
	using namespace oglplus;
	return std::move(
		oglplus::error_info()
			.gl_library_name("GL")
			.gl_function_name("Function")
			.source_function("function")
			.source_file("file.cpp")
			.source_line(12345)
			.gl_object(mock_object_name(23456))
			.gl_subject(mock_object_name(34567))
			.gl_error_code(GL_OUT_OF_MEMORY)
	);
}

BOOST_AUTO_TEST_CASE(error_format_empty)
{
	using namespace oglplus;

	std::stringstream out;

	format_error_info(get_error_info(), "", out);
	BOOST_CHECK(out.str().empty());
}

BOOST_AUTO_TEST_CASE(error_format_percent)
{
	using namespace oglplus;

	std::stringstream out;

	format_error_info(get_error_info(), "%%", out);
	BOOST_CHECK(out.str() == "%");
	out.str(std::string());

	format_error_info(get_error_info(), "  %%", out);
	BOOST_CHECK(out.str() == "  %");
	out.str(std::string());

	format_error_info(get_error_info(), "%%  ", out);
	BOOST_CHECK(out.str() == "%  ");
	out.str(std::string());

	format_error_info(get_error_info(), "  %%  %% ", out);
	BOOST_CHECK(out.str() == "  %  % ");
	out.str(std::string());
}

BOOST_AUTO_TEST_CASE(error_format_fail)
{
	using namespace oglplus;

	std::stringstream out;

	int passed = 0;

	try { format_error_info(get_error_info(), "%", out); }
	catch(std::runtime_error&) { ++passed; }
	out.str(std::string());

	try { format_error_info(get_error_info(), "%  ", out); }
	catch(std::runtime_error&) { ++passed; }
	out.str(std::string());

	try { format_error_info(get_error_info(), "  %", out); }
	catch(std::runtime_error&) { ++passed; }
	out.str(std::string());

	try { format_error_info(get_error_info(), "%()", out); }
	catch(std::runtime_error&) { ++passed; }
	out.str(std::string());

	try { format_error_info(get_error_info(), "%(|)", out); }
	catch(std::runtime_error&) { ++passed; }
	out.str(std::string());

	try { format_error_info(get_error_info(), "%(|blah)", out); }
	catch(std::runtime_error&) { ++passed; }
	out.str(std::string());

	try { format_error_info(get_error_info(), "%(", out); }
	catch(std::runtime_error&) { ++passed; }
	out.str(std::string());

	try { format_error_info(get_error_info(), "%(invalid)", out); }
	catch(std::runtime_error&) { ++passed; }
	out.str(std::string());

	try { format_error_info(get_error_info(), "%(invalid|)", out); }
	catch(std::runtime_error&) { ++passed; }
	out.str(std::string());

	try { format_error_info(get_error_info(), "%(invalid|blah)", out); }
	catch(std::runtime_error&) { ++passed; }
	out.str(std::string());

	BOOST_CHECK_EQUAL(passed, 10);
}

BOOST_AUTO_TEST_CASE(error_format_gl_library_name)
{
	using namespace oglplus;

	std::stringstream out;

	format_error_info(get_error_info(), "%(gl_library_name)", "N/A", out);
	BOOST_CHECK(out.str() == "GL" || out.str() == "N/A");
	out.str(std::string());

	format_error_info(error_info(), "%(gl_library_name|fallback)", out);
	BOOST_CHECK(out.str() == "fallback");
	out.str(std::string());

	format_error_info(error_info(), "%(gl_library_name|)", out);
	BOOST_CHECK(out.str().empty());
	out.str(std::string());
}

BOOST_AUTO_TEST_CASE(error_format_gl_function_name)
{
	using namespace oglplus;

	std::stringstream out;

	format_error_info(get_error_info(), "%(gl_function_name)", "N/A", out);
	BOOST_CHECK(out.str() == "Function" || out.str() == "N/A");
	out.str(std::string());

	format_error_info(error_info(), "%(gl_function_name|fallback)", out);
	BOOST_CHECK(out.str() == "fallback");
	out.str(std::string());

	format_error_info(error_info(), "%(gl_function_name|)", out);
	BOOST_CHECK(out.str().empty());
	out.str(std::string());
}

BOOST_AUTO_TEST_CASE(error_format_source_function)
{
	using namespace oglplus;

	std::stringstream out;

	format_error_info(get_error_info(), "%(source_function)", "N/A", out);
	BOOST_CHECK(out.str() == "function" || out.str() == "N/A");
	out.str(std::string());

	format_error_info(error_info(), "%(source_function|fallback)", out);
	BOOST_CHECK(out.str() == "fallback");
	out.str(std::string());

	format_error_info(error_info(), "%(source_function|)", out);
	BOOST_CHECK(out.str().empty());
	out.str(std::string());
}

BOOST_AUTO_TEST_CASE(error_format_source_file)
{
	using namespace oglplus;

	std::stringstream out;

	format_error_info(get_error_info(), "%(source_file)", "N/A", out);
	BOOST_CHECK(out.str() == "file.cpp" || out.str() == "N/A");
	out.str(std::string());

	format_error_info(error_info(), "%(source_file|fallback)", out);
	BOOST_CHECK(out.str() == "fallback");
	out.str(std::string());

	format_error_info(error_info(), "%(source_file|)", out);
	BOOST_CHECK(out.str().empty());
	out.str(std::string());
}

BOOST_AUTO_TEST_CASE(error_format_source_line)
{
	using namespace oglplus;

	std::stringstream out;

	format_error_info(get_error_info(), "%(source_line)", "N/A", out);
	BOOST_CHECK(out.str() == "12345" || out.str() == "N/A");
	out.str(std::string());

	format_error_info(error_info(), "%(source_line|fallback)", out);
	BOOST_CHECK(out.str() == "fallback");
	out.str(std::string());

	format_error_info(error_info(), "%(source_line|)", out);
	BOOST_CHECK(out.str().empty());
	out.str(std::string());
}

BOOST_AUTO_TEST_CASE(error_format_gl_object_name)
{
	using namespace oglplus;

	std::stringstream out;

	format_error_info(get_error_info(), "%(gl_object)", "N/A", out);
	BOOST_CHECK(out.str() == "23456" || out.str() == "N/A");
	out.str(std::string());

	format_error_info(error_info(), "%(gl_object|fallback)", out);
	BOOST_CHECK(out.str() == "fallback");
	out.str(std::string());

	format_error_info(error_info(), "%(gl_object|)", "", out);
	BOOST_CHECK(out.str().empty());
	out.str(std::string());
}

BOOST_AUTO_TEST_CASE(error_format_fallback)
{
	using namespace oglplus;

	std::stringstream out;

	format_error_info(error_info(), "%(gl_object)", "N/A", out);
	BOOST_CHECK(out.str() == "N/A");
	out.str(std::string());
}

BOOST_AUTO_TEST_CASE(error_format_combine_1)
{
	using namespace oglplus;

	std::stringstream out;

	format_error_info(get_error_info(), "%(gl_library_name|)%(gl_function_name|)", "", out);
	BOOST_CHECK(out.str() == "GLFunction" || out.str().empty());
	out.str(std::string());

	format_error_info(error_info(), "%(gl_library_name|gl)%(gl_function_name|Func)", "", out);
	BOOST_CHECK(out.str() == "glFunc" || out.str().empty());
	out.str(std::string());
}

BOOST_AUTO_TEST_SUITE_END()
