#ifndef MOTORJOINTFL_H
#define MOTORJOINTFL_H

#include <Simulation/Joints/motorjointbase.h>

class MotorJointFL : public MotorJointBase
{
public:
    explicit MotorJointFL( WheelBase &i_wheel );
};

#endif // MOTORJOINTFL_H
