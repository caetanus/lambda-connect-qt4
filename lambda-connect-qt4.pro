#-------------------------------------------------
#
# Project created by QtCreator 2013-12-10T15:31:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++0x

TARGET = cpp11qt
TEMPLATE = app

INCLUDE_DIR += lambda-connect


SOURCES += main.cpp\
        lambda-connect/lambdaconnect.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h\
            lambda-connect/lambdaconnect.h

FORMS    += mainwindow.ui
