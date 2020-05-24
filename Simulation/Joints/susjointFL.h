#ifndef SUSJOINTFL_H
#define SUSJOINTFL_H

#include <Simulation/Joints/susjointbase.h>

class SusJointFL : public SusJointBase
{
public:
    SusJointFL(WheelBase &i_wheel, Mainbody &i_carBody);
    void postCalculate(double timestep) override;
};

#endif // SUSJOINTFL_H
