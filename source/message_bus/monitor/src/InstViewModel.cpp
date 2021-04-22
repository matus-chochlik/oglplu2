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
      &selectedItemViewModel,
      &SelectedItemViewModel::instChanged,
      this,
      &InstViewModel::onInstInfoChanged);
}
//------------------------------------------------------------------------------
auto InstViewModel::getItemKind() -> QString {
    return {"Instance"};
}
//------------------------------------------------------------------------------
auto InstViewModel::getIdentifier() -> QVariant {
    if(_inst) {
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
void InstViewModel::onInstInfoChanged(eagine::identifier_t instId) {
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

