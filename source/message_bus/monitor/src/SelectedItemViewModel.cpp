///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///

#include "SelectedItemViewModel.hpp"
#include "MonitorBackend.hpp"
#include "NodeListViewModel.hpp"
#include "TrackerModel.hpp"
//------------------------------------------------------------------------------
SelectedItemViewModel::SelectedItemViewModel(
  MonitorBackend& backend,
  NodeListViewModel& nodeListViewModel)
  : QObject{nullptr}
  , eagine::main_ctx_object{EAGINE_ID(MonitorVM), backend}
  , _backend{backend}
  , _nodeListViewModel{nodeListViewModel}
  , _hostViewModel{_backend, *this}
  , _instViewModel{_backend, *this}
  , _nodeViewModel{_backend, *this} {
    connect(
      &_nodeListViewModel,
      &NodeListViewModel::itemSelected,
      this,
      &SelectedItemViewModel::onItemSelected);
    connect(
      &_nodeListViewModel,
      &NodeListViewModel::itemUnselected,
      this,
      &SelectedItemViewModel::onItemUnselected);

    connect(
      &_hostViewModel,
      &HostViewModel::infoChanged,
      this,
      &SelectedItemViewModel::onItemInfoChanged);
    connect(
      &_instViewModel,
      &InstViewModel::infoChanged,
      this,
      &SelectedItemViewModel::onItemInfoChanged);
    connect(
      &_nodeViewModel,
      &NodeViewModel::infoChanged,
      this,
      &SelectedItemViewModel::onItemInfoChanged);
}
//------------------------------------------------------------------------------
auto SelectedItemViewModel::getItemKind() -> QString {
    if(_itemSelected) {
        if(_nodeViewModel) {
            return _nodeViewModel.getItemKind();
        } else if(_instViewModel) {
            return _instViewModel.getItemKind();
        } else if(_hostViewModel) {
            return _hostViewModel.getItemKind();
        }
    }
    return {"NoItem"};
}
//------------------------------------------------------------------------------
auto SelectedItemViewModel::getItemViewUrl() -> QUrl {
    return QString("qrc:///views/%1View.qml").arg(getItemKind());
}
//------------------------------------------------------------------------------
auto SelectedItemViewModel::getHostViewUrl() -> QUrl {
    return QString("qrc:///views/%1View.qml").arg(_hostViewModel.getItemKind());
}
//------------------------------------------------------------------------------
auto SelectedItemViewModel::getInstViewUrl() -> QUrl {
    return QString("qrc:///views/%1View.qml").arg(_instViewModel.getItemKind());
}
//------------------------------------------------------------------------------
auto SelectedItemViewModel::getNodeViewUrl() -> QUrl {
    return QString("qrc:///views/%1View.qml").arg(_nodeViewModel.getItemKind());
}
//------------------------------------------------------------------------------
auto SelectedItemViewModel::getHostViewModel() -> HostViewModel* {
    if(_hostViewModel) {
        return &_hostViewModel;
    }
    return nullptr;
}
//------------------------------------------------------------------------------
auto SelectedItemViewModel::getInstViewModel() -> InstViewModel* {
    if(_instViewModel) {
        return &_instViewModel;
    }
    return nullptr;
}
//------------------------------------------------------------------------------
auto SelectedItemViewModel::getNodeViewModel() -> NodeViewModel* {
    if(_nodeViewModel) {
        return &_nodeViewModel;
    }
    return nullptr;
}
//------------------------------------------------------------------------------
void SelectedItemViewModel::onItemInfoChanged() {
    emit itemSelectionChanged();
}
//------------------------------------------------------------------------------
void SelectedItemViewModel::onItemSelected(
  eagine::identifier_t hostId,
  eagine::identifier_t instId,
  eagine::identifier_t nodeId) {
    _itemSelected = true;
    emit hostChanged(hostId);
    emit instChanged(instId);
    emit nodeChanged(nodeId);
    emit itemSelectionChanged();
}
//------------------------------------------------------------------------------
void SelectedItemViewModel::onItemUnselected() {
    _itemSelected = false;
    emit itemSelectionChanged();
    emit hostChanged(0U);
    emit instChanged(0U);
    emit nodeChanged(0U);
}
//------------------------------------------------------------------------------
