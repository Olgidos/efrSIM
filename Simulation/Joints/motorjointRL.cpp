#include "motorjointRL.h"

MotorJointRL::MotorJointRL( WheelBase &i_wheel ):
    MotorJointBase(Data::instance().torqueMotorEnabledRL,
                   Data::instance().MotorRLEnergyFlow,
                   i_wheel,
                   Data::instance().torqueMotorRL,
                   Data::instance().powerMotorRL,
                   Data::instance().torqueMotorMaxRL,
                   Data::instance().powerMotorMaxRL,
                   Data::instance().motorCRL_e)
{
}
