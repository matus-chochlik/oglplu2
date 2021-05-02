///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include "TilingModel.hpp"
#include <QVariant>
//------------------------------------------------------------------------------
TilingModel::TilingModel(eagine::main_ctx_parent parent)
  : QObject{nullptr}
  , eagine::main_ctx_object{EAGINE_ID(TilngModel), parent} {}
//------------------------------------------------------------------------------
void TilingModel::update() {
    // TODO
}
//------------------------------------------------------------------------------
auto TilingModel::getWidth() const noexcept -> int {
    return 256;
}
//------------------------------------------------------------------------------
auto TilingModel::getHeight() const noexcept -> int {
    return 256;
}
//------------------------------------------------------------------------------
auto TilingModel::getTile(int row, int column) const noexcept -> QVariant {
    // clang-format off
	const QString t[4][4] = {
		{"0", "1", "2", "3"},
		{"4", "5", "6", "7"},
		{"8", "9", "A", "B"},
		{"C", "D", "E", "F"}};
    // clang-format on
    return {t[row % 4][(row + column) % 4]};
}
//------------------------------------------------------------------------------
