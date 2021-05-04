import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

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
			ProgressBar {
				Layout.columnSpan: 5
				Layout.fillWidth: true
				from: 0.0
				to: 1.0
				value: info.node && info.node.pingSuccessRate
					? info.node.pingSuccessRate
					: 0.0
				indeterminate: !(info.node && info.node.pingSuccessRate)
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

