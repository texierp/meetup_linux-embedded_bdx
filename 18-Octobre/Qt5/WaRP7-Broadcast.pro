#-------------------------------------------------
#
# Project created by QtCreator 2015-10-30T21:03:34
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = WaRP7_Broadcast
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp\
    CWaRP7Broadcast.cpp

HEADERS += \
    CWaRP7Broadcast.h

target.path= /usr/bin
INSTALLS += target
