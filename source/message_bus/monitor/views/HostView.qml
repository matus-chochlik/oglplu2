import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

Pane {
	id: hostView
    property variant model: null
	leftPadding: 0

	ColumnLayout {
		ItemViewHeading {
			itemKind: "Host"
			iconName: "HostItem"
			itemModel: hostView.model.host
		}
		Item {
			Layout.fillHeight: true
		}
		Grid {
			columns: 6
			columnSpacing: 20

			Label {
				text: qsTr("CPU threads")
			}
			Label {
				text: hostView.model.host.cpuThreads
					? hostView.model.host.cpuThreads
					: "-"
			}

			Label {
				text: qsTr("Short average load")
			}
			ProgressBar {
				from: 0.0
				to: 1.0
				value: hostView.model.host.shortLoad
					? hostView.model.host.shortLoad
					: 0.0
				indeterminate: !hostView.model.host.shortLoad
			}

			Label {
				text: qsTr("Long average load")
			}
			ProgressBar {
				from: 0.0
				to: 1.0
				value: hostView.model.host.longLoad
					? hostView.model.host.longLoad
					: 0.0
				indeterminate: !hostView.model.host.longLoad
			}

			Label {
				text: qsTr("Total RAM size")
			}
			Label {
				text: hostView.model.host.ramTotal
					? "%1 MB".arg(hostView.model.host.ramTotal/1000000)
					: "-"
			}

			Label {
				text: qsTr("Free RAM size")
			}
			Label {
				text: hostView.model.host.ramFree
					? "%1 MB".arg(hostView.model.host.ramFree/1000000)
					: "-"
			}

			Label {
				text: qsTr("RAM usage")
			}
			ProgressBar {
				from: 0.0
				to: 1.0
				value: hostView.model.host.ramUsage
					? hostView.model.host.ramUsage
					: 0.0
				indeterminate: !hostView.model.host.ramUsage
			}

			Label {
				text: qsTr("Total swap size")
			}
			Label {
				text: hostView.model.host.swapTotal
					? "%1 MB".arg(hostView.model.host.swapTotal/1000000)
					: "-"
			}

			Label {
				text: qsTr("Free swap size")
			}
			Label {
				text: hostView.model.host.swapFree
					? "%1 MB".arg(hostView.model.host.swapFree/1000000)
					: "-"
			}

			Label {
				text: qsTr("Swap usage")
			}
			ProgressBar {
				from: 0.0
				to: 1.0
				value: hostView.model.host.swapUsage
					? hostView.model.host.swapUsage
					: 0.0
				indeterminate: !hostView.model.host.swapUsage
			}
		}
	}
}

