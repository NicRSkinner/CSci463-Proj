#-------------------------------------------------
#
# Project created by QtCreator 2019-04-01T16:50:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project
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

CONFIG += c++11

SOURCES += \
    loginwindow.cpp \
    buildingview.cpp \
    graphicsviewzoom.cpp \
        main.cpp \
        mainwindow.cpp \
    room.cpp \
    door.cpp \
    zone.cpp \
    employee.cpp \
    supervisor.cpp \
    testbench.cpp \
    adminoptions.cpp

HEADERS += \
    loginwindow.h \
    buildingview.h \
    graphicsviewzoom.h \
        mainwindow.h \
    room.h \
    door.h \
    zone.h \
    employee.h \
    supervisor.h \
    testbench.h \
    adminoptions.h

FORMS += \
    loginwindow.ui \
        mainwindow.ui \
    testbench.ui \
    adminoptions.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
