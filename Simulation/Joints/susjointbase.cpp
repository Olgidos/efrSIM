#include "susjointbase.h"

SusJointBase::SusJointBase(Parameter &i_enabled,
                           Value &i_energyFlow,
                           WheelBase &i_wheel,
                           Mainbody &i_carBody,
                           Value &i_forceX,
                           Value &i_forceY,
                           Value &i_forceZ,
                           Value &i_torqueX,
                           Value &i_torqueY,
                           Value &i_torqueZ):
                    Joint(i_enabled, i_energyFlow),
                    wheel(i_wheel),
                    carBody(i_carBody),
                    forceX(i_forceX),
                    forceY(i_forceY),
                    forceZ(i_forceZ),
                    torqueX(i_torqueX),
                    torqueY(i_torqueY),
                    torqueZ(i_torqueZ)
{
    forceX.setLock(&lock);
    forceY.setLock(&lock);
    forceZ.setLock(&lock);
    torqueX.setLock(&lock);
    torqueY.setLock(&lock);
    torqueZ.setLock(&lock);
}


double SusJointBase::offsetZ = 0.0;

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

void SusJointBase::calculateEnergy(double timestep){
    energyFlow.newValue(energyFlow.val() - wheel.MrollingResistanceY.val() * wheel.angularVeloY.val() * M_PI / 180.0 * timestep / 1000, timestamp + timestep, &lock);
}

//+ (wheel.veloX.getValue() - carBody.veloX.getValue())* 100
void SusJointBase::calculate(double timestep){

    if(Joint::timestamp < 0){
        offsetZ += 0.0001 * pow((carBody.posZ.val() - Data::instance().mainInitPosZ.val())*1,1);
    }

    double val = (wheel.posX.val() - carBody.posX.val() - s_wheelx
                  - sgn(s_wheelx)*(sqrt(pow(s_wheelz,2) + pow(s_wheelx,2))
                  * cos( Data::instance().mainEulerY.val() * M_PI / 180.0 - asin(s_wheelz/sqrt(pow(s_wheelz,2) + pow(s_wheelx,2)))) - sgn(s_wheelx)*s_wheelx)
//                  - sgn(s_wheelx)*(sqrt(pow(s_wheely,2) + pow(s_wheelx,2))
//                  * sin( Values::instance().mainEulerZ.getValue() * M_PI / 180.0 + asin(s_wheely/sqrt(pow(s_wheely,2) + pow(s_wheelx,2)))) + s_wheelx)
                  )
            * SolidSpringParameter
            + (wheel.veloX.val() - carBody.veloX.val()) * 2 * sqrt(SolidSpringParameter * wheel.massComb);
    forceX.newValue(val, Joint::timestamp + timestep, &lock);

    val = (wheel.posY.val() - carBody.posY.val() + s_wheely
//           *(1-cos( Values::instance().mainEulerY.getValue() * M_PI / 180.0 )
//             -cos( Values::instance().mainEulerZ.getValue() * M_PI / 180.0 ))
           )
            * SolidSpringParameter
            + (wheel.veloY.val() - carBody.veloY.val()) * 2 * sqrt(SolidSpringParameter * wheel.massComb);
    forceY.newValue(val, Joint::timestamp + timestep, &lock);

    val = (wheel.posZ.val() - carBody.posZ.val() - (s_wheelz + offsetZ)
                 + sgn(s_wheelx)*(sqrt(pow(s_wheelz,2) + pow(s_wheelx,2))
                 * sin( Data::instance().mainEulerY.val() * M_PI / 180.0 - sgn(s_wheelz)*asin(s_wheelz/sqrt(pow(s_wheelz,2) + pow(s_wheelx,2)))) + s_wheelz)
                 - sgn(s_wheely)*(sqrt(pow(s_wheelz,2) + pow(s_wheely,2))
                 * sin( Data::instance().mainEulerX.val() * M_PI / 180.0 + sgn(s_wheelz)*asin(s_wheelz/sqrt(pow(s_wheelz,2) + pow(s_wheely,2)))) - s_wheelz)
             )
            * Data::instance().wheelSusRealc.val()
            + (wheel.veloZ.val() - carBody.veloZ.val()) * Data::instance().wheelSusReald.val();
    forceZ.newValue(val, Joint::timestamp + timestep, &lock);

    torqueX.newValue(0.0, Joint::timestamp + timestep, &lock);
//    torqueY.newValue(-wheel.MotorTorque.val(), Joint::timestamp + timestep, &lock);
    torqueY.newValue(0.0, Joint::timestamp + timestep, &lock);
    torqueZ.newValue(0.0, Joint::timestamp + timestep, &lock);
    postCalculate(timestep);
}

void SusJointBase::writeDefault(double timestep){
    timestamp = initTimestamp.val();
    forceX.newValue(0.0, Joint::timestamp + timestep, &lock);
    forceY.newValue(0.0, Joint::timestamp + timestep, &lock);
    forceZ.newValue(0.0, Joint::timestamp + timestep, &lock);
    torqueX.newValue(0.0, Joint::timestamp + timestep, &lock);
    torqueY.newValue(0.0, Joint::timestamp + timestep, &lock);
    torqueZ.newValue(0.0, Joint::timestamp + timestep, &lock);
}

void SusJointBase::setInitialState() {
    timestamp = initTimestamp.val();
    forceX.clearHistory(initParaSet.forceX, timestamp, &lock);
    forceY.clearHistory(initParaSet.forceY, timestamp, &lock);
    forceZ.clearHistory(initParaSet.forceZ, timestamp, &lock);

    torqueX.clearHistory(initParaSet.forceX, timestamp, &lock);
    torqueY.clearHistory(initParaSet.forceY, timestamp, &lock);
    torqueZ.clearHistory(initParaSet.forceZ, timestamp, &lock);
    offsetZ = 0;
    energyFlow.clearHistory(0.0,timestamp,&lock);
}

void SusJointBase::postCalculate(double timestep){

}

