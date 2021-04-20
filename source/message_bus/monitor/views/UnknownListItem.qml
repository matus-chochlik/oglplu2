import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

NodeListItem {
	id: unknownListItem

	RowLayout {
		anchors.fill: parent
		Item {
			Layout.preferredWidth: 50
		}
		Image {
			Layout.preferredWidth:  backend.theme.nodeListIconSize
			Layout.preferredHeight: backend.theme.nodeListIconSize
			horizontalAlignment: Image.AlignHCenter
			source: "qrc:/icons/UnknownNode.svg"
		}
		ColumnLayout {
			Layout.fillHeight: true
			Label {
				Layout.fillWidth: true
				font.pixelSize: 10;
				text: "Unknown node: %1".arg(identifier ? identifier : "?")
			}
			Label {
				Layout.fillWidth: true
				font.italic: true
				text: "No info available"
			}
		}
	}
}
