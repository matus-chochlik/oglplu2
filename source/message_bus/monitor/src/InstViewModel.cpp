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
auto InstViewModel::getIdentifier() -> QVariant {
    if(_instId) {
        return {QString::number(_instId)};
    }
    return {};
}
//------------------------------------------------------------------------------
auto InstViewModel::getItemKind() -> QString {
    return {"Instance"};
}
//------------------------------------------------------------------------------
void InstViewModel::onInstInfoChanged(eagine::identifier_t instId) {
    _instId = instId;
}
//------------------------------------------------------------------------------

