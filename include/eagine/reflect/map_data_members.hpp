/**
 *  @file eagine/reflect/map_data_members.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_REFLECT_MAP_DATA_MEMBERS_HPP
#define EAGINE_REFLECT_MAP_DATA_MEMBERS_HPP

#include "../selector.hpp"
#include "../string_span.hpp"
#include <type_traits>
#include <utility>

namespace eagine {
//------------------------------------------------------------------------------
template <typename C, typename... M>
constexpr auto make_data_member_mapping(
  std::pair<string_view, M C::*>... m) noexcept {
    return std::make_tuple(m...);
}
//------------------------------------------------------------------------------
template <typename F, typename S, identifier_t Id>
constexpr auto data_member_mapping(
  identity<std::pair<F, S>>, selector<Id>) noexcept {
    using P = std::pair<F, S>;
    return make_data_member_mapping<P, F, S>(
      {"first", &P::first}, {"second", &P::second});
}
//------------------------------------------------------------------------------
template <typename T, typename Selector>
struct does_have_data_member_mapping {
private:
    template <
      typename X,
      typename = decltype(data_member_mapping(identity<X>(), Selector()))>
    static std::true_type _test(X*);
    static std::false_type _test(...);

public:
    using type = decltype(_test(static_cast<std::remove_cv_t<T>*>(nullptr)));
};
//------------------------------------------------------------------------------
template <typename T, typename Selector>
using has_data_member_mapping_t =
  typename does_have_data_member_mapping<T, Selector>::type;
//------------------------------------------------------------------------------
template <typename T, typename Selector>
constexpr auto _do_map_single_data_member(
  string_view name, T& ref, Selector, std::false_type) noexcept {
    return std::pair<string_view, T&>(name, ref);
}
//------------------------------------------------------------------------------
template <typename T, typename Selector>
constexpr auto _do_map_single_data_member(
  string_view name, T& ref, Selector select, std::true_type) noexcept {
    return std::make_pair(name, map_data_members(ref, select));
}
//------------------------------------------------------------------------------
template <typename T, typename Selector>
constexpr auto _map_single_data_member(
  string_view name, T& ref, Selector select) noexcept {
    return _do_map_single_data_member(
      name, ref, select, has_data_member_mapping_t<T, Selector>());
}
//------------------------------------------------------------------------------
template <typename T, typename Selector, typename Mapping, std::size_t... I>
constexpr auto _map_data_members_impl(
  T& instance,
  Selector select,
  const Mapping& mapping,
  std::index_sequence<I...>) {
    return std::make_tuple(_map_single_data_member(
      std::get<0>(std::get<I>(mapping)),
      instance.*std::get<1>(std::get<I>(mapping)),
      select)...);
}
//------------------------------------------------------------------------------
template <typename T, typename Selector, typename C, typename... M>
constexpr auto do_map_data_members(
  T& instance,
  Selector select,
  const std::tuple<std::pair<string_view, M C::*>...>& mapping) {
    return _map_data_members_impl(
      instance, select, mapping, std::make_index_sequence<sizeof...(M)>());
}
//------------------------------------------------------------------------------
template <typename T, identifier_t Id>
constexpr auto map_data_members(T& instance, selector<Id> select) noexcept {
    return do_map_data_members(
      instance,
      select,
      data_member_mapping(identity<std::remove_cv_t<T>>(), select));
}
//------------------------------------------------------------------------------
template <typename T>
constexpr auto map_data_members(T& instance) noexcept {
    return map_data_members(instance, selector<0>{});
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_REFLECT_MAP_DATA_MEMBERS_HPP
