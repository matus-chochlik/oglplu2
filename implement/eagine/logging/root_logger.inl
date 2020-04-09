/**
 *  @file eagine/logging/root_logger.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

namespace eagine {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
std::unique_ptr<logger_backend> root_logger::_init_backend(
  const program_args&) {
    return std::make_unique<null_log_backend>();
}
//------------------------------------------------------------------------------
} // namespace eagine
