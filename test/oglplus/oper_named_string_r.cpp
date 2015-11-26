/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_oper_named_string
#include <boost/test/unit_test.hpp>

#include <oglplus/gl.hpp>
#include "helper/mock_gl_func.hpp"

OGLPLUS_MOCK_GLFUNC(
	NamedStringARB,
	void(GLenum,GLint,const GLchar*,GLint,const GLchar*)
);

OGLPLUS_MOCK_GLFUNC(
	DeleteNamedStringARB,
	void(GLint,const GLchar*)
);

OGLPLUS_MOCK_GLFUNC(
	IsNamedStringARB,
	GLboolean(GLint,const GLchar*)
);

OGLPLUS_MOCK_GLFUNC(
	GetNamedStringARB,
	void(GLint,const GLchar*,GLsizei,GLint*,GLchar*)
);

OGLPLUS_MOCK_GLFUNC(
	GetNamedStringivARB,
	void(GLint,const GLchar*,GLenum,oglplus::mock_ptr<GLint>)
);

#include <oglplus/oper/named_string.hpp>
#include <oglplus/enum/values.hpp>
#include <cstring>
#include <cstdlib>

BOOST_AUTO_TEST_SUITE(named_string)

#if defined(GL_ARB_shading_language_include)

BOOST_AUTO_TEST_CASE(named_string_ops)
{
	using namespace oglplus;

	oper::named_string_state gl;
	oglplus::enum_values GL;
	named_string_type type = GL.shader_include;

	{
		auto test_glNamedStringARB = make_aoe_test(
			mock_glNamedStringARB,
			GLenum(type), 4, "key", 6, "value"
		);
		gl.named_string(type, "key", "value");
		BOOST_CHECK(test_glNamedStringARB);
	}
	{
		auto test_glDeleteNamedStringARB = make_aoe_test(
			mock_glDeleteNamedStringARB,
			9, "some_key"
		);
		gl.delete_named_string("some_key");
		BOOST_CHECK(test_glDeleteNamedStringARB);
	}
	{
		auto test_glIsNamedStringARB = make_aoe_test(
			mock_glIsNamedStringARB,
			GLboolean(GL_TRUE), 6, "a_key"
		);
		gl.is_named_string("a_key");
		BOOST_CHECK(test_glIsNamedStringARB);
	}
	{
		auto test_glGetNamedStringivARB = make_aoe_test(
			mock_glGetNamedStringivARB,
			6, "a_key", GLenum(GL_NAMED_STRING_LENGTH_ARB), mock_ptr<GLint>()
		);
		gl.named_string_length("a_key");
		BOOST_CHECK(test_glGetNamedStringivARB);
	}
	{
		auto test_glGetNamedStringivARB = make_aoe_test(
			mock_glGetNamedStringivARB,
			6, "a_key", GLenum(GL_NAMED_STRING_TYPE_ARB), mock_ptr<GLint>()
		);
		gl.named_string_type("a_key");
		BOOST_CHECK(test_glGetNamedStringivARB);
	}

	BOOST_CHECK(mock_glNamedStringARB.was_called());
	BOOST_CHECK(mock_glDeleteNamedStringARB.was_called());
	BOOST_CHECK(mock_glIsNamedStringARB.was_called());
}

#else
BOOST_AUTO_TEST_CASE(named_string_dummy) { }
#endif

BOOST_AUTO_TEST_SUITE_END()
