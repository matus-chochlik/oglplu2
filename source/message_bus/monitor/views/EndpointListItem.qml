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
				itemKind: model.itemKind
			}
			Label {
				Layout.fillWidth: true
				text: displayName ? displayName : "-"
			}
		}
	}

	function toolTipText() {
		var result = ""
		if(itemKind && identifier) {
			result += "%1: %2\n".arg(qsTr(itemKind)).arg(identifier)
		}
		if(displayName) {
			result += "%1\n".arg(qsTr(displayName))
		}
		if(description) {
			result += "%1\n".arg(qsTr(description))
		}
		return result
	}

	ToolTip.text: toolTipText()
}
