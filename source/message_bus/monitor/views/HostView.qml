import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

Pane {
	id: hostView
    property variant model: null
	property var lc: Qt.locale("C")
	Layout.fillWidth: true
	leftPadding: 0

	ColumnLayout {
		anchors.fill: parent
		ItemViewHeading {
			itemKind: "Host"
			iconName: "HostItem"
			itemModel: hostView.model.host
		}
		Item {
			Layout.fillHeight: true
		}
		GridLayout {
			Layout.fillWidth: true
			columns: 6
			rowSpacing: 20
			columnSpacing: 20

			Label {
				text: qsTr("Load")
			}
			ProgressBar {
				Layout.columnSpan: 5
				Layout.fillWidth: true
				from: 0.0
				to: 1.0
				value: hostView.model.host.shortLoad
					? hostView.model.host.shortLoad
					: 0.0
				indeterminate: !hostView.model.host.shortLoad
			}

			Label {
				text: qsTr("CPU threads")
			}
			Label {
				Layout.fillWidth: true
				text: hostView.model.host.cpuThreads
					? hostView.model.host.cpuThreads
					: "-"
			}

			Label {
				text: qsTr("Short average load")
			}
			Label {
				Layout.fillWidth: true
				text: hostView.model.host.shortLoad
					? "%1 %".arg(
						Number(hostView.model.host.shortLoad*100.0)
							.toLocaleString(lc, "f", 1))
					: "-"
			}

			Label {
				text: qsTr("Long average load")
			}
			Label {
				Layout.fillWidth: true
				text: hostView.model.host.longLoad
					? "%1 %".arg(
						Number(hostView.model.host.longLoad*100.0)
							.toLocaleString(lc, "f", 1))
					: "-"
			}

			Label {
				Layout.columnSpan: 2
			}

			Label {
				text: qsTr("Change")
			}
			Label {
				Layout.fillWidth: true
				text: hostView.model.host.shortLoadDelta
					? "%1 %".arg(
						Number(hostView.model.host.shortLoadDelta*100.0)
							.toLocaleString(lc, "f", 1))
					: "-"
			}

			Label {
				text: qsTr("Change")
			}
			Label {
				Layout.fillWidth: true
				text: hostView.model.host.longLoadDelta
					? "%1 %".arg(
						Number(hostView.model.host.longLoadDelta*100.0)
							.toLocaleString(lc, "f", 1))
					: "-"
			}

			Label {
				text: qsTr("Total RAM size")
			}
			Label {
				text: hostView.model.host.ramTotal
					? "%1 MB".arg(
						Number(hostView.model.host.ramTotal/1000000)
							.toLocaleString(lc, "f", 0))
					: "-"
			}

			Label {
				text: qsTr("Free RAM size")
			}
			Label {
				text: hostView.model.host.ramFree
					? "%1 MB".arg(
						Number(hostView.model.host.ramFree/1000000)
							.toLocaleString(lc, "f", 1))
					: "-"
			}

			Label {
				text: qsTr("RAM usage")
			}
			Label {
				text: hostView.model.host.ramUsage
					? "%1 %".arg(
						Number(hostView.model.host.ramUsage*100.0)
							.toLocaleString(lc, "f", 1))
					: "-"
			}

			Label {
				Layout.columnSpan: 2
			}

			Label {
				text: qsTr("Change")
			}
			Label {
				Layout.fillWidth: true
				text: hostView.model.host.ramFreeDelta
					? "%1 MB".arg(
						Number(hostView.model.host.ramFreeDelta/1000000)
							.toLocaleString(lc, "f", 1))
					: "-"
			}

			Label {
				text: qsTr("Change")
			}
			Label {
				Layout.fillWidth: true
				text: hostView.model.host.ramUsageDelta
					? "%1 %".arg(
						Number(hostView.model.host.ramUsageDelta*100.0)
							.toLocaleString(lc, "f", 2))
					: "-"
			}

			Label {
				text: qsTr("Total swap size")
			}
			Label {
				text: hostView.model.host.swapTotal
					? "%1 MB".arg(
						Number(hostView.model.host.swapTotal/1000000)
							.toLocaleString(lc, "f", 0))
					: "-"
			}

			Label {
				text: qsTr("Free swap size")
			}
			Label {
				text: hostView.model.host.swapFree
					? "%1 MB".arg(
						Number(hostView.model.host.swapFree/1000000)
							.toLocaleString(lc, "f", 1))
					: "-"
			}

			Label {
				text: qsTr("Swap usage")
			}
			Label {
				text: hostView.model.host.swapUsage
					? "%1 %".arg(
						Number(hostView.model.host.swapUsage*100.0)
							.toLocaleString(lc, "f", 1))
					: "-"
			}

			Label {
				Layout.columnSpan: 2
			}

			Label {
				text: qsTr("Change")
			}
			Label {
				Layout.fillWidth: true
				text: hostView.model.host.swapFreeDelta
					? "%1 MB".arg(
						Number(hostView.model.host.swapFreeDelta/1000000)
							.toLocaleString(lc, "f", 1))
					: "-"
			}

			Label {
				text: qsTr("Change")
			}
			Label {
				Layout.fillWidth: true
				text: hostView.model.host.swapUsageDelta
					? "%1 %".arg(
						Number(hostView.model.host.swapUsageDelta*100.0)
							.toLocaleString(lc, "f", 2))
					: "-"
			}
		}
	}
}

