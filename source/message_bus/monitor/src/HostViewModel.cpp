///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
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
  , _backend{backend} {
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
}
//------------------------------------------------------------------------------
void HostViewModel::onHostInfoChanged(const remote_host& host) {
    if(host.id() == _host.id()) {
        emit infoChanged();
    }
}
//------------------------------------------------------------------------------
