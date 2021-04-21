import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

NodeListItem {
	id: unknownHostListItem

	RowLayout {
		anchors.fill: parent
		Item {
			Layout.preferredWidth: backend.theme.nodeListHostOffset
		}
		NodeListIcon {
			iconName: "UnknownHostItem"
		}
		ColumnLayout {
			Layout.fillHeight: true
			NodeListHeading {
				title: "Unknown host"
			}
			Label {
				Layout.fillWidth: true
				font.italic: true
				text: "No info available"
			}
		}
	}
}
