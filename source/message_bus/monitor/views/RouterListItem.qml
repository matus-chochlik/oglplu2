import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

NodeListItem {
	id: routerListItem

	RowLayout {
		anchors.fill: parent
		Item {
			Layout.preferredWidth: backend.theme.nodeListNodeOffset
		}
		NodeListIcon {
			iconName: "RouterNode"
		}
		ColumnLayout {
			Layout.fillHeight: true
			NodeListHeading {
				title: "Router"
			}
			Label {
				text: "Connected:"
			}
		}
	}
}
