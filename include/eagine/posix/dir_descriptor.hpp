/**
 *  @file eagine/posix/dir_descriptor.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_POSIX_DIR_DESCRIPTOR_HPP
#define EAGINE_POSIX_DIR_DESCRIPTOR_HPP

#include "error.hpp"
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated"
#endif

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

namespace eagine {
namespace posix {

class dir_descriptor {

protected:
    DIR* _dp{nullptr};

public:
    constexpr inline dir_descriptor() noexcept = default;

    explicit inline dir_descriptor(DIR* dp) noexcept
      : _dp(dp) {
    }

    dir_descriptor(dir_descriptor&& temp) noexcept
      : _dp(temp._dp) {
        temp._dp = nullptr;
    }

    dir_descriptor(const dir_descriptor&) = default;
    dir_descriptor& operator=(const dir_descriptor&) = default;

    dir_descriptor& operator=(dir_descriptor&& temp) noexcept {
        _dp = temp._dp;
        temp._dp = nullptr;
        return *this;
    }

    ~dir_descriptor() noexcept = default;

    constexpr bool is_valid() const noexcept {
        return _dp != nullptr;
    }

    explicit constexpr operator bool() const noexcept {
        return is_valid();
    }

    constexpr bool operator!() const noexcept {
        return !is_valid();
    }

    template <typename Func>
    outcome<void> for_each_entry(Func func) {
        ::dirent entry{};
        ::dirent* pent = nullptr;

        do {
            if(::readdir_r(_dp, &entry, &pent) != 0) {
                return error_outcome(-1);
            }
            if(pent != nullptr) {
                if(!func(entry)) {
                    break;
                }
            }
        } while(pent != nullptr);

        return {};
    }

    friend constexpr inline DIR* get_raw_dp(dir_descriptor dp) noexcept {
        return dp._dp;
    }

    friend inline void swap(dir_descriptor& a, dir_descriptor& b) noexcept {
        std::swap(a._dp, b._dp);
    }
};

class owned_dir_descriptor : public dir_descriptor {
public:
    explicit owned_dir_descriptor(DIR* dp) noexcept
      : dir_descriptor(dp) {
    }

    explicit owned_dir_descriptor(dir_descriptor&& fdw) noexcept
      : dir_descriptor(std::move(fdw)) {
    }

    owned_dir_descriptor(owned_dir_descriptor&&) noexcept = default;
    owned_dir_descriptor& operator=(owned_dir_descriptor&&) noexcept = default;
    owned_dir_descriptor(const owned_dir_descriptor&) = delete;
    owned_dir_descriptor& operator=(const owned_dir_descriptor&) = delete;
    ~owned_dir_descriptor() noexcept = default;

    friend inline void swap(
      owned_dir_descriptor& a, owned_dir_descriptor& b) noexcept {
        std::swap(a._dp, b._dp);
    }
};

static inline outcome<owned_dir_descriptor> dup(dir_descriptor from) noexcept {
    int fd = ::dup(::dirfd(get_raw_dp(from)));
    if(fd < 0) {
        return error_outcome(fd).add(owned_dir_descriptor(nullptr));
    }
    DIR* dp = ::fdopendir(fd);
    return error_if(dp == nullptr, -1).add(owned_dir_descriptor(dp));
}

static inline outcome<void> closedir(owned_dir_descriptor& dpw) noexcept {
    owned_dir_descriptor tdpw = std::move(dpw);
    DIR* dp = get_raw_dp(tdpw);
    return error_if_not_zero(::closedir(dp), -1);
}

class dir_descriptor_owner {
private:
    owned_dir_descriptor _odd;

public:
    dir_descriptor_owner() = default;

    dir_descriptor_owner(owned_dir_descriptor&& odd) noexcept
      : _odd(std::move(odd)) {
    }

    dir_descriptor_owner(dir_descriptor_owner&&) = default;

    dir_descriptor_owner(const dir_descriptor_owner& that)
      : _odd(dup(that._odd)) {
    }

    dir_descriptor_owner& operator=(dir_descriptor_owner&& temp) noexcept {
        swap(_odd, temp._odd);
        try {
            ::closedir(get_raw_dp(temp._odd));
        } catch(...) {
        }
        return *this;
    }

    dir_descriptor_owner& operator=(const dir_descriptor_owner& that) {
        owned_dir_descriptor odd(dup(that._odd));
        swap(_odd, odd);
        try {
            ::closedir(get_raw_dp(odd));
        } catch(...) {
        }
        return *this;
    }

    ~dir_descriptor_owner() noexcept {
        try {
            ::closedir(get_raw_dp(_odd));
        } catch(...) {
        }
    }

    dir_descriptor get() const noexcept {
        return _odd;
    }

    operator dir_descriptor() const noexcept {
        return get();
    }
};

} // namespace posix
} // namespace eagine

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif // EAGINE_POSIX_DIR_DESCRIPTOR_HPP
