import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

NodeListItem {
	id: instListItem

	RowLayout {
		anchors.fill: parent
		Item {
			Layout.preferredWidth: 25
		}
		Image {
			Layout.preferredWidth:  backend.theme.nodeListIconSize
			Layout.preferredHeight: backend.theme.nodeListIconSize
			horizontalAlignment: Image.AlignHCenter
			source: "qrc:/icons/InstanceItem.svg"
		}
		ColumnLayout {
			Layout.fillHeight: true
			Label {
				Layout.fillWidth: true
				font.pixelSize: 10;
				text: "Process: %1".arg(identifier ? identifier : "?")
			}
			Label {
				Layout.fillWidth: true
				text: "Running nodes: %1".arg(childCount ? childCount : "?")
			}
		}
	}
}
