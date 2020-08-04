/**
 *  @file eagine/message_bus/types.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_TYPES_HPP
#define EAGINE_MESSAGE_BUS_TYPES_HPP

#include "../identifier_t.hpp"
#include "../types.hpp"
#include <tuple>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
using message_sequence_t = std::uint32_t;
//------------------------------------------------------------------------------
using router_topology_info = std::tuple<identifier_t>;
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_TYPES_HPP

