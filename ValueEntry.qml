import QtQuick 2.4
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.0
import QtCharts 2.3
import QtQuick.Scene3D 2.0


Rectangle {
    id: rectangle
    property bool undecorated: false
    property bool big: false
    property QtObject object
    property int chartUpdateRate: 30
    property alias lineSeries: series

    Layout.preferredHeight: 23
    color: "#3c3e40"
//    radius: 10
//    border.color: "#bcbaba"
    Layout.leftMargin: 10
    Layout.rightMargin: 10
//    border.width: 1
    Layout.fillWidth: true

    ColumnLayout {
        id: columnLayout
        anchors.fill: parent

        RowLayout {
            id: rowLayout
            height: 23
            spacing: 10

            CheckBox {
                id: chartSwitch
                Layout.topMargin: 3
                Layout.leftMargin: 10
                Layout.bottomMargin: 3
                bottomPadding: 0
                topPadding: 0
                leftPadding: 0
            }


            Label {
                id: lblValueName
                text: {
                    return " " + object.getName().replace( /_/g , ",").replace( /,,/g , "_") + " " + "[" + object.unit + "]";
                }
                Layout.topMargin: 0
                Layout.leftMargin: 0
                bottomPadding: 0
                topPadding: 0
                leftPadding: 0
                font.weight: Font.DemiBold
                font.pointSize: 8
                font.family: "Verdana"
                color: "#ffc505"

                MouseArea{
                    anchors.fill: parent

                    onDoubleClicked: {
                      bigC.object = object;
                      bigC.lineSeries.clear();
                    }
                }
            }

            Label {
                id: lblValue
                //text: object.value.toFixed(4)
                horizontalAlignment: Text.AlignRight
                textFormat: Text.PlainText
                fontSizeMode: Text.FixedSize
                Layout.topMargin: 0
                Layout.rightMargin: 10
                topPadding: 0
                Layout.fillWidth: true
                font.weight: Font.ExtraBold
                font.bold: false
                font.pointSize: 8
                font.family: "Verdana"
                color: "#ffc505"
            }

        }

//        Rectangle {
//            id: lineSeparator
//            height: 2
//            color: "#2c3035"
//            radius: 5
//            Layout.topMargin: 0
//            border.width: 0
//            Layout.rightMargin: 150
//            Layout.fillWidth: true
//            border.color: "#5cffc505"
//        }

        Rectangle {
            id: chartRect
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.topMargin: 0
            Layout.leftMargin: 0
            Layout.rightMargin: 0
            Layout.bottomMargin: 0
            clip: true
            border.width: 0
            color: "transparent"
            visible: false

            //CHART HERE
            ChartView {
                id: chart
                antialiasing: true
                backgroundColor: "transparent"
                legend.visible: false
                clip: true
                anchors.fill: parent
                margins.top: 0
                margins.bottom: 0
                margins.left: 0
                margins.right: 0
                backgroundRoundness: 0

                //Performance
                animationOptions: ChartView.NoAnimation

                Slider {
                    id: control
                    anchors.fill: parent
                    anchors.bottomMargin: 5
                    anchors.leftMargin: 40
                    anchors.rightMargin: 22

                    onMoved: {
                        DisplayTime.setValue(control.value*(TotalSimulationTime.value+1)-1);
                        scene3D.focus = true;
                    }


                    handle: Rectangle {
                        id: handle
                        x: control.visualPosition * (control.width - width)
                        y: (control.height - height) / 2
                        color: "red"
                        width: 2
                        height: control.height
                    }

                    background: Rectangle {
                        visible: false
                    }

                    Timer {
                        id: sliderTimer
                        interval: 1 / 60 * 1000 // 60 Hz
                        running: true
                        repeat: true
                        onTriggered: {
                            handle.visible = !SimController.simulating;
                            if(TotalSimulationTime.value === -1.0){
                                control.value = 0;
                                return;
                            }
                            control.value = (DisplayTime.value+1)/(TotalSimulationTime.value+1);
                        }
                    }
                }

                ValueAxis {
                    id: xAxis
    //              labelsVisible: false
                    gridVisible:false
                    minorGridVisible:false
                    minorTickCount: 0
                    tickCount: 5
                    tickAnchor: 0
                    labelsFont.family:  "Verdana"
                    labelsFont.pixelSize: 10
                    labelsColor: "#bcbaba"
                    max: 75
                }

                ValueAxis {
                    id: yAxis
        //          labelsVisible: false
                    gridVisible:false
                    minorGridVisible:false
                    minorTickCount: 1
                    tickCount: 3
                    max: 5
                    labelsFont.family:  "Verdana"
                    labelsColor: "#bcbaba"
                    labelsFont.pixelSize: 10
                }

                LineSeries {
                    id: series
                    XYPoint {
                        x: 0
                        y: 0 }
                    color: "#ffc505"
//                    style: Qt.
                    axisX: xAxis
                    axisY: yAxis
                    name: ""
                    useOpenGL: true;
                }

            }
        }
    }

    Timer {
        id: refreshTimerBig
        interval: 1.0 / chartUpdateRate * 1000.0 // 60 Hz
        running: true
        repeat: true
        onTriggered: {
            if(big) {
                object.updateChart(series, xAxis, yAxis, true);
            }

        }
    }

    Timer {
        id: refreshTimer
        interval: 1.0 / chartUpdateRate * 10 * 1000.0 // 60 Hz
        running: true
        repeat: true
        onTriggered: {
            if(chartRect.visible && !big){
                object.updateChart(series, xAxis, yAxis, false);
                lblValue.text = object.value.toFixed(4);
            }
        }
    }

    Timer {
        id: refreshTimerValue
        interval: 1.0 / 1 * 1000.0 // 30 Hz
        running: true
        repeat: true
        onTriggered: {
            if(chartRect.visible){
                lblValue.text = object.value.toFixed(4);
            }
        }
    }

//    Connections {
//        target: SimController
//        onSimulatingChanged: {
//                if(!SimController.simulating){
//                    chart.removeAllSeries();
//                    chart.visible = false;
//                    var series = chart.createSeries(ChartView.SeriesTypeLine, "series", xAxis, yAxis);
//                    series.useOpenGL = true;
//                    for( var i = 0; i < object.getValueHistoryGUI().length; i++){
//                        series.append(object.getTimestampHistoryGUI()[i], object.getValueHistoryGUI()[i]);
////                        if(series.axisX.max < object.getValueHistory()[i]) {
////                            series.axisX.max = object.getValueHistory()[i];
////                        }
////                        if(series.axisY.max < object.getValueHistory()[i]) {
////                            series.axisY.max = object.getValueHistory()[i];
////                        }
//                    }
//                    //series.axisX.max = object.getTimestampHistoryGUI()[object.getTimestampHistoryGUI().length - 1];
//                    chart.visible = true;
//                }
//        }
//     }

    states: [
        State {
            name: "ChartState"
            when: chartSwitch.checked

            PropertyChanges {
                target: rectangle
                Layout.preferredHeight: 130
            }

            PropertyChanges {
                target: chartRect
                visible: true
            }
        },

        State {
            name: "undecoratedState"
            when: undecorated

            PropertyChanges {
                target: chartSwitch
                visible: false

            }

            PropertyChanges {
                target: rectangle
                Layout.preferredHeight: 130
            }

            PropertyChanges {
                target: chartRect
                visible: true
            }

        }

    ]

    Connections {
        target: SimController
        onSimulatingChanged: {
            if(SimController.simulating) chartUpdateRate = 10.0;
            else chartUpdateRate = 30.0;
        }
     }


}





