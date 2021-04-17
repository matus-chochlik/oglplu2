///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include "MonitorBackend.hpp"
#include "TrackerModel.hpp"
//------------------------------------------------------------------------------
// Backend
//------------------------------------------------------------------------------
MonitorBackend::MonitorBackend(eagine::main_ctx_parent parent)
  : QObject{nullptr}
  , eagine::main_ctx_object{EAGINE_ID(Backend), parent}
  , _trackerModel{std::make_shared<TrackerModel>(*this)} {
    startTimer(10);
}
//------------------------------------------------------------------------------
void MonitorBackend::timerEvent(QTimerEvent*) {
    if(_trackerModel) {
        _trackerModel->update();
    }
}
//------------------------------------------------------------------------------
auto MonitorBackend::getMonitor() -> MonitorViewModel* {
    return nullptr;
}
//------------------------------------------------------------------------------
