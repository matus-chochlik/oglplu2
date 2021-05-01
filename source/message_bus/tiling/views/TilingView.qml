import QtQuick 2.12
import QtQuick.Controls 2.4
import "qrc:///views"

TableView {
	rowSpacing: 0
	columnSpacing: 0
	columnWidthProvider: function() { return backend.theme.tileWidth; }
	rowHeightProvider: function() { return backend.theme.tileHeight; }
	clip: true

	delegate: Tile { }
}
