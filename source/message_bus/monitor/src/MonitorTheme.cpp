///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include "MonitorTheme.hpp"
//------------------------------------------------------------------------------
MonitorTheme::MonitorTheme(eagine::main_ctx_parent parent)
  : QObject{nullptr}
  , eagine::main_ctx_object{EAGINE_ID(Theme), parent} {}
//------------------------------------------------------------------------------
void MonitorTheme::setLight(bool value) {
    _light = value;
    emit lightChanged();
}
//------------------------------------------------------------------------------
auto MonitorTheme::getLight() const -> bool {
    return _light;
}
//------------------------------------------------------------------------------
auto MonitorTheme::getNodeListItemWidth() -> int {
    return 350;
}
//------------------------------------------------------------------------------
auto MonitorTheme::getNodeListItemHeight() -> int {
    return 56;
}
//------------------------------------------------------------------------------
auto MonitorTheme::getNodeListIconSize() -> int {
    return 48;
}
//------------------------------------------------------------------------------
