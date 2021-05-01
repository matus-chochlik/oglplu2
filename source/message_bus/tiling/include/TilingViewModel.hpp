///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_TILING_TILING_VIEW_MODEL
#define EAGINE_MESSAGE_BUS_TILING_TILING_VIEW_MODEL

#include <eagine/main_ctx_object.hpp>
#include <QAbstractTableModel>

class TilingBackend;
//------------------------------------------------------------------------------
class TilingViewModel
  : public QAbstractTableModel
  , public eagine::main_ctx_object {
    Q_OBJECT

public:
    TilingViewModel(TilingBackend&);

    auto rowCount(const QModelIndex&) const -> int final;
    auto columnCount(const QModelIndex&) const -> int final;
    auto data(const QModelIndex& index, int role) const -> QVariant final;
    auto roleNames() const -> QHash<int, QByteArray> final;
public slots:

private:
    TilingBackend& _backend;
};
//------------------------------------------------------------------------------
#endif
