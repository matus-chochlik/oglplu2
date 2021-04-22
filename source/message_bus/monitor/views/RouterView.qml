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
			itemId: routerView.model.node.identifier
		}
		InstanceView {
			model: routerView.model
		}
		Item {
			Layout.fillHeight: true
		}
	}
}

