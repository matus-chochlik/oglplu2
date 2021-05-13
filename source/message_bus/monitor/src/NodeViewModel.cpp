///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
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
  , _backend{backend}
  , _parameters{backend} {
    connect(
      &_backend,
      &MonitorBackend::trackerModelChanged,
      this,
      &NodeViewModel::onTrackerModelChanged);
    connect(
      &selectedItemViewModel,
      &SelectedItemViewModel::nodeChanged,
      this,
      &NodeViewModel::onNodeIdChanged);
}
//------------------------------------------------------------------------------
auto NodeViewModel::getItemKind() -> QString {
    if(_node.id()) {
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
    switch(_node.kind()) {
        case eagine::msgbus::node_kind::endpoint:
            if(auto optStr{_node.display_name()}) {
                return {c_str(extract(optStr))};
            }
            break;
        case eagine::msgbus::node_kind::router:
            return {"routing node"};
        case eagine::msgbus::node_kind::bridge:
            return {"bridge node"};
        case eagine::msgbus::node_kind::unknown:
            return {"unknown node"};
    }
    return {};
}
//------------------------------------------------------------------------------
auto NodeViewModel::getDescription() -> QVariant {
    switch(_node.kind()) {
        case eagine::msgbus::node_kind::endpoint:
            if(auto optStr{_node.description()}) {
                return {c_str(extract(optStr))};
            }
            break;
        case eagine::msgbus::node_kind::router:
            return {"message bus routing node"};
        case eagine::msgbus::node_kind::bridge:
            return {"message bus bridge node"};
        case eagine::msgbus::node_kind::unknown:
            return {"unknown message bus node"};
    }
    return {};
}
//------------------------------------------------------------------------------
auto NodeViewModel::getUptime() -> QVariant {
    if(const auto uptime{_node.uptime()}) {
        const std::chrono::seconds secs{extract(uptime)};
        return {static_cast<qulonglong>(secs.count())};
    }
    return {};
}
//------------------------------------------------------------------------------
auto NodeViewModel::getSentMessages() -> QVariant {
    if(const auto count{_node.sent_messages()}) {
        return {static_cast<qulonglong>(extract(count))};
    }
    return {};
}
//------------------------------------------------------------------------------
auto NodeViewModel::getReceivedMessages() -> QVariant {
    if(const auto count{_node.received_messages()}) {
        return {static_cast<qulonglong>(extract(count))};
    }
    return {};
}
//------------------------------------------------------------------------------
auto NodeViewModel::getDroppedMessages() -> QVariant {
    if(const auto count{_node.dropped_messages()}) {
        return {static_cast<qulonglong>(extract(count))};
    }
    return {};
}
//------------------------------------------------------------------------------
auto NodeViewModel::getMessagesPerSecond() -> QVariant {
    if(auto optNum{_node.messages_per_second()}) {
        return {extract(optNum)};
    }
    return {};
}
//------------------------------------------------------------------------------
auto NodeViewModel::getPingSuccessRate() -> QVariant {
    if(auto optNum{_node.ping_success_rate()}) {
        return {extract(optNum)};
    }
    return {};
}
//------------------------------------------------------------------------------
auto NodeViewModel::getParameters() -> QAbstractItemModel* {
    return &_parameters;
}
//------------------------------------------------------------------------------
void NodeViewModel::onTrackerModelChanged() {
    if(auto trackerModel{_backend.trackerModel()}) {
        connect(
          trackerModel,
          &TrackerModel::nodeKindChanged,
          this,
          &NodeViewModel::onNodeInfoChanged);
        connect(
          trackerModel,
          &TrackerModel::nodeRelocated,
          this,
          &NodeViewModel::onNodeInfoChanged);
        connect(
          trackerModel,
          &TrackerModel::nodeInfoChanged,
          this,
          &NodeViewModel::onNodeInfoChanged);
    }
}
//------------------------------------------------------------------------------
void NodeViewModel::onNodeIdChanged(eagine::identifier_t nodeId) {
    if(nodeId) {
        if(auto trackerModel{_backend.trackerModel()}) {
            auto& tracker = trackerModel->tracker();
            _node = tracker.get_node(nodeId);
        }
    } else {
        _node = {};
    }
    emit infoChanged();
    _parameters.setNodeId(nodeId);
}
//------------------------------------------------------------------------------
void NodeViewModel::onNodeInfoChanged(const remote_node& node) {
    if(node.id() == _node.id()) {
        emit infoChanged();
        _parameters.notifyUpdated();
    }
}
//------------------------------------------------------------------------------
