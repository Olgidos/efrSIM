#include "susjointRR.h"

SusJointRR::SusJointRR( WheelBase &i_wheel, Mainbody &i_carBody ):
                        SusJointBase(Data::instance().wheelSusRREnabled,
                                     Data::instance().wheelSusRREnergyFlow,
                                     i_wheel,
                                     i_carBody,
                                     Data::instance().wheelSusRRForceX,
                                     Data::instance().wheelSusRRForceY,
                                     Data::instance().wheelSusRRForceZ,
                                     Data::instance().wheelSusRRTorqueX,
                                     Data::instance().wheelSusRRTorqueY,
                                     Data::instance().wheelSusRRTorqueZ)
{
    s_wheelx = Data::instance().wheelRR_sx.val();
    s_wheely = Data::instance().wheelRR_sy.val();
    s_wheelz = Data::instance().wheelRR_sz.val();
}
