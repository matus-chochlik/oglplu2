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
			NumericLabel {
				Layout.fillWidth: true

				value: info.node.sentMessages
				format: Math.trunc
			}

			Label {
				text: qsTr("Received:")
			}
			NumericLabel {
				Layout.fillWidth: true

				value: info.node.receivedMessages
				format: Math.trunc
			}

			Label {
				text: qsTr("Dropped:")
			}
			NumericLabel {
				Layout.fillWidth: true

				value: info.node.droppedMessages
				format: Math.trunc
			}

			Label {
				text: qsTr("Uptime")
			}
			NumericLabel {
				Layout.columnSpan: 5
				Layout.fillWidth: true

				value: info.node.uptime
				format: Format.durationStr
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

