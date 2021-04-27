import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

Pane {
	id: unknownInstanceView
    property variant model: null
	leftPadding: 0

	ColumnLayout {
		anchors.fill: parent
		UnknownItemViewHeading {
			itemKind: "UnknownInstance"
			iconName: "InstanceItem"
		}
		ParentHostView {
			Layout.fillWidth: true
			model: unknownInstanceView.model
		}
		Item {
			Layout.fillHeight: true
		}
	}
}

