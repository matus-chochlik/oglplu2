/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_glsl_source_ref
#include <boost/test/unit_test.hpp>

#include <oglplus/gl.hpp>
#include <oglplus/glsl/source_ref.hpp>
#include <cstring>

BOOST_AUTO_TEST_SUITE(glsl_source_ref)

BOOST_AUTO_TEST_CASE(glsl_source_ref_1)
{
	using namespace oglplus;

	const char* s = "#version 150\n";
	GLint l = GLint(std::strlen(s));

	oglplus::glsl_source_ref sr{1, &s, &l};

	BOOST_CHECK(sr.count() == 1);

	BOOST_ASSERT(sr.parts() != nullptr);
	BOOST_CHECK(std::strcmp(*sr.parts(), s) == 0);

	BOOST_ASSERT(sr.lengths() != nullptr);
	BOOST_CHECK(*sr.lengths() == l);
}

BOOST_AUTO_TEST_CASE(glsl_source_ref_2)
{
	using namespace oglplus;

	const std::size_t n = 6;
	const char* s[n] = {
		"#version 150\n",
		"vec4 in Position;\n",
		"void main(void)\n",
		"{\n",
		"	gl_Position = Position;\n",
		"}\n"
	};
	GLint l[n];
	for(std::size_t i=0; i<n; ++i)
	{
		l[i] = GLint(std::strlen(s[i]));
	}

	oglplus::glsl_source_ref sr{n, s, l};

	BOOST_CHECK(sr.count() == n);
	BOOST_ASSERT(sr.parts() != nullptr);
	BOOST_ASSERT(sr.lengths() != nullptr);

	for(std::size_t i=0; i<n; ++i)
	{
		BOOST_CHECK(std::strcmp(sr.parts()[i], s[i]) == 0);
		BOOST_CHECK(sr.lengths()[i] == l[i]);
		BOOST_CHECK(std::strlen(sr.parts()[i]) == std::size_t(l[i]));
	}
}

BOOST_AUTO_TEST_SUITE_END()
