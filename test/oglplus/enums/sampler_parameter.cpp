//  File test/oglplus/enums/sampler_parameter.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_sampler_parameter

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_sampler_parameter_tests)

BOOST_AUTO_TEST_CASE(enum_sampler_parameter_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	sampler_parameter x;
	(void)x;

#ifdef GL_TEXTURE_BORDER_COLOR
	x = ev.texture_border_color;
	BOOST_CHECK(x == ev.texture_border_color);
# ifdef GL_TEXTURE_COMPARE_FUNC
	BOOST_CHECK(x != ev.texture_compare_func);
# endif
# ifdef GL_TEXTURE_COMPARE_MODE
	BOOST_CHECK(x != ev.texture_compare_mode);
# endif
# ifdef GL_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.texture_lod_bias);
# endif
# ifdef GL_TEXTURE_MAG_FILTER
	BOOST_CHECK(x != ev.texture_mag_filter);
# endif
# ifdef GL_TEXTURE_MAX_LOD
	BOOST_CHECK(x != ev.texture_max_lod);
# endif
# ifdef GL_TEXTURE_MIN_FILTER
	BOOST_CHECK(x != ev.texture_min_filter);
# endif
# ifdef GL_TEXTURE_MIN_LOD
	BOOST_CHECK(x != ev.texture_min_lod);
# endif
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_COMPARE_FUNC
	x = ev.texture_compare_func;
	BOOST_CHECK(x == ev.texture_compare_func);
# ifdef GL_TEXTURE_COMPARE_MODE
	BOOST_CHECK(x != ev.texture_compare_mode);
# endif
# ifdef GL_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.texture_lod_bias);
# endif
# ifdef GL_TEXTURE_MAG_FILTER
	BOOST_CHECK(x != ev.texture_mag_filter);
# endif
# ifdef GL_TEXTURE_MAX_LOD
	BOOST_CHECK(x != ev.texture_max_lod);
# endif
# ifdef GL_TEXTURE_MIN_FILTER
	BOOST_CHECK(x != ev.texture_min_filter);
# endif
# ifdef GL_TEXTURE_MIN_LOD
	BOOST_CHECK(x != ev.texture_min_lod);
# endif
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_COMPARE_MODE
	x = ev.texture_compare_mode;
	BOOST_CHECK(x == ev.texture_compare_mode);
# ifdef GL_TEXTURE_LOD_BIAS
	BOOST_CHECK(x != ev.texture_lod_bias);
# endif
# ifdef GL_TEXTURE_MAG_FILTER
	BOOST_CHECK(x != ev.texture_mag_filter);
# endif
# ifdef GL_TEXTURE_MAX_LOD
	BOOST_CHECK(x != ev.texture_max_lod);
# endif
# ifdef GL_TEXTURE_MIN_FILTER
	BOOST_CHECK(x != ev.texture_min_filter);
# endif
# ifdef GL_TEXTURE_MIN_LOD
	BOOST_CHECK(x != ev.texture_min_lod);
# endif
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_LOD_BIAS
	x = ev.texture_lod_bias;
	BOOST_CHECK(x == ev.texture_lod_bias);
# ifdef GL_TEXTURE_MAG_FILTER
	BOOST_CHECK(x != ev.texture_mag_filter);
# endif
# ifdef GL_TEXTURE_MAX_LOD
	BOOST_CHECK(x != ev.texture_max_lod);
# endif
# ifdef GL_TEXTURE_MIN_FILTER
	BOOST_CHECK(x != ev.texture_min_filter);
# endif
# ifdef GL_TEXTURE_MIN_LOD
	BOOST_CHECK(x != ev.texture_min_lod);
# endif
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_MAG_FILTER
	x = ev.texture_mag_filter;
	BOOST_CHECK(x == ev.texture_mag_filter);
# ifdef GL_TEXTURE_MAX_LOD
	BOOST_CHECK(x != ev.texture_max_lod);
# endif
# ifdef GL_TEXTURE_MIN_FILTER
	BOOST_CHECK(x != ev.texture_min_filter);
# endif
# ifdef GL_TEXTURE_MIN_LOD
	BOOST_CHECK(x != ev.texture_min_lod);
# endif
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_MAX_LOD
	x = ev.texture_max_lod;
	BOOST_CHECK(x == ev.texture_max_lod);
# ifdef GL_TEXTURE_MIN_FILTER
	BOOST_CHECK(x != ev.texture_min_filter);
# endif
# ifdef GL_TEXTURE_MIN_LOD
	BOOST_CHECK(x != ev.texture_min_lod);
# endif
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_MIN_FILTER
	x = ev.texture_min_filter;
	BOOST_CHECK(x == ev.texture_min_filter);
# ifdef GL_TEXTURE_MIN_LOD
	BOOST_CHECK(x != ev.texture_min_lod);
# endif
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_MIN_LOD
	x = ev.texture_min_lod;
	BOOST_CHECK(x == ev.texture_min_lod);
# ifdef GL_TEXTURE_WRAP_R
	BOOST_CHECK(x != ev.texture_wrap_r);
# endif
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_WRAP_R
	x = ev.texture_wrap_r;
	BOOST_CHECK(x == ev.texture_wrap_r);
# ifdef GL_TEXTURE_WRAP_S
	BOOST_CHECK(x != ev.texture_wrap_s);
# endif
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_WRAP_S
	x = ev.texture_wrap_s;
	BOOST_CHECK(x == ev.texture_wrap_s);
# ifdef GL_TEXTURE_WRAP_T
	BOOST_CHECK(x != ev.texture_wrap_t);
# endif
#endif

#ifdef GL_TEXTURE_WRAP_T
	x = ev.texture_wrap_t;
	BOOST_CHECK(x == ev.texture_wrap_t);
#endif
}

BOOST_AUTO_TEST_CASE(enum_sampler_parameter_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	sampler_parameter x;
	(void)x;

#ifdef GL_TEXTURE_BORDER_COLOR
	x = ev.texture_border_color;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_BORDER_COLOR"
	) == 0);
#endif

#ifdef GL_TEXTURE_COMPARE_FUNC
	x = ev.texture_compare_func;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_COMPARE_FUNC"
	) == 0);
#endif

#ifdef GL_TEXTURE_COMPARE_MODE
	x = ev.texture_compare_mode;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_COMPARE_MODE"
	) == 0);
#endif

#ifdef GL_TEXTURE_LOD_BIAS
	x = ev.texture_lod_bias;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_LOD_BIAS"
	) == 0);
#endif

#ifdef GL_TEXTURE_MAG_FILTER
	x = ev.texture_mag_filter;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_MAG_FILTER"
	) == 0);
#endif

#ifdef GL_TEXTURE_MAX_LOD
	x = ev.texture_max_lod;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_MAX_LOD"
	) == 0);
#endif

#ifdef GL_TEXTURE_MIN_FILTER
	x = ev.texture_min_filter;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_MIN_FILTER"
	) == 0);
#endif

#ifdef GL_TEXTURE_MIN_LOD
	x = ev.texture_min_lod;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_MIN_LOD"
	) == 0);
#endif

#ifdef GL_TEXTURE_WRAP_R
	x = ev.texture_wrap_r;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_WRAP_R"
	) == 0);
#endif

#ifdef GL_TEXTURE_WRAP_S
	x = ev.texture_wrap_s;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_WRAP_S"
	) == 0);
#endif

#ifdef GL_TEXTURE_WRAP_T
	x = ev.texture_wrap_t;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"TEXTURE_WRAP_T"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_sampler_parameter_range)
{
	using namespace oglplus;
	auto count = enum_value_range<sampler_parameter>().size();

#ifdef GL_TEXTURE_BORDER_COLOR
{
	--count;
	auto r = enum_value_range<sampler_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		sampler_parameter(GL_TEXTURE_BORDER_COLOR)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_COMPARE_FUNC
{
	--count;
	auto r = enum_value_range<sampler_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		sampler_parameter(GL_TEXTURE_COMPARE_FUNC)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_COMPARE_MODE
{
	--count;
	auto r = enum_value_range<sampler_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		sampler_parameter(GL_TEXTURE_COMPARE_MODE)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_LOD_BIAS
{
	--count;
	auto r = enum_value_range<sampler_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		sampler_parameter(GL_TEXTURE_LOD_BIAS)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_MAG_FILTER
{
	--count;
	auto r = enum_value_range<sampler_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		sampler_parameter(GL_TEXTURE_MAG_FILTER)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_MAX_LOD
{
	--count;
	auto r = enum_value_range<sampler_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		sampler_parameter(GL_TEXTURE_MAX_LOD)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_MIN_FILTER
{
	--count;
	auto r = enum_value_range<sampler_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		sampler_parameter(GL_TEXTURE_MIN_FILTER)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_MIN_LOD
{
	--count;
	auto r = enum_value_range<sampler_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		sampler_parameter(GL_TEXTURE_MIN_LOD)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_WRAP_R
{
	--count;
	auto r = enum_value_range<sampler_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		sampler_parameter(GL_TEXTURE_WRAP_R)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_WRAP_S
{
	--count;
	auto r = enum_value_range<sampler_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		sampler_parameter(GL_TEXTURE_WRAP_S)
	) != r.end());
}
#endif

#ifdef GL_TEXTURE_WRAP_T
{
	--count;
	auto r = enum_value_range<sampler_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		sampler_parameter(GL_TEXTURE_WRAP_T)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_sampler_parameter_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	sampler_parameter x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_TEXTURE_BORDER_COLOR
	x = ev.texture_border_color;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_border_color);
#endif

#ifdef GL_TEXTURE_COMPARE_FUNC
	x = ev.texture_compare_func;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_compare_func);
#endif

#ifdef GL_TEXTURE_COMPARE_MODE
	x = ev.texture_compare_mode;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_compare_mode);
#endif

#ifdef GL_TEXTURE_LOD_BIAS
	x = ev.texture_lod_bias;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_lod_bias);
#endif

#ifdef GL_TEXTURE_MAG_FILTER
	x = ev.texture_mag_filter;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_mag_filter);
#endif

#ifdef GL_TEXTURE_MAX_LOD
	x = ev.texture_max_lod;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_max_lod);
#endif

#ifdef GL_TEXTURE_MIN_FILTER
	x = ev.texture_min_filter;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_min_filter);
#endif

#ifdef GL_TEXTURE_MIN_LOD
	x = ev.texture_min_lod;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_min_lod);
#endif

#ifdef GL_TEXTURE_WRAP_R
	x = ev.texture_wrap_r;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_wrap_r);
#endif

#ifdef GL_TEXTURE_WRAP_S
	x = ev.texture_wrap_s;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_wrap_s);
#endif

#ifdef GL_TEXTURE_WRAP_T
	x = ev.texture_wrap_t;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.texture_wrap_t);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
