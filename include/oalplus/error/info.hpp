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

#include "info_base.hpp"
#include "../object/al_name.hpp"
#include "../utils/enum_class.hpp"

namespace oalplus {

struct extended_error_info;

class error_info
 : public error_info_base<error_info>
{
private:
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

	error_info& al_object(const any_object_name& obj)
	noexcept;

	any_object_name al_object(void) const
	noexcept;

	error_info& index(ALuint idx)
	noexcept;

	ALuint index(void) const
	noexcept;

	error_info& al_enum_value(const any_enum_value& enum_val)
	noexcept;

	const any_enum_value& al_enum_value(void) const
	noexcept;
};

} // namespace oalplus

#include <oalplus/error/info.inl>

#endif // include guard
