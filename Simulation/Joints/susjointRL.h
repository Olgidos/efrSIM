#ifndef SUSJOINTRL_H
#define SUSJOINTRL_H

#include <Simulation/Joints/susjointbase.h>

class SusJointRL : public SusJointBase
{
public:
    SusJointRL( WheelBase &i_wheel, Mainbody &i_carBody );
};

#endif // SUSJOINTRL_H
