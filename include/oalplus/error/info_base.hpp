/**
 *  @file oalplus/error/info_base.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ERROR_INFO_BASE_1509260923_HPP
#define OALPLUS_ERROR_INFO_BASE_1509260923_HPP

#include "../config/error.hpp"

namespace oalplus {

template <typename Derived>
class error_info_base
{
private:
	Derived& _self(void)
	noexcept
	{
		return *static_cast<Derived*>(this);
	}

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
public:
	constexpr
	error_info_base(ALenum al_err_code)
	noexcept;

	constexpr
	error_info_base(void)
	noexcept
	 : error_info_base(ALenum(AL_NONE))
	{ }

	Derived& al_error_code(ALenum al_err_code)
	noexcept;

	ALenum al_error_code(void) const
	noexcept;

	Derived& al_library_name(const char* al_lb_name)
	noexcept;

	const char* al_library_name(void) const
	noexcept;

	Derived& al_function_name(const char* al_fn_name)
	noexcept;

	const char* al_function_name(void) const
	noexcept;

	Derived& source_function(const char* src_func)
	noexcept;

	const char* source_function(void) const
	noexcept;

	Derived& source_file(const char* src_file)
	noexcept;

	const char* source_file(void) const
	noexcept;

	Derived& source_line(unsigned src_line)
	noexcept;

	unsigned source_line(void) const
	noexcept;
};

} // namespace oalplus

#include <oalplus/error/info_base.inl>

#endif // include guard
