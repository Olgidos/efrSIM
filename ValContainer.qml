import QtQuick 2.4
import QtQuick.Controls 2.13
import Qt.labs.calendar 1.0
import QtQuick.Layouts 1.0
import QtQuick.Scene3D 2.0

Rectangle {
    id: rectangle
    color: "#00ffffff"
    radius: 20

    border.color: "#e7e7e7"
    property alias label: label
    property alias rectangleHeader: rectangleHeader
    property bool enabledState: false
    property int valueCount: 0
    property int parameterCount: 0
    property string valueGroup: ""
    property string parameterGroup: ""
    property alias columnCharts: column

    clip: true
    border.width: 1
    Layout.leftMargin: 10
    Layout.rightMargin: 10
    Layout.fillWidth: true
    Layout.preferredHeight: 20

    ColumnLayout {
        anchors.fill: parent

        Rectangle {
            id: rectangleHeader
            color: "#232323"
            radius: 10
            border.width: 0
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            Layout.preferredHeight: 20
            Layout.preferredWidth: 200

            Label {
                id: label
                color: "#e7e7e7"
                text: {
                  if(valueGroup != "")return valueGroup;
                  if(parameterGroup != "")return parameterGroup;
                }
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
            }

            MouseArea {
                id: mouseArea
                hoverEnabled: true
                anchors.fill: parent

                onEntered: {
                  rectangleHeader.color = "#e7e7e7"
                  label.color= "#232323"
                }

                onExited: {
                  rectangleHeader.color = "#232323"
                  label.color= "#e7e7e7"
               }

               onClicked: enabledState = !enabledState

            }


        }

        Rectangle {
            id: charts
            color: "#00ffffff"
            border.width: 0
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.bottomMargin: 5
            visible: false

            ColumnLayout {
                id: column
                anchors.fill: parent
            }
        }
    }

    Component.onCompleted : {
        if(valueGroup != ""){
         for(var i = 0; i < SimController.getValueListByGroup(valueGroup).length; i ++){
             Qt.createQmlObject('import QtQuick 2.13; import "../Viewer"; ValueEntry { undecorated: true; object: '+ SimController.getValueListByGroup(valueGroup)[i] +' }',column);
             valueCount += 1;
         }
        }

        if(parameterGroup != ""){
         for(var x = 0; x < SimController.getParameterListByGroup(parameterGroup).length; x ++){
             //console.log('import QtQuick 2.13; import "../Viewer"; ParameterEntry {  object: '+ SimController.getParameterListByGroup(parameterGroup)[x] +' }');
             Qt.createQmlObject('import QtQuick 2.13; import "../Viewer"; ParameterEntry { object: '+ SimController.getParameterListByGroup(parameterGroup)[x] +' }',column);
             parameterCount += 1;
         }
        }
    }


    states: [
        State {
            name: "ChartState"
            when: enabledState

            PropertyChanges {
                target: rectangle
                Layout.preferredHeight:  {
                    return 20 + 5 + valueCount*140 + parameterCount*30
                }
            }

            PropertyChanges {
                target: charts
                visible: true
            }
        }

    ]
}

