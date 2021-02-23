/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_LOGGING_ROOT_LOGGER_OPTS_HPP
#define EAGINE_LOGGING_ROOT_LOGGER_OPTS_HPP

namespace eagine {
//------------------------------------------------------------------------------
/// @brief Structure holding root logger customization options.
/// @ingroup logging
struct root_logger_options {
    /// @brief Option saying that by default no logging should be done.
    bool default_no_log{false};
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_LOGGING_ROOT_LOGGER_OPTS_HPP
