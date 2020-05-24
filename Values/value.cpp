#include <Values/value.h>
#include <Model/data.h>

void Value::newValue(double newValue, double timestamp, void* i_lock) {
    if(ValueBase::checkLock(i_lock)){
        mutexVal.lock();
            history.push_back(QPointF(timestamp, newValue));
            if(timestamp > xMax) xMax = timestamp;
            if(timestamp < xMin) xMin = timestamp;
            if(newValue > yMax && timestamp >= 0) yMax = newValue;
            if(newValue < yMin && timestamp >= 0) yMin = newValue;
        mutexVal.unlock();
        ValueBase::notify();
        //qDebug() << name << ": value changed " << newValue;
        notifyGUI();
        return;
    }
}

QString Value::getName(){
    return ValueBase::name;
}

QString Value::getUnit(){
    return unit;
}

double Value::val() {
    mutexVal.lock();
    double val;
        if(history.isEmpty()){
            val = -1;
        }else {
             val = history.back().y();
        }
    mutexVal.unlock();
    return val;
}

double Value::getValueGUI(){
    mutexVal.lock();
    calcIter();
    double val;
        if(history.isEmpty() || historyIter >= history.size()){
            val = -1;
        }else {
             val = history[historyIter].y();
        }
    mutexVal.unlock();
    return val;
}

double Value::getLastValue(){
    mutexVal.lock();
    double val;
        if(history.isEmpty()){
            val = -1;
        }else {
             val = history.at(history.size() - 2).y();
        }
    mutexVal.unlock();
    return val;
}

double Value::getTimestamp() {
    mutexVal.lock();
        double time;
        if(history.isEmpty()){
            time = -1;
        }else {
             time = history.back().x();
        }
    mutexVal.unlock();
    return time;
}

double Value::getTimestampGUI(){
    mutexVal.lock();
    calcIter();
        double time;
        if(history.isEmpty() || historyIter >= history.size()){
            time = -1;
        }else {
             time = history[historyIter].x();
        }
    mutexVal.unlock();
    return time;
}

const QPointF Value::getValueEntry(){
    mutexVal.lock();
        QPointF point;
        if(history.isEmpty()){
            point = QPointF(-1,-1);
        }else {
             point = history.back();
        }
    mutexVal.unlock();
    return point;
}

const QVector<QPointF> Value::getHistory(){
    mutexVal.lock();
        QVector<QPointF> vec;
        if(history.isEmpty()){
            vec.push_back(QPointF(-1,-1));
        }else {
            vec = history;
        }
    mutexVal.unlock();
    return vec;
}


void Value::clearHistory(const double initialValue, double timestamp, void* i_lock) {
    if(ValueBase::checkLock(i_lock)){
        mutexVal.lock();
            history.clear();
            newValue(initialValue,timestamp,lock);
            xMax = Default_X_MAX;
            xMin = Default_X_MIN;
            yMax = Default_Y_MAX;
            yMin = Default_Y_MIN;
        mutexVal.unlock();
        return;
    }
}


Value::Value(const QString i_name, const QString i_unit, const QString i_group, Parameter& i_displayTime)
    : ValueBase(i_name, i_group), displayTime(i_displayTime), historyIter(0) {
    addProperty(name,this);
    Value::valueList.push_back(this);
    history.reserve(1);
    history.push_back(QPointF(-1, 0.0));
    unit = i_unit;
    qDebug() << "VALUEChronicled: " << i_name << " value inited ";
    timer.start();
    displayTime.registerCallback(std::bind(&Value::notifyGUI, this));
}

//static instance made of chonical list
QList<Value*> Value::valueList{};

void Value::calcIter(){
    if(historyIter >= history.size() || history[historyIter].x() > displayTime.val()) historyIter = 0;
        for(long i = historyIter; i < history.size(); i++ ){
            if(history[i].x() >= displayTime.val() ){ //- 0.016
                historyIter = i;
                return;
            }
        }

        for(long i = 0; i < historyIter; i++ ){
            if(history[i].x() >= displayTime.val() ){ //- 0.016
                historyIter = i;
                return;
            }
        }

    historyIter = 0;
    //qDebug() << "Time in History not found " << name << " " << displayTime.val() << " " << history.back().x();
}


void Value::updateChart(QAbstractSeries *series, QAbstractAxis *axisX, QAbstractAxis *axisY, bool zoom){
    if (series && axisX && axisY) {
        QXYSeries *xySeries = static_cast<QXYSeries *>(series);
        QValueAxis *valAxisX = static_cast<QValueAxis *>(axisX);
        QValueAxis *valAxisY = static_cast<QValueAxis *>(axisY);
        mutexVal.lock();
            if(history.isEmpty()) return;
            if(xySeries->count() != history.count()) xySeries->replace(history);
            if(Data::instance().chartZoom.val() == 0 || !zoom){
                if(fabs(valAxisX->max() - xMax) > Default_Axis_MaxMin_Tolerance) valAxisX->setMax(xMax);
                if(fabs(valAxisX->min() - xMin) > Default_Axis_MaxMin_Tolerance) valAxisX->setMin(xMin);
                if(fabs(valAxisY->max() - yMax) > Default_Axis_MaxMin_Tolerance) valAxisY->setMax(yMax);
                if(fabs(valAxisY->min() - yMin) > Default_Axis_MaxMin_Tolerance) valAxisY->setMin(yMin);
            }else if(zoom) {
                double range = xMax * (1 - Data::instance().chartZoom.val());
                double xMaxZoom = history.at(historyIter).x() + 0.5 * range;
                double xMinZoom = history.at(historyIter).x() - 0.5 * range;
                if(fabs(valAxisX->max() - xMaxZoom) > Default_Axis_MaxMin_Tolerance) valAxisX->setMax(xMaxZoom);
                if(fabs(valAxisX->min() - xMinZoom) > Default_Axis_MaxMin_Tolerance) valAxisX->setMin(xMinZoom);
                if(fabs(valAxisY->max() - yMax) > Default_Axis_MaxMin_Tolerance) valAxisY->setMax(yMax);
                if(fabs(valAxisY->min() - yMin) > Default_Axis_MaxMin_Tolerance) valAxisY->setMin(yMin);
            }
        mutexVal.unlock();
    }
}

void Value::notifyGUI(){
   if(timer.elapsed() > 16){
        valueChangedGUI();
        timer.start();
   }
}
