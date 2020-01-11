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

#include "maybe_unused.hpp"
#include "selector.hpp"
#include "string_span.hpp"
#include "valid_if/decl.hpp"
#include <type_traits>
#include <utility>

namespace eagine {
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
    for(auto [unused, enumerator] : enumerator_mapping(id, sel)) {
        EAGINE_MAYBE_UNUSED(unused);
        if(enumerator_value(enumerator, id) == value) {
            return {enumerator, true};
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
    for(auto [enum_name, enumerator] : enumerator_mapping(id, sel)) {
        if(are_equal(enum_name, name)) {
            return {enumerator, true};
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
enumerator_name(T value, identity<T> id, Selector sel) noexcept {
    for(auto [enum_name, enumerator] : enumerator_mapping(id, sel)) {
        if(value == enumerator) {
            return enum_name;
        }
    }
    return {};
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_MAP_ENUMERATORS_HPP
