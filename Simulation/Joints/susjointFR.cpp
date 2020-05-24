#include "susjointFR.h"

SusJointFR::SusJointFR( WheelBase &i_wheel, Mainbody &i_carBody ):
                        SusJointBase(Data::instance().wheelSusFREnabled,
                                     Data::instance().wheelSusFREnergyFlow,
                                     i_wheel,
                                     i_carBody,
                                     Data::instance().wheelSusFRForceX,
                                     Data::instance().wheelSusFRForceY,
                                     Data::instance().wheelSusFRForceZ,
                                     Data::instance().wheelSusFRTorqueX,
                                     Data::instance().wheelSusFRTorqueY,
                                     Data::instance().wheelSusFRTorqueZ)
{
    s_wheelx = Data::instance().wheelFR_sx.val();
    s_wheely = Data::instance().wheelFR_sy.val();
    s_wheelz = Data::instance().wheelFR_sz.val();
}
