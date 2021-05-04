///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include "TilingViewModel.hpp"
#include "TilingBackend.hpp"
#include "TilingModel.hpp"
//------------------------------------------------------------------------------
TilingViewModel::TilingViewModel(TilingBackend& backend)
  : QAbstractTableModel{nullptr}
  , eagine::main_ctx_object{EAGINE_ID(TilingVM), backend}
  , _backend{backend} {
    connect(
      &_backend,
      &TilingBackend::tilingModelChanged,
      this,
      &TilingViewModel::onTilingModelChanged);
}
//------------------------------------------------------------------------------
void TilingViewModel::reinitialize(int w, int h) {
    if(auto tilingModel{_backend.getTilingModel()}) {
        extract(tilingModel).reinitialize(w, h);
    }
}
//------------------------------------------------------------------------------
auto TilingViewModel::rowCount(const QModelIndex&) const -> int {
    if(auto tilingModel{_backend.getTilingModel()}) {
        return extract(tilingModel).getHeight();
    }
    return 0;
}
//------------------------------------------------------------------------------
auto TilingViewModel::columnCount(const QModelIndex&) const -> int {
    if(auto tilingModel{_backend.getTilingModel()}) {
        return extract(tilingModel).getWidth();
    }
    return 0;
}
//------------------------------------------------------------------------------
auto TilingViewModel::data(const QModelIndex& index, int role) const
  -> QVariant {
    if(role == Qt::DisplayRole) {
        if(auto tilingModel{_backend.getTilingModel()}) {
            return extract(tilingModel).getTile(index.row(), index.column());
        }
    }
    return {};
}
//------------------------------------------------------------------------------
auto TilingViewModel::roleNames() const -> QHash<int, QByteArray> {
    return {{Qt::DisplayRole, "tile"}};
}
//------------------------------------------------------------------------------
void TilingViewModel::onTilingModelChanged() {
    connect(
      _backend.getTilingModel(),
      &TilingModel::reinitialized,
      this,
      &TilingViewModel::onTilingChanged);
    connect(
      _backend.getTilingModel(),
      &TilingModel::fragmentAdded,
      this,
      &TilingViewModel::onTilingChanged);
    emit modelReset({});
}
//------------------------------------------------------------------------------
void TilingViewModel::onTilingChanged() {
    emit modelReset({});
}
//------------------------------------------------------------------------------

