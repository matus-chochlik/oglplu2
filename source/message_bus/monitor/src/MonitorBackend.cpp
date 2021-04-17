///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include "MonitorBackend.hpp"
//------------------------------------------------------------------------------
// Backend
//------------------------------------------------------------------------------
MonitorBackend::MonitorBackend(eagine::main_ctx_parent parent)
  : QObject{nullptr}
  , eagine::main_ctx_object{EAGINE_ID(Backend), parent} {}
//------------------------------------------------------------------------------
auto MonitorBackend::getMonitor() -> MonitorViewModel* {
    return nullptr;
}
//------------------------------------------------------------------------------
