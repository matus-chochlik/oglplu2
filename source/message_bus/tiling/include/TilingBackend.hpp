///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///

#ifndef EAGINE_MESSAGE_BUS_TILING_BACKEND
#define EAGINE_MESSAGE_BUS_TILING_BACKEND

#include "HelperContributionViewModel.hpp"
#include "SolutionIntervalViewModel.hpp"
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
    Q_PROPERTY(HelperContributionViewModel* helperContributions READ
                 getHelperContributionViewModel CONSTANT)
    Q_PROPERTY(SolutionIntervalViewModel* solutionIntervals READ
                 getSolutionIntervalViewModel CONSTANT)
public:
    TilingBackend(eagine::main_ctx_parent);
    ~TilingBackend() final;

    auto getTilingModel() noexcept -> TilingModel*;
    auto getTilingTheme() noexcept -> TilingTheme*;
    auto getTilingViewModel() noexcept -> TilingViewModel*;
    auto getHelperContributionViewModel() noexcept
      -> HelperContributionViewModel*;
    auto getSolutionIntervalViewModel() noexcept -> SolutionIntervalViewModel*;
signals:
    void tilingModelChanged();
public slots:
    void onTilingReset();
    void onHelperAppeared(eagine::identifier_t helperId);
    void onHelperContributed(eagine::identifier_t helperId);

private:
    void timerEvent(QTimerEvent*) final;

    int _timerId{0};
    std::shared_ptr<TilingModel> _tilingModel;
    TilingTheme _tilingTheme;
    TilingViewModel _tilingViewModel;
    HelperContributionViewModel _helperContributionViewModel;
    SolutionIntervalViewModel _solutionIntervalViewModel;
};
//------------------------------------------------------------------------------
#endif
