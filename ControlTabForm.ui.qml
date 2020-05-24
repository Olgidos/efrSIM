import QtQuick 2.12
import QtQuick.Layouts 1.0
import QtQuick.Templates 2.13
import QtQuick.Controls 2.13
import QtQuick.Scene3D 2.0

Item {
    id: item
    width: 700
    height: 700
    property alias columnLayoutSettings: columnLayoutSettings
    property alias columnLayoutValues: columnLayoutValues
    property alias buttonReset: buttonReset
    property alias buttonPause: buttonPause
    property alias buttonPlay: buttonPlay
    property alias buttonSettings: buttonSettings
    property alias buttonData: buttonData
    property alias mouseAreaData: mouseAreaData
    property alias mouseAreaSettings: mouseAreaSettings
    property alias mouseAreaPlay: mouseAreaPlay
    property alias mouseAreaPause: mouseAreaPause
    property alias mouseAreaReset: mouseAreaReset
    property int currentPage: 0
    property Item controlTab: item

    RowLayout {
        width: 700
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        spacing: 0
        anchors.fill: parent

        Rectangle {
            id: mainbar
            width: 40
            color: "#232323"
            border.width: 0
            Layout.maximumWidth: 40
            clip: false
            Layout.fillHeight: true
            Layout.preferredHeight: 200
            Layout.preferredWidth: 200

            ColumnLayout {
                id: columnLayout
                spacing: 0
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                anchors.bottomMargin: 0
                anchors.topMargin: 0
                anchors.fill: parent

                Button {
                    id: buttonData
                    height: 30
                    text: qsTr("")
                    Layout.alignment: Qt.AlignLeft | Qt.AlignBottom
                    Layout.fillWidth: true
                    Layout.minimumHeight: 10
                    Layout.minimumWidth: 10
                    icon.source: "qrc:/Objects/icons/menu.png"
                    icon.color: "#e7e7e7"
                    background.visible: false

                    MouseArea {
                        id: mouseAreaData
                        anchors.fill: parent
                        hoverEnabled: true
                    }
                }

                Button {
                    id: buttonSettings
                    height: 30
                    text: qsTr("")
                    Layout.alignment: Qt.AlignLeft | Qt.AlignBottom
                    Layout.fillWidth: true
                    Layout.minimumHeight: 10
                    Layout.minimumWidth: 10
                    icon.source: "qrc:/Objects/icons/setting2s.png"
                    icon.color: "#e7e7e7"
                    background.visible: false

                    MouseArea {
                        id: mouseAreaSettings
                        anchors.fill: parent
                        hoverEnabled: true
                    }
                }

                Rectangle {
                    id: space
                    width: 200
                    height: 200
                    color: "#00ffffff"
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                }

                Rectangle {
                    id: rectangle1
                    width: 200
                    height: 200
                    color: "#3c3e40"
                    Layout.fillWidth: true
                    Layout.minimumHeight: 1
                    Layout.maximumHeight: 1
                }

                Button {
                    id: buttonPlay
                    height: 30
                    text: qsTr("")
                    Layout.topMargin: 4
                    Layout.alignment: Qt.AlignLeft | Qt.AlignBottom
                    Layout.fillWidth: true
                    Layout.minimumHeight: 10
                    Layout.minimumWidth: 10
                    icon.source: "qrc:/Objects/icons/play-button.png"
                    icon.color: "#7fc241"
                    background.visible: false

                    MouseArea {
                        id: mouseAreaPlay
                        anchors.fill: parent
                        hoverEnabled: true
                    }
                }

                Button {
                    id: buttonPause
                    height: 30
                    text: qsTr("")
                    Layout.alignment: Qt.AlignLeft | Qt.AlignBottom
                    Layout.fillWidth: true
                    Layout.minimumHeight: 10
                    Layout.minimumWidth: 10
                    icon.source: "qrc:/Objects/icons/pause.png"
                    icon.color: "#e7e7e7"
                    background.visible: false

                    MouseArea {
                        id: mouseAreaPause
                        anchors.fill: parent
                        hoverEnabled: true
                    }
                }


                Button {
                    id: buttonReset
                    height: 30
                    text: qsTr("")
                    Layout.alignment: Qt.AlignLeft | Qt.AlignBottom
                    Layout.fillWidth: true
                    Layout.minimumHeight: 10
                    Layout.minimumWidth: 10
                    icon.source: "qrc:/Objects/icons/repeat.png"
                    icon.color: "#e7e7e7"
                    background.visible: false

                    MouseArea {
                        id: mouseAreaReset
                        anchors.fill: parent
                        hoverEnabled: true
                    }
                }






            }
        }

        Rectangle {
            id: rectangle
            color: "#3c3e40"
            radius: 0
            Layout.fillHeight: true
            Layout.fillWidth: true
            opacity: 1
            border.color: "#232323"
            border.width: 1

            ColumnLayout {
                id: columnLayoutValues1
                anchors.fill: parent

                Label {
                    id: labelValues
                    color: "#e7e7e7"
                    text: qsTr("Values:")
                    clip: true
                    Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                    Layout.fillWidth: true
                    font.family: "Verdana"
                    font.bold: true
                    font.pointSize: 20
                    Layout.leftMargin: 20
                    Layout.rightMargin: 20
                    Layout.bottomMargin: 20
                    Layout.topMargin: 20
                }




                ScrollView {
                    id: scrollViewValues
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    clip: true
                    ScrollBar.vertical.policy: ScrollBar.AlwaysOn

                    ColumnLayout {
                        id: columnLayoutValues
                        width: scrollViewValues.width
                    }
                }

            }

            ColumnLayout {
                id: columnLayout1
                visible: false
                anchors.fill: parent

                Label {
                    id: labelSettings
                    color: "#e7e7e7"
                    text: qsTr("Values:")
                    Layout.fillWidth: true
                    font.bold: true
                    Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                    font.family: "Verdana"
                    clip: true
                    Layout.leftMargin: 20
                    Layout.topMargin: 20
                    Layout.rightMargin: 20
                    Layout.bottomMargin: 20
                    font.pointSize: 20
                }

                ScrollView {
                    id: scrollViewSettings
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    clip: true
                    ColumnLayout {
                        id: columnLayoutSettings
                        width: scrollViewSettings.width
                    }
                }
            }
        }
    }



    states: [
        State {
            name: "Settings"
            when: currentPage == 1

            PropertyChanges {
                target: labelValues
                text: qsTr("Settings:")
            }

            PropertyChanges {
                target: scrollViewValues
                visible: false
            }

            PropertyChanges {
                target: columnLayoutValues
                visible: false
            }

            PropertyChanges {
                target: labelSettings
                text: qsTr("Settings:")
            }

            PropertyChanges {
                target: columnLayout1
                visible: true
            }
        }


    ]

}

/*##^##
Designer {
    D{i:6;anchors_height:100;anchors_width:100}D{i:3;anchors_height:100;anchors_width:100}
D{i:2;anchors_height:100;anchors_width:100;anchors_x:160;anchors_y:360}D{i:1;anchors_x:"-266";anchors_y:83}
}
##^##*/
