///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///

#ifndef EAGINE_MESSAGE_BUS_MONITOR_MONITOR_VIEW_MODEL
#define EAGINE_MESSAGE_BUS_MONITOR_MONITOR_VIEW_MODEL

#include "NodeListViewModel.hpp"
#include "SelectedItemViewModel.hpp"
#include <eagine/main_ctx_object.hpp>
#include <QObject>

class MonitorBackend;
//------------------------------------------------------------------------------
class MonitorViewModel
  : public QObject
  , public eagine::main_ctx_object {
    Q_OBJECT

    Q_PROPERTY(NodeListViewModel* nodeList READ getNodeListViewModel CONSTANT)
    Q_PROPERTY(SelectedItemViewModel* selectedItem READ getSelectedItemViewModel
                 CONSTANT)
public:
    MonitorViewModel(MonitorBackend&);

    auto getNodeListViewModel() -> NodeListViewModel*;
    auto getSelectedItemViewModel() -> SelectedItemViewModel*;
public slots:

private:
    MonitorBackend& _backend;
    NodeListViewModel _nodeListViewModel;
    SelectedItemViewModel _selectedItemViewModel;
};
//------------------------------------------------------------------------------
#endif
