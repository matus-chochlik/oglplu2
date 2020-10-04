/**
 *  @file eagine/optional_ref.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_OPTIONAL_REF_HPP
#define EAGINE_OPTIONAL_REF_HPP

#include "assert.hpp"
#include "nothing.hpp"
#include "tribool.hpp"
#include <memory>

namespace eagine {
//------------------------------------------------------------------------------
template <typename T>
class optional_reference_wrapper {
private:
    T* _ptr{nullptr};

public:
    optional_reference_wrapper(T& ref) noexcept
      : _ptr(std::addressof(ref)) {}

    optional_reference_wrapper(optional_reference_wrapper&&) noexcept = default;
    optional_reference_wrapper(const optional_reference_wrapper&) = default;

    auto operator=(optional_reference_wrapper&&) noexcept
      -> optional_reference_wrapper& = default;
    auto operator=(const optional_reference_wrapper&)
      -> optional_reference_wrapper& = default;
    ~optional_reference_wrapper() noexcept = default;

    constexpr optional_reference_wrapper(nothing_t) noexcept {}

    constexpr optional_reference_wrapper(std::nullptr_t) noexcept {}

    auto is_valid() const noexcept -> bool {
        return _ptr != nullptr;
    }

    explicit operator bool() const noexcept {
        return is_valid();
    }

    auto get() const noexcept -> T& {
        EAGINE_ASSERT(is_valid());
        return *_ptr;
    }

    auto value() const noexcept -> T& {
        EAGINE_ASSERT(is_valid());
        return *_ptr;
    }

    template <typename U>
    auto value_or(U&& fallback) const noexcept
      -> std::enable_if_t<std::is_convertible_v<U, T>, T> {
        if(is_valid()) {
            return *_ptr;
        }
        return T(std::forward<U>(fallback));
    }

    explicit operator T&() const noexcept {
        return get();
    }

    friend auto operator==(const optional_reference_wrapper& l, const T& r)
      -> tribool {
        if(l.is_valid()) {
            return l.value() == r;
        }
        return indeterminate;
    }

    friend auto operator!=(const optional_reference_wrapper& l, const T& r)
      -> tribool {
        if(l.is_valid()) {
            return l.value() != r;
        }
        return indeterminate;
    }
};
//------------------------------------------------------------------------------
template <typename T>
static inline auto extract(optional_reference_wrapper<T> ref) noexcept -> T& {
    return ref.get();
}
//------------------------------------------------------------------------------
template <typename T>
static inline auto
extract_or(optional_reference_wrapper<T> ref, T& fallback) noexcept -> T& {
    if(ref) {
        return ref.get();
    }
    return fallback;
}
//------------------------------------------------------------------------------
template <typename T, typename F>
static inline auto extract_or(optional_reference_wrapper<T> ref, F&& fallback)
  -> std::enable_if_t<std::is_convertible_v<F, T>, T> {
    if(ref) {
        return ref.get();
    }
    return T{std::forward<F>(fallback)}; // NOLINT(hicpp-no-array-decay)
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_OPTIONAL_REF_HPP
