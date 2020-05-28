#include "mainbody.h"
#define vals Data::instance()

Mainbody::Mainbody() :
         Solid(Data::instance().mainPosX,
               Data::instance().mainPosY,
               Data::instance().mainPosZ,
               Data::instance().mainVeloX,
               Data::instance().mainVeloY,
               Data::instance().mainVeloZ,
               Data::instance().mainAccelX,
               Data::instance().mainAccelY,
               Data::instance().mainAccelZ,
               Data::instance().mainAngularVeloX,
               Data::instance().mainAngularVeloY,
               Data::instance().mainAngularVeloZ,
               Data::instance().mainAngularAccelX,
               Data::instance().mainAngularAccelY,
               Data::instance().mainAngularAccelZ,
               Data::instance().mainEulerX,
               Data::instance().mainEulerY,
               Data::instance().mainEulerZ,
               Data::instance().main_mass,
               Data::instance().main_MOIX,
               Data::instance().main_MOIY,
               Data::instance().main_MOIZ,
               Data::instance().main_energy
               )
{
}

Solid* Mainbody::setInitialState(){
    timestamp = initTimestamp.val();
    posX.clearHistory                   (vals.mainInitPosX.val(),timestamp,&lock);
    posY.clearHistory                   (vals.mainInitPosY.val(),timestamp,&lock);
    posZ.clearHistory                   (vals.mainInitPosZ.val(),timestamp,&lock);
    nextPos.clear();
    nextPos.push_back(0.0);
    nextPos.push_back(0.0);
    nextPos.push_back(0.0);

    veloX.clearHistory                  (0.0,timestamp,&lock);
    veloY.clearHistory                  (0.0,timestamp,&lock);
    veloZ.clearHistory                  (0.0,timestamp,&lock);

    nextVelo.clear();
    nextVelo.push_back(0.0);
    nextVelo.push_back(0.0);
    nextVelo.push_back(0.0);

    accelX.clearHistory                 (0.0,timestamp,&lock);
    accelY.clearHistory                 (0.0,timestamp,&lock);
    accelZ.clearHistory                 (0.0,timestamp,&lock);

    nextAccel.clear();
    nextAccel.push_back(0.0);
    nextAccel.push_back(0.0);
    nextAccel.push_back(0.0);

    eulerX.clearHistory                 (0.0,timestamp,&lock);
    eulerY.clearHistory                 (0.0,timestamp,&lock);
    eulerZ.clearHistory                 (0.0,timestamp,&lock);

    nextEuler.clear();
    nextEuler.push_back(0.0);
    nextEuler.push_back(0.0);
    nextEuler.push_back(0.0);

    angularVeloX.clearHistory           (0.0,timestamp,&lock);
    angularVeloY.clearHistory           (0.0,timestamp,&lock);
    angularVeloZ.clearHistory           (0.0,timestamp,&lock);

    nextAngularVelo.clear();
    nextAngularVelo.push_back(0.0);
    nextAngularVelo.push_back(0.0);
    nextAngularVelo.push_back(0.0);

    angularAccelX.clearHistory          (0.0,timestamp,&lock);
    angularAccelY.clearHistory          (0.0,timestamp,&lock);
    angularAccelZ.clearHistory          (0.0,timestamp,&lock);

    nextAngularAccel.clear();
    nextAngularAccel.push_back(0.0);
    nextAngularAccel.push_back(0.0);
    nextAngularAccel.push_back(0.0);

    mass.clearHistory                   (calculateMass(), timestamp, &lock);
    MOIX.clearHistory                   (calculateMOIx(), timestamp, &lock);
    MOIY.clearHistory                   (calculateMOIy(), timestamp, &lock);
    MOIZ.clearHistory                   (calculateMOIz(), timestamp, &lock);
    energy.clearHistory                 (0.0,timestamp,&lock);
    return this;
}



double Mainbody::calculateMass() {
    massComb = vals.mainMass.val() + vals.driverMass.val() + 0.5*(
                vals.wheelSusFLMass.val() + vals.wheelSusFRMass.val() + vals.wheelSusRLMass.val() + vals.wheelSusRRMass.val());

    sx_mComb = vals.driverMass.val() / massComb * vals.sxDriver.val() + 0.5 / massComb*(
                vals.wheelSusFLMass.val() * vals.wheelSusFL_sx.val() +
                vals.wheelSusFRMass.val() * vals.wheelSusFR_sx.val() +
                vals.wheelSusRLMass.val() * vals.wheelSusRL_sx.val() +
                vals.wheelSusRRMass.val() * vals.wheelSusRR_sx.val());
    sy_mComb = vals.driverMass.val() / massComb * vals.syDriver.val() + 0.5 / massComb*(
                vals.wheelSusFLMass.val() * vals.wheelSusFL_sy.val() +
                vals.wheelSusFRMass.val() * vals.wheelSusFR_sy.val() +
                vals.wheelSusRLMass.val() * vals.wheelSusRL_sy.val() +
                vals.wheelSusRRMass.val() * vals.wheelSusRR_sy.val());
    sz_mComb = vals.driverMass.val() / massComb * vals.szDriver.val() + 0.5 / massComb*(
                vals.wheelSusFLMass.val() * vals.wheelSusFL_sz.val() +
                vals.wheelSusFRMass.val() * vals.wheelSusFR_sz.val() +
                vals.wheelSusRLMass.val() * vals.wheelSusRL_sz.val() +
                vals.wheelSusRRMass.val() * vals.wheelSusRR_sz.val());
    return massComb;
}

double Mainbody::calculateMOIx() {
    J_combX  = (vals.main_JX.val() + vals.driverMass.val() * pow(vals.sxDriver.val(),2) + 0.5 *(
                vals.wheelSusFLMass.val() * pow(vals.wheelSusFL_sx.val(),2) +
                vals.wheelSusFRMass.val() * pow(vals.wheelSusFR_sx.val(),2) +
                vals.wheelSusRLMass.val() * pow(vals.wheelSusRL_sx.val(),2) +
                vals.wheelSusRRMass.val() * pow(vals.wheelSusRR_sx.val(),2) ) ) * M_PI / 180.0;
    return J_combX;
}


double Mainbody::calculateMOIy() {
    J_combY  = (vals.main_JY.val() + vals.driverMass.val() * pow(vals.syDriver.val(),2) + 0.5 *(
                vals.wheelSusFLMass.val() * pow(vals.wheelSusFL_sy.val(),2) +
                vals.wheelSusFRMass.val() * pow(vals.wheelSusFR_sy.val(),2) +
                vals.wheelSusRLMass.val() * pow(vals.wheelSusRL_sy.val(),2) +
                vals.wheelSusRRMass.val() * pow(vals.wheelSusRR_sy.val(),2) ) ) * M_PI / 180.0;
    return J_combY;
}

double Mainbody::calculateMOIz() {
    J_combZ  = (vals.main_JZ.val() + vals.driverMass.val() * pow(vals.szDriver.val(),2) + 0.5 *(
                vals.wheelSusFLMass.val() * pow(vals.wheelSusFL_sz.val(),2) +
                vals.wheelSusFRMass.val() * pow(vals.wheelSusFR_sz.val(),2) +
                vals.wheelSusRLMass.val() * pow(vals.wheelSusRL_sz.val(),2) +
                vals.wheelSusRRMass.val() * pow(vals.wheelSusRR_sz.val(),2) ) ) * M_PI / 180.0;
    return J_combZ;
}


Solid* Mainbody::calculateAcceleration(double timestep) {

    nextAccel[0] = (vals.wheelSusFLForceX.val() + vals.wheelSusFRForceX.val()
                    + vals.wheelSusRLForceX.val() + vals.wheelSusRRForceX.val() - vals.aeroFx.val()) / massComb;
    nextAccel[1] = (vals.wheelSusFLForceY.val() + vals.wheelSusFRForceY.val()
                    + vals.wheelSusRLForceY.val() + vals.wheelSusRRForceY.val()) / massComb;
    nextAccel[2] = (vals.wheelSusFLForceZ.val() + vals.wheelSusFRForceZ.val()
                    + vals.wheelSusRLForceZ.val() + vals.wheelSusRRForceZ.val() - vals.aeroFz.val()) / massComb - vals.g.val();

    nextAngularAccel[0] = (vals.wheelSusFLTorqueX.val() + vals.wheelSusFRTorqueX.val() + vals.wheelSusRLTorqueX.val() + vals.wheelSusRRTorqueX.val()
                    + vals.wheelSusFLForceZ.val() * vals.wheelFL_sy.val()
                    + vals.wheelSusFRForceZ.val() * vals.wheelFR_sy.val()
                    + vals.wheelSusRLForceZ.val() * vals.wheelRL_sy.val()
                    + vals.wheelSusRRForceZ.val() * vals.wheelRR_sy.val()

                    - vals.wheelSusFLForceY.val() * vals.wheelFL_sz.val()
                    - vals.wheelSusFRForceY.val() * vals.wheelFR_sz.val()
                    - vals.wheelSusRLForceY.val() * vals.wheelRL_sz.val()
                    - vals.wheelSusRRForceY.val() * vals.wheelRR_sz.val())
                    / J_combX;

    nextAngularAccel[1] = (vals.wheelSusFLTorqueY.val() + vals.wheelSusFRTorqueY.val() + vals.wheelSusRLTorqueY.val() + vals.wheelSusRRTorqueY.val()
                           + vals.wheelSusFLForceX.val() * (-posZ.val() )
                           + vals.wheelSusFRForceX.val() * (-posZ.val() )
                           + vals.wheelSusRLForceX.val() * (-posZ.val() )
                           + vals.wheelSusRRForceX.val() * (-posZ.val() )

                           - vals.wheelSusFLForceZ.val() * vals.wheelFL_sx.val()
                           - vals.wheelSusFRForceZ.val() * vals.wheelFR_sx.val()
                           - vals.wheelSusRLForceZ.val() * vals.wheelRL_sx.val()
                           - vals.wheelSusRRForceZ.val() * vals.wheelRR_sx.val()

                           + vals.aeroFz.val() * vals.aero_sx.val()
                           + massComb * vals.g.val() * sx_mComb
                           )
                           / J_combX;

    nextAngularAccel[2] = 0;
    return this;
}
#undef vals
