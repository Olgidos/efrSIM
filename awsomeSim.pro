#-------------------------------------------------
#
# Project created by QtCreator 2019-10-20T15:34:31
#
#-------------------------------------------------

QT += core gui widgets charts qml quick concurrent\
    3dcore 3drender 3dinput \
    3dquick 3dquickrender 3dquickinput 3dquickextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = efrSIM
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11 console

SOURCES += \
        Simulation/Base/joint.cpp \
        Simulation/Base/solid.cpp \
        Simulation/Joints/aerojoint.cpp \
        Simulation/Joints/motorjointFL.cpp \
        Simulation/Joints/motorjointFR.cpp \
        Simulation/Joints/motorjointRL.cpp \
        Simulation/Joints/motorjointRR.cpp \
        Simulation/Joints/motorjointbase.cpp \
        Simulation/Joints/susjointFL.cpp \
        Simulation/Joints/susjointFR.cpp \
        Simulation/Joints/susjointRL.cpp \
        Simulation/Joints/susjointRR.cpp \
        Simulation/Joints/susjointbase.cpp \
        Simulation/simcontroller.cpp \
        Simulation/Solids/mainbody.cpp \
        Simulation/Solids/wheelFR.cpp \
        Simulation/Solids/wheelFl.cpp \
        Simulation/Solids/wheelRL.cpp \
        Simulation/Solids/wheelRR.cpp \
        Simulation/Solids/wheelbase.cpp \
        Values/parameter.cpp \
        Values/value.cpp \
        main.cpp

HEADERS += \
    Model/data.h \
    Simulation/Base/joint.h \
    Simulation/Base/solid.h \
    Simulation/Joints/aerojoint.h \
    Simulation/Joints/motorjointFL.h \
    Simulation/Joints/motorjointFL.h \
    Simulation/Joints/motorjointFR.h \
    Simulation/Joints/motorjointRL.h \
    Simulation/Joints/motorjointRR.h \
    Simulation/Joints/motorjointbase.h \
    Simulation/Joints/susjointFL.h \
    Simulation/Joints/susjointFR.h \
    Simulation/Joints/susjointRL.h \
    Simulation/Joints/susjointRR.h \
    Simulation/Joints/susjointbase.h \
    Simulation/simcontroller.h \
    Simulation/Solids/Moduls/MFTModul.h \
    Simulation/Solids/mainbody.h \
    Simulation/Solids/wheelFL.h \
    Simulation/Solids/wheelFR.h \
    Simulation/Solids/wheelRL.h \
    Simulation/Solids/wheelRR.h \
    Simulation/Solids/wheelbase.h \
    Values/parameter.h \
    Values/value.h \
    Values/valuebase.h \
    main.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    resource-graphic.qrc \
    resource-qml.qrc

RC_ICONS = icon.ico
