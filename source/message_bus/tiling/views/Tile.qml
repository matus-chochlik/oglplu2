import QtQuick 2.2
import QtQuick.Controls 2.4
import "qrc:///views"

Loader {
	source: tile
		? "qrc:///views/KnownTile.qml"
		: "qrc:///views/EmptyTile.qml"
}
