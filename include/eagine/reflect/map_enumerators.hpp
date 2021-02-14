/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_REFLECT_MAP_ENUMERATORS_HPP
#define EAGINE_REFLECT_MAP_ENUMERATORS_HPP

#include "../selector.hpp"
#include "decl_name.hpp"
#include <array>
#include <type_traits>

namespace eagine {
//------------------------------------------------------------------------------
template <typename T>
struct enumerator_and_name {
    constexpr enumerator_and_name(decl_name n, T e) noexcept
      : name{n}
      , enumerator{e} {}

    const decl_name name;
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
      typename = decltype(enumerator_mapping(type_identity<X>(), Selector()))>
    static auto _test(X*) -> std::true_type;
    static auto _test(...) -> std::false_type;

public:
    // NOLINTNEXTLINE(hicpp-vararg)
    using type = decltype(_test(static_cast<std::remove_cv_t<T>*>(nullptr)));
};
//------------------------------------------------------------------------------
template <typename T, typename Selector = default_selector_t>
using has_enumerator_mapping_t =
  typename does_have_enumerator_mapping<T, Selector>::type;

template <typename T, typename Selector = default_selector_t>
constexpr const bool has_enumerator_mapping_v =
  has_enumerator_mapping_t<T, Selector>::value;
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_REFLECT_MAP_ENUMERATORS_HPP
