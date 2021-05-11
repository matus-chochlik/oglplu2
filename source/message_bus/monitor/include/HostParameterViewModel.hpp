///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///

#ifndef EAGINE_MESSAGE_BUS_MONITOR_HOST_PARAMETER_VIEW_MODEL
#define EAGINE_MESSAGE_BUS_MONITOR_HOST_PARAMETER_VIEW_MODEL

#include "PickRoleProxyModel.hpp"
#include <eagine/main_ctx_object.hpp>
#include <QAbstractItemModel>
#include <QObject>

class MonitorBackend;
class HostParameterModel;
class HostParameterViewModel;
//------------------------------------------------------------------------------
class HostParameterViewModel
  : public QAbstractItemModel
  , public eagine::main_ctx_object {
    Q_OBJECT

    Q_PROPERTY(QAbstractItemModel* shortLoad READ getShortLoad CONSTANT)
public:
    HostParameterViewModel(MonitorBackend&);

    void notifyUpdated();
    void setHostId(eagine::identifier_t hostId);
    auto getShortLoad() -> QAbstractItemModel*;

    auto roleNames() const -> QHash<int, QByteArray> final;
    auto index(int row, int column, const QModelIndex& parent = {}) const
      -> QModelIndex final;
    auto parent(const QModelIndex& child) const -> QModelIndex final;
    auto columnCount(const QModelIndex& parent) const -> int final;
    auto rowCount(const QModelIndex& parent) const -> int final;
    auto data(const QModelIndex& index, int role) const -> QVariant final;

private:
    enum {
        reservedValueRole = Qt::UserRole,
        shortLoadRole = Qt::UserRole + 1,
        longLoadRole = Qt::UserRole + 2
    };

    MonitorBackend& _backend;
    PickRoleProxyModel _shortLoadModel;

    eagine::identifier_t _hostId{0U};
    std::shared_ptr<HostParameterModel> _parameters;
};
//------------------------------------------------------------------------------
#endif
