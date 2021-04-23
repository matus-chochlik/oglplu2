import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

Item {
	id: unknownHostView
    property variant model: null

	ColumnLayout {
		UnknownItemViewHeading {
			itemKind: model.itemKind
			iconName: "UnknownHostItem"
		}
		Item {
			Layout.fillHeight: true;
		}
		Label {
			Layout.fillWidth: true;
			horizontalAlignment: Label.AlignHCenter
			font.pixelSize: backend.theme.hugeFontSize;
			text: qsTr("Unknown host")
		}
		Label {
			Layout.fillWidth: true;
			horizontalAlignment: Label.AlignHCenter
			font.italic: true
			text: qsTr("No additional information available")
		}
		Item {
			Layout.fillHeight: true;
		}
	}
}

