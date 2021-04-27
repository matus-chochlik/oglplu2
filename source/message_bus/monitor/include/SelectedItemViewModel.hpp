///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_MONITOR_SELECTED_ITEM_VIEW_MODEL
#define EAGINE_MESSAGE_BUS_MONITOR_SELECTED_ITEM_VIEW_MODEL

#include "HostViewModel.hpp"
#include "InstViewModel.hpp"
#include "NodeViewModel.hpp"
#include <eagine/main_ctx_object.hpp>
#include <QObject>
#include <QUrl>

class MonitorBackend;
class NodeListViewModel;
//------------------------------------------------------------------------------
class SelectedItemViewModel
  : public QObject
  , public eagine::main_ctx_object {
    Q_OBJECT

    Q_PROPERTY(QString itemKind READ getItemKind NOTIFY itemSelectionChanged)

    Q_PROPERTY(QUrl itemViewUrl READ getItemViewUrl NOTIFY itemSelectionChanged)
    Q_PROPERTY(QUrl hostViewUrl READ getHostViewUrl NOTIFY itemSelectionChanged)
    Q_PROPERTY(QUrl instViewUrl READ getInstViewUrl NOTIFY itemSelectionChanged)
    Q_PROPERTY(QUrl nodeViewUrl READ getNodeViewUrl NOTIFY itemSelectionChanged)

    Q_PROPERTY(
      HostViewModel* host READ getHostViewModel NOTIFY itemSelectionChanged)
    Q_PROPERTY(
      InstViewModel* inst READ getInstViewModel NOTIFY itemSelectionChanged)
    Q_PROPERTY(
      NodeViewModel* node READ getNodeViewModel NOTIFY itemSelectionChanged)
public:
    SelectedItemViewModel(MonitorBackend&, NodeListViewModel&);

    auto getItemKind() -> QString;

    auto getItemViewUrl() -> QUrl;
    auto getHostViewUrl() -> QUrl;
    auto getInstViewUrl() -> QUrl;
    auto getNodeViewUrl() -> QUrl;

    auto getHostViewModel() -> HostViewModel*;
    auto getInstViewModel() -> InstViewModel*;
    auto getNodeViewModel() -> NodeViewModel*;

signals:
    void itemSelectionChanged();
    void hostChanged(eagine::identifier_t);
    void instChanged(eagine::identifier_t);
    void nodeChanged(eagine::identifier_t);

private slots:
    void onItemInfoChanged();
    void onItemSelected(
      eagine::identifier_t,
      eagine::identifier_t,
      eagine::identifier_t);
    void onItemUnselected();

private:
    MonitorBackend& _backend;
    NodeListViewModel& _nodeListViewModel;
    HostViewModel _hostViewModel;
    InstViewModel _instViewModel;
    NodeViewModel _nodeViewModel;

    bool _itemSelected{false};
};
//------------------------------------------------------------------------------
#endif
