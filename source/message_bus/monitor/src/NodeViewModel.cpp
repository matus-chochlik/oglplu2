///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include "NodeViewModel.hpp"
#include "MonitorBackend.hpp"
#include "TrackerModel.hpp"
//------------------------------------------------------------------------------
NodeViewModel::NodeViewModel(
  MonitorBackend& backend,
  SelectedItemViewModel& selectedItemViewModel)
  : QObject{nullptr}
  , eagine::main_ctx_object{EAGINE_ID(NodeVM), backend}
  , _backend{backend} {
    connect(
      &selectedItemViewModel,
      &SelectedItemViewModel::nodeChanged,
      this,
      &NodeViewModel::onNodeInfoChanged);
}
//------------------------------------------------------------------------------
auto NodeViewModel::getIdentifier() -> QVariant {
    if(_nodeId) {
        return {QString::number(_nodeId)};
    }
    return {};
}
//------------------------------------------------------------------------------
auto NodeViewModel::getItemKind() -> QString {
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
        }
    }
    return {"NoItem"};
}
//------------------------------------------------------------------------------
void NodeViewModel::onNodeInfoChanged(eagine::identifier_t nodeId) {
    _nodeId = nodeId;
}
//------------------------------------------------------------------------------
