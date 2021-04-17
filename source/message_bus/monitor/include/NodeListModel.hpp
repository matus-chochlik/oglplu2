///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_MONITOR_NODE_LIST_MODEL
#define EAGINE_MESSAGE_BUS_MONITOR_NODE_LIST_MODEL

#include <eagine/main_ctx_object.hpp>
#include <QObject>

class MonitorBackend;
//------------------------------------------------------------------------------
class NodeListModel
  : public QObject
  , public eagine::main_ctx_object {
    Q_OBJECT

public:
    NodeListModel(MonitorBackend&);

public slots:
    void onTrackerModelChanged();
    void onNodeAppeared(eagine::identifier_t nodeId);

private:
    MonitorBackend& _backend;
};
//------------------------------------------------------------------------------
#endif
