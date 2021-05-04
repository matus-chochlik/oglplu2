///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_TILING_MODEL
#define EAGINE_MESSAGE_BUS_TILING_MODEL

#include <eagine/main_ctx_object.hpp>
#include <eagine/message_bus/service.hpp>
#include <eagine/message_bus/service/common_info.hpp>
#include <eagine/message_bus/service/ping_pong.hpp>
#include <eagine/message_bus/service/sudoku.hpp>
#include <QObject>

//------------------------------------------------------------------------------
class TilingModel
  : public QObject
  , public eagine::main_ctx_object {
    Q_OBJECT

public:
    TilingModel(eagine::main_ctx_parent);

    void update();

    void reinitialize(int w, int h);
    auto getWidth() const noexcept -> int;
    auto getHeight() const noexcept -> int;
    auto getTile(int row, int column) const noexcept -> QVariant;

signals:
    void reinitialized();
    void fragmentAdded();

private:
    void onFragmentAdded(
      const eagine::msgbus::sudoku_tiles<4>&,
      const std::tuple<int, int>&);

    eagine::msgbus::endpoint _bus;

    eagine::msgbus::service_composition<eagine::msgbus::pingable<
      eagine::msgbus::common_info_providers<eagine::msgbus::sudoku_tiling<>>>>
      _tiling;

    eagine::default_sudoku_board_traits<4> _traits_4;

    std::vector<char> _cellCache;
    int _width{0};
    int _height{0};
};
//------------------------------------------------------------------------------
#endif
