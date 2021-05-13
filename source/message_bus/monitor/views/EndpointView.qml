///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///
import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"
import "qrc:///scripts/Format.js" as Format

Pane {
	id: endpointView
    property variant model: null
	leftPadding: 0

	ColumnLayout {
		anchors.fill: parent
		ItemViewHeading {
			itemKind: "Endpoint"
			iconName: "EndpointNode"
			itemModel: endpointView.model.node
		}
		GridLayout {
			id: info
			property variant node: endpointView.model.node
			Layout.fillWidth: true
			columns: 6
			rowSpacing: 10
			columnSpacing: 20

			Label {
				text: qsTr("Responsivity")
			}
			PlainBarChart {
				Layout.columnSpan: 5
				Layout.preferredHeight: 25
				Layout.fillWidth: true
				model: info.node.parameters.pingSuccessRate
			}

			Label {
				text: qsTr("Sent:")
			}
			Label {
				Layout.fillWidth: true
				text: info.node.sentMessages
					? info.node.sentMessages
					: "-"
			}

			Label {
				text: qsTr("Received:")
			}
			Label {
				Layout.fillWidth: true
				text: info.node.receivedMessages
					? info.node.receivedMessages
					: "-"
			}

			Label {
				text: qsTr("Dropped:")
			}
			Label {
				Layout.fillWidth: true
				text: info.node.droppedMessages
					? info.node.droppedMessages
					: "-"
			}

			Label {
				text: qsTr("Uptime")
			}
			Label {
				Layout.columnSpan: 5
				text: info.node.uptime
					? Format.durationStr(info.node.uptime)
					: "-"
			}
		}
		ParentInstanceView {
			Layout.fillWidth: true
			model: endpointView.model
		}
		Item {
			Layout.fillHeight: true
		}
	}
}

