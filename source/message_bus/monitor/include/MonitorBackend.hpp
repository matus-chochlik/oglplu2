///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_MONITOR_BACKEND
#define EAGINE_MESSAGE_BUS_MONITOR_BACKEND

#include "MonitorViewModel.hpp"
#include "NodeListModel.hpp"
#include <eagine/main_ctx_object.hpp>
#include <QObject>
#include <memory>

class TrackerModel;
//------------------------------------------------------------------------------
class MonitorBackend
  : public QObject
  , public eagine::main_ctx_object {
    Q_OBJECT

    Q_PROPERTY(MonitorViewModel* monitor READ getMonitorViewModel CONSTANT)
public:
    MonitorBackend(eagine::main_ctx_parent);
    ~MonitorBackend() final;

    auto trackerModel() noexcept -> TrackerModel*;
    auto getMonitorViewModel() noexcept -> MonitorViewModel*;
signals:
    void trackerModelChanged();
public slots:
private:
    void timerEvent(QTimerEvent*) final;

    int _timerId{0};
    std::shared_ptr<TrackerModel> _trackerModel;
    NodeListModel _nodeListModel;
    MonitorViewModel _monitorViewModel;
};
//------------------------------------------------------------------------------
#endif
