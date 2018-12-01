/**
 *  @file eagine/posix/file_stat.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_POSIX_FILE_STAT_1509260923_HPP
#define EAGINE_POSIX_FILE_STAT_1509260923_HPP

#include <sys/stat.h>
#include "file_descriptor.hpp"

namespace eagine {
namespace posix {

static inline outcome<void>
fstat(file_descriptor fd, struct ::stat& buf) noexcept {
    return error_if_not_zero(::fstat(get_raw_fd(fd), &buf), get_raw_fd(fd));
}

static inline outcome<off_t>
file_size(file_descriptor fd) noexcept {
    struct ::stat buf;
    buf.st_size = 0;
    outcome<void> result = fstat(fd, buf);
    return std::move(result).add(buf.st_size);
}

class file_stat {
private:
    struct ::stat _st;

public:
    file_stat(file_descriptor fdw) {
        fstat(fdw, _st);
    }

    auto size(void) const noexcept {
        return _st.st_size;
    }
};

} // namespace posix
} // namespace eagine

#endif // include guard
