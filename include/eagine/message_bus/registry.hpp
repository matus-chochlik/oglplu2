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
struct registered_entry {
    std::unique_ptr<endpoint> the_endpoint;
};
//------------------------------------------------------------------------------
class registry {
public:
    registry(logger& parent, const program_args& args);

    auto establish(identifier log_id) -> endpoint&;
    auto establish() -> endpoint&;

    auto update() -> bool;

private:
    logger _log{};
    std::shared_ptr<direct_acceptor> _acceptor;
    router _router;
    std::vector<registered_entry> _endpoints;

    template <typename Log>
    auto _do_establish(Log &&) -> endpoint&;
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/message_bus/registry.inl>
#endif

#endif // EAGINE_MESSAGE_BUS_REGISTRY_HPP
