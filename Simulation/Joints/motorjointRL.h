#ifndef MOTORJOINTRL_H
#define MOTORJOINTRL_H

#include <Simulation/Joints/motorjointbase.h>

class MotorJointRL : public MotorJointBase
{
public:
    explicit MotorJointRL( WheelBase &i_wheel );
};

#endif // MOTORJOINTRL_H
