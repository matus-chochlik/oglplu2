/**
 *  @file eagine/valid_if/base.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALID_IF_BASE_HPP
#define EAGINE_VALID_IF_BASE_HPP

#include "../assert.hpp"
#include "../branch_predict.hpp"
#include <sstream>
#include <stdexcept>
#include <type_traits>
#include <utility>

namespace eagine {

template <typename T>
class basic_valid_if_value {
public:
    constexpr basic_valid_if_value(T value) noexcept(
      noexcept(T(std::declval<T&&>())))
      : _value{std::move(value)} {
    }

    constexpr basic_valid_if_value() noexcept = default;

    constexpr basic_valid_if_value(basic_valid_if_value&&) noexcept(
      std::is_nothrow_move_constructible_v<T>) = default;

    constexpr basic_valid_if_value(const basic_valid_if_value&) noexcept(
      std::is_nothrow_copy_constructible_v<T>) = default;

    basic_valid_if_value& operator=(basic_valid_if_value&&) noexcept(
      std::is_nothrow_move_assignable_v<T>) = default;
    basic_valid_if_value& operator=(const basic_valid_if_value&) noexcept(
      std::is_nothrow_copy_assignable_v<T>) = default;

    ~basic_valid_if_value() noexcept = default;

    basic_valid_if_value& operator=(const T& v) {
        _value = v;
        return *this;
    }

    basic_valid_if_value& operator=(T&& v) {
        _value = std::move(v);
        return *this;
    }

protected:
    T& _ref_value() noexcept {
        return _value;
    }

    constexpr inline const T& _get_value() const noexcept {
        return _value;
    }

private:
    T _value = {};
};

template <typename T, typename Policy, typename DoLog, typename... P>
class basic_valid_if
  : public basic_valid_if_value<T>
  , private Policy
  , private DoLog {
private:
    const DoLog& _do_log() const noexcept {
        return *this;
    }

    explicit constexpr basic_valid_if(Policy plcy) noexcept
      : Policy(plcy)
      , DoLog(policy()) {
    }

public:
    const Policy& policy() const noexcept {
        return *this;
    }
    constexpr basic_valid_if() noexcept
      : DoLog(policy()) {
    }

    constexpr inline basic_valid_if(T val) noexcept
      : basic_valid_if_value<T>(std::move(val))
      , DoLog(policy()) {
    }

    constexpr inline basic_valid_if(T val, Policy plcy) noexcept
      : basic_valid_if_value<T>(std::move(val))
      , Policy(std::move(plcy))
      , DoLog(policy()) {
    }

    constexpr basic_valid_if(const basic_valid_if& that)
      : basic_valid_if_value<T>(
          static_cast<const basic_valid_if_value<T>&>(that))
      , Policy(static_cast<const Policy&>(that))
      , DoLog(policy()) {
    }

    basic_valid_if(basic_valid_if&& that) noexcept(
      std::is_nothrow_move_constructible_v<T>)
      : basic_valid_if_value<T>(static_cast<basic_valid_if_value<T>&&>(that))
      , Policy(static_cast<Policy&&>(that))
      , DoLog(policy()) {
    }

    basic_valid_if& operator=(const basic_valid_if& that) {
        if(this != std::addressof(that)) {
            static_cast<basic_valid_if_value<T>&>(*this) =
              static_cast<const basic_valid_if_value<T>&>(that);
            static_cast<Policy&>(*this) = static_cast<const Policy&>(that);
            static_cast<DoLog&>(*this) = DoLog(policy());
        }
        return *this;
    }

    basic_valid_if& operator=(basic_valid_if&& that) noexcept(
      std::is_nothrow_move_assignable_v<T>) {
        if(this != std::addressof(that)) {
            static_cast<basic_valid_if_value<T>&>(*this) =
              static_cast<basic_valid_if_value<T>&&>(that);
            static_cast<Policy&>(*this) = static_cast<Policy&&>(that);
            static_cast<DoLog&>(*this) = DoLog(policy());
        }
        return *this;
    }

    basic_valid_if& operator=(const T& value) {
        static_cast<basic_valid_if_value<T>&>(*this) =
          static_cast<const basic_valid_if_value<T>&>(value);
        return *this;
    }

    basic_valid_if& operator=(T& value) {
        static_cast<basic_valid_if_value<T>&>(*this) =
          static_cast<basic_valid_if_value<T>&&>(value);
        return *this;
    }

    ~basic_valid_if() noexcept = default;

    constexpr bool is_valid(const T& val, P... p) const noexcept {
        return policy()(val, p...);
    }

    constexpr bool is_valid(P... p) const noexcept {
        return is_valid(this->_get_value(), p...);
    }

    constexpr bool has_value(P... p) const noexcept {
        return is_valid(p...);
    }

    constexpr friend bool operator==(
      const basic_valid_if& a, const basic_valid_if& b) noexcept {
        return (a._get_value() == b._get_value()) && a.is_valid() &&
               b.is_valid();
    }

    template <typename Log>
    void log_invalid(Log& log, const T& v, P... p) const {
        EAGINE_ASSERT(!is_valid(v, p...));
        _do_log()(log, v, p...);
    }

    template <typename Log>
    void log_invalid(Log& log, P... p) const {
        log_invalid(log, this->_get_value(), p...);
    }

    template <typename Func>
    basic_valid_if& call_if_invalid(Func func, P... p) {
        if(!is_valid(p...)) {
            func(_do_log(), this->_get_value(), p...);
        }
        return *this;
    }

    void throw_if_invalid(P... p) const {
        if(!is_valid(p...)) {
            std::stringstream ss;
            log_invalid(ss, p...);
            throw std::runtime_error(ss.str());
        }
    }

    T& value(P... p) {
        throw_if_invalid(p...);
        return this->_ref_value();
    }

    const T& value(P... p) const {
        throw_if_invalid(p...);
        return this->_get_value();
    }

    auto& value_or(T& fallback, P... p) noexcept {
        return EAGINE_LIKELY(is_valid(p...)) ? this->_ref_value() : fallback;
    }

    constexpr const auto& value_or(const T& fallback, P... p) const noexcept {
        return EAGINE_LIKELY(is_valid(p...)) ? this->_get_value() : fallback;
    }

    constexpr const auto& value_anyway(P...) const noexcept {
        return this->_get_value();
    }

    constexpr auto& value_anyway(P...) noexcept {
        return this->_ref_value();
    }

    template <typename Func>
    std::enable_if_t<std::is_same_v<std::result_of_t<Func(T)>, void>> then(
      const Func& func, P... p) const {
        if(EAGINE_LIKELY(is_valid(p...))) {
            func(value(p...));
        }
    }

    template <typename Func>
    constexpr inline auto transformed(Func func, P... p) const noexcept {
        return func(this->_get_value(), is_valid(p...));
    }
};

} // namespace eagine

#endif // EAGINE_VALID_IF_BASE_HPP
