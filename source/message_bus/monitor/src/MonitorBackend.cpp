///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include "MonitorBackend.hpp"
#include "TrackerModel.hpp"
//------------------------------------------------------------------------------
MonitorBackend::MonitorBackend(eagine::main_ctx_parent parent)
  : QObject{nullptr}
  , eagine::main_ctx_object{EAGINE_ID(Backend), parent}
  , _monitorViewModel{*this}
  , _trackerModel{std::make_shared<TrackerModel>(*this)} {
    emit trackerModelChanged();
    startTimer(10);
}
//------------------------------------------------------------------------------
void MonitorBackend::timerEvent(QTimerEvent*) {
    if(_trackerModel) {
        _trackerModel->update();
    }
}
//------------------------------------------------------------------------------
auto MonitorBackend::trackerModel() noexcept -> TrackerModel* {
    return _trackerModel.get();
}
//------------------------------------------------------------------------------
auto MonitorBackend::getMonitorViewModel() noexcept -> MonitorViewModel* {
    return &_monitorViewModel;
}
//------------------------------------------------------------------------------
