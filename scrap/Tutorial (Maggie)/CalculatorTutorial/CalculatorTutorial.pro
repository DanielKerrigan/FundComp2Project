#-------------------------------------------------
#
# Project created by QtCreator 2016-03-23T14:19:06
#
#-------------------------------------------------

QT += widgets

HEADERS       = button.h \
                calculator.h
SOURCES       = button.cpp \
                calculator.cpp \
                main.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/widgets/calculator
INSTALLS += target
