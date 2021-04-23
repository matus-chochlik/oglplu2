///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include "InstViewModel.hpp"
#include "MonitorBackend.hpp"
#include "TrackerModel.hpp"
//------------------------------------------------------------------------------
InstViewModel::InstViewModel(
  MonitorBackend& backend,
  SelectedItemViewModel& selectedItemViewModel)
  : QObject{nullptr}
  , eagine::main_ctx_object{EAGINE_ID(InstVM), backend}
  , _backend{backend} {
    connect(
      &_backend,
      &MonitorBackend::trackerModelChanged,
      this,
      &InstViewModel::onTrackerModelChanged);
    connect(
      &selectedItemViewModel,
      &SelectedItemViewModel::instChanged,
      this,
      &InstViewModel::onInstIdChanged);
}
//------------------------------------------------------------------------------
auto InstViewModel::getItemKind() -> QString {
    if(_inst) {
        return {"Instance"};
    }
    return {"UnknownInstance"};
}
//------------------------------------------------------------------------------
auto InstViewModel::getIdentifier() -> QVariant {
    if(_inst.id()) {
        return {QString::number(extract(_inst.id()))};
    }
    return {};
}
//------------------------------------------------------------------------------
auto InstViewModel::getDisplayName() -> QVariant {
    if(auto optStr{_inst.application_name()}) {
        return {c_str(extract(optStr))};
    }
    return {};
}
//------------------------------------------------------------------------------
auto InstViewModel::getDescription() -> QVariant {
    return {};
}
//------------------------------------------------------------------------------
void InstViewModel::onTrackerModelChanged() {
    if(auto trackerModel{_backend.trackerModel()}) {
        connect(
          trackerModel,
          &TrackerModel::instanceRelocated,
          this,
          &InstViewModel::onInstInfoChanged);
        connect(
          trackerModel,
          &TrackerModel::instanceInfoChanged,
          this,
          &InstViewModel::onInstInfoChanged);
    }
}
//------------------------------------------------------------------------------
void InstViewModel::onInstIdChanged(eagine::identifier_t instId) {
    if(instId) {
        if(auto trackerModel{_backend.trackerModel()}) {
            auto& tracker = trackerModel->tracker();
            _inst = tracker.get_instance(instId);
        }
    } else {
        _inst = {};
    }
    emit infoChanged();
}
//------------------------------------------------------------------------------
void InstViewModel::onInstInfoChanged(const remote_inst& inst) {
    if(inst.id() == _inst.id()) {
        emit infoChanged();
    }
}
//------------------------------------------------------------------------------
