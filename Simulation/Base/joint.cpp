#include "joint.h"
#include <Simulation/Base/solid.h>

Joint::Joint( Parameter &i_enabled, Value &i_energyFlow ) :
          energyFlow(i_energyFlow),
          enabled(i_enabled),
          initTimestamp(Data::instance().initTimestep),
          timestamp(initTimestamp.val())
{
    energyFlow.setLock(&lock);
}

double Joint::getTimestamp() const{
    return timestamp;
}

Joint* Joint::calculateReactionForce(double timestep){
    if(enabled.val() == 0.0){
        //qDebug() << "Joint: is not enabled!";
        writeDefault(timestep);
        timestamp += timestep;
        return this;
    }

    calculate(timestep);
    calculateEnergy(timestep);
    timestamp += timestep;
    return this;
}
