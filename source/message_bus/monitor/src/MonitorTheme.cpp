///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
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
auto MonitorTheme::getNodeListHostOffset() -> int {
    return 0;
}
//------------------------------------------------------------------------------
auto MonitorTheme::getNodeListInstOffset() -> int {
    return 25;
}
//------------------------------------------------------------------------------
auto MonitorTheme::getNodeListNodeOffset() -> int {
    return 50;
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
auto MonitorTheme::getItemViewIconSize() -> int {
    return 64;
}
//------------------------------------------------------------------------------
auto MonitorTheme::getNodeListAliveSize() -> int {
    return 12;
}
//------------------------------------------------------------------------------
auto MonitorTheme::getSmallFontSize() -> float {
    return 12;
}
//------------------------------------------------------------------------------
auto MonitorTheme::getNormalFontSize() -> float {
    return 15;
}
//------------------------------------------------------------------------------
auto MonitorTheme::getHugeFontSize() -> float {
    return 30;
}
//------------------------------------------------------------------------------
