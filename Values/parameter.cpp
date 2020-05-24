#include <Values/parameter.h>

double Parameter::val(){
    mutexVal.lock();
        double d = value;
    mutexVal.unlock();
    return d;
}

std::shared_ptr<const double> Parameter::getValuePointer() {
    mutexVal.lock();
        std::shared_ptr<const double> ptr = std::make_shared<double>(value);
    mutexVal.unlock();
    return ptr;
}

QString Parameter::getName(){
    return ValueBase::name;
}

QString Parameter::getUnit(){
    return unit;
}

void Parameter::setValue(const double newValue) {
//    if(ValueBase::checkLock(i_lock)){
        mutexVal.lock();
            value = newValue;
        mutexVal.unlock();
        Parameter::notify();
        //qDebug() << name << ": value changed " << newValue;
        valueChanged();
        //notifyValue();
        return;
//    }
//    qCritical() << "VALUE:  lock was not accepted" ;
}

Parameter::Parameter(double initialValue, const QString i_name, const QString i_unit, const QString i_group) : ValueBase(i_name, i_group), value(initialValue), unit(i_unit){
    addProperty(name,this);
    Parameter::parameterList.push_back(this);
    qDebug() << "VALUE: " << i_name << " value inited " << initialValue;
    //timer.start();
}

QList<Parameter*> Parameter::parameterList{};

//void Parameter::notifyValue(){
//   if(timer.elapsed() > 1000){
//        valueChanged();
//        timer.start();
//   }
//}
