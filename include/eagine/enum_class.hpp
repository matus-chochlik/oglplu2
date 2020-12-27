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
#include "identifier_t.hpp"
#include "iterator.hpp"
#include "mp_list.hpp"
#include "nothing.hpp"
#include "type_identity.hpp"
#include "wrapping_container.hpp"
#include <tuple>
#include <type_traits>

namespace eagine {
//------------------------------------------------------------------------------
template <typename T, typename ClassList, typename Tag = nothing_t>
struct enum_value;

template <typename T, typename... Classes, typename Tag>
struct enum_value<T, mp_list<Classes...>, Tag> {
    using type = enum_value;

    using value_type = T;
    using tag_type = Tag;

    const T value{};

    constexpr enum_value(T val) noexcept
      : value{val} {}

    explicit constexpr operator T() const noexcept {
        return value;
    }

    explicit constexpr operator bool() const noexcept {
        return true;
    }
};

template <typename... Classes, typename Tag>
struct enum_value<bool, mp_list<Classes...>, Tag> {
    using type = enum_value;

    using value_type = bool;
    using tag_type = Tag;

    const bool value{false};

    constexpr enum_value(bool val) noexcept
      : value{val} {}

    explicit constexpr operator bool() const noexcept {
        return value;
    }
};
//------------------------------------------------------------------------------
template <typename T, typename ClassList, typename Tag = nothing_t>
struct opt_enum_value;

template <typename T, typename... Classes, typename Tag>
struct opt_enum_value<T, mp_list<Classes...>, Tag> {
    using type = opt_enum_value;

    using value_type = T;
    using tag_type = Tag;

    const T value{};
    const bool is_valid{false};

    constexpr opt_enum_value(T val, bool valid) noexcept
      : value(val)
      , is_valid{valid} {}

    constexpr opt_enum_value(std::tuple<T, bool> init) noexcept
      : value(std::get<0>(init))
      , is_valid{std::get<1>(init)} {}

    explicit constexpr operator T() const noexcept {
        return value;
    }

    explicit constexpr operator bool() const noexcept {
        return is_valid;
    }
};

template <typename... Classes, typename Tag>
struct opt_enum_value<bool, mp_list<Classes...>, Tag> {
    using type = opt_enum_value;

    using value_type = bool;
    using tag_type = Tag;

    const bool value{};
    const bool is_valid{false};

    constexpr opt_enum_value(bool val, bool valid) noexcept
      : value(val)
      , is_valid{valid} {}

    constexpr opt_enum_value(std::tuple<bool, bool> init) noexcept
      : value(std::get<0>(init))
      , is_valid{std::get<1>(init)} {}

    explicit constexpr operator bool() const noexcept {
        return is_valid && value;
    }
};
//------------------------------------------------------------------------------
template <typename T, typename Tag = nothing_t>
struct no_enum_value {
    using type = no_enum_value;

    using value_type = T;
    using tag_type = Tag;

    const T value{};

    explicit constexpr operator T() const noexcept {
        return value;
    }

    explicit constexpr operator bool() const noexcept {
        return false;
    }
};

template <typename Tag>
struct no_enum_value<bool, Tag> {
    using type = no_enum_value;

    using value_type = bool;
    using tag_type = Tag;

    explicit constexpr operator bool() const noexcept {
        return false;
    }
};
//------------------------------------------------------------------------------
template <identifier_t LibId>
struct any_enum_value;

template <typename Self, typename T, identifier_t LibId, identifier_t Id>
struct enum_class {
    using type = enum_class;

    using value_type = T;

    static constexpr const identifier_t lib_id = LibId;
    static constexpr const identifier_t id = Id;

    value_type _value{};

    enum_class() = default;

    template <
      typename Classes,
      typename Tag,
      typename = std::enable_if_t<mp_contains_v<Classes, Self>>>
    constexpr enum_class(enum_value<T, Classes, Tag> ev) noexcept
      : _value{ev.value} {}

    template <
      typename Classes,
      typename Tag,
      typename = std::enable_if_t<mp_contains_v<Classes, Self>>>
    constexpr enum_class(opt_enum_value<T, Classes, Tag> ev) noexcept
      : _value{ev.value} {
        EAGINE_ASSERT(ev.is_valid);
    }

    constexpr enum_class(no_enum_value<T>) noexcept {
        EAGINE_UNREACHABLE();
    }

    constexpr enum_class(const any_enum_value<LibId>& aev) noexcept
      : _value{static_cast<T>(aev._value)} {
        EAGINE_ASSERT(aev._type_id == Id);
    }

    explicit constexpr enum_class(value_type value) noexcept
      : _value{value} {}

    constexpr operator Self() const noexcept {
        return Self{_value};
    }

    explicit constexpr operator value_type() const noexcept {
        return _value;
    }

    friend constexpr auto operator==(enum_class a, enum_class b) noexcept {
        return a._value == b._value;
    }

    friend constexpr auto operator!=(enum_class a, enum_class b) noexcept {
        return a._value != b._value;
    }

    struct transform {
        constexpr auto operator()(T value) noexcept {
            return enum_class<Self, T, LibId, Id>{value};
        }
    };
};
//------------------------------------------------------------------------------
template <typename T>
struct is_enum_class : std::false_type {};

template <typename T>
constexpr bool is_enum_class_v = is_enum_class<T>::value;

template <typename Self, typename T, identifier_t LibId, identifier_t Id>
struct is_enum_class<enum_class<Self, T, LibId, Id>> : std::true_type {
    static_assert(std::is_base_of_v<enum_class<Self, T, LibId, Id>, Self>);
};
//------------------------------------------------------------------------------
template <typename Class, typename Value>
struct is_enum_class_value : std::false_type {};

template <typename C, typename V>
constexpr auto is_enum_class_value_v =
  is_enum_class_value<type_t<C>, type_t<V>>::value;

template <
  typename Self,
  typename T,
  typename Tag,
  identifier_t LibId,
  identifier_t Id>
struct is_enum_class_value<enum_class<Self, T, LibId, Id>, no_enum_value<T, Tag>>
  : std::true_type {
    static_assert(std::is_base_of_v<enum_class<Self, T, LibId, Id>, Self>);
};

template <
  typename Self,
  typename T,
  typename Classes,
  typename Tag,
  identifier_t LibId,
  identifier_t Id>
struct is_enum_class_value<
  enum_class<Self, T, LibId, Id>,
  enum_value<T, Classes, Tag>> : mp_contains<Classes, Self> {
    static_assert(std::is_base_of_v<enum_class<Self, T, LibId, Id>, Self>);
};

template <
  typename Self,
  typename T,
  typename Classes,
  typename Tag,
  identifier_t LibId,
  identifier_t Id>
struct is_enum_class_value<
  enum_class<Self, T, LibId, Id>,
  opt_enum_value<T, Classes, Tag>> : mp_contains<Classes, Self> {
    static_assert(std::is_base_of_v<enum_class<Self, T, LibId, Id>, Self>);
};
//------------------------------------------------------------------------------
template <identifier_t LibId>
struct any_enum_class {

    identifier_t _type_id{~identifier_t(0)};

    constexpr any_enum_class() noexcept = default;

    template <typename Self, typename T, identifier_t Id>
    constexpr any_enum_class(const enum_class<Self, T, LibId, Id>&) noexcept
      : _type_id{Id} {
        static_assert(std::is_base_of_v<enum_class<Self, T, LibId, Id>, Self>);
    }

    constexpr any_enum_class(const any_enum_value<LibId>& aev) noexcept
      : _type_id{aev._type_id} {}

    explicit constexpr operator bool() const noexcept {
        return _type_id != ~identifier_t(0);
    }

    friend auto
    operator==(const any_enum_class& a, const any_enum_class& b) noexcept {
        return a._type_id == b._type_id;
    }

    friend auto
    operator!=(const any_enum_class& a, const any_enum_class& b) noexcept {
        return a._type_id != b._type_id;
    }
};

template <identifier_t LibId>
struct any_enum_value {
    long _value{0};
    identifier_t _type_id{~identifier_t(0)};

    constexpr any_enum_value() noexcept = default;

    template <typename Self, typename T, identifier_t Id>
    constexpr any_enum_value(enum_class<Self, T, LibId, Id> v) noexcept
      : _value{long(v._value)}
      , _type_id{Id} {
        static_assert(std::is_base_of_v<enum_class<Self, T, LibId, Id>, Self>);
    }

    explicit constexpr operator bool() const noexcept {
        return _type_id != ~identifier_t(0);
    }

    friend auto
    operator==(const any_enum_value& a, const any_enum_value& b) noexcept {
        return (a._value == b._value) && (a._type_id == b._type_id);
    }

    friend auto
    operator!=(const any_enum_value& a, const any_enum_value& b) noexcept {
        return (a._value != b._value) || (a._type_id != b._type_id);
    }
};

template <identifier_t LibId>
static constexpr inline auto
same_enum_class(any_enum_class<LibId> a, any_enum_class<LibId> b) noexcept {
    return a._type_id == b._type_id;
}
//------------------------------------------------------------------------------
template <typename EnumClass, typename Container>
class enum_class_container
  : public basic_wrapping_container<
      Container,
      EnumClass,
      typename EnumClass::value_type> {
    using base = basic_wrapping_container<
      Container,
      EnumClass,
      typename EnumClass::value_type>;

public:
    using base::base;

    constexpr auto raw_enums() noexcept {
        return this->raw_items();
    }

    constexpr auto raw_enums() const noexcept {
        return this->raw_items();
    }
};
//------------------------------------------------------------------------------
template <typename EnumClass>
using enum_class_span =
  enum_class_container<EnumClass, span<typename EnumClass::value_type>>;

template <typename EnumClass>
using enum_class_view =
  enum_class_container<EnumClass, span<const typename EnumClass::value_type>>;

template <typename EnumClass, std::size_t N>
using enum_class_array =
  enum_class_container<EnumClass, std::array<typename EnumClass::value_type, N>>;
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_ENUM_CLASS_HPP
