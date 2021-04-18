import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

NodeListItem {
	id: endpointListItem

	RowLayout {
		Item {
			width: 20
		}
		ColumnLayout {
			Layout.fillWidth: true
			Label {
				text: "Endpoint: %1".arg(identifier ? identifier : "?")
			}
			Label {
				text: displayName ? displayName : "-"
			}
		}
	}
}
