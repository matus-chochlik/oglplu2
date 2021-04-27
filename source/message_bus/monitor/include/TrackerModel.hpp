///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_MONITOR_TRACKER_MODEL
#define EAGINE_MESSAGE_BUS_MONITOR_TRACKER_MODEL

#include <eagine/main_ctx_object.hpp>
#include <eagine/message_bus/service.hpp>
#include <eagine/message_bus/service/shutdown.hpp>
#include <eagine/message_bus/service/tracker.hpp>
#include <QObject>

class MonitorBackend;
//------------------------------------------------------------------------------
class TrackerModel
  : public QObject
  , public eagine::main_ctx_object {
    Q_OBJECT
public:
    TrackerModel(MonitorBackend&);

    void update();

    auto tracker() noexcept -> auto& {
        return _tracker;
    }

    auto tracker() const noexcept -> auto& {
        return _tracker;
    }
signals:
    void nodeKindChanged(const eagine::msgbus::remote_node&);
    void nodeRelocated(const eagine::msgbus::remote_node&);
    void nodeInfoChanged(const eagine::msgbus::remote_node&);
    void instanceRelocated(const eagine::msgbus::remote_instance&);
    void instanceInfoChanged(const eagine::msgbus::remote_instance&);
    void hostInfoChanged(const eagine::msgbus::remote_host&);

    void nodeDisappeared(eagine::identifier_t);

private:
    void handleHostChanged(
      eagine::msgbus::remote_host&,
      eagine::msgbus::remote_host_changes);

    void handleInstanceChanged(
      eagine::msgbus::remote_instance&,
      eagine::msgbus::remote_instance_changes);

    void handleNodeChanged(
      eagine::msgbus::remote_node&,
      eagine::msgbus::remote_node_changes);

    void handleNodeDisappeared(eagine::identifier_t);

    MonitorBackend& _backend;
    eagine::msgbus::endpoint _bus;
    eagine::msgbus::service_composition<
      eagine::msgbus::node_tracker<eagine::msgbus::shutdown_invoker<>>>
      _tracker;
};
//------------------------------------------------------------------------------
#endif