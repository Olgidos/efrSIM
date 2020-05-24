#ifndef SUSJOINTRR_H
#define SUSJOINTRR_H

#include <Simulation/Joints/susjointbase.h>

class SusJointRR : public SusJointBase
{
public:
    SusJointRR( WheelBase &i_wheel, Mainbody &i_carBody );
};


#endif // SUSJOINTRR_H
