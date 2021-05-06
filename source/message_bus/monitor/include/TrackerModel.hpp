///
/// Copyright Matus Chochlik.
//// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
//

#ifndef EAGINE_MESSAGE_BUS_MONITOR_TRACKER_MODEL
#define EAGINE_MESSAGE_BUS_MONITOR_TRACKER_MODEL

#include <eagine/main_ctx_object.hpp>
#include <eagine/message_bus/service.hpp>
#include <eagine/message_bus/service/shutdown.hpp>
#include <eagine/message_bus/service/tracker.hpp>
#include <eagine/value_with_history.hpp>
#include <QObject>
#include <map>

class MonitorBackend;
class TrackerModel;
//------------------------------------------------------------------------------
class HostParameterModel {
public:
    auto shortAverageLoadHistory() const noexcept -> auto& {
        return _short_average_load_history.as_value();
    }

    auto longAverageLoadHistory() const noexcept -> auto& {
        return _long_average_load_history.as_value();
    }

private:
    friend class TrackerModel;

    eagine::variable_with_history<float, 128> _short_average_load_history;
    eagine::variable_with_history<float, 128> _long_average_load_history;
};
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

    auto hostParameters(eagine::identifier_t hostId) noexcept
      -> std::shared_ptr<HostParameterModel>;
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

    std::map<eagine::identifier_t, std::weak_ptr<HostParameterModel>>
      _host_parameters;
};
//------------------------------------------------------------------------------
#endif
