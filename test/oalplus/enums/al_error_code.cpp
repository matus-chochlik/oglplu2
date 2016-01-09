//  File test/oalplus/enums/al_error_code.cpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oalplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt
//
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OALPLUS_al_error_code

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_al_error_code_tests)

BOOST_AUTO_TEST_CASE(enum_al_error_code_values)
{
	using namespace oalplus;
	enum_values ev;
	(void)ev;
	al_error_code x;
	(void)x;

#ifdef AL_INVALID_ENUM
	x = ev.invalid_enum;
	BOOST_CHECK(x == ev.invalid_enum);
# ifdef AL_INVALID_NAME
	BOOST_CHECK(x != ev.invalid_name);
# endif
# ifdef AL_INVALID_OPERATION
	BOOST_CHECK(x != ev.invalid_operation);
# endif
# ifdef AL_INVALID_VALUE
	BOOST_CHECK(x != ev.invalid_value);
# endif
# ifdef AL_NO_ERROR
	BOOST_CHECK(x != ev.no_error);
# endif
# ifdef AL_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.out_of_memory);
# endif
#endif

#ifdef AL_INVALID_NAME
	x = ev.invalid_name;
	BOOST_CHECK(x == ev.invalid_name);
# ifdef AL_INVALID_OPERATION
	BOOST_CHECK(x != ev.invalid_operation);
# endif
# ifdef AL_INVALID_VALUE
	BOOST_CHECK(x != ev.invalid_value);
# endif
# ifdef AL_NO_ERROR
	BOOST_CHECK(x != ev.no_error);
# endif
# ifdef AL_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.out_of_memory);
# endif
#endif

#ifdef AL_INVALID_OPERATION
	x = ev.invalid_operation;
	BOOST_CHECK(x == ev.invalid_operation);
# ifdef AL_INVALID_VALUE
	BOOST_CHECK(x != ev.invalid_value);
# endif
# ifdef AL_NO_ERROR
	BOOST_CHECK(x != ev.no_error);
# endif
# ifdef AL_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.out_of_memory);
# endif
#endif

#ifdef AL_INVALID_VALUE
	x = ev.invalid_value;
	BOOST_CHECK(x == ev.invalid_value);
# ifdef AL_NO_ERROR
	BOOST_CHECK(x != ev.no_error);
# endif
# ifdef AL_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.out_of_memory);
# endif
#endif

#ifdef AL_NO_ERROR
	x = ev.no_error;
	BOOST_CHECK(x == ev.no_error);
# ifdef AL_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.out_of_memory);
# endif
#endif

#ifdef AL_OUT_OF_MEMORY
	x = ev.out_of_memory;
	BOOST_CHECK(x == ev.out_of_memory);
#endif
}

BOOST_AUTO_TEST_CASE(enum_al_error_code_names)
{
	using namespace oalplus;
	enum_values ev;
	(void)ev;
	al_error_code x;
	(void)x;

#ifdef AL_INVALID_ENUM
	x = ev.invalid_enum;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"INVALID_ENUM"
	) == 0);
#endif

#ifdef AL_INVALID_NAME
	x = ev.invalid_name;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"INVALID_NAME"
	) == 0);
#endif

#ifdef AL_INVALID_OPERATION
	x = ev.invalid_operation;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"INVALID_OPERATION"
	) == 0);
#endif

#ifdef AL_INVALID_VALUE
	x = ev.invalid_value;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"INVALID_VALUE"
	) == 0);
#endif

#ifdef AL_NO_ERROR
	x = ev.no_error;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NO_ERROR"
	) == 0);
#endif

#ifdef AL_OUT_OF_MEMORY
	x = ev.out_of_memory;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"OUT_OF_MEMORY"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_al_error_code_range)
{
	using namespace oalplus;
	auto count = enum_value_range<al_error_code>().size();

#ifdef AL_INVALID_ENUM
{
	--count;
	auto r = enum_value_range<al_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		al_error_code(AL_INVALID_ENUM)
	) != r.end());
}
#endif

#ifdef AL_INVALID_NAME
{
	--count;
	auto r = enum_value_range<al_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		al_error_code(AL_INVALID_NAME)
	) != r.end());
}
#endif

#ifdef AL_INVALID_OPERATION
{
	--count;
	auto r = enum_value_range<al_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		al_error_code(AL_INVALID_OPERATION)
	) != r.end());
}
#endif

#ifdef AL_INVALID_VALUE
{
	--count;
	auto r = enum_value_range<al_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		al_error_code(AL_INVALID_VALUE)
	) != r.end());
}
#endif

#ifdef AL_NO_ERROR
{
	--count;
	auto r = enum_value_range<al_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		al_error_code(AL_NO_ERROR)
	) != r.end());
}
#endif

#ifdef AL_OUT_OF_MEMORY
{
	--count;
	auto r = enum_value_range<al_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		al_error_code(AL_OUT_OF_MEMORY)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_al_error_code_any)
{
	using namespace oalplus;
	enum_values ev;
	(void)ev;
	al_error_code x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef AL_INVALID_ENUM
	x = ev.invalid_enum;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.invalid_enum);
#endif

#ifdef AL_INVALID_NAME
	x = ev.invalid_name;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.invalid_name);
#endif

#ifdef AL_INVALID_OPERATION
	x = ev.invalid_operation;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.invalid_operation);
#endif

#ifdef AL_INVALID_VALUE
	x = ev.invalid_value;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.invalid_value);
#endif

#ifdef AL_NO_ERROR
	x = ev.no_error;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.no_error);
#endif

#ifdef AL_OUT_OF_MEMORY
	x = ev.out_of_memory;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.out_of_memory);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
