/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_SERVICE_REQUIREMENTS_HPP
#define EAGINE_MESSAGE_BUS_SERVICE_REQUIREMENTS_HPP

#include "../type_identity.hpp"
#include <type_traits>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
template <class Base, template <typename...> class Required, typename... ReqiredArgs>
struct has_base_service : std::false_type {};

template <
  class BaseOfBase,
  template <typename...>
  class BaseService,
  typename... BaseArgs,
  template <typename...>
  class Required,
  typename... RequiredArgs>
struct has_base_service<
  BaseService<BaseOfBase, BaseArgs...>,
  Required,
  RequiredArgs...> : has_base_service<BaseOfBase, Required, RequiredArgs...> {};

template <
  class BaseOfBase,
  template <typename...>
  class Required,
  typename... RequiredArgs>
struct has_base_service<
  Required<BaseOfBase, RequiredArgs...>,
  Required,
  RequiredArgs...> : std::true_type {};

template <class Base, template <typename...> class Required>
constexpr const bool has_base_service_v =
  has_base_service<Base, Required>::value;
//------------------------------------------------------------------------------
template <class Base, template <typename...> class Required, typename... Args>
using require_service = std::conditional_t<
  has_base_service_v<Base, Required, Args...>,
  Base,
  Required<Base, Args...>>;
//------------------------------------------------------------------------------
template <class Base, template <class> class... Requirements>
struct get_required_services;

template <class Base, template <class> class... Requirements>
using require_services =
  typename get_required_services<Base, Requirements...>::type;

template <class Base>
struct get_required_services<Base> : type_identity<Base> {};

template <
  class Base,
  template <class>
  class Required,
  template <class>
  class... Requirements>
struct get_required_services<Base, Required, Requirements...>
  : type_identity<
      require_service<require_services<Base, Requirements...>, Required>> {};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_REQUIREMENTS_HPP
