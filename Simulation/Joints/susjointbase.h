#ifndef SUSJOINTBASE_H
#define SUSJOINTBASE_H

#include <Simulation/Base/joint.h>
#include <Simulation/Solids/wheelbase.h>
#include <Simulation/Solids/mainbody.h>

#define SolidSpringParameter 1000000

//List of Initial Parameters
class InitialSusParametersSet {
    public:
        double forceX = 0.0;
        double forceY = 0.0;
        double forceZ = 0.0;
        double torqueX = 0.0;
        double torqueY = 0.0;
        double torqueZ = 0.0;
};


class SusJointBase : public Joint
{
public:
    SusJointBase(Parameter &i_enabled,
                 Value &i_energyFlow,
                 WheelBase &i_wheel,
                 Mainbody &i_carBody,
                 Value &i_forceX,
                 Value &i_forceY,
                 Value &i_forceZ,
                 Value &i_torqueX,
                 Value &i_torqueY,
                 Value &i_torqueZ);
    void calculate(double timestep) override;
    virtual void postCalculate(double timestep);
    void writeDefault(double timestep) override;
    void setInitialState() override;
    void calculateEnergy(double timestep) override;

protected:
    InitialSusParametersSet initParaSet;

    WheelBase &wheel;
    Mainbody &carBody;
    Value &forceX;
    Value &forceY;
    Value &forceZ;
    Value &torqueX;
    Value &torqueY;
    Value &torqueZ;

    //@ all angles = 0°
    double s_wheelx = 0;
    double s_wheely = 0;
    double s_wheelz = 0;

    static double offsetZ;

    void setInitialSusParametersSet(InitialSusParametersSet i_initParaSet);
};

#endif // SUSJOINTBASE_H
