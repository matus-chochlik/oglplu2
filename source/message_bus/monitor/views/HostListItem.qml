import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

NodeListItem {
	id: hostListItem

	RowLayout {
		anchors.fill: parent
		Image {
			Layout.preferredWidth: 56
			Layout.preferredHeight: 56
			horizontalAlignment: Image.AlignHCenter
			source: "qrc:/icons/HostItem.svg"
		}
		ColumnLayout {
			Layout.fillHeight: true
			Label {
				Layout.fillWidth: true
				font.pixelSize: 10;
				text: "Host: %1".arg(identifier ? identifier : "?")
			}
			Label {
				Layout.fillWidth: true
				text: "Processes: %1".arg(childCount ? childCount : "?")
			}
		}
	}
}
