/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/gl_fixed.hpp>
#include <oglplus/glsl/string_ref.hpp>
#define BOOST_TEST_MODULE OGLPLUS_glsl_string_ref
#include "../unit_test_begin.inl"

#include <cstring>

BOOST_AUTO_TEST_SUITE(glsl_string_ref_tests)

BOOST_AUTO_TEST_CASE(glsl_string_ref_1)
{
	using namespace oglplus;

	const char* s =
		"#version 150\n"\
		"vec4 in Position;\n"\
		"void main(void)\n"\
		"{\n"\
		"	gl_Position = Position;\n"\
		"}\n";

	span_size_t l = span_size(std::strlen(s));

	glsl_string_ref lr{s, l};
	glsl_source_ref sr = lr;

	BOOST_CHECK(sr.count() == 1);

	BOOST_ASSERT(sr.parts() != nullptr);
	BOOST_CHECK(std::strcmp(
		*sr.parts(),
		"#version 150\n"\
		"vec4 in Position;\n"\
		"void main(void)\n"\
		"{\n"\
		"	gl_Position = Position;\n"\
		"}\n"
	) == 0);

	BOOST_ASSERT(sr.lengths() != nullptr);
}

BOOST_AUTO_TEST_CASE(glsl_literal_1)
{
	using namespace oglplus;

	glsl_literal l(
		"#version 150\n"\
		"vec4 in Position;\n"\
		"void main(void)\n"\
		"{\n"\
		"	gl_Position = Position;\n"\
		"}\n"
	);

	glsl_source_ref sr = l;

	BOOST_CHECK(sr.count() == 1);

	BOOST_ASSERT(sr.parts() != nullptr);
	BOOST_CHECK(std::strcmp(
		*sr.parts(),
		"#version 150\n"\
		"vec4 in Position;\n"\
		"void main(void)\n"\
		"{\n"\
		"	gl_Position = Position;\n"\
		"}\n"
	) == 0);

	BOOST_ASSERT(sr.lengths() != nullptr);
}

BOOST_AUTO_TEST_SUITE_END()
