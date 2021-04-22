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
      &selectedItemViewModel,
      &SelectedItemViewModel::hostChanged,
      this,
      &HostViewModel::onHostInfoChanged);
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
void HostViewModel::onHostInfoChanged(eagine::identifier_t hostId) {
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
