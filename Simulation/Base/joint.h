#ifndef JOINT_H
#define JOINT_H
#include <Values/parameter.h>
#include <Model/data.h>
#include <Values/value.h>
#include <QMutex>

class Solid;

class Joint
{
    public:
        Joint( Parameter &i_enabled, Value &i_energyFlow);
        double getTimestamp() const;
        Joint* calculateReactionForce(double timestep);
        virtual void calculate(double timestep) = 0;
        //in case of not enabled, write default Values
        virtual void writeDefault(double timestep) = 0;
        virtual void setInitialState() = 0;
        virtual void calculateEnergy(double timestep) = 0;
        Value &energyFlow;

    private:
        Parameter &enabled;

    protected:
        ValueLock lock;
        Parameter &initTimestamp;
        double timestamp;
};

#endif // JOINT_H
