#include "motorjointRR.h"

MotorJointRR::MotorJointRR( WheelBase &i_wheel ):
                MotorJointBase(Data::instance().torqueMotorEnabledRR,
                               Data::instance().MotorRREnergyFlow,
                               i_wheel,
                               Data::instance().torqueMotorRR,
                               Data::instance().powerMotorRR,
                               Data::instance().torqueMotorMaxRR,
                               Data::instance().powerMotorMaxRR,
                               Data::instance().motorCRR_e)
{
}
