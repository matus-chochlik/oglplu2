/**
 *  @file eagine/posix/sysconf.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_POSIX_SYSCONF_1509260923_HPP
#define EAGINE_POSIX_SYSCONF_1509260923_HPP

#include "error.hpp"
#include <unistd.h>

namespace eagine {
namespace posix {

static inline
outcome<long> system_config(int name)
noexcept
{
	long res = ::sysconf(name);
	return {error_if_negative(res), res};
}

static inline
outcome<long> page_size(void)
noexcept
{
	return system_config(_SC_PAGESIZE);
}

} // namespace posix
} // namespace eagine

#endif // include guard
