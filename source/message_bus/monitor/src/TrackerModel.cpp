///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <QDebug>

#include "MonitorBackend.hpp"
#include "TrackerModel.hpp"
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

    _tracker.host_changed.connect(EAGINE_THIS_MEM_FUNC_REF(handleHostChanged));
    _tracker.instance_changed.connect(
      EAGINE_THIS_MEM_FUNC_REF(handleInstanceChanged));
    _tracker.node_changed.connect(EAGINE_THIS_MEM_FUNC_REF(handleNodeChanged));

    _tracker.router_disappeared.connect(
      EAGINE_THIS_MEM_FUNC_REF(handleNodeDisappeared));
    _tracker.bridge_disappeared.connect(
      EAGINE_THIS_MEM_FUNC_REF(handleNodeDisappeared));
    _tracker.endpoint_disappeared.connect(
      EAGINE_THIS_MEM_FUNC_REF(handleNodeDisappeared));
}
//------------------------------------------------------------------------------
void TrackerModel::handleHostChanged(
  eagine::msgbus::remote_host& host,
  eagine::msgbus::remote_host_changes changes) {
    using eagine::msgbus::remote_host_change;

    if(changes) {
        emit hostInfoChanged(host);
    }
}
//------------------------------------------------------------------------------
void TrackerModel::handleInstanceChanged(
  eagine::msgbus::remote_instance& instance,
  eagine::msgbus::remote_instance_changes changes) {
    using eagine::msgbus::remote_instance_change;

    if(changes.has(remote_instance_change::host_id)) {
        emit instanceRelocated(instance);
    }

    if(
      changes.has(remote_instance_change::started_responding) ||
      changes.has(remote_instance_change::stopped_responding) ||
      changes.has(remote_instance_change::application_info) ||
      changes.has(remote_instance_change::build_info)) {
        emit instanceInfoChanged(instance);
    }
}
//------------------------------------------------------------------------------
void TrackerModel::handleNodeChanged(
  eagine::msgbus::remote_node& node,
  eagine::msgbus::remote_node_changes changes) {
    using eagine::msgbus::remote_node_change;

    if(changes.has(remote_node_change::kind)) {
        emit nodeKindChanged(node);
    }

    if(
      changes.has(remote_node_change::host_id) ||
      changes.has(remote_node_change::instance_id)) {
        emit nodeRelocated(node);
    }

    if(
      changes.has(remote_node_change::endpoint_info) ||
      changes.has(remote_node_change::response_rate) ||
      changes.has(remote_node_change::started_responding) ||
      changes.has(remote_node_change::stopped_responding)) {
        emit nodeInfoChanged(node);
    }

    if(changes.has(remote_node_change::methods_added)) {
    }

    if(changes.has(remote_node_change::methods_removed)) {
    }

    if(changes.has(remote_node_change::connection_info)) {
    }
}
//------------------------------------------------------------------------------
void TrackerModel::handleNodeDisappeared(eagine::identifier_t nodeId) {
    emit nodeDisappeared(nodeId);
}
//------------------------------------------------------------------------------
void TrackerModel::update() {
    _tracker.process_all();
    _tracker.update();
}
//------------------------------------------------------------------------------
