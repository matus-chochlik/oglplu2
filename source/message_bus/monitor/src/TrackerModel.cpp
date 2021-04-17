///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include "TrackerModel.hpp"
#include "MonitorBackend.hpp"
#include <eagine/message_bus/conn_setup.hpp>
#include <eagine/message_bus/router_address.hpp>
//------------------------------------------------------------------------------
TrackerModel::TrackerModel(MonitorBackend& backend)
  : QObject{nullptr}
  , eagine::main_ctx_object{EAGINE_ID(Tracker), backend}
  , _backend{backend}
  , _bus{EAGINE_ID(TrckrEndpt), *this}
  , _tracker{_bus} {
    eagine::msgbus::router_address address{*this};
    eagine::msgbus::connection_setup conn_setup{*this};
    conn_setup.setup_connectors(_tracker, address);
}
//------------------------------------------------------------------------------
void TrackerModel::update() {
    _tracker.process_all();
    _tracker.update();
}
//------------------------------------------------------------------------------
