#ifndef SOLID_H
#define SOLID_H

#include <qthread.h>
#include <Qt3DCore>

#include <Simulation/Base/Joint.h>
#include <Values/parameter.h>
#include <Values/value.h>
#include <Model/data.h>
#include <math.h>

class Solid
{
    public:

        virtual Solid* calculateAcceleration(double timestep) = 0;
        virtual Solid* setInitialState() = 0;
        virtual double calculateMass() = 0;
        virtual double calculateMOIx() = 0;
        virtual double calculateMOIy() = 0;
        virtual double calculateMOIz() = 0;


        void preCalculation(double timestep);
        Solid* calculateNextPosVelo(double timestep);
        Solid* updateValues(double timestep);

        double getTimestamp() const;
        QVector<double> getPosition() const;

        Solid(  Value &i_posX,
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
              );

    protected:
        Parameter &initTimestamp;
        double timestamp;
        Solid();
        ValueLock lock;


    public:
        Value &posX;
        Value &posY;
        Value &posZ;
        QVector<double> nextPos;

        Value &veloX;
        Value &veloY;
        Value &veloZ;
        QVector<double> nextVelo;

        Value &accelX;
        Value &accelY;
        Value &accelZ;
        QVector<double> nextAccel;

        Value &angularVeloX;
        Value &angularVeloY;
        Value &angularVeloZ;
        QVector<double> nextAngularVelo;

        Value &angularAccelX;
        Value &angularAccelY;
        Value &angularAccelZ;
        QVector<double> nextAngularAccel;

        Value &eulerX;
        Value &eulerY;
        Value &eulerZ;
        QVector<double> nextEuler;

        Value &mass;
        Value &MOIX;
        Value &MOIY;
        Value &MOIZ;
        Value &energy;
};

#endif // SOLID_H
