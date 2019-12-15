/**
 *  @file eagine/enum_class.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_ENUM_CLASS_HPP
#define EAGINE_ENUM_CLASS_HPP

#include "assert.hpp"
#include "mp_list.hpp"
#include <tuple>
#include <type_traits>

namespace eagine {

template <typename T, typename ClassList>
struct enum_value;

template <typename T, typename... Classes>
struct enum_value<T, mp_list<Classes...>> {
    using type = enum_value;

    using value_type = T;

    const T value;

    constexpr inline enum_value(T val) noexcept
      : value(val) {
    }

    explicit constexpr inline operator T() const noexcept {
        return value;
    }

    explicit constexpr inline operator bool() const noexcept {
        return true;
    }

    constexpr inline bool operator!() const noexcept {
        return false;
    }
};

template <typename T, typename ClassList>
struct opt_enum_value;

template <typename T, typename... Classes>
struct opt_enum_value<T, mp_list<Classes...>> {
    using type = opt_enum_value;

    using value_type = T;

    const T value{};
    const bool is_valid{false};

    constexpr inline opt_enum_value(T val, bool valid) noexcept
      : value(val)
      , is_valid{valid} {
    }

    constexpr inline opt_enum_value(std::tuple<T, bool> init) noexcept
      : value(std::get<0>(init))
      , is_valid{std::get<1>(init)} {
    }

    explicit constexpr inline operator T() const noexcept {
        return value;
    }

    explicit constexpr inline operator bool() const noexcept {
        return is_valid;
    }

    constexpr inline bool operator!() const noexcept {
        return !is_valid;
    }
};

template <typename T>
struct no_enum_value {
    using type = no_enum_value;

    using value_type = T;

    const T value{};

    explicit constexpr inline operator T() const noexcept {
        return value;
    }

    explicit constexpr inline operator bool() const noexcept {
        return false;
    }

    constexpr inline bool operator!() const noexcept {
        return true;
    }
};

template <unsigned LibId>
struct any_enum_value;

template <typename Self, typename T, unsigned LibId, unsigned Id>
struct enum_class {
    using type = enum_class;

    using value_type = T;

    static constexpr const unsigned lib_id = LibId;
    static constexpr const unsigned id = Id;

    value_type _value{};

    enum_class() = default;

    template <
      typename Classes,
      typename = std::enable_if_t<mp_contains<Classes, Self>::value>>
    constexpr inline enum_class(enum_value<T, Classes> ev) noexcept
      : _value(ev.value) {
    }

    template <
      typename Classes,
      typename = std::enable_if_t<mp_contains<Classes, Self>::value>>
    constexpr inline enum_class(opt_enum_value<T, Classes> ev) noexcept
      : _value(ev.value) {
        EAGINE_ASSERT(ev.is_valid);
    }

    constexpr inline enum_class(no_enum_value<T>) noexcept {
        EAGINE_UNREACHABLE();
    }

    constexpr enum_class(const any_enum_value<LibId>& aev) noexcept
      : _value(static_cast<T>(aev._value)) {
        EAGINE_ASSERT(aev._type_id == Id);
    }

    explicit constexpr inline enum_class(value_type value) noexcept
      : _value(value) {
    }

    constexpr inline operator Self() const noexcept {
        return Self(_value);
    }

    explicit constexpr inline operator value_type() const noexcept {
        return _value;
    }

    friend constexpr inline bool operator==(
      enum_class a, enum_class b) noexcept {
        return a._value == b._value;
    }

    friend constexpr inline bool operator!=(
      enum_class a, enum_class b) noexcept {
        return a._value != b._value;
    }
};

template <typename T>
struct is_enum_class : std::false_type {};

template <typename Self, typename T, unsigned LibId, unsigned Id>
struct is_enum_class<enum_class<Self, T, LibId, Id>> : std::true_type {};

template <typename T>
constexpr bool is_enum_class_v = is_enum_class<T>::value;

template <unsigned LibId>
struct any_enum_class {
    unsigned _type_id;

    constexpr inline any_enum_class() noexcept
      : _type_id(~unsigned(0)) {
    }

    template <typename Self, typename T, unsigned Id>
    constexpr inline any_enum_class(
      const enum_class<Self, T, LibId, Id>&) noexcept
      : _type_id(Id) {
    }

    constexpr inline any_enum_class(const any_enum_value<LibId>& aev) noexcept
      : _type_id(aev._type_id) {
    }

    explicit constexpr inline operator bool() const noexcept {
        return _type_id != ~unsigned(0);
    }

    constexpr inline bool operator!() const noexcept {
        return _type_id == ~unsigned(0);
    }

    friend bool operator==(
      const any_enum_class& a, const any_enum_class& b) noexcept {
        return a._type_id == b._type_id;
    }

    friend bool operator!=(
      const any_enum_class& a, const any_enum_class& b) noexcept {
        return a._type_id != b._type_id;
    }
};

template <unsigned LibId>
struct any_enum_value {
    long _value{0};
    unsigned _type_id;

    constexpr inline any_enum_value() noexcept
      : _type_id(~unsigned(0)) {
    }

    template <typename Self, typename T, unsigned Id>
    constexpr inline any_enum_value(enum_class<Self, T, LibId, Id> v) noexcept
      : _value(long(v._value))
      , _type_id(Id) {
    }

    explicit constexpr inline operator bool() const noexcept {
        return _type_id != ~unsigned(0);
    }

    constexpr inline bool operator!() const noexcept {
        return _type_id == ~unsigned(0);
    }

    friend bool operator==(
      const any_enum_value& a, const any_enum_value& b) noexcept {
        return (a._value == b._value) && (a._type_id == b._type_id);
    }

    friend bool operator!=(
      const any_enum_value& a, const any_enum_value& b) noexcept {
        return (a._value != b._value) || (a._type_id != b._type_id);
    }
};

template <unsigned LibId>
static constexpr inline bool same_enum_class(
  any_enum_class<LibId> a, any_enum_class<LibId> b) noexcept {
    return a._type_id == b._type_id;
}

} // namespace eagine

#endif // EAGINE_ENUM_CLASS_HPP
