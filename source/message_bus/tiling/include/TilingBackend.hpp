///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_TILING_BACKEND
#define EAGINE_MESSAGE_BUS_TILING_BACKEND

#include "TilingTheme.hpp"
#include "TilingViewModel.hpp"
#include <eagine/main_ctx_object.hpp>
#include <QObject>
#include <memory>

class TilingModel;
//------------------------------------------------------------------------------
class TilingBackend
  : public QObject
  , public eagine::main_ctx_object {
    Q_OBJECT

    Q_PROPERTY(TilingTheme* theme READ getTilingTheme CONSTANT)
    Q_PROPERTY(TilingViewModel* tiling READ getTilingViewModel CONSTANT)
public:
    TilingBackend(eagine::main_ctx_parent);
    ~TilingBackend() final;

    auto getTilingModel() noexcept -> TilingModel*;
    auto getTilingTheme() noexcept -> TilingTheme*;
    auto getTilingViewModel() noexcept -> TilingViewModel*;
signals:
    void tilingModelChanged();
public slots:
private:
    void timerEvent(QTimerEvent*) final;

    int _timerId{0};
    std::shared_ptr<TilingModel> _tilingModel;
    TilingTheme _tilingTheme;
    TilingViewModel _tilingViewModel;
};
//------------------------------------------------------------------------------
#endif
