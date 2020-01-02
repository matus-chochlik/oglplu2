/**
 *  @file eagine/map_data_members.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MAP_DATA_MEMBERS_HPP
#define EAGINE_MAP_DATA_MEMBERS_HPP

#include "selector.hpp"
#include "string_span.hpp"
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
template <typename T, typename Mapping, std::size_t... I>
constexpr auto _map_data_members_impl(
  T& instance, const Mapping& mapping, std::index_sequence<I...>) {
    return std::make_tuple(
      std::pair<
        string_view,
        decltype(instance.*std::get<1>(std::get<I>(mapping)))&>(
        std::get<0>(std::get<I>(mapping)),
        instance.*std::get<1>(std::get<I>(mapping)))...);
}
//------------------------------------------------------------------------------
template <typename T, typename C, typename... M>
constexpr auto do_map_data_members(
  T& instance, const std::tuple<std::pair<string_view, M C::*>...>& mapping) {
    return _map_data_members_impl(
      instance, mapping, std::make_index_sequence<sizeof...(M)>());
}
//------------------------------------------------------------------------------
template <typename T, identifier_t Id>
constexpr auto map_data_members(T& instance, selector<Id> sel) noexcept {
    return do_map_data_members(
      instance, data_member_mapping(identity<std::remove_cv_t<T>>(), sel));
}
//------------------------------------------------------------------------------
template <typename T>
constexpr auto map_data_members(T& instance) noexcept {
    return map_data_members(instance, selector<0>{});
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_MAP_DATA_MEMBERS_HPP
