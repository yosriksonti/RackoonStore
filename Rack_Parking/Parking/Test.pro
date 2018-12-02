#-------------------------------------------------
#
# Project created by QtCreator 2018-10-24T16:08:53
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       +=texttospeech
QT       += multimedia

RESOURCES +=



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test
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
        main.cpp \
        mainwindow.cpp \
    vehicule.cpp \
    connexion.cpp \
    add.cpp \
    deleteinterface.cpp \
    place.cpp \
    enable.cpp \
    disable.cpp \
    database.cpp \
    initiate.cpp \
    user.cpp \
    system.cpp \
    date.cpp

HEADERS += \
        mainwindow.h \
    vehicule.h \
    connexion.h \
    add.h \
    deleteinterface.h \
    place.h \
    enable.h \
    disable.h \
    database.h \
    initiate.h \
    user.h \
    system.h \
    date.h

FORMS += \
        mainwindow.ui \
    add.ui \
    deleteinterface.ui \
    enable.ui \
    disable.ui \
    database.ui \
    initiate.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES +=
