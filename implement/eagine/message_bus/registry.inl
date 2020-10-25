/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/message_bus/conn_setup.hpp>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
registry::registry(logger& parent, const program_args& args)
  : _log{EAGINE_ID(MsgBusRgtr), parent}
  , _acceptor{std::make_shared<direct_acceptor>()}
  , _router{_log, args} {
    _router.add_acceptor(_acceptor);

    router_address parent_address{ctx.log(), ctx.args()};
    connection_setup conn_setup(_log);
    conn_setup.default_init(args);

    conn_setup.setup_connectors(router, parent_address);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto registry::establish() -> endpoint {
    endpoint result{_log};
    result.add_connection(_acceptor->make_connection());
    return result;
}
//------------------------------------------------------------------------------
} // namespace eagine::msgbus
