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
auto NodeViewModel::getItemKind() -> QString {
    if(_node) {
        switch(_node.kind()) {
            case eagine::msgbus::node_kind::endpoint:
                return {"Endpoint"};
            case eagine::msgbus::node_kind::router:
                return {"Router"};
            case eagine::msgbus::node_kind::bridge:
                return {"Bridge"};
            case eagine::msgbus::node_kind::unknown:
                break;
        }
        return {"UnknownNode"};
    }
    return {"NoItem"};
}
//------------------------------------------------------------------------------
auto NodeViewModel::getIdentifier() -> QVariant {
    if(_node) {
        return {QString::number(extract(_node.id()))};
    }
    return {};
}
//------------------------------------------------------------------------------
auto NodeViewModel::getDisplayName() -> QVariant {
    if(auto optStr{_node.display_name()}) {
        return {c_str(extract(optStr))};
    }
    return {};
}
//------------------------------------------------------------------------------
void NodeViewModel::onNodeInfoChanged(eagine::identifier_t nodeId) {
    if(nodeId) {
        if(auto trackerModel{_backend.trackerModel()}) {
            auto& tracker = trackerModel->tracker();
            _node = tracker.get_node(nodeId);
        }
    } else {
        _node = {};
    }
    emit infoChanged();
}
//------------------------------------------------------------------------------
