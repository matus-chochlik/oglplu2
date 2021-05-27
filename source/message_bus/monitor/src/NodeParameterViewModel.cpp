///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///

#include "NodeParameterViewModel.hpp"
#include "MonitorBackend.hpp"
#include "TrackerModel.hpp"

//------------------------------------------------------------------------------
NodeParameterViewModel::NodeParameterViewModel(MonitorBackend& backend)
  : QAbstractItemModel{nullptr}
  , eagine::main_ctx_object{EAGINE_ID(NodeParaVM), backend}
  , _backend{backend}
  , _pingSuccessRateModel{*this, pingSuccessRateRole} {}
//------------------------------------------------------------------------------
void NodeParameterViewModel::notifyUpdated() {
    if(_nodeId && !_parameters) {
        if(auto tracker{_backend.trackerModel()}) {
            _parameters = tracker->nodeParameters(_nodeId);
        }
    } else if(!_nodeId && _parameters) {
        _parameters.reset();
    }
    emit modelReset({});
    _pingSuccessRateModel.notifyUpdated();
}
//------------------------------------------------------------------------------
void NodeParameterViewModel::setNodeId(eagine::identifier_t nodeId) {
    if(_nodeId != nodeId) {
        _nodeId = nodeId;
        _parameters.reset();
        notifyUpdated();
    }
}
//------------------------------------------------------------------------------
auto NodeParameterViewModel::getPingSuccessRate() -> QAbstractItemModel* {
    return &_pingSuccessRateModel;
}
//------------------------------------------------------------------------------
auto NodeParameterViewModel::roleNames() const -> QHash<int, QByteArray> {
    QHash<int, QByteArray> result;
    result.insert(
      NodeParameterViewModel::pingSuccessRateRole, "pingSuccessRate");
    return result;
}
//------------------------------------------------------------------------------
auto NodeParameterViewModel::index(int row, int column, const QModelIndex&) const
  -> QModelIndex {
    return QAbstractItemModel::createIndex(row, column);
}
//------------------------------------------------------------------------------
auto NodeParameterViewModel::parent(const QModelIndex&) const -> QModelIndex {
    return {};
}
//------------------------------------------------------------------------------
auto NodeParameterViewModel::columnCount(const QModelIndex&) const -> int {
    return 1;
}
//------------------------------------------------------------------------------
auto NodeParameterViewModel::rowCount(const QModelIndex&) const -> int {
    if(_parameters) {
        return _parameters->count();
    }
    return 0;
}
//------------------------------------------------------------------------------
auto NodeParameterViewModel::data(const QModelIndex& index, int role) const
  -> QVariant {
    if(_parameters) {
        const auto row = index.row();
        auto& params = *_parameters;
        if((row >= 0) && (row < params.count())) {
            auto get = [row](const auto& v) {
                return QVariant{*(v.rbegin() + row)};
            };
            switch(role) {
                case pingSuccessRateRole:
                    return get(params.pingSuccessRateHistory());
                case pingResponseTimeRole:
                default:
                    break;
            }
        }
    }
    return {};
}
//------------------------------------------------------------------------------
