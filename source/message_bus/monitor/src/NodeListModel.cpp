///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include "NodeListModel.hpp"
#include "MonitorBackend.hpp"
#include "TrackerModel.hpp"
//------------------------------------------------------------------------------
NodeListModel::NodeListModel(MonitorBackend& backend)
  : QObject{nullptr}
  , eagine::main_ctx_object{EAGINE_ID(NodeListM), backend}
  , _backend{backend} {
    connect(
      &_backend,
      &MonitorBackend::trackerModelChanged,
      this,
      &NodeListModel::onTrackerModelChanged);
}
//------------------------------------------------------------------------------
void NodeListModel::onTrackerModelChanged() {
    if(auto trackerModel{_backend.trackerModel()}) {
        connect(
          trackerModel,
          &TrackerModel::nodeAppeared,
          this,
          &NodeListModel::onNodeAppeared);
    }
}
//------------------------------------------------------------------------------
void NodeListModel::onNodeAppeared(eagine::identifier_t nodeId) {
    log_warning("node ${id} appeared").arg(EAGINE_ID(id), nodeId);
}
//------------------------------------------------------------------------------
