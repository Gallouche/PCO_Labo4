
QT       += core

QT       -= gui

TARGET = bubblesort
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    sorttester.cpp \
    moniteurmesa.cpp \
    sorthandler.cpp

HEADERS += \
    bubblesort.h \
    isort.h \
    bubblesortthreaded.h \
    sorttester.h \
    moniteurmesa.h \
    sorthandler.h
