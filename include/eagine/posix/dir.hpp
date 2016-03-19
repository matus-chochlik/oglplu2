/**
 *  @file eagine/posix/dir.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_POSIX_DIR_1509260923_HPP
#define EAGINE_POSIX_DIR_1509260923_HPP

#include "dir_descriptor.hpp"
#include "file_descriptor.hpp"
#include "../cstr_ref.hpp"
#include <fcntl.h>

namespace eagine {
namespace posix {

static inline
outcome<owned_dir_descriptor> opendir(const cstr_ref& path)
noexcept
{
	DIR* dp = ::opendir(path.c_str());
	return error_if(dp == nullptr, -1), owned_dir_descriptor(dp);
}

static inline
outcome<owned_dir_descriptor> fdopendir(file_descriptor fd)
noexcept
{
	DIR* dp = ::fdopendir(get_raw_fd(fd));
	return error_if(dp == nullptr, -1), owned_dir_descriptor(dp);
}

static inline
outcome<file_descriptor> dirfd(dir_descriptor dd)
noexcept
{
	int dfd = ::dirfd(get_raw_dp(dd));
	return error_if_negative(dfd, dfd), file_descriptor(dfd);
}

static inline
outcome<owned_file_descriptor> openat(
	file_descriptor dfd,
	const cstr_ref& path,
	int flags
) noexcept
{
	int fd = ::openat(get_raw_fd(dfd), path.c_str(), flags);
	return error_if_negative(fd, fd), owned_file_descriptor(fd);
}

} // namespace posix
} // namespace eagine

#endif // include guard
