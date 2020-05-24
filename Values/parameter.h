#ifndef VALUE_H
#define VALUE_H
#include <Values/valuebase.h>

class Parameter: public QObject, public ValueBase
{
        Q_OBJECT
        Q_PROPERTY(double value READ val NOTIFY valueChanged)
        Q_PROPERTY(QString unit READ getUnit NOTIFY unitChanged)

    public:
        static QList<Parameter*> parameterList;
        QString getUnit();
        double val();
        std::shared_ptr<const double> getValuePointer();
        Q_INVOKABLE QString getName();
        Q_INVOKABLE void setValue(const double newValue);
        Parameter(double initialValue, const QString i_name, const QString i_unit, const QString i_group);
        QString unit;

    private:
        double value;
        QElapsedTimer timer;
//        void notifyValue();

    signals:
        void valueChanged();
        void unitChanged();

    public slots:
};

#endif // VALUE_H
