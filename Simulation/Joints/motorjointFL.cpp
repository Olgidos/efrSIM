#include "motorjointFL.h"

MotorJointFL::MotorJointFL( WheelBase &i_wheel ):
    MotorJointBase(Data::instance().torqueMotorEnabledFL,
                   Data::instance().MotorFLEnergyFlow,
                   i_wheel,
                   Data::instance().torqueMotorFL,
                   Data::instance().powerMotorFL,
                   Data::instance().torqueMotorMaxFL,
                   Data::instance().powerMotorMaxFL,
                   Data::instance().motorCFL_e)
{
}
