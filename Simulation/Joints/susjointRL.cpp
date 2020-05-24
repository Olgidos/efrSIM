#include "susjointRL.h"

SusJointRL::SusJointRL( WheelBase &i_wheel, Mainbody &i_carBody ):
                        SusJointBase(Data::instance().wheelSusRLEnabled,
                                     Data::instance().wheelSusRLEnergyFlow,
                                     i_wheel,
                                     i_carBody,
                                     Data::instance().wheelSusRLForceX,
                                     Data::instance().wheelSusRLForceY,
                                     Data::instance().wheelSusRLForceZ,
                                     Data::instance().wheelSusRLTorqueX,
                                     Data::instance().wheelSusRLTorqueY,
                                     Data::instance().wheelSusRLTorqueZ)
{
    s_wheelx = Data::instance().wheelRL_sx.val();
    s_wheely = Data::instance().wheelRL_sy.val();
    s_wheelz = Data::instance().wheelRL_sz.val();
}
