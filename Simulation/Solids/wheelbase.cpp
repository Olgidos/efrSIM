#include "wheelbase.h"
#include <Simulation/solids/Moduls/MFTModul.h>

WheelBase::WheelBase(   	 Parameter &i_sx,
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
                             Value &i_MotorTorque):

                        Solid( i_posX,
                               i_posY,
                               i_posZ,
                               i_veloX,
                               i_veloY,
                               i_veloZ,
                               i_accelX,
                               i_accelY,
                               i_accelZ,
                               i_angularVeloX,
                               i_angularVeloY,
                               i_angularVeloZ,
                               i_angularAccelX,
                               i_angularAccelY,
                               i_angularAccelZ,
                               i_eulerX,
                               i_eulerY,
                               i_eulerZ,
                               i_mass,
                               i_MOIX,
                               i_MOIY,
                               i_MOIZ,
                               i_energy),
                        sx(i_sx),
                        sy(i_sy),
                        sz(i_sz),
                        massRim(i_MassRim),
                        massTyre(i_MassTyre),
                        massMotorAssembly(i_MassMotorAssembly),
                        MassSus(i_MassSus),
                        sxSus(i_sxSus),
                        sySus(i_sySus),
                        szSus(i_szSus),
                        JTyreX(i_JTyreX),
                        JTyreY(i_JTyreY),
                        JTyreZ(i_JTyreZ),
                        JRimX(i_JRimX),
                        JRimY(i_JRimY),
                        JRimZ(i_JRimZ),
                        JRotorTransmissionX(i_JRotorTransmissionX),
                        JRotorTransmissionY(i_JRotorTransmissionY),
                        JRotorTransmissionZ(i_JRotorTransmissionZ),
                        dMotorAssemblyX(i_dMotorAssemblyX),
                        dMotorAssemblyY(i_dMotorAssemblyY),
                        dMotorAssemblyZ(i_dMotorAssemblyZ),
                        Fz(i_Fz),
                        Fx(i_Fx),
                        k(i_k),
                        ux(i_ux),
                        MrollingResistanceY(i_MrollingResistanceY),
                        MoverturningCoupleX(i_MoverturningCoupleX),
                        SusForceX(i_SusForceX),
                        SusForceY(i_SusForceY),
                        SusForceZ(i_SusForceZ),
                        SusTorqueX(i_SusTorqueX),
                        SusTorqueY(i_SusTorqueY),
                        SusTorqueZ(i_SusTorqueZ),
                        MotorTorque(i_MotorTorque)
{
    Fz.setLock(&lock);
    Fx.setLock(&lock);
    k.setLock(&lock);
    ux.setLock(&lock);
    MrollingResistanceY.setLock(&lock);
    MoverturningCoupleX.setLock(&lock);
    massComb  = massTyre.val() + massRim.val() + massMotorAssembly.val() + 0.5 * MassSus.val();
    J_combX = (JTyreX.val() + JRimX.val() + massMotorAssembly.val()*pow(dMotorAssemblyX.val(),2) + 0.5 * MassSus.val()* pow(sx.val() - sxSus.val(),2)) * 180.0 / M_PI;
    J_rotY  = (JTyreY.val() + JRimY.val() + JRotorTransmissionY.val()) * 180.0 / M_PI;
    J_combZ = (JTyreZ.val() + JRimZ.val() + massMotorAssembly.val()*pow(dMotorAssemblyZ.val(),2) + 0.5 * MassSus.val()* pow(sz.val() - szSus.val(),2)) * 180.0 / M_PI;
}


Solid* WheelBase::setInitialState(){
    timestamp = initTimestamp.val();
    posX.clearHistory                   (Data::instance().mainInitPosX.val() + sx.val(),timestamp,&lock);
    posY.clearHistory                   (Data::instance().mainInitPosY.val() + sy.val(),timestamp,&lock);
    posZ.clearHistory                   (Data::instance().R0.val() - 0.001,timestamp,&lock);

    nextPos.clear();
    nextPos.push_back(0.0);
    nextPos.push_back(0.0);
    nextPos.push_back(0.0);

    veloX.clearHistory                  (initParaSet.veloX,timestamp,&lock);
    veloY.clearHistory                  (initParaSet.veloY,timestamp,&lock);
    veloZ.clearHistory                  (initParaSet.veloZ,timestamp,&lock);

    nextVelo.clear();
    nextVelo.push_back(0.0);
    nextVelo.push_back(0.0);
    nextVelo.push_back(0.0);

    accelX.clearHistory                 (initParaSet.accelX,timestamp,&lock);
    accelY.clearHistory                 (initParaSet.accelY,timestamp,&lock);
    accelZ.clearHistory                 (initParaSet.accelZ,timestamp,&lock);

    nextAccel.clear();
    nextAccel.push_back(0.0);
    nextAccel.push_back(0.0);
    nextAccel.push_back(0.0);

    eulerX.clearHistory                 (initParaSet.eulerX,timestamp,&lock);
    eulerY.clearHistory                 (initParaSet.eulerY,timestamp,&lock);
    eulerZ.clearHistory                 (initParaSet.eulerZ + 90.0,timestamp,&lock);

    nextEuler.clear();
    nextEuler.push_back(0.0);
    nextEuler.push_back(0.0);
    nextEuler.push_back(0.0);

    angularVeloX.clearHistory           (initParaSet.angularVeloX,timestamp,&lock);
    angularVeloY.clearHistory           (initParaSet.angularVeloY,timestamp,&lock);
    angularVeloZ.clearHistory           (initParaSet.angularVeloZ,timestamp,&lock);

    nextAngularVelo.clear();
    nextAngularVelo.push_back(0.0);
    nextAngularVelo.push_back(0.0);
    nextAngularVelo.push_back(0.0);

    angularAccelX.clearHistory          (initParaSet.angularAccelX,timestamp,&lock);
    angularAccelY.clearHistory          (initParaSet.angularAccelY,timestamp,&lock);
    angularAccelZ.clearHistory          (initParaSet.angularAccelZ,timestamp,&lock);

    nextAngularAccel.clear();
    nextAngularAccel.push_back(0.0);
    nextAngularAccel.push_back(0.0);
    nextAngularAccel.push_back(0.0);

    Fz.clearHistory                     (0.0,timestamp,&lock);
    Fx.clearHistory                     (0.0,timestamp,&lock);
    k.clearHistory                      (0.0,timestamp,&lock);
    ux.clearHistory                     (0.0,timestamp,&lock);
    MrollingResistanceY.clearHistory    (0.0,timestamp,&lock);
    MoverturningCoupleX.clearHistory    (0.0,timestamp,&lock);

    mass.clearHistory                   (calculateMass(), timestamp, &lock);
    MOIX.clearHistory                   (calculateMOIx(), timestamp, &lock);
    MOIY.clearHistory                   (calculateMOIy(), timestamp, &lock);
    MOIZ.clearHistory                   (calculateMOIz(), timestamp, &lock);
    energy.clearHistory                 (0.0,timestamp,&lock);
    return this;
}

bool WheelBase::accelFinished() {
    return (posX.val() >= Data::instance().mainInitPosX.val() + sx.val() + 75.0);
}

void WheelBase::setInitialWheelParametersSet(InitialWheelParametersSet i_initParaSet){
    initParaSet = i_initParaSet;
}


double WheelBase::calculateMass() {
    massComb  = massTyre.val() + massRim.val() + massMotorAssembly.val() + 0.5 * MassSus.val();
    return massComb;
}

double WheelBase::calculateMOIx() {
    J_combX = (JTyreX.val() + JRimX.val() + massMotorAssembly.val()*pow(dMotorAssemblyX.val(),2) + 0.5 * MassSus.val()* pow(sx.val() - sxSus.val(),2)) * M_PI / 180.0;
    return J_combX;
}


double WheelBase::calculateMOIy() {
    J_rotY  = (JTyreY.val() + JRimY.val() + JRotorTransmissionY.val()) * M_PI / 180.0;
    return J_rotY;
}

double WheelBase::calculateMOIz() {
    J_combZ = (JTyreZ.val() + JRimZ.val() + massMotorAssembly.val()*pow(dMotorAssemblyZ.val(),2) + 0.5 * MassSus.val()* pow(sz.val() - szSus.val(),2)) * M_PI / 180.0;
    return J_combZ;
}




Solid* WheelBase::calculateAcceleration(double timestep) {

    //Calculate MFT
    Fz.newValue(Data::instance().c_tyre.val()*(Data::instance().R0.val() - Solid::posZ.val()) - Data::instance().d_tyre.val() * Solid::veloZ.val()
                ,Solid::timestamp + timestep, &lock);

    double kval = (Solid::angularVeloY.val() / 180.0 * Solid::posZ.val() * M_PI  - Solid::veloX.val()) / abs(Solid::veloX.val() + 0.0001);
    if(Solid::timestamp + timestep < 0) {
        k.newValue(0.0,Solid::timestamp + timestep, &lock);
    } else {
        if(kval < -1) kval = -1;
        if(kval > 1) kval = 1;
        k.newValue(kval,Solid::timestamp + timestep, &lock);
    }


    double i_Fx = 0.0;
    double i_ux = 0.0;
    if(k.val() > 0.2 ) {
        MFT_FX_PureLongSlip(Fz.val(),k.val() /100.0 ,Solid::eulerX.val(), &i_Fx, &i_ux);
    }
    else {
        MFT_FX_PureLongSlip(Fz.val(),k.val(),Solid::eulerX.val(), &i_Fx, &i_ux);
    }

    Fx.newValue( i_Fx, Solid::timestamp + timestep, &lock);
    ux.newValue( i_ux, Solid::timestamp + timestep, &lock);
    MrollingResistanceY.newValue(MFT_MY_RollingResistance(Fz.val(),Solid::veloX.val(),Fx.val()), Solid::timestamp + timestep, &lock);

    //Calculate Motion Equations
    //FY = 0 !!! problem overturningCouple needs Fy but also influences Fy
    MoverturningCoupleX.newValue(MFT_MX_OverturningCouple(Fz.val(),Solid::eulerX.val(),0), Solid::timestamp + timestep, &lock);
    double Fy = -1* MoverturningCoupleX.val();

    nextAccel[0] = (Fx.val() - SusForceX.val() - MrollingResistanceY.val() / Solid::posZ.val())/ massComb;
    nextAccel[1] = 0;
    nextAccel[2] = (Fz.val() - SusForceZ.val())/ massComb - Data::instance().g.val();

    nextAngularAccel[0] = (-Fy*Solid::posZ.val() - SusTorqueX.val()) / J_combX;
    //MotorTorque.getValue() - SusTorqueY.getValue() - Fx.getValue() * Solid::posZ.getValue()) / J_rotY;
    nextAngularAccel[1] = (MotorTorque.val() - Fx.val() * Solid::posZ.val()) / J_rotY;
    nextAngularAccel[2] = 0;
    return this;
}
