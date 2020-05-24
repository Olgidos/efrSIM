#ifndef MOTORJOINTFR_H
#define MOTORJOINTFR_H

#include <Simulation/Joints/motorjointbase.h>

class MotorJointFR : public MotorJointBase
{
public:
    explicit MotorJointFR( WheelBase &i_wheel );
};

#endif // MOTORJOINTFR_H
