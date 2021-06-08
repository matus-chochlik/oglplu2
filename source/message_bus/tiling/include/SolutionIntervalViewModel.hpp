///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///

#ifndef EAGINE_MESSAGE_BUS_SOLUTION_INTERVAL_VIEW_MODEL
#define EAGINE_MESSAGE_BUS_SOLUTION_INTERVAL_VIEW_MODEL

#include <eagine/main_ctx_object.hpp>
#include <eagine/value_with_history.hpp>
#include <QObject>
#include <QVariant>
#include <chrono>
#include <tuple>

//------------------------------------------------------------------------------
class SolutionIntervalViewModel
  : public QObject
  , public eagine::main_ctx_object {
    Q_OBJECT

    Q_PROPERTY(QVariantList intervals READ getIntervals NOTIFY dataChanged)
    Q_PROPERTY(qreal maxInterval READ getMaxInterval NOTIFY dataChanged)
public:
    SolutionIntervalViewModel(eagine::main_ctx_parent);

    void tilingReset();
    void helperContributed(eagine::identifier_t helperId);

    auto getIntervals() const -> QVariantList;
    auto getMaxInterval() const -> qreal;
signals:
    void dataChanged();

private:
    std::chrono::steady_clock::time_point _previousSolutionTime{
      std::chrono::steady_clock::now()};
    eagine::variable_with_history<std::chrono::duration<float>, 128> _intervals;
    std::chrono::duration<float> _maxInterval{1.F};
};
//------------------------------------------------------------------------------
#endif
