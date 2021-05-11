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
				text: qsTr("%1")
					.arg(qsTr(itemKind, "item"))
			}
			Label {
				text: qsTr("unknown name", "item")
			}
		}
	}
	Label {
		Layout.fillWidth: true
		text: qsTr("no information available", "item")
	}
}
