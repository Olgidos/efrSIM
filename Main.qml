import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Scene3D 2.0
import QtQuick.Controls 2.13

// Credits


Window {
    id: mainview
    width: 1800
    height: 768
    visible: true
    flags: Qt.Window
    title: "EFR Full Vehicle Simulation v1.0"

    SplitView {
        anchors.fill: parent
        ControlTab {
           id: control
           SplitView.preferredWidth: 500
           SplitView.minimumWidth: 200
           SplitView.maximumWidth: 1000
        }
        SplitView{
            orientation: Qt.Vertical

            Rectangle {
                SplitView.preferredHeight: 600
                SplitView.minimumWidth: 200
                SplitView.maximumWidth: 1000
                 Scene3D {
                   id: scene3D
                   anchors.fill: parent
                   aspects: ["render", "logic", "input"]
                   focus: true
                   Main3D { id: main3D }
                 }
            }


            Rectangle {
                color: "#3c3e40"
                ValueEntry {
                    id: bigC
                    anchors.fill: parent
                    undecorated: true
                    object: r__Mainbody_x
                    big: true
                }
            }
        }
    }
}
