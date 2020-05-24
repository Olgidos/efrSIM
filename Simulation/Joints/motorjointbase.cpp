#include "motorjointbase.h"
#define vals Data::instance()

MotorJointBase::MotorJointBase(
                Parameter &i_enabled,
                Value &i_energyFlow,
                WheelBase &i_wheel,
                Value &i_torqueMotor,
                Value &i_powerMotor,
                Parameter &i_torqueMotorMax,
                Parameter &i_powerMotorMax,
                Value &i_e):
            Joint(i_enabled, i_energyFlow),
            wheel(i_wheel),
            torqueMotor(i_torqueMotor),
            powerMotor(i_powerMotor),
            torqueMotorMax(i_torqueMotorMax),
            powerMotorMax(i_powerMotorMax),
            e(i_e)
{
    torqueMotor.setLock(&lock);
    powerMotor.setLock(&lock);
    e.setLock(&lock);
}

void MotorJointBase::calculateEnergy(double timestep){
    energyFlow.newValue(energyFlow.val() + powerMotor.val() * timestep / 1000, timestamp + timestep, &lock);
}

void MotorJointBase::calculate(double timestep){

    e.newValue(vals.MotorC_keff.val() - wheel.k.val() , timestamp + timestep, &lock);
    e_i += e.val();

    if(e_i > vals.motorC_eimax.val()) e_i = vals.motorC_eimax.val();
    if(e_i < vals.motorC_eimin.val()) e_i = vals.motorC_eimin.val();

    double torque = e.val() * vals.motorC_Kp.val()
                    + e_i * vals.motorC_Ki.val()
                    + (e.val() - e.getLastValue()) / (timestep) * vals.motorC_Kd.val();


    bool reachedLimit = false;

    if(torque > torqueMotorMax.val()){
        torque = torqueMotorMax.val();
        reachedLimit = true;
    }

    else if(torque < 0){
        torque = 0;
        reachedLimit = true;
    }

    double power = torque * wheel.angularVeloY.val() * M_PI / 180.0;

    if(power > powerMotorMax.val()) {
        power = powerMotorMax.val();
        torque = power / (wheel.angularVeloY.val() * M_PI / 180.0);
        reachedLimit = true;
    }

    if(reachedLimit) e_i -= e.val();

    if(Joint::timestamp + timestep >= 0){
        torqueMotor.newValue(torque, timestamp + timestep, &lock);
        //power = 100 * wheel.angularVeloY.val() * M_PI / 180.0;
        powerMotor.newValue(power, timestamp + timestep, &lock);
    }
    else {
        torqueMotor.newValue(0, timestamp + timestep, &lock);
        powerMotor.newValue(0, timestamp + timestep, &lock);
    }
}

void MotorJointBase::writeDefault(double timestep){
    torqueMotor.newValue(0.0, Joint::timestamp + timestep, &lock);
}

void MotorJointBase::setInitialState() {
    timestamp = initTimestamp.val();
    torqueMotor.clearHistory(0.0, timestamp, &lock);
    powerMotor.clearHistory(0.0, timestamp, &lock);
    energyFlow.clearHistory(0.0,timestamp,&lock);
    e.clearHistory(0.0, timestamp, &lock);

    e_i = 0;
}

#undef vals
