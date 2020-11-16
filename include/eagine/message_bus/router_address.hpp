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

#include "../application_config.hpp"
#include "../logging/logger.hpp"

namespace eagine::msgbus {
//------------------------------------------------------------------------------
class router_address {
public:
    router_address(logger& log, application_config& cfg) {
        if(cfg.fetch("msg_bus.router_address", _addr)) {
            log.debug("configured router address ${addr}")
              .arg(EAGINE_ID(addr), _addr);
        }
    }

    operator string_view() const noexcept {
        return {_addr};
    }

private:
    std::string _addr{};
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_ROUTER_ADDRESS_HPP
