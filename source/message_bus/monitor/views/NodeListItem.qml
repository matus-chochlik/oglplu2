import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

Pane {
	id: nodeListItem
	property variant view: nodeListItemLayout.view

	width: 250
	height: 55
	clip: true

	background: Rectangle {
		id: nodeItemBackground
		color: "orange"
		opacity: 0.1
	}

	function isCurrent() {
		return nodeListItem.view.currentIndex == index
	}

	function makeCurrent() {
		nodeListItem.view.currentIndex = index
	}

	state: isCurrent() ? "Selected" : "Unselected"
	states: [
		State {
			name: "Selected"
			PropertyChanges {
				target: nodeItemBackground
				opacity: 0.6
			}
		},
		State {
			name: "Unselected"
			PropertyChanges {
				target: nodeItemBackground
				opacity: 0.1
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
