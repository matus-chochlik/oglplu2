///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include "TilingModel.hpp"
#include <eagine/message_bus/conn_setup.hpp>
#include <eagine/message_bus/router_address.hpp>
#include <QVariant>
//------------------------------------------------------------------------------
TilingModel::TilingModel(eagine::main_ctx_parent parent)
  : QObject{nullptr}
  , eagine::main_ctx_object{EAGINE_ID(TilngModel), parent}
  , _bus{EAGINE_ID(TrckrEndpt), *this}
  , _tiling{_bus} {
    eagine::msgbus::router_address address{*this};
    eagine::msgbus::connection_setup conn_setup{*this};
    conn_setup.setup_connectors(_tiling, address);

    _tiling.reinitialize(
      {_width, _height},
      eagine::default_sudoku_board_traits<4>()
        .make_generator()
        .generate_medium());
}
//------------------------------------------------------------------------------
void TilingModel::update() {
    _tiling.process_all();
    _tiling.update();
}
//------------------------------------------------------------------------------
auto TilingModel::getWidth() const noexcept -> int {
    return _width;
}
//------------------------------------------------------------------------------
auto TilingModel::getHeight() const noexcept -> int {
    return _height;
}
//------------------------------------------------------------------------------
auto TilingModel::getTile(int row, int column) const noexcept -> QVariant {
    if(column < 2 * _width - row) {
        // clang-format off
		const QString t[4][4] = {
			{"0", "1", "2", "3"},
			{"4", "5", "6", "7"},
			{"8", "9", "A", "B"},
			{"C", "D", "E", "F"}};
        // clang-format on
        return {t[row % 4][(row + column) % 4]};
    }
    return {};
}
//------------------------------------------------------------------------------
