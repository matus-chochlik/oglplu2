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
#include <memory>
#include <type_traits>

namespace eagine {
//------------------------------------------------------------------------------
template <typename T>
static constexpr inline T& extract(T* ptr) noexcept {
    return EAGINE_CONSTEXPR_ASSERT(bool(ptr), *ptr);
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr inline T& extract_or(
  T* ptr, std::remove_const_t<T>& fallback) noexcept {
    return bool(ptr) ? *ptr : fallback;
}
//------------------------------------------------------------------------------
template <typename T, typename F>
static constexpr inline std::enable_if_t<std::is_convertible_v<F, T>, T>
extract_or(T* ptr, F&& fallback) {
    return bool(ptr) ? *ptr : T{std::forward<F>(fallback)};
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr inline T& extract(std::shared_ptr<T>& ptr) noexcept {
    return EAGINE_CONSTEXPR_ASSERT(bool(ptr), *ptr);
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr inline T& extract_or(
  std::shared_ptr<T>& ptr, std::remove_const_t<T>& fallback) noexcept {
    return bool(ptr) ? *ptr : fallback;
}
//------------------------------------------------------------------------------
template <typename T, typename F>
static constexpr inline std::enable_if_t<std::is_convertible_v<F, T>, T>
extract_or(std::shared_ptr<T>& ptr, F&& fallback) {
    return bool(ptr) ? *ptr : T{std::forward<F>(fallback)};
}
//------------------------------------------------------------------------------
template <typename T, typename D>
static constexpr inline T& extract(std::unique_ptr<T, D>& ptr) noexcept {
    return EAGINE_CONSTEXPR_ASSERT(bool(ptr), *ptr);
}
//------------------------------------------------------------------------------
template <typename T, typename D>
static constexpr inline T& extract_or(
  std::unique_ptr<T, D>& ptr, std::remove_const_t<T>& fallback) noexcept {
    return bool(ptr) ? *ptr : fallback;
}
//------------------------------------------------------------------------------
template <typename T, typename D, typename F>
static constexpr inline std::enable_if_t<std::is_convertible_v<F, T>, T>
extract_or(std::unique_ptr<T, D>& ptr, F&& fallback) {
    return bool(ptr) ? *ptr : T{std::forward<F>(fallback)};
}
//------------------------------------------------------------------------------
template <typename Outcome>
struct ok_traits {
    static constexpr nothing_t nok_info(const Outcome&) noexcept {
        return {};
    }
};
//------------------------------------------------------------------------------
template <typename Outcome>
class ok {
private:
    Outcome _outcome{};

    using _traits = ok_traits<Outcome>;

public:
    constexpr inline ok(Outcome&& outcome) noexcept(
      noexcept(std::declval<Outcome&&>()))
      : _outcome{std::move(outcome)} {
    }

    explicit constexpr operator bool() noexcept(
      noexcept(bool(std::declval<Outcome&>()))) {
        return bool(_outcome);
    }

    explicit constexpr operator bool() const
      noexcept(noexcept(bool(std::declval<const Outcome&>()))) {
        return bool(_outcome);
    }

    constexpr decltype(extract(std::declval<Outcome&>())) get() noexcept(
      noexcept(extract(std::declval<Outcome&>()))) {
        return extract(_outcome);
    }

    constexpr decltype(extract(std::declval<const Outcome&>())) get() const
      noexcept(noexcept(extract(std::declval<const Outcome&>()))) {
        return extract(_outcome);
    }

    constexpr operator decltype(extract(std::declval<Outcome&>()))() noexcept(
      noexcept(extract(std::declval<Outcome&>()))) {
        return extract(_outcome);
    }

    constexpr operator decltype(extract(std::declval<const Outcome&>()))() const
      noexcept(noexcept(extract(std::declval<const Outcome&>()))) {
        return extract(_outcome);
    }

    constexpr decltype(_traits::nok_info(std::declval<const Outcome&>())) nok()
      const noexcept {
        return _traits::nok_info(_outcome);
    }

    constexpr decltype(_traits::nok_info(std::declval<const Outcome&>()))
    operator!() const noexcept {
        return _traits::nok_info(_outcome);
    }
};
//------------------------------------------------------------------------------
template <typename Outcome>
auto begin(
  const ok<Outcome>& x,
  decltype(std::declval<const ok<Outcome>&>().get().begin())* = nullptr) {
    return x.get().begin();
}
//------------------------------------------------------------------------------
template <typename Outcome>
auto end(
  const ok<Outcome>& x,
  decltype(std::declval<const ok<Outcome>&>().get().end())* = nullptr) {
    return x.get().end();
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_EXTRACT_HPP
