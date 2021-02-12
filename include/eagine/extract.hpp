/// @file eagine/extract.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_EXTRACT_HPP
#define EAGINE_EXTRACT_HPP

#include "assert.hpp"
#include "nothing.hpp"
#include <memory>
#include <type_traits>

namespace eagine {
//------------------------------------------------------------------------------
template <typename T>
static constexpr auto extract(T* ptr) noexcept -> T& {
    return EAGINE_CONSTEXPR_ASSERT(bool(ptr), *ptr);
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr auto
extract_or(T* ptr, std::remove_const_t<T>& fallback) noexcept -> T& {
    return bool(ptr) ? *ptr : fallback;
}
//------------------------------------------------------------------------------
template <typename T, typename F>
static constexpr auto extract_or(T* ptr, F&& fallback)
  -> std::enable_if_t<std::is_convertible_v<F, T>, T> {
    return bool(ptr) ? *ptr : T{std::forward<F>(fallback)};
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr auto extract(std::shared_ptr<T>& ptr) noexcept -> T& {
    return EAGINE_CONSTEXPR_ASSERT(bool(ptr), *ptr);
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr auto extract(const std::shared_ptr<T>& ptr) noexcept
  -> const T& {
    return EAGINE_CONSTEXPR_ASSERT(bool(ptr), *ptr);
}
//------------------------------------------------------------------------------
template <typename T>
static constexpr auto
extract_or(std::shared_ptr<T>& ptr, std::remove_const_t<T>& fallback) noexcept
  -> T& {
    return bool(ptr) ? *ptr : fallback;
}
//------------------------------------------------------------------------------
template <typename T, typename F>
static constexpr auto extract_or(std::shared_ptr<T>& ptr, F&& fallback)
  -> std::enable_if_t<std::is_convertible_v<F, T>, T> {
    return bool(ptr) ? *ptr : T{std::forward<F>(fallback)};
}
//------------------------------------------------------------------------------
template <typename T, typename D>
static constexpr auto extract(std::unique_ptr<T, D>& ptr) noexcept -> T& {
    return EAGINE_CONSTEXPR_ASSERT(bool(ptr), *ptr);
}
//------------------------------------------------------------------------------
template <typename T, typename D>
static constexpr auto extract(const std::unique_ptr<T, D>& ptr) noexcept
  -> const T& {
    return EAGINE_CONSTEXPR_ASSERT(bool(ptr), *ptr);
}
//------------------------------------------------------------------------------
template <typename T, typename D>
static constexpr auto extract_or(
  std::unique_ptr<T, D>& ptr,
  std::remove_const_t<T>& fallback) noexcept -> T& {
    return bool(ptr) ? *ptr : fallback;
}
//------------------------------------------------------------------------------
template <typename T, typename D, typename F>
static constexpr auto extract_or(std::unique_ptr<T, D>& ptr, F&& fallback)
  -> std::enable_if_t<std::is_convertible_v<F, T>, T> {
    return bool(ptr) ? *ptr : T{std::forward<F>(fallback)};
}
//------------------------------------------------------------------------------
template <typename Outcome>
struct ok_traits {
    static constexpr auto nok_info(const Outcome&) noexcept -> nothing_t {
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
    constexpr ok(Outcome&& outcome) noexcept(noexcept(std::declval<Outcome&&>()))
      : _outcome{std::move(outcome)} {}

    explicit constexpr
    operator bool() noexcept(noexcept(bool(std::declval<Outcome&>()))) {
        return bool(_outcome);
    }

    explicit constexpr operator bool() const
      noexcept(noexcept(bool(std::declval<const Outcome&>()))) {
        return bool(_outcome);
    }

    constexpr auto get() noexcept(noexcept(extract(_outcome)))
      -> decltype(extract(_outcome)) {
        return extract(_outcome);
    }

    constexpr auto get() const noexcept(noexcept(extract(_outcome)))
      -> decltype(extract(_outcome)) {
        return extract(_outcome);
    }

    constexpr operator decltype(extract(std::declval<Outcome&>()))() noexcept(
      noexcept(extract(_outcome))) {
        return extract(_outcome);
    }

    constexpr operator decltype(extract(std::declval<const Outcome&>()))() const
      noexcept(noexcept(extract(_outcome))) {
        return extract(_outcome);
    }

    constexpr auto nok() const noexcept {
        return _traits::nok_info(_outcome);
    }

    constexpr auto operator!() const noexcept {
        return _traits::nok_info(_outcome);
    }
};
//------------------------------------------------------------------------------
template <typename Outcome>
auto extract(const ok<Outcome>& x) noexcept -> const auto& {
    return x.get();
}
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
