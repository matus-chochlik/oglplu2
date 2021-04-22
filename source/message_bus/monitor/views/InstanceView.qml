import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

Pane {
	id: instanceView
    property variant model: null
	leftPadding: 0

	ColumnLayout {
		ItemViewHeading {
			itemKind: "Process"
			iconName: "InstanceItem"
			itemId: instanceView.model.inst.identifier
		}
		HostView {
			model: instanceView.model
		}
		Item {
			Layout.fillHeight: true
		}
	}
}

