import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

NodeListItem {
	id: instListItem

	RowLayout {
		anchors.fill: parent
		Item {
			Layout.preferredWidth: backend.theme.nodeListInstOffset
		}
		NodeListIcon {
			iconName: "InstanceItem"
		}
		ColumnLayout {
			Layout.fillHeight: true
			NodeListHeading {
				title: "Process"
			}
			Label {
				text: displayName ? displayName : "-"
			}
		}
	}
}
