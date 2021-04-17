import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

Pane {
	id: nodeListItem
	width: parent.width
	height: 55

	function isCurrent() {
		return nodeListItem.ListView.view.currentIndex != index
	}

	function makeCurrent() {
		nodeListItem.ListView.view.currentIndex = index
	}

	background: Rectangle {
		color: "orange"
		opacity: isCurrent() ? 0.0 : 0.5
	}
	ColumnLayout {
		Label {
			text: identifier ? itemKind + ": " + identifier : "N/A"
		}
		Label {
			text: displayName ? displayName : "-"
		}
	}
	MouseArea {
		anchors.fill: parent
		onClicked: makeCurrent()
	}
}
