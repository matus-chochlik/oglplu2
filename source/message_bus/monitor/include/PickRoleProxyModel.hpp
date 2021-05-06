///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///

#ifndef EAGINE_MESSAGE_BUS_MONITOR_PICK_ROLE_PROXY_MODEL
#define EAGINE_MESSAGE_BUS_MONITOR_PICK_ROLE_PROXY_MODEL

#include <QAbstractItemModel>
#include <QAbstractProxyModel>

//------------------------------------------------------------------------------
class PickRoleProxyModel : public QAbstractProxyModel {
    Q_OBJECT
public:
    PickRoleProxyModel(QAbstractItemModel& parent, int role);

    auto roleNames() const -> QHash<int, QByteArray> final;
    auto index(int row, int column, const QModelIndex& parent = {}) const
      -> QModelIndex final;
    auto parent(const QModelIndex& child) const -> QModelIndex final;
    auto mapFromSource(const QModelIndex&) const -> QModelIndex final;
    auto mapToSource(const QModelIndex&) const -> QModelIndex final;
    auto columnCount(const QModelIndex& parent) const -> int final;
    auto rowCount(const QModelIndex& parent) const -> int final;
    auto data(const QModelIndex& proxyIndex, int role) const -> QVariant final;

private:
    int _pickedRole{Qt::DisplayRole};
};
//------------------------------------------------------------------------------
#endif
