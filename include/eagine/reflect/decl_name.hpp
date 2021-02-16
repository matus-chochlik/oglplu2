/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_REFLECT_DECL_NAME_HPP
#define EAGINE_REFLECT_DECL_NAME_HPP

#include "../memory/span_algo.hpp"
#include "../string_span.hpp"

namespace eagine {
//------------------------------------------------------------------------------
struct decl_name : string_view {
    static constexpr const span_size_t max_length = 80;

    constexpr decl_name() noexcept = default;

    template <
      std::size_t N,
      typename = std::enable_if_t<(N <= span_size_t(max_length))>>
    constexpr decl_name(const char (&array)[N]) noexcept
      : string_view{array} {}
};
//------------------------------------------------------------------------------
class decl_name_storage {
public:
    static constexpr const span_size_t max_length = decl_name::max_length;

    auto assign(string_view str) -> bool {
        if(str.size() <= max_length) {
            memory::copy(str, cover(_storage));
            _length = str.size();
            return true;
        }
        return false;
    }

    auto get() noexcept {
        return head(cover(_storage), _length);
    }

    auto get() const noexcept {
        return head(view(_storage), _length);
    }

private:
    std::array<char, max_length> _storage{};
    span_size_t _length{0};
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_REFLECT_DECL_NAME_HPP
