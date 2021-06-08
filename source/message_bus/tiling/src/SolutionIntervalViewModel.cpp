///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///

#include "SolutionIntervalViewModel.hpp"
#include <eagine/iterator.hpp>

//------------------------------------------------------------------------------
SolutionIntervalViewModel::SolutionIntervalViewModel(
  eagine::main_ctx_parent parent)
  : QObject{nullptr}
  , eagine::main_ctx_object{EAGINE_ID(IntvlModel), parent} {}
//------------------------------------------------------------------------------
void SolutionIntervalViewModel::tilingReset() {
    _previousSolutionTime = std::chrono::steady_clock::now();
    _maxInterval = std::chrono::duration<float>{1.F};
}
//------------------------------------------------------------------------------
void SolutionIntervalViewModel::helperContributed(eagine::identifier_t) {
    const auto now = std::chrono::steady_clock::now();
    _intervals.assign(now - _previousSolutionTime);
    _previousSolutionTime = now;
    _maxInterval = std::max(_maxInterval, _intervals.value());
    emit dataChanged();
}
//------------------------------------------------------------------------------
auto SolutionIntervalViewModel::getIntervals() const -> QVariantList {
    QVariantList result;
    result.reserve(_intervals.size());
    for(const auto& value : eagine::reverse(_intervals)) {
        result.append(value.count());
    }
    return result;
}
//------------------------------------------------------------------------------
auto SolutionIntervalViewModel::getMaxInterval() const -> qreal {
    return _maxInterval.count();
}
//------------------------------------------------------------------------------
