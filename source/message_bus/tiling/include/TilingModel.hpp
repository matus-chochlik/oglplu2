///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_TILING_MODEL
#define EAGINE_MESSAGE_BUS_TILING_MODEL

#include <eagine/main_ctx_object.hpp>
#include <QObject>

//------------------------------------------------------------------------------
class TilingModel
  : public QObject
  , public eagine::main_ctx_object {
    Q_OBJECT

public:
    TilingModel(eagine::main_ctx_parent);

    void update();

    auto getWidth() const noexcept -> int;
    auto getHeight() const noexcept -> int;
    auto getTile(int row, int column) const noexcept -> QVariant;

signals:
public slots:
private:
};
//------------------------------------------------------------------------------
#endif
