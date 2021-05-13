///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///
import QtQuick 2.2
import QtQuick.Controls 2.4

Label {
	id: numericLabel
	property var value: null
	property real numericValue: value ? value : 0
	property real duration: 1000
	property var format: function(x) {
		return x
	}

	text: format(value ? numericValue : null)

	Behavior on numericValue {
		NumberAnimation {
			duration: numericLabel.duration
		}
	}
}
