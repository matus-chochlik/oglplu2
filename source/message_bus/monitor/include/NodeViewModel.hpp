///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_MONITOR_NODE_VIEW_MODEL
#define EAGINE_MESSAGE_BUS_MONITOR_NODE_VIEW_MODEL

#include "NodeParameterViewModel.hpp"
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
    Q_PROPERTY(QVariant uptime READ getUptime NOTIFY infoChanged)
    Q_PROPERTY(QVariant sentMessages READ getSentMessages NOTIFY infoChanged)
    Q_PROPERTY(
      QVariant receivedMessages READ getReceivedMessages NOTIFY infoChanged)
    Q_PROPERTY(
      QVariant droppedMessages READ getDroppedMessages NOTIFY infoChanged)
    Q_PROPERTY(
      QVariant messagesPerSecond READ getMessagesPerSecond NOTIFY infoChanged)

    Q_PROPERTY(
      QVariant pingSuccessRate READ getPingSuccessRate NOTIFY infoChanged)

    Q_PROPERTY(QAbstractItemModel* parameters READ getParameters CONSTANT)

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
    auto getUptime() -> QVariant;
    auto getSentMessages() -> QVariant;
    auto getReceivedMessages() -> QVariant;
    auto getDroppedMessages() -> QVariant;
    auto getMessagesPerSecond() -> QVariant;

    auto getPingSuccessRate() -> QVariant;

    auto getParameters() -> QAbstractItemModel*;
signals:
    void infoChanged();

private slots:
    void onTrackerModelChanged();
    void onNodeIdChanged(eagine::identifier_t nodeId);
    void onNodeInfoChanged(const remote_node& node);

private:
    MonitorBackend& _backend;
    NodeParameterViewModel _parameters;
    remote_node _node;
};
//------------------------------------------------------------------------------
#endif
