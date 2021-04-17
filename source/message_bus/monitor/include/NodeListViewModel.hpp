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
    auto data(const QModelIndex& index, int role) const -> QVariant final;

public slots:
    void onNodeAppeared(eagine::msgbus::remote_node&);

private slots:
    void onTrackerModelChanged();

private:
    enum {
        identifierRole = Qt::UserRole + 0,
        itemKindRole = Qt::UserRole + 1,
        displayNameRole = Qt::UserRole + 2,
        descriptionRole = Qt::UserRole + 3
    };

    MonitorBackend& _backend;
    eagine::flat_map<eagine::identifier_t, eagine::msgbus::remote_node> _nodes;
};
//------------------------------------------------------------------------------
#endif
