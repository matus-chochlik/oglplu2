///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///

#ifndef EAGINE_MESSAGE_BUS_MONITOR_THEME
#define EAGINE_MESSAGE_BUS_MONITOR_THEME

#include <eagine/main_ctx_object.hpp>
#include <QObject>

//------------------------------------------------------------------------------
class MonitorTheme
  : public QObject
  , public eagine::main_ctx_object {
    Q_OBJECT

    Q_PROPERTY(bool light READ getLight WRITE setLight NOTIFY lightChanged)
    Q_PROPERTY(int nodeListHostOffset READ getNodeListHostOffset CONSTANT)
    Q_PROPERTY(int nodeListInstOffset READ getNodeListInstOffset CONSTANT)
    Q_PROPERTY(int nodeListNodeOffset READ getNodeListNodeOffset CONSTANT)

    Q_PROPERTY(int nodeListItemWidth READ getNodeListItemWidth CONSTANT)
    Q_PROPERTY(int nodeListItemHeight READ getNodeListItemHeight CONSTANT)
    Q_PROPERTY(int nodeListIconSize READ getNodeListIconSize CONSTANT)
    Q_PROPERTY(int itemViewIconSize READ getItemViewIconSize CONSTANT)
    Q_PROPERTY(int nodeListAliveSize READ getNodeListAliveSize CONSTANT)

    Q_PROPERTY(float smallFontSize READ getSmallFontSize CONSTANT)
    Q_PROPERTY(float normalFontSize READ getNormalFontSize CONSTANT)
    Q_PROPERTY(float hugeFontSize READ getHugeFontSize CONSTANT)
public:
    MonitorTheme(eagine::main_ctx_parent);

    void setLight(bool);
    auto getLight() const -> bool;

    auto getNodeListHostOffset() -> int;
    auto getNodeListInstOffset() -> int;
    auto getNodeListNodeOffset() -> int;

    auto getNodeListItemWidth() -> int;
    auto getNodeListItemHeight() -> int;
    auto getNodeListIconSize() -> int;
    auto getItemViewIconSize() -> int;
    auto getNodeListAliveSize() -> int;

    auto getSmallFontSize() -> float;
    auto getNormalFontSize() -> float;
    auto getHugeFontSize() -> float;
signals:
    void lightChanged();
public slots:
private:
    bool _light{false};
};
//------------------------------------------------------------------------------
#endif
