#ifndef WHEELBASE_H
#define WHEELBASE_H

#include <Simulation/Base/solid.h>
#include <math.h>

//List of Initial Parameters
class InitialWheelParametersSet {
    public:
        double posX = 0;
        double posY = 0;
        //double posZ = 0;

        double veloX = 0;
        double veloY = 0;
        double veloZ = 0;

        double accelX = 0;
        double accelY = 0;
        double accelZ = 0;

        double eulerX = 0;
        double eulerY = 0;
        double eulerZ = 0;

        double angularVeloX = 0;
        double angularVeloY = 0;
        double angularVeloZ = 0;

        double angularAccelX = 0;
        double angularAccelY = 0;
        double angularAccelZ = 0;
};


class WheelBase : public Solid
{
public:
    explicit WheelBase(Parameter &i_sx,
                       Parameter &i_sy,
                       Parameter &i_sz,

                       Parameter &i_MassRim,
                       Parameter &i_MassTyre,
                       Parameter &i_MassMotorAssembly,

                       Parameter &i_MassSus,
                       Parameter &i_sxSus,
                       Parameter &i_sySus,
                       Parameter &i_szSus,

                       Parameter &i_JTyreX,
                       Parameter &i_JTyreY,
                       Parameter &i_JTyreZ,
                       Parameter &i_JRimX,
                       Parameter &i_JRimY,
                       Parameter &i_JRimZ,
                       Parameter &i_JRotorTransmissionX,
                       Parameter &i_JRotorTransmissionY,
                       Parameter &i_JRotorTransmissionZ,

                       Parameter &i_dMotorAssemblyX,
                       Parameter &i_dMotorAssemblyY,
                       Parameter &i_dMotorAssemblyZ,

                       Value &i_posX,
                       Value &i_posY,
                       Value &i_posZ,

                       Value &i_veloX,
                       Value &i_veloY,
                       Value &i_veloZ,

                       Value &i_accelX,
                       Value &i_accelY,
                       Value &i_accelZ,

                       Value &i_angularVeloX,
                       Value &i_angularVeloY,
                       Value &i_angularVeloZ,

                       Value &i_angularAccelX,
                       Value &i_angularAccelY,
                       Value &i_angularAccelZ,

                       Value &i_eulerX,
                       Value &i_eulerY,
                       Value &i_eulerZ,

                       Value &i_mass,
                       Value &i_MOIX,
                       Value &i_MOIY,
                       Value &i_MOIZ,
                       Value &i_energy,

                       Value &i_Fz,
                       Value &i_Fx,
                       Value &i_k,
                       Value &i_ux,
                       Value &i_MrollingResistanceY,
                       Value &i_MoverturningCoupleX,

                       Value &i_SusForceX,
                       Value &i_SusForceY,
                       Value &i_SusForceZ,
                       Value &i_SusTorqueX,
                       Value &i_SusTorqueY,
                       Value &i_SusTorqueZ,
                       Value &i_MotorTorque);

    Solid* calculateAcceleration(double timestep) override;
    Solid* setInitialState() override;
    bool accelFinished();
    double calculateMass() override;
    double calculateMOIx() override;
    double calculateMOIy() override;
    double calculateMOIz() override;

    InitialWheelParametersSet initParaSet;

    Parameter &sx;
    Parameter &sy;
    Parameter &sz;

    Parameter &massRim;
    Parameter &massTyre;
    Parameter &massMotorAssembly;
    double massComb = 0;
    double J_combX = 0;
    double J_rotY = 0;
    double J_combZ = 0;

    Parameter &MassSus;
    Parameter &sxSus;
    Parameter &sySus;
    Parameter &szSus;

    Parameter &JTyreX;
    Parameter &JTyreY;
    Parameter &JTyreZ;
    Parameter &JRimX;
    Parameter &JRimY;
    Parameter &JRimZ;
    Parameter &JRotorTransmissionX;
    Parameter &JRotorTransmissionY;
    Parameter &JRotorTransmissionZ;
    Parameter &dMotorAssemblyX;
    Parameter &dMotorAssemblyY;
    Parameter &dMotorAssemblyZ;

    Value &Fz;
    Value &Fx;
    Value &k;
    Value &ux;
    Value &MrollingResistanceY;
    Value &MoverturningCoupleX;

    //Joint Forces just read
    Value &SusForceX;
    Value &SusForceY;
    Value &SusForceZ;
    Value &SusTorqueX;
    Value &SusTorqueY;
    Value &SusTorqueZ;

    Value &MotorTorque;

    void setInitialWheelParametersSet(InitialWheelParametersSet i_initParaSet);


protected:
};

#endif // WHEELBASE_H
