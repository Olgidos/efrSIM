#ifndef SUSJOINTFR_H
#define SUSJOINTFR_H


#include <Simulation/Joints/susjointbase.h>

class SusJointFR : public SusJointBase
{
public:
    SusJointFR( WheelBase &i_wheel, Mainbody &i_carBody );
};


#endif // SUSJOINTFR_H
