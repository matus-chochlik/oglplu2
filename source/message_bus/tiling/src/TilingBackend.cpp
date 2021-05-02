///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include "TilingBackend.hpp"
#include "TilingModel.hpp"
//------------------------------------------------------------------------------
TilingBackend::TilingBackend(eagine::main_ctx_parent parent)
  : QObject{nullptr}
  , eagine::main_ctx_object{EAGINE_ID(Backend), parent}
  , _tilingModel{std::make_shared<TilingModel>(*this)}
  , _tilingTheme{*this}
  , _tilingViewModel{*this} {
    _timerId = startTimer(20);
}
//------------------------------------------------------------------------------
TilingBackend::~TilingBackend() {
    killTimer(_timerId);
}
//------------------------------------------------------------------------------
void TilingBackend::timerEvent(QTimerEvent*) {
    if(_tilingModel) {
        _tilingModel->update();
    }
}
//------------------------------------------------------------------------------
auto TilingBackend::getTilingModel() noexcept -> TilingModel* {
    return _tilingModel.get();
}
//------------------------------------------------------------------------------
auto TilingBackend::getTilingTheme() noexcept -> TilingTheme* {
    return &_tilingTheme;
}
//------------------------------------------------------------------------------
auto TilingBackend::getTilingViewModel() noexcept -> TilingViewModel* {
    return &_tilingViewModel;
}
//------------------------------------------------------------------------------
