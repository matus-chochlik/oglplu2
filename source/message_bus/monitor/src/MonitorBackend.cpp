///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///

#include "MonitorBackend.hpp"
#include "TrackerModel.hpp"
//------------------------------------------------------------------------------
MonitorBackend::MonitorBackend(eagine::main_ctx_parent parent)
  : QObject{nullptr}
  , eagine::main_ctx_object{EAGINE_ID(Backend), parent}
  , _trackerModel{std::make_shared<TrackerModel>(*this)}
  , _monitorTheme{*this}
  , _monitorViewModel{*this} {
    emit trackerModelChanged();
    _timerId = startTimer(10);
}
//------------------------------------------------------------------------------
MonitorBackend::~MonitorBackend() {
    killTimer(_timerId);
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
auto MonitorBackend::getMonitorTheme() noexcept -> MonitorTheme* {
    return &_monitorTheme;
}
//------------------------------------------------------------------------------
auto MonitorBackend::getMonitorViewModel() noexcept -> MonitorViewModel* {
    return &_monitorViewModel;
}
//------------------------------------------------------------------------------
