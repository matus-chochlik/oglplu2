///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_MONITOR_SELECTED_ITEM_VIEW_MODEL
#define EAGINE_MESSAGE_BUS_MONITOR_SELECTED_ITEM_VIEW_MODEL

#include <eagine/main_ctx_object.hpp>
#include <QObject>

class MonitorBackend;
class NodeListViewModel;
//------------------------------------------------------------------------------
class SelectedItemViewModel
  : public QObject
  , public eagine::main_ctx_object {
    Q_OBJECT

    Q_PROPERTY(QString itemKind READ getItemKind NOTIFY itemSelectionChanged)
    Q_PROPERTY(QVariant hostId READ getHostId NOTIFY itemSelectionChanged)
    Q_PROPERTY(QVariant instId READ getInstId NOTIFY itemSelectionChanged)
    Q_PROPERTY(QVariant nodeId READ getNodeId NOTIFY itemSelectionChanged)
public:
    SelectedItemViewModel(MonitorBackend&, NodeListViewModel&);

    auto getItemKind() -> QString;
    auto getHostId() -> QVariant;
    auto getInstId() -> QVariant;
    auto getNodeId() -> QVariant;

signals:
    void itemSelectionChanged();

public slots:
    void onItemSelected(
      eagine::identifier_t,
      eagine::identifier_t,
      eagine::identifier_t);
    void onItemUnselected();

private:
    MonitorBackend& _backend;
    NodeListViewModel& _nodeListViewModel;
    eagine::identifier_t _hostId{0};
    eagine::identifier_t _instId{0};
    eagine::identifier_t _nodeId{0};
    bool _itemSelected{false};
};
//------------------------------------------------------------------------------
#endif
