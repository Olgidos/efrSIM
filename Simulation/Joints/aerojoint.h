#ifndef AEROJOINT_H
#define AEROJOINT_H

#include <Simulation/Base/joint.h>
#include <Simulation/Solids/mainbody.h>

class AeroJoint : public Joint
{
public:
    explicit AeroJoint(Mainbody &i_carbody);
    void calculate(double timestep) override;
    void writeDefault(double timestep) override;
    void calculateEnergy(double timestep) override;
    void setInitialState() override;

private:
    Mainbody &carbody;
    Value &aeroFz;
    Value &aeroFx;

};

#endif // AEROJOINT_H
