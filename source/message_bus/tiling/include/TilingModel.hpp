///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///

#ifndef EAGINE_MESSAGE_BUS_TILING_MODEL
#define EAGINE_MESSAGE_BUS_TILING_MODEL

#include <eagine/main_ctx_object.hpp>
#include <eagine/message_bus/service.hpp>
#include <eagine/message_bus/service/common_info.hpp>
#include <eagine/message_bus/service/ping_pong.hpp>
#include <eagine/message_bus/service/sudoku.hpp>
#include <QObject>

class TilingBackend;
//------------------------------------------------------------------------------
class TilingModel
  : public QObject
  , public eagine::main_ctx_object {
    Q_OBJECT

public:
    TilingModel(TilingBackend&);

    void update();

    void reinitialize(int w, int h);

    auto getWidth() const noexcept -> int;
    auto getHeight() const noexcept -> int;
    auto getCellChar(int row, int column) const noexcept -> char;
    auto getCell(int row, int column) const noexcept -> QVariant;

    auto getProgress() const noexcept -> QVariant;

signals:
    void reinitialized();
    void fragmentAdded();

private:
    TilingBackend& _backend;

    void onHelperAppeared(eagine::identifier_t);
    void onFragmentAdded(
      eagine::identifier_t,
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
    float _progress{-1.F};
};
//------------------------------------------------------------------------------
#endif
