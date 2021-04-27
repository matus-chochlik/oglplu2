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
		GridLayout {
			id: info
			property variant host: hostView.model.host
			Layout.fillWidth: true
			columns: 6
			rowSpacing: 10
			columnSpacing: 20

			Label {
				text: qsTr("Load")
			}
			ProgressBar {
				Layout.columnSpan: 5
				Layout.fillWidth: true
				from: 0.0
				to: 1.0
				value: info.host && info.host.shortLoad
					? info.host.shortLoad
					: 0.0
				indeterminate: !(info.host && info.host.shortLoad)
			}

			Label {
				text: qsTr("CPU threads")
			}
			Label {
				Layout.fillWidth: true
				text: info.host && info.host.cpuThreads
					? info.host.cpuThreads
					: "-"
			}

			Label {
				text: qsTr("Short average load")
			}
			Label {
				Layout.fillWidth: true
				text: info.host && info.host.shortLoad
					? "%1 %".arg(
						Number(info.host.shortLoad*100.0)
							.toLocaleString(lc, "f", 1))
					: "-"
			}

			Label {
				text: qsTr("Long average load")
			}
			Label {
				Layout.fillWidth: true
				text: info.host && info.host.longLoad
					? "%1 %".arg(
						Number(info.host.longLoad*100.0)
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
				text: info.host && info.host.shortLoadDelta
					? "%1 %".arg(
						Number(info.host.shortLoadDelta*100.0)
							.toLocaleString(lc, "f", 1))
					: "-"
			}

			Label {
				text: qsTr("Change")
			}
			Label {
				Layout.fillWidth: true
				text: info.host && info.host.longLoadDelta
					? "%1 %".arg(
						Number(info.host.longLoadDelta*100.0)
							.toLocaleString(lc, "f", 1))
					: "-"
			}

			Label {
				text: qsTr("Total RAM size")
			}
			Label {
				text: info.host && info.host.ramTotal
					? "%1 MB".arg(
						Number(info.host.ramTotal/1000000)
							.toLocaleString(lc, "f", 0))
					: "-"
			}

			Label {
				text: qsTr("Free RAM size")
			}
			Label {
				text: info.host && info.host.ramFree
					? "%1 MB".arg(
						Number(info.host.ramFree/1000000)
							.toLocaleString(lc, "f", 1))
					: "-"
			}

			Label {
				text: qsTr("RAM usage")
			}
			Label {
				text: info.host && info.host.ramUsage
					? "%1 %".arg(
						Number(info.host.ramUsage*100.0)
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
				text: info.host && info.host.ramFreeDelta
					? "%1 MB".arg(
						Number(info.host.ramFreeDelta/1000000)
							.toLocaleString(lc, "f", 1))
					: "-"
			}

			Label {
				text: qsTr("Change")
			}
			Label {
				Layout.fillWidth: true
				text: info.host && info.host.ramUsageDelta
					? "%1 %".arg(
						Number(info.host.ramUsageDelta*100.0)
							.toLocaleString(lc, "f", 2))
					: "-"
			}

			Label {
				text: qsTr("Total swap size")
			}
			Label {
				text: info.host && info.host.swapTotal
					? "%1 MB".arg(
						Number(info.host.swapTotal/1000000)
							.toLocaleString(lc, "f", 0))
					: "-"
			}

			Label {
				text: qsTr("Free swap size")
			}
			Label {
				text: info.host && info.host.swapFree
					? "%1 MB".arg(
						Number(info.host.swapFree/1000000)
							.toLocaleString(lc, "f", 1))
					: "-"
			}

			Label {
				text: qsTr("Swap usage")
			}
			Label {
				text: info.host && info.host.swapUsage
					? "%1 %".arg(
						Number(info.host.swapUsage*100.0)
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
				text: info.host && info.host.swapFreeDelta
					? "%1 MB".arg(
						Number(info.host.swapFreeDelta/1000000)
							.toLocaleString(lc, "f", 1))
					: "-"
			}

			Label {
				text: qsTr("Change")
			}
			Label {
				Layout.fillWidth: true
				text: info.host && info.host.swapUsageDelta
					? "%1 %".arg(
						Number(info.host.swapUsageDelta*100.0)
							.toLocaleString(lc, "f", 2))
					: "-"
			}
		}
		Item {
			Layout.fillHeight: true
		}
	}
}

