///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include "MonitorViewModel.hpp"
#include "MonitorBackend.hpp"
#include "NodeListViewModel.hpp"
//------------------------------------------------------------------------------
MonitorViewModel::MonitorViewModel(MonitorBackend& backend)
  : QObject{nullptr}
  , eagine::main_ctx_object{EAGINE_ID(MonitorVM), backend}
  , _backend{backend}
  , _nodeListViewModel{_backend}
  , _selectedItemViewModel{_backend, _nodeListViewModel} {}
//------------------------------------------------------------------------------
auto MonitorViewModel::getNodeListViewModel() -> NodeListViewModel* {
    return &_nodeListViewModel;
}
//------------------------------------------------------------------------------auto
auto MonitorViewModel::getSelectedItemViewModel() -> SelectedItemViewModel* {
    return &_selectedItemViewModel;
}
//------------------------------------------------------------------------------
