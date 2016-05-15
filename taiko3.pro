#-------------------------------------------------
#
# Project created by QtCreator 2016-05-15T06:04:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += multimediawidgets

TARGET = taiko3
TEMPLATE = app


SOURCES += main.cpp \
    taiko.cpp \
    hitarea.cpp \
    drum1.cpp \
    drum2.cpp \
    dialog.cpp \
    mainwindow.cpp \
    dialog2.cpp

HEADERS  += \
    taiko.h \
    hitarea.h \
    drum1.h \
    drum2.h \
    dialog.h \
    mainwindow.h \
    dialog2.h

FORMS    += \
    mainwindow.ui \
    dialog.ui \
    dialog2.ui

RESOURCES += \
    res.qrc \
    bestmusic.qrc
