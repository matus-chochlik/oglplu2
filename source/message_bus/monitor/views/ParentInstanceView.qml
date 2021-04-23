import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

Loader {
	id: parentInstanceView
    property variant model: null
	Layout.fillWidth: true

	function itemViewUrl() {
		return "qrc:///views/%1View.qml"
			.arg(parentInstanceView.model.instKind)
	}

	source: itemViewUrl()
	onLoaded: {
		parentInstanceView.item.model = parentInstanceView.model
	}
}

