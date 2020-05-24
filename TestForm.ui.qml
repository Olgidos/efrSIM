import QtQuick 2.4
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.0

Item {
    width: 400
    height: 130

    Rectangle {
        id: rectangle
        height: 130
        color: "#ffffff"
        border.color: "#00000000"
        anchors.fill: parent

        ColumnLayout {
            id: columnLayout
            anchors.fill: parent

            RowLayout {
                id: rowLayout
                width: 100
                height: 100
                spacing: 10

                Label {
                    id: lblValueName
                    text: qsTr("Speed Wheel FL (m/s):")
                    Layout.topMargin: 4
                    Layout.leftMargin: 4
                    bottomPadding: 0
                    topPadding: 0
                    leftPadding: 0
                    font.weight: Font.DemiBold
                    font.pointSize: 16
                    font.family: "Verdana"
                }

                Label {
                    id: lblValue
                    text: qsTr("100")
                    Layout.rightMargin: 4
                    horizontalAlignment: Text.AlignRight
                    textFormat: Text.PlainText
                    fontSizeMode: Text.FixedSize
                    Layout.topMargin: 4
                    topPadding: 0
                    Layout.fillWidth: true
                    font.weight: Font.ExtraBold
                    font.bold: false
                    font.pointSize: 16
                    font.family: "Verdana"
                }



            }

            Rectangle {
                id: lineSeparator
                width: 200
                height: 2
                color: "#2c3035"
                radius: 5
                Layout.topMargin: 0
                border.width: 0
                Layout.rightMargin: 150
                Layout.fillWidth: true
            }

            Rectangle {
                id: rectangle1
                width: 200
                height: 200
                color: "#d69202"
                radius: 0
                Layout.fillWidth: true
                Layout.fillHeight: true
            }

        }
    }


}

/*##^##
Designer {
    D{i:2;anchors_height:100;anchors_width:100}D{i:1;anchors_height:200;anchors_width:200;anchors_x:82;anchors_y:100}
}
##^##*/
