///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///

#ifndef EAGINE_MESSAGE_BUS_MONITOR_BACKEND
#define EAGINE_MESSAGE_BUS_MONITOR_BACKEND

#include "MonitorTheme.hpp"
#include "MonitorViewModel.hpp"
#include <eagine/main_ctx_object.hpp>
#include <QObject>
#include <memory>

class TrackerModel;
//------------------------------------------------------------------------------
class MonitorBackend
  : public QObject
  , public eagine::main_ctx_object {
    Q_OBJECT

    Q_PROPERTY(MonitorTheme* theme READ getMonitorTheme CONSTANT)
    Q_PROPERTY(MonitorViewModel* monitor READ getMonitorViewModel CONSTANT)
public:
    MonitorBackend(eagine::main_ctx_parent);
    ~MonitorBackend() final;

    auto trackerModel() noexcept -> TrackerModel*;
    auto getMonitorTheme() noexcept -> MonitorTheme*;
    auto getMonitorViewModel() noexcept -> MonitorViewModel*;
signals:
    void trackerModelChanged();
public slots:
private:
    void timerEvent(QTimerEvent*) final;

    int _timerId{0};
    std::shared_ptr<TrackerModel> _trackerModel;
    MonitorTheme _monitorTheme;
    MonitorViewModel _monitorViewModel;
};
//------------------------------------------------------------------------------
#endif
