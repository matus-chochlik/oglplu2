///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///
import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

RowLayout {
	property string itemKind: "Unknown"
	AliveIndicator {}
	Label {
		Layout.fillWidth: true
		font.pixelSize: backend.theme.smallFontSize;
		text: (identifier == 0)
			? "<b>%1</b>"
				.arg(qsTr(itemKind))
			: "<b>%1:</b> %2"
				.arg(qsTr(itemKind))
				.arg(identifier)
	}
}

