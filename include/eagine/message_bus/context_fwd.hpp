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
#include "../program_args.hpp"
#include <memory>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
class context;
//------------------------------------------------------------------------------
using shared_context = std::shared_ptr<context>;
//------------------------------------------------------------------------------
auto make_context(logger&) -> std::shared_ptr<context>;
auto make_context(logger&, const program_args&) -> std::shared_ptr<context>;
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_CONTEXT_FWD_HPP
