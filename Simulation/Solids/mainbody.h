#ifndef CARBODY_H
#define CARBODY_H

#include <Simulation/Base/Solid.h>
#include <math.h>

class Mainbody : public Solid
{

public:
    explicit Mainbody();
    Solid* calculateAcceleration(double timestep) override;
    Solid* setInitialState() override;
    double calculateMass() override;
    double calculateMOIx() override;
    double calculateMOIy() override;
    double calculateMOIz() override;

    double massComb = 0;
    double sx_mComb = 0;
    double sy_mComb = 0;
    double sz_mComb = 0;
    double J_combX = 0;
    double J_combY = 0;
    double J_combZ = 0;

protected:

};

#endif // CARBODY_H
