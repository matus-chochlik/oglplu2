/**
 *  @file eagine/reflect/enumerators.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_REFLECT_ENUMERATORS_HPP
#define EAGINE_REFLECT_ENUMERATORS_HPP

#include "../selector.hpp"
#include "../valid_if/decl.hpp"
#include "map_enumerators.hpp"
#include <cstdint>

namespace eagine {
//------------------------------------------------------------------------------
template <typename T, typename Selector>
constexpr inline auto enumerator_count(identity<T> id, Selector sel) noexcept
  -> std::enable_if_t<has_enumerator_mapping_v<T, Selector>, span_size_t> {
    return span_size_t(enumerator_mapping(id, sel).size());
}
//------------------------------------------------------------------------------
template <typename T>
constexpr inline auto enumerator_count(identity<T> id) noexcept {
    return enumerator_count(id, selector<0>());
}
//------------------------------------------------------------------------------
template <typename T>
constexpr auto enumerator_name(T value, identity<T> id = {}) noexcept {
    return enumerator_name(value, id, selector<0>());
}
//------------------------------------------------------------------------------
template <typename T, typename Selector>
inline auto enumerator_name(T enumerator, identity<T> id, Selector sel) noexcept
  -> std::enable_if_t<has_enumerator_mapping_v<T, Selector>, decl_name> {
    for(const auto& info : enumerator_mapping(id, sel)) {
        if(info.enumerator == enumerator) {
            return info.name;
        }
    }
    return {};
}
//------------------------------------------------------------------------------
template <typename T>
constexpr inline auto enumerator_value(T value, identity<T> = {}) noexcept {
    return static_cast<std::underlying_type_t<T>>(value);
}
//------------------------------------------------------------------------------
template <bool Signed>
struct enum_int_value_and_name {
    using value_type =
      std::conditional_t<Signed, std::intmax_t, std::uintmax_t>;

    constexpr enum_int_value_and_name() noexcept = default;

    template <typename T>
    constexpr enum_int_value_and_name(const enumerator_and_name<T>& src) noexcept
      : name{src.name}
      , value{static_cast<value_type>(src.enumerator)} {}

    const string_view name{};
    const value_type value{0};
};
//------------------------------------------------------------------------------
using signed_enum_value_and_name = enum_int_value_and_name<true>;
using unsigned_enum_value_and_name = enum_int_value_and_name<false>;
//------------------------------------------------------------------------------
template <typename T>
using enum_value_and_name =
  enum_int_value_and_name<std::is_signed_v<std::underlying_type_t<T>>>;
//------------------------------------------------------------------------------
template <typename T, typename Selector>
inline auto enumerator_info(T enumerator, identity<T> id, Selector sel) noexcept
  -> std::enable_if_t<
    has_enumerator_mapping_v<T, Selector>,
    optionally_valid<enum_value_and_name<T>>> {
    for(const auto& info : enumerator_mapping(id, sel)) {
        if(info.enumerator == enumerator) {
            return {enum_value_and_name<T>{info}, true};
        }
    }
    return {};
}
//------------------------------------------------------------------------------
template <typename T>
auto enumerator_info(T enumerator, identity<T> id = {}) noexcept {
    return enumerator_info(enumerator, id, selector<0>{});
}
//------------------------------------------------------------------------------
template <typename T, typename Selector>
inline auto from_value(
  std::underlying_type_t<T> value,
  identity<T> id,
  Selector sel) noexcept
  -> std::enable_if_t<has_enumerator_mapping_v<T, Selector>, optionally_valid<T>> {
    for(const auto& info : enumerator_mapping(id, sel)) {
        if(enumerator_value(info.enumerator, id) == value) {
            return {info.enumerator, true};
        }
    }
    return {};
}
//------------------------------------------------------------------------------
template <typename T>
constexpr inline auto
from_value(std::underlying_type_t<T> value, identity<T> id = {}) noexcept {
    return from_value(value, id, selector<0>());
}
//------------------------------------------------------------------------------
template <typename T, typename Selector>
inline auto from_string(string_view name, identity<T> id, Selector sel) noexcept
  -> std::enable_if_t<has_enumerator_mapping_v<T, Selector>, optionally_valid<T>> {
    for(const auto& info : enumerator_mapping(id, sel)) {
        if(are_equal(string_view(info.name), name)) {
            return {info.enumerator, true};
        }
    }
    return {};
}
//------------------------------------------------------------------------------
template <typename T>
inline auto from_string(string_view name, identity<T> id) noexcept -> std::
  enable_if_t<has_enumerator_mapping_v<T, selector<0>>, optionally_valid<T>> {
    return from_string(name, id, selector<0>());
}
//------------------------------------------------------------------------------
template <typename Function, typename T, typename Selector>
inline auto
for_each_enumerator(Function& function, identity<T> id, Selector sel) noexcept
  -> std::enable_if_t<has_enumerator_mapping_v<T, Selector>> {
    for(const auto& info : enumerator_mapping(id, sel)) {
        function(enum_value_and_name<T>{info});
    }
}
//------------------------------------------------------------------------------
template <typename Function, typename T>
inline auto for_each_enumerator(Function& function, identity<T> id) noexcept
  -> std::enable_if_t<has_enumerator_mapping_v<T, selector<0>>> {
    for_each_enumerator(function, id, selector<0>{});
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_REFLECT_ENUMERATORS_HPP
