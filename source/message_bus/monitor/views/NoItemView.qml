///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///
import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

Item {
	id: noItemView
    property variant model: null

	ColumnLayout {
		anchors.fill: parent
		Item {
			Layout.fillHeight: true;
		}
		Label {
			Layout.fillWidth: true;
			horizontalAlignment: Label.AlignHCenter
			font.pixelSize: backend.theme.hugeFontSize;
			text: qsTr("No item selected")
		}
		Label {
			Layout.fillWidth: true;
			horizontalAlignment: Label.AlignHCenter
			font.italic: true
			text: qsTr("Select a host, instance or node")
		}
		Item {
			Layout.fillHeight: true;
		}
	}
}

