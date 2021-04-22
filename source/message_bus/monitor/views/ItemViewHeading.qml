import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

RowLayout {
	property string itemKind: "Unknown"
	property string iconName: "Unknown"
	property variant itemModel: null

	Image {
		Layout.preferredWidth:  backend.theme.itemViewIconSize
		Layout.preferredHeight: backend.theme.itemViewIconSize
		horizontalAlignment: Image.AlignHCenter
		source: "qrc:/icons/%1.svg".arg(iconName)
	}
	ColumnLayout {
		Label {
			Layout.fillWidth: true;
			font.pixelSize: backend.theme.hugeFontSize;
			text: qsTr("%1 <i>%2</i>")
				.arg(qsTr(itemKind, "item"))
				.arg(itemModel.identifier ? itemModel.identifier : "?")
		}
		Label {
			text: itemModel.displayName ? itemModel.displayName : ""
		}
	}
}

