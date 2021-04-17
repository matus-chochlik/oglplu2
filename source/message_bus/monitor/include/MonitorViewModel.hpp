///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_MONITOR_MONITOR_VIEW_MODEL
#define EAGINE_MESSAGE_BUS_MONITOR_MONITOR_VIEW_MODEL

#include <eagine/main_ctx_object.hpp>
#include <QObject>

class MonitorBackend;
class TrackerModel;
//------------------------------------------------------------------------------
class MonitorViewModel
  : public QObject
  , public eagine::main_ctx_object {
    Q_OBJECT

public:
    MonitorViewModel(MonitorBackend&);

public slots:
private:
    MonitorBackend& _backend;
};
//------------------------------------------------------------------------------
#endif
