///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_MONITOR_THEME
#define EAGINE_MESSAGE_BUS_MONITOR_THEME

#include "MonitorViewModel.hpp"
#include <eagine/main_ctx_object.hpp>
#include <QObject>

//------------------------------------------------------------------------------
class MonitorTheme
  : public QObject
  , public eagine::main_ctx_object {
    Q_OBJECT

    Q_PROPERTY(bool light READ getLight WRITE setLight NOTIFY lightChanged)
    Q_PROPERTY(int nodeListItemWidth READ getNodeListItemWidth CONSTANT)
    Q_PROPERTY(int nodeListItemHeight READ getNodeListItemHeight CONSTANT)
    Q_PROPERTY(int nodeListIconSize READ getNodeListIconSize CONSTANT)
public:
    MonitorTheme(eagine::main_ctx_parent);

    void setLight(bool);
    auto getLight() const -> bool;

    auto getNodeListItemWidth() -> int;
    auto getNodeListItemHeight() -> int;
    auto getNodeListIconSize() -> int;
signals:
    void lightChanged();
public slots:
private:
    bool _light{false};
};
//------------------------------------------------------------------------------
#endif
