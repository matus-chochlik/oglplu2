/**
 *  @file eagine/message_bus/registry.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_REGISTRY_HPP
#define EAGINE_MESSAGE_BUS_REGISTRY_HPP

#include "direct.hpp"
#include "endpoint.hpp"
#include "router.hpp"
#include <memory>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
class registry {
public:
    registry(logger& parent, const program_args& args);

    auto establish(identifier log_id) -> endpoint;

    auto establish() -> endpoint;

private:
    logger _log{};
    std::shared_ptr<direct_acceptor> _acceptor;
    router _router;
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/message_bus/registry.inl>
#endif

#endif // EAGINE_MESSAGE_BUS_REGISTRY_HPP
