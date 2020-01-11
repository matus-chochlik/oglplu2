/**
 *  @file eagine/reflect/map_enumerators.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_REFLECT_MAP_ENUMERATORS_HPP
#define EAGINE_REFLECT_MAP_ENUMERATORS_HPP

#include "../string_span.hpp"
#include <array>
#include <type_traits>

namespace eagine {
//------------------------------------------------------------------------------
template <typename T>
struct enumerator_and_name {
    constexpr enumerator_and_name(string_view n, T e) noexcept
      : name{n}
      , enumerator{e} {
    }

    const string_view name;
    const T enumerator;
};
//------------------------------------------------------------------------------
template <typename T, std::size_t N>
using enumerator_map_type = std::array<enumerator_and_name<T>, N>;
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
} // namespace eagine

#endif // EAGINE_MAP_ENUMERATORS_HPP
