///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///

#ifndef EAGINE_MESSAGE_BUS_MONITOR_HOST_VIEW_MODEL
#define EAGINE_MESSAGE_BUS_MONITOR_HOST_VIEW_MODEL

#include <eagine/main_ctx_object.hpp>
#include <eagine/message_bus/remote_node.hpp>
#include <QObject>
#include <QVariant>

class MonitorBackend;
class SelectedItemViewModel;
//------------------------------------------------------------------------------
class HostViewModel
  : public QObject
  , public eagine::main_ctx_object {
    Q_OBJECT

    Q_PROPERTY(QVariant identifier READ getIdentifier NOTIFY infoChanged)
    Q_PROPERTY(QVariant displayName READ getDisplayName NOTIFY infoChanged)
    Q_PROPERTY(QVariant description READ getDescription NOTIFY infoChanged)
    Q_PROPERTY(QVariant cpuThreads READ getCpuThreads NOTIFY infoChanged)
    Q_PROPERTY(QVariant shortLoad READ getShortLoad NOTIFY infoChanged)
    Q_PROPERTY(QVariant shortLoadDelta READ getShortLoadDelta NOTIFY infoChanged)
    Q_PROPERTY(QVariant longLoad READ getLongLoad NOTIFY infoChanged)
    Q_PROPERTY(QVariant longLoadDelta READ getLongLoadDelta NOTIFY infoChanged)
    Q_PROPERTY(QVariant ramTotal READ getRamTotal NOTIFY infoChanged)
    Q_PROPERTY(QVariant ramFree READ getRamFree NOTIFY infoChanged)
    Q_PROPERTY(QVariant ramFreeDelta READ getRamFreeDelta NOTIFY infoChanged)
    Q_PROPERTY(QVariant ramUsage READ getRamUsage NOTIFY infoChanged)
    Q_PROPERTY(QVariant ramUsageDelta READ getRamUsageDelta NOTIFY infoChanged)
    Q_PROPERTY(QVariant swapTotal READ getSwapTotal NOTIFY infoChanged)
    Q_PROPERTY(QVariant swapFree READ getSwapFree NOTIFY infoChanged)
    Q_PROPERTY(QVariant swapFreeDelta READ getSwapFreeDelta NOTIFY infoChanged)
    Q_PROPERTY(QVariant swapUsage READ getSwapUsage NOTIFY infoChanged)
    Q_PROPERTY(QVariant swapUsageDelta READ getSwapUsageDelta NOTIFY infoChanged)

    Q_PROPERTY(QVariant powerSupply READ getPowerSupply NOTIFY infoChanged)

    using remote_host = eagine::msgbus::remote_host;

public:
    HostViewModel(MonitorBackend&, SelectedItemViewModel&);

    explicit operator bool() const noexcept {
        return bool(_host.id());
    }

    auto getItemKind() -> QString;
    auto getIdentifier() -> QVariant;
    auto getDisplayName() -> QVariant;
    auto getDescription() -> QVariant;
    auto getCpuThreads() -> QVariant;
    auto getShortLoad() -> QVariant;
    auto getShortLoadDelta() -> QVariant;
    auto getLongLoad() -> QVariant;
    auto getLongLoadDelta() -> QVariant;
    auto getRamTotal() -> QVariant;
    auto getRamFree() -> QVariant;
    auto getRamFreeDelta() -> QVariant;
    auto getRamUsage() -> QVariant;
    auto getRamUsageDelta() -> QVariant;
    auto getSwapTotal() -> QVariant;
    auto getSwapFree() -> QVariant;
    auto getSwapFreeDelta() -> QVariant;
    auto getSwapUsage() -> QVariant;
    auto getSwapUsageDelta() -> QVariant;

    auto getPowerSupply() -> QVariant;

signals:
    void infoChanged();

private slots:
    void onTrackerModelChanged();
    void onHostIdChanged(eagine::identifier_t hostId);
    void onHostInfoChanged(const remote_host& host);

private:
    MonitorBackend& _backend;
    remote_host _host;
};
//------------------------------------------------------------------------------
#endif
