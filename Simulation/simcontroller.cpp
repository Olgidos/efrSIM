#include "simcontroller.h"


SimController::SimController()
    : wheelFL(nullptr),
      wheelFR(nullptr),
      wheelRL(nullptr),
      wheelRR(nullptr),
      displayTime(Data::instance().displayTime),
      totalSimulationTime(Data::instance().totalSimulationTime),
      playbackSpeed(Data::instance().playbackSpeed),
      timestep{&Data::instance().timestep},
      calculationTimePerStep(Data::instance().calculationTimePerStep)
{
    addProperty("SimController",this);
    calculationTimePerStep.setLock(this);

    wheelFL = new WheelFL();
    wheelFR = new WheelFR();
    wheelRL = new WheelRL();
    wheelRR = new WheelRR();
    carBody = new Mainbody();

    susJointFL = new SusJointFL( *wheelFL, *carBody );
    susJointFR = new SusJointFR( *wheelFR, *carBody );
    susJointRL = new SusJointRL( *wheelRL, *carBody );
    susJointRR = new SusJointRR( *wheelRR, *carBody );

    motorJointFL = new MotorJointFL( *wheelFL );
    motorJointFR = new MotorJointFR( *wheelFR );
    motorJointRL = new MotorJointRL( *wheelRL );
    motorJointRR = new MotorJointRR( *wheelRR );

    aeroJoint = new AeroJoint( *carBody );





    joints.push_back(susJointFL);
    joints.push_back(susJointFR);
    joints.push_back(susJointRL);
    joints.push_back(susJointRR);
    joints.push_back(motorJointFL);
    joints.push_back(motorJointFR);
    joints.push_back(motorJointRL);
    joints.push_back(motorJointRR);
    joints.push_back(aeroJoint);


    solids.push_back(wheelFL);
    solids.push_back(wheelFR);
    solids.push_back(wheelRL);
    solids.push_back(wheelRR);
    solids.push_back(carBody);

    Data::instance().total_energy.setLock(this);
    Data::instance().total_energyFlow.setLock(this);
    Data::instance().difference_energy.setLock(this);






//    t1 = new SimulationTask();
//    t2 = new SimulationTask();
//    t3 = new SimulationTask();
//    t4 = new SimulationTask();

    jointsByMainthread.push_back(susJointFL);
    jointsByMainthread.push_back(susJointFR);
    jointsByMainthread.push_back(susJointRL);
    jointsByMainthread.push_back(susJointRR);
    jointsByMainthread.push_back(motorJointFL);
    jointsByMainthread.push_back(motorJointFR);
    jointsByMainthread.push_back(motorJointRL);
    jointsByMainthread.push_back(motorJointRR);
    jointsByMainthread.push_back(aeroJoint);

    solidsByMainthread.push_back(wheelFL);
    solidsByMainthread.push_back(wheelFR);
    solidsByMainthread.push_back(wheelRL);
    solidsByMainthread.push_back(wheelRR);
    solidsByMainthread.push_back(carBody);


//    t1->start();
//    t2->start();
//    t3->start();
//    t4->start();
    start();
}

void SimController::setPlay(bool b) {
    mutexBools.lock();
    play = b;
    mutexBools.unlock();
}

void SimController::setReset(bool b) {
    mutexBools.lock();
    reset = b;
    mutexBools.unlock();
}

void SimController::setStop(bool b) {
    mutexBools.lock();
    stop = b;
    mutexBools.unlock();
}

void SimController::setPlayback(bool b){
    mutexBools.lock();
    playback = b;
    mutexBools.unlock();
    playbackChanged();
}

bool SimController::isPlay(){
    mutexBools.lock();
    bool x = play;
    mutexBools.unlock();
    return x;
}

bool SimController::isReset(){
    mutexBools.lock();
    bool x = reset;
    mutexBools.unlock();
    return x;
}

bool SimController::isStop(){
    mutexBools.lock();
    bool x = stop;
    mutexBools.unlock();
    return x;
}

bool SimController::isSimulating(){
    mutexBools.lock();
    bool x = simulating;
    mutexBools.unlock();
    return x;
}

bool SimController::isPlayback(){
    mutexBools.lock();
    bool x = playback;
    mutexBools.unlock();
    return x;
}

void SimController::setSimulating(bool b){
    mutexBools.lock();
    simulating = b;
    mutexBools.unlock();
    simulatingChanged();
}


QList<QString> SimController::getParameterListByGroup(QString group){
    QList<QString> list;
    for(Parameter* val : Parameter::parameterList){
        if(val->group == group) list.push_back(val->name);
    }
    return list;
}

QList<QString> SimController::getValueListByGroup(QString group){
    QList<QString> list;
    for(Value* val : Value::valueList){
        if(val->group == group) list.push_back(val->name);
    }
    return list;
}

QList<QString> SimController::getParameterGroups(){
    QList<QString> list;

    for(Parameter* val : Parameter::parameterList){
        if(!list.contains(val->group)) list.push_back(val->group);
    }
    return list;
}

QList<QString> SimController::getValueGroups(){
    QList<QString> list;

    for(Value* val : Value::valueList){
        if(!list.contains(val->group)) list.push_back(val->group);
    }
    return list;
}



void SimController::run(){
    qDebug() << "Simulation Controller started";

    for(Solid* solid : solids) {
        solid->setInitialState();
    }

    for(Joint* joint : joints) {
        joint->setInitialState();
    }

    while(true){
        if(isPlay()){
            setSimulating(true);
            setPlay(false);
            totalCalculationTimer.start();
            simulatingChanged();
        }

        if(isReset()){
            playback = false;
            playbackChanged();
            playbackTimer.invalidate();

            for(Solid* solid : solids) {
                solid->setInitialState();
            }

            for(Joint* joint : joints) {
                joint->setInitialState();
            }

            calculationTimePerStep.clearHistory(0.0,0.0,this);
            Data::instance().total_energy.clearHistory(0.0,-1,this);
            Data::instance().total_energyFlow.clearHistory(0.0,-1,this);
            Data::instance().difference_energy.clearHistory(0.0,-1,this);

            displayTime.setValue(-1.0);
            setReset(false);
        }

        if(isStop()){
            setSimulating(false);
            setStop(false);
            setPlayback(false);
            playbackTimer.invalidate();
        }

        if(playback){
            if(!playbackTimer.isValid()) playbackTimer.start();
            if(playbackTimer.elapsed() > 16.0){
                if(displayTime.val() + playbackTimer.elapsed()*0.001*playbackSpeed.val() >= totalSimulationTime.val()){
                    displayTime.setValue(totalSimulationTime.val());
                    setPlayback(false);
                    playbackTimer.invalidate();
                }else {
                    displayTime.setValue(displayTime.val() + playbackTimer.elapsed()*0.001*playbackSpeed.val());
                    playbackTimer.start();
                }
            }
        }


        if(isSimulating()){
            if(wheelFL->accelFinished()) {
                Data::instance().totalCalculationTime.setValue(totalCalculationTimer.elapsed());
                totalCalculationTimer.invalidate();
                setSimulating(false);
                setPlayback(true);
                writeCSV();
            }else {
                simtimeTimer.start();

//                t1->calcForcesJoint(timestep->val());
//                t2->calcForcesJoint(timestep->val());
                for(Joint* joint : jointsByMainthread) {
                    joint->calculateReactionForce(timestep->val());
                }
//                while(!t1->finished || !t2->finished);

//                t1->preCalc(timestep->val());
//                t2->preCalc(timestep->val());
                for(Solid* solid : solidsByMainthread) {
                    solid->preCalculation(timestep->val());
                }
//                while(!t1->finished || !t2->finished);

//                t1->calculateAcceln(timestep->val());
//                t2->calculateAcceln(timestep->val());
                for(Solid* solid : solidsByMainthread) {
                    solid->calculateAcceleration(timestep->val());
                }
//                while(!t1->finished || !t2->finished);

//                t1->calculatePosVelo(timestep->val());
//                t2->calculatePosVelo(timestep->val());
                for(Solid* solid : solidsByMainthread) {
                    solid->calculateNextPosVelo(timestep->val());
                }
//                while(!t1->finished || !t2->finished);

//                t1->updateValues(timestep->val());
//                t2->updateValues(timestep->val());
                for(Solid* solid : solidsByMainthread) {
                    solid->updateValues(timestep->val());
                }
//                while(!t1->finished || !t2->finished);

                displayTime.setValue(displayTime.val() + timestep->val());
                totalSimulationTime.setValue(wheelFL->getTimestamp());
                calculationTimePerStep.newValue(simtimeTimer.nsecsElapsed(),displayTime.val(),this);

                Data::instance().total_energy.newValue(wheelFL->energy.val() + wheelFR->energy.val() + wheelRL->energy.val()
                                                       + wheelRR->energy.val() + carBody ->energy.val(), wheelFL->getTimestamp(),this);
                Data::instance().total_energyFlow.newValue( motorJointFL->energyFlow.val()
                                                               + motorJointFR->energyFlow.val()
                                                               + motorJointRL->energyFlow.val()
                                                               + motorJointRR->energyFlow.val()
                                                               + susJointFL->energyFlow.val()
                                                               + susJointFR->energyFlow.val()
                                                               + susJointRL->energyFlow.val()
                                                               + susJointRR->energyFlow.val()
                                                               + aeroJoint->energyFlow.val(), wheelFL->getTimestamp(),this);
                Data::instance().difference_energy.newValue(Data::instance().total_energy.val() - Data::instance().total_energyFlow.val(), wheelFL->getTimestamp(),this);
            }

        }
       QThread::yieldCurrentThread();
       if(!isSimulating()) QThread::msleep(100);
    }
}



void SimController::writeCSV() {
    QList<QVector<QPointF>> histories;
    QList<QString> names;

    for(Value* value : Value::valueList) {
        histories.push_back(value->getHistory());
        names.push_back(value->getName());
    }

    QFile file("C:/Users/The Olg/Desktop/text.txt");
          if(file.open(QIODevice::WriteOnly | QIODevice::Text))
          {
              // We're going to streaming text to the file
              QTextStream stream(&file);

              for(QString name : names) {
                  stream << name << ",";
              }

              int l = histories.begin()->length();

              for(int i = 0; i < l; l++) {
                  for(QVector<QPointF> history : histories) {
                      stream << history.at(i).y() << ",";
                  }
              }

              file.close();
              qDebug() << "Writing finished";
          }
}




















