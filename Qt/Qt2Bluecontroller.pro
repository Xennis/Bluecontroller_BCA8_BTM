#-------------------------------------------------
#
# Project created by QtCreator 2013-03-22T14:22:04
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Qt2Bluecontroller
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

# For RS232 usage
include(PortControl/PortControl.pri)
include(qextserialport/src/qextserialport.pri)
