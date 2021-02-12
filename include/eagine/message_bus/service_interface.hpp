/// @file eagine/message_bus/service_interface.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_SERVICE_INTERFACE_HPP
#define EAGINE_MESSAGE_BUS_SERVICE_INTERFACE_HPP

#include "../types.hpp"

namespace eagine::msgbus {
//------------------------------------------------------------------------------
struct service_interface {
    service_interface() noexcept = default;
    service_interface(service_interface&&) noexcept = default;
    service_interface(const service_interface&) = delete;
    auto operator=(service_interface&&) = delete;
    auto operator=(const service_interface&) = delete;

    virtual ~service_interface() noexcept = default;
    virtual auto update_and_process_all() -> bool = 0;
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_INTERFACE_HPP

