import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

NodeListItem {
	id: endpointListItem

	RowLayout {
		anchors.fill: parent
		Item {
			Layout.preferredWidth: backend.theme.nodeListNodeOffset
		}
		NodeListIcon {
			iconName: "EndpointNode"
		}
		ColumnLayout {
			Layout.fillHeight: true
			NodeListHeading {
				title: "Endpoint"
			}
			Label {
				Layout.fillWidth: true
				text: displayName ? displayName : "-"
			}
		}
	}
}
