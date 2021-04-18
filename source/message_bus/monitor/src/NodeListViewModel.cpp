///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include "NodeListViewModel.hpp"
#include "MonitorBackend.hpp"
#include "TrackerModel.hpp"
#include <algorithm>
//------------------------------------------------------------------------------
// InstanceInfo
//------------------------------------------------------------------------------
auto NodeListViewModel::InstanceInfo::count() const noexcept -> int {
    return eagine::limit_cast<int>(nodes.size());
}
//------------------------------------------------------------------------------
auto NodeListViewModel::InstanceInfo::totalCount() const noexcept -> int {
    return count();
}
//------------------------------------------------------------------------------
auto NodeListViewModel::InstanceInfo::indexOk(int i) const noexcept -> bool {
    return (i >= 0) && (i < eagine::limit_cast<int>(nodes.size()));
}
//------------------------------------------------------------------------------
auto NodeListViewModel::InstanceInfo::id(int i) const noexcept
  -> eagine::identifier_t {
    EAGINE_ASSERT(indexOk(i));
    return (nodes.begin() + i)->first;
}
//------------------------------------------------------------------------------
// HostInfo
//------------------------------------------------------------------------------
auto NodeListViewModel::HostInfo::count() const noexcept -> int {
    return eagine::limit_cast<int>(instances.size());
}
//------------------------------------------------------------------------------
auto NodeListViewModel::HostInfo::totalCount() const noexcept -> int {
    return std::accumulate(
      instances.begin(), instances.end(), 0, [](int s, auto& e) {
          return s + e.second.totalCount();
      });
}
//------------------------------------------------------------------------------
// Data
//------------------------------------------------------------------------------
auto NodeListViewModel::Data::totalCount() const noexcept -> int {
    return std::accumulate(hosts.begin(), hosts.end(), 0, [](int s, auto& e) {
        return s + e.second.totalCount();
    });
}
//------------------------------------------------------------------------------
template <typename Function>
void NodeListViewModel::Data::forHost(
  eagine::identifier_t hostId,
  Function function) const {
    const auto hostPos = hosts.find(hostId);
    if(hostPos != hosts.end()) {
        const auto& hostInfo = hostPos->second;
        function(hostInfo);
    }
}
//------------------------------------------------------------------------------
template <typename Function>
void NodeListViewModel::Data::forInst(
  eagine::identifier_t instId,
  Function function) const {
    const auto hostIdPos = inst2Host.find(instId);
    if(hostIdPos != inst2Host.end()) {
        const auto hostId = hostIdPos->second;
        const auto hostPos = hosts.find(hostId);
        if(hostPos != hosts.end()) {
            const auto& hostInfo = hostPos->second;
            const auto instPos = hostInfo.instances.find(instId);
            if(instPos != hostInfo.instances.end()) {
                const auto& instInfo = instPos->second;
                function(instInfo);
            }
        }
    }
}
//------------------------------------------------------------------------------
template <typename Function>
void NodeListViewModel::Data::forNode(
  eagine::identifier_t nodeId,
  Function function) const {
    const auto instIdPos = node2Inst.find(nodeId);
    if(instIdPos != node2Inst.end()) {
        const auto instId = instIdPos->second;
        const auto hostIdPos = inst2Host.find(instId);
        if(hostIdPos != inst2Host.end()) {
            const auto hostId = hostIdPos->second;
            const auto hostPos = hosts.find(hostId);
            if(hostPos != hosts.end()) {
                const auto& hostInfo = hostPos->second;
                const auto instPos = hostInfo.instances.find(instId);
                if(instPos != hostInfo.instances.end()) {
                    const auto& instInfo = instPos->second;
                    const auto nodePos = instInfo.nodes.find(nodeId);
                    if(nodePos != instInfo.nodes.end()) {
                        const auto& nodeInfo = nodePos->second;
                        function(nodeInfo);
                    }
                }
            }
        }
    }
}
//------------------------------------------------------------------------------
// NodeListViewModel
//------------------------------------------------------------------------------
NodeListViewModel::NodeListViewModel(MonitorBackend& backend)
  : QAbstractItemModel{nullptr}
  , eagine::main_ctx_object{EAGINE_ID(NodeListVM), backend}
  , _backend{backend} {
    connect(
      &_backend,
      &MonitorBackend::trackerModelChanged,
      this,
      &NodeListViewModel::onTrackerModelChanged);
}
//------------------------------------------------------------------------------
void NodeListViewModel::onTrackerModelChanged() {
    if(auto trackerModel{_backend.trackerModel()}) {
        connect(
          trackerModel,
          &TrackerModel::nodeAppeared,
          this,
          &NodeListViewModel::onNodeAppeared);
    }
}
//------------------------------------------------------------------------------
void NodeListViewModel::onNodeAppeared(eagine::msgbus::remote_node& node) {
    if(node) {
        const auto hostId = extract_or(node.host().id(), 0U);
        const auto instId = extract_or(node.instance().id(), 0U);
        const auto nodeId = extract_or(node.id(), 0U);
        auto& entry = _model.hosts[hostId].instances[instId].nodes[nodeId];
        if(!entry.node) {
            entry.node = node;
            _model.node2Inst[nodeId] = instId;
            _model.inst2Host[instId] = hostId;
            emit modelReset({});
        }
    }
}
//------------------------------------------------------------------------------
auto NodeListViewModel::roleNames() const -> QHash<int, QByteArray> {
    QHash<int, QByteArray> result;
    result.insert(NodeListViewModel::itemKindRole, "itemKind");
    result.insert(NodeListViewModel::identifierRole, "identifier");
    result.insert(NodeListViewModel::displayNameRole, "displayName");
    result.insert(NodeListViewModel::descriptionRole, "description");
    result.insert(NodeListViewModel::childCountRole, "childCount");
    return result;
}
//------------------------------------------------------------------------------
auto NodeListViewModel::index(int row, int, const QModelIndex&) const
  -> QModelIndex {
    int skip = row;
    for(auto& [hostId, host] : _model.hosts) {
        if(!skip) {
            return QAbstractItemModel::createIndex(row, 0, hostId);
        }
        skip--;
        auto subtotal = host.totalCount();
        if(skip < subtotal) {
            for(auto& [instId, inst] : host.instances) {
                if(!skip) {
                    return QAbstractItemModel::createIndex(row, 1, instId);
                }
                skip--;
                subtotal = inst.totalCount();
                if(skip < subtotal) {
                    return QAbstractItemModel::createIndex(
                      row, 2, inst.id(skip));
                }
                skip -= subtotal;
            }
        }
        skip -= subtotal;
    }
    return {};
}
//------------------------------------------------------------------------------
auto NodeListViewModel::parent(const QModelIndex&) const -> QModelIndex {
    return {};
}
//------------------------------------------------------------------------------
auto NodeListViewModel::columnCount(const QModelIndex&) const -> int {
    return 3;
}
//------------------------------------------------------------------------------
auto NodeListViewModel::rowCount(const QModelIndex&) const -> int {
    return _model.totalCount();
}
//------------------------------------------------------------------------------
auto NodeListViewModel::itemKindData(
  const eagine::msgbus::remote_node& node) const -> QVariant {
    switch(node.kind()) {
        case eagine::msgbus::node_kind::router:
            return {"Router"};
        case eagine::msgbus::node_kind::bridge:
            return {"Bridge"};
        case eagine::msgbus::node_kind::endpoint:
            return {"Endpoint"};
        case eagine::msgbus::node_kind::unknown:
            break;
    }
    return {"Node"};
}
//------------------------------------------------------------------------------
auto NodeListViewModel::identifierData(
  const eagine::msgbus::remote_node& node) const -> QVariant {
    return {QString::number(extract(node.id()))};
}
//------------------------------------------------------------------------------
auto NodeListViewModel::displayNameData(
  const eagine::msgbus::remote_node& node) const -> QVariant {
    if(auto optStr{node.display_name()}) {
        return {c_str(extract(optStr))};
    }
    return {};
}
//------------------------------------------------------------------------------
auto NodeListViewModel::descriptionData(
  const eagine::msgbus::remote_node& node) const -> QVariant {
    if(auto optStr{node.description()}) {
        return {c_str(extract(optStr))};
    }
    return {};
}
//------------------------------------------------------------------------------
auto NodeListViewModel::data(const QModelIndex& index, int role) const
  -> QVariant {
    QVariant result;
    if(role == NodeListViewModel::identifierRole) {
        result = {QString::number(index.internalId())};
    } else if(index.column() == 0) {
        const auto hostId = index.internalId();
        if(role == NodeListViewModel::itemKindRole) {
            result = {"Host"};
        } else {
            _model.forHost(hostId, [this, role, &result](auto& info) {
                if(role == NodeListViewModel::childCountRole) {
                    result = {info.count()};
                }
            });
        }
    } else if(index.column() == 1) {
        const auto instId = index.internalId();
        if(role == NodeListViewModel::itemKindRole) {
            result = {"Instance"};
        } else {
            _model.forInst(instId, [this, role, &result](auto& info) {
                if(role == NodeListViewModel::childCountRole) {
                    result = {info.count()};
                }
            });
        }
    } else {
        const auto nodeId = index.internalId();
        _model.forNode(nodeId, [this, role, &result](auto& info) {
            auto& node = info.node;
            if(role == NodeListViewModel::itemKindRole) {
                result = itemKindData(node);
            } else if(role == NodeListViewModel::displayNameRole) {
                result = displayNameData(node);
            } else if(role == NodeListViewModel::descriptionRole) {
                result = descriptionData(node);
            } else if(role == NodeListViewModel::childCountRole) {
                result = 1;
            }
        });
    }
    return result;
}
//------------------------------------------------------------------------------
