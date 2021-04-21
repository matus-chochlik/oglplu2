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

	Loader {
		id: selectedItemView
		Layout.fillWidth: true
		Layout.fillHeight: true

		function itemViewUrl() {
			return "qrc:///views/%1View.qml"
				.arg(monitorView.model.selectedItem.itemKind
					? monitorView.model.selectedItem.itemKind
					: "NoItem")
		}

		source: itemViewUrl()
		onLoaded: {
			selectedItemView.item.model = monitorView.model.selectedItem
		}
	}
}
