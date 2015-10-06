//  File test/oglplus/enums/compare_function.cpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt
//
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_compare_function

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_compare_function)

BOOST_AUTO_TEST_CASE(enum_compare_function_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	compare_function x;
	(void)x;

#ifdef GL_ALWAYS
	x = ev.always;
	BOOST_CHECK(x == ev.always);
# ifdef GL_EQUAL
	BOOST_CHECK(x != ev.equal);
# endif
# ifdef GL_GEQUAL
	BOOST_CHECK(x != ev.gequal);
# endif
# ifdef GL_GREATER
	BOOST_CHECK(x != ev.greater);
# endif
# ifdef GL_LEQUAL
	BOOST_CHECK(x != ev.lequal);
# endif
# ifdef GL_LESS
	BOOST_CHECK(x != ev.less);
# endif
# ifdef GL_NEVER
	BOOST_CHECK(x != ev.never);
# endif
# ifdef GL_NOTEQUAL
	BOOST_CHECK(x != ev.notequal);
# endif
#endif

#ifdef GL_EQUAL
	x = ev.equal;
# ifdef GL_ALWAYS
	BOOST_CHECK(x != ev.always);
# endif
	BOOST_CHECK(x == ev.equal);
# ifdef GL_GEQUAL
	BOOST_CHECK(x != ev.gequal);
# endif
# ifdef GL_GREATER
	BOOST_CHECK(x != ev.greater);
# endif
# ifdef GL_LEQUAL
	BOOST_CHECK(x != ev.lequal);
# endif
# ifdef GL_LESS
	BOOST_CHECK(x != ev.less);
# endif
# ifdef GL_NEVER
	BOOST_CHECK(x != ev.never);
# endif
# ifdef GL_NOTEQUAL
	BOOST_CHECK(x != ev.notequal);
# endif
#endif

#ifdef GL_GEQUAL
	x = ev.gequal;
# ifdef GL_ALWAYS
	BOOST_CHECK(x != ev.always);
# endif
# ifdef GL_EQUAL
	BOOST_CHECK(x != ev.equal);
# endif
	BOOST_CHECK(x == ev.gequal);
# ifdef GL_GREATER
	BOOST_CHECK(x != ev.greater);
# endif
# ifdef GL_LEQUAL
	BOOST_CHECK(x != ev.lequal);
# endif
# ifdef GL_LESS
	BOOST_CHECK(x != ev.less);
# endif
# ifdef GL_NEVER
	BOOST_CHECK(x != ev.never);
# endif
# ifdef GL_NOTEQUAL
	BOOST_CHECK(x != ev.notequal);
# endif
#endif

#ifdef GL_GREATER
	x = ev.greater;
# ifdef GL_ALWAYS
	BOOST_CHECK(x != ev.always);
# endif
# ifdef GL_EQUAL
	BOOST_CHECK(x != ev.equal);
# endif
# ifdef GL_GEQUAL
	BOOST_CHECK(x != ev.gequal);
# endif
	BOOST_CHECK(x == ev.greater);
# ifdef GL_LEQUAL
	BOOST_CHECK(x != ev.lequal);
# endif
# ifdef GL_LESS
	BOOST_CHECK(x != ev.less);
# endif
# ifdef GL_NEVER
	BOOST_CHECK(x != ev.never);
# endif
# ifdef GL_NOTEQUAL
	BOOST_CHECK(x != ev.notequal);
# endif
#endif

#ifdef GL_LEQUAL
	x = ev.lequal;
# ifdef GL_ALWAYS
	BOOST_CHECK(x != ev.always);
# endif
# ifdef GL_EQUAL
	BOOST_CHECK(x != ev.equal);
# endif
# ifdef GL_GEQUAL
	BOOST_CHECK(x != ev.gequal);
# endif
# ifdef GL_GREATER
	BOOST_CHECK(x != ev.greater);
# endif
	BOOST_CHECK(x == ev.lequal);
# ifdef GL_LESS
	BOOST_CHECK(x != ev.less);
# endif
# ifdef GL_NEVER
	BOOST_CHECK(x != ev.never);
# endif
# ifdef GL_NOTEQUAL
	BOOST_CHECK(x != ev.notequal);
# endif
#endif

#ifdef GL_LESS
	x = ev.less;
# ifdef GL_ALWAYS
	BOOST_CHECK(x != ev.always);
# endif
# ifdef GL_EQUAL
	BOOST_CHECK(x != ev.equal);
# endif
# ifdef GL_GEQUAL
	BOOST_CHECK(x != ev.gequal);
# endif
# ifdef GL_GREATER
	BOOST_CHECK(x != ev.greater);
# endif
# ifdef GL_LEQUAL
	BOOST_CHECK(x != ev.lequal);
# endif
	BOOST_CHECK(x == ev.less);
# ifdef GL_NEVER
	BOOST_CHECK(x != ev.never);
# endif
# ifdef GL_NOTEQUAL
	BOOST_CHECK(x != ev.notequal);
# endif
#endif

#ifdef GL_NEVER
	x = ev.never;
# ifdef GL_ALWAYS
	BOOST_CHECK(x != ev.always);
# endif
# ifdef GL_EQUAL
	BOOST_CHECK(x != ev.equal);
# endif
# ifdef GL_GEQUAL
	BOOST_CHECK(x != ev.gequal);
# endif
# ifdef GL_GREATER
	BOOST_CHECK(x != ev.greater);
# endif
# ifdef GL_LEQUAL
	BOOST_CHECK(x != ev.lequal);
# endif
# ifdef GL_LESS
	BOOST_CHECK(x != ev.less);
# endif
	BOOST_CHECK(x == ev.never);
# ifdef GL_NOTEQUAL
	BOOST_CHECK(x != ev.notequal);
# endif
#endif

#ifdef GL_NOTEQUAL
	x = ev.notequal;
# ifdef GL_ALWAYS
	BOOST_CHECK(x != ev.always);
# endif
# ifdef GL_EQUAL
	BOOST_CHECK(x != ev.equal);
# endif
# ifdef GL_GEQUAL
	BOOST_CHECK(x != ev.gequal);
# endif
# ifdef GL_GREATER
	BOOST_CHECK(x != ev.greater);
# endif
# ifdef GL_LEQUAL
	BOOST_CHECK(x != ev.lequal);
# endif
# ifdef GL_LESS
	BOOST_CHECK(x != ev.less);
# endif
# ifdef GL_NEVER
	BOOST_CHECK(x != ev.never);
# endif
	BOOST_CHECK(x == ev.notequal);
#endif
}

BOOST_AUTO_TEST_CASE(enum_compare_function_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	compare_function x;
	(void)x;

#ifdef GL_ALWAYS
	x = ev.always;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ALWAYS"
	) == 0);
#endif

#ifdef GL_EQUAL
	x = ev.equal;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"EQUAL"
	) == 0);
#endif

#ifdef GL_GEQUAL
	x = ev.gequal;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"GEQUAL"
	) == 0);
#endif

#ifdef GL_GREATER
	x = ev.greater;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"GREATER"
	) == 0);
#endif

#ifdef GL_LEQUAL
	x = ev.lequal;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LEQUAL"
	) == 0);
#endif

#ifdef GL_LESS
	x = ev.less;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LESS"
	) == 0);
#endif

#ifdef GL_NEVER
	x = ev.never;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NEVER"
	) == 0);
#endif

#ifdef GL_NOTEQUAL
	x = ev.notequal;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NOTEQUAL"
	) == 0);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
