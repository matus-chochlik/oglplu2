///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_MONITOR_HOST_VIEW_MODEL
#define EAGINE_MESSAGE_BUS_MONITOR_HOST_VIEW_MODEL

#include <eagine/main_ctx_object.hpp>
#include <QObject>
#include <QVariant>

class MonitorBackend;
class SelectedItemViewModel;
//------------------------------------------------------------------------------
class HostViewModel
  : public QObject
  , public eagine::main_ctx_object {
    Q_OBJECT

    Q_PROPERTY(QVariant identifier READ getIdentifier NOTIFY hostInfoChanged)
public:
    HostViewModel(MonitorBackend&, SelectedItemViewModel&);

    explicit operator bool() const noexcept {
        return _hostId != 0U;
    }

    auto getIdentifier() -> QVariant;
    auto getItemKind() -> QString;

signals:
    void hostInfoChanged();

public slots:
    void onHostInfoChanged(eagine::identifier_t hostId);

private:
    MonitorBackend& _backend;
    eagine::identifier_t _hostId{0U};
};
//------------------------------------------------------------------------------
#endif
