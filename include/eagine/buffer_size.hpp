/**
 *  @file eagine/utils/buffer_size.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_UTILS_BUFFER_SIZE_1509260923_HPP
#define EAGINE_UTILS_BUFFER_SIZE_1509260923_HPP

#include "identity.hpp"
#include "span.hpp"
#include "std/type_traits.hpp"

namespace eagine {

template <typename S>
class buffer_size {
private:
    static_assert(std::is_integral_v<S>, "");
    S _v;

public:
    constexpr inline buffer_size(void) noexcept
      : _v(0) {
    }

    explicit constexpr inline buffer_size(S v) noexcept
      : _v(v) {
    }

    template <typename T>
    constexpr inline buffer_size(identity<T>, span_size_t count) noexcept
      : _v(S(span_size_of<T>() * count)) {
    }

    template <typename T, span_size_t N>
    constexpr inline buffer_size(const span<T, N>& s) noexcept
      : _v(S(span_size_of<T>() * span_size(s.size()))) {
    }

    constexpr inline S get(void) const noexcept {
	return _v;
    }

    constexpr inline operator S(void) const noexcept {
	return _v;
    }

    template <typename T>
    explicit constexpr inline operator T(void) const {
	return T(_v);
    }

    friend constexpr inline buffer_size operator+(
      buffer_size a, buffer_size b) noexcept {
	return buffer_size{a._v + b._v};
    }
};

} // namespace eagine

#endif // include guard
