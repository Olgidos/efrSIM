#include "aerojoint.h"

AeroJoint::AeroJoint(Mainbody &i_carbody) :
               Joint(Data::instance().aeroEnabled, Data::instance().aeroEnergyFlow),
               carbody(i_carbody),
               aeroFz(Data::instance().aeroFz),
               aeroFx(Data::instance().aeroFx)

{
    aeroFx.setLock(&lock);
    aeroFz.setLock(&lock);
}

void AeroJoint::calculateEnergy(double timestep) {
    energyFlow.newValue(energyFlow.val() - aeroFx.val() * carbody.veloX.val() * timestep / 1000
                         - aeroFz.val() * carbody.veloZ.val() * timestep / 1000
                        , timestamp + timestep, &lock);
}

void AeroJoint::calculate(double timestep){
    double force = 0.5 * Data::instance().aero_roh.val() * Data::instance().aero_A.val()
                    *carbody.veloX.val() * carbody.veloX.val() * (Data::instance().aero_cd.val() + carbody.eulerY.val() * 0.06);

    aeroFx.newValue(force, timestep + timestamp, &lock);

    force = -0.5 * Data::instance().aero_roh.val() * Data::instance().aero_A.val()
                        *carbody.veloX.val() * carbody.veloX.val() * (Data::instance().aero_cl.val() + carbody.eulerY.val() * 0.06 );

    aeroFz.newValue(force, timestep + timestamp, &lock);
}

void AeroJoint::writeDefault(double timestep){
    aeroFx.newValue(0.0, Joint::timestamp + timestep, &lock);
    aeroFz.newValue(0.0, Joint::timestamp + timestep, &lock);
}

void AeroJoint::setInitialState() {
    timestamp = initTimestamp.val();
    aeroFx.clearHistory(0.0,timestamp,&lock);
    aeroFz.clearHistory(0.0,timestamp,&lock);
    energyFlow.clearHistory(0.0,timestamp,&lock);
}
