///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///

#include "TilingTheme.hpp"
//------------------------------------------------------------------------------
TilingTheme::TilingTheme(eagine::main_ctx_parent parent)
  : QObject{nullptr}
  , eagine::main_ctx_object{EAGINE_ID(Theme), parent} {}
//------------------------------------------------------------------------------
void TilingTheme::setLight(bool value) {
    _light = value;
    emit lightChanged();
}
//------------------------------------------------------------------------------
auto TilingTheme::getLight() const -> bool {
    return _light;
}
//------------------------------------------------------------------------------
auto TilingTheme::getTileset() const -> QString {
    return "b16";
}
//------------------------------------------------------------------------------
auto TilingTheme::getTileWidth() const -> int {
    return 16;
}
//------------------------------------------------------------------------------
auto TilingTheme::getTileHeight() const -> int {
    return 16;
}
//------------------------------------------------------------------------------
