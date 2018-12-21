/**
 *  @file eagine/posix/file_descriptor.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_POSIX_FILE_DESCRIPTOR_HPP
#define EAGINE_POSIX_FILE_DESCRIPTOR_HPP

#include "../memory/block.hpp"
#include "error.hpp"
#include <unistd.h>

namespace eagine {
namespace posix {

class file_descriptor {
protected:
    int _fd{-1};

public:
    constexpr inline file_descriptor() noexcept {
    }

    explicit constexpr inline file_descriptor(int fd) noexcept
      : _fd(fd) {
    }

    file_descriptor(file_descriptor&& temp) noexcept
      : _fd(temp._fd) {
        temp._fd = -1;
    }

    file_descriptor(const file_descriptor&) = default;
    file_descriptor& operator=(const file_descriptor&) = default;

    file_descriptor& operator=(file_descriptor&& temp) noexcept {
        _fd = temp._fd;
        temp._fd = -1;
        return *this;
    }

    constexpr bool is_valid() const noexcept {
        return _fd >= 0;
    }

    explicit constexpr operator bool() const noexcept {
        return is_valid();
    }

    constexpr bool operator!() const noexcept {
        return !is_valid();
    }

    friend constexpr inline int get_raw_fd(file_descriptor fd) noexcept {
        return fd._fd;
    }

    friend inline void swap(file_descriptor& a, file_descriptor& b) noexcept {
        std::swap(a._fd, b._fd);
    }
};

class owned_file_descriptor : public file_descriptor {
public:
    explicit owned_file_descriptor(int fd) noexcept
      : file_descriptor(fd) {
    }

    explicit owned_file_descriptor(file_descriptor&& fdw) noexcept
      : file_descriptor(std::move(fdw)) {
    }

    owned_file_descriptor(owned_file_descriptor&&) = default;
    owned_file_descriptor& operator=(owned_file_descriptor&&) = default;
    owned_file_descriptor(const owned_file_descriptor&) = delete;
    owned_file_descriptor& operator=(const owned_file_descriptor&&) = delete;

    friend inline void swap(
      owned_file_descriptor& a, owned_file_descriptor& b) noexcept {
        std::swap(a._fd, b._fd);
    }
};

static inline outcome<owned_file_descriptor> dup(
  file_descriptor from) noexcept {
    int fd = ::dup(get_raw_fd(from));
    return error_if_negative(fd, fd).add(owned_file_descriptor(fd));
}

static inline outcome<void> close(owned_file_descriptor& fdw) noexcept {
    owned_file_descriptor tfdw = std::move(fdw);
    int fd = get_raw_fd(tfdw);
    return error_if_not_zero(::close(fd), fd);
}

static inline outcome<ssize_t> read(
  file_descriptor fd, memory::block buf) noexcept {
    return error_if_negative(
      ::read(get_raw_fd(fd), buf.data(), size_t(buf.size())), get_raw_fd(fd));
}

static inline outcome<ssize_t> write(
  file_descriptor fd, memory::const_block buf) noexcept {
    return error_if_negative(
      ::write(get_raw_fd(fd), buf.data(), size_t(buf.size())), get_raw_fd(fd));
}

class file_descriptor_owner {
private:
    owned_file_descriptor _ofd;

public:
    file_descriptor_owner() = default;

    file_descriptor_owner(owned_file_descriptor&& ofd) noexcept
      : _ofd(std::move(ofd)) {
    }

    file_descriptor_owner(file_descriptor_owner&&) = default;

    file_descriptor_owner(const file_descriptor_owner& that)
      : _ofd(dup(that._ofd)) {
    }

    file_descriptor_owner& operator=(file_descriptor_owner&& temp) noexcept {
        swap(_ofd, temp._ofd);
        try {
            ::close(get_raw_fd(temp._ofd));
        } catch(...) {
        }
        return *this;
    }

    file_descriptor_owner& operator=(const file_descriptor_owner& that) {
        owned_file_descriptor ofd(dup(that._ofd));
        swap(_ofd, ofd);
        try {
            ::close(get_raw_fd(ofd));
        } catch(...) {
        }
        return *this;
    }

    ~file_descriptor_owner() noexcept {
        try {
            ::close(get_raw_fd(_ofd));
        } catch(...) {
        }
    }

    file_descriptor get() const noexcept {
        return _ofd;
    }

    operator file_descriptor() const noexcept {
        return get();
    }
};

} // namespace posix
} // namespace eagine

#endif // EAGINE_POSIX_FILE_DESCRIPTOR_HPP
