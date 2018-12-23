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

#include "nothing.hpp"
#include <cassert>
#include <memory>

namespace eagine {
//------------------------------------------------------------------------------
template <typename T>
class optional_reference_wrapper {
private:
    T* _ptr = nullptr;

public:
    optional_reference_wrapper(T& ref) noexcept
      : _ptr(std::addressof(ref)) {
    }

    optional_reference_wrapper(optional_reference_wrapper&&) noexcept = default;
    optional_reference_wrapper(const optional_reference_wrapper&) = default;
    optional_reference_wrapper& operator=(
      optional_reference_wrapper&&) noexcept = default;
    optional_reference_wrapper& operator=(const optional_reference_wrapper&) =
      default;
    ~optional_reference_wrapper() noexcept = default;

    constexpr optional_reference_wrapper(nothing_t) noexcept {
    }

    constexpr optional_reference_wrapper(std::nullptr_t) noexcept {
    }

    bool is_valid() const noexcept {
        return _ptr != nullptr;
    }

    explicit operator bool() const noexcept {
        return is_valid();
    }

    bool operator!() const noexcept {
        return !is_valid();
    }

    T& get() const noexcept {
        assert(is_valid());
        return *_ptr;
    }

    operator T&() const noexcept {
        return get();
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_OPTIONAL_REF_HPP
