TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    read.cpp \
    print.cpp \
    update.cpp

HEADERS += \
    class.hpp \
    update.hpp