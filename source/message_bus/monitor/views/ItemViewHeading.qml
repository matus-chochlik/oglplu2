import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

Label {
	property string itemKind: "Unknown"
	property int itemId: 0

	Layout.fillWidth: true;
	font.pixelSize: backend.theme.hugeFontSize;
	text: qsTr("%1 <i>%2</i>")
		.arg(qsTr(itemKind, "item"))
		.arg(Number(itemId).toLocaleString(Qt.locale("C"), "f", 0))
}

