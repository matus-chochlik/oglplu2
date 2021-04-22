///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
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
  , _nodeListViewModel{nodeListViewModel} {
    connect(
      &_nodeListViewModel,
      &NodeListViewModel::itemSelected,
      this,
      &SelectedItemViewModel::onItemSelected);
}
//------------------------------------------------------------------------------
auto SelectedItemViewModel::getItemKind() -> QString {
    if(_itemSelected) {
        if(auto trackerModel{_backend.trackerModel()}) {
            auto& tracker = trackerModel->tracker();
            if(_nodeId) {
                if(auto node = tracker.get_node(_nodeId)) {
                    switch(node.kind()) {
                        case eagine::msgbus::node_kind::endpoint:
                            return {"Endpoint"};
                        case eagine::msgbus::node_kind::router:
                            return {"Router"};
                        case eagine::msgbus::node_kind::bridge:
                            return {"Bridge"};
                        case eagine::msgbus::node_kind::unknown:
                            break;
                    }
                }
                return {"UnknownNode"};
            } else if(_instId) {
                return {"Instance"};
            } else if(_hostId) {
                return {"Host"};
            } else {
                return {"UnknownHost"};
            }
        }
    }
    return {"NoItem"};
}
//------------------------------------------------------------------------------
auto SelectedItemViewModel::getHostId() -> QVariant {
    if(_hostId) {
        return {static_cast<qulonglong>(_hostId)};
    }
    return {};
}
//------------------------------------------------------------------------------
auto SelectedItemViewModel::getInstId() -> QVariant {
    if(_instId) {
        return {static_cast<qulonglong>(_instId)};
    }
    return {};
}
//------------------------------------------------------------------------------
auto SelectedItemViewModel::getNodeId() -> QVariant {
    if(_nodeId) {
        return {static_cast<qulonglong>(_nodeId)};
    }
    return {};
}
//------------------------------------------------------------------------------
void SelectedItemViewModel::onItemSelected(
  eagine::identifier_t hostId,
  eagine::identifier_t instId,
  eagine::identifier_t nodeId) {
    _hostId = hostId;
    _instId = instId;
    _nodeId = nodeId;
    _itemSelected = true;
    emit itemSelectionChanged();
}
//------------------------------------------------------------------------------
void SelectedItemViewModel::onItemUnselected() {
    _itemSelected = false;
    emit itemSelectionChanged();
}
//------------------------------------------------------------------------------
