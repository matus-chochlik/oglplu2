///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_MONITOR_MONITOR_VIEW_MODEL
#define EAGINE_MESSAGE_BUS_MONITOR_MONITOR_VIEW_MODEL

#include "NodeListViewModel.hpp"
#include <eagine/main_ctx_object.hpp>
#include <QObject>

class MonitorBackend;
//------------------------------------------------------------------------------
class MonitorViewModel
  : public QObject
  , public eagine::main_ctx_object {
    Q_OBJECT

    Q_PROPERTY(NodeListViewModel* nodeList READ getNodeListViewModel CONSTANT)
public:
    MonitorViewModel(MonitorBackend&);

    auto getNodeListViewModel() -> NodeListViewModel*;
public slots:

private:
    MonitorBackend& _backend;
    NodeListViewModel _nodeListViewModel;
};
//------------------------------------------------------------------------------
#endif
