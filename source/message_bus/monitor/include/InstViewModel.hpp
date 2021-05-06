
///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///

#ifndef EAGINE_MESSAGE_BUS_MONITOR_INST_VIEW_MODEL
#define EAGINE_MESSAGE_BUS_MONITOR_INST_VIEW_MODEL

#include <eagine/main_ctx_object.hpp>
#include <eagine/message_bus/remote_node.hpp>
#include <QObject>
#include <QVariant>

class MonitorBackend;
class SelectedItemViewModel;
//------------------------------------------------------------------------------
class InstViewModel
  : public QObject
  , public eagine::main_ctx_object {
    Q_OBJECT

    Q_PROPERTY(QVariant identifier READ getIdentifier NOTIFY infoChanged)
    Q_PROPERTY(QVariant displayName READ getDisplayName NOTIFY infoChanged)
    Q_PROPERTY(QVariant description READ getDescription NOTIFY infoChanged)

    Q_PROPERTY(QVariant architecture READ getArchitecture NOTIFY infoChanged)

    Q_PROPERTY(QVariant compilerName READ getCompilerName NOTIFY infoChanged)
    Q_PROPERTY(QVariant compilerVersionMajor READ getCompilerVersionMajor NOTIFY
                 infoChanged)
    Q_PROPERTY(QVariant compilerVersionMinor READ getCompilerVersionMinor NOTIFY
                 infoChanged)
    Q_PROPERTY(QVariant compilerVersionPatch READ getCompilerVersionPatch NOTIFY
                 infoChanged)

    Q_PROPERTY(QVariant versionMajor READ getVersionMajor NOTIFY infoChanged)
    Q_PROPERTY(QVariant versionMinor READ getVersionMinor NOTIFY infoChanged)
    Q_PROPERTY(QVariant versionPatch READ getVersionPatch NOTIFY infoChanged)
    Q_PROPERTY(QVariant versionCommit READ getVersionCommit NOTIFY infoChanged)

    using remote_inst = eagine::msgbus::remote_instance;

public:
    InstViewModel(MonitorBackend&, SelectedItemViewModel&);

    explicit operator bool() const noexcept {
        return bool(_inst.id());
    }

    auto getItemKind() -> QString;
    auto getIdentifier() -> QVariant;
    auto getDisplayName() -> QVariant;
    auto getDescription() -> QVariant;

    auto getArchitecture() -> QVariant;

    auto getCompilerName() -> QVariant;
    auto getCompilerVersionMajor() -> QVariant;
    auto getCompilerVersionMinor() -> QVariant;
    auto getCompilerVersionPatch() -> QVariant;

    auto getVersionMajor() -> QVariant;
    auto getVersionMinor() -> QVariant;
    auto getVersionPatch() -> QVariant;
    auto getVersionCommit() -> QVariant;
signals:
    void infoChanged();

private slots:
    void onTrackerModelChanged();
    void onInstIdChanged(eagine::identifier_t instId);
    void onInstInfoChanged(const remote_inst& inst);

private:
    MonitorBackend& _backend;
    remote_inst _inst;
};
//------------------------------------------------------------------------------
#endif
