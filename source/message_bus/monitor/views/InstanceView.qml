///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///
import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

Pane {
	id: instanceView
    property variant model: null
	leftPadding: 0

	ColumnLayout {
		anchors.fill: parent
		ItemViewHeading {
			itemKind: "Process"
			iconName: "InstanceItem"
			itemModel: instanceView.model.inst
		}
		GridLayout {
			Layout.fillWidth: true
			columns: 8
			rowSpacing: 10
			columnSpacing: 20

			Label {
				text: qsTr("Compiler")
			}
			Label {
				text: instanceView.model.inst &&
					instanceView.model.inst.compilerName
					? instanceView.model.inst.compilerName
					: "-"
			}
			Label {
				text: qsTr("Compiler version")
			}
			Label {
				text: getCompilerVersion()
			}
			Label {
				text: qsTr("Architecture")
			}
			Label {
				text: instanceView.model.inst &&
					instanceView.model.inst.architecture
					? instanceView.model.inst.architecture
					: "-"
			}
			Label {
				text: qsTr("OGLplus version")
			}
			Label {
				text: getOGLplusVersion()
			}
		}
		ParentHostView {
			Layout.fillWidth: true
			model: instanceView.model
		}
		Item {
			Layout.fillHeight: true
		}
	}

	function getCompilerVersion() {
		var result = "-"
		var m = instanceView.model.inst
		if(m && m.compilerVersionMajor != null) {
			result = "%1".arg(m.compilerVersionMajor)
			if(m.compilerVersionMinor != null) {
				result += ".%1".arg(m.compilerVersionMinor)
				if(m.compilerVersionPatch != null) {
					result += ".%1".arg(m.compilerVersionPatch)
				}
			}
		}
		return result
	}

	function getOGLplusVersion() {
		var result = "-"
		var m = instanceView.model.inst
		if(m && m.versionMajor != null) {
			result = "%1".arg(m.versionMajor)
			if(m.versionMinor != null) {
				result += ".%1".arg(m.versionMinor)
				if(m.versionPatch != null) {
					result += ".%1".arg(m.versionPatch)
					if(m.versionCommit != null) {
						result += ".%1".arg(m.versionCommit)
					}
				}
			}
		}
		return result
	}
}

