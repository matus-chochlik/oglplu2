///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_TILING_THEME
#define EAGINE_MESSAGE_BUS_TILING_THEME

#include <eagine/main_ctx_object.hpp>
#include <QObject>

//------------------------------------------------------------------------------
class TilingTheme
  : public QObject
  , public eagine::main_ctx_object {
    Q_OBJECT

    Q_PROPERTY(bool light READ getLight WRITE setLight NOTIFY lightChanged)
    Q_PROPERTY(QString tileset READ getTileset CONSTANT)
    Q_PROPERTY(int tileWidth READ getTileWidth CONSTANT)
    Q_PROPERTY(int tileHeight READ getTileHeight CONSTANT)

public:
    TilingTheme(eagine::main_ctx_parent);

    void setLight(bool);
    auto getLight() const -> bool;

    auto getTileset() const -> QString;
    auto getTileWidth() const -> int;
    auto getTileHeight() const -> int;

signals:
    void lightChanged();
public slots:
private:
    bool _light{false};
};
//------------------------------------------------------------------------------
#endif
