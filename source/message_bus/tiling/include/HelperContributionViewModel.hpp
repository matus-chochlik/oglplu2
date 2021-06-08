///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///

#ifndef EAGINE_MESSAGE_BUS_HELPER_CONTRIBUTION_VIEW_MODEL
#define EAGINE_MESSAGE_BUS_HELPER_CONTRIBUTION_VIEW_MODEL

#include <eagine/flat_map.hpp>
#include <eagine/main_ctx_object.hpp>
#include <QObject>
#include <QVariant>
#include <tuple>

//------------------------------------------------------------------------------
class HelperContributionViewModel
  : public QObject
  , public eagine::main_ctx_object {
    Q_OBJECT

    Q_PROPERTY(QStringList helperIds READ getHelperIds NOTIFY dataChanged)
    Q_PROPERTY(QVariantList solvedCounts READ getSolvedCounts NOTIFY dataChanged)
    Q_PROPERTY(qreal maxSolvedCount READ getMaxSolvedCount NOTIFY dataChanged)
public:
    HelperContributionViewModel(eagine::main_ctx_parent);

    void helperAppeared(eagine::identifier_t helperId);
    void helperContributed(eagine::identifier_t helperId);

    auto getHelperIds() const -> QStringList;
    auto getSolvedCounts() const -> QVariantList;
    auto getMaxSolvedCount() const -> qreal;
signals:
    void dataChanged();

private:
    eagine::flat_map<eagine::identifier_t, std::tuple<eagine::span_size_t>>
      _contributions;
    eagine::span_size_t _maxCount{1};
};
//------------------------------------------------------------------------------
#endif
