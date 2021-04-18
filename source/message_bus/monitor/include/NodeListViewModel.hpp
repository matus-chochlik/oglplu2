///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_MONITOR_NODE_LIST_VIEW_MODEL
#define EAGINE_MESSAGE_BUS_MONITOR_NODE_LIST_VIEW_MODEL

#include <eagine/flat_map.hpp>
#include <eagine/main_ctx_object.hpp>
#include <eagine/message_bus/remote_node.hpp>
#include <QAbstractItemModel>
#include <QObject>
#include <algorithm>

class MonitorBackend;
//------------------------------------------------------------------------------
class NodeListViewModel
  : public QAbstractItemModel
  , public eagine::main_ctx_object {
    Q_OBJECT

public:
    NodeListViewModel(MonitorBackend&);

    auto roleNames() const -> QHash<int, QByteArray> final;
    auto index(int row, int column, const QModelIndex& parent) const
      -> QModelIndex final;
    auto parent(const QModelIndex& child) const -> QModelIndex final;
    auto columnCount(const QModelIndex& parent) const -> int final;
    auto rowCount(const QModelIndex& parent) const -> int final;

    auto itemKindData(const eagine::msgbus::remote_node&) const -> QVariant;
    auto identifierData(const eagine::msgbus::remote_node&) const -> QVariant;
    auto displayNameData(const eagine::msgbus::remote_node&) const -> QVariant;
    auto descriptionData(const eagine::msgbus::remote_node&) const -> QVariant;
    auto data(const QModelIndex& index, int role) const -> QVariant final;

public slots:
    void onNodeAppeared(eagine::msgbus::remote_node&);

private slots:
    void onTrackerModelChanged();

private:
    enum {
        itemKindRole = Qt::UserRole + 0,
        identifierRole = Qt::UserRole + 1,
        displayNameRole = Qt::UserRole + 2,
        descriptionRole = Qt::UserRole + 3
    };

    MonitorBackend& _backend;

    struct NodeInfo {
        eagine::msgbus::remote_node node;
    };

    struct InstanceInfo {
        eagine::msgbus::remote_instance instance;
        eagine::flat_map<eagine::identifier_t, NodeInfo> nodes;

        auto totalCount() const noexcept {
            return eagine::limit_cast<int>(nodes.size());
        }

        auto indexOk(int i) const noexcept -> bool {
            return (i >= 0) && (i < eagine::limit_cast<int>(nodes.size()));
        }

        auto id(int i) const noexcept -> auto {
            EAGINE_ASSERT(indexOk(i));
            return (nodes.begin() + i)->first;
        }

        auto at(int i) const noexcept -> auto& {
            EAGINE_ASSERT(indexOk(i));
            return (nodes.begin() + i)->second;
        }
    };

    struct HostInfo {
        eagine::msgbus::remote_host hosts;
        eagine::flat_map<eagine::identifier_t, InstanceInfo> instances;

        auto totalCount() const noexcept {
            return std::accumulate(
              instances.begin(), instances.end(), 0, [](int s, auto& e) {
                  return s + e.second.totalCount();
              });
        }

        auto indexOk(int i) const noexcept -> bool {
            return (i >= 0) && (i < eagine::limit_cast<int>(instances.size()));
        }

        auto at(int i) const noexcept -> auto& {
            EAGINE_ASSERT(indexOk(i));
            return (instances.begin() + i)->second;
        }
    };

    struct {
        eagine::flat_map<eagine::identifier_t, HostInfo> hosts;
        eagine::flat_map<eagine::identifier_t, eagine::identifier_t> node2Inst;
        eagine::flat_map<eagine::identifier_t, eagine::identifier_t> inst2Host;

        auto totalCount() const noexcept {
            return std::accumulate(
              hosts.begin(), hosts.end(), 0, [](int s, auto& e) {
                  return s + e.second.totalCount();
              });
        }

        auto indexOf(eagine::identifier_t id) const noexcept -> int {
            const auto pos = hosts.find(id);
            return eagine::limit_cast<int>(pos - hosts.begin());
        }

        auto indexOk(int i) const noexcept -> bool {
            return (i >= 0) && (i < eagine::limit_cast<int>(hosts.size()));
        }

        auto at(int i) const noexcept -> auto& {
            EAGINE_ASSERT(indexOk(i));
            return (hosts.begin() + i)->second;
        }

        template <typename Function>
        void forNode(eagine::identifier_t nodeId, Function function) const {
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
                                function(nodeInfo.node);
                            }
                        }
                    }
                }
            }
        }
    } _model;
};
//------------------------------------------------------------------------------
#endif
