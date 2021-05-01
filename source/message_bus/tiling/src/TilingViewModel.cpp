///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include "TilingViewModel.hpp"
#include "TilingBackend.hpp"
//------------------------------------------------------------------------------
TilingViewModel::TilingViewModel(TilingBackend& backend)
  : QAbstractTableModel{nullptr}
  , eagine::main_ctx_object{EAGINE_ID(TilingVM), backend}
  , _backend{backend} {}
//------------------------------------------------------------------------------
auto TilingViewModel::rowCount(const QModelIndex&) const -> int {
    return 256;
}
//------------------------------------------------------------------------------
auto TilingViewModel::columnCount(const QModelIndex&) const -> int {
    return 256;
}
//------------------------------------------------------------------------------
auto TilingViewModel::data(const QModelIndex& index, int role) const
  -> QVariant {
    if(role == Qt::DisplayRole) {
        // clang-format off
        const QString t[4][4] = {
			{"0", "1", "2", "3"},
			{"4", "5", "6", "7"},
			{"8", "9", "A", "B"},
			{"C", "D", "E", "F"}};
        // clang-format on
        return {t[index.row() % 4][(index.row() + index.column()) % 4]};
    }
    return {};
}
//------------------------------------------------------------------------------
auto TilingViewModel::roleNames() const -> QHash<int, QByteArray> {
    return {{Qt::DisplayRole, "tile"}};
}
//------------------------------------------------------------------------------

