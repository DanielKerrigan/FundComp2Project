#-------------------------------------------------
#
# Project created by QtCreator 2016-04-09T11:18:24
#
#-------------------------------------------------

QT       += core gui
QT       += webkitwidgets
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = newBrowser
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    url_collections.cpp

HEADERS  += mainwindow.h \
    url_collections.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc
