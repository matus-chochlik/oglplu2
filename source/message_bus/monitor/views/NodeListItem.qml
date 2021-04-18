import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Controls.Material 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

Pane {
	id: nodeListItem

	width: parent.width
	height: 55
	clip: true

	background: Rectangle {
		id: nodeItemBackground
		color: "orange"
		opacity: 0.0
	}

	function nodeItemIdentifier() {
		return "%1: %2"
			.arg(itemKind ? itemKind : "Node")
			.arg(identifier ? identifier : "?")
	}

	ColumnLayout {
		id: expandedNodeItem
		Label {
			text: nodeItemIdentifier()
		}
		Label {
			text: displayName ? displayName : "-"
		}
	}

	function isCurrent() {
		return nodeListItem.ListView.view.currentIndex == index
	}

	function makeCurrent() {
		nodeListItem.ListView.view.currentIndex = index
	}

	state: isCurrent() ? "Selected" : "Unselected"
	states: [
		State {
			name: "Selected"
			PropertyChanges {
				target: nodeItemBackground
				opacity: 0.5
			}
		},
		State {
			name: "Unselected"
			PropertyChanges {
				target: nodeItemBackground
				opacity: 0.0
			}
		}
	]
	transitions: [
		Transition {
			from: "Unselected"
			to: "Selected"
			PropertyAnimation {
				target: nodeItemBackground
				properties: "opacity"
				duration: 100
			}
		},
		Transition {
			from: "Selected"
			to: "Unselected"
			PropertyAnimation {
				target: nodeItemBackground
				properties: "opacity"
				duration: 300
			}
		}
	]

	MouseArea {
		anchors.fill: parent
		onClicked: makeCurrent()
	}
}
