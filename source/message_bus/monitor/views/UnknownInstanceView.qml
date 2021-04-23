import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

Pane {
	id: unknownInstanceView
    property variant model: null
	leftPadding: 0

	ColumnLayout {
		UnknownItemViewHeading {
			itemKind: model.itemKind
			iconName: "InstanceItem"
		}
		HostView {
			model: unknownInstanceView.model
		}
		Item {
			Layout.fillHeight: true
		}
	}
}

