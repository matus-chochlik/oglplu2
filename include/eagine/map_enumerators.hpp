/**
 *  @file eagine/map_enumerators.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MAP_ENUMERATORS_HPP
#define EAGINE_MAP_ENUMERATORS_HPP

#include "selector.hpp"
#include "string_span.hpp"
#include "valid_if/decl.hpp"
#include <type_traits>
#include <utility>

namespace eagine {
//------------------------------------------------------------------------------
template <typename T>
struct enumerator_info {
    constexpr enumerator_info(string_view n, T e) noexcept
      : name{n}
      , enumerator{e} {
    }

    const string_view name;
    const T enumerator;
};
//------------------------------------------------------------------------------
template <typename T, std::size_t N>
using enumerator_map_type = std::array<enumerator_info<T>, N>;
//------------------------------------------------------------------------------
template <typename T, typename Selector>
struct does_have_enumerator_mapping {
private:
    template <
      typename X,
      typename = decltype(enumerator_mapping(identity<X>(), Selector()))>
    static std::true_type _test(X*);
    static std::false_type _test(...);

public:
    using type = decltype(_test(static_cast<std::remove_cv_t<T>*>(nullptr)));
};
//------------------------------------------------------------------------------
template <typename T, typename Selector>
using has_enumerator_mapping_t =
  typename does_have_enumerator_mapping<T, Selector>::type;

template <typename T, typename Selector>
constexpr const bool has_enumerator_mapping_v =
  has_enumerator_mapping_t<T, Selector>::value;
//------------------------------------------------------------------------------
template <typename T, typename Selector>
constexpr std::enable_if_t<has_enumerator_mapping_v<T, Selector>, span_size_t>
enumerator_count(identity<T> id, Selector sel) noexcept {
    return span_size_t(enumerator_mapping(id, sel).size());
}
//------------------------------------------------------------------------------
template <typename T>
constexpr auto enumerator_count(identity<T> id) noexcept {
    return enumerator_count(id, selector<0>());
}
//------------------------------------------------------------------------------
template <typename T>
constexpr auto enumerator_name(T value, identity<T> id = {}) noexcept {
    return enumerator_name(value, id, selector<0>());
}
//------------------------------------------------------------------------------
template <typename T>
constexpr std::underlying_type_t<T> enumerator_value(
  T value, identity<T> = {}) noexcept {
    return static_cast<std::underlying_type_t<T>>(value);
}
//------------------------------------------------------------------------------
template <typename T, typename Selector>
std::enable_if_t<has_enumerator_mapping_v<T, Selector>, optionally_valid<T>>
from_value(
  std::underlying_type_t<T> value, identity<T> id, Selector sel) noexcept {
    for(const auto& info : enumerator_mapping(id, sel)) {
        if(enumerator_value(info.enumerator, id) == value) {
            return {info.enumerator, true};
        }
    }
    return {};
}
//------------------------------------------------------------------------------
template <typename T>
constexpr auto from_value(
  std::underlying_type_t<T> value, identity<T> id = {}) noexcept {
    return from_value(value, id, selector<0>());
}
//------------------------------------------------------------------------------
template <typename T, typename Selector>
std::enable_if_t<has_enumerator_mapping_v<T, Selector>, optionally_valid<T>>
from_string(string_view name, identity<T> id, Selector sel) noexcept {
    for(const auto& info : enumerator_mapping(id, sel)) {
        if(are_equal(info.name, name)) {
            return {info.enumerator, true};
        }
    }
    return {};
}
//------------------------------------------------------------------------------
template <typename T>
constexpr auto from_string(string_view name, identity<T> id = {}) noexcept {
    return from_string(name, id, selector<0>());
}
//------------------------------------------------------------------------------
template <typename T, typename Selector>
std::enable_if_t<has_enumerator_mapping_v<T, Selector>, string_view>
enumerator_name(T enumerator, identity<T> id, Selector sel) noexcept {
    for(const auto& info : enumerator_mapping(id, sel)) {
        if(info.enumerator == enumerator) {
            return info.name;
        }
    }
    return {};
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_MAP_ENUMERATORS_HPP
