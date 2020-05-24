#ifndef SIMCONTROLLER_H
#define SIMCONTROLLER_H
#include <QMutex>
#include <QObject>
#include <QDebug>
#include <Model/data.h>
#include <QThreadPool>
#include <QFuture>
#include <QtConcurrent>
#include <QFutureSynchronizer>
#include <Simulation/Solids/wheelFL.h>
#include <Simulation/Solids/wheelFR.h>
#include <Simulation/Solids/wheelRL.h>
#include <Simulation/Solids/wheelRR.h>
#include <Simulation/Solids/mainbody.h>
#include <Simulation/Joints/susjointFL.h>
#include <Simulation/Joints/susjointFR.h>
#include <Simulation/Joints/susjointRL.h>
#include <Simulation/Joints/susjointRR.h>
#include <Simulation/Joints/motorjointFL.h>
#include <Simulation/Joints/motorjointFR.h>
#include <Simulation/Joints/motorjointRL.h>
#include <Simulation/Joints/motorjointRR.h>
#include <Simulation/Joints/aerojoint.h>


extern void addProperty(const QString, QObject *obj);

class SimulationTask : public QThread
{
public:
    QList<Solid*> solids;
    QList<Joint*> joints;
    double timestep;
    bool finished = false;

    void addJoint(Joint *joint){
        joints.append(joint);
    }

    void addSolid(Solid *solid){
        solids.append(solid);
    }

    void preCalc(double i_timestep) {
        timestep = i_timestep;
        preCalcBool = true;
        finished = false;
    }
    bool preCalcBool = false;

    void calculateAcceln(double i_timestep) {
        timestep = i_timestep;
        calculateAcceleration = true;
        finished = false;
    }
    bool calculateAcceleration = false;

    void calculatePosVelo(double i_timestep) {
        timestep = i_timestep;
        calculatePosVeloBool = true;
        finished = false;
    }
    bool calculatePosVeloBool = false;


    void updateValues(double i_timestep) {
        timestep = i_timestep;
        updateValuesBool = true;
        finished = false;
    }
    bool updateValuesBool = false;

    void calcForcesJoint(double i_timestep) {
        timestep = i_timestep;
        calcForcesJointBool = true;
        finished = false;
    }
    bool calcForcesJointBool = false;


    void run() override
    {
        while(true){

            if(preCalcBool) {
                for(Solid* solid : solids) {
                    solid->preCalculation(timestep);
                }
                preCalcBool = false;
                finished = true;
            }

            if(calculateAcceleration) {
                for(Solid* solid : solids) {
                    solid->calculateAcceleration(timestep);
                }
                calculateAcceleration = false;
                finished = true;
            }

            if(calculatePosVeloBool) {
                for(Solid* solid : solids) {
                    solid->calculateNextPosVelo(timestep);
                }
                calculatePosVeloBool = false;
                finished = true;
            }

            if(updateValuesBool) {
                for(Solid* solid : solids) {
                    solid->updateValues(timestep);
                }
                updateValuesBool = false;
                finished = true;
            }

            if(calcForcesJointBool) {
                for(Joint* joint : joints) {
                    joint->calculateReactionForce(timestep);
                }
                calcForcesJointBool = false;
                finished = true;
            }

            QThread::yieldCurrentThread();
        }
    }
};

class SimController : public QThread
{
    Q_OBJECT
    Q_PROPERTY(bool simulating READ isSimulating NOTIFY simulatingChanged)
    Q_PROPERTY(bool playback READ isPlayback NOTIFY playbackChanged)

public:
    Q_INVOKABLE void setPlay(bool b);
    Q_INVOKABLE void setReset(bool b);
    Q_INVOKABLE void setStop(bool b);
    Q_INVOKABLE void setPlayback(bool b);
    Q_INVOKABLE QList<QString> getParameterListByGroup(QString group);
    Q_INVOKABLE QList<QString> getValueListByGroup(QString group);
    Q_INVOKABLE QList<QString> getParameterGroups();
    Q_INVOKABLE QList<QString> getValueGroups();
    void run() override;

    bool isSimulating();
    bool isPlayback();

    WheelFL *wheelFL;
    WheelFR *wheelFR;
    WheelRL *wheelRL;
    WheelRR *wheelRR;
    Mainbody *carBody;

    SusJointFL *susJointFL;
    SusJointFR *susJointFR;
    SusJointRL *susJointRL;
    SusJointRR *susJointRR;

    MotorJointFL *motorJointFL;
    MotorJointFR *motorJointFR;
    MotorJointRL *motorJointRL;
    MotorJointRR *motorJointRR;

    AeroJoint *aeroJoint;

    SimController();

private:
    bool play = false;
    bool reset = false;
    bool stop = false;
    bool playback = false;
    bool simulating = false;
    QMutex mutexBools;
    QList<Solid*> solids;
    QList<Joint*> joints;
    QList<Solid*> solidsByMainthread;
    QList<Joint*> jointsByMainthread;

    bool isPlay();
    bool isReset();
    bool isStop();
    void setSimulating(bool b);

    Parameter &displayTime;
    Parameter &totalSimulationTime;
    Parameter &playbackSpeed;
    Parameter* timestep;
    Value &calculationTimePerStep;
    QElapsedTimer playbackTimer;
    QElapsedTimer simtimeTimer;
    QElapsedTimer totalCalculationTimer;

    SimulationTask* t1;
    SimulationTask* t2;
    SimulationTask* t3;
    SimulationTask* t4;

    void writeCSV();

signals:
    void simulatingChanged();
    void playbackChanged();

public slots:
};

#endif // SIMCONTROLLER_H
