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

		source: monitorView.model.selectedItem.itemViewUrl

		onLoaded: {
			selectedItemView.item.model = monitorView.model.selectedItem
		}
	}
}
