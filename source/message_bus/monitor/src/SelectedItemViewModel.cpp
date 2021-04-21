///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include "SelectedItemViewModel.hpp"
#include "MonitorBackend.hpp"
#include "NodeListViewModel.hpp"
//------------------------------------------------------------------------------
SelectedItemViewModel::SelectedItemViewModel(MonitorBackend& backend)
  : QObject{nullptr}
  , eagine::main_ctx_object{EAGINE_ID(MonitorVM), backend}
  , _backend{backend} {}
//------------------------------------------------------------------------------
auto SelectedItemViewModel::_nodeListViewModel() -> NodeListViewModel* {
    if(auto monitorViewModel{_backend.getMonitorViewModel()}) {
        return monitorViewModel->getNodeListViewModel();
    }
    return nullptr;
}
//------------------------------------------------------------------------------
auto SelectedItemViewModel::getItemKind() -> QString {
    return "NoItem";
}
//------------------------------------------------------------------------------
