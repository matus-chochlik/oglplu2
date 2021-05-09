///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <QDebug>

#include "MonitorBackend.hpp"
#include "NodeListViewModel.hpp"
#include "TrackerModel.hpp"
#include <algorithm>
//------------------------------------------------------------------------------
// NodeInfo
//------------------------------------------------------------------------------
auto NodeListViewModel::NodeInfo::totalCount() const noexcept -> int {
    return 1;
}
//------------------------------------------------------------------------------
void NodeListViewModel::NodeInfo::update(MonitorBackend& backend) noexcept {
    if(!parameters) {
        if(auto nodeId{node.id()}) {
            if(auto trackerModel{backend.trackerModel()}) {
                parameters =
                  extract(trackerModel).nodeParameters(extract(nodeId));
            }
        }
    }
}
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
void NodeListViewModel::HostInfo::update(MonitorBackend& backend) noexcept {
    if(!parameters) {
        if(auto hostId{host.id()}) {
            if(auto trackerModel{backend.trackerModel()}) {
                parameters =
                  extract(trackerModel).hostParameters(extract(hostId));
            }
        }
    }
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
auto NodeListViewModel::Data::forHost(
  eagine::identifier_t hostId,
  Function function) const -> bool {
    const auto hostPos = hosts.find(hostId);
    if(hostPos != hosts.end()) {
        const auto& hostInfo = hostPos->second;
        function(hostInfo);
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
template <typename Function>
auto NodeListViewModel::Data::forInst(
  eagine::identifier_t instId,
  Function function) const -> bool {
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
                return true;
            }
        }
    }
    return false;
}
//------------------------------------------------------------------------------
template <typename Function>
auto NodeListViewModel::Data::forNode(
  eagine::identifier_t nodeId,
  Function function) const -> bool {
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
            if(nodePos != instInfo.nodes.end()) {
                const auto& nodeInfo = nodePos->second;
                function(nodeInfo);
                return true;
            }
        }
    }
    return false;
}
//------------------------------------------------------------------------------
auto NodeListViewModel::Data::updateSelection() noexcept -> bool {
    bool updated = false;
    if(selectedNodeId) {
        const auto instIdPos = node2Inst.find(selectedNodeId);
        if(instIdPos != node2Inst.end()) {
            const auto instId = instIdPos->second;
            if(selectedInstId != instId) {
                selectedInstId = instId;
                updated = true;
            }
            const auto hostIdPos = inst2Host.find(selectedInstId);
            if(hostIdPos != inst2Host.end()) {
                const auto hostId = hostIdPos->second;
                if(selectedHostId != hostId) {
                    selectedHostId = hostId;
                    updated = true;
                }
            }
        } else {
            selectedNodeId = 0U;
            selectedInstId = 0U;
            selectedHostId = 0U;
            updated = true;
        }
    }
    return updated;
}
//------------------------------------------------------------------------------
auto NodeListViewModel::Data::rowOf(eagine::identifier_t hostId) const noexcept
  -> int {
    int row = 0;
    for(auto& hostEntry : hosts) {
        if(hostEntry.first == hostId) {
            return row;
        }
        row += hostEntry.second.totalCount();
    }
    return -1;
}
//------------------------------------------------------------------------------
auto NodeListViewModel::Data::rowOf(
  eagine::identifier_t hostId,
  eagine::identifier_t instId) const noexcept -> int {
    int row = 1;
    for(auto& hostEntry : hosts) {
        if(hostEntry.first == hostId) {
            for(auto& instEntry : hostEntry.second.instances) {
                if(instEntry.first == instId) {
                    return row;
                }
                row += instEntry.second.totalCount();
            }
        }
        row += hostEntry.second.totalCount();
    }
    return -1;
}
//------------------------------------------------------------------------------
auto NodeListViewModel::Data::rowOf(
  eagine::identifier_t hostId,
  eagine::identifier_t instId,
  eagine::identifier_t nodeId) const noexcept -> int {
    int row = 2;
    for(auto& hostEntry : hosts) {
        if(hostEntry.first == hostId) {
            for(auto& instEntry : hostEntry.second.instances) {
                if(instEntry.first == instId) {
                    for(auto& nodeEntry : instEntry.second.nodes) {
                        if(nodeEntry.first == nodeId) {
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
    return -1;
}
//------------------------------------------------------------------------------
auto NodeListViewModel::Data::findSelectedRow() const noexcept -> int {
    if(selectedNodeId) {
        return rowOf(selectedHostId, selectedInstId, selectedNodeId);
    }
    if(selectedInstId) {
        return rowOf(selectedHostId, selectedInstId);
    }
    return rowOf(selectedHostId);
}
//------------------------------------------------------------------------------
void NodeListViewModel::Data::fixupHierarchy(
  eagine::identifier_t hostId,
  eagine::identifier_t instId,
  eagine::identifier_t nodeId) {
    for(auto& hostEntry : hosts) {
        auto& hostInfo = hostEntry.second;
        for(auto& instEntry : hostInfo.instances) {
            auto& instInfo = instEntry.second;

            instInfo.nodes.erase(
              std::remove_if(
                instInfo.nodes.begin(),
                instInfo.nodes.end(),
                [this, nodeId, instId, &instEntry](auto& nodeEntry) {
                    if((instEntry.first != instId) && (nodeEntry.first == nodeId)) {
                        node2Inst.erase(nodeId);
                        return true;
                    }
                    node2Inst[nodeEntry.first] = instEntry.first;
                    return false;
                }),
              instInfo.nodes.end());
        }
        hostInfo.instances.erase(
          std::remove_if(
            hostInfo.instances.begin(),
            hostInfo.instances.end(),
            [this, instId, hostId, &hostEntry](auto& instEntry) {
                if((hostEntry.first != hostId) && (instEntry.first == instId)) {
                    inst2Host.erase(instId);
                    return true;
                }
                inst2Host[instEntry.first] = hostEntry.first;
                return false;
            }),
          hostInfo.instances.end());
    }
    hosts.erase(
      std::remove_if(
        hosts.begin(),
        hosts.end(),
        [](auto& hostEntry) { return hostEntry.second.instances.empty(); }),
      hosts.end());
}
//------------------------------------------------------------------------------
auto NodeListViewModel::Data::updateNode(
  MonitorBackend& backend,
  const remote_node& node) -> int {
    const auto inst = node.instance();
    const auto nodeId = extract(node.id());
    const auto instId = extract_or(inst.id(), 0U);
    const auto hostId = instId ? extract_or(inst.host().id(), 0U) : 0U;

    const auto prevInstIdPos = node2Inst.find(nodeId);
    auto& hostInfo = hosts[hostId];
    hostInfo.update(backend);
    auto& instInfo = hostInfo.instances[instId];
    if(prevInstIdPos != node2Inst.end()) {

        if(hostId && instId) {
            bool relocated = false;
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

            if(instId != prevInstId) {
                if(!instInfo.instance) {
                    instInfo.instance = node.instance();
                }
                node2Inst[nodeId] = instId;

                auto& nodeInfo = instInfo.nodes[nodeId];
                nodeInfo.update(backend);
                const auto prevNodePos = prevInstInfo.nodes.find(nodeId);
                if(prevNodePos != prevInstInfo.nodes.end()) {
                    auto& prevNodeInfo = prevNodePos->second;
                    nodeInfo = std::move(prevNodeInfo);
                    prevInstInfo.nodes.erase(prevNodePos);
                } else {
                    nodeInfo.node = node;
                }

                EAGINE_ASSERT(nodeInfo.node);
                relocated = true;
            }

            if(hostId != prevHostId) {
                if(!hostInfo.host) {
                    hostInfo.host = inst.host();
                }
                inst2Host[instId] = hostId;

                if(prevInstId) {
                    for(auto& [otherNodeId, otherNodeInfo] :
                        prevInstInfo.nodes) {
                        auto& nodeInfo = instInfo.nodes[otherNodeId];
                        nodeInfo = std::move(otherNodeInfo);
                        nodeInfo.update(backend);
                        node2Inst[otherNodeId] = instId;
                    }

                    prevInstInfo.nodes.clear();
                }
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
                fixupHierarchy(hostId, instId, nodeId);
                return -1;
            }
        }

        return rowOf(hostId, instId, nodeId);
    }

    auto& nodeInfo = instInfo.nodes[nodeId];
    nodeInfo.update(backend);
    nodeInfo.node = node;
    node2Inst[nodeId] = instId;
    inst2Host[instId] = hostId;
    fixupHierarchy(hostId, instId, nodeId);
    return -1;
}
//------------------------------------------------------------------------------
auto NodeListViewModel::Data::removeNode(eagine::identifier_t nodeId) -> bool {
    node2Inst.erase(nodeId);
    std::size_t erased = 0;

    for(auto& hostEntry : hosts) {
        auto& hostInfo = hostEntry.second;
        hostInfo.instances.erase(
          std::remove_if(
            hostInfo.instances.begin(),
            hostInfo.instances.end(),
            [nodeId, &erased](auto& instEntry) {
                auto& instInfo = instEntry.second;
                erased += instInfo.nodes.erase(nodeId);
                if(instInfo.nodes.empty()) {
                    ++erased;
                    return true;
                }
                return false;
            }),
          hostInfo.instances.end());
    }
    hosts.erase(
      std::remove_if(
        hosts.begin(),
        hosts.end(),
        [&erased](auto& hostEntry) {
            auto& hostInfo = hostEntry.second;
            if(hostInfo.instances.empty()) {
                ++erased;
                return true;
            }
            return false;
        }),
      hosts.end());
    return erased > 0;
}
//------------------------------------------------------------------------------
auto NodeListViewModel::Data::updateInst(
  MonitorBackend&,
  const remote_inst& inst) -> int {
    const auto instId = extract_or(inst.id(), 0U);
    const auto hostId = instId ? extract_or(inst.host().id(), 0U) : 0U;

    const auto hostPos = hosts.find(hostId);
    if(hostPos != hosts.end()) {
        auto& hostInfo = hostPos->second;
        auto& instances = hostInfo.instances;
        const auto instPos = instances.find(instId);
        if(instPos != instances.end()) {
            auto& instInfo = instPos->second;
            if(!instInfo.instance) {
                instInfo.instance = inst;
            }
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
auto NodeListViewModel::Data::updateHost(
  MonitorBackend&,
  const remote_host& host) -> int {
    const auto hostId = extract_or(host.id(), 0U);
    const auto hostPos = hosts.find(hostId);
    if(hostPos != hosts.end()) {
        auto& hostInfo = hostPos->second;
        if(!hostInfo.host) {
            hostInfo.host = host;
        }
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
        connect(
          trackerModel,
          &TrackerModel::nodeDisappeared,
          this,
          &NodeListViewModel::onNodeDisappeared);
    }
}
//------------------------------------------------------------------------------
void NodeListViewModel::afterHierarchyChanged() {
    const bool updated = _model.updateSelection();
    _selectedRow = _model.findSelectedRow();
    emit selectedRowChanged();
    if(updated) {
        if(_selectedRow < 0) {
            emit itemUnselected();
        } else {
            emit itemSelected(
              _model.selectedHostId,
              _model.selectedInstId,
              _model.selectedNodeId);
        }
    }
    emit modelReset({});
}
//------------------------------------------------------------------------------
void NodeListViewModel::onNodeChanged(const remote_node& node) {
    if(node) {
        if(int row = _model.updateNode(_backend, node); row >= 0) {
            const auto nodeId = extract(node.id());
            emit dataChanged(
              QAbstractItemModel::createIndex(row, 0, nodeId),
              QAbstractItemModel::createIndex(row + 1, 2, nodeId));
        } else {
            afterHierarchyChanged();
        }
    }
}
//------------------------------------------------------------------------------
void NodeListViewModel::onNodeDisappeared(eagine::identifier_t nodeId) {
    if(_model.removeNode(nodeId)) {
        afterHierarchyChanged();
    }
}
//------------------------------------------------------------------------------
void NodeListViewModel::onInstanceInfoChanged(const remote_inst& inst) {
    if(inst) {
        if(const auto row = _model.updateInst(_backend, inst); row >= 0) {
            const auto instId = extract_or(inst.id(), 0U);
            emit dataChanged(
              QAbstractItemModel::createIndex(row, 0, instId),
              QAbstractItemModel::createIndex(row + 1, 2, instId));
        }
    }
}
//------------------------------------------------------------------------------
void NodeListViewModel::onHostInfoChanged(const remote_host& host) {
    if(host) {
        if(const auto row = _model.updateHost(_backend, host); row >= 0) {
            const auto hostId = extract_or(host.id(), 0U);
            emit dataChanged(
              QAbstractItemModel::createIndex(row, 0, hostId),
              QAbstractItemModel::createIndex(row + 1, 2, hostId));
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
void NodeListViewModel::_select(
  eagine::identifier_t hostId,
  eagine::identifier_t instId,
  eagine::identifier_t nodeId) {
    _model.selectedHostId = hostId;
    _model.selectedInstId = instId;
    _model.selectedNodeId = nodeId;
    emit itemSelected(hostId, instId, nodeId);
}
//------------------------------------------------------------------------------
void NodeListViewModel::_unselect() {
    _model.selectedHostId = 0U;
    _model.selectedInstId = 0U;
    _model.selectedNodeId = 0U;
    emit itemUnselected();
}
//------------------------------------------------------------------------------
void NodeListViewModel::onItemSelected(int row) {
    _selectedRow = row;
    emit selectedRowChanged();

    if(row < 0 || row >= _model.totalCount()) {
        _unselect();
        return;
    }
    int skip = row;
    for(auto& [hostId, host] : _model.hosts) {
        if(!skip) {
            _select(hostId, 0, 0);
            return;
        }
        skip--;
        auto subtotal = host.subCount();
        if(skip < subtotal) {
            for(auto& [instId, inst] : host.instances) {
                if(!skip) {
                    _select(hostId, instId, 0);
                    return;
                }
                skip--;
                subtotal = inst.subCount();
                if(skip < subtotal) {
                    _select(hostId, instId, inst.id(skip));
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
        if(!_model.forNode(nodeId, [this, role, &result](auto& info) {
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
           })) {
            if(role == NodeListViewModel::itemKindRole) {
                result = {"UnknownNode"};
            }
        }
    }
    return result;
}
//------------------------------------------------------------------------------
auto NodeListViewModel::getSelectedRow() const noexcept -> int {
    return _selectedRow;
}
//------------------------------------------------------------------------------

