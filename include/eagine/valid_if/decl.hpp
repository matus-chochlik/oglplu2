/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_VALID_IF_DECL_HPP
#define EAGINE_VALID_IF_DECL_HPP

#include "../assert.hpp"
#include "../tribool.hpp"
#include "../type_traits.hpp"
#include "base.hpp"

namespace eagine {
//------------------------------------------------------------------------------
/// @brief Policy for optionally valid values, indicated by a boolean flag.
/// @ingroup valid_if
struct valid_flag_policy {
    bool _is_valid{false};

    constexpr valid_flag_policy() noexcept = default;

    constexpr valid_flag_policy(bool is_valid) noexcept
      : _is_valid(is_valid) {}

    /// @brief Returns value validity depending on internally stored flag.
    template <typename T>
    auto operator()(const T&) const noexcept -> bool {
        return _is_valid;
    }

    struct do_log {
        template <typename X>
        constexpr do_log(X) noexcept {}

        template <typename Log, typename T>
        void operator()(Log& log, const T&) const {
            log << "Getting the value of an empty optional";
        }
    };
};
//------------------------------------------------------------------------------
/// @brief Primary template for conditionally valid values.
/// @ingroup valid_if
template <typename T, typename Policy, typename DoLog = typename Policy::do_log>
class valid_if : public basic_valid_if<T, Policy, DoLog> {
private:
    using _base_t = basic_valid_if<T, Policy, DoLog>;

    auto _base() noexcept -> _base_t& {
        return *this;
    }

    using _base_t::_get_value;

public:
    using _base_t::_base_t;
    using _base_t::is_valid;
    using _base_t::value;
    using _base_t::value_or;

    /// @brief Copies argument into this instance.
    auto operator=(const T& v) -> auto& {
        _base() = v;
        return *this;
    }

    /// @brief Moves argument into this instance.
    auto operator=(T&& v) -> auto& {
        _base() = std::move(v);
        return *this;
    }

    /// @brief Indicates if the stored value is valid according to policy.
    /// @see basic_valid_if::is_valid
    explicit operator bool() const noexcept {
        return is_valid();
    }

    /// @brief Calls the specified function if the stored valus is valid.
    /// @param func the function to call.
    template <typename Func>
    auto then(const Func& func) const -> std::enable_if_t<
      !std::is_same_v<std::result_of_t<Func(T)>, void>,
      valid_if<std::result_of_t<Func(T)>, valid_flag_policy>> {
        if(is_valid()) {
            return {func(_get_value()), true};
        }
        return {};
    }

    /// @brief Calls the specified function if the stored valus is valid.
    /// @param func the function to call.
    /// @see then
    template <typename Func>
    auto operator|(const Func& func) const {
        return then(func);
    }

    /// @brief Returns the stored value if valid, returns fallback otherwise.
    /// @see basic_valid_if::value_or
    auto operator/(const T& fallback) const noexcept -> const T& {
        return value_or(fallback);
    }

    /// @brief Returns the stored value, throws if it is invalid.
    /// @see basic_valid_if::value
    /// @throws std::runtime_error
    auto operator*() const noexcept -> const T& {
        return value();
    }

    /// @brief Returns pointer to the stored value, throws if it is invalid.
    /// @see basic_valid_if::value
    /// @throws std::runtime_error
    auto operator->() const noexcept -> const T* {
        return &value();
    }

    /// @brief Equality comparison of the stored value with @p v.
    constexpr auto operator==(const T& v) const -> tribool {
        return {_get_value() == v, !is_valid()};
    }

    /// @brief Non-equality comparison of the stored value with @p v.
    constexpr auto operator!=(const T& v) const -> tribool {
        return {_get_value() != v, !is_valid()};
    }

    /// @brief Less-than comparison of the stored value with @p v.
    constexpr auto operator<(const T& v) const -> tribool {
        return {_get_value() < v, !is_valid()};
    }

    /// @brief Greater-than comparison of the stored value with @p v.
    constexpr auto operator>(const T& v) const -> tribool {
        return {_get_value() > v, !is_valid()};
    }

    /// @brief Less-equal comparison of the stored value with @p v.
    constexpr auto operator<=(const T& v) const -> tribool {
        return {_get_value() <= v, !is_valid()};
    }

    /// @brief Greater-equal comparison of the stored value with @p v.
    constexpr auto operator>=(const T& v) const -> tribool {
        return {_get_value() >= v, !is_valid()};
    }
};
//------------------------------------------------------------------------------
/// @brief Equality comparison of two conditionally valid values.
/// @ingroup valid_if
template <typename T, typename P1, typename P2>
static constexpr auto
operator==(const valid_if<T, P1>& v1, const valid_if<T, P2>& v2) noexcept
  -> tribool {
    return {
      (v1.value_anyway() == v2.value_anyway()),
      (!v1.is_valid() || !v2.is_valid())};
}

/// @brief Non-equality comparison of two conditionally valid values.
/// @ingroup valid_if
template <typename T, typename P1, typename P2>
static constexpr auto
operator!=(const valid_if<T, P1>& v1, const valid_if<T, P2>& v2) noexcept
  -> tribool {
    return {
      (v1.value_anyway() != v2.value_anyway()),
      (!v1.is_valid() || !v2.is_valid())};
}

/// @brief Less-than comparison of two conditionally valid values.
/// @ingroup valid_if
template <typename T, typename P1, typename P2>
static constexpr auto
operator<(const valid_if<T, P1>& v1, const valid_if<T, P2>& v2) noexcept
  -> tribool {
    return {
      (v1.value_anyway() < v2.value_anyway()),
      (!v1.is_valid() || !v2.is_valid())};
}

/// @brief Greater-than comparison of two conditionally valid values.
/// @ingroup valid_if
template <typename T, typename P1, typename P2>
static constexpr auto
operator>(const valid_if<T, P1>& v1, const valid_if<T, P2>& v2) noexcept
  -> tribool {
    return {
      (v1.value_anyway() > v2.value_anyway()),
      (!v1.is_valid() || !v2.is_valid())};
}

/// @brief Less-equal comparison of two conditionally valid values.
/// @ingroup valid_if
template <typename T, typename P1, typename P2>
static constexpr auto
operator<=(const valid_if<T, P1>& v1, const valid_if<T, P2>& v2) noexcept
  -> tribool {
    return {
      (v1.value_anyway() <= v2.value_anyway()),
      (!v1.is_valid() || !v2.is_valid())};
}

/// @brief Greater-equal comparison of two conditionally valid values.
/// @ingroup valid_if
template <typename T, typename P1, typename P2>
static constexpr auto
operator>=(const valid_if<T, P1>& v1, const valid_if<T, P2>& v2) noexcept
  -> tribool {
    return {
      (v1.value_anyway() >= v2.value_anyway()),
      (!v1.is_valid() || !v2.is_valid())};
}
//------------------------------------------------------------------------------
/// @brief Overload of extract for conditionally valid values.
/// @pre opt.is_valid()
template <typename T, typename P>
static constexpr auto extract(const valid_if<T, P>& opt) noexcept -> const T& {
    return EAGINE_CONSTEXPR_ASSERT(bool(opt), opt.value_anyway());
}

/// @brief Overload of extract for conditionally valid values.
/// @pre opt.is_valid()
template <typename T, typename P>
static constexpr auto extract(valid_if<T, P>& opt) noexcept -> T& {
    return EAGINE_CONSTEXPR_ASSERT(bool(opt), opt.value_anyway());
}

/// @brief Overload of extract for conditionally valid values.
/// @pre opt.is_valid()
template <typename T, typename P>
static constexpr auto extract(valid_if<T, P>&& opt) noexcept -> T&& {
    return EAGINE_CONSTEXPR_ASSERT(bool(opt), std::move(opt.value_anyway()));
}
//------------------------------------------------------------------------------
/// @brief Overload of extract_or for conditionally valid values.
template <typename T, typename P, typename F>
static constexpr auto
extract_or(const valid_if<T, P>& opt, F&& fallback) noexcept
  -> std::enable_if_t<std::is_convertible_v<F, T>, T> {
    if(bool(opt)) {
        return opt.value_anyway();
    }
    return T{std::forward<F>(fallback)};
}
//------------------------------------------------------------------------------
/// @brief Overload of extract_or for conditionally valid values.
template <typename T, typename P, typename F>
static constexpr auto extract_or(valid_if<T, P>& opt, T& fallback) noexcept
  -> T& {
    if(bool(opt)) {
        return opt.value_anyway();
    }
    return fallback;
}
//------------------------------------------------------------------------------
/// @brief Helper class storing both conditionally valid value and fallback.
template <typename T, typename P, typename F>
class valid_if_or_fallback : public valid_if<T, P> {
public:
    /// @brief Constructor
    valid_if_or_fallback(valid_if<T, P> vi, F fallback) noexcept(
      noexcept(valid_if<T, P>(std::declval<valid_if<T, P>&&>())) && noexcept(
        F(std::declval<F&&>())))
      : valid_if<T, P>{std::move(vi)}
      , _fallback{std::move(fallback)} {}

    /// @brief Returns the stored fallback value.
    auto fallback() const noexcept -> const F& {
        return _fallback;
    }

    /// @brief Returns the stored fallback value.
    auto fallback() noexcept -> F& {
        return _fallback;
    }

private:
    F _fallback{};
};
//------------------------------------------------------------------------------
/// @brief Constructor function for valid_if_or_fallback.
/// @ingroup valid_if
template <typename T, typename P, typename F>
static inline auto either_or(valid_if<T, P> vi, F f) noexcept(
  noexcept(valid_if<T, P>(std::declval<valid_if<T, P>&&>())) && noexcept(
    F(std::declval<F&&>()))) -> valid_if_or_fallback<T, P, F> {
    return {std::move(vi), std::move(f)};
}
//------------------------------------------------------------------------------
/// @brief Specialization of valid_if with flag indicating validity.
/// @ingroup valid_if
/// @see valid_if_indicated
template <typename T>
using optionally_valid = valid_if<T, valid_flag_policy>;
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_VALID_IF_DECL_HPP
