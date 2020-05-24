#include "susjointFL.h"

SusJointFL::SusJointFL( WheelBase &i_wheel , Mainbody &i_carBody ):
                        SusJointBase(Data::instance().wheelSusFLEnabled,
                                     Data::instance().wheelSusFLEnergyFlow,
                                     i_wheel,
                                     i_carBody,
                                     Data::instance().wheelSusFLForceX,
                                     Data::instance().wheelSusFLForceY,
                                     Data::instance().wheelSusFLForceZ,
                                     Data::instance().wheelSusFLTorqueX,
                                     Data::instance().wheelSusFLTorqueY,
                                     Data::instance().wheelSusFLTorqueZ)
{
    s_wheelx = Data::instance().wheelFL_sx.val();
    s_wheely = Data::instance().wheelFL_sy.val();
    s_wheelz = Data::instance().wheelFL_sz.val();
    Data::instance().wheelFLDisplacementWheelToBody.setLock(&lock);
}


void SusJointFL::postCalculate(double timestep){
    Data::instance().wheelFLDisplacementWheelToBody.newValue((SusJointBase::wheel.posX.val()
                                                               - SusJointBase::carBody.posX.val() -
                                                                s_wheelx) * 1000
                                                               , timestamp + timestep, &lock);
}
