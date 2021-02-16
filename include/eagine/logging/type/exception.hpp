/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_LOGGING_TYPE_EXCEPTION_HPP
#define EAGINE_LOGGING_TYPE_EXCEPTION_HPP

#include "../entry.hpp"
#include <stdexcept>

namespace eagine {
//------------------------------------------------------------------------------
static inline auto
adapt_log_entry_arg(identifier name, const std::exception& value) {
    return [name, value](logger_backend& backend) {
        backend.add_string(
          name, EAGINE_ID(Exception), string_view(value.what()));
    };
}
//------------------------------------------------------------------------------
static inline auto
adapt_log_entry_arg(identifier name, const std::runtime_error& value) {
    return [name, value](logger_backend& backend) {
        backend.add_string(
          name, EAGINE_ID(RuntmError), string_view(value.what()));
    };
}
//------------------------------------------------------------------------------
static inline auto
adapt_log_entry_arg(identifier name, const std::system_error& value) {
    return [name, value](logger_backend& backend) {
        backend.add_string(
          name, EAGINE_ID(SystmError), string_view(value.what()));
        backend.add_string(
          EAGINE_ID(category),
          EAGINE_ID(ErrorCtgry),
          string_view(value.code().category().name()));
    };
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_LOGGING_TYPE_EXCEPTION_HPP
