///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///

#include "HostParameterViewModel.hpp"
#include "MonitorBackend.hpp"
#include "TrackerModel.hpp"

//------------------------------------------------------------------------------
// PickRoleProxyModel
//------------------------------------------------------------------------------
PickRoleProxyModel::PickRoleProxyModel(QAbstractItemModel& parent, int role)
  : QAbstractProxyModel{nullptr}
  , _pickedRole{role} {
    setSourceModel(&parent);
}
//------------------------------------------------------------------------------
auto PickRoleProxyModel::roleNames() const -> QHash<int, QByteArray> {
    auto result = sourceModel()->roleNames();
    result.insert(Qt::DisplayRole, "display");
    return result;
}

//------------------------------------------------------------------------------
auto PickRoleProxyModel::index(int row, int column, const QModelIndex& parent)
  const -> QModelIndex {
    return sourceModel()->index(row, column, parent);
}
//------------------------------------------------------------------------------
auto PickRoleProxyModel::parent(const QModelIndex& child) const -> QModelIndex {
    return sourceModel()->parent(child);
}
//------------------------------------------------------------------------------
auto PickRoleProxyModel::mapFromSource(const QModelIndex& index) const
  -> QModelIndex {
    return index;
}
//------------------------------------------------------------------------------
auto PickRoleProxyModel::mapToSource(const QModelIndex& index) const
  -> QModelIndex {
    return index;
}
//------------------------------------------------------------------------------
auto PickRoleProxyModel::columnCount(const QModelIndex&) const -> int {
    return 1;
}
//------------------------------------------------------------------------------
auto PickRoleProxyModel::rowCount(const QModelIndex& parent) const -> int {
    return sourceModel()->rowCount(parent);
}
//------------------------------------------------------------------------------
auto PickRoleProxyModel::data(const QModelIndex& index, int role) const
  -> QVariant {
    if(role == Qt::DisplayRole) {
        role = _pickedRole;
    }
    return sourceModel()->data(index, role);
}
//------------------------------------------------------------------------------
