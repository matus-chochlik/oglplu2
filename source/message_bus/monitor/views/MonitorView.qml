import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

RowLayout {
    id: monitorView
    property variant model: null

	ListView {
		Layout.preferredWidth: 200
		Layout.fillHeight: true

		model: monitorView.model.nodeList
		delegate: NodeListItem {
			Layout.fillWidth: true
		}
		clip: true
	}
}
