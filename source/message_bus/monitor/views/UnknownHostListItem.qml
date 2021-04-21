import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

NodeListItem {
	id: unknownHostListItem

	RowLayout {
		anchors.fill: parent
		Image {
			Layout.preferredWidth:  backend.theme.nodeListIconSize
			Layout.preferredHeight: backend.theme.nodeListIconSize
			horizontalAlignment: Image.AlignHCenter
			source: "qrc:/icons/UnknownHostItem.svg"
		}
		ColumnLayout {
			Layout.fillHeight: true
			Label {
				Layout.fillWidth: true
				text: "Unknown host"
			}
			Label {
				Layout.fillWidth: true
				font.italic: true
				text: "No info available"
			}
		}
	}
}
