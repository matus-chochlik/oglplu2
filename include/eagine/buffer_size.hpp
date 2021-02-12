/// @file eagine/utils/buffer_size.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_BUFFER_SIZE_HPP
#define EAGINE_BUFFER_SIZE_HPP

#include "span.hpp"
#include "type_identity.hpp"
#include <type_traits>

namespace eagine {

template <typename S>
class buffer_size {
private:
    static_assert(std::is_integral_v<S>);
    S _v{0};

public:
    constexpr buffer_size() noexcept = default;

    explicit constexpr buffer_size(S v) noexcept
      : _v(v) {}

    template <typename T>
    constexpr buffer_size(type_identity<T>, span_size_t count) noexcept
      : _v(S(span_size_of<T>() * count)) {}

    template <typename T, typename P, typename Z>
    constexpr buffer_size(memory::basic_span<T, P, Z> s) noexcept
      : _v(S(span_size_of<T>() * span_size(s.size()))) {}

    constexpr auto get() const noexcept -> S {
        return _v;
    }

    constexpr operator S() const noexcept {
        return _v;
    }

    template <typename T>
    explicit constexpr operator T() const {
        return T(_v);
    }

    friend constexpr auto operator+(buffer_size a, buffer_size b) noexcept
      -> buffer_size {
        return {a._v + b._v};
    }
};

} // namespace eagine

#endif // EAGINE_BUFFER_SIZE_HPP
