#-------------------------------------------------
#
# Project created by QtCreator 2015-12-22T13:21:50
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QQSearchWidgets
TEMPLATE = app

#qcp
include("QCustomPlot/src/qcustomplot.pri")

SOURCES += main.cpp\
        mainwindow.cpp \
    baskets.cpp

HEADERS  += mainwindow.h \
    baskets.h

FORMS    += mainwindow.ui
CONFIG += c++11
