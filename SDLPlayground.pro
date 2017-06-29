QT += core
QT -= gui

CONFIG += c++14

QMAKE_CXXFLAGS += -std=c++14
QMAKE_CXXFLAGS += -isystem ../SDLFramework  #restrict warnings from its headers

INCLUDEPATH += ../SDLFramework
LIBS += -L../build-SDLFramework-Desktop-Debug -lSDLFramework
LIBS += -lSDL2 -lSDL2_image -lSDL2_ttf
PRE_TARGETDEPS += ../build-SDLFramework-Desktop-Debug/libSDLFramework.a

TARGET = SDLPlayground
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp
