///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
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
//------------------------------------------------------------------------------
auto MonitorViewModel::getSelectedItemViewModel() -> SelectedItemViewModel* {
    return &_selectedItemViewModel;
}
//------------------------------------------------------------------------------
