/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_OPTIONAL_REF_HPP
#define EAGINE_OPTIONAL_REF_HPP

#include "assert.hpp"
#include "nothing.hpp"
#include "tribool.hpp"
#include <memory>

namespace eagine {
//------------------------------------------------------------------------------
/// @brief Optional reference to an instance of type @p T.
/// @ingroup valid_if
/// @see valid_if
template <typename T>
class optional_reference_wrapper {
public:
    /// @brief Construction from a reference to value of type @p T.
    optional_reference_wrapper(T& ref) noexcept
      : _ptr{std::addressof(ref)} {}

    /// @brief Move constructor.
    optional_reference_wrapper(optional_reference_wrapper&&) noexcept = default;

    /// @brief Copy constructor.
    optional_reference_wrapper(const optional_reference_wrapper&) = default;

    /// @brief Move assignment operator.
    auto operator=(optional_reference_wrapper&&) noexcept
      -> optional_reference_wrapper& = default;

    /// @brief Copy assignment operator.
    auto operator=(const optional_reference_wrapper&)
      -> optional_reference_wrapper& = default;

    ~optional_reference_wrapper() noexcept = default;

    /// @brief Construction from nothing.
    /// @post !is_valid()
    constexpr optional_reference_wrapper(nothing_t) noexcept {}

    /// @brief Construction from nullptr.
    /// @post !is_valid()
    constexpr optional_reference_wrapper(std::nullptr_t) noexcept {}

    /// @brief Indicates if this stores a valid reference.
    auto is_valid() const noexcept -> bool {
        return _ptr != nullptr;
    }

    /// @brief Indicates if this stores a valid reference.
    /// @see is_valid
    explicit operator bool() const noexcept {
        return is_valid();
    }

    /// @brief Returns the stored reference.
    /// @pre is_valid()
    auto get() const noexcept -> T& {
        EAGINE_ASSERT(is_valid());
        return *_ptr;
    }

    /// @brief Returns the stored value.
    /// @pre is_valid()
    auto value() const noexcept -> const T& {
        EAGINE_ASSERT(is_valid());
        return *_ptr;
    }

    /// @brief Returns the stored value if valid or @p fallback otherwise.
    /// @see is_valid
    template <typename U>
    auto value_or(U&& fallback) const noexcept
      -> std::enable_if_t<std::is_convertible_v<U, T>, T> {
        if(is_valid()) {
            return *_ptr;
        }
        return T(std::forward<U>(fallback));
    }

    /// @brief Returns the stored reference.
    /// @see get
    explicit operator T&() const noexcept {
        return get();
    }

    /// @brief Tri-state equality comparison of the referred instance with a value.
    friend auto operator==(const optional_reference_wrapper& l, const T& r)
      -> tribool {
        if(l.is_valid()) {
            return l.value() == r;
        }
        return indeterminate;
    }

    /// @brief Tri-state nonequality comparison of the referred instance with a value.
    friend auto operator!=(const optional_reference_wrapper& l, const T& r)
      -> tribool {
        if(l.is_valid()) {
            return l.value() != r;
        }
        return indeterminate;
    }

private:
    T* _ptr{nullptr};
};
//------------------------------------------------------------------------------
/// @brief Overload of extract for optional_reference_wrapper.
/// @ingroup valid_if
template <typename T>
static inline auto extract(optional_reference_wrapper<T> ref) noexcept -> T& {
    return ref.get();
}
//------------------------------------------------------------------------------
/// @brief Overload of extract_or for optional_reference_wrapper.
/// @ingroup valid_if
template <typename T>
static inline auto
extract_or(optional_reference_wrapper<T> ref, T& fallback) noexcept -> T& {
    if(ref) {
        return ref.get();
    }
    return fallback;
}
//------------------------------------------------------------------------------
/// @brief Overload of extract_or for optional_reference_wrapper.
/// @ingroup valid_if
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
