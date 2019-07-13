/**
 *  @file eagine/outcome.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_OUTCOME_HPP
#define EAGINE_OUTCOME_HPP

#include "branch_predict.hpp"
#include "deferred_handler.hpp"
#include "selector.hpp"
#include <cassert>
#include <utility>

namespace eagine {

template <typename T>
class basic_outcome_storage;

template <typename T>
class basic_outcome_storage {
private:
    T _val;

public:
    constexpr basic_outcome_storage() noexcept
      : _val{} {
    }

    constexpr basic_outcome_storage(T val) noexcept
      : _val(std::move(val)) {
    }

    constexpr const T& get() const noexcept {
        return _val;
    }

    T& ref() noexcept {
        return _val;
    }

    template <typename Func>
    void apply(Func func) noexcept {
        try {
            func(_val);
        } catch(...) {
        }
    }
};

template <typename T>
class basic_outcome_storage<T&> {
private:
    T* _ref = nullptr;

public:
    constexpr basic_outcome_storage() noexcept = default;

    basic_outcome_storage(T& ref) noexcept
      : _ref(&ref) {
    }

    T& get() const noexcept {
        EAGINE_ASSERT(_ref != nullptr);
        return *_ref;
    }

    template <typename Func>
    void apply(Func func) noexcept {
        try {
            func(get());
        } catch(...) {
        }
    }
};

template <
  typename T,
  typename ErrorData,
  typename HandlerPolicy = default_deferred_handler_policy<ErrorData>,
  template <class, class> class Handler = deferred_handler>
class basic_outcome;

template <typename ErrorData, typename HandlerPolicy>
class basic_outcome<void, ErrorData, HandlerPolicy, cancelled_handler> {
protected:
    cancelled_handler<ErrorData, HandlerPolicy> _handler;

public:
    basic_outcome() = default;
    basic_outcome(basic_outcome&&) noexcept(
      std::is_nothrow_move_constructible_v<
        cancelled_handler<ErrorData, HandlerPolicy>>) = default;
    basic_outcome(const basic_outcome&) = delete;
    basic_outcome& operator=(basic_outcome&&) = delete;
    basic_outcome& operator=(const basic_outcome&) = delete;
    ~basic_outcome() = default;

    constexpr basic_outcome(
      cancelled_handler<ErrorData, HandlerPolicy>&& handler) noexcept
      : _handler(std::move(handler)) {
    }

    ErrorData& handler_data() noexcept {
        return _handler.data();
    }

    const ErrorData& handler_data() const noexcept {
        return _handler.data();
    }

    bool failed() const noexcept {
        return bool(_handler);
    }

    bool succeeded() const noexcept {
        return !_handler;
    }

    bool done_without_error() noexcept {
        return !_handler.cancel();
    }
};

template <typename T, typename ErrorData, typename HandlerPolicy>
class basic_outcome<T, ErrorData, HandlerPolicy, cancelled_handler>
  : public basic_outcome<void, ErrorData, HandlerPolicy, cancelled_handler> {
private:
    using _base =
      basic_outcome<void, ErrorData, HandlerPolicy, cancelled_handler>;
    basic_outcome_storage<T> _value;

public:
    basic_outcome(basic_outcome&&) noexcept(
      std::is_nothrow_move_constructible_v<
        cancelled_handler<ErrorData, HandlerPolicy>>) = default;
    basic_outcome(const basic_outcome&) = delete;
    basic_outcome& operator=(basic_outcome&&) = delete;
    basic_outcome& operator=(const basic_outcome&) = delete;
    ~basic_outcome() = default;

    basic_outcome(
      cancelled_handler<ErrorData, HandlerPolicy>&& handler,
      basic_outcome_storage<T>&& val_stor) noexcept
      : _base(std::move(handler))
      , _value(std::move(val_stor)) {
    }

    T value() noexcept {
        EAGINE_ASSERT(this->succeeded());
        return _value.get();
    }

    T value_or(const T& fallback) noexcept {
        return EAGINE_LIKELY(this->succeeded()) ? _value.get() : fallback;
    }

    T&& rvalue() noexcept {
        EAGINE_ASSERT(this->succeeded());
        return std::move(_value.ref());
    }

    T&& release_value() noexcept {
        EAGINE_ASSERT(this->succeeded());
        return std::move(_value.ref());
    }

    operator T &&() noexcept {
        return rvalue();
    }

    template <typename Func>
    void then(Func func) noexcept {
        if(EAGINE_LIKELY(this->succeeded())) {
            _value.apply(func);
        }
    }
};

template <typename ErrorData, typename HandlerPolicy>
class basic_outcome<void, ErrorData, HandlerPolicy, deferred_handler> {
protected:
    deferred_handler<ErrorData, HandlerPolicy> _handler;

public:
    basic_outcome() = default;
    basic_outcome(basic_outcome&&) noexcept(
      std::is_nothrow_move_constructible_v<
        cancelled_handler<ErrorData, HandlerPolicy>>) = default;
    basic_outcome(const basic_outcome&) = delete;
    basic_outcome& operator=(basic_outcome&&) = delete;
    basic_outcome& operator=(const basic_outcome&) = delete;
    ~basic_outcome() = default;

    constexpr basic_outcome(
      deferred_handler<ErrorData, HandlerPolicy>&& handler) noexcept
      : _handler(std::move(handler)) {
    }

    template <typename T>
      basic_outcome<T, ErrorData, HandlerPolicy, deferred_handler> add(
        T value) &&
      noexcept;

    deferred_handler<ErrorData, HandlerPolicy> release_handler() noexcept {
        return std::move(_handler);
    }

    ErrorData& handler_data() noexcept {
        return _handler.data();
    }

    const ErrorData& handler_data() const noexcept {
        return _handler.data();
    }

    basic_outcome<void, ErrorData, HandlerPolicy, cancelled_handler>
    ignore_error() noexcept {
        return cancelled_handler<ErrorData, HandlerPolicy>(
          std::move(_handler.data()), _handler.cancel());
    }

    void trigger_error() {
        _handler.trigger();
    }

    template <typename HandlerFunc>
    auto handle_error(HandlerFunc handler_func) {
        _handler.cancel();
        return handler_func(_handler.data());
    }

    bool failed() const noexcept {
        return bool(_handler);
    }

    bool succeeded() const noexcept {
        return !_handler;
    }

    bool done_without_error() noexcept {
        return !_handler.cancel();
    }
};

template <typename T, typename ErrorData, typename HandlerPolicy>
class basic_outcome<T, ErrorData, HandlerPolicy, deferred_handler>
  : public basic_outcome<void, ErrorData, HandlerPolicy, deferred_handler> {
private:
    using _base =
      basic_outcome<void, ErrorData, HandlerPolicy, deferred_handler>;
    basic_outcome_storage<T> _value;

public:
    basic_outcome(basic_outcome&&) noexcept(
      std::is_nothrow_move_constructible_v<
        cancelled_handler<ErrorData, HandlerPolicy>>) = default;
    basic_outcome(const basic_outcome&) = delete;
    basic_outcome& operator=(basic_outcome&&) = delete;
    basic_outcome& operator=(const basic_outcome&) = delete;
    ~basic_outcome() = default;

    constexpr basic_outcome(
      deferred_handler<ErrorData, HandlerPolicy>&& handler) noexcept
      : _base(std::move(handler)) {
    }

    basic_outcome(T value) noexcept
      : _value(value) {
    }

    basic_outcome(
      deferred_handler<ErrorData, HandlerPolicy>&& handler, T&& val) noexcept
      : _base(std::move(handler))
      , _value(std::move(val)) {
    }

    basic_outcome(
      basic_outcome<void, ErrorData, HandlerPolicy>&& that,
      T&& val,
      selector<0>) noexcept
      : _base(std::move(that))
      , _value(std::move(val)) {
    }

    basic_outcome(
      basic_outcome<void, ErrorData, HandlerPolicy>&& that,
      const T& val) noexcept
      : _base(std::move(that))
      , _value(val) {
    }

    basic_outcome<T, ErrorData, HandlerPolicy, cancelled_handler>
    ignore_error() noexcept {
        return {cancelled_handler<ErrorData, HandlerPolicy>(
                  std::move(this->_handler.data()), this->_handler.cancel()),
                std::move(_value)};
    }

    void trigger_error() {
        this->_handler.trigger();
    }

    template <typename HandlerFunc>
    auto handle_error(HandlerFunc handler_func) {
        this->_handler.cancel();
        return handler_func(this->_handler.data());
    }

    T value() {
        trigger_error();
        return _value.get();
    }

    T&& rvalue() {
        trigger_error();
        return std::move(_value.ref());
    }

    T&& release_value() noexcept {
        EAGINE_ASSERT(this->succeeded());
        return std::move(_value.ref());
    }

    operator T &&() {
        return rvalue();
    }

    template <typename Func>
    void then(Func func) noexcept {
        if(this->succeeded()) {
            _value.apply(func);
        }
    }
};

template <typename ErrorData, typename HandlerPolicy>
  template <typename T>
  inline basic_outcome<T, ErrorData, HandlerPolicy, deferred_handler>
  basic_outcome<void, ErrorData, HandlerPolicy, deferred_handler>::add(
    T value) &&
  noexcept {
    return {std::move(*this), std::move(value), selector<0>()};
}

template <typename T, typename U, typename ErrorData, typename HandlerPolicy>
static inline basic_outcome<T, ErrorData, HandlerPolicy>
outcome_cast(basic_outcome<U, ErrorData, HandlerPolicy>&& that) noexcept(
  std::is_nothrow_move_constructible_v<T>&& noexcept(T(std::declval<U>()))) {
    if(that.failed()) {
        return {that.release_handler()};
    }
    return {T(that.release_value())};
}

template <typename T, typename U, typename ErrorData, typename HandlerPolicy>
static inline basic_outcome<T, ErrorData, HandlerPolicy> outcome_conversion(
  basic_outcome<U, ErrorData, HandlerPolicy>&& that,
  T (*convert)(U) noexcept) noexcept {
    if(that.failed()) {
        return {that.release_handler()};
    }
    return {convert(that.release_value())};
}

template <typename T, typename ErrorData, typename HandlerPolicy, typename Func>
static inline basic_outcome<T, ErrorData, HandlerPolicy>&& operator|(
  basic_outcome<T, ErrorData, HandlerPolicy>&& bo, Func func) noexcept {
    bo.then(func);
    return std::move(bo);
}

template <typename T, typename ErrorData, typename HandlerPolicy>
class basic_positive_outcome
  : public basic_outcome<T, ErrorData, HandlerPolicy> {
public:
    basic_positive_outcome(
      basic_outcome<T, ErrorData, HandlerPolicy>&& o) noexcept
      : basic_outcome<T, ErrorData, HandlerPolicy>(std::move(o)) {
    }

    explicit operator bool() const noexcept {
        return this->succeeded();
    }

    bool operator!() const noexcept {
        return this->failed();
    }
};

template <typename T, typename ErrorData, typename HandlerPolicy>
static inline basic_positive_outcome<T, ErrorData, HandlerPolicy> success(
  basic_outcome<T, ErrorData, HandlerPolicy>&& o) noexcept {
    return std::move(o);
}

template <typename T, typename ErrorData, typename HandlerPolicy>
class basic_negative_outcome
  : public basic_outcome<T, ErrorData, HandlerPolicy> {
public:
    basic_negative_outcome(
      basic_outcome<T, ErrorData, HandlerPolicy>&& o) noexcept
      : basic_outcome<T, ErrorData, HandlerPolicy>(std::move(o)) {
    }

    explicit operator bool() const noexcept {
        return this->failed();
    }

    bool operator!() const noexcept {
        return this->succeeded();
    }
};

template <typename T, typename ErrorData, typename HandlerPolicy>
static inline basic_negative_outcome<T, ErrorData, HandlerPolicy> failure(
  basic_outcome<T, ErrorData, HandlerPolicy>&& o) noexcept {
    return std::move(o);
}

} // namespace eagine

#endif // EAGINE_OUTCOME_HPP
