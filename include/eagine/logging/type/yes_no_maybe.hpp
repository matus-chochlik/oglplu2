/// @file eagine/logging/type/yes_no_maybe.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_LOGGING_TYPE_YES_NO_MAYBE_HPP
#define EAGINE_LOGGING_TYPE_YES_NO_MAYBE_HPP

#include "../../tribool.hpp"
#include "../entry.hpp"

namespace eagine {
//------------------------------------------------------------------------------
struct yes_no_maybe : tribool {
    constexpr yes_no_maybe(tribool v) noexcept
      : tribool{v} {}
};
//------------------------------------------------------------------------------
static inline auto adapt_log_entry_arg(identifier name, yes_no_maybe value) {
    return [name, value](logger_backend& backend) {
        backend.add_string(
          name,
          EAGINE_ID(YesNoMaybe),
          value.is(true)
            ? string_view{"yes"}
            : value.is(false) ? string_view{"no"} : string_view{"maybe"});
    };
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_LOGGING_TYPE_YES_NO_MAYBE_HPP
