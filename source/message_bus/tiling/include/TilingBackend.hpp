///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///

#ifndef EAGINE_MESSAGE_BUS_TILING_BACKEND
#define EAGINE_MESSAGE_BUS_TILING_BACKEND

#include "HelperContributionModel.hpp"
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
    Q_PROPERTY(HelperContributionModel* helperContribution READ
                 getHelperContributionModel CONSTANT)
public:
    TilingBackend(eagine::main_ctx_parent);
    ~TilingBackend() final;

    void helperContributed(eagine::identifier_t helperId);

    auto getTilingModel() noexcept -> TilingModel*;
    auto getTilingTheme() noexcept -> TilingTheme*;
    auto getTilingViewModel() noexcept -> TilingViewModel*;
    auto getHelperContributionModel() noexcept -> HelperContributionModel*;
signals:
    void tilingModelChanged();
public slots:
private:
    void timerEvent(QTimerEvent*) final;

    int _timerId{0};
    std::shared_ptr<TilingModel> _tilingModel;
    TilingTheme _tilingTheme;
    TilingViewModel _tilingViewModel;
    HelperContributionModel _helperContributionModel;
};
//------------------------------------------------------------------------------
#endif
