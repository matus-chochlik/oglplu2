/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
context::context(logger& parent)
  : _log{EAGINE_ID(MsgBusCtxt), parent} {
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
context::context(logger& parent, const program_args&)
  : context{parent} {
    // TODO
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
std::unique_ptr<context> make_context(logger& parent) {
    return std::make_unique<context>(parent);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC std::unique_ptr<context> make_context(
  logger& parent, const program_args& args) {
    return std::make_unique<context>(parent, args);
}
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine
