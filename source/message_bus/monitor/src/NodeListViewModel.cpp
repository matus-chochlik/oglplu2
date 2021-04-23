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
// NodeInfo
//------------------------------------------------------------------------------
auto NodeListViewModel::NodeInfo::totalCount() const noexcept -> int {
    return 1;
}
//------------------------------------------------------------------------------
void NodeListViewModel::NodeInfo::update() {}
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
void NodeListViewModel::InstanceInfo::update() {}
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
void NodeListViewModel::HostInfo::update() {}
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
auto NodeListViewModel::Data::updateNode(const remote_node& node) -> int {
    const auto hostId = extract_or(node.host().id(), 0U);
    const auto instId = extract_or(node.instance().id(), 0U);
    const auto nodeId = extract(node.id());

    const auto prevInstIdPos = node2Inst.find(nodeId);
    if(prevInstIdPos != node2Inst.end()) {
        auto& hostInfo = hosts[hostId];
        auto& instInfo = hostInfo.instances[instId];

        if(hostId && instId) {
            const auto prevInstId = prevInstIdPos->second;
            const auto prevHostIdPos = inst2Host.find(prevInstId);
            EAGINE_ASSERT(prevHostIdPos != inst2Host.end());
            const auto prevHostId = prevHostIdPos->second;

            const auto prevHostPos = hosts.find(prevHostId);
            EAGINE_ASSERT(prevHostPos != hosts.end());
            auto& prevHostInfo = prevHostPos->second;
            const auto prevInstPos = prevHostInfo.instances.find(prevInstId);
            EAGINE_ASSERT(prevInstPos != prevHostInfo.instances.end());
            auto& prevInstInfo = prevInstPos->second;
            const auto prevNodePos = prevInstInfo.nodes.find(nodeId);
            EAGINE_ASSERT(prevNodePos != prevInstInfo.nodes.end());
            auto& prevNodeInfo = prevNodePos->second;

            bool relocated = false;
            if(instId != prevInstId) {
                if(!instInfo.instance) {
                    instInfo.instance = node.instance();
                }
                auto& nodeInfo = instInfo.nodes[nodeId];
                nodeInfo = std::move(prevNodeInfo);
                EAGINE_ASSERT(nodeInfo.node);

                node2Inst[nodeId] = instId;
                inst2Host[instId] = hostId;
                prevInstInfo.nodes.erase(prevNodePos);
                relocated = true;
            }

            if(hostId != prevHostId) {
                if(!hostInfo.host) {
                    hostInfo.host = node.host();
                }
                for(auto& [otherNodeId, otherNodeInfo] : prevInstInfo.nodes) {
                    instInfo.nodes[otherNodeId] = std::move(otherNodeInfo);
                    node2Inst[otherNodeId] = instId;
                }

                inst2Host[instId] = hostId;
                prevInstInfo.nodes.clear();
                relocated = true;
            }

            if(prevInstInfo.nodes.empty()) {
                prevHostInfo.instances.erase(prevInstPos);
                relocated = true;
            }

            if(prevHostInfo.instances.empty()) {
                hosts.erase(prevHostPos);
                relocated = true;
            }

            if(relocated) {
                return -1;
            }
        }

        int row = 2;
        for(auto& hostEntry : hosts) {
            if(hostEntry.first == hostId) {
                for(auto& instEntry : hostEntry.second.instances) {
                    if(instEntry.first == instId) {
                        for(auto& nodeEntry : instEntry.second.nodes) {
                            if(nodeEntry.first == nodeId) {
                                nodeEntry.second.update();
                                return row;
                            }
                            row += nodeEntry.second.totalCount();
                        }
                    }
                    row += instEntry.second.totalCount();
                }
            }
            row += hostEntry.second.totalCount();
        }
        EAGINE_UNREACHABLE();
    }

    auto& nodeInfo = hosts[hostId].instances[instId].nodes[nodeId];
    nodeInfo.node = node;
    node2Inst[nodeId] = instId;
    inst2Host[instId] = hostId;
    return -1;
}
//------------------------------------------------------------------------------
auto NodeListViewModel::Data::updateInst(const remote_inst& inst) -> int {
    const auto hostId = extract_or(inst.host().id(), 0U);
    const auto hostPos = hosts.find(hostId);
    if(hostPos != hosts.end()) {
        auto& hostInfo = hostPos->second;
        auto& instances = hostInfo.instances;
        const auto instId = extract_or(inst.id(), 0U);
        const auto instPos = instances.find(instId);
        if(instPos != instances.end()) {
            auto& instInfo = instPos->second;
            if(!instInfo.instance) {
                instInfo.instance = inst;
            }
            instInfo.update();
            int row = 1;
            for(auto it = hosts.begin(); it != hostPos; ++it) {
                row += it->second.totalCount();
            }
            for(auto it = instances.begin(); it != instPos; ++it) {
                row += it->second.totalCount();
            }
            return row;
        }
    }
    return -1;
}
//------------------------------------------------------------------------------
auto NodeListViewModel::Data::updateHost(const remote_host& host) -> int {
    const auto hostId = extract_or(host.id(), 0U);
    const auto hostPos = hosts.find(hostId);
    if(hostPos != hosts.end()) {
        auto& hostInfo = hostPos->second;
        if(!hostInfo.host) {
            hostInfo.host = host;
        }
        hostInfo.update();
        int row = 0;
        for(auto it = hosts.begin(); it != hostPos; ++it) {
            row += it->second.totalCount();
        }
        return row;
    }
    return -1;
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
          &TrackerModel::nodeKindChanged,
          this,
          &NodeListViewModel::onNodeChanged);
        connect(
          trackerModel,
          &TrackerModel::nodeRelocated,
          this,
          &NodeListViewModel::onNodeChanged);
        connect(
          trackerModel,
          &TrackerModel::nodeInfoChanged,
          this,
          &NodeListViewModel::onNodeChanged);
        connect(
          trackerModel,
          &TrackerModel::instanceInfoChanged,
          this,
          &NodeListViewModel::onInstanceInfoChanged);
        connect(
          trackerModel,
          &TrackerModel::hostInfoChanged,
          this,
          &NodeListViewModel::onHostInfoChanged);
    }
}
//------------------------------------------------------------------------------
void NodeListViewModel::onNodeChanged(const remote_node& node) {
    if(node) {
        if(int row = _model.updateNode(node); row >= 0) {
            const auto nodeId = extract(node.id());
            emit dataChanged(
              QAbstractItemModel::createIndex(row, 0, nodeId),
              QAbstractItemModel::createIndex(row, 2, nodeId));
        } else {
            emit modelReset({});
        }
    }
}
//------------------------------------------------------------------------------
void NodeListViewModel::onInstanceInfoChanged(const remote_inst& inst) {
    if(inst) {
        if(const auto row = _model.updateInst(inst); row >= 0) {
            const auto instId = extract_or(inst.id(), 0U);
            emit dataChanged(
              QAbstractItemModel::createIndex(row, 0, instId),
              QAbstractItemModel::createIndex(row, 2, instId));
        }
    }
}
//------------------------------------------------------------------------------
void NodeListViewModel::onHostInfoChanged(const remote_host& host) {
    if(host) {
        if(const auto row = _model.updateHost(host); row >= 0) {
            const auto hostId = extract_or(host.id(), 0U);
            emit dataChanged(
              QAbstractItemModel::createIndex(row, 0, hostId),
              QAbstractItemModel::createIndex(row, 2, hostId));
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
    result.insert(NodeListViewModel::isResponsiveRole, "isResponsive");
    result.insert(NodeListViewModel::childCountRole, "childCount");
    return result;
}
//------------------------------------------------------------------------------
void NodeListViewModel::onItemSelected(int row) {
    if(row < 0) {
        emit itemSelected(0, 0, 0);
        return;
    }
    int skip = row;
    for(auto& [hostId, host] : _model.hosts) {
        if(!skip) {
            emit itemSelected(hostId, 0, 0);
            return;
        }
        skip--;
        auto subtotal = host.subCount();
        if(skip < subtotal) {
            for(auto& [instId, inst] : host.instances) {
                if(!skip) {
                    emit itemSelected(hostId, instId, 0);
                    return;
                }
                skip--;
                subtotal = inst.subCount();
                if(skip < subtotal) {
                    emit itemSelected(hostId, instId, inst.id(skip));
                    return;
                }
                skip -= subtotal;
            }
        }
        skip -= subtotal;
    }
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
auto NodeListViewModel::itemKindData(const remote_node& node) const
  -> QVariant {
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
    return {"UnknownNode"};
}
//------------------------------------------------------------------------------
auto NodeListViewModel::identifierData(const remote_node& node) const
  -> QVariant {
    return {QString::number(extract(node.id()))};
}
//------------------------------------------------------------------------------
auto NodeListViewModel::displayNameData(const remote_host& host) const
  -> QVariant {
    if(auto optStr{host.name()}) {
        return {c_str(extract(optStr))};
    }
    return {};
}
//------------------------------------------------------------------------------
auto NodeListViewModel::displayNameData(const remote_inst& inst) const
  -> QVariant {
    if(auto optStr{inst.application_name()}) {
        return {c_str(extract(optStr))};
    }
    return {};
}
//------------------------------------------------------------------------------
auto NodeListViewModel::displayNameData(const remote_node& node) const
  -> QVariant {
    if(auto optStr{node.display_name()}) {
        return {c_str(extract(optStr))};
    }
    return {};
}
//------------------------------------------------------------------------------
auto NodeListViewModel::descriptionData(const remote_node& node) const
  -> QVariant {
    if(auto optStr{node.description()}) {
        return {c_str(extract(optStr))};
    }
    return {};
}
//------------------------------------------------------------------------------
auto NodeListViewModel::isResponsiveData(const remote_host& host) const
  -> QVariant {
    return {host.is_alive()};
}
//------------------------------------------------------------------------------
auto NodeListViewModel::isResponsiveData(const remote_inst& inst) const
  -> QVariant {
    return {inst.is_alive()};
}
//------------------------------------------------------------------------------
auto NodeListViewModel::isResponsiveData(const remote_node& node) const
  -> QVariant {
    if(node.is_responsive()) {
        return {true};
    }
    if(!node.is_responsive()) {
        return {false};
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
            if(hostId) {
                result = {"Host"};
            } else {
                result = {"UnknownHost"};
            }
        } else {
            _model.forHost(hostId, [this, role, &result](auto& info) {
                if(role == NodeListViewModel::childCountRole) {
                    result = {info.count()};
                } else if(role == NodeListViewModel::displayNameRole) {
                    result = displayNameData(info.host);
                } else if(role == NodeListViewModel::isResponsiveRole) {
                    result = isResponsiveData(info.host);
                }
            });
        }
    } else if(index.column() == instItem) {
        const auto instId = index.internalId();
        if(role == NodeListViewModel::itemKindRole) {
            if(instId) {
                result = {"Instance"};
            } else {
                result = {"UnknownInstance"};
            }
        } else {
            _model.forInst(instId, [this, role, &result](auto& info) {
                if(role == NodeListViewModel::childCountRole) {
                    result = {info.count()};
                } else if(role == NodeListViewModel::displayNameRole) {
                    result = displayNameData(info.instance);
                } else if(role == NodeListViewModel::isResponsiveRole) {
                    result = isResponsiveData(info.instance);
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
            } else if(role == NodeListViewModel::isResponsiveRole) {
                result = isResponsiveData(node);
            } else if(role == NodeListViewModel::childCountRole) {
                result = {0};
            }
        });
    }
    return result;
}
//------------------------------------------------------------------------------

