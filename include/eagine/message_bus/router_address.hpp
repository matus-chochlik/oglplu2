/**
 *  @file eagine/message_bus/router_address.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_ROUTER_ADDRESS_HPP
#define EAGINE_MESSAGE_BUS_ROUTER_ADDRESS_HPP

#include "../logging/logger.hpp"
#include "../program_args.hpp"

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
class router_address {
public:
    router_address(logger& log, const program_args& args) {
        if(auto arg = args.find("--msg-bus-router-address").next()) {
            arg.parse(_addr, log.error_stream());
        }
    }

    operator string_view() const noexcept {
        return {_addr};
    }

private:
    std::string _addr{};
};
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

#endif // EAGINE_MESSAGE_BUS_ROUTER_ADDRESS_HPP
