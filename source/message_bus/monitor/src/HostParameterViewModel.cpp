///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///

#include "HostParameterViewModel.hpp"
#include "MonitorBackend.hpp"
#include "TrackerModel.hpp"

//------------------------------------------------------------------------------
HostParameterViewModel::HostParameterViewModel(MonitorBackend& backend)
  : QAbstractItemModel{nullptr}
  , eagine::main_ctx_object{EAGINE_ID(HostParaVM), backend}
  , _backend{backend}
  , _shortLoadModel{*this, shortLoadRole} {}
//------------------------------------------------------------------------------
void HostParameterViewModel::notifyUpdated() {
    if(_hostId && !_parameters) {
        if(auto tracker{_backend.trackerModel()}) {
            _parameters = tracker->hostParameters(_hostId);
        }
    } else if(!_hostId && _parameters) {
        _parameters.reset();
    }
    emit modelReset({});
    _shortLoadModel.notifyUpdated();
}
//------------------------------------------------------------------------------
void HostParameterViewModel::setHostId(eagine::identifier_t hostId) {
    if(_hostId != hostId) {
        _hostId = hostId;
        _parameters.reset();
        notifyUpdated();
    }
}
//------------------------------------------------------------------------------
auto HostParameterViewModel::getShortLoad() -> QAbstractItemModel* {
    return &_shortLoadModel;
}
//------------------------------------------------------------------------------
auto HostParameterViewModel::roleNames() const -> QHash<int, QByteArray> {
    QHash<int, QByteArray> result;
    result.insert(HostParameterViewModel::shortLoadRole, "shortLoad");
    result.insert(HostParameterViewModel::longLoadRole, "longLoad");
    return result;
}
//------------------------------------------------------------------------------
auto HostParameterViewModel::index(int row, int column, const QModelIndex&) const
  -> QModelIndex {
    return QAbstractItemModel::createIndex(row, column);
}
//------------------------------------------------------------------------------
auto HostParameterViewModel::parent(const QModelIndex&) const -> QModelIndex {
    return {};
}
//------------------------------------------------------------------------------
auto HostParameterViewModel::columnCount(const QModelIndex&) const -> int {
    return 2;
}
//------------------------------------------------------------------------------
auto HostParameterViewModel::rowCount(const QModelIndex&) const -> int {
    if(_parameters) {
        return _parameters->count();
    }
    return 0;
}
//------------------------------------------------------------------------------
auto HostParameterViewModel::data(const QModelIndex& index, int role) const
  -> QVariant {
    if(_parameters) {
        const auto row = index.row();
        auto& params = *_parameters;
        if((row >= 0) && (row < params.count())) {
            auto get = [row](const auto& v) {
                return QVariant{*(v.rbegin() + row)};
            };
            switch(role) {
                case shortLoadRole:
                    return get(params.shortAverageLoadHistory());
                case longLoadRole:
                    return get(params.longAverageLoadHistory());
                default:
                    break;
            }
        }
    }
    return {};
}
//------------------------------------------------------------------------------
