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
auto HostViewModel::getIdentifier() -> QVariant {
    if(_hostId) {
        return {QString::number(_hostId)};
    }
    return {};
}
//------------------------------------------------------------------------------
auto HostViewModel::getItemKind() -> QString {
    if(_hostId) {
        return {"Host"};
    }
    return {"UnknownHost"};
}
//------------------------------------------------------------------------------
void HostViewModel::onHostInfoChanged(eagine::identifier_t hostId) {
    _hostId = hostId;
}
//------------------------------------------------------------------------------
