#ifndef MAIN_H
#define MAIN_H

#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include <QOpenGLContext>
#include <QDebug>
#include <QString>

#include <Model/data.h>
#include <Simulation/simcontroller.h>
#include <Simulation/Solids/Moduls/MFTModul.h>


void addProperty(const QString name, QObject *obj);

static QQmlApplicationEngine *engine_ptr = nullptr;

#endif // MAIN_H
