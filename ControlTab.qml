import QtQuick 2.12

ControlTabForm {

//    velo.text: (MainVeloX.value*100).toFixed(4)

//    time.text: (MainVeloX.timestamp/100).toFixed(2)

//    pos.text: (MainPosX.value - 0.67).toFixed(4)

    //Data Button
    mouseAreaData.onEntered: {
        buttonData.background.visible = true;
        buttonData.icon.color= "#232323";
    }
    mouseAreaData.onExited: {
        if(currentPage != 0){
        buttonData.background.visible = false;
        buttonData.icon.color= "#e7e7e7";
        }
    }
    mouseAreaData.onClicked: {
       currentPage = 0;
       buttonSettings.background.visible = false;
       buttonSettings.icon.color= "#e7e7e7";
    }

    //Settings Button
    mouseAreaSettings.onEntered: {
        buttonSettings.background.visible = true;
        buttonSettings.icon.color= "#232323";
    }
    mouseAreaSettings.onExited: {
        if(currentPage != 1){
        buttonSettings.background.visible = false;
        buttonSettings.icon.color= "#e7e7e7";
        }
    }
    mouseAreaSettings.onClicked: {
       currentPage = 1;

        buttonData.background.visible = false;
        buttonData.icon.color= "#e7e7e7";
    }

    //Start Button
    mouseAreaPlay.onEntered: {
        buttonPlay.background.visible = true;
        buttonPlay.icon.color= "#232323";
    }
    mouseAreaPlay.onExited: {
        buttonPlay.background.visible = false;
        buttonPlay.icon.color= "#7fc241"
    }
    mouseAreaPlay.onClicked: {
        SimController.setPlay(true);
    }

    //Pause Button
    mouseAreaPause.onEntered: {
        buttonPause.background.visible = true;
        buttonPause.icon.color= "#232323";
    }
    mouseAreaPause.onExited: {
        buttonPause.background.visible = false;
        buttonPause.icon.color= "#e7e7e7";
    }
    mouseAreaPause.onClicked: {
        SimController.setStop(true);
    }

    //Reset Button
    mouseAreaReset.onEntered: {
        buttonReset.background.visible = true;
        buttonReset.icon.color= "#232323";
    }
    mouseAreaReset.onExited: {
        buttonReset.background.visible = false;
        buttonReset.icon.color= "#e7e7e7";
    }
    mouseAreaReset.onClicked: {
        SimController.setReset(true);
    }


    Component.onCompleted : {

        //Create Values
         for(var i = 0; i < SimController.getValueGroups().length; i++){
             Qt.createQmlObject('import QtQuick 2.13; import "../Viewer"; ValContainer { valueGroup: "'+ SimController.getValueGroups()[i] +'" }',columnLayoutValues);
         }

         //Create Paremeters
         for(var x = 0; x < SimController.getParameterGroups().length; x++){
             Qt.createQmlObject('import QtQuick 2.13; import "../Viewer"; ValContainer { parameterGroup: "'+ SimController.getParameterGroups()[x] +'" }',columnLayoutSettings);
         }

    }
}

