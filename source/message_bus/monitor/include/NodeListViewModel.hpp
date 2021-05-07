///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///

#ifndef EAGINE_MESSAGE_BUS_MONITOR_NODE_LIST_VIEW_MODEL
#define EAGINE_MESSAGE_BUS_MONITOR_NODE_LIST_VIEW_MODEL

#include <eagine/flat_map.hpp>
#include <eagine/main_ctx_object.hpp>
#include <eagine/message_bus/remote_node.hpp>
#include <QAbstractItemModel>
#include <QObject>

class MonitorBackend;
class NodeParameterModel;
class HostParameterModel;
//------------------------------------------------------------------------------
class NodeListViewModel
  : public QAbstractItemModel
  , public eagine::main_ctx_object {
    Q_OBJECT

    using remote_node = eagine::msgbus::remote_node;
    using remote_inst = eagine::msgbus::remote_instance;
    using remote_host = eagine::msgbus::remote_host;

    Q_PROPERTY(int selectedRow READ getSelectedRow NOTIFY selectedRowChanged)
public:
    NodeListViewModel(MonitorBackend&);

    auto roleNames() const -> QHash<int, QByteArray> final;
    auto index(int row, int column, const QModelIndex& parent = {}) const
      -> QModelIndex final;
    auto parent(const QModelIndex& child) const -> QModelIndex final;
    auto columnCount(const QModelIndex& parent) const -> int final;
    auto rowCount(const QModelIndex& parent) const -> int final;

    auto itemKindData(const remote_node&) const -> QVariant;
    auto identifierData(const remote_node&) const -> QVariant;
    auto displayNameData(const remote_host&) const -> QVariant;
    auto displayNameData(const remote_inst&) const -> QVariant;
    auto displayNameData(const remote_node&) const -> QVariant;
    auto descriptionData(const remote_node&) const -> QVariant;
    auto isResponsiveData(const remote_host&) const -> QVariant;
    auto isResponsiveData(const remote_inst&) const -> QVariant;
    auto isResponsiveData(const remote_node&) const -> QVariant;

    auto data(const QModelIndex& index, int role) const -> QVariant final;

    auto getSelectedRow() const noexcept -> int;

    Q_INVOKABLE void onItemSelected(int row);
signals:
    void selectedRowChanged();
    void itemSelected(
      eagine::identifier_t,
      eagine::identifier_t,
      eagine::identifier_t);
    void itemUnselected();

private slots:
    void onTrackerModelChanged();
    void onNodeChanged(const remote_node&);
    void onNodeDisappeared(eagine::identifier_t);
    void onInstanceInfoChanged(const remote_inst&);
    void onHostInfoChanged(const remote_host&);

private:
    void afterHierarchyChanged();

    enum { hostItem = 0, instItem = 1, nodeItem = 2 };
    enum {
        displayNameRole = Qt::DisplayRole,
        descriptionRole = Qt::ToolTipRole,
        itemKindRole = Qt::UserRole + 0,
        identifierRole = Qt::UserRole + 1,
        isResponsiveRole = Qt::UserRole + 2,
        childCountRole = Qt::UserRole + 3
    };

    MonitorBackend& _backend;

    struct NodeInfo {
        remote_node node;
        std::shared_ptr<NodeParameterModel> parameters;
        auto totalCount() const noexcept -> int;
        void update(MonitorBackend&) noexcept;
    };

    struct InstanceInfo {
        remote_inst instance;
        eagine::flat_map<eagine::identifier_t, NodeInfo> nodes;

        auto count() const noexcept -> int;
        auto subCount() const noexcept -> int;
        auto totalCount() const noexcept -> int;
        auto indexOk(int i) const noexcept -> bool;
        auto id(int i) const noexcept -> eagine::identifier_t;
    };

    struct HostInfo {
        remote_host host;
        std::shared_ptr<HostParameterModel> parameters;
        eagine::flat_map<eagine::identifier_t, InstanceInfo> instances;

        auto count() const noexcept -> int;
        auto subCount() const noexcept -> int;
        auto totalCount() const noexcept -> int;
        void update(MonitorBackend&) noexcept;
    };

    struct Data {
        eagine::flat_map<eagine::identifier_t, HostInfo> hosts;
        eagine::flat_map<eagine::identifier_t, eagine::identifier_t> node2Inst;
        eagine::flat_map<eagine::identifier_t, eagine::identifier_t> inst2Host;

        eagine::identifier_t selectedHostId{0U};
        eagine::identifier_t selectedInstId{0U};
        eagine::identifier_t selectedNodeId{0U};

        auto totalCount() const noexcept -> int;

        template <typename Function>
        auto forHost(eagine::identifier_t hostId, Function function) const
          -> bool;

        template <typename Function>
        auto forInst(eagine::identifier_t instId, Function function) const
          -> bool;

        template <typename Function>
        auto forNode(eagine::identifier_t nodeId, Function function) const
          -> bool;

        auto updateSelection() noexcept -> bool;

        auto rowOf(eagine::identifier_t) const noexcept -> int;
        auto rowOf(eagine::identifier_t, eagine::identifier_t) const noexcept
          -> int;
        auto rowOf(
          eagine::identifier_t,
          eagine::identifier_t,
          eagine::identifier_t) const noexcept -> int;

        auto findSelectedRow() const noexcept -> int;

        void fixupHierarchy(
          eagine::identifier_t hostId,
          eagine::identifier_t instId,
          eagine::identifier_t nodeId);

        auto updateNode(MonitorBackend&, const remote_node&) -> int;
        auto removeNode(eagine::identifier_t) -> bool;
        auto updateInst(MonitorBackend&, const remote_inst&) -> int;
        auto updateHost(MonitorBackend&, const remote_host&) -> int;
    } _model;

    int _selectedRow{-1};

    void _select(
      eagine::identifier_t hostId,
      eagine::identifier_t instId,
      eagine::identifier_t nodeId);
    void _unselect();
};
//------------------------------------------------------------------------------
#endif
