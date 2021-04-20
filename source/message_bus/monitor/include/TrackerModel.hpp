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

    auto tracker() const noexcept -> auto& {
        return _tracker;
    }
signals:
    void nodeAppeared(const eagine::msgbus::remote_node&);
    void nodeRelocated(const eagine::msgbus::remote_node&);
    void hostInfoChanged(const eagine::msgbus::remote_host&);

private:
    void handleHostChanged(
      eagine::msgbus::remote_host&,
      eagine::msgbus::remote_host_changes);

    void handleNodeChanged(
      eagine::msgbus::remote_node&,
      eagine::msgbus::remote_node_changes);

    MonitorBackend& _backend;
    eagine::msgbus::endpoint _bus;
    eagine::msgbus::service_composition<
      eagine::msgbus::node_tracker<eagine::msgbus::shutdown_invoker<>>>
      _tracker;
};
//------------------------------------------------------------------------------
#endif
