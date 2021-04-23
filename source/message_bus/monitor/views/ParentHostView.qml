import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

Loader {
	id: parentHostView
    property variant model: null
	Layout.fillWidth: true

	source: parentHostView.model.hostViewUrl

	onLoaded: {
		parentHostView.item.model = parentHostView.model
	}
}

