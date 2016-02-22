/**
 *  @file eagine/posix/file.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_POSIX_FILE_1509260923_HPP
#define EAGINE_POSIX_FILE_1509260923_HPP

#include "file_descriptor.hpp"
#include "../cstr_ref.hpp"
#include <fcntl.h>

namespace eagine {
namespace posix {

static inline
outcome<owned_file_descriptor> open(const cstr_ref& path, int flags)
noexcept
{
	int fd = ::open(path.c_str(), flags);
	return error_if_negative(fd, fd), owned_file_descriptor(fd);
}

} // namespace posix
} // namespace eagine

#endif // include guard
