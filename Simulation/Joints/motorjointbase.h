#ifndef MOTORJOINTBASE_H
#define MOTORJOINTBASE_H

#include <Simulation/Base/joint.h>
#include <Simulation/Solids/wheelbase.h>

class MotorJointBase : public Joint
{
public:
    MotorJointBase(   Parameter &i_enabled,
                      Value &i_energyFlow,
                      WheelBase &i_wheel,
                      Value &i_torqueMotor,
                      Value &i_powerMotor,
                      Parameter &i_torqueMotorMax,
                      Parameter &i_powerMotorMax,
                      Value &i_e);
    void calculate(double timestep) override;
    void writeDefault(double timestep) override;
    void setInitialState() override;
    void calculateEnergy(double timestep) override;

protected:
    WheelBase &wheel;
    Value &torqueMotor;
    Value &powerMotor;

    Parameter &torqueMotorMax;
    Parameter &powerMotorMax;
    Value &e;

    double e_i = 0;
};

#endif // MOTORJOINTBASE_H
