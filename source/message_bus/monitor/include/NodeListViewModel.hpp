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
        descriptionRole = Qt::UserRole + 3,
        childCountRole = Qt::UserRole + 4
    };

    MonitorBackend& _backend;

    struct NodeInfo {
        eagine::msgbus::remote_node node;
    };

    struct InstanceInfo {
        eagine::msgbus::remote_instance instance;
        eagine::flat_map<eagine::identifier_t, NodeInfo> nodes;

        auto count() const noexcept {
            return eagine::limit_cast<int>(nodes.size());
        }

        auto totalCount() const noexcept {
            return count();
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

        auto count() const noexcept {
            return eagine::limit_cast<int>(instances.size());
        }

        auto totalCount() const noexcept;

        auto indexOk(int i) const noexcept -> bool {
            return (i >= 0) && (i < eagine::limit_cast<int>(instances.size()));
        }

        auto at(int i) const noexcept -> auto& {
            EAGINE_ASSERT(indexOk(i));
            return (instances.begin() + i)->second;
        }
    };

    struct Data {
        eagine::flat_map<eagine::identifier_t, HostInfo> hosts;
        eagine::flat_map<eagine::identifier_t, eagine::identifier_t> node2Inst;
        eagine::flat_map<eagine::identifier_t, eagine::identifier_t> inst2Host;

        auto totalCount() const noexcept;

        auto indexOk(int i) const noexcept -> bool {
            return (i >= 0) && (i < eagine::limit_cast<int>(hosts.size()));
        }

        auto at(int i) const noexcept -> auto& {
            EAGINE_ASSERT(indexOk(i));
            return (hosts.begin() + i)->second;
        }

        template <typename Function>
        void forHost(eagine::identifier_t hostId, Function function) const;

        template <typename Function>
        void forInst(eagine::identifier_t instId, Function function) const;

        template <typename Function>
        void forNode(eagine::identifier_t nodeId, Function function) const;
    } _model;
};
//------------------------------------------------------------------------------
#endif
