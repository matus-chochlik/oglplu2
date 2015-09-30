//  File test/oglplus/enums/stencil_operation.cpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_stencil_operation

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_stencil_operation)

BOOST_AUTO_TEST_CASE(enum_stencil_operation_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	stencil_operation x;
	(void)x;

#ifdef GL_DECR
	x = ev.decr;
	BOOST_CHECK(x == ev.decr);
# ifdef GL_DECR_WRAP
	BOOST_CHECK(x != ev.decr_wrap);
# endif
# ifdef GL_INCR
	BOOST_CHECK(x != ev.incr);
# endif
# ifdef GL_INCR_WRAP
	BOOST_CHECK(x != ev.incr_wrap);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_KEEP
	BOOST_CHECK(x != ev.keep);
# endif
# ifdef GL_REPLACE
	BOOST_CHECK(x != ev.replace);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_DECR_WRAP
	x = ev.decr_wrap;
# ifdef GL_DECR
	BOOST_CHECK(x != ev.decr);
# endif
	BOOST_CHECK(x == ev.decr_wrap);
# ifdef GL_INCR
	BOOST_CHECK(x != ev.incr);
# endif
# ifdef GL_INCR_WRAP
	BOOST_CHECK(x != ev.incr_wrap);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_KEEP
	BOOST_CHECK(x != ev.keep);
# endif
# ifdef GL_REPLACE
	BOOST_CHECK(x != ev.replace);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_INCR
	x = ev.incr;
# ifdef GL_DECR
	BOOST_CHECK(x != ev.decr);
# endif
# ifdef GL_DECR_WRAP
	BOOST_CHECK(x != ev.decr_wrap);
# endif
	BOOST_CHECK(x == ev.incr);
# ifdef GL_INCR_WRAP
	BOOST_CHECK(x != ev.incr_wrap);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_KEEP
	BOOST_CHECK(x != ev.keep);
# endif
# ifdef GL_REPLACE
	BOOST_CHECK(x != ev.replace);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_INCR_WRAP
	x = ev.incr_wrap;
# ifdef GL_DECR
	BOOST_CHECK(x != ev.decr);
# endif
# ifdef GL_DECR_WRAP
	BOOST_CHECK(x != ev.decr_wrap);
# endif
# ifdef GL_INCR
	BOOST_CHECK(x != ev.incr);
# endif
	BOOST_CHECK(x == ev.incr_wrap);
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_KEEP
	BOOST_CHECK(x != ev.keep);
# endif
# ifdef GL_REPLACE
	BOOST_CHECK(x != ev.replace);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_INVERT
	x = ev.invert;
# ifdef GL_DECR
	BOOST_CHECK(x != ev.decr);
# endif
# ifdef GL_DECR_WRAP
	BOOST_CHECK(x != ev.decr_wrap);
# endif
# ifdef GL_INCR
	BOOST_CHECK(x != ev.incr);
# endif
# ifdef GL_INCR_WRAP
	BOOST_CHECK(x != ev.incr_wrap);
# endif
	BOOST_CHECK(x == ev.invert);
# ifdef GL_KEEP
	BOOST_CHECK(x != ev.keep);
# endif
# ifdef GL_REPLACE
	BOOST_CHECK(x != ev.replace);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_KEEP
	x = ev.keep;
# ifdef GL_DECR
	BOOST_CHECK(x != ev.decr);
# endif
# ifdef GL_DECR_WRAP
	BOOST_CHECK(x != ev.decr_wrap);
# endif
# ifdef GL_INCR
	BOOST_CHECK(x != ev.incr);
# endif
# ifdef GL_INCR_WRAP
	BOOST_CHECK(x != ev.incr_wrap);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
	BOOST_CHECK(x == ev.keep);
# ifdef GL_REPLACE
	BOOST_CHECK(x != ev.replace);
# endif
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_REPLACE
	x = ev.replace;
# ifdef GL_DECR
	BOOST_CHECK(x != ev.decr);
# endif
# ifdef GL_DECR_WRAP
	BOOST_CHECK(x != ev.decr_wrap);
# endif
# ifdef GL_INCR
	BOOST_CHECK(x != ev.incr);
# endif
# ifdef GL_INCR_WRAP
	BOOST_CHECK(x != ev.incr_wrap);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_KEEP
	BOOST_CHECK(x != ev.keep);
# endif
	BOOST_CHECK(x == ev.replace);
# ifdef GL_ZERO
	BOOST_CHECK(x != ev.zero);
# endif
#endif

#ifdef GL_ZERO
	x = ev.zero;
# ifdef GL_DECR
	BOOST_CHECK(x != ev.decr);
# endif
# ifdef GL_DECR_WRAP
	BOOST_CHECK(x != ev.decr_wrap);
# endif
# ifdef GL_INCR
	BOOST_CHECK(x != ev.incr);
# endif
# ifdef GL_INCR_WRAP
	BOOST_CHECK(x != ev.incr_wrap);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_KEEP
	BOOST_CHECK(x != ev.keep);
# endif
# ifdef GL_REPLACE
	BOOST_CHECK(x != ev.replace);
# endif
	BOOST_CHECK(x == ev.zero);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
