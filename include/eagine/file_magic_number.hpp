/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_FILE_MAGIC_NUMBER_HPP
#define EAGINE_FILE_MAGIC_NUMBER_HPP

#include "types.hpp"
#include <array>
#include <cstring>

namespace eagine {

template <char... C>
class file_magic_number {
private:
    static_assert(
      sizeof...(C) <= 16,
      "File magic number cannot be more than 16 bytes long");

    const std::array<const char, 16> _magic_number;

    static constexpr auto _make_magic_number() -> std::array<const char, 16> {
        return {{C...}};
    }

public:
    using value_type = const char;
    using size_type = span_size_t;

    constexpr file_magic_number() noexcept
      : _magic_number(_make_magic_number()) {}

    auto is_valid() const noexcept -> bool {
        return std::strncmp(
                 _magic_number.data(),
                 _make_magic_number().data(),
                 sizeof...(C)) == 0;
    }

    auto data() const noexcept -> const char* {
        return _magic_number.data();
    }

    static constexpr auto size() noexcept -> span_size_t {
        return 16;
    }
};

} // namespace eagine

#endif // EAGINE_FILE_MAGIC_NUMBER_HPP
