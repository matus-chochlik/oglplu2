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

#include "../string_span.hpp"
#include "dir_descriptor.hpp"
#include "file_descriptor.hpp"
#include <fcntl.h>

namespace eagine {
namespace posix {

static inline outcome<owned_dir_descriptor> opendir(string_view path) noexcept {
    DIR* dp = ::opendir(c_str(path));
    return error_if(dp == nullptr, -1).add(owned_dir_descriptor(dp));
}

static inline outcome<owned_dir_descriptor>
fdopendir(file_descriptor fd) noexcept {
    DIR* dp = ::fdopendir(get_raw_fd(fd));
    return error_if(dp == nullptr, -1).add(owned_dir_descriptor(dp));
}

static inline outcome<file_descriptor> dirfd(dir_descriptor dd) noexcept {
    int dfd = ::dirfd(get_raw_dp(dd));
    return error_if_negative(dfd, dfd).add(file_descriptor(dfd));
}

static inline outcome<owned_file_descriptor>
openat(file_descriptor dfd, string_view path, int flags) noexcept {
    int fd = ::openat(get_raw_fd(dfd), c_str(path), flags);
    return error_if_negative(fd, fd).add(owned_file_descriptor(fd));
}

} // namespace posix
} // namespace eagine

#endif // include guard
