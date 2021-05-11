///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///
import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

ColumnLayout {
	property string itemKind: "Unknown"
	property string iconName: "Unknown"
	property variant itemModel: null

	RowLayout {
		Image {
			Layout.preferredWidth:  backend.theme.itemViewIconSize
			Layout.preferredHeight: backend.theme.itemViewIconSize
			horizontalAlignment: Image.AlignHCenter
			source: "qrc:/icons/%1.svg".arg(iconName)
		}
		ColumnLayout {
			Label {
				Layout.fillWidth: true
				font.pixelSize: backend.theme.hugeFontSize;
				text: qsTr("%1 <i>%2</i>")
					.arg(qsTr(itemKind, "item"))
					.arg(itemModel.identifier ? itemModel.identifier : "?")
			}
			Label {
				text: itemModel.displayName ? qsTr(itemModel.displayName) : ""
			}
		}
	}
	Label {
		Layout.fillWidth: true
		text: itemModel.description ? qsTr(itemModel.description) : ""
	}
}
