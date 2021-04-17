///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_MONITOR_BACKEND
#define EAGINE_MESSAGE_BUS_MONITOR_BACKEND

#include <eagine/main_ctx_object.hpp>
#include <QObject>

class MonitorViewModel;
//------------------------------------------------------------------------------
class MonitorBackend
  : public QObject
  , public eagine::main_ctx_object {
    Q_OBJECT

    Q_PROPERTY(MonitorViewModel* monitor READ getMonitor CONSTANT)
public:
    MonitorBackend(eagine::main_ctx_parent);

    auto getMonitor() -> MonitorViewModel*;
public slots:
private:
};
//------------------------------------------------------------------------------
#endif
