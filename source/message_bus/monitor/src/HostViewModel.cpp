///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include "HostViewModel.hpp"
#include "MonitorBackend.hpp"
#include "TrackerModel.hpp"
//------------------------------------------------------------------------------
HostViewModel::HostViewModel(
  MonitorBackend& backend,
  SelectedItemViewModel& selectedItemViewModel)
  : QObject{nullptr}
  , eagine::main_ctx_object{EAGINE_ID(HostVM), backend}
  , _backend{backend} {
    connect(
      &_backend,
      &MonitorBackend::trackerModelChanged,
      this,
      &HostViewModel::onTrackerModelChanged);
    connect(
      &selectedItemViewModel,
      &SelectedItemViewModel::hostChanged,
      this,
      &HostViewModel::onHostIdChanged);
}
//------------------------------------------------------------------------------
auto HostViewModel::getItemKind() -> QString {
    if(_host) {
        return {"Host"};
    }
    return {"UnknownHost"};
}
//------------------------------------------------------------------------------
auto HostViewModel::getIdentifier() -> QVariant {
    if(_host) {
        return {QString::number(extract(_host.id()))};
    }
    return {};
}
//------------------------------------------------------------------------------
auto HostViewModel::getDisplayName() -> QVariant {
    if(auto optStr{_host.name()}) {
        return {c_str(extract(optStr))};
    }
    return {};
}
//------------------------------------------------------------------------------
auto HostViewModel::getDescription() -> QVariant {
    return {};
}
//------------------------------------------------------------------------------
void HostViewModel::onTrackerModelChanged() {
    if(auto trackerModel{_backend.trackerModel()}) {
        connect(
          trackerModel,
          &TrackerModel::hostInfoChanged,
          this,
          &HostViewModel::onHostInfoChanged);
    }
}
//------------------------------------------------------------------------------
void HostViewModel::onHostIdChanged(eagine::identifier_t hostId) {
    if(hostId) {
        if(auto trackerModel{_backend.trackerModel()}) {
            auto& tracker = trackerModel->tracker();
            _host = tracker.get_host(hostId);
        }
    } else {
        _host = {};
    }
    emit infoChanged();
}
//------------------------------------------------------------------------------
void HostViewModel::onHostInfoChanged(const remote_host& host) {
    if(host.id() == _host.id()) {
        emit infoChanged();
    }
}
//------------------------------------------------------------------------------
