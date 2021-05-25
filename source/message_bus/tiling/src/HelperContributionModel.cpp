///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///

#include "HelperContributionModel.hpp"

//------------------------------------------------------------------------------
HelperContributionModel::HelperContributionModel(eagine::main_ctx_parent parent)
  : QObject{nullptr}
  , eagine::main_ctx_object{EAGINE_ID(HlprModel), parent} {}
//------------------------------------------------------------------------------
void HelperContributionModel::helperContributed(eagine::identifier_t helperId) {
    auto pos = _contributions.find(helperId);
    if(pos == _contributions.end()) {
        pos = _contributions.emplace(helperId, 0).first;
    }
    auto& [solvedCount] = pos->second;
    ++solvedCount;
    emit dataChanged();
}
//------------------------------------------------------------------------------
auto HelperContributionModel::getHelperIds() const -> QStringList {
    QStringList result;
    for(const auto& entry : _contributions) {
        result.append(QString::number(std::get<0>(entry)));
    }
    return result;
}
//------------------------------------------------------------------------------
auto HelperContributionModel::getSolvedCounts() const -> QVariantList {
    QVariantList result;
    for(const auto& entry : _contributions) {
        result.append(qlonglong(std::get<0>(std::get<1>(entry))));
    }
    return result;
}
//------------------------------------------------------------------------------
auto HelperContributionModel::getMaxSolvedCount() const -> qreal {
    qreal result = 1;
    for(const auto& entry : _contributions) {
        result = std::max(result, qreal(std::get<0>(std::get<1>(entry))));
    }
    return result;
}
//------------------------------------------------------------------------------
