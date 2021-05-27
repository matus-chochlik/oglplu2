///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///

#include "TilingModel.hpp"
#include "TilingBackend.hpp"
#include <eagine/memory/span_algo.hpp>
#include <eagine/message_bus.hpp>
#include <QVariant>
#include <algorithm>
//------------------------------------------------------------------------------
TilingModel::TilingModel(TilingBackend& backend)
  : QObject{nullptr}
  , eagine::main_ctx_object{EAGINE_ID(TilngModel), backend}
  , _backend{backend}
  , _bus{EAGINE_ID(TrckrEndpt), *this}
  , _tiling{_bus} {
    setup_bus_connectors(_tiling);

    auto& info = _tiling.provided_endpoint_info();
    info.display_name = "sudoku tiling generator";
    info.description = "sudoku tiling solver/generator GUI application";

    _tiling.tiles_generated_4.connect(
      EAGINE_THIS_MEM_FUNC_REF(onFragmentAdded));

    reinitialize(
      extract_or(app_config().get<int>("msg_bus.sudoku.solver.width"), 64),
      extract_or(app_config().get<int>("msg_bus.sudoku.solver.height"), 64));
}
//------------------------------------------------------------------------------
void TilingModel::update() {
    _tiling.process_all();
    _tiling.update();
    if(_tiling.solution_timeouted(eagine::unsigned_constant<4>{})) {
        reinitialize(_width, _height);
    }
}
//------------------------------------------------------------------------------
void TilingModel::reinitialize(int w, int h) {
    if((_width != w) || (_height != h)) {
        _width = w;
        _height = h;
        _cellCache.resize(eagine::std_size(w * h));
    }
    zero(eagine::cover(_cellCache));
    _progress = -1.F;

    _tiling.reinitialize(
      {_width, _height},
      eagine::default_sudoku_board_traits<4>()
        .make_generator()
        .generate_medium());
    _backend.onTilingReset();
    emit reinitialized();
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
auto TilingModel::getCellChar(int row, int column) const noexcept -> char {
    const auto k = eagine::std_size(row * _width + column);
    return _cellCache[k];
}
//------------------------------------------------------------------------------
auto TilingModel::getProgress() const noexcept -> QVariant {
    if(_progress >= 0.F) {
        return {_progress};
    }
    return {};
}
//------------------------------------------------------------------------------
auto TilingModel::getCell(int row, int column) const noexcept -> QVariant {
    if(const char c{getCellChar(row, column)}) {
        const char s[2] = {c, '\0'};
        return {static_cast<const char*>(s)};
    }
    return {};
}
//------------------------------------------------------------------------------
void TilingModel::onFragmentAdded(
  eagine::identifier_t helperId,
  const eagine::msgbus::sudoku_tiles<4>& tiles,
  const std::tuple<int, int>& fragCoord) {
    _backend.onHelperContributed(helperId);

    const auto fragment = tiles.get_fragment(fragCoord);
    fragment.for_each_cell(
      [this](const auto& coord, const auto& offs, const auto& glyph) {
          if(auto glyphStr{_traits_4.to_string(glyph)}) {
              const auto column = std::get<0>(coord) + std::get<0>(offs);
              const auto row = std::get<1>(coord) + std::get<1>(offs);
              const auto k = eagine::std_size(row * _width + column);
              _cellCache[k] = extract(glyphStr).front();
          }
      });
    if(const auto total = _cellCache.size()) {
        const auto todo =
          std::count(_cellCache.begin(), _cellCache.end(), '\0');
        _progress = {float(total - todo) / float(total)};
    } else {
        _progress = -1.F;
    }
    emit fragmentAdded();
}
//------------------------------------------------------------------------------
