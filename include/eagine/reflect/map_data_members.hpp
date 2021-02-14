/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_REFLECT_MAP_DATA_MEMBERS_HPP
#define EAGINE_REFLECT_MAP_DATA_MEMBERS_HPP

#include "../selector.hpp"
#include "../string_span.hpp"
#include <tuple>
#include <type_traits>
#include <utility>

namespace eagine {
//------------------------------------------------------------------------------
template <typename C, typename... M>
constexpr auto
make_data_member_mapping(std::pair<string_view, M C::*>... m) noexcept {
    return std::make_tuple(m...);
}
//------------------------------------------------------------------------------
template <typename T, typename Selector>
struct does_have_data_member_mapping {
private:
    template <
      typename X,
      typename = decltype(data_member_mapping(type_identity<X>(), Selector()))>
    static auto _test(X*) -> std::true_type;
    static auto _test(...) -> std::false_type;

public:
    // NOLINTNEXTLINE(hicpp-vararg)
    using type = decltype(_test(static_cast<std::remove_cv_t<T>*>(nullptr)));
};
//------------------------------------------------------------------------------
template <typename T, typename Selector = default_selector_t>
using has_data_member_mapping_t =
  typename does_have_data_member_mapping<T, Selector>::type;

template <typename T, typename Selector = default_selector_t>
constexpr const bool has_data_member_mapping_v =
  has_data_member_mapping_t<T, Selector>::value;
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_REFLECT_MAP_DATA_MEMBERS_HPP
