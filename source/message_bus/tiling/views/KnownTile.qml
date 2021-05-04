import QtQuick 2.2
import QtQuick.Controls 2.4
import "qrc:///views"

Image {
	source: "qrc:/tiles/%1_%2.svg"
		.arg(backend.theme.tileset)
		.arg(tile)
}
