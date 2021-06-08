///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///

#include "HelperContributionViewModel.hpp"

//------------------------------------------------------------------------------
HelperContributionViewModel::HelperContributionViewModel(
  eagine::main_ctx_parent parent)
  : QObject{nullptr}
  , eagine::main_ctx_object{EAGINE_ID(CntrbModel), parent} {}
//------------------------------------------------------------------------------
void HelperContributionViewModel::helperAppeared(eagine::identifier_t helperId) {
    const auto pos = _contributions.find(helperId);
    if(pos == _contributions.end()) {
        _contributions.emplace(helperId, 0);
        emit dataChanged();
    }
}
//------------------------------------------------------------------------------
void HelperContributionViewModel::helperContributed(
  eagine::identifier_t helperId) {
    auto pos = _contributions.find(helperId);
    if(pos == _contributions.end()) {
        pos = _contributions.emplace(helperId, 0).first;
    }
    auto& [solvedCount] = pos->second;
    ++solvedCount;
    _maxCount = std::max(_maxCount, solvedCount);
    emit dataChanged();
}
//------------------------------------------------------------------------------
auto HelperContributionViewModel::getHelperIds() const -> QStringList {
    QStringList result;
    result.reserve(_contributions.size());
    for(const auto& entry : _contributions) {
        result.append(QString::number(std::get<0>(entry)));
    }
    return result;
}
//------------------------------------------------------------------------------
auto HelperContributionViewModel::getSolvedCounts() const -> QVariantList {
    QVariantList result;
    result.reserve(_contributions.size());
    for(const auto& entry : _contributions) {
        result.append(qlonglong(std::get<0>(std::get<1>(entry))));
    }
    return result;
}
//------------------------------------------------------------------------------
auto HelperContributionViewModel::getMaxSolvedCount() const -> qreal {
    return _maxCount;
}
//------------------------------------------------------------------------------
