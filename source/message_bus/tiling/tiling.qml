///
/// Copyright Matus Chochlik.
/// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
///
import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Dialogs 1.3
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
        id: saveAction
        text: qsTr("&Save")
        shortcut: StandardKey.Save
        onTriggered: {
            saveDialog.open()
        }
    }

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
            Menu {
                title: qsTr("&New tiling")
                MenuItem {
                    text: qsTr("16x16")
                    onTriggered: {
                        backend.tiling.reinitialize(32, 32)
                    }
                }
                MenuItem {
                    text: qsTr("32x32")
                    onTriggered: {
                        backend.tiling.reinitialize(32, 32)
                    }
                }
                MenuItem {
                    text: qsTr("64x64")
                    onTriggered: {
                        backend.tiling.reinitialize(64, 64)
                    }
                }
                MenuItem {
                    text: qsTr("128x128")
                    onTriggered: {
                        backend.tiling.reinitialize(128, 128)
                    }
                }
                MenuItem {
                    text: qsTr("256x256")
                    onTriggered: {
                        backend.tiling.reinitialize(256, 256)
                    }
                }
                MenuItem {
                    text: qsTr("512x512")
                    onTriggered: {
                        backend.tiling.reinitialize(256, 256)
                    }
                }
            }
            MenuItem {
                action: saveAction
            }
            MenuSeparator { }
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

    contentData: TilingView {
        anchors.fill: parent
        model: backend.tiling
    }

    FileDialog {
        id: saveDialog
        title: qsTr("Save tiling into file")
        folder: shortcuts.home
        selectExisting: false
        selectMultiple: false
        selectFolder: false
        onAccepted: {
            backend.tiling.saveAs(saveDialog.fileUrl)
        }

        Component.onCompleted: visible = false
    }
}
