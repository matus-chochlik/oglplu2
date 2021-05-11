///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///
import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

Loader {
	id: parentInstanceView
    property variant model: null
	Layout.fillWidth: true

	source: parentInstanceView.model.instViewUrl

	onLoaded: {
		parentInstanceView.item.model = parentInstanceView.model
	}
}

