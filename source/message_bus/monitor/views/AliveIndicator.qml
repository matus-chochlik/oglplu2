///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///
import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

Image {
	Layout.preferredWidth:  backend.theme.nodeListAliveSize
	Layout.preferredHeight: backend.theme.nodeListAliveSize
	horizontalAlignment: Image.AlignHCenter
	verticalAlignment: Image.AlignVCenter
	source: "qrc:/icons/%1.svg"
		.arg(isResponsive ? "Responsive" : "Unresponsive")
}

