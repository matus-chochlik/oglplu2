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
    void onNodeRelocated(eagine::msgbus::remote_node&);

private slots:
    void onTrackerModelChanged();

private:
    enum { hostItem = 0, instItem = 1, nodeItem = 2 };
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

        auto count() const noexcept -> int;
        auto subCount() const noexcept -> int;
        auto totalCount() const noexcept -> int;
        auto indexOk(int i) const noexcept -> bool;
        auto id(int i) const noexcept -> eagine::identifier_t;
    };

    struct HostInfo {
        eagine::msgbus::remote_host host;
        eagine::flat_map<eagine::identifier_t, InstanceInfo> instances;

        auto count() const noexcept -> int;
        auto subCount() const noexcept -> int;
        auto totalCount() const noexcept -> int;
    };

    struct Data {
        eagine::flat_map<eagine::identifier_t, HostInfo> hosts;
        eagine::flat_map<eagine::identifier_t, eagine::identifier_t> node2Inst;
        eagine::flat_map<eagine::identifier_t, eagine::identifier_t> inst2Host;

        auto totalCount() const noexcept -> int;

        template <typename Function>
        void forHost(eagine::identifier_t hostId, Function function) const;

        template <typename Function>
        void forInst(eagine::identifier_t instId, Function function) const;

        template <typename Function>
        void forNode(eagine::identifier_t nodeId, Function function) const;

        void addNode(eagine::msgbus::remote_node&);
        void moveNode(eagine::msgbus::remote_node&);
    } _model;
};
//------------------------------------------------------------------------------
#endif
