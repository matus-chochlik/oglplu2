import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

NodeListItem {
	id: hostListItem

	RowLayout {
		anchors.fill: parent
		Item {
			Layout.preferredWidth: backend.theme.nodeListHostOffset
		}
		NodeListIcon {
			iconName: "HostItem"
		}
		ColumnLayout {
			Layout.fillHeight: true
			NodeListHeading {
				title: "Host"
			}
			Label {
				text: displayName ? displayName : "-"
			}
		}
	}
}
