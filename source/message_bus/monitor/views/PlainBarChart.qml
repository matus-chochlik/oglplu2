///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///
import QtQuick 2.2
import QtQuick.Controls 2.4
import "qrc:///views"

Pane {
	id: plainBarChart
	property variant model: null
	property color barColor: "gray"

	background: Rectangle {
		color: "gray"
		opacity: 0.1
		radius: 2
	}

	contentItem: Row {
		id: barArea
		anchors.fill: parent

		spacing: 2

		Repeater {
			id: bars
			anchors.fill: parent
			model: plainBarChart.model

			function barWidth() {
				return (
					barArea.width -
					(bars.count - 1) * barArea.spacing
				) / (bars.count > 0 ? bars.count : 1)
			}

			Rectangle {
				id: bar
				anchors.bottom: bars.bottom
				color: plainBarChart.barColor
				antialiasing: true

				width: bars.barWidth()
				height: barArea.height * (0.05 + 0.95 * (value ? value : 0))
			}
		}
	}
}
