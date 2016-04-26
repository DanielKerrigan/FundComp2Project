#-------------------------------------------------
#
# Project created by QtCreator 2016-03-11T22:06:14
#
#-------------------------------------------------

QT       += core gui
QT       += webkitwidgets
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Browser
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    url_collections.cpp

HEADERS  += dialog.h \
    url_collections.h

FORMS    += dialog.ui

RESOURCES += \
    images.qrc

DISTFILES +=
