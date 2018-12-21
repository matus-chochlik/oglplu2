/**
 *  @file eagine/tribool.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_TRIBOOL_HPP
#define EAGINE_TRIBOOL_HPP

namespace eagine {

enum class _tribool_value_t : unsigned char {
    _false = 0x00,
    _true = 0x01,
    _unknown = 0x02
};

struct indeterminate_t {};

constexpr static const indeterminate_t indeterminate = {};

class tribool;

class weakbool {
private:
    using _value_t = _tribool_value_t;
    _value_t _value;

    friend class tribool;

    constexpr explicit weakbool(_value_t value) noexcept
      : _value(value) {
    }

public:
    constexpr explicit operator bool() const noexcept {
        return _value != _value_t::_false;
    }

    constexpr bool operator!() const noexcept {
        return _value != _value_t::_true;
    }

    constexpr bool is(indeterminate_t) const noexcept {
        return _value == _value_t::_unknown;
    }
};

class tribool {
private:
    using _value_t = _tribool_value_t;
    _value_t _value{_value_t::_false};

public:
    constexpr tribool() noexcept = default;

    constexpr tribool(bool value) noexcept
      : _value(value ? _value_t::_true : _value_t::_false) {
    }

    constexpr tribool(indeterminate_t) noexcept
      : _value(_value_t::_unknown) {
    }

    constexpr tribool(bool value, bool is_unknown) noexcept
      : _value(
          is_unknown ? _value_t::_unknown
                     : value ? _value_t::_true : _value_t::_false) {
    }

    constexpr explicit operator bool() const noexcept {
        return _value == _value_t::_true;
    }

    constexpr bool operator!() const noexcept {
        return _value == _value_t::_false;
    }

    constexpr bool operator*() const noexcept {
        return _value == _value_t::_unknown;
    }

    constexpr weakbool operator~() const noexcept {
        return weakbool{_value};
    }

    constexpr bool is(indeterminate_t) const noexcept {
        return *(*this);
    }

    friend constexpr tribool operator==(tribool a, tribool b) noexcept {
        return {a._value == b._value, (*a || *b)};
    }

    friend constexpr tribool operator!=(tribool a, tribool b) noexcept {
        return {a._value != b._value, (*a || *b)};
    }
};

constexpr inline tribool operator&&(tribool a, tribool b) noexcept {
    return !a ? tribool{false}
              : a ? b : !b ? tribool{false} : tribool{indeterminate};
}

constexpr inline tribool operator||(tribool a, tribool b) noexcept {
    return a ? tribool{true}
             : !a ? b : b ? tribool{true} : tribool{indeterminate};
}

} // namespace eagine

#endif // EAGINE_TRIBOOL_HPP
