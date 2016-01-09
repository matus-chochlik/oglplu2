//  File test/oalplus/enums/alc_error_code.cpp
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
#define BOOST_TEST_MODULE OALPLUS_alc_error_code

#include <boost/test/unit_test.hpp>
#include "common_alc.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_alc_error_code_tests)

BOOST_AUTO_TEST_CASE(enum_alc_error_code_values)
{
	using namespace oalplus;
	enum_values_alc ev;
	(void)ev;
	alc_error_code x;
	(void)x;

#ifdef ALC_INVALID_CONTEXT
	x = ev.invalid_context;
	BOOST_CHECK(x == ev.invalid_context);
# ifdef ALC_INVALID_DEVICE
	BOOST_CHECK(x != ev.invalid_device);
# endif
# ifdef ALC_INVALID_ENUM
	BOOST_CHECK(x != ev.invalid_enum);
# endif
# ifdef ALC_INVALID_VALUE
	BOOST_CHECK(x != ev.invalid_value);
# endif
# ifdef ALC_NO_ERROR
	BOOST_CHECK(x != ev.no_error);
# endif
# ifdef ALC_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.out_of_memory);
# endif
#endif

#ifdef ALC_INVALID_DEVICE
	x = ev.invalid_device;
	BOOST_CHECK(x == ev.invalid_device);
# ifdef ALC_INVALID_ENUM
	BOOST_CHECK(x != ev.invalid_enum);
# endif
# ifdef ALC_INVALID_VALUE
	BOOST_CHECK(x != ev.invalid_value);
# endif
# ifdef ALC_NO_ERROR
	BOOST_CHECK(x != ev.no_error);
# endif
# ifdef ALC_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.out_of_memory);
# endif
#endif

#ifdef ALC_INVALID_ENUM
	x = ev.invalid_enum;
	BOOST_CHECK(x == ev.invalid_enum);
# ifdef ALC_INVALID_VALUE
	BOOST_CHECK(x != ev.invalid_value);
# endif
# ifdef ALC_NO_ERROR
	BOOST_CHECK(x != ev.no_error);
# endif
# ifdef ALC_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.out_of_memory);
# endif
#endif

#ifdef ALC_INVALID_VALUE
	x = ev.invalid_value;
	BOOST_CHECK(x == ev.invalid_value);
# ifdef ALC_NO_ERROR
	BOOST_CHECK(x != ev.no_error);
# endif
# ifdef ALC_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.out_of_memory);
# endif
#endif

#ifdef ALC_NO_ERROR
	x = ev.no_error;
	BOOST_CHECK(x == ev.no_error);
# ifdef ALC_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.out_of_memory);
# endif
#endif

#ifdef ALC_OUT_OF_MEMORY
	x = ev.out_of_memory;
	BOOST_CHECK(x == ev.out_of_memory);
#endif
}

BOOST_AUTO_TEST_CASE(enum_alc_error_code_names)
{
	using namespace oalplus;
	enum_values_alc ev;
	(void)ev;
	alc_error_code x;
	(void)x;

#ifdef ALC_INVALID_CONTEXT
	x = ev.invalid_context;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"INVALID_CONTEXT"
	) == 0);
#endif

#ifdef ALC_INVALID_DEVICE
	x = ev.invalid_device;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"INVALID_DEVICE"
	) == 0);
#endif

#ifdef ALC_INVALID_ENUM
	x = ev.invalid_enum;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"INVALID_ENUM"
	) == 0);
#endif

#ifdef ALC_INVALID_VALUE
	x = ev.invalid_value;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"INVALID_VALUE"
	) == 0);
#endif

#ifdef ALC_NO_ERROR
	x = ev.no_error;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NO_ERROR"
	) == 0);
#endif

#ifdef ALC_OUT_OF_MEMORY
	x = ev.out_of_memory;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"OUT_OF_MEMORY"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_alc_error_code_range)
{
	using namespace oalplus;
	auto count = enum_value_range<alc_error_code>().size();

#ifdef ALC_INVALID_CONTEXT
{
	--count;
	auto r = enum_value_range<alc_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		alc_error_code(ALC_INVALID_CONTEXT)
	) != r.end());
}
#endif

#ifdef ALC_INVALID_DEVICE
{
	--count;
	auto r = enum_value_range<alc_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		alc_error_code(ALC_INVALID_DEVICE)
	) != r.end());
}
#endif

#ifdef ALC_INVALID_ENUM
{
	--count;
	auto r = enum_value_range<alc_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		alc_error_code(ALC_INVALID_ENUM)
	) != r.end());
}
#endif

#ifdef ALC_INVALID_VALUE
{
	--count;
	auto r = enum_value_range<alc_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		alc_error_code(ALC_INVALID_VALUE)
	) != r.end());
}
#endif

#ifdef ALC_NO_ERROR
{
	--count;
	auto r = enum_value_range<alc_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		alc_error_code(ALC_NO_ERROR)
	) != r.end());
}
#endif

#ifdef ALC_OUT_OF_MEMORY
{
	--count;
	auto r = enum_value_range<alc_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		alc_error_code(ALC_OUT_OF_MEMORY)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_alc_error_code_any)
{
	using namespace oalplus;
	enum_values_alc ev;
	(void)ev;
	alc_error_code x, y;
	(void)x;
	(void)y;
	any_enum_value_alc a;
	(void)a;

#ifdef ALC_INVALID_CONTEXT
	x = ev.invalid_context;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.invalid_context);
#endif

#ifdef ALC_INVALID_DEVICE
	x = ev.invalid_device;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.invalid_device);
#endif

#ifdef ALC_INVALID_ENUM
	x = ev.invalid_enum;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.invalid_enum);
#endif

#ifdef ALC_INVALID_VALUE
	x = ev.invalid_value;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.invalid_value);
#endif

#ifdef ALC_NO_ERROR
	x = ev.no_error;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.no_error);
#endif

#ifdef ALC_OUT_OF_MEMORY
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
