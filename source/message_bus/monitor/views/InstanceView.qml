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
			columns: 6
			rowSpacing: 10
			columnSpacing: 20

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

	function getOGLplusVersion() {
		var m = instanceView.model.inst
		var result = "-"
		if(m.versionMajor != null) {
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

