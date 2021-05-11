///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///

#ifndef EAGINE_MESSAGE_BUS_MONITOR_PICK_ROLE_PROXY_MODEL
#define EAGINE_MESSAGE_BUS_MONITOR_PICK_ROLE_PROXY_MODEL

#include <QAbstractItemModel>
#include <QIdentityProxyModel>

//------------------------------------------------------------------------------
class PickRoleProxyModel : public QIdentityProxyModel {
    Q_OBJECT
public:
    PickRoleProxyModel(QAbstractItemModel& parent, int role);

    void notifyUpdated();

    auto roleNames() const -> QHash<int, QByteArray> final;
    auto data(const QModelIndex& proxyIndex, int role) const -> QVariant final;

private:
    int _pickedRole{Qt::UserRole};
};
//------------------------------------------------------------------------------
#endif
