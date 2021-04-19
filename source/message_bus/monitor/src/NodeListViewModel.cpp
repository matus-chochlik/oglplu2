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
auto NodeListViewModel::InstanceInfo::subCount() const noexcept -> int {
    return count();
}
//------------------------------------------------------------------------------
auto NodeListViewModel::InstanceInfo::totalCount() const noexcept -> int {
    return subCount() + 1;
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
auto NodeListViewModel::HostInfo::subCount() const noexcept -> int {
    return std::accumulate(
      instances.begin(), instances.end(), 0, [](int s, auto& e) {
          return s + e.second.totalCount();
      });
}
//------------------------------------------------------------------------------
auto NodeListViewModel::HostInfo::totalCount() const noexcept -> int {
    return std::accumulate(
      instances.begin(), instances.end(), 1, [](int s, auto& e) {
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
            EAGINE_ASSERT(hostPos != hosts.end());
            const auto& hostInfo = hostPos->second;
            const auto instPos = hostInfo.instances.find(instId);
            EAGINE_ASSERT(instPos != hostInfo.instances.end());
            const auto& instInfo = instPos->second;
            const auto nodePos = instInfo.nodes.find(nodeId);
            EAGINE_ASSERT(nodePos != instInfo.nodes.end());
            const auto& nodeInfo = nodePos->second;
            function(nodeInfo);
        }
    }
}
//------------------------------------------------------------------------------
void NodeListViewModel::Data::addNode(eagine::msgbus::remote_node& node) {
    const auto hostId = extract_or(node.host().id(), 0U);
    const auto instId = extract_or(node.instance().id(), 0U);
    const auto nodeId = extract_or(node.id(), 0U);

    auto& nodeInfo = hosts[hostId].instances[instId].nodes[nodeId];
    nodeInfo.node = node;
    node2Inst[nodeId] = instId;
    inst2Host[instId] = hostId;
}
//------------------------------------------------------------------------------
void NodeListViewModel::Data::moveNode(eagine::msgbus::remote_node& node) {
    const auto nodeId = extract(node.id());
    if(auto inst{node.instance()}) {
        const auto instId = extract(inst.id());
        if(auto host{inst.host()}) {
            const auto hostId = extract(host.id());
            auto& hostInfo = hosts[hostId];
            auto& instInfo = hostInfo.instances[instId];
            const auto prevInstIdPos = node2Inst.find(nodeId);
            if(prevInstIdPos != node2Inst.end()) {
                const auto prevInstId = prevInstIdPos->second;
                const auto prevHostIdPos = inst2Host.find(prevInstId);
                EAGINE_ASSERT(prevHostIdPos != inst2Host.end());
                const auto prevHostId = prevHostIdPos->second;
                if((instId != prevInstId) || (hostId != prevHostId)) {
                    const auto prevHostPos = hosts.find(prevHostId);
                    EAGINE_ASSERT(prevHostPos != hosts.end());
                    auto& prevHostInfo = prevHostPos->second;
                    const auto prevInstPos =
                      prevHostInfo.instances.find(prevInstId);
                    EAGINE_ASSERT(prevInstPos != prevHostInfo.instances.end());
                    auto& prevInstInfo = prevInstPos->second;
                    const auto prevNodePos = prevInstInfo.nodes.find(nodeId);
                    EAGINE_ASSERT(prevNodePos != prevInstInfo.nodes.end());
                    auto& prevNodeInfo = prevNodePos->second;

                    if(instId != prevInstId) {
                        if(!instInfo.instance) {
                            instInfo.instance = inst;
                        }
                        auto& nodeInfo = instInfo.nodes[nodeId];
                        nodeInfo = std::move(prevNodeInfo);
                        EAGINE_ASSERT(nodeInfo.node);

                        node2Inst[nodeId] = instId;
                        prevInstInfo.nodes.erase(prevNodePos);
                    }

                    if(hostId != prevHostId) {
                        if(!hostInfo.host) {
                            hostInfo.host = node.host();
                        }
                        for(auto& [otherNodeId, otherNodeInfo] :
                            prevInstInfo.nodes) {
                            instInfo.nodes[otherNodeId] =
                              std::move(otherNodeInfo);
                            node2Inst[otherNodeId] = instId;
                        }

                        inst2Host[instId] = hostId;
                        prevInstInfo.nodes.clear();
                    }

                    if(prevInstInfo.nodes.empty()) {
                        prevHostInfo.instances.erase(prevInstPos);
                    }

                    if(prevHostInfo.instances.empty()) {
                        hosts.erase(prevHostPos);
                    }
                }
            } else {
                auto& nodeInfo = hosts[hostId].instances[instId].nodes[nodeId];
                nodeInfo.node = node;
                node2Inst[nodeId] = instId;
                inst2Host[instId] = hostId;
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
        connect(
          trackerModel,
          &TrackerModel::nodeRelocated,
          this,
          &NodeListViewModel::onNodeRelocated);
    }
}
//------------------------------------------------------------------------------
void NodeListViewModel::onNodeAppeared(eagine::msgbus::remote_node& node) {
    if(node) {
        _model.addNode(node);
        emit modelReset({});
    }
}
//------------------------------------------------------------------------------
void NodeListViewModel::onNodeRelocated(eagine::msgbus::remote_node& node) {
    if(node) {
        _model.moveNode(node);
        emit modelReset({});
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
            return QAbstractItemModel::createIndex(row, hostItem, hostId);
        }
        skip--;
        auto subtotal = host.subCount();
        if(skip < subtotal) {
            for(auto& [instId, inst] : host.instances) {
                if(!skip) {
                    return QAbstractItemModel::createIndex(
                      row, instItem, instId);
                }
                skip--;
                subtotal = inst.subCount();
                if(skip < subtotal) {
                    return QAbstractItemModel::createIndex(
                      row, nodeItem, inst.id(skip));
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
    return {"Unknown"};
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
    } else if(index.column() == hostItem) {
        const auto hostId = index.internalId();
        if(role == NodeListViewModel::itemKindRole) {
            result = {"Host"};
        } else {
            _model.forHost(hostId, [role, &result](auto& info) {
                if(role == NodeListViewModel::childCountRole) {
                    result = {info.count()};
                }
            });
        }
    } else if(index.column() == instItem) {
        const auto instId = index.internalId();
        if(role == NodeListViewModel::itemKindRole) {
            result = {"Instance"};
        } else {
            _model.forInst(instId, [role, &result](auto& info) {
                if(role == NodeListViewModel::childCountRole) {
                    result = {info.count()};
                }
            });
        }
    } else if(index.column() == nodeItem) {
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
                result = {0};
            }
        });
    }
    return result;
}
//------------------------------------------------------------------------------
