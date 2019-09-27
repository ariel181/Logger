QT += core
QT -= gui

CONFIG += c++11

TARGET = Logger
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    src/logrecorder.cpp \
    src/logger.cpp \
    src/logmessage.cpp \
    src/loggercreator.cpp \
    src/loghelper.cpp \
    src/loggermennager.cpp

HEADERS += \
    src/logrecorder.h \
    src/logger.h \
    src/logmessage.h \
    src/loggercreator.h \
    src/macro.h \
    src/loghelper.h \
    src/logconfig.h \
    src/loggermennager.h
