///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
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
