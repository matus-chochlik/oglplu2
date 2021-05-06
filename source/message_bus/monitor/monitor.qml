///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///
import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Controls.Material 2.4
import QtQuick.Layouts 1.2
import "qrc:///views"

ApplicationWindow {
    id: root
    visible: true
    width: 1200
    height: 800
    Material.theme: backend.theme.light ? Material.Light : Material.Dark
	Material.accent: Material.Blue
    Action {
        id: quitAction
        text: qsTr("&Quit")
        shortcut: StandardKey.Quit
        onTriggered: {
            Qt.callLater(Qt.quit)
        }
    }

    Action {
        id: lightThemeToggleAction
        text: qsTr("&Light")
		checkable: true
		checked: backend.theme.light
        onToggled: {
            backend.theme.light = checked
        }
    }

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {
                action: quitAction
            }
        }
        Menu {
            title: qsTr("&Window")
        	Menu {
            	title: qsTr("&Theme")
				MenuItem {
					action: lightThemeToggleAction
				}
			}
        }
    }

    contentData: MonitorView {
        anchors.fill: parent
        model: backend.monitor
    }
}
