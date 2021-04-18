import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

NodeListItem {
	id: instListItem

	RowLayout {
		Item {
			width: 10
		}
		ColumnLayout {
			Label {
				text: "Instance: %1".arg(identifier ? identifier : "?")
			}
			Label {
				text: "Nodes: %1".arg(childCount ? childCount : "?")
			}
		}
	}
}
