///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include "TilingModel.hpp"
#include <eagine/memory/span_algo.hpp>
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

    _tiling.tiles_generated_4.connect(
      EAGINE_THIS_MEM_FUNC_REF(onFragmentAdded));

    reinitialize(64, 64);
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
        zero(eagine::cover(_cellCache));
    }

    _tiling.reinitialize(
      {_width, _height},
      eagine::default_sudoku_board_traits<4>()
        .make_generator()
        .generate_medium());
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
auto TilingModel::getTile(int row, int column) const noexcept -> QVariant {
    const auto k = eagine::std_size(row * _width + column);
    const auto c = _cellCache[k];
    if(c) {
        const char s[2] = {c, '\0'};
        return {static_cast<const char*>(s)};
    }
    return {};
}
//------------------------------------------------------------------------------
void TilingModel::onFragmentAdded(
  const eagine::msgbus::sudoku_tiles<4>& tiles,
  const std::tuple<int, int>& frag_coord) {
    const auto fragment = tiles.get_fragment(frag_coord);
    fragment.for_each_cell(
      [this](const auto& coord, const auto& offs, const auto& glyph) {
          if(auto glyphStr{_traits_4.to_string(glyph)}) {
              const auto column = std::get<0>(coord) + std::get<0>(offs);
              const auto row = std::get<1>(coord) + std::get<1>(offs);
              const auto k = eagine::std_size(row * _width + column);
              _cellCache[k] = extract(glyphStr).front();
          }
      });
    emit fragmentAdded();
}
//------------------------------------------------------------------------------
