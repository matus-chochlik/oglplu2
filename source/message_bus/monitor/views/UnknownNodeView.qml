import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

Item {
	id: unknownNodeView
    property variant model: null

	ColumnLayout {
		anchors.fill: parent
		Label {
			text: qsTr("Unknown node view")
		}
		Item {
			Layout.fillHeight: true
		}
	}
}

