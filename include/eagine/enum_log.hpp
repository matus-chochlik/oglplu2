/**
 *  @file eagine/enum_log.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_ENUM_LOG_HPP
#define EAGINE_ENUM_LOG_HPP

#include "enum_class.hpp"
#include "logging/backend.hpp"
#include <type_traits>

namespace eagine {
//------------------------------------------------------------------------------
template <typename Self, typename T, identifier_t LibId, identifier_t Id>
static constexpr auto adapt_log_entry_arg(
  identifier name,
  enum_class<Self, T, LibId, Id> ec,
  std::enable_if_t<std::is_signed_v<T>, T> = {}) {
    return [=](logger_backend& backend) {
        backend.add_integer(name, identifier{Id}, ec._value);
    };
}
//------------------------------------------------------------------------------
template <typename Self, typename T, identifier_t LibId, identifier_t Id>
static constexpr auto adapt_log_entry_arg(
  identifier name,
  enum_class<Self, T, LibId, Id> ec,
  std::enable_if_t<std::is_unsigned_v<T>, T> = {}) {
    return [=](logger_backend& backend) {
        backend.add_unsigned(name, identifier{Id}, ec._value);
    };
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_ENUM_LOG_HPP
