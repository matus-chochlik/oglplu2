///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include "TilingBackend.hpp"
//------------------------------------------------------------------------------
TilingBackend::TilingBackend(eagine::main_ctx_parent parent)
  : QObject{nullptr}
  , eagine::main_ctx_object{EAGINE_ID(Backend), parent}
  , _tilingTheme{*this} {
    _timerId = startTimer(10);
}
//------------------------------------------------------------------------------
TilingBackend::~TilingBackend() {
    killTimer(_timerId);
}
//------------------------------------------------------------------------------
void TilingBackend::timerEvent(QTimerEvent*) {
    // TODO
}
//------------------------------------------------------------------------------
auto TilingBackend::getTilingTheme() noexcept -> TilingTheme* {
    return &_tilingTheme;
}
//------------------------------------------------------------------------------
