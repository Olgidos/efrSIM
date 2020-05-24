#include "motorjointFR.h"

MotorJointFR::MotorJointFR( WheelBase &i_wheel ):
    MotorJointBase(Data::instance().torqueMotorEnabledFR,
                   Data::instance().MotorFREnergyFlow,
                   i_wheel,
                   Data::instance().torqueMotorFR,
                   Data::instance().powerMotorFR,
                   Data::instance().torqueMotorMaxFR,
                   Data::instance().powerMotorMaxFR,
                   Data::instance().motorCFR_e)
{
}
