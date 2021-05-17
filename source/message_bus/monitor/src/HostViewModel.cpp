///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///

#include "HostViewModel.hpp"
#include "MonitorBackend.hpp"
#include "TrackerModel.hpp"
//------------------------------------------------------------------------------
HostViewModel::HostViewModel(
  MonitorBackend& backend,
  SelectedItemViewModel& selectedItemViewModel)
  : QObject{nullptr}
  , eagine::main_ctx_object{EAGINE_ID(HostVM), backend}
  , _backend{backend}
  , _parameters{backend} {
    connect(
      &_backend,
      &MonitorBackend::trackerModelChanged,
      this,
      &HostViewModel::onTrackerModelChanged);
    connect(
      &selectedItemViewModel,
      &SelectedItemViewModel::hostChanged,
      this,
      &HostViewModel::onHostIdChanged);
}
//------------------------------------------------------------------------------
auto HostViewModel::getItemKind() -> QString {
    if(_host.id()) {
        return {"Host"};
    }
    return {"UnknownHost"};
}
//------------------------------------------------------------------------------
auto HostViewModel::getIdentifier() -> QVariant {
    if(_host) {
        return {QString::number(extract(_host.id()))};
    }
    return {};
}
//------------------------------------------------------------------------------
auto HostViewModel::getDisplayName() -> QVariant {
    if(auto optStr{_host.name()}) {
        return {c_str(extract(optStr))};
    }
    return {};
}
//------------------------------------------------------------------------------
auto HostViewModel::getDescription() -> QVariant {
    return {};
}
//------------------------------------------------------------------------------
auto HostViewModel::getCpuThreads() -> QVariant {
    if(auto optNum{_host.cpu_concurrent_threads()}) {
        return {eagine::limit_cast<int>(extract(optNum))};
    }
    return {};
}
//------------------------------------------------------------------------------
auto HostViewModel::getShortLoad() -> QVariant {
    if(auto optNum{_host.short_average_load()}) {
        return {extract(optNum)};
    }
    return {};
}
//------------------------------------------------------------------------------
auto HostViewModel::getShortLoadDelta() -> QVariant {
    if(auto optNum{_host.short_average_load_change()}) {
        return {extract(optNum)};
    }
    return {};
}
//------------------------------------------------------------------------------
auto HostViewModel::getLongLoad() -> QVariant {
    if(auto optNum{_host.long_average_load()}) {
        return {extract(optNum)};
    }
    return {};
}
//------------------------------------------------------------------------------
auto HostViewModel::getLongLoadDelta() -> QVariant {
    if(auto optNum{_host.long_average_load_change()}) {
        return {extract(optNum)};
    }
    return {};
}
//------------------------------------------------------------------------------
auto HostViewModel::getRamTotal() -> QVariant {
    if(auto optNum{_host.total_ram_size()}) {
        return {eagine::limit_cast<qulonglong>(extract(optNum))};
    }
    return {};
}
//------------------------------------------------------------------------------
auto HostViewModel::getRamFree() -> QVariant {
    if(auto optNum{_host.free_ram_size()}) {
        return {eagine::limit_cast<qulonglong>(extract(optNum))};
    }
    return {};
}
//------------------------------------------------------------------------------
auto HostViewModel::getRamFreeDelta() -> QVariant {
    if(auto optNum{_host.free_ram_size_change()}) {
        return {eagine::limit_cast<qlonglong>(extract(optNum))};
    }
    return {};
}
//------------------------------------------------------------------------------
auto HostViewModel::getRamUsage() -> QVariant {
    if(auto optNum{_host.ram_usage()}) {
        return {extract(optNum)};
    }
    return {};
}
//------------------------------------------------------------------------------
auto HostViewModel::getRamUsageDelta() -> QVariant {
    if(auto optNum{_host.ram_usage_change()}) {
        return {extract(optNum)};
    }
    return {};
}
//------------------------------------------------------------------------------
auto HostViewModel::getSwapTotal() -> QVariant {
    if(auto optNum{_host.total_swap_size()}) {
        return {eagine::limit_cast<qulonglong>(extract(optNum))};
    }
    return {};
}
//------------------------------------------------------------------------------
auto HostViewModel::getSwapFree() -> QVariant {
    if(auto optNum{_host.free_swap_size()}) {
        return {eagine::limit_cast<qulonglong>(extract(optNum))};
    }
    return {};
}
//------------------------------------------------------------------------------
auto HostViewModel::getSwapFreeDelta() -> QVariant {
    if(auto optNum{_host.free_swap_size_change()}) {
        return {eagine::limit_cast<qlonglong>(extract(optNum))};
    }
    return {};
}
//------------------------------------------------------------------------------
auto HostViewModel::getSwapUsage() -> QVariant {
    if(auto optNum{_host.swap_usage()}) {
        return {extract(optNum)};
    }
    return {};
}
//------------------------------------------------------------------------------
auto HostViewModel::getSwapUsageDelta() -> QVariant {
    if(auto optNum{_host.swap_usage_change()}) {
        return {extract(optNum)};
    }
    return {};
}
//------------------------------------------------------------------------------
auto HostViewModel::getMinTemperature() -> QVariant {
    if(auto optTemp{_host.min_temperature()}) {
        return {extract(optTemp).value()};
    }
    return {};
}
//------------------------------------------------------------------------------
auto HostViewModel::getMaxTemperature() -> QVariant {
    if(auto optTemp{_host.max_temperature()}) {
        return {extract(optTemp).value()};
    }
    return {};
}
//------------------------------------------------------------------------------
auto HostViewModel::getMinTemperatureDelta() -> QVariant {
    if(auto optTemp{_host.min_temperature_change()}) {
        return {extract(optTemp).value()};
    }
    return {};
}
//------------------------------------------------------------------------------
auto HostViewModel::getMaxTemperatureDelta() -> QVariant {
    if(auto optTemp{_host.max_temperature_change()}) {
        return {extract(optTemp).value()};
    }
    return {};
}
//------------------------------------------------------------------------------
auto HostViewModel::getPowerSupply() -> QVariant {
    switch(_host.power_supply()) {
        case eagine::power_supply_kind::ac_supply:
            return {"ACSupply"};
        case eagine::power_supply_kind::battery:
            return {"Battery"};
        case eagine::power_supply_kind::unknown:
            break;
    }
    return {};
}
//------------------------------------------------------------------------------
auto HostViewModel::getParameters() -> QAbstractItemModel* {
    return &_parameters;
}
//------------------------------------------------------------------------------
void HostViewModel::onTrackerModelChanged() {
    if(auto trackerModel{_backend.trackerModel()}) {
        connect(
          trackerModel,
          &TrackerModel::hostInfoChanged,
          this,
          &HostViewModel::onHostInfoChanged);
    }
}
//------------------------------------------------------------------------------
void HostViewModel::onHostIdChanged(eagine::identifier_t hostId) {
    if(hostId) {
        if(auto trackerModel{_backend.trackerModel()}) {
            auto& tracker = trackerModel->tracker();
            _host = tracker.get_host(hostId);
        }
    } else {
        _host = {};
    }
    emit infoChanged();
    _parameters.setHostId(hostId);
}
//------------------------------------------------------------------------------
void HostViewModel::onHostInfoChanged(const remote_host& host) {
    if(host.id() == _host.id()) {
        emit infoChanged();
        _parameters.notifyUpdated();
    }
}
//------------------------------------------------------------------------------
