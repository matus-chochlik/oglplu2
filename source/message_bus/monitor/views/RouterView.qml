///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///
import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

Pane {
	id: routerView
    property variant model: null
	leftPadding: 0

	ColumnLayout {
		anchors.fill: parent
		ItemViewHeading {
			itemKind: "Router"
			iconName: "RouterNode"
			itemModel: routerView.model.node
		}
		GridLayout {
			id: info
			property variant node: routerView.model.node
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
			model: routerView.model
		}
		Item {
			Layout.fillHeight: true
		}
	}
}

