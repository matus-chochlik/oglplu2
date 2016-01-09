//  File test/oglplus/enums/program_parameter.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_program_parameter

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_program_parameter_tests)

BOOST_AUTO_TEST_CASE(enum_program_parameter_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	program_parameter x;
	(void)x;

#ifdef GL_ACTIVE_ATTRIBUTE_MAX_LENGTH
	x = ev.active_attribute_max_length;
	BOOST_CHECK(x == ev.active_attribute_max_length);
# ifdef GL_ACTIVE_ATTRIBUTES
	BOOST_CHECK(x != ev.active_attributes);
# endif
# ifdef GL_ACTIVE_UNIFORM_MAX_LENGTH
	BOOST_CHECK(x != ev.active_uniform_max_length);
# endif
# ifdef GL_ACTIVE_UNIFORMS
	BOOST_CHECK(x != ev.active_uniforms);
# endif
# ifdef GL_ATTACHED_SHADERS
	BOOST_CHECK(x != ev.attached_shaders);
# endif
# ifdef GL_DELETE_STATUS
	BOOST_CHECK(x != ev.delete_status);
# endif
# ifdef GL_INFO_LOG_LENGTH
	BOOST_CHECK(x != ev.info_log_length);
# endif
# ifdef GL_LINK_STATUS
	BOOST_CHECK(x != ev.link_status);
# endif
# ifdef GL_VALIDATE_STATUS
	BOOST_CHECK(x != ev.validate_status);
# endif
#endif

#ifdef GL_ACTIVE_ATTRIBUTES
	x = ev.active_attributes;
	BOOST_CHECK(x == ev.active_attributes);
# ifdef GL_ACTIVE_UNIFORM_MAX_LENGTH
	BOOST_CHECK(x != ev.active_uniform_max_length);
# endif
# ifdef GL_ACTIVE_UNIFORMS
	BOOST_CHECK(x != ev.active_uniforms);
# endif
# ifdef GL_ATTACHED_SHADERS
	BOOST_CHECK(x != ev.attached_shaders);
# endif
# ifdef GL_DELETE_STATUS
	BOOST_CHECK(x != ev.delete_status);
# endif
# ifdef GL_INFO_LOG_LENGTH
	BOOST_CHECK(x != ev.info_log_length);
# endif
# ifdef GL_LINK_STATUS
	BOOST_CHECK(x != ev.link_status);
# endif
# ifdef GL_VALIDATE_STATUS
	BOOST_CHECK(x != ev.validate_status);
# endif
#endif

#ifdef GL_ACTIVE_UNIFORM_MAX_LENGTH
	x = ev.active_uniform_max_length;
	BOOST_CHECK(x == ev.active_uniform_max_length);
# ifdef GL_ACTIVE_UNIFORMS
	BOOST_CHECK(x != ev.active_uniforms);
# endif
# ifdef GL_ATTACHED_SHADERS
	BOOST_CHECK(x != ev.attached_shaders);
# endif
# ifdef GL_DELETE_STATUS
	BOOST_CHECK(x != ev.delete_status);
# endif
# ifdef GL_INFO_LOG_LENGTH
	BOOST_CHECK(x != ev.info_log_length);
# endif
# ifdef GL_LINK_STATUS
	BOOST_CHECK(x != ev.link_status);
# endif
# ifdef GL_VALIDATE_STATUS
	BOOST_CHECK(x != ev.validate_status);
# endif
#endif

#ifdef GL_ACTIVE_UNIFORMS
	x = ev.active_uniforms;
	BOOST_CHECK(x == ev.active_uniforms);
# ifdef GL_ATTACHED_SHADERS
	BOOST_CHECK(x != ev.attached_shaders);
# endif
# ifdef GL_DELETE_STATUS
	BOOST_CHECK(x != ev.delete_status);
# endif
# ifdef GL_INFO_LOG_LENGTH
	BOOST_CHECK(x != ev.info_log_length);
# endif
# ifdef GL_LINK_STATUS
	BOOST_CHECK(x != ev.link_status);
# endif
# ifdef GL_VALIDATE_STATUS
	BOOST_CHECK(x != ev.validate_status);
# endif
#endif

#ifdef GL_ATTACHED_SHADERS
	x = ev.attached_shaders;
	BOOST_CHECK(x == ev.attached_shaders);
# ifdef GL_DELETE_STATUS
	BOOST_CHECK(x != ev.delete_status);
# endif
# ifdef GL_INFO_LOG_LENGTH
	BOOST_CHECK(x != ev.info_log_length);
# endif
# ifdef GL_LINK_STATUS
	BOOST_CHECK(x != ev.link_status);
# endif
# ifdef GL_VALIDATE_STATUS
	BOOST_CHECK(x != ev.validate_status);
# endif
#endif

#ifdef GL_DELETE_STATUS
	x = ev.delete_status;
	BOOST_CHECK(x == ev.delete_status);
# ifdef GL_INFO_LOG_LENGTH
	BOOST_CHECK(x != ev.info_log_length);
# endif
# ifdef GL_LINK_STATUS
	BOOST_CHECK(x != ev.link_status);
# endif
# ifdef GL_VALIDATE_STATUS
	BOOST_CHECK(x != ev.validate_status);
# endif
#endif

#ifdef GL_INFO_LOG_LENGTH
	x = ev.info_log_length;
	BOOST_CHECK(x == ev.info_log_length);
# ifdef GL_LINK_STATUS
	BOOST_CHECK(x != ev.link_status);
# endif
# ifdef GL_VALIDATE_STATUS
	BOOST_CHECK(x != ev.validate_status);
# endif
#endif

#ifdef GL_LINK_STATUS
	x = ev.link_status;
	BOOST_CHECK(x == ev.link_status);
# ifdef GL_VALIDATE_STATUS
	BOOST_CHECK(x != ev.validate_status);
# endif
#endif

#ifdef GL_VALIDATE_STATUS
	x = ev.validate_status;
	BOOST_CHECK(x == ev.validate_status);
#endif
}

BOOST_AUTO_TEST_CASE(enum_program_parameter_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	program_parameter x;
	(void)x;

#ifdef GL_ACTIVE_ATTRIBUTE_MAX_LENGTH
	x = ev.active_attribute_max_length;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ACTIVE_ATTRIBUTE_MAX_LENGTH"
	) == 0);
#endif

#ifdef GL_ACTIVE_ATTRIBUTES
	x = ev.active_attributes;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ACTIVE_ATTRIBUTES"
	) == 0);
#endif

#ifdef GL_ACTIVE_UNIFORM_MAX_LENGTH
	x = ev.active_uniform_max_length;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ACTIVE_UNIFORM_MAX_LENGTH"
	) == 0);
#endif

#ifdef GL_ACTIVE_UNIFORMS
	x = ev.active_uniforms;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ACTIVE_UNIFORMS"
	) == 0);
#endif

#ifdef GL_ATTACHED_SHADERS
	x = ev.attached_shaders;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ATTACHED_SHADERS"
	) == 0);
#endif

#ifdef GL_DELETE_STATUS
	x = ev.delete_status;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DELETE_STATUS"
	) == 0);
#endif

#ifdef GL_INFO_LOG_LENGTH
	x = ev.info_log_length;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"INFO_LOG_LENGTH"
	) == 0);
#endif

#ifdef GL_LINK_STATUS
	x = ev.link_status;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LINK_STATUS"
	) == 0);
#endif

#ifdef GL_VALIDATE_STATUS
	x = ev.validate_status;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"VALIDATE_STATUS"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_program_parameter_range)
{
	using namespace oglplus;
	auto count = enum_value_range<program_parameter>().size();

#ifdef GL_ACTIVE_ATTRIBUTE_MAX_LENGTH
{
	--count;
	auto r = enum_value_range<program_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_parameter(GL_ACTIVE_ATTRIBUTE_MAX_LENGTH)
	) != r.end());
}
#endif

#ifdef GL_ACTIVE_ATTRIBUTES
{
	--count;
	auto r = enum_value_range<program_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_parameter(GL_ACTIVE_ATTRIBUTES)
	) != r.end());
}
#endif

#ifdef GL_ACTIVE_UNIFORM_MAX_LENGTH
{
	--count;
	auto r = enum_value_range<program_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_parameter(GL_ACTIVE_UNIFORM_MAX_LENGTH)
	) != r.end());
}
#endif

#ifdef GL_ACTIVE_UNIFORMS
{
	--count;
	auto r = enum_value_range<program_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_parameter(GL_ACTIVE_UNIFORMS)
	) != r.end());
}
#endif

#ifdef GL_ATTACHED_SHADERS
{
	--count;
	auto r = enum_value_range<program_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_parameter(GL_ATTACHED_SHADERS)
	) != r.end());
}
#endif

#ifdef GL_DELETE_STATUS
{
	--count;
	auto r = enum_value_range<program_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_parameter(GL_DELETE_STATUS)
	) != r.end());
}
#endif

#ifdef GL_INFO_LOG_LENGTH
{
	--count;
	auto r = enum_value_range<program_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_parameter(GL_INFO_LOG_LENGTH)
	) != r.end());
}
#endif

#ifdef GL_LINK_STATUS
{
	--count;
	auto r = enum_value_range<program_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_parameter(GL_LINK_STATUS)
	) != r.end());
}
#endif

#ifdef GL_VALIDATE_STATUS
{
	--count;
	auto r = enum_value_range<program_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		program_parameter(GL_VALIDATE_STATUS)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_program_parameter_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	program_parameter x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_ACTIVE_ATTRIBUTE_MAX_LENGTH
	x = ev.active_attribute_max_length;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.active_attribute_max_length);
#endif

#ifdef GL_ACTIVE_ATTRIBUTES
	x = ev.active_attributes;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.active_attributes);
#endif

#ifdef GL_ACTIVE_UNIFORM_MAX_LENGTH
	x = ev.active_uniform_max_length;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.active_uniform_max_length);
#endif

#ifdef GL_ACTIVE_UNIFORMS
	x = ev.active_uniforms;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.active_uniforms);
#endif

#ifdef GL_ATTACHED_SHADERS
	x = ev.attached_shaders;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.attached_shaders);
#endif

#ifdef GL_DELETE_STATUS
	x = ev.delete_status;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.delete_status);
#endif

#ifdef GL_INFO_LOG_LENGTH
	x = ev.info_log_length;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.info_log_length);
#endif

#ifdef GL_LINK_STATUS
	x = ev.link_status;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.link_status);
#endif

#ifdef GL_VALIDATE_STATUS
	x = ev.validate_status;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.validate_status);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
