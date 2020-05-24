#ifndef VALUEBASE_H
#define VALUEBASE_H

#include <QObject>
#include <QDebug>
#include <QElapsedTimer>
#include <vector>
#include <QMutex>
#include <memory>

extern void addProperty(const QString, QObject *obj);

//Lock-Class
class ValueLock{};

//ValueListener-Class
class ValueListener{
    public:
        std::function<void(void)> func;
        ValueListener(std::function<void(void)> i_func ) : func(i_func){}
        void update()  { func(); }
};


class ValueBase
{
    public:
        void setLock(void* i_lock) {
            if (!lock) {
                mutexVal.lock();
                lock = i_lock;
                mutexVal.unlock();
            }
        }

        void registerCallback(std::function<void(void)> func) {
            mutexVal.lock();
            listeners.push_back(std::make_shared<ValueListener>(func));
            mutexVal.unlock();
        }

        bool checkLock(void* i_lock) {
            if (lock == i_lock) {
                return true;
            }
            qCritical() << "VALUE: " << name << "  lock was not accepted" ;
            return false;
        }

        const QString name;
        const QString group;

    protected:
        //Variables
        std::vector <std::shared_ptr<ValueListener>> listeners;
        QMutex mutexVal{QMutex::Recursive};

        void* lock;

        //Functions
        void notify(){
            for (std::shared_ptr<ValueListener> listener : listeners) {
                listener->update();
            }
        }

        ValueBase(const QString i_name, const QString i_group) : name(i_name), group(i_group) , lock(nullptr){
        }
};


#endif // VALUEBASE_H
