///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_MONITOR_NODE_VIEW_MODEL
#define EAGINE_MESSAGE_BUS_MONITOR_NODE_VIEW_MODEL

#include <eagine/main_ctx_object.hpp>
#include <eagine/message_bus/remote_node.hpp>
#include <QObject>
#include <QVariant>

class MonitorBackend;
class SelectedItemViewModel;
//------------------------------------------------------------------------------
class NodeViewModel
  : public QObject
  , public eagine::main_ctx_object {
    Q_OBJECT

    Q_PROPERTY(QVariant identifier READ getIdentifier NOTIFY infoChanged)
    Q_PROPERTY(QVariant displayName READ getDisplayName NOTIFY infoChanged)
    Q_PROPERTY(QVariant description READ getDescription NOTIFY infoChanged)

    Q_PROPERTY(
      QVariant pingSuccessRate READ getPingSuccessRate NOTIFY infoChanged)

    using remote_node = eagine::msgbus::remote_node;

public:
    NodeViewModel(MonitorBackend&, SelectedItemViewModel&);

    explicit operator bool() const noexcept {
        return bool(_node);
    }

    auto getItemKind() -> QString;
    auto getIdentifier() -> QVariant;
    auto getDisplayName() -> QVariant;
    auto getDescription() -> QVariant;

    auto getPingSuccessRate() -> QVariant;

signals:
    void infoChanged();

private slots:
    void onTrackerModelChanged();
    void onNodeIdChanged(eagine::identifier_t nodeId);
    void onNodeInfoChanged(const remote_node& node);

private:
    MonitorBackend& _backend;
    remote_node _node;
};
//------------------------------------------------------------------------------
#endif
