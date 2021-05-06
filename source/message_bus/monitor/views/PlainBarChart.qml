///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///
import QtQuick 2.2
import QtQuick.Controls 2.4
import "qrc:///views"

Row {
	id: plainBarChart
    property variant model: null
	property color barColor: "gray"
	
	spacing: 2

	Repeater {
		id: bars
		anchors.fill: parent
		model: plainBarChart.model

		function barWidth() {
			return (
				plainBarChart.width -
				(bars.count - 1) * plainBarChart.spacing
			) / (bars.count > 0 ? bars.count : 1)
		}

		Rectangle {
			id: bar
			anchors.bottom: bars.bottom
			color: plainBarChart.barColor

			width: bars.barWidth()
			height: plainBarChart.height * (0.05 + 0.95 * (value ? value : 0))
		}
}
}
