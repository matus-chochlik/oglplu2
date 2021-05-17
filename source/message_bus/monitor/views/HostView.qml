///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///
import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"
import "qrc:///scripts/Format.js" as Format

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
            PlainBarChart {
                Layout.columnSpan: 5
                Layout.preferredHeight: 25
                Layout.fillWidth: true
                model: info.host.parameters.shortLoad
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
            NumericLabel {
                Layout.fillWidth: true

                value: info.host 
                    ? info.host.shortLoad
                    : null
                format: Format.percentStr
            }

            Label {
                text: qsTr("Long average load")
            }
            NumericLabel {
                Layout.fillWidth: true

                value: info.host
                    ? info.host.longLoad
                    : null
                format: Format.percentStr
            }

            Label {
                Layout.columnSpan: 2
            }

            Label {
                text: qsTr("Change")
            }
            NumericLabel {
                Layout.fillWidth: true

                value: info.host
                    ? info.host.shortLoadDelta
                    : null
                format: Format.percentStr
            }

            Label {
                text: qsTr("Change")
            }
            NumericLabel {
                Layout.fillWidth: true

                value: info.host
                    ? info.host.longLoadDelta
                    : null
                format: Format.percentStr
            }

            Label {
                text: qsTr("Total RAM size")
            }
            NumericLabel {
                Layout.fillWidth: true

                value: info.host
                    ? info.host.ramTotal
                    : null
                format: Format.megabyteStr
            }

            Label {
                text: qsTr("Free RAM size")
            }
            NumericLabel {
                Layout.fillWidth: true

                value: info.host
                    ? info.host.ramFree
                    : null
                format: Format.megabyteStr
            }

            Label {
                text: qsTr("RAM usage")
            }
            NumericLabel {
                Layout.fillWidth: true

                value: info.host
                    ? info.host.ramUsage
                    : null
                format: Format.percentStr
            }

            Label {
                Layout.columnSpan: 2
            }

            Label {
                text: qsTr("Change")
            }
            NumericLabel {
                Layout.fillWidth: true

                value: info.host
                    ? info.host.ramFreeDelta
                    : null
                format: Format.megabyteStr
            }

            Label {
                text: qsTr("Change")
            }
            NumericLabel {
                Layout.fillWidth: true

                value: info.host
                    ? info.host.ramUsageDelta
                    : null
                format: Format.percentStr
            }

            Label {
                text: qsTr("Total swap size")
            }
            NumericLabel {
                Layout.fillWidth: true

                value: info.host
                    ? info.host.swapTotal
                    : null
                format: Format.megabyteStr
            }

            Label {
                text: qsTr("Free swap size")
            }
            NumericLabel {
                Layout.fillWidth: true

                value: info.host
                    ? info.host.swapFree
                    : null
                format: Format.megabyteStr
            }

            Label {
                text: qsTr("Swap usage")
            }
            NumericLabel {
                Layout.fillWidth: true

                value: info.host
                    ? info.host.swapUsage
                    : null
                format: Format.percentStr
            }

            Label {
                Layout.columnSpan: 2
            }

            Label {
                text: qsTr("Change")
            }
            NumericLabel {
                Layout.fillWidth: true

                value: info.host
                    ? info.host.swapFreeDelta
                    : null
                format: Format.megabyteStr
            }

            Label {
                text: qsTr("Change")
            }
            NumericLabel {
                Layout.fillWidth: true

                value: info.host
                    ? info.host.swapUsageDelta
                    : null
                format: Format.percentStr
            }

            Label {
                text: qsTr("Thermal sensors temperatures")
                Layout.columnSpan: 2
            }

            Label {
                text: qsTr("Minimum")
            }
            NumericLabel {
                Layout.fillWidth: true

                value: info.host
                    ? info.host.minTemperature
                    : null
                format: Format.temperature
            }

            Label {
                text: qsTr("Maximum")
            }
            NumericLabel {
                Layout.fillWidth: true

                value: info.host
                    ? info.host.maxTemperature
                    : null
                format: Format.temperature
            }

            Label {
                Layout.columnSpan: 2
            }

            Label {
                text: qsTr("Change")
            }
            NumericLabel {
                Layout.fillWidth: true

                value: info.host
                    ? info.host.minTemperatureDelta
                    : null
                format: Format.temperatureDelta
            }

            Label {
                text: qsTr("Change")
            }
            NumericLabel {
                Layout.fillWidth: true

                value: info.host
                    ? info.host.maxTemperatureDelta
                    : null
                format: Format.temperatureDelta
            }

            Label {
                text: qsTr("Power supply")
            }
            Label {
                Layout.fillWidth: true
                text: info.host && info.host.powerSupply
                    ? info.host.powerSupply
                    : qsTr("-")
            }
        }
        Item {
            Layout.fillHeight: true
        }
    }
}

