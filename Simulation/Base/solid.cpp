#include <Simulation/Base/solid.h>


Solid* Solid::updateValues(double timestep){
    posX.newValue(nextPos.at(0), timestamp + timestep, &lock);
    posY.newValue(nextPos.at(1), timestamp + timestep, &lock);
    posZ.newValue(nextPos.at(2), timestamp + timestep, &lock);

    veloX.newValue(nextVelo.at(0), timestamp + timestep, &lock);
    veloY.newValue(nextVelo.at(1), timestamp + timestep, &lock);
    veloZ.newValue(nextVelo.at(2), timestamp + timestep, &lock);

    accelX.newValue(nextAccel.at(0), timestamp, &lock);
    accelY.newValue(nextAccel.at(1), timestamp, &lock);
    accelZ.newValue(nextAccel.at(2), timestamp, &lock);

    angularVeloX.newValue(nextAngularVelo.at(0), timestamp + timestep, &lock);
    angularVeloY.newValue(nextAngularVelo.at(1), timestamp + timestep, &lock);
    angularVeloZ.newValue(nextAngularVelo.at(2), timestamp + timestep, &lock);

    angularAccelX.newValue(nextAngularAccel.at(0), timestamp, &lock);
    angularAccelY.newValue(nextAngularAccel.at(1), timestamp, &lock);
    angularAccelZ.newValue(nextAngularAccel.at(2), timestamp, &lock);

    eulerX.newValue(nextEuler.at(0),  timestamp + timestep, &lock);
    eulerY.newValue(nextEuler.at(1),  timestamp + timestep, &lock);
    eulerZ.newValue(nextEuler.at(2),  timestamp + timestep, &lock);


    double i_energy = 0;
    i_energy += 0.5 * pow(veloX.val(),2) * mass.val();
    i_energy += 0.5 * pow(veloY.val(),2) * mass.val();
    i_energy += 0.5 * pow(veloZ.val(),2) * mass.val();
    i_energy += 0.5 * pow(angularVeloX.val() / 180 * M_PI,2) * MOIX.val() * 180 / M_PI;
    i_energy += 0.5 * pow(angularVeloY.val() / 180 * M_PI,2) * MOIY.val() * 180 / M_PI;
    i_energy += 0.5 * pow(angularVeloZ.val() / 180 * M_PI,2) * MOIZ.val() * 180 / M_PI;
    i_energy = i_energy/1000.0;

    energy.newValue(i_energy, timestamp + timestep, &lock);

    timestamp += timestep;
    return this;
}

double Solid::getTimestamp() const {
    return timestamp;
}

void Solid::preCalculation(double timestep){
    mass.newValue(calculateMass(), timestamp + timestep, &lock);
    MOIX.newValue(calculateMOIx(), timestamp + timestep, &lock);
    MOIY.newValue(calculateMOIy(), timestamp + timestep, &lock);
    MOIZ.newValue(calculateMOIz(), timestamp + timestep, &lock);
}


Solid* Solid::calculateNextPosVelo(double timestep){

    //Calc Next Positions
    //firstStep (Taylor)
    if(posX.getHistory().length() == 1) {

        nextPos[0] = posX.val() + timestep*veloX.val() + 0.5*nextAccel[0]*timestep*timestep;
        nextPos[1] = posY.val() + timestep*veloY.val() + 0.5*nextAccel[1]*timestep*timestep;
        nextPos[2] = posZ.val() + timestep*veloZ.val() + 0.5*nextAccel[2]*timestep*timestep;

        nextEuler[0] = eulerX.val() + timestep*angularVeloX.val() + 0.5*nextAngularAccel[0]*timestep*timestep;
        nextEuler[1] = eulerY.val() + timestep*angularVeloY.val() + 0.5*nextAngularAccel[1]*timestep*timestep;
        nextEuler[2] = eulerZ.val() + timestep*angularVeloZ.val() + 0.5*nextAngularAccel[2]*timestep*timestep;
    }

    //All other steps (central difference for axial, taylor for radial)
    else {
        nextPos[0] = 2*posX.val() - posX.getLastValue()  + nextAccel[0]*timestep*timestep;
        nextPos[1] = 2*posY.val() - posY.getLastValue()  + nextAccel[1]*timestep*timestep;
        nextPos[2] = 2*posZ.val() - posZ.getLastValue()  + nextAccel[2]*timestep*timestep;

        nextEuler[0] = 2*eulerX.val() - eulerX.getLastValue()  + nextAngularAccel[0]*timestep*timestep;
        nextEuler[1] = 2*eulerY.val() - eulerY.getLastValue()  + nextAngularAccel[1]*timestep*timestep;
        nextEuler[2] = 2*eulerZ.val() - eulerZ.getLastValue()  + nextAngularAccel[2]*timestep*timestep;
    }

    //Calc next velocities (Forwarde difference)
    nextVelo[0] = (nextPos[0] - posX.val()) / timestep;
    nextVelo[1] = (nextPos[1] - posY.val()) / timestep;
    nextVelo[2] = (nextPos[2] - posZ.val()) / timestep;

    nextAngularVelo[0] = (nextEuler[0] - eulerX.val()) / timestep;
    nextAngularVelo[1] = (nextEuler[1] - eulerY.val()) / timestep;
    nextAngularVelo[2] = (nextEuler[2] - eulerZ.val()) / timestep;

    return this;
}

QVector<double> Solid::getPosition() const{
    return QVector<double>{posX.val(), posY.val(), posY.val()};
}

Solid::Solid(Value &i_posX,
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
             Value &i_energy
      ):
        initTimestamp(Data::instance().initTimestep),
        timestamp(initTimestamp.val()),
        posX(i_posX),
        posY(i_posY),
        posZ(i_posZ),
        veloX(i_veloX),
        veloY(i_veloY),
        veloZ(i_veloZ),
        accelX(i_accelX),
        accelY(i_accelY),
        accelZ(i_accelZ),
        angularVeloX(i_angularVeloX),
        angularVeloY(i_angularVeloY),
        angularVeloZ(i_angularVeloZ),
        angularAccelX(i_angularAccelX),
        angularAccelY(i_angularAccelY),
        angularAccelZ(i_angularAccelZ),
        eulerX(i_eulerX),
        eulerY(i_eulerY),
        eulerZ(i_eulerZ),
        mass(i_mass),
        MOIX(i_MOIX),
        MOIY(i_MOIY),
        MOIZ(i_MOIZ),
        energy(i_energy)
{
    nextPos.push_back(0.0);
    nextPos.push_back(0.0);
    nextPos.push_back(0.0);

    nextVelo.push_back(0.0);
    nextVelo.push_back(0.0);
    nextVelo.push_back(0.0);

    nextAccel.push_back(0.0);
    nextAccel.push_back(0.0);
    nextAccel.push_back(0.0);

    nextAngularVelo.push_back(0.0);
    nextAngularVelo.push_back(0.0);
    nextAngularVelo.push_back(0.0);

    nextAngularAccel.push_back(0.0);
    nextAngularAccel.push_back(0.0);
    nextAngularAccel.push_back(0.0);

    nextEuler.push_back(0.0);
    nextEuler.push_back(0.0);
    nextEuler.push_back(0.0);

    posX.setLock(&lock);
    posY.setLock(&lock);
    posZ.setLock(&lock);
    veloX.setLock(&lock);
    veloY.setLock(&lock);
    veloZ.setLock(&lock);
    accelX.setLock(&lock);
    accelY.setLock(&lock);
    accelZ.setLock(&lock);
    angularVeloX.setLock(&lock);
    angularVeloY.setLock(&lock);
    angularVeloZ.setLock(&lock);
    angularAccelX.setLock(&lock);
    angularAccelY.setLock(&lock);
    angularAccelZ.setLock(&lock);
    eulerX.setLock(&lock);
    eulerY.setLock(&lock);
    eulerZ.setLock(&lock);
    mass.setLock(&lock);
    MOIX.setLock(&lock);
    MOIY.setLock(&lock);
    MOIZ.setLock(&lock);
    energy.setLock(&lock);
}
