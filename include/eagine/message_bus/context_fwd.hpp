/**
 *  @file eagine/message_bus/context_fwd.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_CONTEXT_FWD_HPP
#define EAGINE_MESSAGE_BUS_CONTEXT_FWD_HPP

#include "../logging/fwd.hpp"
#include <memory>

namespace eagine {
class application_config;
namespace msgbus {
//------------------------------------------------------------------------------
class context;
//------------------------------------------------------------------------------
using shared_context = std::shared_ptr<context>;
//------------------------------------------------------------------------------
auto make_context(logger&) -> std::shared_ptr<context>;
auto make_context(logger&, application_config&) -> std::shared_ptr<context>;
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

#endif // EAGINE_MESSAGE_BUS_CONTEXT_FWD_HPP
