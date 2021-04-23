import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

Pane {
	id: unknownNodeView
    property variant model: null
	leftPadding: 0

	ColumnLayout {
		UnknownItemViewHeading {
			itemKind: "UnknownNode"
			iconName: "UnknownNode"
		}
		ParentInstanceView {
			model: unknownNodeView.model
		}
		Item {
			Layout.fillHeight: true
		}
	}
}

