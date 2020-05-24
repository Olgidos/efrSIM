#ifndef VALUECHRONICLED_H
#define VALUECHRONICLED_H

#include <Values/valuebase.h>
#include <QtCharts/QXYSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QAbstractSeries>
#include <math.h>
#include <Values/parameter.h>

#define Default_X_MAX 1
#define Default_X_MIN 0.0
#define Default_Y_MAX 1
#define Default_Y_MIN 0.0
#define Default_Axis_MaxMin_Tolerance 0.01

QT_CHARTS_USE_NAMESPACE

class Value: public QObject, public ValueBase{

        Q_OBJECT
        Q_PROPERTY(double value READ getValueGUI NOTIFY valueChangedGUI)
        Q_PROPERTY(QString unit READ getUnit NOTIFY unitChanged)
        Q_PROPERTY(double timestamp READ getTimestampGUI NOTIFY valueChangedGUI)

    public:
        static QList<Value*> valueList;
        void newValue(double newValue, double timestamp, void* i_lock);
        double val();
        double getValueGUI();
        QString getUnit();
        double getLastValue();
        double getTimestamp();
        double getTimestampGUI();
        Q_INVOKABLE void updateChart(QAbstractSeries *series, QAbstractAxis *axisX, QAbstractAxis *axisY, bool zoom);
        Q_INVOKABLE QString getName();
        const QPointF getValueEntry();
        const QVector<QPointF> getHistory();
        void clearHistory(const double initialValue, double timestamp, void* i_lock);

        //Constructor
        Value(const QString i_name, const QString i_unit, const QString i_group, Parameter& i_displayTime);

    protected:
        //Variables
        //std::vector<ValueEntry> history;
        QVector<QPointF> history;
        QElapsedTimer timer;
        Parameter &displayTime;
        QString unit;

        long historyIter;
        double xMax = Default_X_MAX;
        double xMin = Default_X_MIN;
        double yMax = Default_Y_MAX;
        double yMin = Default_Y_MIN;
        void calcIter();
        void notifyGUI();

    signals:
        void valueChangedGUI();
        void unitChanged();

    public slots:
};



#endif // VALUECHRONICLED_H


