/**
 *  @file oalplus/error/error_alc.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ERROR_ERROR_ALC_1509260923_HPP
#define OALPLUS_ERROR_ERROR_ALC_1509260923_HPP

#include "info_alc.hpp"
#include <stdexcept>

namespace oalplus {

class error_alc
 : public std::runtime_error
{
private:
	error_info_alc _info;

	static
	std::string _make_msg(error_info_alc& info);
public:
	error_alc(error_info_alc&& info);

	const error_info_alc& info(void) const
	noexcept
	{
		return _info;
	}
};

} // namespace oalplus

#include <oalplus/error/error_alc.inl>

#endif // include guard
