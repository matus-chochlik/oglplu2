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

    Q_PROPERTY(QString itemKind READ getItemKind NOTIFY itemSelected)
public:
    SelectedItemViewModel(MonitorBackend&);

    auto getItemKind() -> QString;

signals:
    void itemSelected();
public slots:

private:
    auto _nodeListViewModel() -> NodeListViewModel*;
    MonitorBackend& _backend;
};
//------------------------------------------------------------------------------
#endif
