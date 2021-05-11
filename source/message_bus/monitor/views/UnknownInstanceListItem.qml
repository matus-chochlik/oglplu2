///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///
import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

NodeListItem {
	id: unknownHostListItem

	RowLayout {
		anchors.fill: parent
		Item {
			Layout.preferredWidth: backend.theme.nodeListInstOffset
		}
		NodeListIcon {
			iconName: "InstanceItem"
		}
		ColumnLayout {
			Layout.fillHeight: true
			NodeListHeading {
				itemKind: "Unknown instance"
			}
			Label {
				Layout.fillWidth: true
				font.italic: true
				text: "No info available"
			}
		}
	}
}
