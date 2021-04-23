import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

Item {
	id: unknownHostView
    property variant model: null

	ColumnLayout {
		UnknownItemViewHeading {
			itemKind: "UnknownHost"
			iconName: "UnknownHostItem"
		}
		Item {
			Layout.fillHeight: true;
		}
	}
}

