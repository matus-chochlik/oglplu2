///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
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
    Q_PROPERTY(int tileWidth READ getTileWidth NOTIFY tileSizeChanged)
    Q_PROPERTY(int tileHeight READ getTileHeight NOTIFY tileSizeChanged)

public:
    TilingTheme(eagine::main_ctx_parent);

    void setLight(bool);
    auto getLight() const -> bool;

    auto getTileset() const -> QString;
    auto getTileWidth() const -> int;
    auto getTileHeight() const -> int;

    Q_INVOKABLE void setTileSize(int);

signals:
    void lightChanged();
    void tileSizeChanged();
public slots:
private:
    int _tileSize{16};
    bool _light{false};
};
//------------------------------------------------------------------------------
#endif
