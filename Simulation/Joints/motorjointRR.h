#ifndef MOTORJOINTRR_H
#define MOTORJOINTRR_H

#include <Simulation/Joints/motorjointbase.h>

class MotorJointRR : public MotorJointBase
{
public:
    explicit MotorJointRR( WheelBase &i_wheel );
};

#endif // MOTORJOINTRR_H
