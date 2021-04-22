
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_MONITOR_INST_VIEW_MODEL
#define EAGINE_MESSAGE_BUS_MONITOR_INST_VIEW_MODEL

#include <eagine/main_ctx_object.hpp>
#include <QObject>
#include <QVariant>

class MonitorBackend;
class SelectedItemViewModel;
//------------------------------------------------------------------------------
class InstViewModel
  : public QObject
  , public eagine::main_ctx_object {
    Q_OBJECT

    Q_PROPERTY(QVariant identifier READ getIdentifier NOTIFY instInfoChanged)
public:
    InstViewModel(MonitorBackend&, SelectedItemViewModel&);

    explicit operator bool() const noexcept {
        return _instId != 0U;
    }

    auto getIdentifier() -> QVariant;
    auto getItemKind() -> QString;

signals:
    void instInfoChanged();

public slots:
    void onInstInfoChanged(eagine::identifier_t instId);

private:
    MonitorBackend& _backend;
    eagine::identifier_t _instId{0U};
};
//------------------------------------------------------------------------------
#endif
