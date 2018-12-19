/**
 *  @file eagine/extract.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_EXTRACT_HPP
#define EAGINE_EXTRACT_HPP

#include "assert.hpp"
#include <type_traits>
#include <utility>

namespace eagine {
//------------------------------------------------------------------------------
template <typename T>
class extracted {
public:
    constexpr extracted() noexcept = default;

    constexpr extracted(T* ref) noexcept
      : _ref{ref} {
    }

    constexpr bool is_valid() const noexcept {
        return bool(_ref);
    }

    constexpr T& ref() const noexcept {
        return EAGINE_CONSTEXPR_ASSERT(bool(_ref), *_ref);
    }

    explicit constexpr operator T&() const noexcept {
        return ref();
    }

    constexpr T* operator->() const noexcept {
        return EAGINE_CONSTEXPR_ASSERT(bool(_ref), _ref);
    }

    template <
      typename M,
      typename X,
      typename =
        std::enable_if_t<std::is_same_v<T, X> || std::is_base_of_v<T, X>>>
    constexpr extracted<
      std::conditional_t<std::is_const_v<T>, std::add_const_t<M>, M>>
    operator[](M X::*data_member) const noexcept {
        return is_valid() ? &(_ref->*data_member) : nullptr;
    }

    constexpr T or_default() const noexcept {
        return bool(_ref) ? *_ref : T{};
    }

    template <typename X>
    constexpr std::enable_if_t<std::is_convertible_v<X&, T&>, T&> or_(
      X& fallback) const noexcept {
        return is_valid() ? *_ref : fallback;
    }

    template <typename X>
    constexpr std::enable_if_t<std::is_convertible_v<X, std::remove_cv_t<T>>, T>
    or_(X fallback) const noexcept {
        return is_valid() ? *_ref : std::move(fallback);
    }

private:
    T* const _ref = nullptr;
};
//------------------------------------------------------------------------------
template <typename T, typename X>
constexpr std::enable_if_t<std::is_convertible_v<X&, T&>, T&> operator/(
  extracted<T> extr, X& fallback) noexcept {
    return extr.or_(fallback);
}
//------------------------------------------------------------------------------
template <typename T, typename X>
constexpr std::enable_if_t<std::is_convertible_v<X, std::remove_cv_t<T>>, T>
operator/(extracted<T> extr, X fallback) noexcept {
    return extr.or_(std::move(fallback));
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr inline extracted<T> extract(T* ptr) noexcept {
    return {ptr};
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_EXTRACT_HPP
