import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

RowLayout {
    id: monitorView
    property variant model: null

	NodeListView {
		Layout.fillHeight: true
		model: monitorView.model.nodeList
	}
}
