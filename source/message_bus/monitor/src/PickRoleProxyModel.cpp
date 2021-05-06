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
  : QIdentityProxyModel{nullptr}
  , _pickedRole{role} {
    setSourceModel(&parent);
}
//------------------------------------------------------------------------------
void PickRoleProxyModel::notifyUpdated() {
    emit modelReset({});
}
//------------------------------------------------------------------------------
auto PickRoleProxyModel::roleNames() const -> QHash<int, QByteArray> {
    auto result = sourceModel()->roleNames();
    result.insert(Qt::UserRole, "value");
    return result;
}

//------------------------------------------------------------------------------
auto PickRoleProxyModel::data(const QModelIndex& index, int role) const
  -> QVariant {
    if(role == Qt::UserRole) {
        role = _pickedRole;
    }
    return sourceModel()->data(index, role);
}
//------------------------------------------------------------------------------
