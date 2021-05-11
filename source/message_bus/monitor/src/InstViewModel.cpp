///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///

#include "InstViewModel.hpp"
#include "MonitorBackend.hpp"
#include "TrackerModel.hpp"
//------------------------------------------------------------------------------
InstViewModel::InstViewModel(
  MonitorBackend& backend,
  SelectedItemViewModel& selectedItemViewModel)
  : QObject{nullptr}
  , eagine::main_ctx_object{EAGINE_ID(InstVM), backend}
  , _backend{backend} {
    connect(
      &_backend,
      &MonitorBackend::trackerModelChanged,
      this,
      &InstViewModel::onTrackerModelChanged);
    connect(
      &selectedItemViewModel,
      &SelectedItemViewModel::instChanged,
      this,
      &InstViewModel::onInstIdChanged);
}
//------------------------------------------------------------------------------
auto InstViewModel::getItemKind() -> QString {
    if(_inst) {
        return {"Instance"};
    }
    return {"UnknownInstance"};
}
//------------------------------------------------------------------------------
auto InstViewModel::getIdentifier() -> QVariant {
    if(_inst.id()) {
        return {QString::number(extract(_inst.id()))};
    }
    return {};
}
//------------------------------------------------------------------------------
auto InstViewModel::getDisplayName() -> QVariant {
    if(auto optStr{_inst.application_name()}) {
        return {c_str(extract(optStr))};
    }
    return {};
}
//------------------------------------------------------------------------------
auto InstViewModel::getDescription() -> QVariant {
    return {};
}
//------------------------------------------------------------------------------
auto InstViewModel::getArchitecture() -> QVariant {
    if(auto optCompiler{_inst.compiler()}) {
        if(auto optArchName{extract(optCompiler).architecture_name()}) {
            return {c_str(extract(optArchName))};
        }
    }
    return {};
}
//------------------------------------------------------------------------------
auto InstViewModel::getCompilerName() -> QVariant {
    if(auto optCompiler{_inst.compiler()}) {
        if(auto optCompilerName{extract(optCompiler).name()}) {
            return {c_str(extract(optCompilerName))};
        }
    }
    return {};
}
//------------------------------------------------------------------------------
auto InstViewModel::getCompilerVersionMajor() -> QVariant {
    if(auto optCompiler{_inst.compiler()}) {
        if(auto optVerMajor{extract(optCompiler).version_major()}) {
            return {extract(optVerMajor)};
        }
    }
    return {};
}
//------------------------------------------------------------------------------
auto InstViewModel::getCompilerVersionMinor() -> QVariant {
    if(auto optCompiler{_inst.compiler()}) {
        if(auto optVerMinor{extract(optCompiler).version_minor()}) {
            return {extract(optVerMinor)};
        }
    }
    return {};
}
//------------------------------------------------------------------------------
auto InstViewModel::getCompilerVersionPatch() -> QVariant {
    if(auto optCompiler{_inst.compiler()}) {
        if(auto optVerPatch{extract(optCompiler).version_patch()}) {
            return {extract(optVerPatch)};
        }
    }
    return {};
}
//------------------------------------------------------------------------------
auto InstViewModel::getVersionMajor() -> QVariant {
    if(auto optBuild{_inst.build()}) {
        if(auto optVerMajor{extract(optBuild).version_major()}) {
            return {extract(optVerMajor)};
        }
    }
    return {};
}
//------------------------------------------------------------------------------
auto InstViewModel::getVersionMinor() -> QVariant {
    if(auto optBuild{_inst.build()}) {
        if(auto optVerMinor{extract(optBuild).version_minor()}) {
            return {extract(optVerMinor)};
        }
    }
    return {};
}
//------------------------------------------------------------------------------
auto InstViewModel::getVersionPatch() -> QVariant {
    if(auto optBuild{_inst.build()}) {
        if(auto optVerPatch{extract(optBuild).version_patch()}) {
            return {extract(optVerPatch)};
        }
    }
    return {};
}
//------------------------------------------------------------------------------
auto InstViewModel::getVersionCommit() -> QVariant {
    if(auto optBuild{_inst.build()}) {
        if(auto optVerCommit{extract(optBuild).version_commit()}) {
            return {extract(optVerCommit)};
        }
    }
    return {};
}
//------------------------------------------------------------------------------
void InstViewModel::onTrackerModelChanged() {
    if(auto trackerModel{_backend.trackerModel()}) {
        connect(
          trackerModel,
          &TrackerModel::instanceRelocated,
          this,
          &InstViewModel::onInstInfoChanged);
        connect(
          trackerModel,
          &TrackerModel::instanceInfoChanged,
          this,
          &InstViewModel::onInstInfoChanged);
    }
}
//------------------------------------------------------------------------------
void InstViewModel::onInstIdChanged(eagine::identifier_t instId) {
    if(instId) {
        if(auto trackerModel{_backend.trackerModel()}) {
            auto& tracker = trackerModel->tracker();
            _inst = tracker.get_instance(instId);
        }
    } else {
        _inst = {};
    }
    emit infoChanged();
}
//------------------------------------------------------------------------------
void InstViewModel::onInstInfoChanged(const remote_inst& inst) {
    if(inst.id() == _inst.id()) {
        emit infoChanged();
    }
}
//------------------------------------------------------------------------------
