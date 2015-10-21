/**
 *  @file oalplus/error/info.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ERROR_INFO_1509260923_HPP
#define OALPLUS_ERROR_INFO_1509260923_HPP

#include "../config/error.hpp"
#include "../object/al_name.hpp"
#include "../utils/enum_class.hpp"

namespace oalplus {

struct extended_error_info;

class error_info
{
private:
	ALenum _al_err_code;

#if! OALPLUS_ERROR_NO_AL_LIB
	const char* _al_lb_name;
#endif

#if! OALPLUS_ERROR_NO_AL_FUNC
	const char* _al_fn_name;
#endif

#if! OALPLUS_ERROR_NO_SRC_FUNC
	const char* _src_func;
#endif

#if! OALPLUS_ERROR_NO_SRC_FILE
	const char* _src_file;
#endif

#if! OALPLUS_ERROR_NO_SRC_LINE
	unsigned _src_line;
#endif

#if !OALPLUS_ERROR_NO_OBJECT
	any_object_name _obj_name;
#endif

#if !OALPLUS_ERROR_NO_INDEX
	ALuint _index;
#endif

#if !OALPLUS_ERROR_NO_ENUM_VALUE
	any_enum_value _enum_val;
#endif
public:
	constexpr
	error_info(ALenum al_err_code)
	noexcept;

	constexpr
	error_info(void)
	noexcept
	 : error_info(ALenum(AL_NONE))
	{ }

	constexpr
	error_info& no_info(void)
	noexcept
	{
		return *this;
	}

	error_info& al_error_code(ALenum al_err_code)
	noexcept;

	ALenum al_error_code(void) const
	noexcept;

	error_info& al_library_name(const char* al_lb_name)
	noexcept;

	const char* al_library_name(void) const
	noexcept;

	error_info& al_function_name(const char* al_fn_name)
	noexcept;

	const char* al_function_name(void) const
	noexcept;

	error_info& source_function(const char* src_func)
	noexcept;

	const char* source_function(void) const
	noexcept;

	error_info& source_file(const char* src_file)
	noexcept;

	const char* source_file(void) const
	noexcept;

	error_info& source_line(unsigned src_line)
	noexcept;

	unsigned source_line(void) const
	noexcept;

	error_info& al_object(const any_object_name& obj)
	noexcept;

	any_object_name al_object(void) const
	noexcept;

	error_info& index(ALuint idx)
	noexcept;

	ALuint index(void) const
	noexcept;

	error_info& enum_value(const any_enum_value& enum_val)
	noexcept;

	const any_enum_value& enum_value(void) const
	noexcept;
};

} // namespace oalplus

#include <oalplus/error/info.inl>

#endif // include guard
