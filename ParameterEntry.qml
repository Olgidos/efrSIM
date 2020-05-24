import QtQuick 2.4
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.0
import QtQuick.Scene3D 2.0

Rectangle {
    id: rectangle
    Layout.preferredHeight: 25
    color: "#00ffffff"
    //color: "#ffffff"
    Layout.leftMargin: 10
    Layout.rightMargin: 10
    Layout.fillWidth: true

    property QtObject object
    property alias label: label
    property alias textField: textField

    RowLayout {
        height: 25
        spacing: 30
        anchors.fill: parent

        Label {
            id: label
            text: {
                return object.getName().replace( /_/g , ",").replace( /,,/g , "_") + " " + "[" + object.unit + "]" + ":"
              }

            Layout.leftMargin: 5
            font.family: "Verdana"
            Layout.preferredWidth: -1
            verticalAlignment: Text.AlignVCenter
            Layout.fillHeight: true
            Layout.fillWidth: true
            color: "#ffc505"
        }

        TextField {
            id: textField
            text: object.value //.toFixed(5)
            font.family: "Verdana"
            Layout.bottomMargin: 1
            Layout.topMargin: 1
            Layout.maximumWidth: 200
            Layout.minimumWidth: 200
//            Layout.maximumHeight: 25
            horizontalAlignment: Text.AlignHCenter
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "#e7e7e7"
            background: Rectangle {
                color: "#00ffffff"
                radius: 10
                border.color: "#e7e7e7"
            }

            Keys.onReturnPressed: {
                object.setValue(textField.text);
            }


            MouseArea{
                anchors.fill: parent
                hoverEnabled: true;
                onExited: {
                    //textField.text = object.value.toFixed(4)
                    textField.focus = false
                    scene3D.focus = true
                    textField.text = Qt.binding(function() { return object.value}) //.toFixed(5)
                }

                onClicked: {
                    textField.forceActiveFocus();
                    textField.text = object.value.toFixed(2)
//                    Connections {
//                        target: object
//                        onValueChanged: {
//                            textField.text = object.value.toFixed(4)
//                        }
//                     }
                }

            }
        }
    }

    Connections {
        target: SimController
        onSimulatingChanged: {
            if(SimController.simulating) textField.readOnly = true;
            else textField.readOnly = false;
        }
     }


}
