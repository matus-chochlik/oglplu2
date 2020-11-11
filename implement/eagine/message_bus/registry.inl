/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/bool_aggregate.hpp>
#include <eagine/message_bus/conn_setup.hpp>
#include <eagine/message_bus/router_address.hpp>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
registry::registry(logger& parent, const program_args& args)
  : _log{EAGINE_ID(MsgBusRgtr), parent}
  , _acceptor{std::make_shared<direct_acceptor>(_log)}
  , _router{_log, args} {
    _router.add_acceptor(_acceptor);

    router_address parent_address{_log, args};
    connection_setup conn_setup(_log, args);

    conn_setup.setup_connectors(_router, parent_address);
}
//------------------------------------------------------------------------------
template <typename Log>
auto registry::_do_establish(Log&& log) -> endpoint& {
    auto new_ept{std::make_unique<endpoint>(std::forward<Log>(log))};
    new_ept->add_connection(_acceptor->make_connection());

    _endpoints.emplace_back();
    auto& registered = _endpoints.back();

    registered.the_endpoint = std::move(new_ept);

    return *(registered.the_endpoint);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto registry::establish(identifier log_id) -> endpoint& {
    return _do_establish(logger{log_id, _log});
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto registry::establish() -> endpoint& {
    return _do_establish(_log);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto registry::update() -> bool {
    some_true something_done{};

    something_done(_router.update(8));

    return something_done;
}
//------------------------------------------------------------------------------
} // namespace eagine::msgbus
