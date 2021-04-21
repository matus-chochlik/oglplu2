import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

NodeListItem {
	id: unknownNodeListItem

	RowLayout {
		anchors.fill: parent
		Item {
			Layout.preferredWidth: backend.theme.nodeListNodeOffset
		}
		NodeListIcon {
			iconName: "UnknownNode"
		}
		ColumnLayout {
			Layout.fillHeight: true
			NodeListHeading {
				title: "Unknown node"
			}
			Label {
				Layout.fillWidth: true
				font.italic: true
				text: "No info available"
			}
		}
	}
}
